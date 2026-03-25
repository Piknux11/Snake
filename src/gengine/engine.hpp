#pragma once

#include <string>

namespace sf {
    class RenderWindow;
    class RectangleShape;
}

namespace Game {

    struct Platform;
    struct SnakeH;
    struct Food;

    struct Engine {
            Engine();
            ~Engine();

            static constexpr int WINDOW_WIDTH         { 800 };
            static constexpr int WINDOW_HEIGHT        { 800 };
            static constexpr int FRAME_RATE           { 60 };
            static constexpr float DELTA_TIME         { 1 / static_cast<float>( FRAME_RATE ) };
            static constexpr int DEFAULT_SCORE_GAME   { 0 };
            static constexpr std::string TITLE_WINDOW { "Demo 1.0" };

            [[nodiscard]] operator bool() const;

            void InitWindow();
            void InitVariables();
            void EventsWindow();
            void Update();
            void Draw();

            int score_ { DEFAULT_SCORE_GAME };

            sf::RenderWindow* p_window  { nullptr };
            sf::RectangleShape* p_shape { nullptr };
            sf::RectangleShape* p_shape1{ nullptr };
            sf::RectangleShape* p_shape2{ nullptr };

            Platform* p_plat            { nullptr };
            SnakeH* p_snake             { nullptr };
            Food* p_food                { nullptr };
    };

}
