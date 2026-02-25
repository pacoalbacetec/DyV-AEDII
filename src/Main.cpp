#include "Proyecto.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<char> v = {'c','d','d','a','b','c','d','a','c','c'};

    pair<int,int> r = Iterativo::ej5(v, v.size(), 5, 'c');

    cout << "Posicion: " << r.first << endl;
    cout << "Cantidad: " << r.second << endl;

    return 0;
}