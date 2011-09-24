#include "viewer.h"
#include <QDebug>

Viewer::Viewer(QList<QStringList> m ,QStringList names ,QStatusBar* sb)
{
    Mmatrix = m;
    tableSize = (Mmatrix).count();
    stB = sb;
    vertexNames = names;
    curS = Viewer::Begin;
    iFrom = jFrom = 0;

    this->stB->showMessage("Это пошаговый посмотр поиска методом Робертса-Флореса. Нажимайте на кнопки передвижения для просмотра нахождения циклов");
//    this->printMatrix(Mmatrix);
//    qDebug() << this->vertexNames;
    counter = 0 ;

}
//
//void Viewer::printMatrix(QList<QStringList> m)
//{
//    qDebug() << "printMatrix";
//    qDebug() << "tableSize " << tableSize;
//    QString row;
//    for (int i = 0 ; i < tableSize ; i++)
//    {
//        for (int j = 0 ; j < m[i].size() ; j++)
//        {
//            row += m[i][j] + "\t";
//        }
//        qDebug() << row;
//        row="";
//    }
//}

Viewer::~Viewer()
{
    Mmatrix.clear();
    vertexNames.clear();
    path.clear();
    paths.clear();
}

void Viewer::doNext()
{
    chooseNext();
    qDebug() << "curS " << curS;
    switch(curS)
    {
    case Viewer::AddFirst:
        stB->showMessage("В текущий путь добавлена первая вершина из списка вершин графа.");
        path << this->vertexNames[0];
        break;

    case Viewer::AddNext:
        stB->showMessage("В текущий путь добавлена вершина из списка возможных вершин предыдущей вершины.");
        path << this->vertexNames[iFrom];
        break;

    case Viewer::CheckLast:
        stB->showMessage("Поиск дуги между последней и первой вершиной. Нахождение дуги обеспечит нахождение гамильтонова цикла.");
        //        checkLast();
        break;

    case Viewer::AddLast:
        stB->showMessage("Добавление последней вершины в текущий путь. Гамильтонов цикл найден.");
        path << this->vertexNames[0];
        break;

    case Viewer::AddRes:
        stB->showMessage("Добавление текущего пути к списку найденных циклов. Удаление последней дуги из текущего пути.");
        paths << path;
        path.removeLast();
        qDebug() << "paths.last() " << paths.last();
        break;

    case Viewer::GoBack:
        stB->showMessage("Возвращение из последней вершины цепи на одну вершину назад, так как нет возможности добавить следующую вершину.");
        goBack();
        break;

    case Viewer::Finish:
        stB->showMessage("Конец поиска. Возвращение списка найденных циклов.");
        emit finish(paths);
        return;
    }

    qDebug () << "path " << path;
    emit pathUpdate(path, paths.size());

    counter ++;
}

void Viewer::doPrev()
{
    this->path.clear();
    this->paths.clear();
    iFrom = jFrom = 0;

    curS = Viewer::Begin;
    this->stB->showMessage("Нажимайте на кнопки передвижения для просмотра нахождения гамильтоновых циклов методом Робертса-Флореса");
    int lastCounter = counter;
    counter = 0;

    if (lastCounter < 2)
        emit this->pathUpdate(path,paths.size());
    else
        while(lastCounter-1 != counter)
        {
        doNext();
    }
}

bool Viewer::isNext()
{
    qDebug() <<"isNext";

    bool isNextV = false;

    for(int j = jFrom; j < Mmatrix[iFrom].count() ; j++)
    {
        if (!path.contains(Mmatrix[iFrom][j]))
        {
            iFrom = vertexNames.indexOf(Mmatrix[iFrom][j]);
            jFrom = 0 ;
            isNextV = true;
            break;
        }
    }
    return isNextV;
}


bool Viewer::isLast()
{
    qDebug() <<"isLast";
    if (Mmatrix[iFrom].contains(this->vertexNames[0]))
        return true;
    return false;
}

void Viewer::goBack()
{
    qDebug() <<"goBack";
    qDebug() <<"path[path.size()-2]" << path[path.size()-2];
    qDebug() <<"path.last()" << path.last();

    iFrom = vertexNames.indexOf(path[path.size()-2]);
    jFrom = Mmatrix[iFrom].indexOf(path.last()) + 1;
    path.removeLast();
    qDebug() <<"iFrom" << iFrom;
    qDebug() <<"jFrom" << jFrom;
    qDebug() <<"path" << path;
}

void Viewer::chooseNext()
{
    qDebug() <<"chooseNext";

    switch(curS)
    {
    case Viewer::Begin:
        curS = Viewer::AddFirst;
        break;
    case Viewer::AddFirst:
        if (isNext())
            curS = Viewer::AddNext;
        else
            curS = Viewer::Finish;
        break;
    case Viewer::AddNext:
        if (path.size() == this->vertexNames.size())
            curS = Viewer::CheckLast;
        else if (isNext())
            curS = Viewer::AddNext;
        else if (path.size() != 1)
            curS = Viewer::GoBack;
        else
            curS = Viewer::Finish;
        break;

    case Viewer::CheckLast:
        if (isLast())
            curS = Viewer::AddLast;
        else if (path.size() != 1)
            curS = Viewer::GoBack;
        else
            curS = Viewer::Finish;
        break;

    case Viewer::AddLast:
        curS = Viewer::AddRes;
        break;
    case Viewer::AddRes:
        curS = Viewer::GoBack;
        break;
    case Viewer::GoBack:
        curS = Viewer::AddNext;
        chooseNext();
        break;
    }
}

