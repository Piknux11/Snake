#include "engine.hpp"
#include "../snakeh/snake.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <print>
#include <iostream>
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

        p_snake = new SnakeH {
            .position_     = { WINDOW_WIDTH/2, WINDOW_HEIGHT/2 },
            .acceleration_ = { 0.f, 0.f } 
        };

        if (p_snake == nullptr)
            Engine::~Engine(); 

        p_shape = new sf::RectangleShape {p_snake->size_};

        if (p_shape == nullptr)
            Engine::~Engine();

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

        p_shape->setPosition(p_snake->position_);
    }

    void 
    Engine::Draw() 
    {
        p_window->clear();

        p_window->draw(*p_shape);

        p_window->display();
    }

    Engine::~Engine() 
    {
        if (p_snake != nullptr)
            delete p_snake;

        if (p_shape != nullptr)
            delete p_shape;

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
