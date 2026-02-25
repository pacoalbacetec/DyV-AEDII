### Pseudocodigo
---
#### Notacion :
- `:=` → definir y asignar
- `=` → asignar (tiene que haber sido definido previamente)
- `==` → igualdad
```go
function ej5(A: vector, n: int, m: int, C: char) -> (int, int)

    // Casos base
    si m == 0 o A.size() == 0:
        ret (1, 0)
    finSi

    count := 0
    bestPos := 0

    // Procesar primera ventana de tamaño m
    para i desde 0 hasta m - 1:
        si A[i] == C:
            ++count
        finSi
    finPara

    // Ventana inicial es completa
    si count == m:
        ret (1, m)
    finSi

    maxCount := count

    // Bucle principal moviendo la ventana desde m hasta < n
    para right desde m hasta n - 1:
        left := right - m + 1

        // Entra nuevo elemento por la derecha
        si A[right] == C:
            ++count
        finSi

        // Sale elemento por la izquierda
        si A[left - 1] == C:
            --count
        finSi

        // Actualizar maxCount y bestPos
        si count > maxCount:
            maxCount = count
            bestPos = left
            // Conformarse si la ventana es completa
            si maxCount == m:
                break
            finSi
        finSi

    finPara

    ret (++bestPos, maxCount)

finFunction
```