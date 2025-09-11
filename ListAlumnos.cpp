//
// Created by gabri on 09-09-2025.
//

#include "ListAlumnos.h"

ListAlumnos::ListAlumnos() : cabeza(nullptr) {}

ListAlumnos::~ListAlumnos() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->getSiguiente();
        delete temp;
    }
}

void ListAlumnos::insertar(Alumno a) {
    Nodo* nuevo = new Nodo(a);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->getSiguiente()) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

void ListAlumnos::recorrer(int id) {
    bool encontrado = false;

    for (Nodo* actual = cabeza; actual != nullptr; actual = actual->getSiguiente()) {
        if (actual->getAlumno().getId() == id) {
            cout << "Alumno con ID " << id << " encontrado\n" << endl;
            actual->getAlumno().mostrar();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro al alumno con ID " << id << endl;
    }
}

void ListAlumnos::eliminar(int id) {
    if (cabeza == nullptr) {
        cout << "No se encontro al alumno con ID " << id << endl;
        return;
    }

    Nodo* anterior = nullptr;
    for (Nodo* actual = cabeza; actual != nullptr; actual = actual->getSiguiente()) {
        if (actual->getAlumno().getId() == id) {

            if (anterior == nullptr) {
                cabeza = actual->getSiguiente();
            } else {
                anterior->setSiguiente(actual->getSiguiente());
            }

            delete actual;
            cout << " Alumno con ID " << id << " eliminado\n";
            return;
        }
        anterior = actual;
    }
}

void ListAlumnos::porCarrera(string carrera) {
    if (cabeza == nullptr) {
        cout << "No se encontro alumnos en esa carrera\n";
        return;
    }
    bool encontrado = false;

    for (Nodo* actual = cabeza; actual != nullptr; actual = actual->getSiguiente()) {
        if (actual->getAlumno().getCarrera() == carrera) {
            actual->getAlumno().mostrar();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontro al alumno con esa carrera\n";
    }
}





