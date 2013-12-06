INCLUDE =
LIB = -L/usr/X11R6/lib 

LINK = -lfltk -lfltk_gl -lX11 -lXext -lGL -lGLU -lglut

OBJ = CubicBspline.o GenericException.o Ground.o Track.o World.o WorldWindow.o libtarga.o Tree.o

Project2: $(OBJ)
	g++ -ggdb -Wall -o Project2 $(OBJ) $(INCLUDE) $(LINK) $(LIB)

%.o: %.cpp
	g++ -ggdb -Wall -c -o $@ $<

libtarga.o: libtarga.c libtarga.h
	gcc -c -o libtarga.o libtarga.c $(INCLUDE)

clean:
	@for obj in $(OBJ); do\
		if test -f $$obj; then rm $$obj; fi; done
	@if (test -f Project2); then rm Project2; fi;

