#include "Proyecto.hpp"

/**
 * Ejercicio 5: Ventana de caracteres Iterativo
 * @note: ventana completa es aquella que todos los elementos son el caracter buscado
 */
pair<int, int> Iterativo::ej5(vector<char> &a, int n, int m, char c){

    if(m == 0 || a.size() == 0){
        return {1,0};
    }

    int count = 0;
    int bestPos = 0;

    // Rellenar primera ventana
    for (int i = 0; i < m; ++i){
        if (a[i] == c)
        {
            ++count;
        }
    }
    // Ventana inicial es completa 
    if(count == m){
        return {1, m};
    }

    int maxCount = count;

    // Fixed sliding window
    for (int right = m; right < n; ++right){
        int left = right - m + 1;

        // Entra caracter buscado en la ventana
        if (a[right] == c){
            ++count;
        }
        // Sale caraceter buscado
        if (a[left - 1] == c){
            --count;
        }
        // Verificar caracteres y actualizar
        if (count > maxCount){
            maxCount = count;
            bestPos = left;
            // Nos conformamos si una ventana es completa
            if(maxCount == m){
                break;
            }
        }
    }

    return {++bestPos, maxCount};
}
