#include "bodymassindexcalculator.h"

//Implementation of the BodyMassIndexCalculator class.

BodyMassIndexCalculator::BodyMassIndexCalculator()
{}

BodyMassIndexCalculator::~BodyMassIndexCalculator()
{}

double BodyMassIndexCalculator::calculateBMI(double weight, double height)
{
    return weight/(height*height);
}
