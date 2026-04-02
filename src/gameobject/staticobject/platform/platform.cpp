#include "platform.hpp"
#include <cmath>

namespace Game {

    Platform::Platform( const sf::Vector2f& size,
                        const sf::Vector2f& position,
                        const std::string&  label,
                        const std::string&  tex_path )
        : StaticObject(size, position, label, tex_path)
    {}

    Platform::~Platform()
    {}

    void
    Platform::resolveCollision( GameObject& obj )
    {
        if ( this->aabbOverlap( obj ) ) {
            const float overlapLeft  { ( obj.position_.x + obj.size_.x ) - position_.x };
            const float overlapRight { ( position_.x + size_.x ) - obj.position_.x };

            const float overlapUp    { ( obj.position_.y + obj.size_.y ) - position_.y };
            const float overlapDown  { ( position_.y + size_.y ) - obj.position_.y };

            const float minOverlapX  { std::min( overlapLeft, overlapRight ) };
            const float minOverlapY  { std::min( overlapUp, overlapDown ) };

            if ( minOverlapY < minOverlapX ) {
                if ( overlapUp < overlapDown ) {
                    obj.position_.y = position_.y - obj.size_.y;
                    this->label_ = "platform-up";
                }
                else {
                    obj.position_.y = position_.y + size_.y;
                    this->label_ = "platform-down";
                }
            }
            else {
                if ( overlapLeft < overlapRight ) {
                    obj.position_.x = position_.x - obj.size_.x;
                    this->label_ = "platform-left";
                }
                else {
                    obj.position_.x = position_.x + size_.x;
                    this->label_ = "platform-right";
                }
            }

        }
    }
}
