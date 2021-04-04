/*
** EPITECH PROJECT, 2021
** LibFooModule.hpp.h
** File description:
** LibFooModule.hpp.h
*/

#ifndef __SFML_MODULE_H__
#define __SFML_MODULE_H__

#include <unordered_map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include "IDisplayModule.hpp"
#include "Text.hpp"

namespace sfml
{

    class Module :
        public arc::IDisplayModule
    {

        public:
            const std::string m_name;
            sf::RenderWindow m_window;
            sf::Event m_event;

            std::unordered_map<std::string, sf::Texture> m_txtMap;
            std::unordered_map<std::string, std::unique_ptr<arc::IText>> m_textMap;

            Module();
            ~Module() = default;
            std::string getName() override;

            void init() override;
            void stop() override;

            arc::IText *createText(const std::string& cptName) override;
            arc::IText *getText(const std::string& cptName) override;
            void deleteText(const std::string& cptName) override;

            void clear() override;
            template <typename... Args>
            void draw(Args... values);
            void display() override;

            bool pollEvent() override;
            void closeWindow() override;
            bool isOk() override;

    }; // class Module

} // namespace sfml

extern "C" void *entryPoint();

#endif // __SFML_MODULE_H__