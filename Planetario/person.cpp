#include "person.h"

Person::Person() {

}

void Person::desideWhatToDo() {
    specialization->work();
}

double Person::getStamina() {
    return stamina;
}

double Person::getFtigue() {
    return fatigue;
}

double Person::getStrength() {
    return strength;
}

double Person::getAgility() {
    return agility;
}

double Person::getIntelligence() {
    return intelligence;
}

void Person::setStamina(double value) {
    stamina = value;
}

void Person::setFatigue(double value) {
    fatigue = value;
}

void Person::setStrength(double value) {
    strength = value;
}

void Person::setAgility(double value) {
    agility = value;
}

void Person::setIntelligence(double value) {
    intelligence = value;
}
