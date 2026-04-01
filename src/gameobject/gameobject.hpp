#pragma once

#include <string>
#include <filesystem>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Game {

    struct GameObject {
        static constexpr std::string DEFAULT_TEXTURE_PATH { "../../public/" };
        static constexpr std::string DEFAULT_LABEL        { "object" };
        static constexpr float DEFAULT_SIZE_OBJ_X         { 50.f };
        static constexpr float DEFAULT_SIZE_OBJ_Y         { 50.f };
        static constexpr float DEFAULT_POSITION_X         { 0.f };
        static constexpr float DEFAULT_POSITION_Y         { 0.f };

        sf::Vector2f size_                   { DEFAULT_SIZE_OBJ_X, DEFAULT_SIZE_OBJ_Y };
        sf::Vector2f position_               { DEFAULT_POSITION_X, DEFAULT_POSITION_Y };
        std::string  label_                  { DEFAULT_LABEL };
    	std::filesystem::path texture_path_  { DEFAULT_TEXTURE_PATH };

        GameObject(const sf::Vector2f&, const sf::Vector2f&);
        GameObject(const sf::Vector2f&, const sf::Vector2f&, const std::string&);
        GameObject(const sf::Vector2f&, const std::string&);

        GameObject(const sf::Vector2f&, const sf::Vector2f&, const std::string&, const std::string&);
        GameObject(const sf::Vector2f&, const std::string&, const std::string&);

        virtual ~GameObject();

        virtual bool aabbOverlap(const GameObject&) const;
        void checkTexturePath() const;
    };

}
