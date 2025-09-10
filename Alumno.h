//
// Created by gabri on 03-09-2025.
//


#pragma once
#include <string>
using namespace std;

class Alumno {
private:
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

public:
    // Constructor
    Alumno(int id, string nombre, string apellido, string carrera, string fechaIngreso);

    // Destructor
    ~Alumno();

    // Getters
    int getId();
    string getNombre();
    string getApellido();
    string getCarrera();
    string getFechaIngreso();

    // Setters
    void setId(int id);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setCarrera(string carrera);
    void setFechaIngreso(string fechaIngreso);

    // Mostrar información
    void mostrar();
};


