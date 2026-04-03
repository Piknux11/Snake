#pragma once

#include "../gameobject.hpp"

namespace Game {

    struct DynamicObject : public GameObject {

        static constexpr float DEFAULT_ACCELERATION_X { 7500.f };
        static constexpr float DEFAULT_ACCELERATION_Y { 980.f };
        static constexpr float DEFAULT_VELOCITY_X     { 0.f };
        static constexpr float DEFAULT_VELOCITY_Y     { 0.f };
        static constexpr float MAX_FALL_SPEED         { 800.f };

        sf::Vector2f velocity_     { DEFAULT_VELOCITY_X, DEFAULT_VELOCITY_Y };
        sf::Vector2f acceleration_ { DEFAULT_ACCELERATION_X, DEFAULT_ACCELERATION_Y };
        bool         on_ground_    { false };

        DynamicObject( const sf::Vector2f& size,
                       const sf::Vector2f& position,
                       const std::string&  label = "object",
                       const std::string&  tex_path = "" );

        ~DynamicObject();

        virtual void update( const float& delta_time );
        virtual void resolveCollision( const GameObject& obj );
        void applyGravity( const float& delta_time );
    };
}
