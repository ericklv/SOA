# Solución 3

Para una tabla de paginas de un nivel:

``` math
#n de entradas * tamaño de entrada => 2^11 * 8 = 2^14 bytes
```

Para una tabla de paginas de 2 niveles:  

Considerando la dirección logica de 22bits y que se toman 5 bits para el segundo nivel, entonces tendriamos 6 bis para la dirección del primer nivel.  
Entonces cada tabla del segundo nivel puede direccionar hasta 2^5 paginas, es decir:
```math
    32 paginas * 2KB = 64KB
```
Como el proceso requiere 90KB, completariamos con 2 tablas del 2do nivel.

```math
    2^6 * 8 +2 * 2^5 * 8 = 2^10 bytes
```
 Entonces el ahorro sería:

```math
    2^14-2^10 =  15360 bytes
```