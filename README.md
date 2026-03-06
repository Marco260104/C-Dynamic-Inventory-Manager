# 🛠️ HidrosCore CLI - C++ Inventory Engine

*(Read in [English](#english) | Leer en [Español](#español))*

---

## <a id="english"></a> 🇬🇧 English

### 📌 About the Project
**HidrosCore CLI** is a Command-Line Interface (CLI) inventory management system built entirely in pure C++ for "Ferretería Los Hidros". This project was developed to master low-level memory management, pointers, and software engineering fundamentals without relying on high-level standard libraries (like `std::vector`).

### 🚀 Key Features
* **CRUD Operations:** Add, view, search, and sell inventory items.
* **Data Persistence:** Automatically loads and saves inventory data to a local `.txt` file upon startup and exit.
* **Dynamic Stock Management:** Real-time stock validation and updates during sales transactions.

### 🧠 Technical Concepts Applied
* **Manual Memory Management:** Dynamic array allocation (`new` and `delete[]`) preventing memory leaks.
* **Modular Architecture:** Clean separation of declaration and implementation using header (`.h`) and source (`.cpp`) files.
* **File I/O Streams:** Two-pass algorithm for reading, parsing, and writing data using the `<fstream>` library.
* **Pointers & References:** Efficient data handling and manipulation across functions using pointers passed by reference (`*&`).

### ⚙️ How to Compile and Run
Ensure you have the GCC compiler installed (`g++`). Open your terminal in the project directory and run:

```bash
# Compile the project
g++ -Wall -Wextra main.cpp inventario.cpp -o ferreteria.exe

# Run the executable
./ferreteria.exe
```

# 🛠️ HidrosCore CLI - Sistema de Inventario en C++

## <a id="español"></a> 🇬🇧 Español

### 📌 Sobre el Proyecto
**HidrosCore CLI** es un sistema de gestión de inventario por interfaz de línea de comandos (CLI) construido completamente en C++ puro para "Ferretería Los Hidros". Este proyecto fue desarrollado para dominar el manejo de memoria a bajo nivel, punteros y los fundamentos de la ingeniería de software sin depender de librerías estándar de alto nivel (como `std::vector`).

### 🚀 Características Principales
* **Operaciones CRUD:** Agregar, visualizar, buscar y vender artículos del inventario.
* **Persistencia de Datos:** Carga y guarda automáticamente los datos del inventario en un archivo local `.txt` al iniciar y al salir.
* **Gestión Dinámica de Stock:** Validación y actualización de stock en tiempo real durante las transacciones de venta.

### 🧠 Conceptos Técnicos Aplicados
* **Gestión Manual de Memoria:** Asignación de arrays dinámicos (`new` y `delete[]`) evitando fugas de memoria (*memory leaks*).
* **Arquitectura Modular:** Separación limpia de la declaración y la implementación mediante archivos de cabecera (`.h`) y código fuente (`.cpp`).
* **Flujos de Entrada/Salida (I/O):** Algoritmo de dos pasadas para leer, analizar y escribir datos usando la librería `<fstream>`.
* **Punteros y Referencias:** Manejo y manipulación eficiente de datos entre funciones mediante el paso de punteros por referencia (`*&`).

### ⚙️ Cómo Compilar y Ejecutar
Asegúrate de tener instalado el compilador GCC (`g++`). Abre tu terminal en el directorio del proyecto y ejecuta:

```bash
# Compilar el proyecto
g++ -Wall -Wextra main.cpp inventario.cpp -o ferreteria.exe

# Ejecutar el programa
./ferreteria.exe
