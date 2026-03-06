/*Un programa para controlar el stock de productos físicos.

Struct: Herramienta { int64_t id_codigo; double precio; int stock; };

Tu Reto: Además de agregar y guardar en inventario.txt,
podrías intentar hacer una opción extra en el menú llamada
"Vender Herramienta" (que pida un ID al usuario, busque esa herramienta en el array dinámico y le reste 1 al stock).*/
#include <iostream>
#include "inventario.h"

int main()
{
    size_t n_actuales = 0;
    Herramienta *productos = cargar(n_actuales);
    size_t opc = 0;
    size_t n_antiguos = 0;
    std::cout << "====BIENVENIDO A FERRETERIA LOS HIDROS====" << std ::endl;
    do
    {

        std::cout << "Ingrese la opcion que desea hacer: " << std::endl;
        std::cout << "1. Agregar herramientas " << std::endl;
        std::cout << "2. Mostrar herramientas " << std::endl;
        std::cout << "3. Guardar herramientas " << std::endl;
        std::cout << "4. Buscar herramientas" << std::endl;
        std::cout << "5. Vender herramientas " << std::endl;
        std::cout << "6. Salir " << std::endl;
        std::cin >> opc;
        switch (opc)
        {
        case 1:
            n_antiguos = n_actuales;
            std::cout << "Ingrese cuantas herramientas desea agregar: ";
            std::cin >> n_actuales;
            n_actuales = n_actuales + n_antiguos;
            if (n_actuales > 0)
            {
                agregar(productos, n_actuales, n_antiguos);
            };
            break;
        case 2:
            if (n_actuales > 0)
            {
                mostrar(productos, n_actuales);
            }
            else
                std::cout << "AUN NO TIENES HERRAMIENTAS INGRESADAS" << std::endl;
            break;
        case 3:
            if (n_actuales > 0)
            {
                guardar(productos, n_actuales);
            }
            else
                std::cout << "AUN NO TIENES HERRAMIENTAS PARA GUARDAR" << std::endl;

            break;
        case 4:
            if (n_actuales > 0)
            {
                size_t id = 0;
                std::cout << "Ingrese el ID a buscar: ";
                std::cin>>id;
                if (buscar(productos, n_actuales, id) == -1){
                    std::cout << "ESTA HERRAMIENTA NO ESTA EN EL INVENTARIO" << std::endl;
                } else std::cout << "HERRAMIENTA DISPONIBLE" << std::endl;;
                
            }
            else
                std::cout << "NO TIENES HERRAMIENTAS PARA BUSCAR" << std::endl;

            break;
            break;
        case 5:
        if (n_actuales > 0)
            {
                vender(productos, n_actuales);
            }
            else
                std::cout << "AUN NO TIENES HERRAMIENTAS PARA VENDER" << std::endl;

            break;
            break;
        }

    } while (opc < 6);
    delete[] productos;
    productos = nullptr;
    return 0;
}