#include "Common.h"

mouse_state cursor;
nlohmann::json keys;

int main(int argc, char *argv[]){
    Engine _Engine;
    _Engine.Init();
    while(!glfwWindowShouldClose(_Engine._window)){
        _Engine.Update();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        _Engine._Renderer->SetDrawColor(color{1,0,0});
        if(cursor.left && !cursor.right)
            _Engine._Renderer->DrawTriangle(point{-1,-1},point{1,-1},point{1,0.5});
        if(!cursor.left && cursor.right)
            _Engine._Renderer->DrawLine(point{-0.5,-0.5},point{0.5,0.5},5);
        if(cursor.left && cursor.right)
            _Engine._Renderer->DrawRect(point{-0.5,-0.5},point{0.5,0.5});

        _Engine._Gui->Test();

        glfwSwapBuffers(_Engine._window);
        glfwPollEvents();
    }
    _Engine.Exit();
    return 0;
}
