//
// Created by gabri on 11-09-2025.
//

#include "ListaInscripciones.h"


ListaInscripciones::ListaInscripciones() : cabeza(nullptr) {}


ListaInscripciones::~ListaInscripciones() {
    NodoInscripcion* actual = cabeza;
    while (actual) {
        NodoInscripcion* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}


void ListaInscripciones::inscribir(int idAlumno, int idCurso) {

    for (NodoInscripcion* actual = cabeza; actual; actual = actual->siguiente) {
        if (actual->idAlumno == idAlumno && actual->idCurso == idCurso) {
            cout << " Alumno " << idAlumno << " ya está inscrito en curso " << idCurso << endl;
            return;
        }
    }

    NodoInscripcion* nuevo = new NodoInscripcion(idAlumno, idCurso);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        NodoInscripcion* actual = cabeza;
        while (actual->siguiente) actual = actual->siguiente;
        actual->siguiente = nuevo;
    }

    cout << " Alumno " << idAlumno << " inscrito en curso " << idCurso << endl;
}

void ListaInscripciones::eliminarPorAlumno(int idAlumno) {
    NodoInscripcion* anterior = nullptr;
    NodoInscripcion* actual = cabeza;

    while (actual) {
        if (actual->idAlumno == idAlumno) {
            NodoInscripcion* temp = actual;
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
                actual = cabeza;
            } else {
                anterior->siguiente = actual->siguiente;
                actual = anterior->siguiente;
            }
            delete temp;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}


void ListaInscripciones::eliminar(int idAlumno, int idCurso) {
    if (!cabeza) {
        cout << "No hay inscripciones registradas.\n";
        return;
    }

    NodoInscripcion* anterior = nullptr;
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->siguiente) {
        if (actual->idAlumno == idAlumno && actual->idCurso == idCurso) {
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            cout << "Inscripción eliminada: Alumno " << idAlumno
                 << " en Curso " << idCurso << endl;
            return;
        }
        anterior = actual;
    }
    cout << "No se encontró inscripción de Alumno " << idAlumno
         << " en Curso " << idCurso << endl;
}

void ListaInscripciones::eliminarPorCurso(int idCurso) {
    if (cabeza == nullptr) {
        cout << " No hay inscripciones registradas.\n";
        return;
    }

    NodoInscripcion* anterior = nullptr;

    for (NodoInscripcion* actual = cabeza; actual != nullptr; ) {
        if (actual->idCurso == idCurso) {
            NodoInscripcion* temp = actual;


            if (anterior == nullptr) {
                cabeza = actual->siguiente;
                actual = cabeza;
            } else {
                anterior->siguiente = actual->siguiente;
                actual = anterior->siguiente;
            }

            delete temp;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    cout << " Se eliminaron todas las inscripciones del curso con ID " << idCurso << endl;
}

// Agregar nota
void ListaInscripciones::agregarNota(int idAlumno, int idCurso, float nota) {
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->siguiente) {
        if (actual->idAlumno == idAlumno && actual->idCurso == idCurso) {
            if (nota >= 1.0 && nota <= 7.0) {
                actual->notas.push_back(nota);
                cout << " Nota " << nota << " registrada para Alumno "
                     << idAlumno << " en Curso " << idCurso << endl;
            } else {
                cout << " Nota inválida. Debe estar entre 1.0 y 7.0\n";
            }
            return;
        }
    }
    cout << "No se encontró inscripción para Alumno " << idAlumno
         << " en Curso " << idCurso << endl;
}



// Mostrar cursos en los que está inscrito un alumno
void ListaInscripciones::mostrarCursosDeAlumno(int idAlumno) {
    bool encontrado = false;
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->siguiente) {
        if (actual->idAlumno == idAlumno) {
            cout << " Alumno Inscrito en Curso ID: " << actual->idCurso << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "Alumno " << idAlumno << " no está inscrito en ningún curso.\n";
    }
}

// Mostrar alumnos inscritos en un curso
void ListaInscripciones::mostrarAlumnosDeCurso(int idCurso) {
    bool encontrado = false;
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->siguiente) {
        if (actual->idCurso == idCurso) {
            cout << "Alumno ID: " << actual->idAlumno << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay alumnos inscritos en curso " << idCurso << endl;
    }
}

