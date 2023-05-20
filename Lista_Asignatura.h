#pragma once
#include <iostream>
#include <string>
#include "Nodo_Cabeza_Asignatura.h"
#include "Nodo_Asignatura.h"
#include "Lista_Estudiante.h"
using namespace std;
class Lista_Asignatura
{
private:
	Lista_Estudiante lista_estudiante;
	Nodo_Cabeza_Asignatura* nodo_cabeza;
	Nodo_Asignatura* nodo_inicial;
	Nodo_Asignatura* buscar_nodo(Nodo_Asignatura* nodo_c, int _posicion = 0, string _codigo = " ") {
		int indice_busqueda = 1;
		while ((nodo_c != nullptr) && (nodo_c->asignatura.codigo != _codigo) && (indice_busqueda != _posicion - 1)) { nodo_c = nodo_c->siguiente; indice_busqueda++; }
		return nodo_c;
	}
	bool nodo_encontrar(Nodo_Asignatura* nodo_c) { return (nodo_c != nullptr); }
public:
	Lista_Asignatura() : nodo_cabeza(new Nodo_Cabeza_Asignatura), nodo_inicial(new Nodo_Asignatura) {}
	void insertar_asignatura(int _posicion) {
		Nodo_Asignatura* nodo_nuevo = new Nodo_Asignatura();
		Nodo_Asignatura* nodo_actual = nodo_inicial;
		while (_posicion > nodo_cabeza->cantidad_asignaturas + 1 || _posicion < 0) { 
			cout << "Inserte una posición válida: "; cin >> _posicion; cin.ignore(); 
			cout << "--------------------------------------------------------------------\n";
		}
		cout << "Código: "; getline(cin, nodo_nuevo->asignatura.codigo); 
		cout << "Nombre de la Asignatura: "; getline(cin, nodo_nuevo->asignatura.nombre);
		cout << "Descripción: "; getline(cin, nodo_nuevo->asignatura.descripcion); 
		cout << "Cantidad de horas: "; 
		while (!(cin >> nodo_nuevo->asignatura.cantidad_de_horas) || (nodo_nuevo->asignatura.cantidad_de_horas > 24 || nodo_nuevo->asignatura.cantidad_de_horas < 1)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Cantidad de horas incorrecta: ";
		}
		if (lista_vacia() || _posicion == 1) {
			nodo_nuevo->siguiente_e = nullptr;
			nodo_nuevo->siguiente = (!lista_vacia()) ? nodo_actual : nullptr;
			if (nodo_nuevo->siguiente != nullptr) { nodo_actual->anterior = nodo_nuevo; }
			nodo_nuevo->anterior = nullptr;
			nodo_inicial = nodo_nuevo;
			nodo_cabeza->siguiente_a = nodo_nuevo;
		} else {
			nodo_actual = buscar_nodo(nodo_actual, _posicion);
			nodo_nuevo->siguiente_e = nullptr;
			nodo_nuevo->siguiente = nodo_actual->siguiente;
			if (nodo_actual->siguiente != nullptr) { nodo_actual->siguiente->anterior = nodo_nuevo; }
			nodo_nuevo->anterior = nodo_actual;
			nodo_actual->siguiente = nodo_nuevo;
		}
		cout << "--------------------------------------------------------------------\n";
		nodo_cabeza->cantidad_asignaturas++;
	}
	void eliminar_asignatura(string _codigo) {
		Nodo_Asignatura* nodo_eliminar = nodo_inicial;
		nodo_eliminar = buscar_nodo(nodo_eliminar, 0, _codigo);
		if (nodo_encontrar(nodo_eliminar)) {
			lista_estudiante.eliminar_todo(nodo_eliminar);
			if (nodo_eliminar->anterior != nullptr) { nodo_eliminar->anterior->siguiente = nodo_eliminar->siguiente; }
			if (nodo_eliminar->siguiente != nullptr) { nodo_eliminar->siguiente->anterior = nodo_eliminar->anterior; }
			if (nodo_eliminar == nodo_inicial) { nodo_inicial = nodo_eliminar->siguiente; }
			delete nodo_eliminar;
			if (lista_vacia()) { nodo_cabeza->siguiente_a = nullptr; nodo_inicial = nullptr; }
			cout << "Se ha eliminado correctamente la asignatura.\n";
			cout << "--------------------------------------------------------------------\n";
			nodo_cabeza->cantidad_asignaturas--; 
			return;
		}
		cout << "No se ha encontrado la asignatura.\n";
		cout << "--------------------------------------------------------------------\n";
	}
	void mostrar_asignaturas() {
		Nodo_Asignatura* nodo_actual = nodo_inicial;
		int i = 1;
		cout << "Cantidad total de asignaturas: " << nodo_cabeza->cantidad_asignaturas << "\n";
		cout << "--------------------------------------------------------------------\n";
		do {
			cout << "Asignatura N°" << i << ":\n";
			cout << "Código: " << nodo_actual->asignatura.codigo << "\n";
			cout << "Nombre: " << nodo_actual->asignatura.nombre << "\n";
			cout << "Descripción: " << nodo_actual->asignatura.descripcion << "\n";
			cout << "Cantidad de horas: " << nodo_actual->asignatura.cantidad_de_horas << "\n";
			nodo_actual = nodo_actual->siguiente; i++;
			cout << "--------------------------------------------------------------------\n";
		} while (nodo_actual != nullptr);
	}
	void get_cantidad_asignaturas() { cout << "La cantidad de asignaturas es: " << nodo_cabeza->cantidad_asignaturas << "\n"; cout << "--------------------------------------------------------------------\n"; }
	bool lista_vacia() {   return (nodo_cabeza->cantidad_asignaturas == 0); }
	void ingresar_lista_estudiantes(string _codigo) {
		Nodo_Asignatura* nodo_buscar = nodo_inicial;
		nodo_buscar = buscar_nodo(nodo_buscar, 0, _codigo);
		if (nodo_encontrar(nodo_buscar)) {
			enum opciones_e { INSERTAR = 1, ELIMINAR = 2, MOSTRAR_E = 3, MOSTRAR_E_M = 4, MOSTRAR_E_F = 5 };
			int opcion_e, posicion_e;
			string codigo_e;
			if (nodo_buscar->siguiente_e == nullptr) {
				Lista_Estudiante lista_estudiante_aux(nodo_buscar);
				lista_estudiante = lista_estudiante_aux; 
			} 
			do {
				system("cls");
				cout << "--------------------------------------------------------------------\n"; //ASCII: 218, 196, 191, 179, 192, 217, 195, 180, 194, 193, 197,
				cout << "****Lista de Estudiantes****\n";
				cout << "--------------------------------------------------------------------\n";
				cout << "1. Insertar un estudiante.\n";
				cout << "2. Eliminar un estudiante.\n";
				cout << "3. Mostrar todos los estudiantes.\n";
				cout << "4. Mostrar cantidad de estudiantes masculinos.\n";
				cout << "5. Mostrar cantidad de estudiantes femeninos.\n";
				cout << "6. Salir.\n";
				cout << "--------------------------------------------------------------------\n";
				cout << "Seleccione una opción: ";
				while (!(cin >> opcion_e) || (opcion_e < 1 || opcion_e > 6)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "--------------------------------------------------------------------\n";
					cout << "Seleccione una opción válida: ";
				}
				if (lista_estudiante.lista_vacia_e(nodo_buscar) && (opcion_e > 1) && (opcion_e < 6)) { cout << "Error: Lista Vacía.\n"; opcion_e = 1; }
				cin.ignore();
				opciones_e opcion_i = static_cast<opciones_e>(opcion_e);
				switch (opcion_i) {
				case INSERTAR:
					cout << "***Se insertará un estudiante***\n";
					cout << "--------------------------------------------------------------------\n";
					cout << "Escriba la posición donde se insertará el estudiante: ";
					while (!(cin >> posicion_e)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "--------------------------------------------------------------------\n";
						cout << "Escriba la posición donde se insertará el estudiante: ";
					} cin.ignore();
					cout << "--------------------------------------------------------------------\n";
					lista_estudiante.insertar_estudiante(nodo_buscar, posicion_e); system("pause");
					break;
				case ELIMINAR:
					cout << "***Se eliminará un estudiante***\n";
					cout << "--------------------------------------------------------------------\n";
					cout << "Escriba el código del estudiante que se eliminará: "; getline(cin, codigo_e); cin.ignore();
					cout << "--------------------------------------------------------------------\n";
					lista_estudiante.eliminar_estudiante(nodo_buscar, codigo_e); system("pause");
					break;
				case MOSTRAR_E:
					cout << "***Se mostrarán todos los estudiantes***\n";
					cout << "--------------------------------------------------------------------\n";
					lista_estudiante.mostrar_estudiantes(nodo_buscar); system("pause");
					break;
				case MOSTRAR_E_M:
					cout << "***Se mostrarán los estudiantes masculinos***\n";
					cout << "--------------------------------------------------------------------\n";
					lista_estudiante.mostar_estudiantes_masculinos(nodo_buscar); system("pause");
					break;
				case MOSTRAR_E_F:
					cout << "***Se mostrarán los estudiantes femeninos***\n";
					cout << "--------------------------------------------------------------------\n";
					lista_estudiante.mostar_estudiantes_femeninos(nodo_buscar); system("pause");
					break;
				default:
					cout << "Será retornado a la lista de asignaturas.\n"; 
					cout << "--------------------------------------------------------------------\n"; return;
					break;
				}
			} while (true);
		} else { 
			cout << "Error: No se encontró la asignatura con el código: " << _codigo << ".\n"; 
			cout << "--------------------------------------------------------------------\n";
		}
	}
	void get_cantidad_estudiantes(string _codigo) {
		Nodo_Asignatura* nodo_buscar = nodo_inicial;
		nodo_buscar = buscar_nodo(nodo_buscar, 0, _codigo);
		if (nodo_encontrar(nodo_buscar)) {
			cout << "La cantidad de estudianes es: " << lista_estudiante.get_cantidad_estudiantes(nodo_buscar) << "\n";
			cout << "--------------------------------------------------------------------\n";
		} else {
			cout << "Error: No se encontró la asignatura con el código: " << _codigo << ".\n";
			cout << "--------------------------------------------------------------------\n";
		}
	}
	void mostrar_todo() {
		Nodo_Asignatura* nodo_actual = nodo_inicial; int i = 1;
		do {
			cout << "Asignatura N°" << i << ":\n";
			cout << "Código: " << nodo_actual->asignatura.codigo << "\n";
			cout << "Nombre: " << nodo_actual->asignatura.nombre << "\n";
			cout << "Descripción: " << nodo_actual->asignatura.descripcion << "\n";
			cout << "Cantidad de horas: " << nodo_actual->asignatura.cantidad_de_horas << "\n";
			cout << "--------------------------------------------------------------------\n";
			if (!lista_estudiante.lista_vacia_e(nodo_actual)) { lista_estudiante.mostrar_estudiantes(nodo_actual); }
			nodo_actual = nodo_actual->siguiente; i++;
		} while (nodo_actual != nullptr);
	}
};