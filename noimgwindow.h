#ifndef NOIMGWINDOW_H
#define NOIMGWINDOW_H

#include <QWidget>

namespace Ui {
class noimgwindow;
}

class noimgwindow : public QWidget
{
    Q_OBJECT

public:
    explicit noimgwindow(QWidget *parent = nullptr);
    ~noimgwindow();

private:
    Ui::noimgwindow *ui;
};

#endif // NOIMGWINDOW_H
