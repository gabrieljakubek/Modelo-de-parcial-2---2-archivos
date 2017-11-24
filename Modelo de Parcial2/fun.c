#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "fun.h"


int funMostrarMenu(char texto[])
{
    int opcion;
    printf("%s", texto);
    printf("\nIngrese la opcion a usar: ");
    scanf("%d", &opcion);

    return opcion;
}

void funBorrarPantalla()
{
    system("pause");
    system("cls");
}

int funChequeoNumero(char num[])
{
    int i = 0, cont;
    int flag = 0;
    cont = strlen(num);
    while (i<cont && flag == 0)
    {
        if(isdigit(num[i])!=0)
        {
            i++;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}

int funChequeoFloat(char num[])
{
    int i = 0, cont, contPunt = 0;
    int flag = 0;
    cont = strlen(num);
    while(i<cont && flag == 0)
    {
        if(isdigit(num[i])!=0)
        {
            i++;
        }
        else if(num[i]== '.' && contPunt <1)
        {
            i++;
            contPunt++;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}

char* funCharDyn(char buffer[] )
{
    char* returnAux;
    char* texto;
    texto = (char*)malloc(sizeof(char)*strlen(buffer)+1);
    if(texto!=NULL)
    {
        strcpy(texto,buffer);
        returnAux = texto;
    }
    return returnAux;
}
