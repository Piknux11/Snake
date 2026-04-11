#pragma once

#include "../dynamicobject.hpp"

namespace Game {

    struct Player : public DynamicObject {

        static constexpr float MOVE_SPEED          { 200.f };
        static constexpr float JUMP_FORCE          { 500.f };
        static constexpr float FRICTION            { 0.70f };

        bool jump_requested_   { false }; 

        Player( const sf::Vector2f& size,
               const sf::Vector2f& position,
               const std::string&  label = "Player",
               const std::string&  tex_path = "" ); 

       ~Player();

        [[deprecated]] void update( float delta_time ) override;
        [[deprecated]] void resolveCollision( GameObject& obj ) override;

        void updateX ( float delta_time );
        void updateY ( float delta_time );
        void resolveCollisionX( const GameObject& obj );
        void resolveCollisionY( const GameObject& obj );

        void move( float pos, 
                   float delta_time );
        void friction();
        void jump( float delta_time );
        void requestJump( );
        //void releaseJump( );
    };
}
