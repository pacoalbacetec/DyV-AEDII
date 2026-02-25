FLAGS = -std=c++11 -Werror -Wall -Wextra -Wpedantic
DOCTEST  = vendor/doctest/doctest

all:
	mkdir -p build && g++ $(FLAGS) src/*.cpp -o build/proyecto && ./build/proyecto

tests:
	mkdir -p build && g++ $(FLAGS) -I$(DOCTEST) src/iterativo.cpp src/DyV.cpp test/testEj5.cpp -o build/test && ./build/test