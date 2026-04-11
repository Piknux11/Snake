#include "platform.hpp"

namespace Game {

    Platform::Platform( const sf::Vector2f& size,
                        const sf::Vector2f& position,
                        const std::string&  label,
                        const std::string&  tex_path )
        : StaticObject(size, position, label, tex_path)
    {}

    Platform::~Platform()
    {}

    void
    Platform::resolveCollision( GameObject& obj )
    {
    }
}
