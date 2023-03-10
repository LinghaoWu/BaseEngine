#include "TileSheet.h"

std::unordered_map<std::string, std::unique_ptr<Texture>> TileSheet;

uint GetTexture(const std::string &filename){
    if(!TileSheet.count(filename)){
        TileSheet[filename].reset(new Texture(filename));
    }
    return TileSheet[filename]->_texture;
}