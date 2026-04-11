#pragma once

#include "../gameobject.hpp"

namespace Game {

    struct DynamicObject : public GameObject {

        static constexpr float DEFAULT_ACCELERATION_X { 0.f };
        static constexpr float DEFAULT_ACCELERATION_Y { 0.f };
        static constexpr float DEFAULT_VELOCITY_X     { 0.f };
        static constexpr float DEFAULT_VELOCITY_Y     { 0.f };
        static constexpr float GRAVITY                { 981.f };
        static constexpr float MAX_FALL_SPEED         { 900.f };

        sf::Vector2f velocity_     { DEFAULT_VELOCITY_X, DEFAULT_VELOCITY_Y };
        sf::Vector2f acceleration_ { DEFAULT_ACCELERATION_X, DEFAULT_ACCELERATION_Y };
        bool         on_ground_    { false };

        DynamicObject( const sf::Vector2f& size,
                       const sf::Vector2f& position,
                       const std::string&  label = "object",
                       const std::string&  tex_path = "" );

        ~DynamicObject();

        [[deprecated]] virtual void update( float delta_time );
        [[deprecated]] virtual void resolveCollision( GameObject& );

        //virtual void updateX();
        //virtual void updateY();
        //virtual void resolveCollisionX( const GameObject& obj );
        //virtual void resolveCollisionY( const GameObject& obj );

        void applyGravity( float delta_time );
    };
}
