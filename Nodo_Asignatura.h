#pragma once
#include <string>
#include "Nodo_Cabeza_Estudiante.h"
class Nodo_Asignatura
{
public:
	struct Asignatura {
		std::string codigo, nombre, descripcion;
		int cantidad_de_horas;
	}asignatura;
	Nodo_Asignatura* siguiente, * anterior;
	Nodo_Cabeza_Estudiante* siguiente_e;
	Nodo_Asignatura() : siguiente(nullptr), anterior(nullptr), siguiente_e(nullptr) {}
};

