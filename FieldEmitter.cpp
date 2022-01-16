#include "FieldEmitter.h"

double min(double a, double b) { return a < b ? a : b; }

double max(double a, double b) { return a > b ? a : b; }

PointFieldEmitter::PointFieldEmitter(const point2d &location, double strength) {
    this->location = location;
    this->strength = strength;
}

SegmentFieldEmitter::SegmentFieldEmitter(const point2d &locationA, const point2d &locationB, double strength) {
    this->locationA = locationA;
    this->locationB = locationB;
    this->strength = strength;
}


CompositeFieldEmitter::CompositeFieldEmitter(const std::vector<PointFieldEmitter> &pointEmitters,
                                             const std::vector<SegmentFieldEmitter> &segmentEmitters) : pointEmitters(
        pointEmitters), segmentEmitters(segmentEmitters) {}

double PointFieldEmitter::getFieldAt(point2d point) {
    double d = distance(point, location) + 1;
    return strength / d / d;
}


double SegmentFieldEmitter::getFieldAt(point2d point) {
    point2d closestPoint;
    const float l2 = distance(locationA, locationB) * distance(locationA, locationB);
    if (l2 == 0.0) {
        closestPoint = locationA;
    } else {
        const float t = max(0.0, min(1.0, dot(point - locationA, locationB - locationA) / l2));
        closestPoint = locationA + (locationB - locationA) * t;
    }
    double d = distance(point, closestPoint) + 1;
    return strength / d / d;
}

double CompositeFieldEmitter::getFieldAt(point2d point) {
    double sum = 0;
    for (auto p: pointEmitters)sum += p.getFieldAt(point);
    for (auto p: segmentEmitters)sum += p.getFieldAt(point);
    return sum;
}

void CompositeFieldEmitter::add(PointFieldEmitter pfe) {
    pointEmitters.push_back(pfe);
}

void CompositeFieldEmitter::add(SegmentFieldEmitter sfe) {
    segmentEmitters.push_back(sfe);
}

CompositeFieldEmitter::CompositeFieldEmitter() {}
