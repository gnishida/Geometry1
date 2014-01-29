CFLAGS = -g -I.
COMPILE = g++ $(CFLAGS) -c
LINK = g++ $(CFLAGS)
LIBS = -lGL -lGLU -lglut -lqd -lmpfr

all	: main.o ps1-nishida.o point.o acp.o
	$(LINK) main.o ps1-nishida.o point.o acp.o $(LIBS) -o main

acp.o:	acp.cc acp.h
	$(COMPILE) acp.cc

point.o: point.C point.h object.h pv.h acp.h
	$(COMPILE) point.C

ps1-nishida.o	: ps1-nishida.C 
	$(COMPILE) ps1-nishida.C

main.o	: main.C
	$(COMPILE) main.C

clean : 
	rm -f *.o *~ main
