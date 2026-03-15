#include "Proyecto.hpp"

int Dyv::contar(int izq, int fin){
    int count = 0;
    for(int i = izq; i <= fin; ++i){
        if(a[i] == c) count++;
    }
    return count;
}

pair<int, int> Dyv::rec(int izq, int dch){
    if(dch - izq + 1 == m){
        return {izq + 1, contar(izq, dch)};
    }

    int mid = (izq + dch) / 2;
    int bestPos = -1;
    int maxCount = -1;

    if(mid-izq+1 >= m){
        pair<int, int> leftRes = rec(izq, mid);
        if(leftRes.second > maxCount){
            maxCount = leftRes.second;
            bestPos = leftRes.first;
        }
        if(maxCount == m) return {bestPos, maxCount};

    }

    if(dch-mid >= m){
        pair<int, int> rightRes = rec(mid+1, dch);
        if(rightRes.second > maxCount){
            maxCount = rightRes.second;
            bestPos = rightRes.first;
        }
        if(maxCount == m) return {bestPos, maxCount};

    }

    int start = max(izq, mid - m + 2);
    int count = contar(start, start + m - 1);
    int pos = start;

    for(int i = start + 1; i <= mid; ++i){
        if(a[i-1] == c) --count;
        if(a[i+m-1] == c) ++count;
        if(count > maxCount){
            maxCount = count;
            bestPos = i;
        }
    }

    if(count > maxCount){
        maxCount = count;
        bestPos = pos;
    }

    return {bestPos, maxCount};
}

pair<int, int> Dyv::ej5(){
    if(n == m) {
        return {1, contar(0, n-1)};
    }
    return rec(0, n-1);
}   