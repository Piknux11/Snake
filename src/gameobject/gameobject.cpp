#include "gameobject.hpp"

namespace Game {

    GameObject::GameObject ( const sf::Vector2f& pos, 
                             const sf::Vector2f& acc ) 
        : position_(pos),
          acceleration_(acc)
    {}

    GameObject::~GameObject() 
    {}

    bool 
    GameObject::aabbOverlap ( const GameObject& obj ) const {
        return position_.x < obj.position_.x + obj.size_.x &&
               position_.x + size_.x > obj.position_.x &&
               position_.y < obj.position_.y + obj.size_.y &&
               position_.y + size_.y > obj.position_.y;
    }
}
