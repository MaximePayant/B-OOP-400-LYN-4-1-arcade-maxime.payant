/*
** EPITECH PROJECT, 2021
** libnon.cpp.c
** File description:
** libnon.cpp.c
*/

#include <iostream>
#include "../inc/SdlModule.hpp"

__attribute__((constructor))
void libSdl_constructor()
{
    std::cout << "[Sdl Module] Starting Sdl Module..." << std::endl;
}

__attribute__((destructor))
void libSdl_destructor()
{
    std::cout << "[Sdl Module] Sdl Module stopped." << std::endl;
}

extern "C" void *entryPoint()
{
    auto *module = new SdlModule();

    std::cout << module->getName() << ": Loaded!" << std::endl;
    return (module);
}

SdlModule::SdlModule() :
    m_name("libSdl"),
    m_window(nullptr)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << this->getName() << SDL_GetError() << std::endl;
    m_window = SDL_CreateWindow("arcade_sdl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SdlModule::~SdlModule()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void SdlModule::init()
{
    std::cout << m_name << " initializing..." << std::endl;
}

void SdlModule::stop()
{
    std::cout << m_name << " stopping..." << std::endl;
}

std::string SdlModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

bool SdlModule::isOk()
{
    return (false);
}

void SdlModule::clearWindow()
{
    SDL_RenderClear(m_renderer);
}

void SdlModule::displayWindow()
{

}

void SdlModule::checkEvent()
{

}

void SdlModule::drawText(const std::string& text, int characterSize, std::pair<int, int> position)
{
    (void)text;
    (void)characterSize;
    (void)position;
}

void SdlModule::drawSquare(int size, std::pair<int, int> position)
{
    (void)size;
    (void)position;
}