void minDisc(Points &points, PV2 &center, Parameter &radius);
void minDiscWithPoint(Points &points, int num, Point *p, PV2 &center, Parameter &radiusSquared);
void minDiscWith2Points(Points &points, int num, Point *p1, Point *p2, PV2 &center, Parameter &radiusSquared);
Parameter lengthSquared(const PV2 &vector);