CFLAGS = -g -I.
COMPILE = g++ $(CFLAGS) -c
LINK = g++ $(CFLAGS)
LIBS = -lGL -lGLU -lglut -lqd -lmpfr

acp.o:	acp.cc acp.h
	$(COMPILE) acp.cc

point.o: point.C point.h object.h pv.h acp.h
	$(COMPILE) point.C

hull.o: hull.C hull.h object.h pv.h acp.h
	$(COMPILE) hull.C

hull	: hullplot.o plot.o hull.o point.o acp.o
	$(LINK) hullplot.o plot.o hull.o point.o acp.o \
	$(LIBS) -o hull

clean : 
	rm -f *.o *~ hull mindisk setop mink triangulate tmap voronoi delaunay hull3
