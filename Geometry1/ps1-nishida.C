#include <vector>
#include "point.h"

using namespace std;

/**
 * Return the squared length of the vector.
 */
Parameter lengthSquared(const PV2 &vector) {
	return vector.dot(vector);
}

/**
 * Given two points, compute the minimum disc that contains all the points.
 * The given two points have to be on the boundary of the minimum disc.
 * If a point p is outside the disc, we should create a disc such that p is on its boundary.
 */
void minDiscWith2Points(Points &points, int num, Point *p1, Point *p2, PV2 &center, Parameter &radiusSquared) {
	center = (p1->getP() + p2->getP()) * 0.5;
	radiusSquared = lengthSquared(p1->getP() - center);

	for (int i = 0; i < num; i++) {
		if (lengthSquared(points[i]->getP() - center) > radiusSquared) {
			center = circumCenter(p1->getP(), p2->getP(), points[i]->getP());
			radiusSquared = lengthSquared(p1->getP() - center);
		}
	}
}

/**
 * Given one point, compute the minimum disc that contains all the points.
 * The given point has to be on the boundary of the minimum disc.
 * If a point p is outside the disc, we should create a disc such that p is on its boundary.
 */
void minDiscWithPoint(Points &points, int num, Point *p, PV2 &center, Parameter &radiusSquared) {
	center = (p->getP() + points[0]->getP()) * 0.5;
	radiusSquared = lengthSquared(p->getP() - center);
		
	for (int i = 1; i < num; ++i) {
		if (lengthSquared(points[i]->getP() - center) > radiusSquared) {
			/*
			Points points2;
			points.reserve(i - 1);
			copy(points.begin(), points.begin() + i, back_inserter(points2));
			*/

			minDiscWith2Points(points, i, p, points[i], center, radiusSquared);
		}
	}
}

/**
 * Compute the minimum disc that contains all the given points.
 * The center and the radius of the minimum disc will be returned as arguments of this function.
 */
void minDisc(Points &points, PV2 &center, Parameter &radius) {
	center = (points[0]->getP() + points[1]->getP()) * 0.5;
	Parameter radiusSquared = lengthSquared(points[0]->getP() - center);

	for (int i = 2; i < points.size(); ++i) {
		if (lengthSquared(points[i]->getP() - center) > radiusSquared) {
			/*
			Points points2;
			points.reserve(i - 2);
			copy(points.begin(), points.begin() + i, back_inserter(points2));
			*/

			//minDiscWithPoint(points2, points[i], center, radiusSquared);
			minDiscWithPoint(points, i, points[i], center, radiusSquared);
		}
	}

	radius = radiusSquared.sqrt();
}
