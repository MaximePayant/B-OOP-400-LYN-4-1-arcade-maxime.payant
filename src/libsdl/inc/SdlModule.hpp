/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SDLMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SDLMODULE

#include "../../../inc/IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class SdlModule : IDisplayModule {
private:
    std::string m_name;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
public:
    SdlModule();
    ~SdlModule();
    void init() override;
    void stop() override;
    std::string getName() const override;
    bool isOk() override;
    void clearWindow() override;
    void draw() override;
    SDL_Renderer getRenderer() const;
};

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_SDLMODULE
