#include "staticobject.hpp"

namespace Game {

    StaticObject::StaticObject( const sf::Vector2f& size,
                                const sf::Vector2f& position,
                                const std::string&  label,
                                const std::string&  tex_path ) 
        : GameObject(size, position, label, tex_path)
    {}

    StaticObject::~StaticObject() 
    {}

}
