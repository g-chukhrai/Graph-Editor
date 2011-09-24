#ifndef VIEWER_H
#define VIEWER_H
#include <QProgressBar>
#include <QObject>
#include <QStatusBar>
#include <QLabel>

class Viewer : public QObject
{
    Q_OBJECT
public:
    enum Step{Begin,AddFirst,AddNext,CheckLast,AddLast,AddRes,Finish,GoBack};
    Viewer(QList<QStringList> m , QStringList names,QStatusBar*);
    ~Viewer();
    int tableSize;
    QList<QStringList> Mmatrix;
    QStringList vertexNames;
    Step curS;
    void doNext();
    void doPrev();

    QStringList path;
    int iFrom,jFrom;
//    void printMatrix(QList<QStringList> m);
    bool isNext();
    bool isLast();
    void chooseNext();
    int counter;
    QList<QStringList> paths;

    void goBack();
    void checkLast();
    QStatusBar* stB;
signals:
    void finish(QList<QStringList>);
    void pathUpdate(QStringList, int);
};

#endif // VIEWER_H
