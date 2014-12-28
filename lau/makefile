DONTREBUILD = $(B)o/stb_image.o

B = ../src/

ENO = $(B)o/engine.o $(B)o/texture.o $(B)o/shader.o $(B)o/fbo.o $(B)o/font.o $(B)o/text.o $(B)o/draws.o $(B)o/anim.o

LAUO = o/main.o o/static.o

O = $(LAUO) $(ENO) $(DONTREBUILD)

FLAGS = -DFREEGLUT_STATIC -DGLEW_STATIC
eleven = -std=c++0x
gnu = -std=gnu++0x
stdoverride = $(gnu)

DEBUG = -g
INC = -I../src/ -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/win32"

all: launcher.exe

launcher.exe: $(O)
	g++ $(O) -L../../BUILT -ljvm -lglew32s -lfreeglut_static -lglu32 -lopengl32 -lwinmm -lgdi32 -lphysfs -ljsoncpp -llua -lOpenAL32.dll -static-libgcc -static-libstdc++ -o ../bin/launcher -Wall

o/main.o: main.cpp h.h
	g++ $(INC) -c main.cpp -o o/main.o $(FLAGS) $(gnu) $(stdoverride)

o/static.o: static.cpp h.h
	g++ $(INC) -c static.cpp -o o/static.o $(FLAGS) $(stdoverride)
	
$(B)o/engine.o: $(B)en/engine.cpp $(B)en/engine.h h.h
	g++ -c $(INC) $(B)en/engine.cpp -o $(B)o/engine.o $(FLAGS) $(stdoverride)
	
$(B)o/texture.o: $(B)en/texture.cpp $(B)en/texture.h h.h
	g++ $(INC) -c $(B)en/texture.cpp -o $(B)o/texture.o $(FLAGS) $(stdoverride)
	
$(B)o/fbo.o: $(B)en/fbo.cpp $(B)en/fbo.h h.h
	g++ $(INC) -c $(B)en/fbo.cpp -o $(B)o/fbo.o $(FLAGS) $(eleven) $(stdoverride)

#/ap/gui
#o/box.o: ap/gui/box.cpp ap/gui/box.h
#	g++ -c ap/gui/box.cpp -o o/box.o $(FLAGS) $(eleven) $(stdoverride)

#o/element.o: ap/gui/element.cpp ap/gui/element.h
#	g++ -c ap/gui/element.cpp -o o/element.o $(FLAGS) $(eleven) $(stdoverride)

#o/label.o: ap/gui/label.cpp ap/gui/label.h
#	g++ -c ap/gui/label.cpp -o o/label.o $(FLAGS) $(eleven) $(stdoverride)

#o/button.o: ap/gui/button.cpp ap/gui/button.h
#	g++ -c ap/gui/button.cpp -o o/button.o $(FLAGS) $(eleven) $(stdoverride)


clean:
	rm $(LAUO)