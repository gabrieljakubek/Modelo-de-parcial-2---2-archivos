#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fun.h"
#include "ArrayList.h"
#include "Producto.h"

int funMostrarTodosProductos(ArrayList* lista)
{
    int i;
    int auxRetorno = -1;
    eProducto* producto = NULL;
    if(lista!=NULL)
    {
        printf("%s\t%10s\t%s\t%s\n","ID","Descripcion","Importe","Stock");
        for(i=0; i<al_len(lista); i++)
        {
            producto=lista->get(lista,i);
            if(producto->estado == 1)
            {
                funMostrarProducto(producto);
            }
        }
        auxRetorno = 0;
    }
    return auxRetorno;
}

int funAlta(ArrayList* lista)
{
    eProducto* producto = NULL;
    producto = altaProducto(lista);
    int returnAux = -1;

    if(producto!=NULL)
    {
        returnAux = lista->add(lista,producto);
    }
    return returnAux;
}

int funModif(ArrayList* lista)
{
    eProducto* producto;
    int auxRetorno = -1;
    int flag = -1;
    int auxInt, opcion, auxRetor;
    float auxFloat;
    char buffer[1000], seguir='s';
    char auxResp;
    if(lista!=NULL)
    {
        flag = funMostrarTodosProductos(lista);
        if(flag!=-1)
        {

            printf("Ingrese el ID de el producto a modificar: ");
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
            producto=funBuscarId(lista,auxInt);
            if(producto!=NULL && producto->estado!=0)
            {
                system("cls");
                do
                {
                    printf("%s\t%s\t%s\t%s\n","ID","Descripcion","Importe","Stock");
                    funMostrarProducto(producto);
                    opcion=funMostrarMenu("1- Descripcion\
                                      \n2- Importe\
                                      \n3- Stock\
                                      \n4- Salir");

                    switch(opcion)
                    {
                    case 1:
                        printf("Ingrese la nueva descripcion: ");
                        fflush(stdin);
                        gets(buffer);
                        printf("Esta seguro de cambiar el titulo? s/n ");
                        auxResp = getche();
                        if (auxResp == 's')
                        {
                            producto->descrip=funCharDyn(buffer);
                            printf("\nSe modifico el titulo");
                            auxRetorno = 1;
                        }
                        else
                        {
                            printf("\nNo se modifico el titulo");
                        }
                        funBorrarPantalla();
                        break;

                    case 2:
                        printf("Ingrese el nuevo Importe: $");
                        fflush(stdin);
                        gets(buffer);
                        auxInt = funChequeoFloat(buffer);
                        while (auxInt != 0)
                        {
                            printf("Reingrese el nuevo Importe: $");
                            fflush(stdin);
                            gets(buffer);
                            auxInt = funChequeoFloat(buffer);
                        }
                        auxFloat = atof(buffer);
                        printf("Esta seguro de cambiar el titulo? s/n ");
                        auxResp = getche();
                        if (auxResp == 's')
                        {
                            producto->importe = auxFloat;
                            printf("\nSe modifico el Importe");
                            auxRetorno = 1;
                        }
                        else
                        {
                            printf("\nNo se modifico el Importe");
                        }
                        funBorrarPantalla();
                        break;

                    case 3:
                        printf("Ingrese el nuevo Stock: ");
                        fflush(stdin);
                        gets(buffer);
                        auxRetor = funChequeoNumero(buffer);
                        while(auxRetor != 0)
                        {
                            printf("Reingrese el nuevo Stock: ");
                            fflush(stdin);
                            gets(buffer);
                            auxRetor = funChequeoNumero(buffer);
                        }
                        auxInt = atoi(buffer);
                        printf("Esta seguro de cambiar el titulo? s/n ");
                        auxResp = getche();
                        if (auxResp == 's')
                        {
                            producto->stock = auxInt;
                            printf("\nSe modifico el Stock");
                            auxRetorno = 1;
                        }
                        else
                        {
                            printf("\nNo se modifico el Stock");
                        }
                        funBorrarPantalla();
                        break;

                    case 4:
                        seguir = 'n';
                        if(auxRetorno!=1)
                        {
                            auxRetorno=0;
                        }
                        break;
                    default:
                        printf("Opcion ingresada inexistente");
                        funBorrarPantalla();
                    }
                }
                while(seguir=='s');
            }
        }
    }
    return auxRetorno;
}

int funBajaLogi(ArrayList* lista)
{
    eProducto* producto;
    int auxRetorno = -1, auxResp, auxInt;
    int flag = -1;
    char buffer[1000],seguir;

    if(lista!=NULL)
    {
        flag = funMostrarTodosProductos(lista);
        if(flag!=-1)
        {
            printf("Ingrese el ID de el producto a dar de Baja Logica: ");
            fflush(stdin);
            gets(buffer);
            auxResp = funChequeoNumero(buffer);
            while(auxResp != 0)
            {
                printf("Reingrese la ID del producto a dar de Baja Logica: ");
                fflush(stdin);
                gets(buffer);
                auxResp = funChequeoNumero(buffer);
            }
            auxInt = atoi(buffer);
            producto=funBuscarId(lista,auxInt);
            if(producto!=NULL && producto->estado!=0)
            {
                system("cls");
                printf("%s\t%s\t%s\t%s\n","ID","Descripcion","Importe","Stock");
                funMostrarProducto(producto);
                printf("Esta seguro que desea dar de bajua logica este producto? (s/n) ");
                seguir=getche();
                if(seguir=='s')
                {
                    producto->estado = 0;
                    auxRetorno = 1;
                }
                else
                {
                    auxRetorno = 0;
                }
            }
        }
    }
    return auxRetorno;
}

int funBajaFisi(ArrayList* lista)
{
    eProducto* producto;
    int auxRetorno = -1, auxResp, auxInt;
    int flag = -1;
    char buffer[1000],seguir;

    if(lista!=NULL)
    {
        flag = funMostrarTodosProductos(lista);
        if(flag!=-1)
        {
            printf("Ingrese el ID de el producto a dar de Baja Logica: ");
            fflush(stdin);
            gets(buffer);
            auxResp = funChequeoNumero(buffer);
            while(auxResp != 0)
            {
                printf("Reingrese la ID del producto a dar de Baja Logica: ");
                fflush(stdin);
                gets(buffer);
                auxResp = funChequeoNumero(buffer);
            }
            auxInt = atoi(buffer);
            producto=funBuscarId(lista,auxInt);
            if(producto!=NULL && producto->estado!=0)
            {
                system("cls");
                printf("%s\t%s\t%s\t%s\n","ID","Descripcion","Importe","Stock");
                funMostrarProducto(producto);
                printf("Esta seguro que desea dar de bajua logica este producto? (s/n) ");
                seguir=getche();
                if(seguir=='s')
                {
                    auxInt=lista->indexOf(lista,producto);
                    if(auxInt!=-1)
                    {
                        auxInt=lista->remove(lista,auxInt);
                        auxRetorno = 1;
                    }
                }
                else
                {
                    auxRetorno = 0;
                }
            }
        }
    }
    return auxRetorno;
}


int funGuardar(ArrayList* lista, char destino[])
{
    int flag = 0;
    int i;
    //int auxInt;
    eProducto* producto;
    FILE* arch;
    arch=fopen(destino,"w");
    if(arch != NULL)
    {
        fprintf(arch, "%s,%s,%s,%s,%s\n","ID","Descrip","Importe","Stock","Estado");
        for(i=0;i<lista->len(lista);i++)
        {
            producto=lista->get(lista,i);
            fprintf(arch, "%d,%s,%f,%d,%d\n",producto->id,producto->descrip,producto->importe,producto->stock,producto->estado);
            //fwrite(lista->get(lista,i), sizeof(eProducto), 1, arch);
        }
        fclose(arch);
    }
    else
    {
        flag = -1;
    }
    return flag;
}
