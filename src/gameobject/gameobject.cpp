#include "gameobject.hpp"
#include <print>

namespace Game {

    GameObject::GameObject ( const sf::Vector2f& pos, 
                             const sf::Vector2f& acc ) 
        : position_(pos),
          acceleration_(acc)
    {}

    GameObject::GameObject ( const sf::Vector2f& pos,
                             const std::filesystem::path& tex ) 
        : position_(pos),
          texture_path_ (tex)
    {
        if ( ! texture_.loadFromFile( texture_path_.string() ) ) {
            std::println("La textura no se cargo");
        }
        else {
            std::println("{}", texture_path_.filename().c_str());
        }
    }

    GameObject::GameObject ( const sf::Vector2f& pos,
                             const sf::Vector2f& acc,
                             const std::filesystem::path& tex ) 
        : position_     ( pos ),
          acceleration_ ( acc ),
          texture_path_ ( tex )
    {
        if ( ! texture_.loadFromFile( texture_path_.string() ) ) {
            std::println("La textura no se cargo");
        }
        else {
            std::println("{}", texture_path_.filename().c_str());
        }
    }

    GameObject::~GameObject() 
    {}

    bool 
    GameObject::aabbOverlap ( const GameObject& obj ) const {
        return position_.x < obj.position_.x + obj.size_.x &&
               position_.x + size_.x > obj.position_.x &&
               position_.y < obj.position_.y + obj.size_.y &&
               position_.y + size_.y > obj.position_.y;
    }
}
