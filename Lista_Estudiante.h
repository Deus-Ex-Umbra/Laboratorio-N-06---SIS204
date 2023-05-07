#pragma once
#include <iostream>
#include <string>
#include "Nodo_Asignatura.h"
#include "Nodo_Estudiante.h"
using namespace std;
class Lista_Estudiante
{
private:
	Nodo_Cabeza_Estudiante* nodo_cabeza;
	Nodo_Estudiante* nodo_inicial;
public:
	Lista_Estudiante(Nodo_Asignatura* _nodo_c) : nodo_inicial(nullptr), nodo_cabeza(_nodo_c->siguiente_e) {}
	Lista_Estudiante() : nodo_inicial(nullptr) {}
	void insertar_estudiante(Nodo_Asignatura* _nodo_c, int _posicion) {
		Nodo_Estudiante* nodo_nuevo = new Nodo_Estudiante(); int sexo_i;
		while (_posicion > nodo_cabeza->cantidad_estudiantes + 1 || _posicion < 0) {
			cout << "Inserte una posici�n v�lida: "; cin >> _posicion; cin.ignore();
			cout << "--------------------------------------------------------------------\n";
		}
		cout << "C�digo del estudiante: "; getline(cin, nodo_nuevo->estudiante.codigo);
		cout << "Nombre del estudiante: "; getline(cin, nodo_nuevo->estudiante.nombre);
		cout << "Direcci�n del estudiante: "; getline(cin, nodo_nuevo->estudiante.direccion);
		cout << "Edad del estudiante: "; cin >> nodo_nuevo->estudiante.edad; cin.ignore();
		while (nodo_nuevo->estudiante.edad > 125 || nodo_nuevo->estudiante.edad < 0) {
			cout << "Edad del estudiante correcta: "; cin >> nodo_nuevo->estudiante.edad; cin.ignore();
		}
		cout << "Sexo del estudiante: "; 
		do {
			cout << "1. Masculino.\n"; cout << "2. Femenino.\n"; cin >> sexo_i;
			nodo_nuevo->estudiante.sexo = (sexo_i == 1) ? "Masculino" : "Femenino";
		} while (sexo_i > 2 || sexo_i < 1);
		cout << "Nota del estudiante: "; cin >> nodo_nuevo->estudiante.nota;
		if (lista_vacia_e(_nodo_c)) {
			nodo_cabeza->siguiente = nodo_nuevo;
			nodo_nuevo->anterior = nodo_cabeza;
			nodo_nuevo->siguiente = nullptr;
			nodo_inicial = nodo_nuevo;
		} else {
			Nodo_Estudiante* nodo_actual = nodo_inicial;
			if (_posicion != 1) {
				for (int i = 1; i < _posicion - 1; i++) { nodo_actual = nodo_actual->siguiente; }
				nodo_nuevo->siguiente = nodo_actual->siguiente;
				if (nodo_actual->siguiente != nullptr) { nodo_actual->siguiente->anterior = nodo_nuevo; }
				nodo_nuevo->anterior = nodo_actual;
				nodo_actual->siguiente = nodo_nuevo;
			} else {
				nodo_nuevo->siguiente = nodo_actual->siguiente;
				if (nodo_nuevo->siguiente != nullptr) { nodo_actual->siguiente->anterior = nodo_nuevo; }
				nodo_nuevo->anterior = nodo_cabeza;
				nodo_inicial = nodo_nuevo;
			}
		}
		nodo_cabeza->cantidad_estudiantes++;
	}
	void eliminar_estudiante(Nodo_Asignatura* _nodo_c, string _codigo) {
		Nodo_Estudiante* nodo_eliminar = nodo_inicial; bool encontrar;
		while (nodo_eliminar->siguiente != nullptr) {
			nodo_eliminar = nodo_eliminar->siguiente;
			encontrar = (nodo_eliminar->estudiante.codigo == _codigo);
			if (encontrar) {
				nodo_eliminar->anterior->siguiente = nodo_eliminar->siguiente;
				nodo_eliminar->siguiente->anterior = nodo_eliminar->anterior;
				delete nodo_eliminar;
				cout << "Se ha eliminado correctamente la asignatura.\n";
				cout << "--------------------------------------------------------------------\n";
				_nodo_c->siguiente_e->cantidad_estudiantes--; return;
			}
		}
		cout << "No se ha encontrado la asignatura.\n";
		cout << "--------------------------------------------------------------------\n";
	}
	void mostrar_estudiantes(Nodo_Asignatura* _nodo_c) {
		Nodo_Estudiante* nodo_actual = nodo_inicial; int i = 1;
		cout << "Cantidad de estudiantes en esta asignatura: " << _nodo_c->siguiente_e->cantidad_estudiantes;
		cout << "--------------------------------------------------------------------\n";
		do {
			cout << "Estudiante N�" << i << ":\n"; i++;
			cout << "--------------------------------------------------------------------\n";
			cout << "C�digo del estudiante: " << nodo_actual->estudiante.codigo;
			cout << "Nombre del estudiante: " << nodo_actual->estudiante.nombre;
			cout << "Direcci�n del estudiante: " << nodo_actual->estudiante.direccion;
			cout << "Edad del estudiante: " << nodo_actual->estudiante.edad;
			cout << "Sexo del estudiante: " << nodo_actual->estudiante.sexo;
			cout << "Nota del estudiante: " << nodo_actual->estudiante.nota;
			nodo_actual = nodo_actual->siguiente;
			cout << "--------------------------------------------------------------------\n";
		} while (nodo_actual->siguiente != nullptr);
	}
	void mostar_estudiantes_masculinos(Nodo_Asignatura* _nodo_c) {
		Nodo_Estudiante* nodo_actual = nodo_inicial; int i = 1;
		cout << "Cantidad de estudiantes en esta asignatura: " << nodo_cabeza->cantidad_estudiantes;
		cout << "--------------------------------------------------------------------\n";
		do {
			if (nodo_actual->estudiante.sexo == "Masculino") {
				cout << "Estudiante N�" << i << ":\n";
				cout << "--------------------------------------------------------------------\n";
				cout << "C�digo del estudiante: " << nodo_actual->estudiante.codigo;
				cout << "Nombre del estudiante: " << nodo_actual->estudiante.nombre;
				cout << "Direcci�n del estudiante: " << nodo_actual->estudiante.direccion;
				cout << "Edad del estudiante: " << nodo_actual->estudiante.edad;
				cout << "Sexo del estudiante: " << nodo_actual->estudiante.sexo;
				cout << "Nota del estudiante: " << nodo_actual->estudiante.nota;
				cout << "--------------------------------------------------------------------\n";
			}
			nodo_actual = nodo_actual->siguiente;
		} while (nodo_actual != nullptr);
	}
	void mostar_estudiantes_femeninos(Nodo_Asignatura* _nodo_c) {
		Nodo_Estudiante* nodo_actual = nodo_inicial; int i = 1;
		cout << "Cantidad de estudiantes en esta asignatura: " << _nodo_c->siguiente_e->cantidad_estudiantes;
		cout << "--------------------------------------------------------------------\n";
		do {
			i++;
			if (nodo_actual->estudiante.sexo == "Femenino") {
				cout << "Estudiante N�" << i << ":\n";
				cout << "--------------------------------------------------------------------\n";
				cout << "C�digo del estudiante: " << nodo_actual->estudiante.codigo;
				cout << "Nombre del estudiante: " << nodo_actual->estudiante.nombre;
				cout << "Direcci�n del estudiante: " << nodo_actual->estudiante.direccion;
				cout << "Edad del estudiante: " << nodo_actual->estudiante.edad;
				cout << "Sexo del estudiante: " << nodo_actual->estudiante.sexo;
				cout << "Nota del estudiante: " << nodo_actual->estudiante.nota;
				cout << "--------------------------------------------------------------------\n";
			}
			nodo_actual = nodo_actual->siguiente;
		} while (nodo_actual != nullptr);
	}
	bool lista_vacia_e(Nodo_Asignatura* _nodo_c) { return (_nodo_c->siguiente_e->cantidad_estudiantes == 0); }
	int get_cantidad_estudiantes(Nodo_Asignatura* _nodo_c) { return (_nodo_c->siguiente_e->cantidad_estudiantes); }
	~Lista_Estudiante() {
		Nodo_Estudiante* nodo_eliminar = nodo_inicial;
		while (nodo_eliminar->siguiente != nullptr) {
			Nodo_Estudiante* nodo_siguiente = nodo_eliminar->siguiente;
			delete nodo_eliminar;
			nodo_eliminar = nodo_siguiente;
		}
		delete nodo_cabeza;
	}
};