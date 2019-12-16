#include "qtguiapplication1.h"
#include "ui_qtguiapplication1.h"

#include "coordinatesdialog.h"
#include "model.h"


struct QtGuiApplication1::QtGuiApplication1Impl
{
    Ui::QtGuiApplication1Window ui;
    CoordinatesDialog coordinatesDialog;

    Model model;
};


QtGuiApplication1::QtGuiApplication1(QWidget *parent)
    : QMainWindow(parent)
    , impl(std::make_unique<QtGuiApplication1Impl>())
{
    impl->ui.setupUi(this);
    connect(impl->ui.getCoordinatesPushButton, &QPushButton::clicked, this, &QtGuiApplication1::showCoordinatesDialog);
}

QtGuiApplication1::~QtGuiApplication1() = default;

void QtGuiApplication1::showCoordinatesDialog()
{
    impl->coordinatesDialog.setCoordinates(impl->model.getCoordinates());
    impl->coordinatesDialog.show();
}
