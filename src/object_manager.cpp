#include "includes.h"

unsigned int ObjectManager::add_object(const Object& o) {
    objects.push_back(o);
    return objects.size();
}