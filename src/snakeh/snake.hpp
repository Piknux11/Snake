#pragma once 

#include "../gameobject/gameobject.hpp"

namespace Game {

    struct SnakeH : public GameObject {
        static constexpr int DEFAULT_LIFE             { 1 };
        int life_                  { DEFAULT_LIFE };

        SnakeH( const sf::Vector2f&, const sf::Vector2f& );
        SnakeH( const sf::Vector2f&, const sf::Vector2f&, const std::filesystem::path& );
        ~SnakeH();
    };

}
