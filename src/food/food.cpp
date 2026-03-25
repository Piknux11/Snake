#include "food.hpp"

namespace Game {

    Food::Food() 
        : GameObject( { 0.f, 0.f } , 
                      { 0.f, 0.f } )
    {
            position_.x = dist(gen);
            position_.y = dist(gen);
    }

    Food::~Food() {}


    void 
    Food::resolveCollision( const GameObject& obj ) {
        if ( aabbOverlap( obj ) ) {
            position_.x = dist(gen);
            position_.y = dist(gen);
        }
    }
}
