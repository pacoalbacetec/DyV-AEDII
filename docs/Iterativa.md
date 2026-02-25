### Pseudocodigo
---
#### Notacion :
- `:=` → definir y asignar
- `=` → asignar (tiene que haber sido definido previamente)
- `==` → igualdad
```go
function maxApariciones(A: string, n: int m: int, C: char) -> (int,int)
    count := 0

    // Procesar primera ventana tamaño m
    para i desde 0 hasta m - 1 :
        if A[i] == C:
            count = count + 1:
        finIf
    finPara

    //Definir valores iniciales
    maxCount := count
    bestPos := 0

    //Bucle principal moviendo al ventana desde m hasta < n
    para r desde m hasta n - 1
        // izquerda de la ventana es r - m

        //Sumar 1 if el nuevo elemento coincide
        if A[r] == C:
            ++count:
        finIf

        //Restar 1 if el ultimo elemento que queda fuera coincidia
        if A[r-m] == C:
            --count
        finIf

        //Actualizar maxCount
        if count > maxCount:
            maxCount = count
            bestPos = r -m + 1 
        finIf

    finPara

    ret (bestPos, maxCount)

finFunction
```