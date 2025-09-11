//
// Created by gabri on 10-09-2025.
//

#include "ListaCursos.h"
#include "ListAlumnos.h"

ListaCursos::ListaCursos() : cabeza(nullptr) {}

ListaCursos::~ListaCursos() {
    NodoCurso* actual = cabeza;
    while (actual != nullptr) {
        NodoCurso* temp = actual;
        actual = actual->getSiguiente();
        delete temp;
    }
}

void ListaCursos::insertar(Curso c) {
    NodoCurso* nuevo = new NodoCurso(c);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        NodoCurso* actual = cabeza;
        while (actual->getSiguiente()) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

void ListaCursos::buscarPorId(int idCurso) {
    bool encontrado = false;
    for (NodoCurso* actual = cabeza; actual; actual = actual->getSiguiente()) {
        if (actual->getCurso().getId() == idCurso) {
            cout << "Curso con ID: " << idCurso << " encontrado\n" << endl;
            encontrado = true;
            actual->getCurso().mostrar();
            break;
        }
    }
    if (!encontrado) {
        cout << "No se encontro el Curso con ID " << idCurso << endl;
    }
}

void ListaCursos::eliminarPorId(int idCurso) {
    if (cabeza == nullptr) {
        cout << "No se encontro el curso con ID " << idCurso << endl;
        return;
    }

    NodoCurso* anterior = nullptr;

    for (NodoCurso* actual = cabeza; actual != nullptr; actual = actual->getSiguiente()) {
        if (actual->getCurso().getId() == idCurso) {

            if (anterior == nullptr) {
                cabeza = actual->getSiguiente();
            } else {
                anterior->setSiguiente(actual->getSiguiente());
            }

            delete actual;
            cout << "Curso con ID " << idCurso << " eliminado\n";
            return;
        }
        anterior = actual;
    }

    cout << "No se encontro el curso con ID " << idCurso << endl;
}

void ListaCursos::mostrarTodos() {
    if (!cabeza) {
        cout << "No hay cursos registrados.\n";
        return;
    }
    for (NodoCurso* actual = cabeza; actual != nullptr; actual = actual->getSiguiente()) {
        actual->getCurso().mostrar();
    }
}
