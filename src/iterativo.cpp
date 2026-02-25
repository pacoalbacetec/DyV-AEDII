#include <pair>

class iterativo {
    public:
    static pair<int,int> ej5(vector<char>& a, int n, int m,  char c) const {
    
        int count = 0;
        int maxCount = count;
        int bestPos = 0;

        // Rellenar primera ventana 
        for(int i  = 0; i < m; ++i){
            if(a[i] == c){
                ++count;
            }
        }

        // Fixed sliding window 
        for(int rigth = m; rigth < n; ++i){
            int left = rigth-m+1;
            
            //Entra caracter deseado en la ventana
            if(a[rigth] == c){
                ++count;
            }
            //Sale caraceter deseado
            if(a[left-1] == c){
                --count;
            }
            //Verificar caracteres y actualizar
            if(count > maxCount) {
                maxCount = count;
                bestPos = left;
            }
        }
        return {bestPos, maxCount}
    }
};
