//
// Created by gabri on 10-09-2025.
//

#include "Curso.h"
#include <iostream>
using namespace std;

//constructor
Curso::Curso(int id, string nombre, int cantMax, string carrera, string profesor) {
    this->id = id;
    this->nombre = nombre;
    this->carrera = carrera;
    this->cantMax = cantMax;
    this->profesor = profesor;

}
Curso::~Curso() {

}
int Curso::getId() { return id; }
string Curso::getNombre() { return nombre; }
string Curso::getCarrera() { return carrera; }
string Curso::getProfesor() { return profesor; }
int Curso::getCantMax() { return cantMax; }

void Curso::setId(int id) { this->id = id; }
void Curso::setNombre(string nombre) {this->nombre = nombre; }
void Curso::setCantMax(int cantMax) {this->cantMax = cantMax; }
void Curso::setCarrera(string carrera) {this->carrera = carrera; }
void Curso::setProfesor(string profesor) {this->profesor = profesor; }
void Curso::mostrar() {
    cout << "ID Curso: " << id
         << " | Nombre: " << nombre
         << " | Cantidad Maxima alumnos: " << cantMax
         << " | Carrera: " << carrera
         << " | Profesor: " << profesor
         << endl;
}







