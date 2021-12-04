#ifndef REXENGINE_GLFWAPP_H
#define REXENGINE_GLFWAPP_H

#include "core.h"

#include "debug.h"

class GLApp {
public:
    GLApp() {
        glfwSetErrorCallback([](int error, const char* description) {
            fprintf(stderr, "Error: %s\n", description);
        });

        if(!glfwInit()) exit(-1);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

        const GLFWvidmode* info = glfwGetVideoMode(glfwGetPrimaryMonitor());

        window_ = glfwCreateWindow(info->width, info->height, "Window", nullptr, nullptr);
        if(!window_) {
            glfwTerminate();
            exit(-1);
        }

        glfwMakeContextCurrent(window_);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
            exit(-1);
        }
        glfwSwapInterval(0);

        initDebug();
    }

    ~GLApp() {
        glfwDestroyWindow(window_);
        glfwTerminate();
    }

    [[nodiscard]] GLFWwindow* getWindow() const { return window_; }
    [[nodiscard]] float getDeltaTime() const { return delta_time_; }

    void swapBuffers() {
        glfwSwapBuffers(window_);
        glfwPollEvents();

        auto err = glGetError();
        assert(err == GL_NO_ERROR);

        const double new_time_stamp = glfwGetTime();
        delta_time_ = static_cast<float>(new_time_stamp - time_stamp_);
        time_stamp_ = new_time_stamp;
    }

private:
    GLFWwindow *window_{nullptr};
    double time_stamp_{glfwGetTime()};
    float delta_time_{0.f};
};

#endif //REXENGINE_GLFWAPP_H
