#pragma once
#include <string>
class Nodo_Estudiante
{
public:
	struct Estudiante {
		std::string codigo, nombre, direccion, sexo, estado;
		int edad, nota;
	}estudiante;
	Nodo_Estudiante* siguiente, * anterior;
	Nodo_Estudiante() : siguiente(nullptr), anterior(nullptr) {}
};

