#pragma once

#include "../dynamicobject.hpp"

namespace Game {

    struct Player : public DynamicObject {

        static constexpr float JUMP         { 45000.f };
        static constexpr float MAXIMUN_JUMP { 10000.f};

        Player( const sf::Vector2f& size,
               const sf::Vector2f& position,
               const std::string&  label = "Player",
               const std::string&  tex_path = "" ); 

       ~Player();

        void update( const float& delta_time ) override;
        void resolveCollision( const GameObject& obj ) override;

        void move( const short& pos,
                   const float& delta_time );

        void jump( const float& delta_time );
    };
}
