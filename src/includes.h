#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define GL_GLEXT_PROTOTYPES

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_opengl_glext.h>

#include "macros.h"
#include "object.h"
#include "texture_manager.h"
#include "shader_manager.h"
#include "object_manager.h"
#include "camera.h"

#include "app.h"

#endif