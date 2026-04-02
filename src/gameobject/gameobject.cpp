#include "gameobject.hpp"
#include <print>

namespace Game {

    GameObject::GameObject( const sf::Vector2f& size, 
                            const sf::Vector2f& position, 
                            const std::string&  label, 
                            const std::string&  tex_path )
        : size_         (size),
          position_     (position),
          label_        (label)
    {
        this->loadTexture( tex_path );
    }

    /*
    GameObject::~GameObject() 
    {}
    */

    bool 
    GameObject::aabbOverlap( const GameObject& obj ) const 
    {
        return position_.x < obj.position_.x + obj.size_.x &&
               position_.x + size_.x > obj.position_.x &&
               position_.y < obj.position_.y + obj.size_.y &&
               position_.y + size_.y > obj.position_.y;
    }

    bool
    GameObject::loadTexture( const std::string& path )
    {
        if ( !std::filesystem::exists( path ) ) {
            std::println("[{}] The texture didnt find: {}", label_, path);
            return false;
        }

        texture_ = path;
        std::println("The texture was load: {}", label_, path);
        return true;
    }
}
