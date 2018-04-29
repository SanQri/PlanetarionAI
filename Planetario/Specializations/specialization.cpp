#include "specialization.h"

Specialization::Specialization(Person *worker)
{
    this->worker = worker;
}

double Specialization::getProductivityByExp(double exp) {
    return 1 + 5 * (1 - std::exp(-0.07 * exp));
}

void Specialization::readyToWork() {

}

SpecializationType Specialization::getType() {
    return SpecializationType::FoodGathererType;
}
