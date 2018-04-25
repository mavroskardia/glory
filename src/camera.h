#ifndef __CAMERA_H_
#define __CAMERA_H_

#include "includes.h"

class Camera {

public:

    Camera();
    ~Camera();

    glm::vec3 eye;
    glm::vec3 center;
    glm::vec3 up;

};

#endif