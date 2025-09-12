//
// Created by gabri on 03-09-2025.
//

#include <iostream>
#include <ostream>

#include "Alumno.h"
#include "ListaInscripciones.h"
#include "ListaCursos.h"
#include "ListAlumnos.h"
ListAlumnos lista;
ListaCursos listaCurso;
ListaInscripciones listaInscripciones;

void manejarAlumnos() {
    bool salir = false;
    while (!salir) {
        cout << "1. Crear un alumno con todos sus datos\n";
        cout << "2. Buscar un alumno ID o nombre y listar su informacion\n";
        cout << "3. Eliminar un alumno del sistema utilizando su ID\n";
        cout << "0. Salir\n";
        int opcion;
        cout << "Selecciona opcion:" << endl;
        cin >> opcion;
        while (opcion < 0 || opcion > 3) {
            cout << "Opcion invalida" << endl;
            cout << "Selecciona opcion:" << endl;
            cin >> opcion;
        }

        switch (opcion) {

            case 1: {
                int id;
                string nombre, apellido, carrera, fechaIngreso;

                cout << "Ingresa el ID del alumno: ";
                cin >> id;
                while (id < 0 ) {
                    cout << "Ingrese un valor de ID valido" << endl;
                    cin >> id;
                }

                cout << "Ingresa el nombre del alumno: ";
                cin >> nombre;
                while (nombre.empty()) {
                    cout << "Ingrese un nombre valido " << endl;
                    cin >> nombre;
                }

                cout << "Ingresa el apellido del alumno: ";
                cin >> apellido;
                while (apellido.empty()) {
                    cout << "Ingrese un apellido valido" << endl;
                    cin >> apellido;
                }

                cout << "Ingresa la carrera del alumno: ";
                cin >> carrera;
                while (carrera.empty()) {
                    cout << "Ingrese una carrera valida" << endl;
                    cin >> carrera;
                }

                cout << "Ingresa la fecha de ingreso (D-M-A): ";
                cin >> fechaIngreso;
                while (fechaIngreso.empty()) {
                    cout << "Ingrese una fecha valida" << endl;
                    cin >> fechaIngreso;
                }
                Alumno nuevo(id, nombre, apellido, carrera, fechaIngreso);
                lista.insertar(nuevo);

                break;
            }
            case 2: {
                string nombre;
                int id;
                cout << "Ingrese el nombre";
                cin >> nombre;
                cout << "Ingrese ID" << endl;
                cin >> id;
                lista.recorrer(id);

                break;
            }
            case 3: {
                int id;
                cout << "Ingrese ID" << endl;
                cin >> id;
                lista.eliminar(id);
                listaInscripciones.eliminarPorAlumno(id);

                break;
            }
            case 0:
                salir = true;
                cout << "Saliendo de menu alumno..." << endl;
                break;

        }

    }


}

void manejarInscripciones() {
    bool salir = false;
    while (!salir) {
        cout << "1. Insccribir Alumno a un Curso\n";
        cout << "2. Eliminar un Alumno de un Cruso\n";
        cout << "0. Salir\n";
        int opcion;
        cout << "Selecciona opcion:" << endl;
        cin >> opcion;
        while (opcion < 0 || opcion > 3) {
            cout << "Opcion invalida" << endl;
            cout << "Selecciona opcion:" << endl;
            cin >> opcion;
        }
        switch (opcion) {
            case 1: {
                int idCurso;
                int idAlumno;
                cout << "Ingresa el ID del Curso: ";
                cin >> idCurso;
                cout << "Ingresa el ID del alumno: ";
                cin >> idAlumno;
                listaInscripciones.inscribir(idAlumno, idCurso);

                break;
            }
            case 2: {
                int idAlumno;
                int idCurso;
                cout << "Ingresa el ID del Alumno: ";
                cin >> idAlumno;
                cout << "Ingresa el ID del Curso: ";
                cin >> idCurso;
                listaInscripciones.eliminar(idAlumno, idCurso);


                break;

            }
            case 0: {
                salir = true;
                cout << "Saliendo de menu alumno..." << endl;
                break;
            }

        }

    }

}

void manejarCursos() {
    bool salir = false;
    while (!salir) {
        cout<<"1. Crear un curso" << endl;
        cout<<"2. Buscar un curso" << endl;
        cout<<"3. Eliminar un curso" << endl;
        cout<<"0. Salir" << endl;
        int opcion;
        cout << "Selecciona opcion:" << endl;
        cin >> opcion;
        while (opcion < 0 || opcion > 3) {
            cout << "Opcion invalida" << endl;
            cout << "Selecciona opcion:" << endl;
            cin >> opcion;
        }
        switch (opcion) {
            case 1: {
                int id, cantMax;
                string nombre, carrera, profesor;
                cout << "Ingrese nombre del curso: ";
                cin >> nombre;
                cout << "Ingrese el ID del curso: ";
                cin >> id;
                cout << "Ingrese carrera del curso: ";
                cin >> carrera;
                cout << "Ingrese profesor del curso: ";
                cin >> profesor;
                cout << "Ingrese cantidad Max de alumnos: ";
                cin >> cantMax;
                Curso nuevo(id,nombre,cantMax,carrera,profesor);
                listaCurso.insertar(nuevo);

                break;
            }
            case 2: {
                int id;
                cout << "Ingrese ID del curso: ";
                cin >> id;
                listaCurso.buscarPorId(id);

                break;
            }
            case 3: {
                int id;
                cout << "Ingrese ID del curso: ";
                cin >> id;
                listaCurso.eliminarPorId(id);
                listaInscripciones.eliminarPorCurso(id);
                break;

            }
            case 0: {
                salir = true;
                cout << "Saliendo de menu curso..." << endl;
                break;

            }
        }

    }

}

void manejarNotas() {
    bool salir = false;
    while (!salir) {
        cout << "1. Ingresar Notas a un Alumno" << endl;
        cout << "0. Salir" << endl;
        int opcion;
        cout << "Selecciona opcion:" << endl;
        cin >> opcion;
        while (opcion < 0 || opcion > 3) {
            cout << "Opcion invalida" << endl;
            cout << "Selecciona opcion:" << endl;
            cin >> opcion;
        }
        switch (opcion) {
            case 1: {
                int idAlumno, idCurso;
                float nota;
                cout << "Ingrese el ID del Alumno: ";
                cin >> idAlumno;
                cout << "Ingrese el ID del Curso: ";
                cin >> idCurso;
                cout << "Ingrese la Nota del curso: ";
                cin >> nota;
                while (nota < 1.0 || nota > 7.0) {
                    cout << "Nota invalida" << endl;
                    cout << "Ingrese nuevamente la nota:" << endl;
                    cin >> nota;
                }
                listaInscripciones.agregarNota(idAlumno,idCurso,nota);
                break;
            }
            case 0: {
                salir = true;
                cout << "Saliendo de menu curso..." << endl;
                break;

            }
        }
    }



}

void consultasReportes() {
    bool salir = false;
    while (!salir) {
        cout << "1. Obtener todos los alumnos de una carrera\n";
        cout << "2. Obtener todos los cursos en los que un alumno esta inscrito\n";
        cout << "3. Calcular el promedio de notas de un alumno por curso\n";
        cout << "4. Calcular promedio general de un alumno\n";
        cout << "0. Salir" << endl;
        int opcion;
        cout << " Selecciona opcion:" << endl;
        cin >> opcion;
        while (opcion < 0 || opcion > 4) {
            cout << " Opcion invalida" << endl;
            cout << " Selecciona opcion:" << endl;
            cin >> opcion;
        }
        switch (opcion) {
            case 1: {
                string carrera;
                cout << " Ingrese carrera: ";
                cin >> carrera;
                lista.porCarrera(carrera);

                break;

            }
            case 2: {
                int id;
                cout << "Ingrese ID del Alumno: ";
                cin >> id;
                listaInscripciones.mostrarCursosDeAlumno(id);

                break;

            }
            case 3: {
                int idAlumno, idCurso;
                cout << "Ingrese ID del Curso: ";
                cin >> idCurso;
                cout << "Ingrese ID del Alumno: ";
                cin >> idAlumno;
                listaInscripciones.PromedioAlumnoCurso(idAlumno,idCurso);

                break;
            }
            case 4: {

                break;

            }
            case 0: {

                salir = true;
                cout << "Saliendo de menu curso..." << endl;
                break;
            }
        }

    }

}

int main(){
    bool salir = false;
    while (!salir) {
        cout << "Menu general" << endl;
        cout << "1. Manejo de Alumnos" << endl;
        cout << "2. Manejo de cursos" << endl;
        cout << "3. Manejo de Inscripciones" << endl;
        cout << "4. Manejo de notas" << endl;
        cout << "5. Consultas y reportes" << endl;
        cout << "0. Salir" << endl;

        int opcion;
        cout << "Selecciona opcion:" << endl;
        cin >> opcion;
        while (opcion < 0 || opcion > 5) {
            cout << "Opcion invalida" << endl;
            cout << "Selecciona opcion:" << endl;
            cin >> opcion;
        }


        switch (opcion) {
            case 1:
                manejarAlumnos();
                break;
            case 3:
                manejarInscripciones();
                break;
            case 2:
                manejarCursos();
                break;
            case 4:
                manejarNotas();
                break;
            case 5:
                consultasReportes();
                break;
            case 0:
                salir = true;
                cout << " Saliendo...\n";

        }

    }

    cout <<  "salimos " << endl;

    return 0;
};
