/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** libsdl.cpp
*/

#include <iostream>
#include "../inc/SdlModule.hpp"

sdl::SdlModule::SdlModule() :
    m_name("libSdl"),
    m_window(nullptr)
{
    std::cout << m_name << " initializing..." << std::endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << this->getName() << SDL_GetError() << std::endl;
    m_window = SDL_CreateWindow("arcade_sdl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

sdl::SdlModule::~SdlModule()
{
    std::cout << m_name << " stopping..." << std::endl;
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

std::string sdl::SdlModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

bool sdl::SdlModule::isOk()
{
    SDL_Event event;

    SDL_WaitEvent(&event);
    return (event.type == SDL_QUIT);
}

void sdl::SdlModule::clearWindow()
{
    SDL_RenderClear(m_renderer);
}

void sdl::SdlModule::displayWindow()
{

}

void sdl::SdlModule::checkEvent()
{

}

void sdl::SdlModule::drawText(const std::string& text, int characterSize, arc::Color color, std::pair<int, int> position)
{
    (void)text;
    (void)characterSize;
    (void)position;
    (void)color;
}

void sdl::SdlModule::drawSquare(float size, arc::Color color, std::pair<int, int> position)
{
    (void)size;
    (void)position;
    (void)color;
}