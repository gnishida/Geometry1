#include "point.h"
#include "ps1-nishida.h"

int main() {
	InputPoint p0(0, 10);
	InputPoint p1(0, 0);
	InputPoint p2(10, 1);
	InputPoint p3(10, 10);
	InputPoint p4(20, 20);
	InputPoint p5(20, -10);

	Points points;
	points.push_back(&p0);
	points.push_back(&p1);
	points.push_back(&p2);
	points.push_back(&p3);
	points.push_back(&p4);
	points.push_back(&p5);

	PV2 center(10, 10);
	Parameter radius;
	minDisc(points, center, radius);

	std::cout << "Center: (" << center.getX().lb() << ", " << center.getY().lb() << ")" << std::endl;
	std::cout << "Radius: " << radius.lb() << std::endl;

	return 0;
}
