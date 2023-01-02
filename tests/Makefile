CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
SRC_DIR=../src
SRC= $(wildcard $(SRC_DIR)/*.cpp)
OBJ= $(SRC:.cpp=.o)
TST= $(wildcard *.cpp)
OBJ_TEST = $(filter-out $(SRC_DIR)/main.o, $(OBJ)) $(TST:.cpp=.o)

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^

%.o: %.cpp
	$(CC) $(CCFLAGS) -I$(SRC_DIR) -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) testcase


