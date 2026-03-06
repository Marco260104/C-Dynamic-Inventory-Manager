#pragma once
#include <cstdint>
#include <iostream>

struct Herramienta
{
    int64_t id_codigo;
    double precio;
    int stock;
};

void agregar(Herramienta *&productos, size_t n_actuales, size_t n_antiguos);
void mostrar(Herramienta *&productos, size_t n_actuales);
void guardar(Herramienta *productos, size_t n_actuales);
int buscar(Herramienta *productos, size_t n_actuales, int id_aux);
void vender(Herramienta *&productos, size_t n_actuales);
Herramienta* cargar(size_t &n_actuales);