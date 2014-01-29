#include <vector>
#include "point.h"

using namespace std;

void minDisc(Points &points, PV2 &center, Parameter &radius);

int main() {
	Points points;	
	for (int i = 0; i < 10; i++) {
		points.push_back(new InputPoint(acp::randomNumber(0, 100), acp::randomNumber(0, 100)));
		std::cout << "(" << points[i]->getP().getX().mid() << ", " << points[i]->getP().getX().mid() << ")" << std::endl;
	}

	PV2 center;
	Parameter radius;
	minDisc(points, center, radius);

	std::cout << "Center: (" << center.getX().mid() << ", " << center.getY().mid() << ")" << std::endl;
	std::cout << "Radius: " << radius.mid() << std::endl;

	return 0;
}
