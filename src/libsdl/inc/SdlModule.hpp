/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef SDLMODULE
#define SDLMODULE

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/Color.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

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

#endif //SDLMODULE
