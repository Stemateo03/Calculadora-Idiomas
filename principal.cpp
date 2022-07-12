#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_cmdCalcular_released()
{
    calcular();
}

void Principal::on_actionCalcular_triggered()
{
    calcular();
}

void Principal::calcular()
{
    float num1 = ui->inNum1->value();
    float num2 = ui->inNum2->value();

    float resultado = 0.0;

    switch (ui->inOperacion->currentIndex()) {
    case 0:
        resultado = num1 + num2;
        break;
    case 1:
        resultado = num1 - num2;
        break;
    case 2:
        resultado = num1 * num2;
        break;
    case 3:
        resultado = num1 / num2;
        if(num2 == 0){
            QMessageBox::critical(this,tr("Error"),tr("No existe diviciones para 0"));
            break;
        }
        break;
    default:
        break;
    }

    QMessageBox::information(this,tr("Resultado"),tr("El resultado es: %1").arg(resultado));
}
