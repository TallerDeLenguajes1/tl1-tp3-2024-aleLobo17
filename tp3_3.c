#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int cantidadNombres = 5;

  char **listaNombres = (char **) malloc(sizeof(char *) * cantidadNombres);

  for (int i = 0; i < cantidadNombres; i++)
  {
    char cadena[100];
    printf("Ingrese el nombre %d: ", i + 1);
    gets(cadena);
    listaNombres[i] = (char *) malloc(sizeof(char) * (strlen(cadena) + 1));
    strcpy(listaNombres[i], cadena);
  }


  for (int i = 0; i < cantidadNombres; i++)
  {
    printf("%s\n", *(listaNombres + i));
  }

  return 0;
}