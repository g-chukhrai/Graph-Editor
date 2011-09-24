#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsLineItem>
#include "vertex.h"

class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;

class Edge : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };
    int type() const
    { return Type; }

    enum ArrowType{ArcType, EdgeType, LoopType};
    void setType(ArrowType type)
    { myType = type; }
    ArrowType arrowType()
    { return myType;}

    Edge(QMenu *contextMenu, Vertex *startItem, Vertex *endItem, ArrowType,
         QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);

    void setStartItem(Vertex* st)
    { this->myStartItem = st;}
    Vertex *startItem() const
    { return myStartItem; }

    void setEndItem(Vertex* en)
    { this->myEndItem = en;}
    Vertex *endItem() const
    { return myEndItem; }

    void setName(QGraphicsTextItem *nm)
    { name = nm;}
    QGraphicsTextItem *getName()
    { return this->name;}

    QRectF boundingRect() const;
    void updatePosition();

private:
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

    ArrowType myType;
    QPolygonF arrowHead;
    QPolygonF poly;
    Vertex *myStartItem;
    Vertex *myEndItem;

    QGraphicsTextItem *name;
    QMenu *myContextMenu;
};

#endif
