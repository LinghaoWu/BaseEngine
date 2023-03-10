#include "Shader.h"

Shader::Shader(const std::string &VertexShaderPath, const std::string &FragmentShaderPath){
    std::ifstream VertexFile, FragmentFile;
    VertexFile.open(VertexShaderPath);
    FragmentFile.open(FragmentShaderPath);
    std::stringstream VertexStream, FragmentStream;
    VertexStream << VertexFile.rdbuf();
    FragmentStream << FragmentFile.rdbuf();
    VertexFile.close();
    FragmentFile.close();
    std::string VertexCodeString, FragmentCodeString;
    VertexCodeString = VertexStream.str();
    FragmentCodeString = FragmentStream.str();
    const char *VertexCode = VertexCodeString.c_str();
    const char *FragmentCode = FragmentCodeString.c_str();
    
    uint VertexShader, FragmentShader;
    VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader, 1, &VertexCode, NULL);
    glCompileShader(VertexShader);
    FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader, 1, &FragmentCode, NULL);
    glCompileShader(FragmentShader);

    _program = glCreateProgram();
    glAttachShader(_program, VertexShader);
    glAttachShader(_program, FragmentShader);
    glLinkProgram(_program);
    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);
}

Shader::~Shader(){
    glDeleteProgram(_program);
}

void Shader::SetInt(const std::string &VariableName, int value){
    glUniform1i(glGetUniformLocation(_program, VariableName.c_str()), value);
}

void Shader::SetInt(const std::string &VariableName, int value1, int value2){
    glUniform2i(glGetUniformLocation(_program, VariableName.c_str()), value1, value2);
}

void Shader::SetInt(const std::string &VariableName, int value1, int value2, int value3){
    glUniform3i(glGetUniformLocation(_program, VariableName.c_str()), value1, value2, value3);
}

void Shader::SetInt(const std::string &VariableName, int value1, int value2, int value3, int value4){
    glUniform4i(glGetUniformLocation(_program, VariableName.c_str()), value1, value2, value3, value4);
}

void Shader::SetBool(const std::string &VariableName, bool value){
    glUniform1i(glGetUniformLocation(_program, VariableName.c_str()), (int)value);
}

void Shader::SetFloat(const std::string &VariableName, float value){
    glUniform1f(glGetUniformLocation(_program, VariableName.c_str()), value);
}

void Shader::SetFloat(const std::string &VariableName, float value1, float value2){
    glUniform2f(glGetUniformLocation(_program, VariableName.c_str()), value1, value2);
}

void Shader::SetFloat(const std::string &VariableName, float value1, float value2, float value3){
    glUniform3f(glGetUniformLocation(_program, VariableName.c_str()), value1, value2, value3);
}

void Shader::SetFloat(const std::string &VariableName, float value1, float value2, float value3, float value4){
    glUniform4f(glGetUniformLocation(_program, VariableName.c_str()), value1, value2, value3, value4);
}