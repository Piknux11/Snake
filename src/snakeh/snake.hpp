#pragma once 

#include <SFML/System/Vector2.hpp>

namespace Game {

    struct SnakeH {
        static constexpr float DEFAULT_SIZE_HEAD      { 50.f };
        static constexpr float DEFAULT_POSITION_X     { 0.f };
        static constexpr float DEFAULT_POSITION_Y     { 0.f };
        static constexpr float DEFAULT_ACCELERATION_X { 500.f };
        static constexpr float DEFAULT_ACCELERATION_Y { 500.f };
        static constexpr int DEFAULT_LIFE             { 1 };

        sf::Vector2f size_         { DEFAULT_SIZE_HEAD, DEFAULT_SIZE_HEAD };
        sf::Vector2f position_     { DEFAULT_POSITION_X, DEFAULT_POSITION_Y };
        sf::Vector2f acceleration_ { DEFAULT_ACCELERATION_X, DEFAULT_ACCELERATION_Y };
        int life_                  { DEFAULT_LIFE };
    };

}
