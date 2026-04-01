#include "gameobject.hpp"
#include <print>

namespace Game {

    GameObject::GameObject( const sf::Vector2f& size,
                            const sf::Vector2f& position )
        : size_     (size) ,
          position_ (position)
    {}

    GameObject::GameObject( const sf::Vector2f& size,
                            const sf::Vector2f& position,
                            const std::string&  tex_path )
        : size_         (size),
          position_     (position), 
          texture_path_ (tex_path) 
    {
        this->checkTexturePath();
    }

    GameObject::GameObject( const sf::Vector2f& position,
                            const std::string&  tex_path )
        : position_     (position),
          texture_path_ (tex_path)
    {
        this->checkTexturePath();
    }

    GameObject::GameObject( const sf::Vector2f& size, 
                            const sf::Vector2f& position, 
                            const std::string&  tex_path, 
                            const std::string&  label ) 
        : size_         (size),
          position_     (position),
          label_        (label),
          texture_path_ (tex_path)
    {
        this->checkTexturePath();
    }

    GameObject::GameObject( const sf::Vector2f& position, 
                            const std::string&  tex_path, 
                            const std::string&  label ) 
        : size_         (position),
          label_        (label),
          texture_path_ (tex_path)
    {
        this->checkTexturePath();
    }

    GameObject::~GameObject() 
    {}

    bool 
    GameObject::aabbOverlap( const GameObject& obj ) const 
    {
        return position_.x < obj.position_.x + obj.size_.x &&
               position_.x + size_.x > obj.position_.x &&
               position_.y < obj.position_.y + obj.size_.y &&
               position_.y + size_.y > obj.position_.y;
    }

    void
    GameObject::checkTexturePath() const 
    {
        if ( std::filesystem::exists( texture_path_ ) ) 
            std::println("The file exists!!");
        else 
            std::println("The file dont find!!");
    }
}
