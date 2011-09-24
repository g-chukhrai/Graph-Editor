#ifndef GRAPH_H
#define GRAPH_H
#include <QList>
#include <QStringList>
#include <QProgressBar>

class Graph
{

public:
    Graph(QList<QStringList> m , QStringList names, QProgressBar *);
    QStringList findGamilton(int type);
    ~Graph();

private:
    int tableSize;
    QList<QStringList> matrix,Bmatrix,Mmatrix;
    QStringList vertexNames;
    QProgressBar *prB;
    double cValue;

private:
    void printMatrix(QList<QStringList>);
    QStringList multiplyLine(QStringList P);
    QList<QStringList> multiplyMatrix(QList<QStringList> P);

    void createMmatrix();
    void createBmatrix();

    QStringList algorAlgebr(QStringList);
    QStringList algorAlgebrUpgrade(QString);

    QStringList algorRobFlo();
    QStringList algorRobFloUpgrade();
    QStringList multiChain();

};

#endif // GRAPH_H
