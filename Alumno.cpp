//
// Created by gabri on 03-09-2025.
//

#include "Alumno.h"
#include <iostream>
using namespace std;

#include "Alumno.h"

// Constructor
Alumno::Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso) {
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->carrera = carrera;
    this->fechaIngreso = fechaIngreso;
}

// Destructor
Alumno::~Alumno() {
    // nada especial que liberar
}

// Getters
int Alumno::getId() { return id; }
string Alumno::getNombre() { return nombre; }
string Alumno::getApellido() { return apellido; }
string Alumno::getCarrera() { return carrera; }
string Alumno::getFechaIngreso() { return fechaIngreso; }

// Setters
void Alumno::setId(int id) { this->id = id; }
void Alumno::setNombre(string nombre) { this->nombre = nombre; }
void Alumno::setApellido(string apellido) { this->apellido = apellido; }
void Alumno::setCarrera(string carrera) { this->carrera = carrera; }
void Alumno::setFechaIngreso(string fechaIngreso) { this->fechaIngreso = fechaIngreso; }

// Mostrar información
void Alumno::mostrar() {
    cout << "ID: " << id
         << " | Nombre: " << nombre
         << " | Apellido: " << apellido
         << " | Carrera: " << carrera
         << " | Fecha de ingreso: " << fechaIngreso
         << endl;
}

