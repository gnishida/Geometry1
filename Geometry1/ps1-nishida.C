#include <vector>
#include "point.h"

using namespace std;

/**
 * Return the squared length of the vector.
 *
 * @param vector	the vector
 * @return			the squared length of the vector
 */
Parameter lengthSquared(const PV2 &vector) {
	return vector.dot(vector);
}

/**
 * Given two points, compute the minimum disc that contains all the points.
 * The given two points have to be on the boundary of the minimum disc.
 * If a point p is outside the disc, we should create a disc such that p is on its boundary.
 *
 * @param points		the point list
 * @param num			only the first num points are used for this computation.
 * @param p1			one of the given two points which should be on he boundary of the minimum disc
 * @param p2			the other point
 * @param center		the resulting center of the minimum disc
 * @param radiusSquared	the resulting squared radius of the minimum disc
 */
void minDiscWith2Points(Points &points, int num, Point *p1, Point *p2, PV2 &center, Parameter &radiusSquared) {
	// create the minimum disc by using the given two points
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
 *
 * @param points		the point list
 * @param num			only the first num points are used for this computation.
 * @param p				the given point which should be on he boundary of the minimum disc
 * @param center		the resulting center of the minimum disc
 * @param radiusSquared	the resulting squared radius of the minimum disc
 */
void minDiscWithPoint(Points &points, int num, Point *p, PV2 &center, Parameter &radiusSquared) {
	// create the minimum disc by using the first point and the given point
	center = (p->getP() + points[0]->getP()) * 0.5;
	radiusSquared = lengthSquared(p->getP() - center);
		
	for (int i = 1; i < num; ++i) {
		if (lengthSquared(points[i]->getP() - center) > radiusSquared) {
			minDiscWith2Points(points, i, p, points[i], center, radiusSquared);
		}
	}
}

/**
 * Compute the minimum disc that contains all the given points.
 * The center and the radius of the minimum disc will be returned as arguments of this function.
 *
 * @param points		the point list that should be enclosed by the minimum disc
 * @param center		the resulting center of the minimum disc
 * @param radius		the resulting radius of the minimum disc
 */
void minDisc(Points &points, PV2 &center, Parameter &radius) {
	assert(points.size() >= 3);

	// create the minimum disc by using the first two points
	center = (points[0]->getP() + points[1]->getP()) * 0.5;
	Parameter radiusSquared = lengthSquared(points[0]->getP() - center);

	for (int i = 2; i < points.size(); ++i) {
		if (lengthSquared(points[i]->getP() - center) > radiusSquared) {
			minDiscWithPoint(points, i, points[i], center, radiusSquared);
		}
	}

	radius = radiusSquared.sqrt();
}
