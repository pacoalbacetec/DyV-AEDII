### Pseudocodigo
---
#### Notacion :
- `:=` → definir y asignar
- `=` → asignar (tiene que haber sido definido previamente)
- `==` → igualdad
```go
function contar(A: char*, izq: int, fin: int, C: char) -> (count)
    count := 0
    para i := izq hasta fin
        if A[i] == C
            ++count
        finIf
    finPara
    ret count
finFunction


function DyV(A: char*, izq: int, dch: int, m:int, C:char) -> (bestPos, maxCount)
    
    if dch - izq + 1 == m
        ret (izq, contar(A, izq, dch, C))
    finIf

    mid := (izq + dch) / 2

    bestPos := -1
    maxCount := -1
    

    /* lado izquierdo */
    if mid - izq + 1 >= m
        leftPos, leftCount := DyV(A, izq, mid, m, C)
        if leftCount > maxCount
            maxCount = leftCount
            bestPos = leftPos
        finIf
    finIf


    /* lado derecho */
    if dch - mid >= m
        rightPos, rightCount := DyV(A, mid+1, dch, m, C)
        if rightCount > maxCount
            maxCount = rightCount
            bestPos = rightPos
        finIf
    finIf


    /* caso cruzado */

    start := max(izq, mid - m + 2)

    count := contar(A, start, start+m-1, C)
    crossCount := count
    crossPos := start
    
    para i desde start + 1 hasta mid
        if A[i-1] == C 
            --count
        finIf
        if A[i+m-1] == C
            ++count
        finIf
        if count > crossCount
            crossCount = count
            crossPos = i
        finIf
    finPara 
    

    if crossCount > maxCount
        maxCount = crossCount
        bestPos = crossPos
    finIf    

    ret (bestPos, maxCount)
finFunction


function ej5(A: char*, n: int, m:int, C: char) -> (bestPos, maxCount)
    if n == m
        ret (0, contar(A, 0, n-1, C))
    finIf

    ret DyV(A, 0, n-1, m, C)
finFunction
```