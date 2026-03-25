#include "snake.hpp"

namespace Game {
    
    SnakeH::SnakeH(const sf::Vector2f& pos, const sf::Vector2f& acc)
        : GameObject(pos, acc)
    {}

    SnakeH::~SnakeH()
    {}

}
