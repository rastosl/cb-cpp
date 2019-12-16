#include "coordinatesdialog.h"
#include "ui_coordinatesdialog.h"

#include <assert.h>


struct CoordinatesDialog::CoordinatesDialogImpl
{
    void setCoordinates(TransformationMatrix4x4 coordsMatrix);

    Ui::CoordinatesDialog ui;
};

void CoordinatesDialog::CoordinatesDialogImpl::setCoordinates(TransformationMatrix4x4 coordsMatrix)
{
    ui.tableWidget->setRowCount(coordsMatrix.size());
    ui.tableWidget->setColumnCount(coordsMatrix[0].size());
    for (int i = 0; i < 4; ++i) {
        ui.tableWidget->setColumnWidth(i, ui.tableWidget->columnWidth(i) * 0.8);
    }
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(coordsMatrix[r][c]));
            item->setTextAlignment(Qt::AlignRight | Qt::AlignBottom);
            ui.tableWidget->setItem(r, c, item);
        }
    }
}


CoordinatesDialog::CoordinatesDialog(QWidget *parent)
    : QWidget(parent)
    , impl(std::make_unique<CoordinatesDialogImpl>())
{
    impl->ui.setupUi(this);
}

CoordinatesDialog::~CoordinatesDialog() = default;

void CoordinatesDialog::setCoordinates(const TransformationMatrix4x4 &coordsMatrix)
{
    impl->setCoordinates(coordsMatrix);
}
