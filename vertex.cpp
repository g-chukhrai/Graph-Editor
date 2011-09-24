#include <QtGui>
#include "edge.h"
#include "vertex.h"
#include "math.h"
#include "graphscene.h"
#include "mainwindow.h"

Vertex::Vertex(QMenu *contextMenu, QGraphicsItem *parent, QGraphicsScene *scene)
    : QGraphicsItem(parent, scene)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    myContextMenu = contextMenu;
    name="";
}

QRectF Vertex::boundingRect() const
{
    return QRectF(-12,-12,24,24);
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::darkBlue);
    if (isSelected())
        painter->setBrush(Qt::red);
    else
        painter->setBrush(Qt::darkBlue);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(QPoint(0,0),12,12);
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial",10,QFont::Bold));
    QPointF textBegin;
    if (name.length() == 2)
        textBegin = QPoint(-7,5);
    else
        textBegin = QPoint(-11,5);
    painter->drawText(textBegin,name);
}

void Vertex::removeArrow(Edge *edge)
{
    int index = edges.indexOf(edge);
    if (index != -1)
        edges.removeAt(index);
}

void Vertex::addArrow(Edge *edge)
{
    edges.append(edge);
}

void Vertex::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    myContextMenu->exec(event->screenPos());
}


