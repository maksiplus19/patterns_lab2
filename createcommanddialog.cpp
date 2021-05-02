#include "createcommanddialog.h"
#include "ui_createcommanddialog.h"
#include "figtype.h"

#include <QColorDialog>
#include <QMessageBox>

QString figTypeToString(FigType t){
    switch (t) {
        case FigType::Circle: return "Круг";
        case FigType::Triangle: return "Треугольник";
        case FigType::Square: return "Квадрат";
        case FigType::Pentagon: return "Пятиугольник";
        case FigType::Hexagon: return "Шестиугольник";
    }
}

CreateCommandDialog::CreateCommandDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCommandDialog)
{
    command = new MultiCommand;
    ui->setupUi(this);
}

CreateCommandDialog::~CreateCommandDialog()
{
    delete ui;
}

MultiCommand& CreateCommandDialog::getCommand()
{
    return *command;
}

QString CreateCommandDialog::getName() const
{
    return ui->lineEdit->text();
}

void CreateCommandDialog::addCommandStr(QString c)
{
    switch (command->commandCount()) {
        case 0: ui->comL1->setText(c); break;
        case 1: ui->comL2->setText(c); break;
        case 2: ui->comL3->setText(c); break;
        case 3: ui->comL4->setText(c); break;
        case 4: ui->comL5->setText(c); break;
    }
}

void CreateCommandDialog::addCommand(Command *com, QString str)
{
    if (command->commandCount() < 5) {
        addCommandStr(str);
        command->addCommand(com);
    }
    else
        QMessageBox::information(this, "Не возможно добавить команду", "Мультикоманда может состоять не больше чем из 5 команд");
}

void CreateCommandDialog::on_setTypeButton_clicked()
{
    FigType type;
    if (ui->circleButton->isChecked()) type = FigType::Circle;
    else if (ui->triangleButton->isChecked()) type = FigType::Triangle;
    else if (ui->squareButton->isChecked()) type = FigType::Square;
    else if (ui->pentagonButton->isChecked()) type = FigType::Pentagon;
    else type = FigType::Hexagon;

    addCommand(new ChangeTypeCommand(type), "Изменить тип: " + figTypeToString(type));
}

void CreateCommandDialog::on_setSizeButton_clicked()
{
    addCommand(new ResizeCommand(ui->figSizeSlider->value()), "Изменить радиус: " + QString::number(ui->figSizeSlider->value()));
}

void CreateCommandDialog::on_setPenSizeButton_clicked()
{
    addCommand(new ChangePenSizeCommand(ui->penSizelSlider->value()), "Изменить толщину обводки: " + QString::number(ui->penSizelSlider->value()));
}



void CreateCommandDialog::on_setMainColor_clicked()
{
    addCommand(new ChangeMainColorCommand(mainColor), "Изменить основной цвет: " + QString(mainColor.rgb()));
}

void CreateCommandDialog::on_brushColorButton_clicked()
{
    auto d = new QColorDialog(this);
    d->exec();
    mainColor = d->selectedColor();
}

void CreateCommandDialog::on_penColorButton_clicked()
{
    auto d = new QColorDialog(this);
    d->exec();
    penColor = d->selectedColor();
}

void CreateCommandDialog::on_setPenColorButton_clicked()
{
    addCommand(new ChangePenColorCommand(mainColor), "Изменить цвет обводки: " + QString(penColor.rgb()));
}
