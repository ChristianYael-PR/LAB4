# Proyecto: División de Jugadores y Cálculo de Química en C

## Introducción

El propósito de este proyecto es resolver un problema donde se tiene un conjunto de jugadores, cada uno con una habilidad específica, y se requiere dividirlos en equipos de dos jugadores cada uno. La condición es que la suma de habilidades de cada equipo sea la misma para todos. Posteriormente, se debe calcular la química total de todos los equipos, donde la química de cada equipo es el producto de las habilidades de sus dos integrantes. Si no es posible formar los equipos bajo estas reglas, el programa devolverá `-1`.

## Desarrollo

El código fue desarrollado en **C**, y sigue una estrategia basada en:
1. Ordenar el arreglo de habilidades.
2. Emparejar jugadores desde los extremos (el más débil con el más fuerte).
3. Verificar que la suma de habilidades sea constante en todos los equipos.
4. Calcular la química total acumulando el producto de las habilidades de cada pareja.

A continuación se presenta el código junto con una explicación detallada de cada línea.

## Conclusión

Este programa en C resuelve de manera eficiente el problema de formar equipos balanceados de jugadores y calcular la química total. La solución combina un ordenamiento O(n log n) seguido de un recorrido lineal O(n) para formar equipos válidos.
Es un código sencillo y modular que puede ser adaptado para diferentes escenarios de entrada. Además, es robusto ante entradas inválidas gracias a la verificación de sumas dentro de las parejas.

## Código y explicación línea por línea

```c
#include <stdio.h>   // Librería para funciones de entrada/salida como printf
#include <stdlib.h>  // Librería para funciones como qsort

// Función de comparación para qsort que ordena de menor a mayor
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // Devuelve negativo si *a < *b, positivo si *a > *b, 0 si son iguales
}

// dividePlayers: divide jugadores y calcula la química total
int dividePlayers(int* skill, int skillSize) {
    qsort(skill, skillSize, sizeof(int), compare); // Ordena las habilidades de menor a mayor

    int totalSkill = skill[0] + skill[skillSize - 1]; // Calcula la suma objetivo de cada pareja
    int chemistrySum = 0; // Acumulador para la química total

    // Bucle para recorrer la mitad del arreglo y emparejar extremos
    for (int i = 0; i < skillSize / 2; i++) {
        // Verifica que la suma de la pareja actual sea igual a la suma objetivo
        if (skill[i] + skill[skillSize - 1 - i] != totalSkill) {
            return -1; // Si no coincide, no se puede formar un grupo válido
        }
        // Acumula la química (producto de habilidades) de la pareja actual
        chemistrySum += skill[i] * skill[skillSize - 1 - i];
    }
    return chemistrySum; // Retorna la química total
}

int main() {
    int skill[] = {3, 2, 5, 1, 3, 4}; // Arreglo con las habilidades de los jugadores
    int n = sizeof(skill) / sizeof(skill[0]); // Calcula el tamaño del arreglo
    int result = dividePlayers(skill, n); // Llama a la función que resuelve el problema
    printf("%d\n", result); // Imprime el resultado final en consola
    return 0; // Fin del programa
}
