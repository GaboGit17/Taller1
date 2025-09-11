//
// Created by gabri on 11-09-2025.
//

#pragma once
#include <iostream>
#include <vector>
using namespace std;


struct NodoInscripcion {
    int idAlumno;
    int idCurso;
    vector<float> notas;
    NodoInscripcion* siguiente;

    NodoInscripcion(int a, int c) : idAlumno(a), idCurso(c), siguiente(nullptr) {}
};


class ListaInscripciones {
private:
    NodoInscripcion* cabeza;

public:
    ListaInscripciones();
    ~ListaInscripciones();

    void inscribir(int idAlumno, int idCurso);
    void eliminar(int idAlumno, int idCurso);
    void agregarNota(int idAlumno, int idCurso, float nota);
    void eliminarPorAlumno(int idAlumno);
    void eliminarPorCurso(int idCurso);

    void mostrarCursosDeAlumno(int idAlumno);
    void mostrarAlumnosDeCurso(int idCurso);

};

