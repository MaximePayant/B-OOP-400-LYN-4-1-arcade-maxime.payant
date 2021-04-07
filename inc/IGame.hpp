/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** IGame.hpp
*/

#ifndef __IGAME_HPP__
#define __IGAME_HPP__

#include <memory>

namespace arc
{

    class IDisplayModule;

    class IGame
    {

        public:
            virtual ~IGame() = default;

            virtual void start(std::shared_ptr<arc::IDisplayModule>) = 0;
            virtual void update(std::shared_ptr<arc::IDisplayModule>) = 0;

    }; // class IGame

} // namespace arc

#endif // __IGAME_HPP__