#ifndef ITEMS_H
#define ITEMS_H
#include <QGraphicsItem>
#include <QLinearGradient>
class Edge;

class Vertex : public QGraphicsItem
{
public:

    enum { Type = UserType + 69 };
    int type() const
    { return Type; }

    Vertex(QMenu *contextMenu, QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);

    QRectF boundingRect() const;
    void removeArrow(Edge *arrow);
    void addArrow(Edge *arrow);

//    QList<Edge *> getEdges()
//    { return edges;}
    QList<Edge *> edges;

    void setName(QString nm)
    {name = nm;}
    QString getName()
    {return name;}

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

private:
    QString name;
    QMenu *myContextMenu;
};

#endif
