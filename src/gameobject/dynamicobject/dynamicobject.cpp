#include "dynamicobject.hpp"

namespace Game {

    DynamicObject::DynamicObject( const sf::Vector2f& size,
                                  const sf::Vector2f& position,
                                  const std::string&  label,
                                  const std::string&  tex_path ) 
        : GameObject(size, position, label, tex_path)
    {}

    DynamicObject::~DynamicObject() 
    {}

    void
    DynamicObject::update( float delta_time ) 
    {
    }

    void
    DynamicObject::resolveCollision( GameObject& obj ) 
    {
    }

    void 
    DynamicObject::applyGravity( float delta_time )
    {
        if ( !on_ground_ ) {
            velocity_.y += GRAVITY * delta_time;
        }
    }
}
