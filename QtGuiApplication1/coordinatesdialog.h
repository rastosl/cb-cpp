#ifndef _COORDINATES_DIALOG_H
#define _COORDINATES_DIALOG_H

#include <memory>

#include <QWidget>

#include "transformationmatrix4x4.h"


class CoordinatesDialog : public QWidget
{
    Q_OBJECT

public:
    CoordinatesDialog(QWidget *parent = nullptr);
    ~CoordinatesDialog();

    void setCoordinates(const TransformationMatrix4x4 &coordsMatrix);

private:
    class CoordinatesDialogImpl;
    std::unique_ptr<CoordinatesDialogImpl> impl;
};

#endif // !_COORDINATES_DIALOG_H
