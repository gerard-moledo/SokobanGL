#include "game.hpp"

#include <cstdio>

void Game::Initialize()
{
    glfwInit();

    window = glfwCreateWindow(1280, 720, "Puzzle", NULL, NULL);

    glfwSetWindowPos(window, 640, 320);
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void Game::Start()
{
    glViewport(0, 0, 1280, 720);
    glEnable(GL_DEPTH_TEST);

    world.Initialize();
    renderer.AddRender("cube");
}

void Game::Run()
{
    Start();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        world.Update();
        
        world.Render(renderer);
        
        glfwSwapBuffers(window);
    }
}

void Game::Quit()
{
    glfwDestroyWindow(window);
    
    glfwTerminate();
}