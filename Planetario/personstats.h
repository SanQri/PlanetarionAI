#ifndef PERSONSTATS_H
#define PERSONSTATS_H


class PersonStats
{
private:
    double stamina;
    double fatigue;
    double strength;
    double agility;
    double intelligence;
    double attentiveness;

    double starvation;
    double thurst;
    double drowsiness;

    double foodGatheringExp;
    double woodGatheringExp;
    double fishingExp;
    double huntingExp;
    double bonfireExp;

public:
    double getStamina();
    double getFtigue();
    double getStrength();
    double getAgility();
    double getIntelligence();
    double getAttentiveness();

    double getStarvation();
    double getDrowsiness();
    double getThurst();

    double getFoodGatheringExp();
    double getWoodGatheringExp();
    double getFishingExp();
    double getHuntingExp();
    double getBonfireExp();

    void setStamina(double value);
    void setFatigue(double value);
    void setStrength(double value);
    void setAgility(double value);
    void setIntelligence(double value);
    void setAttentiveness(double value);

    void setStarvation(double value);
    void setDrowsiness(double value);
    void setThurst(double value);

    void setFoodGatheringExp(double value);
    void setWoodGatheringExp(double value);
    void setFishingExp(double value);
    void setHuntingExp(double value);
    void setBonfireExp(double value);

    PersonStats();
};

#endif // PERSONSTATS_H
