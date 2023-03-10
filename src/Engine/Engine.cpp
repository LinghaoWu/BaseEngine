#include "Engine.h"

void Engine::Init(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    _window = glfwCreateWindow(_window_size.w, _window_size.h, "openGLGame", NULL, NULL);
    glfwMakeContextCurrent(_window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    glViewport(0, 0, _window_size.w, _window_size.h);
    glfwSwapInterval(1);

    _Renderer.reset(new Renderer());
    _Gui.reset(new Gui(_window));
    ReadKeybinding();
}

void Engine::Exit(){
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void Engine::Update(){
    EventUpdate(_window);
    glfwSetFramebufferSizeCallback(_window, FrameBufferSizeCallback);
    glfwGetWindowSize(_window, &_window_size.w, &_window_size.h);
}