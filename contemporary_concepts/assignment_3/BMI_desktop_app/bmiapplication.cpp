#include "bodymassindexcalculatorform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    BodyMassIndexCalculatorForm bmi;
    bmi.show();
    return app.exec();
}
