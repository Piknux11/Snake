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
    Player::update( float delta_time ) 
    {

        if ( jump_requested_ && on_ground_) {
            velocity_.y = -JUMP_FORCE;
            on_ground_ = false;
            is_jumping_ = true;
            jump_hold_timer_ = 0.f;
            jump_requested_ = false;
        }

        if ( is_jumping_ && velocity_.y < 0.f ) {
            if ( jump_hold_timer_ < JUMP_HOLD_MAX_TIME ) {
                velocity_.y -= JUMP_HOLD_FORCE * delta_time;
                jump_hold_timer_ += delta_time;
            }
            else {
                is_jumping_ = false;
            }
        }
        else {
            is_jumping_ = false;
        }

        //if ( on_ground_ ) {
        velocity_.x *= FRICTION;
        //}

        this->applyGravity( delta_time );
        position_ += velocity_ * delta_time;

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
    Player::move( float dir ) 
    {
        velocity_.x = dir * MOVE_SPEED;
    }

    void 
    Player::requestJump( )
    {
        if ( on_ground_ ) {
            jump_requested_ = true;
        }
    }

    void
    Player::releaseJump( ) 
    {
        is_jumping_ = false;
    }
}
