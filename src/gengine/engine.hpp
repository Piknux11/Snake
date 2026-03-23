#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>

namespace Game {

    struct SnakeH;

    class Engine : public sf::RenderWindow {
        public:
            Engine();
            ~Engine();

        private:
            static constexpr int WINDOW_WIDTH  { 800 };
            static constexpr int WINDOW_HEIGHT { 800 };

            static constexpr std::string TITLE_WINDOW { "Snake" };

            static constexpr int FRAME_RATE   { 10 };
            static constexpr float DELTA_TIME { 1 / static_cast<float>( FRAME_RATE ) };

            static constexpr int DEFAULT_SCORE_GAME { 0 };

            void EventsWindow();
            void Update();
            void Draw();

            int score_ { DEFAULT_SCORE_GAME };

            SnakeH* p_snake             { nullptr };
            sf::RectangleShape* p_shape { nullptr };
    };

}
