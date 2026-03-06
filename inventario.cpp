#include "inventario.h"
#include <fstream>

void agregar(Herramienta *&productos, size_t n_actuales, size_t n_antiguos)
{
    Herramienta *aux = new Herramienta[n_actuales];
    if (productos != nullptr)
    {
        for (size_t i = 0; i < n_antiguos; i++)
        {
            aux[i] = productos[i];
        }
    }
    for (size_t i = n_antiguos; i < n_actuales; i++)
    {
        std::cout << "Producto #" << i + 1 << std::endl;
        std::cout << "Codigo: " << i + 1 << std::endl;
        aux[i].id_codigo = i + 1;
        std::cout << "Ingrese el precio del producto #" << i + 1 << ": ";
        std::cin >> aux[i].precio;
        std::cout << "Ingrese el stock total del producto: ";
        std::cin >> aux[i].stock;
    }
    delete[] productos;
    productos = aux;
};

void mostrar(Herramienta *&productos, size_t n_actuales)
{
    std ::cout << "---IMPRESION DE LOS PRODUCTOS ACTUALES---" << std::endl;
    for (size_t i = 0; i < n_actuales; i++)
    {
        if (productos[i].stock > 0)
        {
            std::cout << std::endl;
            std::cout << "Codigo del producto: " << productos[i].id_codigo << std::endl;
            std::cout << "Precio del producto: " << productos[i].precio << std::endl;
            std::cout << "STOCK disponible: " << productos[i].stock << std::endl;
        }
    }
};

void guardar(Herramienta *productos, size_t n_actuales)
{

    std::ofstream archivo("Inventario.txt");
    if (!archivo.is_open())
    {
        std::cout << "NO FUE POSIBLE CREAR EL ARCHIVO INTENTALO NUEVAMENTE";
        return;
    }

    for (size_t i = 0; i < n_actuales; i++)
    {
        archivo << productos[i].id_codigo << " " << productos[i].precio << " " << productos[i].stock << std::endl;
    }

    archivo.close();
    std::cout << "ARCHIVOS GUARDADOS EXITOSAMENTE....." << std::endl;
};

int buscar(Herramienta *productos, size_t n_actuales, int id_aux)
{
    for (size_t i = 0; i < n_actuales; i++)
    {
        if (id_aux == productos[i].id_codigo)
        {
            return (int)i;
        }
    }
    return -1;
};

void vender(Herramienta *&productos, size_t n_actuales)
{
    size_t opc = 0;
    int indice_encontrado = -1;
    std ::cout << "---VENTA DE PRODUCTOS ELIJA EL QUE DESEA COMPRAR POR SU CODIGO---" << std::endl;
    for (size_t i = 0; i < n_actuales; i++)
    {
        if (productos[i].stock > 0)
        {
            std::cout << std::endl;
            std::cout << "Codigo del producto: " << productos[i].id_codigo << std::endl;
            std::cout << "Precio del producto: " << productos[i].precio << std::endl;
            std::cout << "STOCK disponible: " << productos[i].stock << std::endl;
        }
    }
    std::cout << std::endl;
    do
    {
        std::cout << "Codigo: ";
        std::cin >> opc;
        indice_encontrado = buscar(productos, n_actuales, opc);
        system("cls");
    } while (indice_encontrado == -1);
    int venta = 0;

    std::cout << std::endl;
    std::cout << "---PRODUCTO A VENDER---" << std::endl;
    std::cout << std::endl;
    std::cout << "Codigo del producto: " << productos[indice_encontrado].id_codigo << std::endl;
    std::cout << "Precio del producto: " << productos[indice_encontrado].precio << std::endl;
    std::cout << "STOCK disponible: " << productos[indice_encontrado].stock << std::endl;

    do
    {

        std::cout << std::endl;
        std::cout << "Ingrese la cantidad a vender revise el stock disponible: ";
        std::cin >> venta;
        system("cls");
    } while (venta > productos[indice_encontrado].stock);

    std::cout << std::endl;
    std::cout << "VENTA EXITOSA, GRACIAS!";
    productos[indice_encontrado].stock = productos[indice_encontrado].stock - venta;

    guardar(productos, n_actuales);
};

Herramienta *cargar(size_t &n_actuales)
{
    std::ifstream archivo("Inventario.txt");

    if (!archivo.is_open())
    { // Si no existe devolvemos un puntero en blanco
        n_actuales = 0;
        return nullptr;
    }

    char linea[500];
    size_t contador = 0;
    while (archivo.getline(linea, 500))
    {
        contador++;
    };
    archivo.clear();
    archivo.seekg(0);

    Herramienta *productos = new Herramienta[contador];
    for (size_t i = 0; i< contador;i++){
       archivo >> productos[i].id_codigo >>  productos[i].precio >>  productos[i].stock;

    }
    archivo.close();
    n_actuales = contador;
    return productos;
};