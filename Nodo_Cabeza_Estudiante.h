#pragma once
#include "Nodo_Estudiante.h"
class Nodo_Cabeza_Estudiante: public Nodo_Estudiante 
{
public: 
	int cantidad_estudiantes;
	Nodo_Cabeza_Estudiante() : cantidad_estudiantes(0) {}
};

