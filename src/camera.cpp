#include "includes.h"

Camera::Camera() {
    eye = glm::vec3(3.0f, 3.0f, 3.0f);
    center = glm::vec3(0.0f, 0.0f, 0.0f);
    up = glm::vec3(0.0f, 0.0f, 1.0f);
}

Camera::~Camera() {
    
}