#include "subwindow.h"
#include "graphscene.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>
#include <QPushButton>
#include <QScrollBar>

SubWindow::SubWindow(GraphScene * scn)
{
    this->setScene(scn);
    scene = scn;

    QLinearGradient gradient;
    gradient.setStart(0,-500);
    gradient.setFinalStop(0,500);
    gradient.setSpread(QGradient::ReflectSpread);
    gradient.setColorAt(0,Qt::white);
    gradient.setColorAt(1,QColor(200,220,220));
    setBackgroundBrush(gradient);

    this->setCurrentFileName("");
}

void SubWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave())
    {
        clearMemory();
        emit subClosed();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

bool SubWindow::save()
{
    if (scene->getFileName().isEmpty())
    {
        return saveAs();
    }
    QFile file(scene->getFileName());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        QMessageBox::warning(this,"Ошибка сохранения графа",file.errorString());
    else
    {
        file.remove(scene->getFileName());
        scene->save(&file);
        scene->setModified(false);
        return true;
    }
    return false;
}

bool SubWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Сохранить как...",".grph","Тип граф (*.grph)");
    if (fileName.isEmpty())
        return false;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this,"Ошибка сохранения графа",file.errorString());
    }
    else
    {
        if(scene->save(&file))
        {
            setCurrentFileName(fileName);
            scene->setModified(false);
            return true;
        }
        file.close();
    }
    return false;
}

bool SubWindow::load(QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"Ошибка загрузки графа",file.errorString());
    }
    else
    {
        scene->load(&file);
        setCurrentFileName(fileName);
        return true;
    }
    return false;
}

bool SubWindow::maybeSave()
{
    if (scene->getModified() == false)
        return true;
    if (scene->getFileName().startsWith(QLatin1String(":/")))
        return true;

    QMessageBox saveBox(this);
    saveBox.setWindowTitle("Программа поиска гамильтоновых циклов");
    saveBox.setText("Граф был изменен, желаете сохранить изменения?");
    QPushButton *saveButton = saveBox.addButton("Сохранить",QMessageBox::ActionRole);
    saveBox.addButton("Не сохранять",QMessageBox::ActionRole);
    QPushButton *abortButton = saveBox.addButton("Отмена",QMessageBox::ActionRole);
    saveBox.exec();

    if (saveBox.clickedButton() == saveButton)
        save();
    else if (saveBox.clickedButton() == abortButton)
        return false;

    return true;
}

void SubWindow::setCurrentFileName(const QString &fileName)
{
    scene->setFileName(fileName);
    QString shownName;
    static int sequenceNumber = 1;

    if (scene->getFileName().isEmpty())
        shownName = QString("Безымянный %1.grph").arg(sequenceNumber++);
    else
        shownName = QFileInfo(scene->getFileName()).fileName();

    setWindowTitle(shownName);
    scene->setModified(false);
    emit setCurrentFile(fileName);
}

void SubWindow::clearMemory()
{
    scene->answerList.clear();
    scene->allVertexes.clear();
}

void SubWindow::centerScrollBar()
{

    int w = this->width(), h = this->height();
    QRectF  itemsRect = scene->itemsBoundingRect();
    QScrollBar *vBar = this->verticalScrollBar(), *hBar = this->horizontalScrollBar();
    vBar->setValue(itemsRect.top() + itemsRect.height()/2 - h/2);
    hBar->setValue(itemsRect.left() + itemsRect.width()/2 - w/2);
}
