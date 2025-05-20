#ifndef UNPACKERWINDOW_H
#define UNPACKERWINDOW_H

#include <QWidget>

namespace Ui {
class UnpackerWindow;
}

class UnpackerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UnpackerWindow(QWidget *parent = nullptr);
    ~UnpackerWindow();

private:
    Ui::UnpackerWindow *ui;
};

#endif // UNPACKERWINDOW_H
