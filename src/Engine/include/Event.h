#pragma once

#include <fstream>
#include <JSON/json.hpp>
#include "Defs.h"

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);

void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

void ReadKeybinding();

void EventUpdate(GLFWwindow *window);

point GetCursorPosition(GLFWwindow *window);