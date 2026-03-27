#include "player.hpp"

namespace Game {

    Player::Player( const sf::Vector2f& pos,
                    const sf::Vector2f& acc )
        : GameObject ( pos, acc )
    {}

    Player::Player( const sf::Vector2f& pos,
                    const sf::Vector2f& acc,
                    const std::filesystem::path& tex )
        : GameObject ( pos, acc, tex )
    {}
}
