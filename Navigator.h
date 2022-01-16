#ifndef FIELDNAVIGATOR_NAVIGATOR_H
#define FIELDNAVIGATOR_NAVIGATOR_H

#include "point2D.h"
#include "FieldEmitter.h"

point2d gradient(CompositeFieldEmitter em, point2d p) {
    point2d a = {0.01, 0};
    point2d b = {0, 0.01};

    double dx = em.getFieldAt(p + a) - em.getFieldAt(p);
    double dy = em.getFieldAt(p + b) - em.getFieldAt(p);

    return {dx, dy};
}

class Navigator {
public:
    point2d position;
    point2d velocity;
    double maxSpeed;

    Navigator(const point2d &position, double maxSpeed) : position(position), maxSpeed(maxSpeed) {velocity = {0,0};}

    void step(CompositeFieldEmitter em) {
        velocity = velocity - gradient(em, position);
        double speed = length(velocity);
        if (speed > maxSpeed) {
            velocity = velocity * maxSpeed * (1/speed);
        }
        position = position + velocity;
    }

    void print(){
        std::cout<<"pos: "<<position<<", vel: "<<velocity<<"\n";
    }
};


#endif //FIELDNAVIGATOR_NAVIGATOR_H
