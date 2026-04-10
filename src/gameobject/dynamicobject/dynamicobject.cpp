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
        this->applyGravity( delta_time );
        position_ += velocity_ * delta_time;
        on_ground_ = false;
    }

    void
    DynamicObject::resolveCollision( GameObject& obj ) 
    {
        if ( aabbOverlap(obj) ) {
            std::string label = obj.label_;

            if (label == "platform-up") {
                on_ground_ = true;
            }
        }
    }

    void 
    DynamicObject::applyGravity( float delta_time )
    {
        if ( !on_ground_ ) {
            velocity_.y += acceleration_.y * delta_time;

            if ( velocity_.y > MAX_FALL_SPEED ) {
                velocity_.y = MAX_FALL_SPEED;
            }
        }
    }
}
