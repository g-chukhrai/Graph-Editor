#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QComboBox>
#include <QToolButton>
#include <QLabel>
#include <QTableWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QSignalMapper>
#include <QProgressBar>
#include <QSpinBox>
#include "graphscene.h"
#include "graph.h"
#include "subwindow.h"
#include "viewer.h"
#include "cmultprocessor.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void beginFind(int type);

private slots:
    void deleteItem();
    void arrowReverse();
    void about();
    void exportImage();
    void addArc();
    void addEdge();
    void clearScene();
    void sceneScaleChanged(const QString &scale);
    void gamiltonComboChanged(const QString &path);
    void addVertexImMatrix(Vertex*);
    void addEdgeInMatrix(Edge*);
    void findGamilton();

    void newFile();
    void save();
    void saveAs();
    void load(QString);
    void getFileName();

    void openRecentFile();
    void setCurrentFile(const QString &fileName);

    void setMatrixSize();
    void buildGraph();

    void filePrint();
    void filePrintPreview();
    void printPreview(QPrinter *);

    void cellChange(int,int);
    void subClosed();

    SubWindow *createGraphicsView();
    void setActiveSubWindow(QMdiSubWindow*);
    void saveInTxt();
    
    void tileSubWindows();
    void cascadeSubWindows();
    void rangChanged();

    void algMet();
    void algMetUpg();
    void algRF();
    void algRFUpg();
    void algMultiChain();
    void selectAll();
    void setMoveMode();
    void closeAllSub();
    void startVisual();


    void prevStep();
    void nextStep();
    void startStep();
    void pauseStep();
    void repeatStep();
    void timeout();
    void finish(QList<QStringList>);
    void pathUpdate(QStringList,int);
    void clearResult();

    void updateWindowMenu();

    void setActiveSub(QWidget* w);
void cellClicked(int,int);
int getCountEdges(int);
private:
    QSignalMapper *windowMapper;

    SubWindow *activeGraphicsView();
    QMdiArea *mdiArea;
    QMdiSubWindow* lastActiveWindow;

    void updateEditToolBar();
    virtual void closeEvent(QCloseEvent *e);
    void showResults(int rang);
    void createActions();
    void createMenus();
    void createToolbars();
    void resizeTable();
    QPixmap getPixmap();
    QString myFileName;
    GraphScene *scene;

    QAction *exitAction;
    QAction *deleteAction;
    QAction *aboutAction;
    QAction *newAction;
    QAction *loadAction;
    QAction *saveAction;
    QAction *saveInTxtAction;
    QAction *saveAsAction;
    QAction *findGamiltonAction;
    QAction *printAction;
    QAction *previewAction;
    QAction *addArcAction;
    QAction *addEdgeAction;
    QAction *selectAllAction;

    QAction *closeAllSubAction;
    QAction *tileAct;
    QAction *cascadeAct;

    QMenu *fileMenu;
    QMenu *redactionMenu;
    QMenu *itemMenu;
    QMenu *arrowMenu;
    QMenu *aboutMenu;
 QMenu *windowMenu;
    QToolBar *editToolBar;
    QToolBar *fileToolBar;

    QComboBox *sceneScaleCombo;
    QComboBox *gamiltonCombo;

    QAction *rangAction;
    QAction *exportAction;
    QAction *reverseAction;

    QAction *buildGraphAction;
    QAction *setMatrixAction;

    QStringList tableLabels;
    QTableWidget *table;

    QLabel *foundName;
    QLabel *foundType;
    QLabel *foundedCount;
    QLabel *foundTime;
    QProgressBar *prB;
    QLabel *pathLabel;

    QAction *prevAct,*nextAct,*startAct,*restartAct,*pauseAction;
     QToolBar* viewToolBal;

    void updateRecentFileActions();
    enum { MaxRecentFiles = 5 };
    QAction *recentFileActs[MaxRecentFiles];
    QMenu *recentFilesMenu;

QTimer* timer;
    Viewer *viewer;
QSpinBox *spin;
};

#endif
