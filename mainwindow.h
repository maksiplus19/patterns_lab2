#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QStack>
#include "figure.h"
#include "multicommand.h"
#include "qcustomgraphicview.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Figure* newFigure();
    void addMemory(QString description, Memento memento);

private slots:
    void on_brushColorButton_clicked();

    void on_penColorButton_clicked();

    void on_createCommand_triggered();

    void on_undoButton_clicked();

    void on_multicommand_triggered();

    void on_saveButton_clicked();

    void on_clearButton_clicked();

private:
    QColor penColor = QColor(0, 0, 0), brushColor = QColor(0, 0, 0);
    Ui::MainWindow *ui;
    QMenu* commandMenu;
    QStack<Memento> memoryStack;
    QCustomGraphicView* viewer;
    QMap<QString, MultiCommand*> multimap;
};
#endif // MAINWINDOW_H
