#include "engine.hpp"
#include "../snakeh/snake.hpp"
#include "../platform/platform.hpp"
#include "../food/food.hpp"
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
        p_window = new sf::RenderWindow(
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

        p_plat = new Platform (
            { WINDOW_WIDTH/3, WINDOW_HEIGHT/3 }, 
            { 0.f, 0.f }
        );

        p_snake = new SnakeH (
            { WINDOW_WIDTH/2, WINDOW_HEIGHT/2 }, 
            { 0.f, 0.f } 
        );

        p_food = new Food( "public/sprites/apple.png" );

        p_sprite_apple = new sf::Sprite(p_food->texture_);
        p_sprite_apple->scale( { 3.5f, 3.5f } );

        p_shape = new sf::RectangleShape {p_snake->size_};
        p_shape1 = new sf::RectangleShape {p_plat->size_};


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

        p_shape->setPosition(p_snake->position_);
        p_shape1->setPosition(p_plat->position_);
        p_sprite_apple->setPosition(p_food->position_);

    }

    void 
    Engine::Draw() 
    {
        p_window->clear();

        p_window->draw(*p_shape);
        p_window->draw(*p_shape1);
        p_window->draw(*p_sprite_apple);

        p_window->display();
    }

    Engine::~Engine() 
    {
        if (p_food != nullptr)
            delete p_food;

        if (p_sprite_apple != nullptr )
            delete p_sprite_apple;

        if (p_plat != nullptr)
            delete p_plat;

        if (p_snake != nullptr)
            delete p_snake;

        if (p_shape != nullptr)
            delete p_shape;

        if (p_shape1 != nullptr)
            delete p_shape1;

        if (p_window != nullptr)
            delete p_window;
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
