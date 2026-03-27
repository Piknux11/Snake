#pragma once

#include "../gameobject/gameobject.hpp"

namespace Game {

    struct Player : public GameObject {
        static constexpr unsigned int DEFAULT_LIFE_PLAYER { 3 };

        unsigned int life_ { DEFAULT_LIFE_PLAYER };

        Player ( const sf::Vector2f&, const sf::Vector2f& );
        Player ( const sf::Vector2f&, const sf::Vector2f&, const std::filesystem::path& );

        ~Player ();
    };

}
