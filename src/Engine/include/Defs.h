#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <unordered_map>
#include <map>

#define PI 3.1415

typedef unsigned int uint;
typedef unsigned short ushort;

struct point{
    float x;
    float y;
};

struct size{
    int w;
    int h;
};

struct color{
    float R;
    float G;
    float B;
};

struct vertex{
    point position;
    point texture;
};

struct mouse_state{
    bool left = false;
    bool right = false;
    point position;
};

struct character{
    uint TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    long Advance;
};