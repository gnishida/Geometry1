#ifndef POINT
#define POINT

#include "object.h"
#include <vector>
#include <iomanip>

using namespace std;
using namespace acp;

class Point : public Object {
 private:
  Parameters getParameters () { return Parameters(p); }
 protected:
  PV2 p;
 public:
  PV2 getP () { return p; }
  virtual Point * copy () const = 0;
};

typedef vector<Point *> Points;

Predicate1(XSign, Point*, a);

Predicate1(YSign, Point*, a);

Predicate2(XOrder, Point*, a, Point*, b);

Predicate2(YOrder, Point*, a, Point*, b);

Predicate2(NormOrder, Point*, a, Point*, b);

Predicate2(CCW, Point*, a, Point*, b);

Predicate3(LeftTurn, Point*, a, Point*, b, Point*, c);

Predicate4(PointInCircumcircle, Point *, p, Point *, a, Point *, b, Point *, c);

class InputPoint : public Point {
 private:
  Objects getObjects () { return Objects(); }
  void calculate () {}
  InputPoint (const PV2 &ip) { p = ip; }
 public:
  InputPoint (double x, double y) { p = PV2(x, y); }
  InputPoint * copy () const { return new InputPoint(p); }
};

class Vector : public Point {
 private:
  Objects getObjects () { return Objects(t, h); }
  void calculate () { p = h->getP() - t->getP(); }
 protected:
  Point *t, *h;
 public:
  Vector (Point *t, Point *h) : t(t), h(h) { calculate(); }
  Vector * copy () const { return new Vector(t, h); }
};

class Normal : public Point {
 private:
  Objects getObjects () { return Objects(t, h); }
  void calculate () { PV2 q = h->getP() - t->getP(); p.x = q.y; p.y = - q.x; }
 protected:
  Point *t, *h;
 public:
  Normal (Point *t, Point *h) : t(t), h(h) { calculate(); }
  Normal * copy () const { return new Normal(t, h); }
};

PV2 lineIntersection (const PV2 &a, const PV2 &b, const PV2 &c, const PV2 &d);

class LineIntersection : public Point {
 private:
  Objects getObjects () { return Objects(a, b, c, d); }
  void calculate () { 
    p = lineIntersection(a->getP(), b->getP(), c->getP(), d->getP());
  }
 protected:
  Point *a, *b, *c, *d;
 public:
  LineIntersection (Point *a, Point *b, Point *c, Point *d) 
    : a(a), b(b), c(c), d(d) { calculate(); }
  LineIntersection * copy () const { return new LineIntersection(a, b, c, d); }
};

PV2 circumCenter (const PV2 &a, const PV2 &b, const PV2 &c);

void linsolve2 (Parameter a, Parameter b, Parameter c, Parameter d, 
		Parameter e, Parameter f, Parameter *xy);

class CircumCenter : public Point {
 private:
  Objects getObjects () { return Objects(a, b, c); }
  void calculate () { 
    p = circumCenter(a->getP(), b->getP(), c->getP());
  }
 protected:
  Point *a, *b, *c;
 public:
  CircumCenter (Point *a, Point *b, Point *c) 
    : a(a), b(b), c(c) { calculate(); }
  CircumCenter * copy () const { return new CircumCenter(a, b, c); }
};

void pp (Point *p);

#endif
