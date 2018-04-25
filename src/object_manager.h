#ifndef __OBJECT_MANAGER_H_
#define __OBJECT_MANAGER_H_

#include "includes.h"

class ObjectManager {

    std::vector<Object> objects;

public:

    ~ObjectManager();

    unsigned int add_object(const Object& o);

};

#endif
