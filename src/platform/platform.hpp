#pragma  once

#include "../gameobject/gameobject.hpp"

namespace Game {

    struct Platform : public GameObject {

        Platform(const sf::Vector2f&, const sf::Vector2f&);
        ~Platform();

        void resolveCollision( GameObject& ) const;
        //void resolveYCollision( GameObject& ) const;
    };

}
