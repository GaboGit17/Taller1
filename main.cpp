//
// Created by gabri on 03-09-2025.
//

#include <iostream>
#include <ostream>

#include "Alumno.h"
#include "ListAlumnos.h"
ListAlumnos lista;

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

                cout << "Ingresa el nombre del alumno: ";
                cin >> nombre;

                cout << "Ingresa el apellido del alumno: ";
                cin >> apellido;

                cout << "Ingresa la carrera del alumno: ";
                cin >> carrera;

                cout << "Ingresa la fecha de ingreso (D-M-A): ";
                cin >> fechaIngreso;
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

}

void manejarCursos() {

}

void manejarNotas() {

}

void consultasReportes() {

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
