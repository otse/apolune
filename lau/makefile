B = ../src/

ENO = $(B)o/engine.o $(B)o/texture.o $(B)o/shader.o $(B)o/fbo.o $(B)o/font.o $(B)o/text.o $(B)o/draws.o $(B)o/anim.o

LAUO = o/main.o o/static.o o/bar.o

O = $(LAUO) $(ENO)

FLAGS = -DGLEW_STATIC -DSFML_STATIC -DUNICODE -std=gnu++0x

xDEBUG = -g
INC = -I../src/ -IQ:/SFML-2.2/include

all: launcher.exe


SFML = -lsfml-graphics-s -lsfml-window-s -lsfml-network-s -lsfml-system-s
LGCC = -static-libgcc -static-libstdc++

launcher.exe: $(O)
	g++ $(O) -LQ:/built -LQ:/SFML-2.2/lib $(SFML) $(LGCC) -lws2_32 -ljvm -ljpeg -lfreetype -lglew32s -lglu32 -lopengl32 -lwinmm -lgdi32 -lphysfs -ljsoncpp -llua -o ../bin/launcher -Wall


o/main.o: main.cpp h.h
	g++ $(INC) -c main.cpp -o o/main.o $(FLAGS)

o/static.o: static.cpp h.h
	g++ $(INC) -c static.cpp -o o/static.o $(FLAGS)
	
o/bar.o: bar.cpp bar.h
	g++ $(INC) -c bar.cpp -o o/bar.o $(FLAGS)


clean:
	rm $(LAUO)