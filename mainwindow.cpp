#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createcommanddialog.h"
#include "figureproxy.h"

#include <QBrush>
#include <QPen>
#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    viewer = new QCustomGraphicView(this);
    ui->mainLayout->addWidget(viewer, 0, 0);

//    QAction* commandAction = new QAction("Макрокоманды", ui->menubar);
//    auto commandActions = ui->menubar->addAction("Макрокоманды");
//    auto addCommandAction = commandActions->actionGroup()->addAction("Добавить макрокоманду");
    commandMenu = menuBar()->addMenu("Макрокоманды");
    auto createCommand = commandMenu->addAction("Создать команду");
    connect(createCommand, &QAction::triggered, this, &MainWindow::on_createCommand_triggered);
    FigureProxy::setWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Figure *MainWindow::newFigure()
{
    Figure *fig = new Figure;
    if (ui->circleButton->isChecked()) fig->setType(FigType::Circle);
    else if (ui->triangleButton->isChecked()) fig->setType(FigType::Triangle);
    else if (ui->squareButton->isChecked()) fig->setType(FigType::Square);
    else if (ui->pentagonButton->isChecked()) fig->setType(FigType::Pentagon);
    else fig->setType(FigType::Hexagon);

    fig->setRadius(ui->figSizeSlider->value());
    fig->setPen(new QPen(QBrush(penColor), ui->penSizelSlider->value()));
    fig->setBrush(new QBrush(brushColor));

    return fig;
}

void MainWindow::addMemory(QString description, Memento memento)
{
    memoryStack.push(memento);
    ui->memoryList->addItem(description);
}


void MainWindow::on_brushColorButton_clicked()
{
    QColorDialog *d = new QColorDialog;
    d->exec();
    brushColor = d->selectedColor();
}

void MainWindow::on_penColorButton_clicked()
{
    QColorDialog *d = new QColorDialog;
    d->exec();
    penColor = d->selectedColor();
}

void MainWindow::on_createCommand_triggered()
{
    auto d = new CreateCommandDialog(this);
    if (d->exec()){
        if (d->getName().length() == 0){
            QMessageBox::warning(this, "Ошибка добавления команды", "Нет названия команды");
            return;
        }
        auto action = commandMenu->addAction(d->getName());
        connect(action, &QAction::triggered, this, &MainWindow::on_multicommand_triggered);
        multimap.insert(d->getName(), &d->getCommand());
    }
    delete d;
}

void MainWindow::on_undoButton_clicked()
{
    if (ui->memoryList->count() <= 0) return;
    auto i = ui->memoryList->takeItem(ui->memoryList->count()-1);
//    if (i->text() == "Перемещение фигуры") memoryStack.pop();
    auto mem = memoryStack.pop();
    mem.restore();
    viewer->scene()->update(viewer->sceneRect());
    viewer->repaint();
}

void MainWindow::on_multicommand_triggered()
{
    QAction* action = dynamic_cast<QAction*>(sender());
    auto fig = viewer->getLastFigure();
    if (fig == nullptr) return ;
    auto f = FigureProxy(fig);
    f.reciveCommand(multimap[action->text()]->copy());
    viewer->scene()->update(viewer->sceneRect());
    viewer->repaint();
}

void MainWindow::on_saveButton_clicked()
{
    auto f = new QFileDialog;
    auto name = f->getSaveFileName(this);
    QFile file(name);

    if (file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        for (int i = 0; i < ui->memoryList->count(); i++){
            out << ui->memoryList->item(i)->text() << Qt::endl;
        }
    }

    file.close();
}

void MainWindow::on_clearButton_clicked()
{
    memoryStack.clear();
    ui->memoryList->clear();
}
