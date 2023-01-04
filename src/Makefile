CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
SRC_DIR=../src
SRC= $(wildcard $(SRC_DIR)/*.cpp)
OBJ= $(SRC:.cpp=.o)

main : $(OBJ) 
	$(CC) $(CCFLAGS)  -o $@ $^

%.o: %.cpp
	$(CC) $(CCFLAGS) -I$(SRC_DIR) -o $@ -c $<

clean :
	rm -f $(OBJ) main


