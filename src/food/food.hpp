#pragma once

#include "../gameobject/gameobject.hpp"
#include <random>

namespace Game {

    struct Food : public GameObject {

        Food();
        ~Food();

        void resolveCollision( const GameObject& );

        private:
        std::random_device rd;
        std::mt19937 gen                           { rd() };
        std::uniform_real_distribution<float> dist { 0.f, 800.f };
    };
}
