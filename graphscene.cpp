#include <QtGui>
#include "graphscene.h"
#include "edge.h"
#include "mainwindow.h"
//#include <QDebug>

GraphScene::GraphScene(QMenu *itemMenu,QMenu *arrowMenu, QObject *parent)
    : QGraphicsScene(parent)
{
    myItemMenu = itemMenu;
    myArrowMenu = arrowMenu;
    myMode = MoveMode;
    vertexCount = 1;
    edgeCount = 1;
    line = 0;
    isModified = false;
    this->moveBug = true;
}

void GraphScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
    {
        if (mouseEvent->button() == Qt::MidButton)
            emit setMoveMode();
        return;
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
    if (!items().isEmpty())
    {
        foreach(QGraphicsItem* selItem,items())
        {            
            if (selItem->type() == Edge::Type)
            {
                Edge *item = qgraphicsitem_cast<Edge *>(selItem);
                QGraphicsTextItem *name = qgraphicsitem_cast<QGraphicsTextItem *>(item->childItems().first());
                name->setTextInteractionFlags(Qt::NoTextInteraction);
            }
        }
    }
    if(myMode == GraphScene::AddArc || myMode == GraphScene::AddEdge)
    {
        line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),mouseEvent->scenePos()));
        line->setPen(QPen(Qt::black, 1,Qt::DashLine));
        addItem(line);
    }
    moveBug = false;
}

void GraphScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (moveBug)
        return;
    if (myMode == GraphScene::MoveMode && !selectedItems().isEmpty())
    {
        int dx = mouseEvent->scenePos().x()-mouseEvent->lastScenePos().x();
        int dy = mouseEvent->scenePos().y()-mouseEvent->lastScenePos().y();
        if (itemsBoundingRect().left()+dx < sceneRect().left() || itemsBoundingRect().right()+dx > sceneRect().right() ||
            itemsBoundingRect().y()+dy < sceneRect().top() || itemsBoundingRect().bottom()+dy > sceneRect().bottom())
            return;
        foreach(QGraphicsItem* selItem,selectedItems()){
            if (selItem->type() == Vertex::Type )
            {
                Vertex *item = qgraphicsitem_cast<Vertex *>(selItem);
                item->moveBy(dx,dy);
            }
        }
    }
    
    else if ((myMode == GraphScene::AddArc || myMode == GraphScene::AddEdge) && line != 0)
    {
        QLineF newLine(QPointF(line->line().p1().x(),line->line().p1().y()),
                       QPointF(mouseEvent->scenePos().x(),mouseEvent->scenePos().y()));
        line->setLine(newLine);
    }
    update();
    foreach(Vertex* vertex, this->allVertexes)
    {
        foreach(Edge* edge, vertex->edges)
            edge->updatePosition();
    }
//    QGraphicsScene::mouseMoveEvent(mouseEvent);
}


void GraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    moveBug = true;
    if ((myMode == GraphScene::AddArc || myMode == GraphScene::AddEdge) && line!=0)
    {        
        if (line->line().length() < 20)
            QGraphicsScene::mousePressEvent(mouseEvent);
        else
        {
            QList<QGraphicsItem *> startItems = items(line->line().p1());
            QList<QGraphicsItem *> endItems = items(line->line().p2());          
            
            if (!startItems.isEmpty() && !endItems.isEmpty())
            {
                if (startItems.first()->type() == Vertex::Type)
                {
                    Edge *edge;
                    Edge::ArrowType arrType;
                    
                    if (myMode == AddArc)
                        arrType = Edge::ArcType;
                    else if (myMode == AddEdge)
                        arrType = Edge::EdgeType;
                    
                    Vertex *startItem = qgraphicsitem_cast<Vertex *>(startItems.first());
                    Vertex *endItem;
                    
                    if (endItems.first()->type() == Vertex::Type)
                    {
                        endItem = qgraphicsitem_cast<Vertex *>(endItems.first());
                    }
                    else if (allVertexes.count() == 1)
                    {
                        arrType = Edge::LoopType;
                        endItem = startItem;
                    }
                    else
                    {
                        this->removeItem(line);
                        goto m1;
                    }

                    if(this->allVertexes.count() > 11)
                    {
                        int countStartEdges=0,countEndEdges=0;
                        foreach(Edge* edge,startItem->edges)
                        {
                            countStartEdges++;
                            if(edge->arrowType() == Edge::EdgeType)
                                countStartEdges++;
                        }
                        foreach(Edge* edge,endItem->edges)
                        {
                            countEndEdges++;
                            if(edge->arrowType() == Edge::EdgeType)
                                countEndEdges++;
                        }
                        qDebug() << "countStartEdges " <<countStartEdges;
                        qDebug() << "countEndEdges " <<countEndEdges;

                        if(countStartEdges >= 10 || countEndEdges >= 10)
                        {
                            QMessageBox::warning(0,(QString)"Добавление ребра",
                                                 (QString)"Ребро не может быть добавлена, так как количество входящих/выходящих дуг должно быть меньше 10");
                            this->removeItem(line);
                            goto m1;
                        }
                    }
                    
                    if (!startItem->edges.isEmpty() && !endItem->edges.isEmpty())
                    {
                        foreach(Edge* stEdge, startItem->edges)
                        {
                            int index = endItem->edges.indexOf(stEdge);
                            if (index != -1)
                            {
                                Edge* endEdge = endItem->edges.at(index);
                                if ((stEdge->arrowType() == Edge::LoopType && stEdge->startItem()==stEdge->endItem() &&
                                    endEdge->startItem() == endEdge->endItem()))
                                {
                                    goto m1;
                                }
                                else if (((stEdge->arrowType() == Edge::EdgeType)||(stEdge->arrowType() == Edge::ArcType &&
                                                                              stEdge->startItem() == startItem)) &&
                                         (startItem!=endItem))
                                {                                    
                                    goto m1;
                                }
                                else if (stEdge->arrowType() == Edge::ArcType && startItem != endItem)
                                {
                                    //qDebug() << "updateIndex 1";
                                    
                                    stEdge->setType(Edge::EdgeType);
                                    emit addEdgeInMatrix(stEdge);
                                    goto m1;
                                }
                            }
                        }
                    }                    
                    QString name = "e"+QString::number(edgeCount++);
                    edge = addEdge(name,startItem,endItem,arrType);
                    emit addEdgeInMatrix(edge);                    
                }
            }
        }
        m1:
        this->removeItem(line);
        line = 0;
    }
    foreach(QGraphicsItem* selItem,items())
    {
        if(selItem->type() == Edge::Type)
        {
            Edge *item = qgraphicsitem_cast<Edge *>(selItem);
            item->updatePosition();
        }
    }
    this->selectedItems().clear();
    update();
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void GraphScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    line = 0;
    if (!selectedItems().isEmpty())
    {
        QGraphicsItem* selItem = selectedItems().first();
        if (selItem->type() == Edge::Type)
        {
            Edge *item = qgraphicsitem_cast<Edge *>(selItem);
            QGraphicsTextItem *name = qgraphicsitem_cast<QGraphicsTextItem *>(item->childItems().first());
            name->setTextInteractionFlags(Qt::TextEditorInteraction);
            name->setFocus();
        }
    }
    else
    {
        QString name = "v"+QString::number(vertexCount++);        
        Vertex *vertex = addVertex(name);
        vertex->setPos(mouseEvent->scenePos());
        isModified = true;
        emit addVertexImMatrix(vertex);
    }
}

Vertex* GraphScene::addVertex(QString name)
{
    Vertex *vertex = new Vertex(myItemMenu);
    vertex->setZValue(200);
    vertex->setName(name);
    

    addItem(vertex);
    allVertexes.append(vertex);
    isModified = true;
    return vertex;
}

Edge* GraphScene::addEdge(QString eName, Vertex* startItem, Vertex*endItem, Edge::ArrowType arrType)
{
    Edge *edge = new Edge(myArrowMenu,startItem,endItem,arrType);
    edge->setZValue(-100.0);
    addItem(edge);
    edge->updatePosition();
    
    QGraphicsTextItem *name;
    QFont myFont("Arial", 10,QFont::Bold);
    name = addText(eName,myFont);
    name->setParentItem(edge);
    name->setTextInteractionFlags(Qt::NoTextInteraction);
    name->setZValue(100.0);
    QTextOption option = name->document()->defaultTextOption();
    option.setAlignment ( Qt::AlignCenter );
    name->document()->setDefaultTextOption(option);
    
    edge->setName(name);
    edge->getName()-> setTextWidth(60);
    edge->getName() -> setPos(edge->boundingRect().x()-18, edge->boundingRect().y()+20);
    isModified = true;
    return edge;
}


bool GraphScene::save(QFile *file)
{
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeComment("File for Graph Editor");
    xmlWriter.writeStartElement("doc");
    foreach(Vertex* item, this->allVertexes)
    {
        xmlWriter.writeStartElement("Item");
        xmlWriter.writeAttribute("Type",QString::number(item->type()));
        xmlWriter.writeEmptyElement("ItemPos");
        xmlWriter.writeAttribute("x",QString::number(item->pos().x()));
        xmlWriter.writeAttribute("y",QString::number(item->pos().y()));
        xmlWriter.writeAttribute("z",QString::number(item->zValue()));
        xmlWriter.writeEmptyElement("ItemType");
        xmlWriter.writeAttribute("type",QString::number(0));
        xmlWriter.writeEmptyElement("ItemName");
        xmlWriter.writeAttribute("name",item->getName());
        xmlWriter.writeEndElement();
    }

    foreach(QGraphicsItem* selItem, this->items())
    {
        if (selItem->type() == Edge::Type)
        {
            Edge *item = qgraphicsitem_cast<Edge *>(selItem);

            xmlWriter.writeStartElement("Item");
            xmlWriter.writeAttribute("Type",QString::number(item->type()));
            xmlWriter.writeEmptyElement("ItemPos");
            xmlWriter.writeAttribute("x",QString::number(item->pos().x()));
            xmlWriter.writeAttribute("y",QString::number(item->pos().y()));
            xmlWriter.writeAttribute("z",QString::number(item->zValue()));
            xmlWriter.writeEmptyElement("ItemType");
            xmlWriter.writeAttribute("type",QString::number(item->arrowType()));
            xmlWriter.writeAttribute("start_name",item->startItem()->getName());
            xmlWriter.writeAttribute("end_name",item->endItem()->getName());
            xmlWriter.writeEmptyElement("ItemName");
            xmlWriter.writeAttribute("name",item->getName()->toPlainText());

            xmlWriter.writeEndElement();
        }
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    return true;
}

bool GraphScene::load(QFile *file)
{
    QXmlStreamReader xmlReader(file);
    int ItemType = 0;
    QPointF mPos;
    qreal z;
    int type;
    Vertex *insertedItem = 0,*startItm, *endItm;
    Edge  * insertedArrow = 0;
    
    while(!xmlReader.atEnd()){
        xmlReader.readNext();
        if(xmlReader.isStartDocument()) continue;
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="doc") continue;
            if(!ItemType and (xmlReader.name()=="Item")){
                bool ok;
                ItemType = xmlReader.attributes().value("Type").toString().toInt(&ok);
                if(!ok)
                {
                    xmlReader.raiseError(tr("Item: type number conversion failed"));
                }
                continue;
            }
            if(ItemType and (xmlReader.name()=="ItemPos")){
                bool ok,okay;
                okay=true;
                mPos.setX(xmlReader.attributes().value("x").toString().toDouble(&ok));
                okay&=ok;
                mPos.setY(xmlReader.attributes().value("y").toString().toDouble(&ok));
                okay&=ok;
                z=xmlReader.attributes().value("z").toString().toDouble(&ok);
                okay&=ok;
                if(!okay)
                {
                    xmlReader.raiseError(tr("Pos: number conversion failed"));
                }
                continue;
            }
            if(ItemType and (xmlReader.name()=="ItemType")){
                bool ok;
                type = xmlReader.attributes().value("type").toString().toInt(&ok);
                if(!ok)
                {
                    xmlReader.raiseError(tr("ItemType: type number conversion failed"));
                    continue;
                }
                switch (ItemType) {
                case QGraphicsItem::UserType+69:{
                        insertedItem = new Vertex(myItemMenu);
                        insertedItem->setPos(mPos);
                        insertedItem->setZValue(z);
                        break;
                    }
                case QGraphicsItem::UserType+4:{
                        QString start = xmlReader.attributes().value("start_name").toString();
                        QString end = xmlReader.attributes().value("end_name").toString();
                        
                        ////qDebug() << "start " << start ;
                        ////qDebug() << "end " << end ;
                        bool isStFound =false,isEndFound = false;
                        
                        foreach(QGraphicsItem* selItem, items())
                        {

                            if(selItem->type() == Vertex::Type)
                            {
                                Vertex *item = qgraphicsitem_cast<Vertex *>(selItem);
                                if (item->getName() == start)
                                {
                                    startItm = item;
                                    isStFound = true;
//                                    ////qDebug() << "startFound ";
                                    
                                }
                                if(item->getName() == end)
                                {
                                    endItm = item;
                                    isEndFound = true;
//                                    ////qDebug() << "endFound ";
                                }
                            }
                        }
                        if (isStFound && isEndFound)
                        {
                            insertedArrow = new Edge(myArrowMenu,startItm, endItm, Edge::ArrowType(type));
                            insertedArrow->setZValue(z);
                            addItem(insertedArrow);
                            insertedArrow->updatePosition();
                        }
                        else
                        {
                            QMessageBox::warning(0,"Ошибка загрузки","Ребро графа не может быть добавлено.");
                            return false;
                        }
                        break;
                    }
                default:
                    break;
                }
                continue;
            }
            if(ItemType and !(insertedItem or insertedArrow))
            {
                xmlReader.raiseError(tr("ItemType definition missing"));
                continue;
            }
            if(ItemType and (xmlReader.name()=="ItemName")){

                switch (ItemType) {
                case QGraphicsItem::UserType+69:{
                        QString name;
                        name = xmlReader.attributes().value("name").toString();
                        //qDebug() << "name!!! " << name;

                        QString copyName = name;
                        int nameValue = copyName.remove(0,1).toInt();
                        if (this->vertexCount <= nameValue)
                            this->vertexCount = nameValue+1;

                        insertedItem->setName(name);
                        insertedItem->update();
                        addItem(insertedItem);
                        allVertexes.append(insertedItem);
                        emit addVertexImMatrix(insertedItem);
                        
                        break;
                    }
                case QGraphicsItem::UserType+4:{
                        QString nm = xmlReader.attributes().value("name").toString();
                        //qDebug() << "nm!!! " << nm;
                        this->edgeCount++;
                        QGraphicsTextItem *name;
                        QFont myFont("Arial", 10,QFont::Bold);
                        name = addText(nm,myFont);
                        name->setParentItem(insertedArrow);
                        name->setTextInteractionFlags(Qt::NoTextInteraction);
                        name->setZValue(100.0);
                        QTextOption option = name->document()->defaultTextOption();
                        option.setAlignment ( Qt::AlignCenter );
                        name->document()->setDefaultTextOption(option);
                        
                        insertedArrow->setName(name);
                        insertedArrow->getName()-> setTextWidth(60);
                        insertedArrow->getName()-> setPos(insertedArrow->boundingRect().x()-18,
                                                      insertedArrow->boundingRect().y()+20);
                        emit addEdgeInMatrix(insertedArrow);
                        break;
                    }
                default:
                    break;
                }
                continue;
            }
            continue;
        }
        if(xmlReader.isEndElement()){
            if(ItemType and (xmlReader.name()=="Item")){
                ItemType = 0;
                insertedItem = 0;
                insertedArrow = 0;
            }
        }
    }
    
    insertedItem = 0;
    insertedArrow = 0;
    setMode(MoveMode);
    this->update();
    return true;
}


