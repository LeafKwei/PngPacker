#ifndef PACKERWINDOW_H
#define PACKERWINDOW_H

#include <QWidget>

namespace Ui {
class PackerWindow;
}

class PackerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PackerWindow(QWidget *parent = nullptr);
    ~PackerWindow();

private:
    Ui::PackerWindow *ui;
};

#endif // PACKERWINDOW_H
