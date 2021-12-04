#include "GLFWApp.h"

int main() {
    GLApp app;

    while (!glfwWindowShouldClose(app.getWindow())) {
        app.swapBuffers();
    }

    return 0;
}

