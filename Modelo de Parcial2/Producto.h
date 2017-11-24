#include "ArrayList.h"

typedef struct
{
    int id;
    char* descrip; // Sting Dynamic - con un len se lee un buffer y se le pasa a un malloc la cantidad de caracteres a gurardar
    float importe;
    int stock;
    int estado; //1 Activo - 0 No Activo
}eProducto;

/** \brief
 * Muestra el producto que se le pasa
 * \param producto eProducto*
 * \return void
 *
 */
void funMostrarProducto(eProducto* producto);

/** \brief
 *  Crea un nuevo producto
 * \return eProducto* retorna (NULL) si no se pudo cargar o el puntero al nuevo producto
 *
 */
eProducto* altaProducto(ArrayList* lista);

/** \brief
 *  Busca Id en los productos cargados
 * \param lista ArrayList* puntero a Arraylist
 * \param ID int ID a buscar
 * \return eProducto* retorna (NULL) si no se pudo cargar o el puntero al producto con ese ID
 *
 */
eProducto* funBuscarId(ArrayList* lista, int ID);

/** \brief
 *
 * \return eProducto*
 *
 */
eProducto* newProducto();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int funProductoCompare (void* eProductoA,void* eProductoB);
