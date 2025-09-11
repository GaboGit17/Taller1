//
// Created by gabri on 10-09-2025.
//

#pragma once
#include "Curso.h"
#include <iostream>
using namespace std;


struct NodoCurso {
    Curso curso;
    NodoCurso* siguiente;

    NodoCurso(Curso c) : curso(c), siguiente(nullptr) {}
};


class ListaCursos {
private:
    NodoCurso* cabeza;

public:
    ListaCursos();
    ~ListaCursos();

    void insertar(Curso c);
    Curso* buscarPorId(int idCurso);
    void eliminarPorId(int idCurso);
    void mostrarTodos();
};


