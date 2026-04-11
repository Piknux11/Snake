#include "player.hpp"
#include <algorithm>

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
        on_ground_ = false;
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
            position_.x = obj.position_.x - size_.x; 
        }
        else {
            position_.x = obj.position_.x + obj.size_.x; 
        }
    }

    void
    Player::resolveCollisionY( const GameObject& obj )
    {
        if ( !this->aabbOverlap(obj) ) return;

        const float overlapUp   { ( position_.y + size_.y ) - obj.position_.y };
        const float overlapDown { ( obj.position_.y + obj.size_.y ) - position_.y };

        if ( overlapUp < overlapDown ) {
            position_.y = obj.position_.y - size_.y;
            on_ground_  = true;
            velocity_.y = 0;
        }
        else {
            position_.y = obj.position_.y + obj.size_.y;
        }
    }

    void 
    Player::move( float dir, float delta_time ) 
    {
        velocity_.x = dir * (MOVE_SPEED / delta_time);
    }

    void
    Player::friction()
    {
        //if ( on_ground_ ) {
        velocity_.x *= FRICTION;
        velocity_.x = std::clamp(velocity_.x, -MOVE_SPEED, MOVE_SPEED);
        if (std::abs(velocity_.x) < 0.05f) velocity_.x = 0.f;
        //}
    }

    void
    Player::jump( float delta_time )
    {
        if ( jump_requested_ && on_ground_) {
            velocity_.y = -JUMP_FORCE;
            on_ground_ = false;
            jump_requested_ = false;
        }
    }

    void 
    Player::requestJump( )
    {
        if ( on_ground_ ) {
            jump_requested_ = true;
        }
        else {
            jump_requested_ = false;
        }
    }

}
