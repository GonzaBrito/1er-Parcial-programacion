#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3
typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;


int aplicarAumento(float precio, float* aumento);

int reemplazarCaracteres(char cadena[], int a, int b);

int ordenarVector(eVacuna vacuna[], int tam);

int main()
{
    float precio = 15.5;
    float aumento;
    aplicarAumento(precio, &aumento);
    printf("%.2f\n\n", aumento);


   char cadena[30] = "gonzalo";
   int a = 'a';
   int b = 'o';

   //reemplazarCaracteres(cadena, a, b);

   printf("%d", reemplazarCaracteres(cadena, a, b));


   eVacuna vacuna[TAM] = {
       {1000, "tipoLocura", 15.5},
       {1001, "tipoCarnada", 29.5},
       {1002, "tipoAracel", 21.6}
    };

   ordenarVector(vacuna, TAM);

   return 0;
}

int aplicarAumento(float precio, float* aumento)
{
    int todoOk = 0;

    if(precio > 0)
    {
        *aumento = precio+(precio*0.05);
        todoOk = 1;
    }

    return todoOk;
}

int reemplazarCaracteres(char cadena[], int a, int b)
{
    int todoOk = 0;
    int contador = 0;

    for(int i = 0; i<strlen(cadena); i++)
    {
        if(cadena[i]==a)
        {
            cadena[i] = b;
            contador++;
        }
    }

    return contador;
}


int ordenarVector(eVacuna vacuna[], int tam)
{
    int todoOk= 0;
    char aux;
    if(vacuna != NULL && tam < 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(strcmp(vacuna[i].tipo, vacuna[i].tipo)>0)
                {
                    aux = vacuna[i].tipo;
                    vacuna[i].tipo = vacuna[j].tipo;
                    vacuna[j].tipo = aux;
                }
                else if(strcmp(vacuna[i].tipo, vacuna[i].tipo)== 0)
                {
                    if(vacuna[i].efectividad > vacuna[j].efectividad)
                    {
                        aux = vacuna[i].efectividad;
                        vacuna[i].efectividad = vacuna[j].efectividad;
                        vacuna[j].efectividad = aux;
                    }
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



