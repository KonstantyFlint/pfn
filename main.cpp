#include <iostream>

#include "point2D.h"
#include "FieldEmitter.h"
#include "Navigator.h"

using namespace std;

int main() {

    SegmentFieldEmitter segment1({20, 20}, {15, 0}, 1);
    SegmentFieldEmitter segment2({10, -20}, {5, 0}, 1);
    PointFieldEmitter goal({0, 0}, -100);

    CompositeFieldEmitter comp;
    comp.add(segment1);
    comp.add(segment2);
    comp.add(goal);

    Navigator navigator({20, 0}, 1);

    for (int i = 0; i < 1000; i++) {
        navigator.step(comp);
        navigator.print();
    }
}
