#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H
#include <QGraphicsScene>
#include <QFile>
#include "vertex.h"
#include "edge.h"

class GraphScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphScene(QMenu *itemMenu,QMenu *arrowMenu, QObject *parent = 0);
    enum Mode { AddVertex, AddArc, AddEdge, MoveMode};

    void setFileName(QString fn)
        { fileName = fn; }
    QString getFileName()
        { return fileName; }

    void setMode(Mode mode)
        { myMode = mode;}
    Mode getMode()
        { return myMode; }
    bool save(QFile *file);
    bool load(QFile *file);

    void setMoveBug(bool bl)
        { moveBug = bl; }
    void setModified(bool bl)
        { isModified = bl; }
    bool getModified()
        { return isModified; }

    Vertex* addVertex(QString name);
    Edge*addEdge(QString eName, Vertex* startItem, Vertex*endItem, Edge::ArrowType arrType);

    void setVertexCount (int count)
        { this->vertexCount = count; }
    int getVertexCount()
        { return this->vertexCount; }
    void setEdgeCount (int count)
        { this->edgeCount = count; }
    int getEdgeCount()
        { return edgeCount; }

//    QList<Vertex*> getAllVertexes()
//        { return allVertexes; }
    QList<Vertex*> allVertexes;

    void setScale(QString sc)
    {scale = sc;}
    QString getScale()
    {return scale;}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent);

signals:
    void addVertexImMatrix(Vertex*);
    void addEdgeInMatrix(Edge*);
    void setMoveMode();
private:

    QString fileName;
    Mode myMode;
    bool moveBug,isModified;
    QGraphicsRectItem *selectRect;
    QPointF selectP;
    QMenu *myItemMenu, *myArrowMenu;
    QGraphicsLineItem *line;
    int vertexCount,edgeCount;
    QString scale;

public:

    QStringList answerList;
    int rang;
    QString foundType;
    QString foundCount;
    QString foundTime;


};

#endif
