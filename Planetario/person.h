#ifndef PERSON_H
#define PERSON_H

#include <QPixmap>

#include "Specializations/specialization.h"

#include "Resources/foodresource.h"

#include "Objectives/pointobject.h"
#include "map.h"
#include "personstats.h"
#include "persontransportationmanager.h"

class PersonTransportationManager;
class Specialization;
class Map;

enum WorkState { JustChanged, Moving, Working };

class Person: public PointObject
{
private:
    bool isDead;

    PersonStats *stats;
    PersonTransportationManager *transportationManager;

    double getStarvationProductivityMultiplier();
    double getDrowsinessProductivityMultiplier();

    Position *targetPosition;

    Specialization *specialization;
    Map *map;

    void updatePosition();
    void updateStats();

    bool atPoint(Position *target);

public:
    PersonStats *getPersonStats();
    PersonTransportationManager *getTransportationManager();
    Person(Map *map);
    double getCommonProductivityMultiplier();
    void moveToPoint(Position *p);
    void desideWhatToDo();
    void updateWithTimer(QTimer *timer) override;
    QPixmap *getPixmap() override;

    WorkState workState;

    void moveToNearestTree();
    bool atAnchorPoint();

    void consumeFoodResource(FoodResource *foodResource);

    // MARK: Getters and Setters
};

#endif // PERSON_H
