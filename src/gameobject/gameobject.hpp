#pragma once

#include <string>
#include <filesystem>
#include <SFML/System/Vector2.hpp>

namespace Game {

    struct GameObject {
        static constexpr float DEFAULT_SIZE_OBJ_X         { 50.f };
        static constexpr float DEFAULT_SIZE_OBJ_Y         { 50.f };
        static constexpr float DEFAULT_POSITION_X         { 0.f };
        static constexpr float DEFAULT_POSITION_Y         { 0.f };

        sf::Vector2f size_                   { DEFAULT_SIZE_OBJ_X, DEFAULT_SIZE_OBJ_Y };
        sf::Vector2f position_               { DEFAULT_POSITION_X, DEFAULT_POSITION_Y };
        std::string  label_                  { "object" };
    	std::filesystem::path texture_;

        GameObject( const sf::Vector2f& size, 
                    const sf::Vector2f& position, 
                    const std::string&  label     = "object",
                    const std::string&  tex_path  = "" );

        virtual ~GameObject() = default;

        virtual bool aabbOverlap( const GameObject& obj ) const;

        private:
        bool loadTexture( const std::string& path );
    };

}
