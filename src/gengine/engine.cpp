#include "engine.hpp"
#include "../gameobject/gameobject.hpp"
#include "../gameobject/staticobject/staticobject.hpp"
#include "../gameobject/staticobject/platform/platform.hpp"
#include "../gameobject/dynamicobject/dynamicobject.hpp"
#include "../gameobject/dynamicobject/player/player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <print>
#include <optional>
#include <cmath>

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

        p_pview = std::make_unique<sf::View>
            (
                sf::Vector2f( WINDOW_WIDTH/2, WINDOW_HEIGHT/2 ),
                sf::Vector2f( VIEW_WIDTH, VIEW_HEIGHT )
            );

        p_window->setView(*p_pview);
        p_window->setFramerateLimit( FRAME_RATE );
    }

    void
    Engine::InitVariables() 
    {

        this->LoadLevel(); 

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
            p_player->move(-1, DELTA_TIME);
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) ) {
            p_player->move(1, DELTA_TIME);
        }

        p_player->friction(); 
        p_player->updateX( DELTA_TIME );

        for (auto& plat : platforms) {
            if (plat != nullptr)
                p_player->resolveCollisionX( *plat );
        }


        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Space )) {
            p_player->requestJump();
        }

        p_player->jump( DELTA_TIME );
        p_player->applyGravity( DELTA_TIME );
        p_player->updateY( DELTA_TIME ); 

        for ( auto& plat : platforms ) {
            if ( plat != nullptr )
                p_player->resolveCollisionY( *plat );
        }

        this->UpdateView();
        
    }

    void 
    Engine::Draw() 
    {
        p_window->clear();

        shape->setPosition(p_player->position_);
        p_window->draw(*shape);

        for (int i=0 ; i<(int)platforms.size() ; i++) {
            if (platforms.at(i) != nullptr) {
                shape->setPosition(platforms.at(i)->position_);
                p_window->draw(*shape);
            }
        }

        p_window->display();
    }

    void
    Engine::LoadLevel()
    {
        // 0 nada bloque vacio
        // 1 bloques 
        // 2 player, esto es temporal
        
        size_t pos = 0;
        int eje[10][10] = 
        { { 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0 }, 
          { 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0 }, 
          { 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0 }, 
          { 0, 0, 0 ,0 ,0 ,1 ,1 ,1, 0, 0 }, 
          { 1, 1, 1 ,0 ,0 ,0 ,0 ,0, 1, 0 }, 
          { 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0 }, 
          { 0, 0, 0 ,0 ,0 ,0 ,0 ,1, 0, 1 }, 
          { 2, 0, 0 ,0 ,1 ,1 ,0 ,1, 1, 0 }, 
          { 1, 1, 1 ,1 ,0 ,0 ,1 ,0, 0, 0 }, 
          { 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0 } };

        for (int i=0 ; i<10 ; i++) {
            for (int j=0 ; j<10 ; j++) {
                if (eje[i][j] == 1) {
                    platforms.at(pos) = std::make_unique<Platform>
                        (
                            sf::Vector2f( 50.f, 50.f ),
                            sf::Vector2f( j * 50.f, i * 50.f )
                        );
                    pos++;
                }
                else if (eje[i][j] == 2) {
                    p_player = std::make_unique<Player>
                        ( 
                            sf::Vector2f( 50.f, 50.f ), 
                            sf::Vector2f( j * 50.f , i * 50.f ) 
                        );
                }
            }
        }
    }

    void
    Engine::UpdateView()
    {
        // La cámara sigue al jugador con un offset para ver más adelante
        sf::Vector2f target = p_player->position_;

        // Limitar la cámara para que no muestre fuera del mundo
        // Ajusta estos valores al tamaño de tu nivel
        const float WORLD_LEFT   {   0.f };
        const float WORLD_RIGHT  { 2000.f };
        const float WORLD_TOP    {   0.f };
        const float WORLD_BOTTOM { 800.f };

        // Clamp: la cámara no se sale del mundo
        target.x = std::max( target.x, WORLD_LEFT   + VIEW_WIDTH  / 2.f );
        target.x = std::min( target.x, WORLD_RIGHT  - VIEW_WIDTH  / 2.f );
        target.y = std::max( target.y, WORLD_TOP    + VIEW_HEIGHT / 2.f );
        target.y = std::min( target.y, WORLD_BOTTOM - VIEW_HEIGHT / 2.f );

        p_pview->setCenter( target );
        p_window->setView( *p_pview );
    }

    Engine::~Engine() 
    {}

    Engine::operator 
    bool() const 
    {
        bool band = false;

        if (p_window != nullptr) 
            band = p_window->isOpen();

        return band;
    }
}
