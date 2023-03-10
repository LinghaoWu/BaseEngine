#pragma once

#include <memory>
#include "Shader.h"
#include "TileSheet.h"
#include "Font.h"

class Renderer final{
public:
    std::unique_ptr<Shader> _Shader;
    std::unique_ptr<Font> _Font;
    
    uint _VBO, _VAO;

    Renderer();
    ~Renderer();

    void SetDrawColor(const color &color);
    void DrawLine(const point &p1, const point &p2, const float &width = 1);
    void DrawTriangle(const point &p1, const point &p2, const point &p3);
    void DrawRect(const point &p1, const point &p2);
};