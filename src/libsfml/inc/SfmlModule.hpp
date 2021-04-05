/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/Color.hpp"

namespace sfml
{
    class SfmlModule : public arc::IDisplayModule
    {

    private:
        sf::RenderWindow m_window;
        sf::Event m_event;
        std::string m_name;
        sf::Font m_font;

    public:
        SfmlModule();
        ~SfmlModule() = default;
        std::string getName() const override;

        void init() override;
        void stop() override;

        void clearWindow() override;
        void displayWindow() override;
        void checkEvent() override;
        bool isOk() override;

        void drawText(const std::string& text, int characterSize, std::pair<int, int> position, , std::pair<int, int> position) override;
        void drawSquare(int size, std::pair<int, int> position) override;

    };
}

extern "C" void *entryPoint();

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
