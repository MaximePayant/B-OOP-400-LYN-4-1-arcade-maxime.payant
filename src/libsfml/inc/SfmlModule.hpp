/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE

#include <SFML/Graphics/RenderWindow.hpp>
#include <unordered_map>
#include "../../../inc/IDisplayModule.hpp"
#include "Text.hpp"

namespace sfml
{
    class SfmlModule : public arc::IDisplayModule
    {
    private:
        sf::RenderWindow m_window;
        sf::Event m_event;
        std::string m_name;
        std::unordered_map<std::string, Text*> m_TextMap;
    public:
        SfmlModule();
        ~SfmlModule();
        std::string getName() const override;

        void init() override;
        void stop() override;

        void clearWindow() override;
        void displayWindow() override;
        bool pollEvent() override; // TODO
        void closeWindow() override; // TODO
        bool isOk() override;

        IText *createText(const std::string& name, const std::string& text, unsigned int size, const std::string& font) override;
        IText *getText(const std::string& name) override;
        void deleteText(const std::string& name) override;
        void drawText(const std::string& name) override;
    };
}

extern "C" void *entryPoint();

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
