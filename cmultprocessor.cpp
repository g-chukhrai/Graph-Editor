#include "cmultprocessor.h"
//#include <QDebug>

// конструктор создания вычислителя по имеющимся вершинам
CMultProcessor::CMultProcessor( QList<QList<int> > matrix, QStringList nodes,QProgressBar * pb)
{
    count = nodes.size();                   // размеры матрицы смежности приравниваются количеству вершин
    matr = matrix;
    vertexes = nodes;
    prB = pb;
    begin = 0;                               // начальной и
    end = 0;                                 // конецной вершиной устанавливается нулевая
}

// конструктор создания копии вычеслителся по существующему
CMultProcessor::CMultProcessor(CMultProcessor &proc)
{
    count = proc.count;                      // копируется количество
    matr = proc.matr;
    vertexes = proc.vertexes;
    prB = proc.prB;
    begin = proc.begin;                      // копирование начальной
    end = proc.end;                          // и конечной вершины
}

// деструктор
CMultProcessor::~CMultProcessor()
{
    matr.clear();
    result.clear();
    vertexes.clear();
}

// операция клонирования
CMultProcessor* CMultProcessor::Clone()
{
    return new CMultProcessor( *this ); // вызов конструктора копирования
}

// получение альтернатив текущего состояния
void CMultProcessor::GetAlts( QList<int> &alts )
{
    for( int j = 0; j < count; ++j ) // по матрице смежности находятся узлы
        if( matr[end][j] == 1 )      // в которые можно перейти
            alts.push_back( j );          // из конца текущей цепи
}

// добавление следующей вершины в решение
void CMultProcessor::AddLink( int ind )
{
    matr[ end ][ ind ] = 3;         // ребро из конца текущей цепи в добавленную помечается признаком решения
    matr[ ind ][ end ] = 0;         // обратная дуга (если имеется) удаляется

    if( ind != begin )              // если добавляемая вершина не начальная (гамельтонова цепь)
        __ClearEx( end, ind );      // удалить лишние после добавления ребра

    ind = __GetEx( ind );           // получить следующую входящую во вспомогательные цепи вершину

    end = ind;                      // добавленная вершина становится концом текущей цепи
}

// проверка на гамельтонов цикл
bool CMultProcessor::IsCycle()
{
    return ( begin == end ); // начало и конец текущей цепи ровны
}

// проверка текущего графа на корректность
bool CMultProcessor::IsValid( bool first)
{
    if( first && begin == end )         // если начало и конец текущей цепи ровны
    {
        QStringList vec;
        __GetList( vec );               // получается список вершин текущей цепи
        if( vec.size() != count + 1 )   // если его размер не равен количеству вершин + 1
            return false;               // это не корректный граф
    }

    // проверка на нулевую полустепень исхода для каждой вершины
    for( int i = 0; i < count; i++ )
    {
        int sum = 0;
        for( int j = 0; j < count; j++ )
        {
            //          qDebug() <<"matr[i][j] " << matr[i][j] ;
            if (matr[i][j] != 0)
                sum++;
        }

        if( sum == 0 )
        {
            //            qDebug() <<"ishod = 0";
            return false;
        }
    }

    // проверка на нулевую полустепень захода для каждой вершины
    for( int j = 0; j < count; ++j )
    {
        int sum = 0;
        for( int i = 0; i < count; ++i )
            if (matr[i][j] != 0)
                sum ++;
        if( sum == 0 )
        {
            //            qDebug() <<"zahod = 0";
            return false;
        }
    }

    return true;
}

// получение следующего элемента из вспомогательной цепи
// паралельно с построением результирующей цепи
// строятся вспомогательные цепи в оставшейся части графа
int CMultProcessor::__GetEx( int from )
{
    for( int j = 0; j < count; ++j ) // просмотр матрици смежности
        if( matr[from][j] == 2 )       // есть ли вспомогательные ребра из вершины from
        {
        matr[from][j] = 3;          // если есть они добавляются в результирующую цепь
        if( j != begin )              // если конечная вершина не начальная
            return __GetEx( j );        // проверяем текущую
        else                          // иначе
            return j;                   // возвращаем ее
    }
    return from;                      // если ничего не нашли возращаем ту что пришла в метод
}

// получение следующего элемента решения
int CMultProcessor::__GetNext( int from )
{
    for( int j = 0; j < count; ++j )  // поиск исходящих ребер из текущей
        if( matr[from][j] == 3 )       // помеченных признаком решения
            return j;
    return -1;
}

// исключение лишних ребер после добавления в решения ребра
void CMultProcessor::__ClearEx( int from, int to )
{
    for( int j = 0; j < count; ++j ) // все ребра из вершины - from удаляются
        if( matr[from][j] == 1  )
            matr[from][j] = 0;

    for( int i = 0; i < count; ++i )// все ребра в вершину - to удаляются
        if( matr[i][to] == 1  )
            matr[i][to] = 0;

    __CheckAll();                    // проверка оставшегося графа
}

// проверка оставшегося графа
void CMultProcessor::__CheckAll()
{
    for( int i = 0; i < count; ++i ) // поиск вершин имеющих полустепень исхода равную единице
    {
        int sum = 0;
        int last = 0;
        for( int j = 0; j < count; ++j )
        {
            if (matr[i][j] == 1)
            {
                sum ++;
                last = j;
            }
        }

        if( sum == 1 )               // если такая вершина найдена
        {
            matr[i][last] = 2;           // исходящее из нее ребро помечается как входящее во вспомогательную цепь
            __ClearEx( i, last );         // относительно этого ребра удаляются лишние
        }
    }

    for( int j = 0; j < count; ++j ) // поиск вершин имеющих полустепень захода равную единице
    {
        int sum = 0;
        int last = 0;
        for( int i = 0; i < count; ++i )
        {
            if( matr[i][j] == 1 )
            {
                sum ++;
                last = i;
            }
        }

        if( sum == 1 )              // если такая вершина найдена
        {
            matr[last][j] = 2;          // входящее в нее ребро помечается как входящее во вспомогательную цепь
            __ClearEx( last, j );        // относительно этого ребра удаляются лишние
        }
    }
}

// получение вершин цикла
void CMultProcessor::__GetList( QList<QString> &vec )
{
    int cur = begin; // стартовая вершина считается текущей
    vec.push_back( QString::number(cur) ); // добавляем текущую в список
    do
    {
        cur = __GetNext( cur ); // получаем следующую вершину
        if( cur >= 0 )          // если она не отрицательная
            vec.push_back( QString::number(cur) ); // добавляем ее в список
    }
    while( cur != begin );  // выполнять пока текущая не станет начальной (цепь замнулась)
}

// Функция потока расчета мультицепным методом
QStringList CMultProcessor::ThreadMultiFind()
{
    QList<CMultProcessor *> works;                      // список мультипроцессоров (вычислителей пути)
    works.push_back( this );                            // помещение его в список
    float last = 100;                                   // остаток процента выполнения
    float progress = 0;                                 // процент выполнения

    while(works.size())                                 // цикл выполняется пока всписке есть мультипроцессоры
    {
        QList<CMultProcessor *> new_works;              // внутренний список
        float local_last = last/(works.size()+1);       // получение локального остатка процента выполнения

        for(int i = 0; i < works.size(); ++i )          // обрабатываем все имеющиеся в списке мультипроцессоры
        {
            QList<int> alts;                            // вектор альтернатив
            works[i]->GetAlts(alts);                    // получение альтернатив
            float step = local_last/(alts.size()+1);    // вычисление локального шага для процента выполнения

            for( int j = 0; j < alts.size(); ++j )      // для каждой альтернативы
            {
                CMultProcessor *new_proc = works[i]->Clone(); // создается копия мультипроцессора и альтернатива
                new_proc->AddLink( alts[j] );           // добавляется как следующая вершина решения
                if( new_proc->IsValid() )               // проверка получившегося графа
                {
                    if( new_proc->IsCycle() )           // если это гамильтонов цикл
                    {
                        this->addToResult(new_proc);
                        last -= step;                             // остаток процента выполнения уменшается на шаг
                        progress += step;                         // прогресс увеличивается на шаг
                        prB->setValue(progress);
                        delete new_proc;                          // текущий мультипроцессор удаляется
                    }
                    else                                        // иначе (гамельтонов цикл не найден)
                    {
                        new_works.push_back( new_proc );          // мультипроцессор добавляется в текущий список
                    }
                }
                else
                    delete new_proc;                            // текущий мультипроцессор удаляется
            }
            last -= step;                                   // остаток процента выполнения уменшается на шаг
            progress += step;                               // прогресс увеличивается на шаг
            prB->setValue(progress);
            works[i]->matr.clear();
        }
        for (int i = 0 ; i < works.size() ; i++)
            works[i]->matr.clear();
        works.clear();                                    // очистка списка мультипроцессоров
        for( int i = 0; i < (int)new_works.size(); ++i )// копирование текущего списка мультипроцессоров
            works.push_back( new_works[i] );                // в рабочий список
    }
    for (int i = 0 ; i < works.size() ; i++)
        works[i]->matr.clear();
    return result;    
}

//
//void CMultProcessor::printMatrix(QList<QList<int> > m)
//{
//    qDebug() << "printMatrix";
//    int tableSize = m.count();
//    qDebug() << "tableSize " << tableSize;
//    QString row;
//    for (int i = 0 ; i < tableSize ; i++)
//    {
//        for (int j = 0 ; j < tableSize ; j++)
//        {
//            row += m[i][j] + "\t";
//        }
//        qDebug() << row;
//        row="";
//    }
//}

void CMultProcessor::addToResult(CMultProcessor *proc)
{
    //    qDebug() << "addToResult";
    QString s = this->vertexes[0];
    int from = 0;
    int kol = 0;
    while (kol != count)
    {
        kol++;
        for( int j = 0; j < count; ++j )
            if( proc->matr[from][j] == 3 )
            {
            from = j;
            break;
        }
        s += this->vertexes[from];
        //        qDebug() << s;
    }
    //    qDebug() << s;
    result << s;
}

