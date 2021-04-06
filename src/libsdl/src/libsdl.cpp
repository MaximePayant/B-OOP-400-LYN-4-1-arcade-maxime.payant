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
    m_isOk(true),
    m_window(nullptr)
{
    std::cout << getName() << " initializing..." << std::endl;
    TTF_Init();
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << this->getName() << SDL_GetError() << std::endl;
    m_window = SDL_CreateWindow("arcade_sdl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_font = TTF_OpenFont("8bit.ttf", 50);
}

sdl::SdlModule::~SdlModule()
{
    std::cout << getName() << " stopping..." << std::endl;
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    TTF_CloseFont(m_font);
    TTF_Quit();
}

std::string sdl::SdlModule::getName() const
{
    return (std::string("[" + m_name + "]"));
}

bool sdl::SdlModule::isOk()
{
    return (m_isOk);
}

void sdl::SdlModule::clearWindow()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);
}

void sdl::SdlModule::displayWindow()
{
    SDL_RenderPresent(m_renderer);
}

void sdl::SdlModule::checkEvent()
{
    m_keystate = const_cast<Uint8*>(SDL_GetKeyboardState(NULL));
    while (SDL_PollEvent(&m_event))
        if (m_event.type == SDL_QUIT)
            m_isOk = false;
}

void sdl::SdlModule::drawText(const std::string& text, int characterSize, arc::Color color, std::pair<int, int> position)
{
    SDL_Color realColor = sdl::sdlColorMap.find(color)->second;
    SDL_Surface *surface = TTF_RenderText_Blended(m_font, text.c_str(), realColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_Rect rect = {position.first * 10, position.second * 10, (surface->w * characterSize) / surface->h, characterSize};

    SDL_RenderCopy(m_renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void sdl::SdlModule::drawSquare(int size, arc::Color color, std::pair<int, int> position)
{
    SDL_Rect rect = {position.first * 10, position.second * 10, size * 10, size * 10};
    SDL_Color realColor = sdl::sdlColorMap.find(color)->second;

    SDL_SetRenderDrawColor(m_renderer, realColor.r, realColor.g, realColor.b, realColor.a);
    SDL_RenderFillRect(m_renderer, &rect);
}

bool sdl::SdlModule::getKeyDown(arc::Keyboard key)
{
    if (m_keystate[sdl::keyboardMap.find(key)->second])
        return (true);
    return (false);
}