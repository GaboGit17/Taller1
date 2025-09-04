//
// Created by gabri on 03-09-2025.
//


#pragma once
#include <string>
using namespace std;

class Alumno {
    private:

        string nombre;
        int edad;
        string carrera;
    public:

        Alumno(string nombre, int edad, string carrera);
        string getNombre();
        int getEdad();
        string getCarrera();

        void setEdad(int edad);

        void setNombre(string nombre);

        void setCarrera(string carrera);

        void mostrar();

    ~Alumno();
};


