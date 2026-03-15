FLAGS = -std=c++11 -Werror -Wall -Wextra -Wpedantic
DOCTEST  = vendor/doctest/doctest
CARPETA_BUILD = mkdir -p build

all:
	$(CARPETA_BUILD) && g++ $(FLAGS) src/*.cpp -o build/proyecto && ./build/proyecto

tests:
	$(CARPETA_BUILD) && g++ $(FLAGS) -I$(DOCTEST) src/iterativo.cpp src/DyV.cpp test/testEj5.cpp -o build/test && ./build/test