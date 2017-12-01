#include "includes.h"

TextureManager::~TextureManager() {
    for (auto texture : textures) {
        glDeleteTextures(1, &texture.second);
    }
}

GLuint TextureManager::add_texture(const char* fname, const char* texname) {

    GLuint texnum;

    glGenTextures(1, &texnum);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texnum);

    SDL_Surface *img = IMG_Load(fname);

    debugout("creating texture with id " << texnum << " called \"" << texname << "\" (" << img->w << "x" << img->h << ")")

    // set the texture data (this op operates on the bound tex)
    // arguments are as follows:
    //  0: 2d texture specifier
    //  1: level of detail (0 == base, others are for mipmaps)
    //  2: internal format for video card
    //  3: width of image
    //  4: height of image
    //  5: always 0
    //  6: format of loaded pixels
    //  7: data type of a pixel
    //  8: the actual pixels
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_BYTE, img->pixels);

    SDL_FreeSurface(img);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    textures[texname] = texnum;

    return texnum;

}