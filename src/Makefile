CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
INCLUDE = -I/usr/local/include/SDL2 
LSDL2 = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

play : $(OBJ) 
	$(CC) $(CCFLAGS) -o $@ $^ $(LSDL2)

%.o: %.cpp
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $< 

clean :
	rm -f $(OBJ) play


#g++ -Wall main.cpp -I/usr/local/include/SDL2 -L/usr/local/lib -o play -lSDL2 -lSDL2_image -lSDL2_ttf