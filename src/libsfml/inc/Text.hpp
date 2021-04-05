/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Text.hpp
*/

#ifndef __SFML_TEXT_H__
#define __SFML_TEXT_H__

#include <SFML/Graphics/Text.hpp>

#include "component/IText.hpp"

namespace sfml
{

    class Text :
        public arc::IText
    {

        public:
            sf::Text m_text;

            Text(const std::string& str);
            ~Text() = default;

            void setString(const std::string& str) override;

    };

} // namespace sfml

#endif // __SFML_TEXT_H__