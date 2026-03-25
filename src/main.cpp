#include "gengine/engine.hpp"

int main(void) {

    Game::Engine engine {};

    while ( engine ) {
        engine.EventsWindow();

        engine.Update();

        engine.Draw();
    }

    return 0;
}
