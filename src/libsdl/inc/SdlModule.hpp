/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SDLMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SDLMODULE

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../../../inc/IDisplayModule.hpp"

class SdlModule :
    public arc::IDisplayModule
{
    private:
        std::string m_name;
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;

    public:
        SdlModule();
        ~SdlModule();
        std::string getName() const override;

        void init() override;
        void stop() override;

        void clearWindow() override;
        void displayWindow() override;
        void checkEvent() override;
        bool isOk() override;

        void drawText(const std::string& text, int characterSize, std::pair<int, int> position) override;
        void drawSquare(int size, std::pair<int, int> position) override;


};

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SDLMODULE
