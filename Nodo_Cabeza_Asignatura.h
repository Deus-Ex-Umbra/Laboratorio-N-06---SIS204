#pragma once
#include "Nodo_Asignatura.h"
class Nodo_Cabeza_Asignatura
{
public: 
	int cantidad_asignaturas;
	Nodo_Asignatura* siguiente_a;
	Nodo_Cabeza_Asignatura() : cantidad_asignaturas(0) {}
};

