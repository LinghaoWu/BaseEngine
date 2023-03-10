#pragma once

#include "GUI.h"
#include "Renderer.h"
#include "Event.h"

class Renderer;

class Engine final{
public:
    std::unique_ptr<Renderer> _Renderer;
    std::unique_ptr<Gui> _Gui;

    size _window_size{1280, 720};

    GLFWwindow *_window;

    void Init();
    void Exit();
    void Update();
};