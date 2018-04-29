#include "waterresource.h"

WaterResource::WaterResource(double mass) : Resource(mass, mass) {

}

ResourceType WaterResource::getType() {
    return ResourceType::FruitType;
}

bool WaterResource::canBeUsed() {
    return true;
}
