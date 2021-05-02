#ifndef FIGDIALOG_H
#define FIGDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "figtype.h"
#include "figure.h"

namespace Ui {
class FigDialog;
}

class FigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FigDialog(Figure *fig, QWidget *parent = nullptr);
    ~FigDialog();

    FigType getType() const;
    int getPenSize() const;
    int getRadius() const;
    QColor getPenColor() const;
    QColor getBrushColor() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

    void on_brushColorButton_clicked();

    void on_penColorButton_clicked();

private:
    Ui::FigDialog *ui;
    QColor penColor, brushColor;
};

#endif // FIGDIALOG_H
