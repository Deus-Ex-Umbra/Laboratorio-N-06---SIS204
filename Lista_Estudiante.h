#pragma once
#include <iostream>
#include <string>
#include "Lista_Asignatura.h"
#include "Nodo_Asignatura.h"
#include "Nodo_Estudiante.h"
using namespace std;
class Lista_Estudiante
{
private:
	Nodo_Estudiante* nodo_inicial = nullptr;
	Nodo_Estudiante* buscar_nodo_e(Nodo_Estudiante* nodo_c, int _posicion = -1, string _codigo = " ") {
		int indice_busqueda_e = 1;
		while ((nodo_c != nullptr) && (indice_busqueda_e != _posicion - 1) && (nodo_c->estudiante.codigo != _codigo)) { nodo_c = nodo_c->siguiente; indice_busqueda_e++; }
		return nodo_c;
	}
	bool nodo_encontrar_e(Nodo_Estudiante* nodo_c) { return (nodo_c != nullptr); }
public:
	Lista_Estudiante(Nodo_Asignatura* _nodo_c) { _nodo_c->siguiente_e = nodo_inicial; }
	Lista_Estudiante() {}
	void insertar_estudiante(Nodo_Asignatura* _nodo_c, int _posicion) {
		nodo_inicial = _nodo_c->siguiente_e;
		Nodo_Estudiante* nodo_nuevo = new Nodo_Estudiante();
		Nodo_Estudiante* nodo_actual = nodo_inicial;
		while (_posicion > _nodo_c->cantidad_estudiantes + 1 || _posicion < 0) {
			cout << "Inserte una posición válida: "; cin >> _posicion; cin.ignore();
			cout << "--------------------------------------------------------------------\n";
		}
		cout << "Código del estudiante: "; getline(cin, nodo_nuevo->estudiante.codigo);
		cout << "Nombre del estudiante: "; getline(cin, nodo_nuevo->estudiante.nombre);
		cout << "Dirección del estudiante: "; getline(cin, nodo_nuevo->estudiante.direccion);
		cout << "Edad del estudiante: "; 
		while (!(cin >> nodo_nuevo->estudiante.edad) || nodo_nuevo->estudiante.edad > 125 || nodo_nuevo->estudiante.edad < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Edad del estudiante incorrecta: ";
		} cin.ignore();
		cout << "Sexo del estudiante (masculino/femenino): "; getline(cin, nodo_nuevo->estudiante.sexo);
		while (nodo_nuevo->estudiante.sexo != "masculino" && nodo_nuevo->estudiante.sexo != "femenino") {
			cout << "Sexo del estudiante incorrecto (masculino/femenino): "; getline(cin, nodo_nuevo->estudiante.sexo);
		}
		cout << "Nota del estudiante: "; 
		while (!(cin >> nodo_nuevo->estudiante.nota) || nodo_nuevo->estudiante.nota > 100 || nodo_nuevo->estudiante.nota < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Nota del estudiante incorrecta: ";
		}
		nodo_nuevo->estudiante.estado = (nodo_nuevo->estudiante.nota < 51) ? "reprobado" : "aprobado";
		cout << "Estado del estudiante: " << nodo_nuevo->estudiante.estado << "\n";
		cout << "--------------------------------------------------------------------\n";
		if (lista_vacia_e(_nodo_c) || _posicion == 1) {
			nodo_nuevo->siguiente = (!lista_vacia_e(_nodo_c)) ? nodo_actual : nullptr;
			if (nodo_nuevo->siguiente != nullptr) { nodo_actual->anterior = nodo_nuevo; }
			nodo_nuevo->anterior = nullptr;
			nodo_inicial = nodo_nuevo;
			_nodo_c->siguiente_e = nodo_inicial;
		}
		else {
			nodo_actual = buscar_nodo_e(nodo_actual, _posicion);
			nodo_nuevo->siguiente = nodo_actual->siguiente;
			if (nodo_actual->siguiente != nullptr) { nodo_actual->siguiente->anterior = nodo_nuevo; }
			nodo_nuevo->anterior = nodo_actual;
			nodo_actual->siguiente = nodo_nuevo;
		}
		_nodo_c->cantidad_estudiantes++;
	}
	void eliminar_estudiante(Nodo_Asignatura* _nodo_c, string _codigo) {
		nodo_inicial = _nodo_c->siguiente_e;
		Nodo_Estudiante* nodo_eliminar = nodo_inicial;
		nodo_eliminar = buscar_nodo_e(nodo_eliminar, 0, _codigo);
		if (nodo_encontrar_e(nodo_eliminar)) {
			if (nodo_eliminar->anterior != nullptr) { nodo_eliminar->anterior->siguiente = nodo_eliminar->siguiente; }
			if (nodo_eliminar->siguiente != nullptr) { nodo_eliminar->siguiente->anterior = nodo_eliminar->anterior; }
			if (nodo_eliminar == nodo_inicial) { nodo_inicial = nodo_eliminar->siguiente; }
			delete nodo_eliminar;
			if (lista_vacia_e(_nodo_c)) { _nodo_c->siguiente_e = nullptr; nodo_inicial = nullptr; }
			cout << "Se ha eliminado correctamente la asignatura.\n";
			cout << "--------------------------------------------------------------------\n";
			_nodo_c->cantidad_estudiantes--;
		}
		cout << "No se ha encontrado la asignatura.\n";
		cout << "--------------------------------------------------------------------\n";
	}
	void mostrar_estudiantes(Nodo_Asignatura* _nodo_c) {
		nodo_inicial = _nodo_c->siguiente_e;
		Nodo_Estudiante* nodo_actual = nodo_inicial; int i = 1;
		cout << "--------------------------------------------------------------------\n";
		cout << "Cantidad de estudiantes en esta asignatura: " << _nodo_c->cantidad_estudiantes << "\n";
		cout << "--------------------------------------------------------------------\n";
		do {
			cout << "Estudiante N°" << i << ":\n"; i++;
			cout << "--------------------------------------------------------------------\n";
			cout << "Código del estudiante: " << nodo_actual->estudiante.codigo << "\n";
			cout << "Nombre del estudiante: " << nodo_actual->estudiante.nombre << "\n";
			cout << "Dirección del estudiante: " << nodo_actual->estudiante.direccion << "\n";
			cout << "Edad del estudiante: " << nodo_actual->estudiante.edad << "\n";
			cout << "Sexo del estudiante: " << nodo_actual->estudiante.sexo << "\n";
			cout << "Nota del estudiante: " << nodo_actual->estudiante.nota << "\n";
			cout << "Estado del estudiante: " << nodo_actual->estudiante.estado << "\n";
			nodo_actual = nodo_actual->siguiente;
			cout << "--------------------------------------------------------------------\n";
			cout << "--------------------------------------------------------------------\n";
		} while (nodo_actual != nullptr);
	}
	void mostar_estudiantes_masculinos(Nodo_Asignatura* _nodo_c) {
		nodo_inicial = _nodo_c->siguiente_e;
		Nodo_Estudiante* nodo_actual = nodo_inicial; int i = 1;
		cout << "--------------------------------------------------------------------\n";
		cout << "Cantidad de estudiantes en esta asignatura: " << _nodo_c->cantidad_estudiantes << "\n";
		cout << "--------------------------------------------------------------------\n";
		do {
			if (nodo_actual->estudiante.sexo == "masculino") {
				cout << "Estudiante N°" << i << ":\n"; i++;
				cout << "--------------------------------------------------------------------\n";
				cout << "Código del estudiante: " << nodo_actual->estudiante.codigo << "\n";
				cout << "Nombre del estudiante: " << nodo_actual->estudiante.nombre << "\n";
				cout << "Dirección del estudiante: " << nodo_actual->estudiante.direccion << "\n";
				cout << "Edad del estudiante: " << nodo_actual->estudiante.edad << "\n";
				cout << "Sexo del estudiante: " << nodo_actual->estudiante.sexo << "\n";
				cout << "Nota del estudiante: " << nodo_actual->estudiante.nota << "\n";
				cout << "Estado del estudiante: " << nodo_actual->estudiante.estado << "\n";
				cout << "--------------------------------------------------------------------\n";
			}
			nodo_actual = nodo_actual->siguiente;
		} while (nodo_actual != nullptr);
	}
	void mostar_estudiantes_femeninos(Nodo_Asignatura* _nodo_c) {
		nodo_inicial = _nodo_c->siguiente_e;
		Nodo_Estudiante* nodo_actual = nodo_inicial; int i = 1;
		cout << "--------------------------------------------------------------------\n";
		cout << "Cantidad de estudiantes en esta asignatura: " << _nodo_c->cantidad_estudiantes << "\n";
		cout << "--------------------------------------------------------------------\n";
		do {
			if (nodo_actual->estudiante.sexo == "femenino") {
				cout << "Estudiante N°" << i << ":\n"; i++;
				cout << "--------------------------------------------------------------------\n";
				cout << "Código del estudiante: " << nodo_actual->estudiante.codigo << "\n";
				cout << "Nombre del estudiante: " << nodo_actual->estudiante.nombre << "\n";
				cout << "Dirección del estudiante: " << nodo_actual->estudiante.direccion << "\n";
				cout << "Edad del estudiante: " << nodo_actual->estudiante.edad << "\n";
				cout << "Sexo del estudiante: " << nodo_actual->estudiante.sexo << "\n";
				cout << "Nota del estudiante: " << nodo_actual->estudiante.nota << "\n";
				cout << "Estado del estudiante: " << nodo_actual->estudiante.estado << "\n";
				cout << "--------------------------------------------------------------------\n";
			}
			nodo_actual = nodo_actual->siguiente;
		} while (nodo_actual != nullptr);
	}
	bool lista_vacia_e(Nodo_Asignatura* _nodo_c) { return (_nodo_c->cantidad_estudiantes == 0); }
	int get_cantidad_estudiantes(Nodo_Asignatura* _nodo_c) { return (_nodo_c->cantidad_estudiantes); }
	void eliminar_todo(Nodo_Asignatura* _nodo_c) {
		nodo_inicial = _nodo_c->siguiente_e;
		Nodo_Estudiante* nodo_eliminar = nodo_inicial;
		while (nodo_eliminar != nullptr) {
			Nodo_Estudiante* nodo_siguiente = nodo_eliminar->siguiente;
			delete nodo_eliminar;
			nodo_eliminar = nodo_siguiente;
		}
	}
};