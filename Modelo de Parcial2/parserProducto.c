#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fun.h"
#include "ArrayList.h"
#include "Producto.h"

int parserProducto(FILE* archivo, ArrayList* lista)
{
    eProducto* producto;
    char auxID[10], auxEstado[10];
    char auxDesc [1000], auxImport [51], auxStock [51];
    int auxRetorn = -1;
    int flag = -1;
    fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxDesc,auxImport,auxStock,auxEstado);
    while (!feof(archivo))
    {
        producto=newProducto();
        if(producto!=NULL)
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxDesc,auxImport,auxStock,auxEstado);
            producto->id = atoi(auxID);
            producto->descrip=funCharDyn(auxDesc);
            producto->importe=atof(auxImport);
            producto->stock=atoi(auxStock);
            producto->estado=atoi(auxEstado);
            lista->add(lista,producto);
            flag = 0;
            /*auxResp=fread(producto,sizeof(eProducto),1,archivo);
            funMostrarProducto(producto);
            if(auxResp!=0)
            {
                lista->add(lista,producto);
                flag = 0;
            }*/
        }
        else
        {
            flag = -1;
            break;
        }
    }
    if(flag!=-1)
    {
        auxRetorn = 0;
    }
    return auxRetorn;
}
