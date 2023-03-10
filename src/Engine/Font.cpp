#include "Font.h"

Font::Font(const std::string &filename){
    FT_Init_FreeType(&_freetype);
    FT_New_Face(_freetype, filename.c_str(), 0, &_face);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

Font::~Font(){
    FT_Done_Face(_face);
    FT_Done_FreeType(_freetype);
}

character Font::GetFont(const char &c){
    if(characters.find(c) == characters.end()){
        FT_Load_Char(_face, c, FT_LOAD_RENDER);
        glGenTextures(1, &_texture);
        glBindTexture(GL_TEXTURE_2D, _texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 
        _face->glyph->bitmap.width, _face->glyph->bitmap.rows, 
        0, GL_RED, GL_UNSIGNED_BYTE, 
        _face->glyph->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       character _character = {
            _texture, 
            glm::ivec2(_face->glyph->bitmap.width, _face->glyph->bitmap.rows),
            glm::ivec2(_face->glyph->bitmap_left, _face->glyph->bitmap_top),
            _face->glyph->advance.x
        };
        characters.emplace(c, _character);
        return characters[c];
    }
    return characters[c];
}