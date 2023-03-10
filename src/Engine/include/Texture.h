#pragma once

#include "Defs.h"
#include <stb/stb_image.h>

class Texture final{
public:
    uint _texture;
    size _size;
    
    Texture(const std::string &filename);
    ~Texture();
};