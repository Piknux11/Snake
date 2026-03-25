#pragma once

#include <SFML/System/Vector2.hpp>

namespace Game {

    struct GameObject {
        static constexpr float DEFAULT_SIZE_HEAD      { 50.f };
        static constexpr float DEFAULT_POSITION_X     { 0.f };
        static constexpr float DEFAULT_POSITION_Y     { 0.f };
        static constexpr float DEFAULT_ACCELERATION_X { 500.f };
        static constexpr float DEFAULT_ACCELERATION_Y { 500.f };

        sf::Vector2f size_         { DEFAULT_SIZE_HEAD, DEFAULT_SIZE_HEAD };
        sf::Vector2f position_     { DEFAULT_POSITION_X, DEFAULT_POSITION_Y };
        sf::Vector2f acceleration_ { DEFAULT_ACCELERATION_X, DEFAULT_ACCELERATION_Y };

        GameObject(const sf::Vector2f&, const sf::Vector2f&);
        virtual ~GameObject();

        virtual bool IsColliding(const GameObject&) const = 0;
    };

}
