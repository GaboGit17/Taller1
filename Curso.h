//
// Created by gabri on 10-09-2025.
//

#pragma once
#include <string>
using namespace std;


class Curso {

    private:
    int id;
    string nombre;
    int cantMax;
    string carrera;
    string profesor;
    public:
    Curso(int id, string nombre, int cantMax, string carrera, string profesor);
    int getId();
    string getNombre();
    int getCantMax();
    string getCarrera();
    string getProfesor();
    void setId(int id);
    void setNombre(string nombre);
    void setCantMax(int cantMax);
    void setCarrera(string carrera);
    void setProfesor(string profesor);
    void mostrar();
    ~Curso();

};


