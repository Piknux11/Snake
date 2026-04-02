#include "engine.hpp"
#include "../gameobject/gameobject.hpp"
#include "../gameobject/staticobject/staticobject.hpp"
#include "../gameobject/staticobject/platform/platform.hpp"
#include "../gameobject/dynamicobject/dynamicobject.hpp"
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
            ( sf::Vector2f( 50.f, 50.f ), 
              sf::Vector2f( 250.f, 400.f ) );

        p_caja = std::make_unique<DynamicObject>
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
        /*
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) ) {
            p_snake->acceleration_.x = -1.f * SnakeH::DEFAULT_ACCELERATION_X;
            p_snake->acceleration_.y = 0;
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) ) {
            p_snake->acceleration_.x = SnakeH::DEFAULT_ACCELERATION_X;
            p_snake->acceleration_.y = 0;
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up )) {
            p_snake->acceleration_.y = -1.f * SnakeH::DEFAULT_ACCELERATION_Y;
            p_snake->acceleration_.x = 0;
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down )) {
            p_snake->acceleration_.y = SnakeH::DEFAULT_ACCELERATION_Y;
            p_snake->acceleration_.x = 0;
        }

        p_snake->position_.x += DELTA_TIME * p_snake->acceleration_.x;
        p_snake->position_.y += DELTA_TIME * p_snake->acceleration_.y;

        p_plat->resolveCollision(*p_snake);
        p_food->resolveCollision(*p_snake);
        */
        p_caja->update(DELTA_TIME);
        p_caja->resolveCollision(*p_platform);
        p_platform->resolveCollision(*p_caja);
    }

    void 
    Engine::Draw() 
    {
        p_window->clear();

        shape->setPosition(p_caja->position_);
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
        p_caja.reset();
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
