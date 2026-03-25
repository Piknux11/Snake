#include "snake.hpp"

namespace Game {
    
    SnakeH::SnakeH(const sf::Vector2f& pos, const sf::Vector2f& acc)
        : GameObject(pos, acc)
    {}

    SnakeH::~SnakeH()
    {}

    bool 
    SnakeH::IsColliding ( const GameObject& obj ) const
    {
        return position_.x < obj.position_.x + obj.size_.x &&
               position_.x + size_.x > obj.position_.x &&
               position_.y < obj.position_.y + obj.size_.y &&
               position_.y + size_.y > obj.position_.y;
    }
}
