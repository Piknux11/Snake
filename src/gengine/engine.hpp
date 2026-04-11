#pragma once

#include <string>
#include <array>
#include <memory>

namespace sf {
    class RenderWindow;
    class RectangleShape;
    class Sprite;
    class View;
}

namespace Game {

    struct GameObject;
    struct StaticObject;
    struct DynamicObject;
    struct Player;
    struct Platform;

    struct Engine {
            Engine();
            ~Engine();

            static constexpr int WINDOW_WIDTH         { 10 * 50 };
            static constexpr int WINDOW_HEIGHT        { 10 * 50 };
            static constexpr int FRAME_RATE           { 60 };
            static constexpr float DELTA_TIME         { 1 / static_cast<float>( FRAME_RATE ) };
            static constexpr float VIEW_WIDTH         { 400.f };
            static constexpr float VIEW_HEIGHT        { 400.f };
            static constexpr int DEFAULT_SCORE_GAME   { 0 };
            static constexpr std::string TITLE_WINDOW { "Demo 1.0" };

            [[nodiscard]] operator bool() const;

            void InitWindow();
            void InitVariables();
            void EventsWindow();
            void Update();
            void Draw();
            void LoadLevel();
            void UpdateView();

            int score_ { DEFAULT_SCORE_GAME };

            std::unique_ptr<sf::RenderWindow>          p_window  { nullptr };
            std::unique_ptr<sf::RectangleShape>        shape     { nullptr };
            std::array<std::unique_ptr<Platform>, 30>  platforms { nullptr };
            std::unique_ptr<Player>                    p_player  { nullptr };
            std::unique_ptr<sf::View>                  p_pview   { nullptr };
    };

}
