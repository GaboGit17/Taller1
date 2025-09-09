//
// Created by gabri on 03-09-2025.
//

#include "Alumno.h"
#include <iostream>
using namespace std;

Alumno::Alumno(string nombre, int edad, string carrera) {
    this->edad = edad;
    this->nombre = nombre;
    this->carrera = carrera;
}

Alumno::~Alumno() {

}

int Alumno::getEdad() {
    return edad;
}


string Alumno::getNombre() {
    return nombre;
}


string Alumno::getCarrera() {
    return carrera;
}


void Alumno::setEdad(int edad) {
    this->edad = edad;
}


void Alumno::setNombre(string nombre) {
    this->nombre = nombre;
}


void Alumno::setCarrera(string carrera) {
    this->carrera = carrera;
}


void Alumno::mostrar() {
    cout << "Nombre: " << nombre
         << " | Edad: " << edad
         << " | Carrera: " << carrera << endl;
}
