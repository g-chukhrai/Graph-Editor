#include <QtGui>
#include "edge.h"
#include <math.h>

const qreal Pi = 3.14;

Edge::Edge(QMenu *contextMenu, Vertex *startItem, Vertex *endItem,ArrowType type,
           QGraphicsItem *parent, QGraphicsScene *scene)
               : QGraphicsLineItem(parent, scene)
{
    myStartItem = startItem;
    myEndItem = endItem;
    myContextMenu = contextMenu;

    myType = type;

    startItem->addArrow(this);
    endItem->addArrow(this);

    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Edge::updatePosition()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);
}

QRectF Edge::boundingRect() const
{
    qreal extra = 20;
    if (myStartItem == myEndItem)
    {
        return QRectF(QPointF(myStartItem->pos())-QPointF(40,5),QSizeF(40,10));
    }
    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
    .normalized().adjusted(-extra, -extra, extra, extra);
}

QPainterPath Edge::shape() const
{

    QPainterPath path = QGraphicsLineItem::shape();

    //path.addRect(QRectF(QPointF(this->line().x1(),this->line().y1()),QPointF(this->line().x2(),this->line().y2())));
    path.addPolygon(poly);
    if (myType == Edge::LoopType)
    {
        path.addRect(startItem()->pos().x()-50,startItem()->pos().y(),50,30);
        return path;
    }
    path.addPolygon(arrowHead);
    return path;
}


void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    if (myStartItem != myEndItem && myStartItem->collidesWithItem(myEndItem))
        return;

    QPen *myPen = new QPen(Qt::darkBlue,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    if (isSelected())
    {
        myPen->setColor(Qt::red);
    }
    if(name!=0)
    {
        name->setPos((this->line().p1().x()+this->line().p2().x())/2-25,(this->line().p1().y()+this->line().p2().y())/2-25);
    }
    painter->setPen(*myPen);
    painter->setRenderHint(QPainter::Antialiasing, true);
    setLine(QLineF( QPointF(myEndItem->pos().x(), myEndItem->pos().y()),
                    QPointF( myStartItem->pos().x(),  myStartItem->pos().y()) ));
    arrowHead.clear();


    poly.clear();
    poly << QPointF(this->line().x1()-3,this->line().y1()-3)
            << QPointF(this->line().x1()+3,this->line().y1()+3)
            << QPointF(this->line().x2()+3,this->line().y2()+3)
            << QPointF(this->line().x2()-3,this->line().y2()-3);


    if (myStartItem != myEndItem)
    {
        painter->setRenderHint(QPainter::Antialiasing);
        painter->drawLine(line());
        if (myType == ArcType)
        {
            qreal arrowSize = 20;
            double angle = ::acos(line().dx() / line().length());

            if (line().dy() >= 0)
                angle = (Pi * 2) - angle;

            QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                                    cos(angle + Pi / 3) * arrowSize);
            QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                                    cos(angle + Pi - Pi / 3) * arrowSize);

            arrowHead << (line().p1()+(arrowP1+arrowP2)/2)/2 << arrowP1 << arrowP2;
            painter->setBrush(Qt::white);
            painter->drawPolygon(arrowHead);
          //  painter->drawPolygon(poly);
        }
    }
    else
    {
        painter->drawEllipse(QPointF(line().p1())-QPointF(20,0),20,5);
        if(name!=0)
            name->moveBy(-25,-10);
    }
}

void Edge::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    myContextMenu->exec(event->screenPos());
}
