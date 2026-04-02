#pragma once 

#include "../gameobject.hpp"

namespace Game {

    struct StaticObject : public GameObject {

        StaticObject( const sf::Vector2f&, 
                      const sf::Vector2f&, 
                      const std::string&, 
                      const std::string&);

        ~StaticObject();
    };
}
