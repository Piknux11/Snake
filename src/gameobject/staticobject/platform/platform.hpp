#pragma once

#include "../staticobject.hpp"

namespace Game {

    struct Platform : public StaticObject {

        Platform( const sf::Vector2f& size,
                  const sf::Vector2f& position,
                  const std::string&  label = "platform-up",
                  const std::string&  tex_path = "" );

        ~Platform();
        
        void resolveCollision( GameObject& );
    };

}
