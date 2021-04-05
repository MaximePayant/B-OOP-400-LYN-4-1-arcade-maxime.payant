/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SdlModule.hpp
*/

#ifndef __SDL_MODULE_HPP__
#define __SDL_MODULE_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../../../inc/IDisplayModule.hpp"

namespace sdl
{
    class SdlModule : public arc::IDisplayModule
    {
    private:
        std::string m_name;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

    public:
        SdlModule();
        ~SdlModule();
        std::string getName() const override;

        void clearWindow() override;
        void displayWindow() override;
        void checkEvent() override;
        bool isOk() override;

        void drawText(const std::string& text, int characterSize, arc::Color color, std::pair<int, int> position) override;
        void drawSquare(float size, arc::Color color, std::pair<int, int> position) override;
    };
}

#endif // __SDL_MODULE_HPP__