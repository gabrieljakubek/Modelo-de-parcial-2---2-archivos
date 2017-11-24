#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
#include "ArrayList.h"
#include "Principal.h"
#include "parserProducto.h"

int main()
{
    system("mode con: cols=120 lines=30");
    system("color 2");
    int opcion;
    int auxInt;
    //int flag = 0;
    FILE* datos;
    char seguir = 's';
    ArrayList* lista;
    lista = al_newArrayList();
    if(lista!=NULL)
    {
        datos = fopen("datos.csv","r");
        if(datos!=NULL)
        {
            parserProducto(datos,lista);
            fclose(datos);
        }

        do
        {
            opcion=funMostrarMenu("1- Alta\
                              \n2- Modificar\
                              \n3- Baja Logica\
                              \n4- Baja Fisica\
                              \n5- Listar\
                              \n6- Salir");

            switch(opcion)
            {
            case 1:
                auxInt = funAlta(lista);
                if(auxInt != -1)
                {
                    printf("El producto se pudo dar de alta!!!\n");
                    auxInt = funGuardar(lista,"tempdatos.csv");
                    if(auxInt!=0)
                    {
                        printf("No se pudodieron guardar los datos!!!\n");
                    }
                }
                else
                {
                    printf("Error no se pudo dar de alta Producto o ID ya existente!!\n");
                }
                funBorrarPantalla();
                break;

            case 2:
                if(lista->isEmpty(lista) == 1)
                {
                    printf("No hay datos cargados como para realizar la accion!!!");
                }
                else if(lista->isEmpty(lista) == 0)
                {
                    auxInt = funModif(lista);
                    if(auxInt == 1)
                    {
                        printf("El producto se modifico!!!\n");
                        auxInt = funGuardar(lista,"tempdatos.csv");
                        if(auxInt!=0)
                        {
                            printf("No se pudodieron guardar los datos!!!\n");
                        }
                    }
                    else if(auxInt == 0)
                    {
                        printf("El producto no se modifico!!!\n");
                    }
                    else
                    {
                        printf("Error el producto no se pudo encontrar o la lista no se encontro!!!\n");
                    }
                }
                else
                {
                    printf("Error lista no encontrada");
                }
                funBorrarPantalla();
                break;

            case 3:
               if(lista->isEmpty(lista) == 1)
                {
                    printf("No hay datos cargados como para realizar la accion!!!");
                }
                else if(lista->isEmpty(lista) == 0)
                {
                    auxInt = funBajaLogi(lista);
                    if(auxInt == 1)
                    {
                        printf("El producto se dio de baja logica!!!\n");
                        auxInt = funGuardar(lista,"tempdatos.csv");
                        if(auxInt!=0)
                        {
                            printf("No se pudodieron guardar los datos!!!\n");
                        }
                    }
                    else if(auxInt == 0)
                    {
                        printf("El producto no se dio de baja logica!!!\n");
                    }
                    else
                    {
                        printf("Error el producto no se pudo encontrar o la lista no se encontro!!!\n");
                    }
                }
                else
                {
                    printf("Error lista no encontrada");
                }
                funBorrarPantalla();
                break;

            case 4:
                if(lista->isEmpty(lista) == 1)
                {
                    printf("No hay datos cargados como para realizar la accion!!!");
                }
                else if(lista->isEmpty(lista) == 0)
                {
                    auxInt=funBajaFisi(lista);
                    if(auxInt == 1)
                    {
                        printf("El producto se dio de baja fisica!!!\n");
                        auxInt = funGuardar(lista,"tempdatos.csv");
                        if(auxInt!=0)
                        {
                            printf("No se pudodieron guardar los datos!!!\n");
                        }
                    }
                    else if(auxInt == 0)
                    {
                        printf("El producto no se dio de baja fisica!!!\n");
                    }
                    else
                    {
                        printf("Error el producto no se pudo encontrar o la lista no se encontro!!!\n");
                    }
                }
                else
                {
                    printf("Error lista no encontrada");
                }
                funBorrarPantalla();
                break;

            case 5:
                if(lista->isEmpty(lista) == 1)
                {
                    printf("No hay datos cargados como para realizar la accion!!!");
                }
                else if(lista->isEmpty(lista) == 0)
                {
                    printf("Desea ordenar decreciente (0) o creciente (1) ");
                    scanf("%d",&auxInt);
                    lista->sort(lista,funProductoCompare,auxInt);
                    funMostrarTodosProductos(lista);
                }
                else
                {
                    printf("Error lista no encontrada");
                }
                funBorrarPantalla();
                break;

            case 6:
                seguir = 'n';
                auxInt = funGuardar(lista,"datos.csv");
                if(auxInt!=0)
                {
                    printf("No se pudodieron guardar los datos!!!\n");
                }
                printf("Chau Chau!!!!!");
                break;

            default:
                printf("Opcion inexistente!!!\n");
                funBorrarPantalla();
                break;
            }
        }
        while(seguir != 'n');
    }
    return 0;
}
