### Pseudocodigo
---
#### Notacion :
- `:=` → definir y asignar
- `=` → asignar (tiene que haber sido definido previamente)
- `==` → igualdad
---
```
funcion maxApariciones(A: string, n: int m: int, C: char) -> (int,int)
    count := 0

    // Procesar primera ventana tamaño m
    i :=0
    mientras i < m :
        si A[i] == C:
            count = count + 1:
        finSi
        i = i + 1
    finMientras

    //Definir valores iniciales
    max_count := count
    best_pos := 0

    //Bucle principal moviendo al ventana desde m hasta  < n
    para i desde m hasta n - 1

        //Sumar 1 si el nuevo elemento coincide
        si A[i] == C:
            count = count + 1:
        finSi

        //Restar 1 si el ultimo elemento que queda fuera coincidia
        si A[i-m] == C:
            count = count - 1
        finSi
        //Actualizar max_count
        si count > max_count:
            max_count = count
            best_pos = i -m + 1 
        finSi

    finPara

    retornar best_pos, max_count

finFuncion

```