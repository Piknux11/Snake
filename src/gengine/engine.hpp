#pragma once

#include <string>

namespace sf {
    class RenderWindow;
    class RectangleShape;
}

namespace Game {

    struct SnakeH;

    struct Engine {
            [[nodiscard]] Engine();
            ~Engine();

            static constexpr int WINDOW_WIDTH         { 800 };
            static constexpr int WINDOW_HEIGHT        { 800 };
            static constexpr int FRAME_RATE           { 10 };
            static constexpr float DELTA_TIME         { 1 / static_cast<float>( FRAME_RATE ) };
            static constexpr int DEFAULT_SCORE_GAME   { 0 };
            static constexpr std::string TITLE_WINDOW { "Demo 1.0" };

            operator bool() const;

            void InitWindow();
            void InitVariables();
            void EventsWindow();
            void Update();
            void Draw();

            int score_ { DEFAULT_SCORE_GAME };

            sf::RenderWindow* p_window  { nullptr };
            sf::RectangleShape* p_shape { nullptr };

            SnakeH* p_snake             { nullptr };
    };

}
