CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
INCLUDE = -I/usr/local/include/SDL2 
LSDL2 = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf
SRC_DIR=../src
SRC= $(wildcard $(SRC_DIR)/*.cpp)
OBJ= $(SRC:.cpp=.o)
TST= $(wildcard *.cpp)
OBJ_TEST = $(filter-out $(SRC_DIR)/main.o, $(OBJ)) $(TST:.cpp=.o)

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^ $(LSDL2)

%.o: %.cpp
	$(CC) $(CCFLAGS) $(INCLUDE) -I$(SRC_DIR) -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) testcase


