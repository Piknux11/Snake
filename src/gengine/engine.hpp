#pragma once

#include <string>
#include <memory>

namespace sf {
    class RenderWindow;
    class RectangleShape;
    class Sprite;
}

namespace Game {

    struct GameObject;
    struct StaticObject;
    struct DynamicObject;
    struct Platform;

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

            std::unique_ptr<sf::RenderWindow> p_window  { nullptr };
            std::unique_ptr<sf::RectangleShape> shape   { nullptr };
            std::unique_ptr<Platform>       p_platform  { nullptr };
            std::unique_ptr<DynamicObject>  p_caja      { nullptr };
    };

}
