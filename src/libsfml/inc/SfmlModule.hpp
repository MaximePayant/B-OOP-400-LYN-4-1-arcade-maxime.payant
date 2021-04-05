/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE
#define B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_LIBOUIMODULE

#include "../../../inc/IDisplayModule.hpp"
#include "../../../inc/IText.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <unordered_map>
#include "Text.hpp"

namespace sfml
{
    class SfmlModule : arc::IDisplayModule {
        private:
            sf::RenderWindow m_window;
            std::string m_name;
            std::unordered_map<std::string, Text*> m_TextMap;
        public:
            SfmlModule();
            ~SfmlModule();
            void init() override;
            void stop() override;
            std::string getName() const override;
            bool isOk() override;
            void clearWindow() override;
            void draw() override;
            IText *createText(std::string name, std::string text, unsigned int size, std::string font) override;
            IText *getText(std::string name) override;
            void displayText(IText *text) override;
    };
}


extern "C" void *entryPoint();

#endif //B_OOP_400_LYN_4_1_ARCADE_GUILLAUME_SOISSON_IDISPLAYMODULE
