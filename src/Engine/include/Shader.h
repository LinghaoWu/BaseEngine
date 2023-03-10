#pragma once

#include "Defs.h"

class Shader final{
public:
    uint _program;

    Shader(const std::string &VertexShaderPath = "property/Vertex.shader", 
    const std::string &FragmentShaderPath = "property/Fragment.shader");
    ~Shader();

    void SetInt(const std::string &VariableName, int value);
    void SetInt(const std::string &VariableName, int value1, int value2);
    void SetInt(const std::string &VariableName, int value1, int value2, int value3);
    void SetInt(const std::string &VariableName, int value1, int value2, int value3, int value4);

    void SetBool(const std::string &VariableName, bool value);
    
    void SetFloat(const std::string &VariableName, float value);
    void SetFloat(const std::string &VariableName, float value1, float value2);
    void SetFloat(const std::string &VariableName, float value1, float value2, float value3);
    void SetFloat(const std::string &VariableName, float value1, float value2, float value3, float value4);
};