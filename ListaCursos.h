//
// Created by gabri on 10-09-2025.
//

#pragma once
#include "Curso.h"
#include <iostream>
using namespace std;

class NodoCurso {
private:
    Curso curso;
    NodoCurso* siguiente;

public:
    NodoCurso(Curso c) : curso(c), siguiente(nullptr) {}

    Curso& getCurso() { return curso; }

    NodoCurso* getSiguiente() { return siguiente; }

    void setSiguiente(NodoCurso* nodo) { siguiente = nodo; }
};

class ListaCursos {
private:
    NodoCurso* cabeza;

public:
    ListaCursos();
    ~ListaCursos();

    void insertar(Curso c);
    void buscarPorId(int idCurso);
    void buscarPorNombre(string nombre);
    void eliminarPorId(int idCurso);
    void mostrarTodos();
};



