#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fun.h"
#include "ArrayList.h"
#include "Producto.h"

void funMostrarProducto(eProducto* producto)
{
    printf("%d\t%10s\t%.2f\t%d\n",producto->id,producto->descrip,producto->importe,producto->stock);
}

eProducto* newProducto()
{
    eProducto* producto;
    producto = (eProducto*)malloc(sizeof(eProducto));
    return producto;
}

eProducto* altaProducto(ArrayList* lista)
{
    eProducto* producto = NULL;
    eProducto* auxProducto;
    producto = (eProducto*) malloc(sizeof(eProducto));
    int auxInt, auxRetor;
    float auxFloat;
    char buffer [10000];

    if(producto != NULL)
    {
        printf("Ingrese la ID del producto: ");
        fflush(stdin);
        gets(buffer);
        auxRetor = funChequeoNumero(buffer);
        while(auxRetor != 0)
        {
            printf("Reingrese la ID del producto: ");
            fflush(stdin);
            gets(buffer);
            auxRetor = funChequeoNumero(buffer);
        }
        auxInt = atoi(buffer);
        auxProducto=funBuscarId(lista,auxInt);
        if(auxProducto!=NULL)
        {
            return producto = NULL;
        }
        producto->id = auxInt;

        printf("Ingrese la descripcion del producto: ");
        fflush(stdin);
        gets(buffer);
        producto->descrip=funCharDyn(buffer);

        printf("Ingrese el Stock: ");
        fflush(stdin);
        gets(buffer);
        auxRetor = funChequeoNumero(buffer);
        while(auxRetor != 0)
        {
            printf("Reingrese el Stock: ");
            fflush(stdin);
            gets(buffer);
            auxRetor = funChequeoNumero(buffer);
        }
        auxInt = atoi(buffer);
        producto->stock = auxInt;

        printf("Ingrese el Importe: $");
        fflush(stdin);
        gets(buffer);
        auxInt = funChequeoFloat(buffer);
        while (auxInt != 0)
        {
            printf("Reingrese el Importe: $");
            fflush(stdin);
            gets(buffer);
            auxInt = funChequeoFloat(buffer);
        }
        auxFloat = atof(buffer);
        producto->importe = auxFloat;

        producto->estado = 1;

    }
    return producto;
}

eProducto* funBuscarId(ArrayList* lista, int ID)
{
    eProducto* producto;
    int i;
    int flag = 0;

    if(lista != NULL)
    {
        producto = (eProducto*)malloc(sizeof(eProducto));
        if(producto!=NULL)
        {
            for(i=0;i<lista->len(lista);i++)
            {
                producto=(eProducto*)lista->get(lista,i);
                if(producto->id==ID)
                {
                    flag = 1;
                   break;
                }
            }
            if (flag!=1)
            {
                producto=NULL;
            }
        }
    }
    return producto;
}

int funProductoCompare (void* eProductoA,void* eProductoB)
{
    int auxInt;
    eProducto* producto1 = (eProducto*) eProductoA;
    eProducto* producto2 = (eProducto*) eProductoB;
    auxInt = strcmp(producto1->descrip,producto2->descrip);
    return auxInt;
}
