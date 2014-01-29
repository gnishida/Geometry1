#include "point.h"
#include "ps1-nishida.h"

int main() {
	InputPoint p1(0, 0);
	InputPoint p2(10, 0);
	InputPoint p3(10, 10);

	Points points;
	points.push_back(&p1);
	points.push_back(&p2);
	points.push_back(&p3);

	InputPoint center(10, 10);
	double radius;
	mindisc(points, center, radius);

	std::cout << "Center: (" << center.getP().getX().lb() << ", " << center.getP().getY().lb() << ")" << std::endl;
	std::cout << "Radius: " << radius << std::endl;

	return 0;
}
