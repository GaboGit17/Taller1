//
// Created by gabri on 11-09-2025.
//

#pragma once
#include <iostream>
#include <vector>
using namespace std;

class NodoInscripcion {
private:
    int idAlumno;
    int idCurso;
    vector<float> notas;
    NodoInscripcion* siguiente;

public:

    NodoInscripcion(int a, int c) : idAlumno(a), idCurso(c), siguiente(nullptr) {}


    int getIdAlumno() const { return idAlumno; }
    int getIdCurso() const { return idCurso; }

    vector<float>& getNotas() { return notas; }
    NodoInscripcion* getSiguiente() { return siguiente; }

    void setSiguiente(NodoInscripcion* nodo) { siguiente = nodo; }
    void agregarNota(float nota) { notas.push_back(nota); }
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
    void PromedioAlumnoCurso(int idAlumno, int idCurso);

    void mostrarCursosDeAlumno(int idAlumno);
    void mostrarAlumnosDeCurso(int idCurso);
};


