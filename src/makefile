xDONTREBUILD = o/stb_image.o

ENO = o/engine.o o/texture.o o/shader.o o/fbo.o o/font.o o/text.o o/draws.o o/anim.o

APO = o/main.o o/loader.o o/lua.o o/start.o o/files.o o/def.o o/bulk.o o/context.o o/world.o o/sprite.o o/emitter.o o/object.o o/chair.o o/table.o o/console.o o/light.o o/mover.o o/ai.o o/chicken.o o/tentacle.o o/ply.o o/planet.o o/asteroid.o o/ship.o o/mothership.o

APGUIO =  o/box.o o/element.o o/label.o o/button.o

# we don´t use srcs anymore
#SRCS = main.cpp ap/lua.cpp ll/files.cpp en/engine.cpp en/shaders.cpp en/texture.cpp en/font.cpp en/text.cpp ap/def.cpp ap/bulk.cpp ap/context.cpp ap/world.cpp en/draws.cpp ap/sprite.cpp ap/mover.cpp ap/ship.cpp ap/mothership.cpp ap/ply.cpp ap/asteroid.cpp en/anim.cpp

O = $(ENO) $(APO) $(APGUIO) $(DONTREBUILD)

FLAGS = -DGLEW_STATIC -DSFML_STATIC -DUNICODE -DAPOLUNE
eleven = -std=c++0x
gnu = -std=gnu++0x
stdoverride = $(gnu)

noDEBUG = -g
INC = -IQ:/SFML-2.2/include -I../src/ -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/win32"
	
all: apolune.exe


SFML = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s
LGCC = -static-libgcc -static-libstdc++

apolune.exe: $(O)
	g++ $(O) -LQ:/built -LQ:/SFML-2.2/lib $(SFML) $(LGCC) -ljvm -ljpeg -lfreetype -lglew32s -lglu32 -lopengl32 -lwinmm -lgdi32 -lphysfs -ljsoncpp -llua -o ../bin/apolune -Wall


o/main.o: main.cpp h.h ap/shards/stats.cpp ap/shards/debugbox.cpp
	g++ $(INC) -c main.cpp -o o/main.o $(FLAGS) $(gnu) $(stdoverride)


#/ap
o/loader.o: ap/loader.cpp ap/loader.h
	g++ $(INC) -c ap/loader.cpp -o o/loader.o $(FLAGS) $(eleven) $(stdoverride)	

o/lua.o: ap/lua.cpp ap/lua.h
	g++ $(INC) -c ap/lua.cpp -o o/lua.o $(FLAGS) $(eleven) $(stdoverride)	

o/bulk.o: ap/bulk.cpp
	g++ $(INC) -c ap/bulk.cpp -o o/bulk.o $(FLAGS) $(eleven) $(stdoverride)

o/start.o: ap/start.cpp ap/start.h
	g++ $(INC) -c ap/start.cpp -o o/start.o $(FLAGS) $(eleven) $(stdoverride)
#rule test  

o/context.o: ap/context.cpp
	g++ $(INC) -c ap/context.cpp -o o/context.o $(FLAGS) $(eleven) $(stdoverride)

o/def.o: ap/def.cpp ap/def.h
	g++ $(INC) -c ap/def.cpp -o o/def.o $(FLAGS) $(eleven) $(stdoverride)

o/sprite.o: ap/sprite.cpp ap/sprite.h
	g++ $(INC) -c ap/sprite.cpp -o o/sprite.o $(FLAGS) $(eleven) $(stdoverride)

o/emitter.o: ap/emitter.cpp ap/emitter.h
	g++ $(INC) -c ap/emitter.cpp -o o/emitter.o $(FLAGS) $(eleven) $(stdoverride)

o/object.o: ap/object.cpp ap/object.h
	g++ $(INC) -c ap/object.cpp -o o/object.o $(FLAGS) $(eleven) $(stdoverride)

o/chair.o: ap/objects/chair.cpp ap/objects/chair.h
	g++ $(INC) -c ap/objects/chair.cpp -o o/chair.o $(FLAGS) $(eleven) $(stdoverride)

o/table.o: ap/objects/table.cpp ap/objects/table.h
	g++ $(INC) -c ap/objects/table.cpp -o o/table.o $(FLAGS) $(eleven) $(stdoverride)

o/console.o: ap/objects/console.cpp ap/objects/console.h
	g++ $(INC) -c ap/objects/console.cpp -o o/console.o $(FLAGS) $(eleven) $(stdoverride)

o/light.o: ap/light.cpp ap/light.h
	g++ $(INC) -c ap/light.cpp -o o/light.o $(FLAGS) $(eleven) $(stdoverride)

o/mover.o: ap/mover.cpp ap/sprite.h ap/mover.h
	g++ $(INC) -c ap/mover.cpp -o o/mover.o $(FLAGS) $(eleven) $(stdoverride)

o/ai.o: ap/ai.cpp ap/ai.h
	g++ $(INC) -c ap/ai.cpp -o o/ai.o $(FLAGS) $(eleven) $(stdoverride)

o/chicken.o: ap/ais/chicken.cpp ap/ais/chicken.h
	g++ $(INC) -c ap/ais/chicken.cpp -o o/chicken.o $(FLAGS) $(eleven) $(stdoverride)

o/tentacle.o: ap/ais/tentacle.cpp ap/ais/tentacle.h
	g++ $(INC) -c ap/ais/tentacle.cpp -o o/tentacle.o $(FLAGS) $(eleven) $(stdoverride)

o/ply.o: ap/ply.cpp ap/sprite.h ap/mover.h ap/ply.h
	g++ $(INC) -c ap/ply.cpp -o o/ply.o $(FLAGS) $(eleven) $(stdoverride)

o/planet.o: ap/planet.cpp ap/planet.h
	g++ $(INC) -c ap/planet.cpp -o o/planet.o $(FLAGS) $(eleven) $(stdoverride)

o/world.o: ap/world.cpp ap/world.h
	g++ $(INC) -c ap/world.cpp -o o/world.o $(FLAGS) $(eleven) $(stdoverride)

o/ship.o: ap/ship.cpp ap/ship.h
	g++ $(INC) -c ap/ship.cpp -o o/ship.o $(FLAGS) $(eleven) $(stdoverride)

o/mothership.o: ap/mothership.cpp ap/mothership.h
	g++ $(INC) -c ap/mothership.cpp -o o/mothership.o $(FLAGS) $(eleven) $(stdoverride)

o/asteroid.o: ap/asteroid.cpp ap/sprite.h ap/mover.h ap/asteroid.h
	g++ $(INC) -c ap/asteroid.cpp -o o/asteroid.o $(FLAGS) $(eleven) $(stdoverride)


#/ap/gui
o/box.o: ap/gui/box.cpp ap/gui/box.h
	g++ $(INC) -c ap/gui/box.cpp -o o/box.o $(FLAGS) $(eleven) $(stdoverride)

o/element.o: ap/gui/element.cpp ap/gui/element.h
	g++ $(INC) -c ap/gui/element.cpp -o o/element.o $(FLAGS) $(eleven) $(stdoverride)

o/label.o: ap/gui/label.cpp ap/gui/label.h
	g++ $(INC) -c ap/gui/label.cpp -o o/label.o $(FLAGS) $(eleven) $(stdoverride)

o/button.o: ap/gui/button.cpp ap/gui/button.h
	g++ $(INC) -c ap/gui/button.cpp -o o/button.o $(FLAGS) $(eleven) $(stdoverride)


#/ll
o/stb_image.o: ll/stb_image.c
	g++ $(INC) -c ll/stb_image.c -o o/stb_image.o $(FLAGS)

o/files.o: ll/files.cpp
	g++ $(INC) -c ll/files.cpp -o o/files.o $(FLAGS) $(stdoverride)

o/load.o: ll/load.cpp
	g++ $(INC) -c ll/load.cpp -o o/load.o $(FLAGS) $(eleven) $(stdoverride)


#/en
o/engine.o: en/engine.cpp en/engine.h h.h
	g++ $(INC) -c en/engine.cpp -o o/engine.o $(FLAGS) $(gnu) $(stdoverride)

o/texture.o: en/texture.cpp en/texture.h
	g++ $(INC) -c en/texture.cpp -o o/texture.o $(FLAGS) $(gnu) $(stdoverride)

o/anim.o: en/anim.cpp en/anim.h
	g++ $(INC) -c en/anim.cpp -o o/anim.o $(FLAGS) $(gnu) $(stdoverride)

o/shader.o: en/shader.cpp en/shader.h
	g++ $(INC) -c en/shader.cpp -o o/shader.o $(FLAGS) $(eleven) $(stdoverride)

o/fbo.o: en/fbo.cpp en/fbo.h
	g++ $(INC) -c en/fbo.cpp -o o/fbo.o $(FLAGS) $(eleven) $(stdoverride)

o/draws.o: en/draws.cpp en/draws.h
	g++ $(INC) -c en/draws.cpp -o o/draws.o $(FLAGS) $(eleven) $(stdoverride)

o/buffer.o: en/buffer.cpp en/buffer.h
	g++ $(INC) -c en/buffer.cpp -o o/buffer.o $(FLAGS) $(eleven) $(stdoverride)

o/font.o: en/font.cpp en/font.h
	g++ $(INC) -c en/font.cpp -o o/font.o $(FLAGS) $(eleven) $(stdoverride)

o/text.o: en/text.cpp en/text.h
	g++ $(INC) -c en/text.cpp -o o/text.o $(FLAGS) $(eleven) $(stdoverride)

clean:
	rm $(APO) $(APGUIO) $(ENO)

cleanap:
	rm $(APO) $(APGUIO)

cleanen:
	rm $(ENO)