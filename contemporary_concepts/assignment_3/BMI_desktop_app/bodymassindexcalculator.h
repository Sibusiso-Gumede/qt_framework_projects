#ifndef BODYMASSINDEXCALCULATOR_H
#define BODYMASSINDEXCALCULATOR_H

//The interface of the BodyMassIndexCalculator.

class BodyMassIndexCalculator
{
public:
    BodyMassIndexCalculator();
    ~BodyMassIndexCalculator();
    double calculateBMI(double weight, double height);
};

#endif // BODYMASSINDEXCALCULATOR_H
