#include "Texture.h"

Texture::Texture(const std::string &filename){
        int channels;
        unsigned char *data = stbi_load(filename.c_str(), &_size.w, &_size.h, &channels, 0);
        glGenTextures(1, &_texture);
        glBindTexture(GL_TEXTURE_2D, _texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _size.w, _size.h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
}

Texture::~Texture(){
    glDeleteTextures(1, &_texture);
}