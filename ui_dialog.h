/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed 28. Apr 09:37:13 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *buttAlg;
    QPushButton *buttAlgUpg;
    QPushButton *buttRobFlor;
    QPushButton *buttRobFloUpg;
    QPushButton *buttMulti;
    QPushButton *buttCancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(250, 300);
        Dialog->setMinimumSize(QSize(250, 300));
        Dialog->setMaximumSize(QSize(250, 300));
        buttAlg = new QPushButton(Dialog);
        buttAlg->setObjectName(QString::fromUtf8("buttAlg"));
        buttAlg->setGeometry(QRect(20, 10, 211, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Trebuchet MS"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        buttAlg->setFont(font);
        buttAlgUpg = new QPushButton(Dialog);
        buttAlgUpg->setObjectName(QString::fromUtf8("buttAlgUpg"));
        buttAlgUpg->setGeometry(QRect(20, 50, 211, 30));
        buttAlgUpg->setFont(font);
        buttRobFlor = new QPushButton(Dialog);
        buttRobFlor->setObjectName(QString::fromUtf8("buttRobFlor"));
        buttRobFlor->setGeometry(QRect(20, 90, 211, 30));
        buttRobFlor->setFont(font);
        buttRobFloUpg = new QPushButton(Dialog);
        buttRobFloUpg->setObjectName(QString::fromUtf8("buttRobFloUpg"));
        buttRobFloUpg->setGeometry(QRect(20, 130, 211, 30));
        buttRobFloUpg->setFont(font);
        buttMulti = new QPushButton(Dialog);
        buttMulti->setObjectName(QString::fromUtf8("buttMulti"));
        buttMulti->setGeometry(QRect(20, 170, 211, 30));
        buttMulti->setFont(font);
        buttCancel = new QPushButton(Dialog);
        buttCancel->setObjectName(QString::fromUtf8("buttCancel"));
        buttCancel->setGeometry(QRect(70, 250, 120, 30));
        buttCancel->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttCancel->setIcon(icon);
        buttCancel->setIconSize(QSize(24, 24));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        buttAlg->setText(QApplication::translate("Dialog", "\320\220\320\273\320\263\320\265\320\261\321\200\320\260\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\265\321\202\320\276\320\264", 0, QApplication::UnicodeUTF8));
        buttAlgUpg->setText(QApplication::translate("Dialog", "\320\220\320\273\320\263\320\265\320\261\321\200\320\260\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\265\321\202\320\276\320\264 \321\203\320\273\321\203\321\207\321\210\320\265\320\275\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8));
        buttRobFlor->setText(QApplication::translate("Dialog", "\320\234\320\265\321\202\320\276\320\264 \320\240\320\276\320\261\320\265\321\200\321\202\321\201\320\260 - \320\244\320\273\320\276\321\200\320\265\321\201\320\260", 0, QApplication::UnicodeUTF8));
        buttRobFloUpg->setText(QApplication::translate("Dialog", "\320\234\320\265\321\202\320\276\320\264 \320\240\320\276\320\261\320\265\321\200\321\202\321\201\320\260 - \320\244\320\273\320\276\321\200\320\265\321\201\320\260 \321\203\320\273\321\203\321\207\321\210\320\265\320\275\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8));
        buttMulti->setText(QApplication::translate("Dialog", "\320\234\321\203\320\273\321\214\321\202\320\270\321\206\320\265\320\277\320\275\320\276\320\271 \320\274\320\265\321\202\320\276\320\264", 0, QApplication::UnicodeUTF8));
        buttCancel->setText(QApplication::translate("Dialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
