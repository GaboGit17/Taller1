//
// Created by gabri on 11-09-2025.
//

#include "ListaInscripciones.h"

ListaInscripciones::ListaInscripciones() : cabeza(nullptr) {}

ListaInscripciones::~ListaInscripciones() {
    NodoInscripcion* actual = cabeza;
    while (actual) {
        NodoInscripcion* temp = actual;
        actual = actual->getSiguiente();
        delete temp;
    }
}

void ListaInscripciones::inscribir(int idAlumno, int idCurso) {
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->getSiguiente()) {
        if (actual->getIdAlumno() == idAlumno && actual->getIdCurso() == idCurso) {
            cout << " Alumno " << idAlumno << " ya esta inscrito en curso " << idCurso << endl;
            return;
        }
    }

    NodoInscripcion* nuevo = new NodoInscripcion(idAlumno, idCurso);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        NodoInscripcion* actual = cabeza;
        while (actual->getSiguiente()) actual = actual->getSiguiente();
        actual->setSiguiente(nuevo);
    }

    cout << " Alumno " << idAlumno << " inscrito en curso " << idCurso << endl;
}

void ListaInscripciones::eliminarPorAlumno(int idAlumno) {
    NodoInscripcion* anterior = nullptr;
    NodoInscripcion* actual = cabeza;

    while (actual) {
        if (actual->getIdAlumno() == idAlumno) {
            NodoInscripcion* temp = actual;
            if (anterior == nullptr) {
                cabeza = actual->getSiguiente();
                actual = cabeza;
            } else {
                anterior->setSiguiente(actual->getSiguiente());
                actual = anterior->getSiguiente();
            }
            delete temp;
        } else {
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }
}

void ListaInscripciones::eliminar(int idAlumno, int idCurso) {
    if (!cabeza) {
        cout << "No hay inscripciones registradas\n";
        return;
    }

    NodoInscripcion* anterior = nullptr;
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->getSiguiente()) {
        if (actual->getIdAlumno() == idAlumno && actual->getIdCurso() == idCurso) {
            if (anterior == nullptr) {
                cabeza = actual->getSiguiente();
            } else {
                anterior->setSiguiente(actual->getSiguiente());
            }
            delete actual;
            cout << "Inscripción eliminada: Alumno " << idAlumno << " en Curso " << idCurso << endl;
            return;
        }
        anterior = actual;
    }
    cout << "No se encontró inscripcion de Alumno " << idAlumno << " en Curso " << idCurso << endl;
}

void ListaInscripciones::eliminarPorCurso(int idCurso) {
    if (cabeza == nullptr) {
        cout << " No hay inscripciones registradas.\n";
        return;
    }

    NodoInscripcion* anterior = nullptr;

    for (NodoInscripcion* actual = cabeza; actual != nullptr; ) {
        if (actual->getIdCurso() == idCurso) {
            NodoInscripcion* temp = actual;

            if (anterior == nullptr) {
                cabeza = actual->getSiguiente();
                actual = cabeza;
            } else {
                anterior->setSiguiente(actual->getSiguiente());
                actual = anterior->getSiguiente();
            }

            delete temp;
        } else {
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }

    cout << " Se eliminaron todas las inscripciones del curso con ID: " << idCurso << endl;
}

void ListaInscripciones::agregarNota(int idAlumno, int idCurso, float nota) {
    bool agregado = false;
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->getSiguiente()) {
        if (actual->getIdAlumno() == idAlumno && actual->getIdCurso() == idCurso) {
            actual->agregarNota(nota);
            cout << "Nota agregada" << endl;
            agregado = true;
        }
    }
    if (!agregado) {
        cout << "No se encontró inscripción para Alumno: " << idAlumno << " en Curso: " << idCurso << endl;
    }

}

void ListaInscripciones::mostrarCursosDeAlumno(int idAlumno) {
    bool encontrado = false;
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->getSiguiente()) {
        if (actual->getIdAlumno() == idAlumno) {
            cout << " Alumno Inscrito en Curso ID: " << actual->getIdCurso() << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "Alumno " << idAlumno << " no esta inscrito en ningún curso\n";
    }
}

void ListaInscripciones::mostrarAlumnosDeCurso(int idCurso) {
    bool encontrado = false;
    for (NodoInscripcion* actual = cabeza; actual; actual = actual->getSiguiente()) {
        if (actual->getIdCurso() == idCurso) {
            cout << "Alumno ID: " << actual->getIdAlumno() << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay alumnos inscritos en curso " << idCurso << endl;
    }
}

void ListaInscripciones::PromedioAlumnoCurso(int idAlumno, int idCurso) {

    for (NodoInscripcion* actual = cabeza; actual; actual = actual->getSiguiente()) {
        if (actual->getIdCurso() == idCurso && actual->getIdAlumno() == idAlumno) {
            vector<float> notas = actual->getNotas();

            if (notas.empty()) {
                cout << "El alumno no tiene notas" << endl;
                return;
            }

            float suma = 0;
            for (float nota : notas) {
                suma += nota;

            }
            cout << "El promedio del alumno con ID: " << actual->getIdAlumno() << " es: " << suma/notas.size() << endl;
            return;


        }
    }


}
