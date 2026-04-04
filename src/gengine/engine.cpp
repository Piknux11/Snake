#include "engine.hpp"
#include "../gameobject/gameobject.hpp"
#include "../gameobject/staticobject/staticobject.hpp"
#include "../gameobject/staticobject/platform/platform.hpp"
#include "../gameobject/dynamicobject/dynamicobject.hpp"
#include "../gameobject/dynamicobject/player/player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <print>
#include <optional>

namespace Game {

    Engine::Engine()
    {
        this->InitWindow();
        this->InitVariables();
    }

    void 
    Engine::InitWindow() 
    {
        p_window = std::make_unique<sf::RenderWindow>
            (
                sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
                TITLE_WINDOW
            );

        if ( p_window == nullptr ) {
            std::println("Error to init Window");
            Engine::~Engine();
        }

        p_window->setFramerateLimit( FRAME_RATE );
    }

    void
    Engine::InitVariables() 
    {

        p_platform = std::make_unique<Platform>
            ( sf::Vector2f( 200.f, 50.f ), 
              sf::Vector2f( 250.f, 400.f ) );

        p_player = std::make_unique<Player>
            ( sf::Vector2f( 50.f, 50.f ), 
              sf::Vector2f( 250.f, 1.f ) );

        shape = std::make_unique<sf::RectangleShape>
            ( sf::Vector2f( 50.f, 50.f ) );
    }

    void
    Engine::EventsWindow() 
    {
        while (const std::optional event { p_window->pollEvent() }) {
            if ( event->is<sf::Event::Closed>() ) {
                p_window->close();
            }
        }
    }

    void 
    Engine::Update() 
    {
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) ) {
            p_player->move(-1);
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) ) {
            p_player->move(1);
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Space )) {
            p_player->requestJump();
        }
        else {
            p_player->releaseJump();
        }

        p_player->update( DELTA_TIME );
        p_player->resolveCollision( *p_platform );
        p_platform->resolveCollision( *p_player );
    }

    void 
    Engine::Draw() 
    {
        p_window->clear();

        shape->setPosition(p_player->position_);
        p_window->draw(*shape);

        shape->setPosition(p_platform->position_);
        p_window->draw(*shape);

        p_window->display();
    }

    Engine::~Engine() 
    {
        p_window.reset();
        shape.reset();
        p_platform.reset();
        p_player.reset();
    }

    Engine::operator 
    bool() const 
    {
        bool band = false;

        if (p_window != nullptr) 
            band = p_window->isOpen();

        return band;
    }
}
