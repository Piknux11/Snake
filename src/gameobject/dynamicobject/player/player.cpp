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
    {}

    void
    Player::updateX( float delta_time )
    {
        position_.x += velocity_.x * delta_time;
    }

    void
    Player::updateY( float delta_time ) 
    {
        position_.y += velocity_.y * delta_time;
    }

    void 
    Player::resolveCollision( GameObject& obj ) 
    {}

    void
    Player::resolveCollisionX( const GameObject& obj )
    {
        if ( !this->aabbOverlap(obj) ) return;

        const float overlapLeft  { ( position_.x + size_.x ) - obj.position_.x };
        const float overlapRight { ( obj.position_.x + obj.size_.x ) - position_.x };

        if ( overlapLeft < overlapRight ) {
            position_.x -= overlapLeft; 
        }
        else {
            position_.x += overlapRight; 
        }
    }

    void
    Player::resolveCollisionY( const GameObject& obj )
    {
        if ( !this->aabbOverlap(obj) ) return;

        const float overlapUp   { ( position_.y + size_.y ) - obj.position_.y };
        const float overlapDown { ( obj.position_.y + obj.size_.y ) - position_.y };

        if ( overlapUp < overlapDown ) {
            position_.y -= overlapUp;
            on_ground_ = true;
            is_jumping_ = false;
        }
        else {
            position_.y += overlapDown;
        }
    }

    void 
    Player::move( float dir ) 
    {
        velocity_.x = dir * MOVE_SPEED;
    }

    void
    Player::friction()
    {
        //if ( on_ground_ ) {
        velocity_.x *= FRICTION;
        //}
    }

    void
    Player::jump( float delta_time )
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
                velocity_.y -= JUMP_HOLD_FORCE;
                jump_hold_timer_ += delta_time;
            }
            else {
                is_jumping_ = false;
            }
        }
        else {
            is_jumping_ = false;
        }
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
