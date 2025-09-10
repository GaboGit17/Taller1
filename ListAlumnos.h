//
// Created by gabri on 09-09-2025.
//

#pragma once

#include "Alumno.h"
#include <iostream>
using namespace std;

struct Nodo {
    Alumno alumno;
    Nodo* siguiente;
    Nodo(Alumno a) : alumno(a), siguiente(nullptr) {}
};

class ListAlumnos {
private:
    Nodo* cabeza;

public:
    ListAlumnos();
    ~ListAlumnos();

    void insertar(Alumno a);

    void recorrer(int id);

    void eliminar(int id);
};

