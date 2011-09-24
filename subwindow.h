#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QGraphicsView>
#include "graphscene.h"

class SubWindow : public QGraphicsView
{
    Q_OBJECT
public:
    SubWindow(GraphScene *);
    bool save();
    bool saveAs();
    bool load(QString&);
    GraphScene* scene;
    bool maybeSave();
    void clearMemory();
    void centerScrollBar();

signals:
    void subClosed();
    void setCurrentFile(QString);

protected:
    void closeEvent(QCloseEvent *event);
    void setCurrentFileName(const QString &fileName);

};

#endif // SUBWINDOW_H
