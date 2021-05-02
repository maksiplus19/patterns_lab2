#include "figdialog.h"
#include "ui_figdialog.h"

FigDialog::FigDialog(Figure *fig, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FigDialog)
{
    ui->setupUi(this);
    switch (fig->getFType()) {
    case FigType::Circle:
        ui->circleButton->setChecked(true);
        break;
    case FigType::Triangle:
        ui->triangleButton->setChecked(true);
        break;
    case FigType::Square:
        ui->squareButton->setChecked(true);
        break;
    case FigType::Pentagon:
        ui->pentagonButton->setChecked(true);
        break;
    case FigType::Hexagon:
        ui->hexButton->setChecked(true);
        break;
    }

    ui->penSizelSlider->setValue(fig->getPen()->width());
    ui->figSizeSlider->setValue(fig->getRadius());
    penColor = fig->getPen()->color();
    brushColor = fig->getBrush()->color();

    setModal(true);
}

FigDialog::~FigDialog()
{
    delete ui;
}

FigType FigDialog::getType() const
{
    if (ui->circleButton->isChecked()) return FigType::Circle;
    else if (ui->triangleButton->isChecked()) return FigType::Triangle;
    else if (ui->squareButton->isChecked()) return FigType::Square;
    else if (ui->pentagonButton->isChecked()) return FigType::Pentagon;
    else return FigType::Hexagon;
}

int FigDialog::getPenSize() const
{
    return ui->penSizelSlider->value();
}

int FigDialog::getRadius() const
{
    return ui->figSizeSlider->value();
}

QColor FigDialog::getPenColor() const
{
    return penColor;
}

QColor FigDialog::getBrushColor() const
{
    return brushColor;
}

void FigDialog::on_buttonBox_accepted()
{
    this->accept();
}

void FigDialog::on_buttonBox_rejected()
{
    this->reject();
}

void FigDialog::on_brushColorButton_clicked()
{

    QColorDialog *d = new QColorDialog;
    d->exec();
    brushColor = d->selectedColor();
}

void FigDialog::on_penColorButton_clicked()
{

    QColorDialog *d = new QColorDialog;
    d->exec();
    penColor = d->selectedColor();
}
