#include "graph.h"
#include <QDebug>
#include "math.h"

Graph::Graph(QList<QStringList> m ,QStringList names ,QProgressBar * pb)
{
    qDebug() << "construct";

    matrix = m;
    tableSize = (matrix).count();
    prB = pb;
    vertexNames = names;
    cValue = 1;

    //    //qDebug() << "cValue  " << cValue;
}
Graph::~Graph()
{

    qDebug() << "destruct";

 matrix.clear();
 Bmatrix.clear();
 Mmatrix.clear();
 vertexNames.clear();
}
QStringList Graph::findGamilton(int type)
{
    QStringList paths;
    prB->setValue(0);
    if (tableSize < 3)
    {
        if (tableSize == 1 && matrix[0][0] == "1")
        {
            paths << this->vertexNames[0];
        }
        else if (tableSize == 2 && matrix[0][1] == "1" && matrix[1][0] == "1")
        {
            paths << this->vertexNames[0] + this->vertexNames[1] + this->vertexNames[0];
        }
    }
    else
    {
        if (type == 0)
        {
            createBmatrix();
            QList<QStringList> P1 = matrix;
            cValue = tableSize - 2;
            for (int i = 0 ; i < tableSize - 2 ; i++)
            {
                prB->setValue(i*100/cValue);
                P1 = multiplyMatrix(P1);
            }
            prB->setValue(90);
            paths = algorAlgebr(P1.first());
        }
        else if (type == 1)
        {
            createBmatrix();
            QStringList P1;
            for (int j = 0; j < this->tableSize; j++)
                P1 << matrix[j][0];
            cValue = tableSize-1;

            for (int i = 0 ; i < tableSize - 1 ; i++)
            {
                prB->setValue(i*100/cValue);
                P1 = multiplyLine(P1);
            }
            prB->setValue(90);
            paths = algorAlgebrUpgrade(P1[0]);
        }
        else if (type == 2)
        {
            qDebug() << "algo RF";

            for (int i = 1; i < vertexNames.count(); i++)
                cValue*=i;
            qDebug() << "cValue" << cValue;

            createMmatrix();
            paths = algorRobFlo();
        }
        else if (type == 3)
        {
            qDebug() << "algo RF U ";

            for (int i = 1; i < vertexNames.count(); i++)
                cValue*=i;

            qDebug() << "cValue" << cValue;

            createMmatrix();
            paths = algorRobFloUpgrade();
        }
    }
    return paths;
}

QStringList Graph::multiChain()
{
    QStringList paths;
    printMatrix(matrix);
    QStringList S;
    QString s1="";
    QStringList endVer,begVer;
    int beg = 0;
    s1+=vertexNames[0];
    begVer << vertexNames[0];
    int end = matrix[0].indexOf("1");
    s1+=this->vertexNames[end];
    endVer << vertexNames[end];
    S << s1;

    //qDebug() << "beg  " << beg  << " end" << end;

    for (int i = 0 ; i < tableSize ; i++)
    {
        if (i != beg &&  i!= end)
        {
            if (matrix[beg][i] == "1")
            {
                matrix[beg][i] = "0";
            }
            if (matrix[i][end] == "1")
            {
                matrix[i][end] = "0";
            }
        }
    }
    for (int i = 0 ; i < S.count() ; i++)
    {
        //qDebug() << "S[" << i << "]    " << S[i];
    }
    printMatrix(matrix);

    if (matrix[end][beg] == "1")
        matrix[end][beg] = "0";

    for (int j = 0 ; j < tableSize; j++)
    {
        int psZax = 0,curR;
        for (int i = 0; i < tableSize ; i++)
        {
            if (!endVer.contains(this->vertexNames[j]) && matrix[i][j] == "1")
            {
                curR = i;
                psZax++;
            }
        }
        if(psZax == 1)
        {
            //qDebug() << "psZax == 1    " ;
            //qDebug() << "curR  = " << curR << "  j = " <<  j ;

            for (int l = 0 ; l < tableSize; l++)
            {
                if (matrix[curR][l] == "1" && l != j)
                    matrix[curR][l] = "0";
            }

            bool bl = false;
            for (int s = 0 ; s < S.count() ; s++)
            {
                QString str = S[s];
                if ((QString)str[str.length()-1] == vertexNames[curR])
                {
                    endVer.removeLast();
                    endVer.append(vertexNames[j]);
                    S[s] += vertexNames[j];
                    int pos = this->vertexNames.indexOf((QString)str[0]);
                    //qDebug() << "add to SS last  "  << S[s];
                    //qDebug() << "  j = " <<  j   << " pos  = " << pos;
                    if (pos != -1  && matrix[j][pos] == "1")
                        matrix[j][pos] = "0";
                    bl = true;
                    break;
                }
                else if ((QString)str[0] == vertexNames[j])
                {
                    begVer.removeFirst();
                    begVer.append(vertexNames[curR]);
                    S[s] = vertexNames[curR] + S[s];
                    int pos = vertexNames.indexOf((QString)str[str.length()-1]);
                    //qDebug() << "add to SS first "  << S[s];
                    //qDebug() << "  j = " <<  j   << " pos  = " << pos;
                    if (pos != -1  && matrix[curR][pos] == "1")
                        matrix[curR][pos] = "0";
                    bl = true;
                    break;
                }
            }
            if (bl == false)
            {
                S << this->vertexNames[curR] + this->vertexNames[j];
                //qDebug() << "create S  "  << S.last();

            }
        }
    }

    printMatrix(matrix);


    for (int i = 0; i < tableSize ; i++)
    {
        int psIsx = 0,curC;
        for (int j = 0 ; j < tableSize; j++)
        {
            if (!begVer.contains(this->vertexNames[i]) && matrix[i][j] == "1")
            {
                curC = j;
                psIsx++;
            }
        }
        if(psIsx == 1)
        {
            //qDebug() << "psIsx == 1    " ;
            //qDebug() << "i  = " << i << "  curC = " <<  curC ;

            for (int k = 0 ; k < tableSize; k++)
            {
                if (matrix[k][curC] == "1" && k != i)
                    matrix[k][curC] == "0";
            }
        }
        bool bl = false;
        for (int s = 0 ; s < S.count() ; s++)
        {
            QString str = S[s];
            if ((QString)str[0] == vertexNames[curC])
            {
                S[s] = this->vertexNames[i] + S[s];
                str = S[s];
                int pos = vertexNames.indexOf((QString)str[str.length()-1]);
                //qDebug() << "add to SS  "  << S[s];
                //qDebug() << "  pos = " <<  pos   << " i  = " << i;
                if (pos != -1 && matrix[pos][i] == "1")
                    matrix[pos][i] = "0";
                bl = true;
                break;
            }
        }
        if (bl == false)
        {
            S << this->vertexNames[i] + this->vertexNames[curC];
            //qDebug() << "create S  "  << S.last();

        }
    }

    for (int i = 0 ; i < S.count() ; i++)
    {
        //qDebug() << "S[" << i << "]    " << S[i];
    }
    printMatrix(matrix);
    return paths;
}

void Graph::printMatrix(QList<QStringList> m)
{
    //qDebug() << "printMatrix";
    //qDebug() << "tableSize " << tableSize;
    QString row;
    for (int i = 0 ; i < tableSize ; i++)
    {
        for (int j = 0 ; j < tableSize ; j++)
        {
            row += m[i][j] + "\t";
        }
        //qDebug() << row;
        row="";
    }
}

void Graph::createBmatrix()
{
    Bmatrix = matrix;
    for (int i = 0 ; i < tableSize ; i++)
    {
        for (int j = 0 ; j < tableSize ; j++)
        {
            if ((Bmatrix)[i][j] == "1" && i != j)
                (Bmatrix)[i][j] = (vertexNames)[j];
            else
                (Bmatrix)[i][j] = "0";
        }
    }
}

QList<QStringList> Graph::multiplyMatrix(QList<QStringList> P)
{
    QList<QStringList> resultMatrix;
    QStringList currRow;
    QString currCell;
    for (int i = 0 ; i < tableSize ; i++)
    {
        for (int j = 0 ; j < tableSize ; j++)
        {
            currCell="";
            for (int k = 0 ; k < tableSize ; k++)
            {
                if (Bmatrix[i][k] != "0" && P[k][j] != "0" && i != j)
                {
                    QString appendStr="";
                    if (P[k][j] == "1")
                        appendStr =  Bmatrix[i][k] + "+";
                    else
                    {
                        QString s = P[k][j];
                        int from = 0,z;
                        while (s.indexOf("+",from) != -1)
                        {
                            z = s.indexOf("+",from);
                            s.insert(z+1,Bmatrix[i][k]);
                            from = z+1;
                        }
                        appendStr =  Bmatrix[i][k] + s + "+";
                    }
                    while (appendStr.contains(this->vertexNames[i]) || appendStr.contains(this->vertexNames[j]))
                    {
                        if (!appendStr.contains("+"))
                            appendStr="";
                        else
                        {
                            int pos = appendStr.indexOf(this->vertexNames[i]);
                            int posE = appendStr.indexOf("+",pos);
                            int posB = -1;
                            for (int i = pos ; i >=0 ; i--)
                                if (appendStr[i]=='+')
                                {
                                posB=i;
                                break;
                            }
                            if (posB == -1)
                                appendStr.remove(0,posE+1);
                            else
                                appendStr.remove(posB,posE-posB);
                        }
                    }
                    currCell += appendStr;
                    appendStr="";
                }
            }
            if (currCell == "") currCell="0";
            else if (currCell[currCell.length()-1]=='+')
                currCell.remove(currCell.length()-1,1);
            currRow << currCell;
        }
        resultMatrix << currRow;
        currRow.clear();
    }
    return resultMatrix;
}

QStringList Graph::multiplyLine(QStringList P)
{
    QStringList resultLine;
    QStringList currRow;
    QString currCell;
    for (int i = 0 ; i < tableSize ; i++)
    {
        currCell="";
        for (int k = 0 ; k < tableSize ; k++)
        {
            if (Bmatrix[i][k] != "0" && P[k] != "0")
            {
                QString appendStr="";
                if (P[k] == "1")
                    appendStr =  Bmatrix[i][k] + "+";
                else
                {
                    QString s = P[k];
                    int from = 0,z;
                    while (s.indexOf("+",from) != -1)
                    {
                        z = s.indexOf("+",from);
                        s.insert(z+1,Bmatrix[i][k]);
                        from = z+1;
                    }
                    appendStr =  Bmatrix[i][k] + s + "+";
                }
                while (appendStr.contains(this->vertexNames[i]))
                {
                    if (!appendStr.contains("+"))
                        appendStr="";
                    else
                    {
                        int pos = appendStr.indexOf(this->vertexNames[i]);
                        int posE = appendStr.indexOf("+",pos);
                        int posB = -1;
                        for (int i = pos ; i >=0 ; i--)
                            if (appendStr[i]=='+')
                            {
                            posB=i;
                            break;
                        }
                        if (posB == -1)
                            appendStr.remove(0,posE+1);
                        else
                            appendStr.remove(posB,posE-posB);
                    }
                }

                currCell += appendStr;
                appendStr="";
            }
        }
        if (currCell == "") currCell="0";
        else if (currCell[currCell.length()-1]=='+')
            currCell.remove(currCell.length()-1,1);
        currRow << currCell;
        resultLine << currRow;
        currRow.clear();
    }
    return resultLine;
}

QStringList Graph::algorAlgebr(QStringList list)
{
    QString curPath="";
    QStringList paths;
    for (int i = 0 ; i < tableSize ; i++)
    {
        QString str = list[i];
        while ( str.lastIndexOf("+") != -1)
        {
            int z = str.lastIndexOf("+");
            for (int j = z+1 ; j < str.length() ; j++)
                curPath += str[j];
            str.remove(z,str.length()-z+1);
            if (matrix[i][0] == "1")
                paths << this->vertexNames[0] + curPath + this->vertexNames[i] + this->vertexNames[0];
            curPath = "";
        }
        if (str != "0" && matrix[i][0] == "1")
            paths << this->vertexNames[0] + str + this->vertexNames[i] + this->vertexNames[0];
    }

    return paths;
}


QStringList Graph::algorAlgebrUpgrade(QString path)
{
    QString curPath;
    QStringList paths;
    while ( path.lastIndexOf("+") != -1)
    {
        int posZ = path.lastIndexOf("+");
        for (int j = posZ+1 ; j < path.length() ; j++)
            curPath += path[j];
        path.remove(posZ, path.length()-posZ+1);
        if (curPath.length() == this->vertexNames.count( )-1)
            paths << this->vertexNames[0] + curPath + this->vertexNames[0];
        curPath = "";
    }
    if (path.length() == this->vertexNames.count( )-1)
        paths << this->vertexNames[0] + path + this->vertexNames[0];
    return paths;
}

void Graph::createMmatrix()
{
    QStringList curColumn;
    for (int i = 0 ; i < tableSize ; i++)
    {
        for (int j = 0 ; j < tableSize ; j++)
        {
            if ((matrix)[i][j] == "1" && i != j)
            {
                curColumn << vertexNames[j];
            }
        }
        Mmatrix << curColumn;
        curColumn.clear();
    }
}

QStringList Graph::algorRobFlo()
{
    QString path;
    QStringList paths;

    path+=vertexNames[0];
    int i = 0,jFrom =0,j ;

    while (path.length() != 0)
    {
        if (jFrom >  Mmatrix[i].count() - 1)
            goto goBack;
        for( j = jFrom; j < Mmatrix[i].count() ; j++)
        {
            if (!path.contains(Mmatrix[i][j]))
            {
                path += Mmatrix[i][j];
                i = vertexNames.indexOf(Mmatrix[i][j]);
                jFrom = 0 ;
                break;
            }
            else if (j == Mmatrix[i].count() - 1)
            {
                goBack:
                if (path.length() == 1)
                {
                    path.clear();
                    break;
                }
                QChar ch = path[path.length()-1];
                path.remove(path.length()-1,1);
                i = vertexNames.indexOf(QString(path[path.length()-1]));
                jFrom = Mmatrix[i].indexOf(QString(ch))+1;
                break;
            }
        }

        if (path.length() == vertexNames.count())
        {
            if (Mmatrix[vertexNames.indexOf((QString)path[path.length()-1])].contains((QString)path[0]))
            {
                paths << path + path[0];
            }
            if (paths.count() % 10 == 0)
            {
                //                //qDebug() << "paths.count()  " << paths.count();
                int value = paths.count()*100/cValue;
                //                //qDebug() << "value  " << value;
                prB->setValue(value);
            }
            goto goBack;
        }
        qDebug();
    }
    return paths;
}





QStringList Graph::algorRobFloUpgrade()
{
    QString path;
    QStringList paths;
    path+=vertexNames[0];
    int i = 0,jFrom =0,j ;
    
    while (path.length() != 0)
    {
        if (jFrom >  Mmatrix[i].count() - 1)
            goto goBack;
        for( j = jFrom; j < Mmatrix[i].count() ; j++)
        {
            if (!path.contains(Mmatrix[i][j]))
            {
                for (int jj = j+1; jj < Mmatrix[i].count(); jj++)
                {
                    bool isEnd = false;
                    int index = this->vertexNames.indexOf(Mmatrix[i][jj]);
                    if(path.contains(Mmatrix[i][jj]))
                        continue;
                    for (int k = 0; k < tableSize ;k++)
                    {
                        if (matrix[k][index]=="1")
                        {
                            if (!path.contains(this->vertexNames[k]))
                            {
                                isEnd = false;
                                break;
                            }
                            else
                                isEnd=true;
                        }
                    }
                    if (isEnd == true)
                    {
                        j = jj;
                        break;
                    }
                }
                path += Mmatrix[i][j];
                i = vertexNames.indexOf(Mmatrix[i][j]);
                jFrom = 0 ;
                break;
            }
            else if (j == Mmatrix[i].count() - 1)
            {
                goBack:
                if (path.length() == 1)
                {
                    path.clear();
                    break;
                }
                QChar ch = path[path.length()-1];
                path.remove(path.length()-1,1);
                i = vertexNames.indexOf(QString(path[path.length()-1]));
                jFrom = Mmatrix[i].indexOf(QString(ch))+1;
                break;                
            }
        }        
        if (path.length() == vertexNames.count())
        {
            if (Mmatrix[vertexNames.indexOf((QString)path[path.length()-1])].contains((QString)path[0]))
            {
                paths << path + path[0];             
            }
            if (paths.count() % 10 == 0)
            {
                //                //qDebug() << "paths.count()  " << paths.count();
                int value = paths.count()*100/cValue;
                //                //qDebug() << "value  " << value;
                prB->setValue(value);
            }
            goto goBack;
        }
    }
    return paths;
}

