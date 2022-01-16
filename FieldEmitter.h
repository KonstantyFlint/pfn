#ifndef FIELDNAVIGATOR_FIELDEMITTER_H
#define FIELDNAVIGATOR_FIELDEMITTER_H

#include <vector>
#include "point2D.h"

class PointFieldEmitter{
public:
    point2d location;
    double strength;
    PointFieldEmitter(const point2d &location, double strength);

    double getFieldAt(point2d point);
};

class SegmentFieldEmitter{
public:
    point2d locationA;
    point2d locationB;
    double strength;
    SegmentFieldEmitter(const point2d &locationA, const point2d &locationB, double strength);

    double getFieldAt(point2d point);
};

class CompositeFieldEmitter{
public:
    std::vector<PointFieldEmitter> pointEmitters;
    std::vector<SegmentFieldEmitter> segmentEmitters;

    CompositeFieldEmitter();

    CompositeFieldEmitter(const std::vector<PointFieldEmitter> &pointEmitters,
                          const std::vector<SegmentFieldEmitter> &segmentEmitters);

    void add(PointFieldEmitter pfe);
    void add(SegmentFieldEmitter sfe);

    double getFieldAt(point2d point);
};

#include "FieldEmitter.cpp"

#endif //FIELDNAVIGATOR_FIELDEMITTER_H