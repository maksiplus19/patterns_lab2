#include "mainwindow.h"
#include "qcustomgraphicview.h"
#include "ui_mainwindow.h"

#include <QBrush>
#include <QPen>
#include <QColor>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainLayout->addWidget(new QCustomGraphicView(this), 0, 0);
//    factory = new FigureFactory(this);
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
