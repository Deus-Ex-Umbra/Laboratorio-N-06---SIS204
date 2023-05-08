#pragma once
#include "Nodo_Estudiante.h"
#include <string>
class Nodo_Asignatura
{
public:
	struct Asignatura {
		std::string codigo, nombre, descripcion;
		int cantidad_de_horas;
	}asignatura;
	int cantidad_estudiantes;
	Nodo_Asignatura* siguiente, * anterior;
	Nodo_Estudiante* siguiente_e;
	Nodo_Asignatura() : siguiente(nullptr), anterior(nullptr), siguiente_e(nullptr), cantidad_estudiantes(0) {}
};

