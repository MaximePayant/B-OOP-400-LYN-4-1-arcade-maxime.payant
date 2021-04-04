/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AText.hpp
*/

#ifndef __ITEXT_H__
#define __ITEXT_H__

#include <string>

namespace arc
{

    class IText
    {

        public:
            virtual ~IText() = default;

            virtual void setString(const std::string& str) = 0;

    };

} // namespace arc

#endif // __ITEXT_H__