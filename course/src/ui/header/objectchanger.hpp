#ifndef OBJECTCHANGER_HPP
#define OBJECTCHANGER_HPP

#include <QDialog>
#include "../../obj/objects.hpp"
#include "../../facade/usagefacade.hpp"

namespace Ui
{
class ObjectChanger;
}

class ObjectChanger : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectChanger(UsageFacade *facade_, QWidget *parent = nullptr);
    ~ObjectChanger();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ObjectChanger *ui;
    UsageFacade *facade;

    int changeModel(PolModel &model, int newXCell, int newYCell);
    void recalculationModelsNum();
};

#endif // OBJECTCHANGER_HPP
