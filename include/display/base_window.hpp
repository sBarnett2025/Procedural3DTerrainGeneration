#pragma once

#include "glad.h"
#include "glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <string>


// my stuff
#include "terrain_gen/perlin_to_geometry.hpp"
#include "utils/camera.hpp"
#include "utils/camera_control.hpp"

class BaseWindow {
    public:
    int windowWidth, windowHeight;
    std::string windowTitle;
    GLFWwindow* windowHandle;

    int intern = 0;

    // deltaTime
    float deltaTime;
    float prevFrameTime;

    // camera
    Camera cam;
    CameraController camController;

    Mesh meshData;


    public:
    BaseWindow();
    BaseWindow(int width, int height, std::string title);
    int Run();

    protected:
    virtual void Initialize() = 0;
    virtual void LoadContent() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Unload() = 0;
};