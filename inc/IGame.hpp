/*
** EPITECH PROJECT, 2021
** IGame.hpp.h
** File description:
** IGame.hpp.h
*/

#ifndef IGAME
#define IGAME

namespace arc
{

    class IDisplayModule;

    class IGame
    {

        public:
            virtual ~IGame() = default;

            virtual void start(IDisplayModule *) = 0;
            virtual void update(IDisplayModule *) = 0;

    }; // class IGame

} // namespace arc

#endif //IGAME
