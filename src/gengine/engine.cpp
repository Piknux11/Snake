#include "engine.hpp"
#include "../snakeh/snake.hpp"
#include <print>
#include <optional>

namespace Game {

    Engine::Engine()
    : RenderWindow(
            sf::VideoMode( { WINDOW_WIDTH, WINDOW_HEIGHT } ),
            TITLE_WINDOW ) 
    {
        this->setFramerateLimit( FRAME_RATE );     

        p_snake = new SnakeH {
            .position_     = { WINDOW_WIDTH/2, WINDOW_HEIGHT/2 },
            .acceleration_ = { 0.f, 0.f } 
        };
        if (p_snake == nullptr)
            Engine::~Engine(); 

        p_shape = new sf::RectangleShape {p_snake->size_};
        if (p_shape == nullptr)
            Engine::~Engine(); 

        while ( this->isOpen() ) {
           EventsWindow();

           clear();

           Update();
           Draw();

           display();
        }
    }

    void
    Engine::EventsWindow() 
    {
        while (const std::optional event { this->pollEvent() }) {
            if ( event->is<sf::Event::Closed>() ) {
                this->close();
            }
        }
    }

    void 
    Engine::Update() {
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
    Engine::Draw() {
        this->draw(*p_shape);
    }

    Engine::~Engine() {
        if (p_snake != nullptr)
            delete p_snake;

        if (p_shape != nullptr)
            delete p_shape;
    }
}
