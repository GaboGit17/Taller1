//
// Created by gabri on 09-09-2025.
//

#pragma once

#include "Alumno.h"
#include <iostream>
using namespace std;

class Nodo {
private:
    Alumno alumno;
    Nodo* siguiente;

public:
    Nodo(Alumno a) : alumno(a), siguiente(nullptr) {}

    Alumno& getAlumno() { return alumno; }
    Nodo* getSiguiente() { return siguiente; }

    void setSiguiente(Nodo* nodo) { siguiente = nodo; }
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
    void porCarrera(string carrera);
};


