#pragma once

#include "Defs.h"
#include <ft2build.h>
#include <freetype/freetype.h>
#include FT_FREETYPE_H

class Font final{
public:
    FT_Library _freetype;
    FT_Face _face;
    uint _texture;
    std::map<char, character> characters;

    Font(const std::string &filename = "property/Mononoki Nerd Font Complete Mono Regular.ttf");
    ~Font();
    character GetFont(const char &c);
};