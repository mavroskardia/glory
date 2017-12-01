#ifndef __TEXTURE_MANAGER_H_
#define __TEXTURE_MANAGER_H_

#include "includes.h"

class TextureManager {

    std::map<std::string, GLuint> textures;

public:

    ~TextureManager();

    GLuint add_texture(const char* fname, const char* texname);

};

#endif