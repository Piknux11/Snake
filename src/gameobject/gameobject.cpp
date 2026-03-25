#include "gameobject.hpp"

namespace Game {

    GameObject::GameObject ( const sf::Vector2f& pos, 
                             const sf::Vector2f& acc ) 
        : position_(pos),
          acceleration_(acc)
    {}

    GameObject::~GameObject() 
    {}

}
