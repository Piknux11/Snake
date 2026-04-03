#include "player.hpp"

namespace Game {

    Player::Player( const sf::Vector2f& size,
                    const sf::Vector2f& position,
                    const std::string&  label,
                    const std::string&  tex_path )
        : DynamicObject(size, position, label, tex_path)
    {}

    Player::~Player() 
    {}

    void
    Player::update( const float& delta_time ) 
    {
        this->applyGravity( delta_time );
        position_ += velocity_ * delta_time;

        velocity_.x = DEFAULT_VELOCITY_X;
        on_ground_ = false;
    }

    void 
    Player::resolveCollision( const GameObject& obj ) 
    {
        if ( aabbOverlap(obj) ) {
            std::string label = obj.label_;

            if ( label == "platform-up" ) {
                on_ground_ = true;
            }
        }
    }

    void 
    Player::move( const short& dir, 
                  const float& delta_time ) 
    {
        velocity_.x += dir * (acceleration_.x * delta_time);
    }

    void 
    Player::jump( const float& delta_time )
    {
        if ( on_ground_ ) {
            velocity_.y -= JUMP * delta_time;
        }
    }
}
