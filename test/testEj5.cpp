#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../vendor/doctest/doctest/doctest.h"
#include "../src/Proyecto.hpp"

vector<char> v = {'c','d','d','a','b','c','d','a','c','c'};

TEST_CASE("Tests ejercicio iterativo") {

    SUBCASE("ejemplo dado") {
        pair<int,int> r = Iterativo::ej5(v, v.size(), 5, 'c');
        CHECK(r.first == 6);
        CHECK(r.second == 3);
    }

    SUBCASE("no hay letra buscada") {
        pair<int,int> r = Iterativo::ej5(v, v.size(), 5, 'x');
        CHECK(r.first == 1);
        CHECK(r.second == 0);
    }

    SUBCASE("mejor ventana al inicio") {
        vector<char> va = {'c','c','c','a','b','d','d','a','d','d'};
        pair<int,int> r = Iterativo::ej5(va, 10, 5, 'c');
        CHECK(r.first == 1);
        CHECK(r.second == 3);
    }

    SUBCASE("m igual a n, ventana unica") {
        vector<char> vb = {'c','d','c','d','c'};
        pair<int,int> r = Iterativo::ej5(vb, 5, 5, 'c');
        CHECK(r.first == 1);
        CHECK(r.second == 3);
    }

    SUBCASE("m igual a 1") {
        vector<char> vc = {'a','c','a','a','c'};
        pair<int,int> r = Iterativo::ej5(vc, 5, 1, 'c');
        CHECK(r.first == 2);
        CHECK(r.second == 1);
    }

    SUBCASE("n=1 m=1 con match") {
        vector<char> vd = {'c'};
        pair<int,int> r = Iterativo::ej5(vd, 1, 1, 'c');
        CHECK(r.first == 1);
        CHECK(r.second == 1);
    }

    SUBCASE("n=1 m=1 sin match") {
        vector<char> ve = {'a'};
        pair<int,int> r = Iterativo::ej5(ve, 1, 1, 'c');
        CHECK(r.first == 1);
        CHECK(r.second == 0);
    }

    SUBCASE("todos los caracteres son c") {
        vector<char> vf = {'c','c','c','c','c'};
        pair<int,int> r = Iterativo::ej5(vf, 5, 3, 'c');
        CHECK(r.first == 1);
        CHECK(r.second == 3);
    }

    SUBCASE("empate gana la primera ventana") {
        vector<char> vg = {'c','a','a','a','c'};
        pair<int,int> r = Iterativo::ej5(vg, 5, 3, 'c');
        CHECK(r.first == 1);
        CHECK(r.second == 1);
    }
}

TEST_CASE("Tests ejercicio DyV") {

    SUBCASE("ejemplo dado") {
        pair<int,int> r = Dyv(v.data(), v.size(), 5, 'c').ej5();
        CHECK(r.first == 6);
        CHECK(r.second == 3);
    }

    SUBCASE("n=6 m=5 caso cruzado fuera de limites") {
    vector<char> vh = {'c','c','a','a','c','c'};
    pair<int,int> r = Dyv(vh.data(), 6, 5, 'c').ej5();
    CHECK(r.second == 3);
    }

    SUBCASE("no hay letra buscada") {
        pair<int,int> r = Dyv(v.data(), v.size(), 5, 'x').ej5();
        CHECK(r.first == 1);
        CHECK(r.second == 0);
    }

    SUBCASE("mejor ventana al inicio") {
        vector<char> va = {'c','c','c','a','b','d','d','a','d','d'};
        pair<int,int> r = Dyv(va.data(), 10, 5, 'c').ej5();
        CHECK(r.first == 1);
        CHECK(r.second == 3);
    }

    SUBCASE("m igual a n, ventana unica") {
        vector<char> vb = {'c','d','c','d','c'};
        pair<int,int> r = Dyv(vb.data(), 5, 5, 'c').ej5();
        CHECK(r.first == 1);
        CHECK(r.second == 3);
    }

    SUBCASE("m igual a 1") {
        vector<char> vc = {'a','c','a','a','c'};
        pair<int,int> r = Dyv(vc.data(), 5, 1, 'c').ej5();
        CHECK(r.first == 2);
        CHECK(r.second == 1);
    }

    SUBCASE("n=1 m=1 con match") {
        vector<char> vd = {'c'};
        pair<int,int> r = Dyv(vd.data(), 1, 1, 'c').ej5();
        CHECK(r.first == 1);
        CHECK(r.second == 1);
    }

    SUBCASE("n=1 m=1 sin match") {
        vector<char> ve = {'a'};
        pair<int,int> r = Dyv(ve.data(), 1, 1, 'c').ej5();
        CHECK(r.first == 1);
        CHECK(r.second == 0);
    }

    SUBCASE("todos los caracteres son c") {
        vector<char> vf = {'c','c','c','c','c'};
        pair<int,int> r = Dyv(vf.data(), 5, 3, 'c').ej5();
        CHECK(r.first == 1);
        CHECK(r.second == 3);
    }

    SUBCASE("empate gana la primera ventana") {
        vector<char> vg = {'c','a','a','a','c'};
        pair<int,int> r = Dyv(vg.data(), 5, 3, 'c').ej5();
        CHECK(r.first == 1);
        CHECK(r.second == 1);
    }
}

TEST_CASE("Consistencia Iterativo == DyV") {

    SUBCASE("ejemplo dado") {
        pair<int,int> ri = Iterativo::ej5(v, v.size(), 5, 'c');
        pair<int,int> rd = Dyv(v.data(), v.size(), 5, 'c').ej5();
        CHECK(ri.second == rd.second);
    }

    SUBCASE("n=6 m=5 caso cruzado fuera de limites") {
    vector<char> vh = {'c','c','a','a','c','c'};
    pair<int,int> r = Dyv(vh.data(), 6, 5, 'c').ej5();
    CHECK(r.second == 3);
    }

    SUBCASE("no hay letra buscada") {
        pair<int,int> ri = Iterativo::ej5(v, v.size(), 5, 'x');
        pair<int,int> rd = Dyv(v.data(), v.size(), 5, 'x').ej5();
        CHECK(ri.second == rd.second);
    }

    SUBCASE("mejor ventana al inicio") {
        vector<char> va = {'c','c','c','a','b','d','d','a','d','d'};
        pair<int,int> ri = Iterativo::ej5(va, 10, 5, 'c');
        pair<int,int> rd = Dyv(va.data(), 10, 5, 'c').ej5();
        CHECK(ri.second == rd.second);
    }

    SUBCASE("m igual a n") {
        vector<char> vb = {'c','d','c','d','c'};
        pair<int,int> ri = Iterativo::ej5(vb, 5, 5, 'c');
        pair<int,int> rd = Dyv(vb.data(), 5, 5, 'c').ej5();
        CHECK(ri.second == rd.second);
    }

    SUBCASE("m igual a 1") {
        vector<char> vc = {'a','c','a','a','c'};
        pair<int,int> ri = Iterativo::ej5(vc, 5, 1, 'c');
        pair<int,int> rd = Dyv(vc.data(), 5, 1, 'c').ej5();
        CHECK(ri.second == rd.second);
        CHECK(ri.first  == rd.first);
    }

    SUBCASE("todos son c") {
        vector<char> vf = {'c','c','c','c','c'};
        pair<int,int> ri = Iterativo::ej5(vf, 5, 3, 'c');
        pair<int,int> rd = Dyv(vf.data(), 5, 3, 'c').ej5();
        CHECK(ri.second == rd.second);
    }

    SUBCASE("n=1 m=1 con match") {
        vector<char> vd = {'c'};
        pair<int,int> ri = Iterativo::ej5(vd, 1, 1, 'c');
        pair<int,int> rd = Dyv(vd.data(), 1, 1, 'c').ej5();
        CHECK(ri.second == rd.second);
        CHECK(ri.first  == rd.first);
    }

    SUBCASE("n=1 m=1 sin match") {
        vector<char> ve = {'a'};
        pair<int,int> ri = Iterativo::ej5(ve, 1, 1, 'c');
        pair<int,int> rd = Dyv(ve.data(), 1, 1, 'c').ej5();
        CHECK(ri.second == rd.second);
        CHECK(ri.first  == rd.first);
    }
}