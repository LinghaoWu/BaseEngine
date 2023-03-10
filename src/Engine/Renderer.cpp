#include "Renderer.h"

Renderer::Renderer(){
    _Shader.reset(new Shader());
    _Font.reset(new Font());

    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
    
    glBindVertexArray(_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)( 2*sizeof(float) ));
    glEnableVertexAttribArray(1);
   
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Renderer::~Renderer(){
    glDeleteVertexArrays(1, &_VAO);
    glDeleteBuffers(1, &_VBO);
}

void Renderer::SetDrawColor(const color &color){
    _Shader->SetFloat("f_color", color.R, color.G, color.B);
}

void Renderer::DrawLine(const point &p1, const point &p2, const float &width){
    vertex Vertices[] = {
        {p1.x, p1.y, 0.0, 0.0},
        {p2.x, p2.y, 0.0, 0.0}
    };

    glBindVertexArray(_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    
    glLineWidth(width);

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), &Vertices, GL_STATIC_DRAW);
    
    glUseProgram(_Shader->_program);
    glDrawArrays(GL_LINES, 0 ,2);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::DrawTriangle(const point &p1, const point &p2, const point &p3){
    vertex Vertices[] = {
        {p1.x, p1.y, 0.0, 0.0},
        {p2.x, p2.y, 0.0, 0.0},
        {p3.x, p3.y, 0.0, 0.0}
    };
    glBindVertexArray(_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), &Vertices, GL_STATIC_DRAW);
    
    glUseProgram(_Shader->_program);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::DrawRect(const point &p1, const point &p2){
    vertex Vertices[] = {
        {p2.x, p2.y, 0.0, 0.0},
        {p2.x, p1.y, 0.0, 0.0},
        {p1.x, p1.y, 0.0, 0.0},
        {p1.x, p2.y, 0.0, 0.0}
    };
    uint Indices[] = {
        0, 1, 3,
        1, 2, 3
    };
    glBindVertexArray(_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), &Vertices, GL_STATIC_DRAW);
    
    glUseProgram(_Shader->_program);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &Indices);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}