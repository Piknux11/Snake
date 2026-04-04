#pragma once

#include "../dynamicobject.hpp"

namespace Game {

    struct Player : public DynamicObject {

        static constexpr float MOVE_SPEED          { 250.f };
        static constexpr float JUMP_FORCE          { 350.f };
        static constexpr float JUMP_HOLD_FORCE     { 950.f };
        static constexpr float JUMP_HOLD_MAX_TIME  { 0.25f };
        static constexpr float FRICTION            { 0.70f };

        bool jump_requested_   { false }; 
        bool is_jumping_       { false };
        float jump_hold_timer_ { 0.f };

        Player( const sf::Vector2f& size,
               const sf::Vector2f& position,
               const std::string&  label = "Player",
               const std::string&  tex_path = "" ); 

       ~Player();

        void update( float delta_time ) override;
        void resolveCollision( const GameObject& obj ) override;
        void move( float pos );
        void requestJump( );
        void releaseJump( );
    };
}
