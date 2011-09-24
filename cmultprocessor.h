#ifndef CMULTPROCESSOR_H
#define CMULTPROCESSOR_H
#include <QList>
#include "graphscene.h"
#include <QProgressBar>

class CMultProcessor
{
public:
    CMultProcessor(QList<QList<int> > matrix, QStringList nodes, QProgressBar *);          // конструктор создания вычислителя по имеющимся вершинам
    CMultProcessor( CMultProcessor &proc ); // конструктор создания копии вычеслителся по существующему

    ~CMultProcessor();                      // деструктор
    CMultProcessor* Clone();                // операция клонирования

    void GetAlts(QList<int>& );             // получение альтернатив текущего состояния
    void AddLink( int ind );               // добавление следующей вершины в решение

    bool IsCycle();                         // проверка на гамельтонов цикл
    bool IsValid( bool first = true );      // проверка текущего графа на корректность
    QProgressBar *prB;

    QStringList ThreadMultiFind();
    void printMatrix(QList<QList<int> > m);
    void addToResult(CMultProcessor*);
protected:

    QStringList vertexes,result;
    QList<QList<int> > matr;                              // матрица смежности
    int count,begin,end;                               // размер матрицы смежности

    void __ClearEx( int from, int to );     // исключение лишних ребер после добавления в решения ребра
    void __CheckAll();                        // проверка оставшегося графа
    int __GetEx( int from );                // получение следующего элемента из вспомогательной цепи
    int __GetNext( int from );              // получение следующего элемента решения
    void  __GetList(QList<QString>&);              // получение вершин цикла
};

#endif // CMULTPROCESSOR_H
