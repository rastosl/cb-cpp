#ifndef _QT_GUI_APPLICATION1_H
#define _QT_GUI_APPLICATION1_H

#include <memory>

#include <QtWidgets/QMainWindow>


class QtGuiApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtGuiApplication1(QWidget *parent = nullptr);
    ~QtGuiApplication1();

public slots:
    void showCoordinatesDialog();

private:
    class QtGuiApplication1Impl;
    std::unique_ptr<QtGuiApplication1Impl> impl;
};

#endif // !_QT_GUI_APPLICATION1_H
