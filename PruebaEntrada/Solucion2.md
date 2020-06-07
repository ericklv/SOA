# Solución 2 
Planificación Round-Robin se le denomina a un método para ejecutar diferentes procesos de manera concurrente, para la utilización equitativa de los recursos del equipo, es limitando cada proceso a un pequeño período, y luego suspendiendo este proceso para dar oportunidad a otro proceso y así sucesivamente. 

Según lo indicado en el enunciado del problema 2 según los tiempos sería:

| | | | | | | | | | | | | | |
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|__E/S D2__|    |    |    |    |    |    |    |    |     |    |    |   | 
|__E/S D1__|    |    |    |    |    |    | A1 | A2 |     |    |    |   |
|__CPU__   | IR | A1 | A2 | IS | IR | IS | B1 | B2 | IH1 | IR | B3 | B4| 

```
```
 
| | | | | | | | | | | | | | |
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|__E/S D2__|    |    |    |    |    |    |    | A1 | A2  | A3 | A4 |A5 | 
|__E/S D1__|    |    |    |    |    |    |    |    |     |    |    |B1 |
|__CPU__   | IR | A1 | A2 | IS | IR | IS | IS | B5 | IR  | IS | IS | N | 

```
```

| | | | | | | | | | | | | | |
|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|__E/S D2__|    |    |    |    |    |    |    |    |     |    |    |   | 
|__E/S D1__|    |    |    |    |    |    |    |    |     |    |    |   |
|__CPU__   |IH1 | IR |IH2 | B1 | IR | IS | IS | A1 | IR  | IS | IS |   | 

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTM1MDg0NTA2Myw2NTg5NzYwOTAsMTQ0MD
E2Mjk2XX0=
-->