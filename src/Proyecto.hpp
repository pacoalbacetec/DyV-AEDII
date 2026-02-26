#ifndef PROYECTO_HPP
#define PROYECTO_HPP

#include <utility>
#include <vector>
using namespace std;


class Iterativo {
    public:
        static pair<int,int> ej5(vector<char>& a, int n, int m,  char c);
};

class Dyv {
    private:
        const char* a;
        int n;
        int m;
        char c;

        int contar(int izq, int fin);
        pair<int, int> rec(int izq, int dch);
    public:
        Dyv(const char* a, int n, int m, char c) : a(a), n(n), m(m), c(c) {}
        pair<int,int> ej5();
};


#endif // PROYECTO_HPP