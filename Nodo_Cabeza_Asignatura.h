#pragma once
class Nodo_Cabeza_Asignatura
{
public: 
	int cantidad_asignaturas;
	class Nodo_Asignatura* siguiente_a;
	Nodo_Cabeza_Asignatura() : cantidad_asignaturas(0) {}
};

