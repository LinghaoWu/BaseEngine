#include "Event.h"

extern mouse_state cursor;
extern nlohmann::json keys;

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods){
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        cursor.left = true;
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        cursor.right = true;
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
        cursor.left = false;
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
        cursor.right = false;
}

void ReadKeybinding(){
    std::ifstream keybindings("property/keybindings.json");
    keys = nlohmann::json::parse(keybindings);
}

void EventUpdate(GLFWwindow *window){
    if(glfwGetKey(window, keys["EXIT"]) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    GetCursorPosition(window);
}

point GetCursorPosition(GLFWwindow *window){
    double _x, _y;
    glfwGetCursorPos(window, &_x, &_y);
    cursor.position.x = _x; cursor.position.y = _y;
    return cursor.position;
}