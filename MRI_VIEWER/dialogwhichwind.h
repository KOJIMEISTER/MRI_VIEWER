#ifndef DIALOGWHICHWIND_H
#define DIALOGWHICHWIND_H

#include <QDialog>
#include <QMouseEvent>
#include <QEvent>
#include <QObject>

namespace Ui {
class DialogWhichWind;
}

class DialogWhichWind : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWhichWind(QWidget *parent = nullptr);
    ~DialogWhichWind();
Q_SIGNALS:
    void pickWindow(const int& windIdx);
private Q_SLOTS:
    void on_btnToWin1_clicked();
    void on_btnToWin2_clicked();

private:
    Ui::DialogWhichWind *ui;
};

#endif // DIALOGWHICHWIND_H
