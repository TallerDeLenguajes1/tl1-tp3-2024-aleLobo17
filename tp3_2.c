#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int *matriz, int filas, int columnas)
{
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      *(matriz + i * columnas + j) = 10000 + rand() % 40001;
    }
  }
}

void mostrarMatriz(int *matriz, int filas, int columnas)
{
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      printf("%d ", *(matriz + i * columnas + j) );
    }
    printf("\n");
  }
  printf("\n");
}

void calcularPromedio(int *matriz, int filas, int columnas)
{
  for (int i = 0; i < filas; i++)
  {
    float suma = 0;
    for (int j = 0; j < columnas; j++)
    {
      suma += *(matriz + i * columnas + j);
    }
    printf("El promedio del anio %d es: %.2f\n", (i + 1), suma/12);
  }
  printf("\n");
}

void maxYMin(int *matriz, int filas, int columnas)
{
  int mesMayor = 0;
  int mesMenor = 0;
  int anioMayor = 0;
  int anioMenor = 0;
  int menor = *(matriz);
  int mayor = *(matriz);
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      if(*(matriz + i * columnas + j) < menor)
      {
        menor = *(matriz + i * columnas + j);
        anioMenor = i;
        mesMenor = j;
      } 
      if(*(matriz + i * columnas + j) > mayor) 
      {
        mayor = *(matriz + i * columnas + j);
        anioMayor = i;
        mesMayor = j;
      }
    }
  }

  printf("La mayor venta fue en el mes %d, del anio %d: \n", mesMayor + 1, anioMayor + 1);
  printf("La menor venta fue en el mes %d, del anio %d: \n", mesMenor + 1, anioMenor + 1);

}


int main()
{
  int filas = 5;
  int columnas = 12;

  int *matriz = (int *) malloc(sizeof(int) * filas * columnas);

  cargarMatriz(matriz, filas, columnas);
  mostrarMatriz(matriz, filas, columnas);
  calcularPromedio(matriz, filas, columnas);
  maxYMin(matriz, filas, columnas);

  free(matriz);

  return 0;
}