#ifndef CREATECOMMANDDIALOG_H
#define CREATECOMMANDDIALOG_H

#include "multicommand.h"
#include "commands.h"
#include <QDialog>
#include <QLabel>

namespace Ui {
class CreateCommandDialog;
}

class CreateCommandDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCommandDialog(QWidget *parent = nullptr);
    ~CreateCommandDialog();

    MultiCommand& getCommand();
    QString getName() const;

private slots:

    void on_setTypeButton_clicked();

    void on_setSizeButton_clicked();

    void on_setPenSizeButton_clicked();

    void on_setMainColor_clicked();

    void on_brushColorButton_clicked();

    void on_penColorButton_clicked();

    void on_setPenColorButton_clicked();

private:
    Ui::CreateCommandDialog *ui;
    MultiCommand* command;

    QColor mainColor = QColor::fromRgb(0, 0, 0), penColor = QColor::fromRgb(0, 0, 0);

    QLabel labels[5];

    void addCommandStr(QString c);
    void addCommand(Command* com, QString str);
};

#endif // CREATECOMMANDDIALOG_H
