#include <vector>
#include "point.h"

using namespace std;

void minDisc(Points &points, PV2 &center, double &radius) {
	for (int i = 3; i < points.size(); ++i) {
		if (PointInCircumcircle(points[i], points[0], points[1], points[1]) == -1) {
			Points points2;
			copy(points.begin(), points.end(), points2.begin())
			minDiscWithPoint(points2, points[i], center, radius);
		}
	}
}

void minDiscWithPoint(Points &points, Point* p, PV2 &center, double &radius) {
	center = (p->getP() + points[0]->getP()) * 0.5;
	radius = (center - p->getP()).dot(center - p->getP()).lb();

	for (int i = 2; i < points.size(); ++i) {
		if (PointInCircumcircle(points[i], points[0], p, p) == -1) {
			Points points2;
			copy(points.begin(), points.end(), points2.begin());
			minDiscWith2Points(points2, p, points[i], center, radius);
		}
	}
}

void minDiscWith2Points(Points &points, Point *p1, Point *p2, PV2 &center, double &radius) {
	center = (p1->getP() + p2->getP()) * 0.5;
	radius = (center - p1->getP()).dot(center - p1->getP()).lb();

	PV2 p3 = p2->getP();

	for (int i = 0; i < points.size(); i++) {
		if (PointInCircumcircle(points[i], p1, p2, p2) == -1) {
			center = circumCenter(p1->getP(), p2->getP(), points[i]->getP());
			radius = (center - p1->getP()).dot(center - p1->getP()).lb();
		}
	}
}
