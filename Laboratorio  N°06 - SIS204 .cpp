//Laboratorio N°06 - SIS204
#include <iostream>
#include "Lista_Asignatura.h"
using namespace std;
int main(int argv, char** argc) {
	Lista_Asignatura lista_asignatura;
	string codigo_a;
	enum opciones { INSERTAR = 1, ELIMINAR = 2, MOSTRAR_A = 3, MOSTRAR_C_A = 4, INGRESAR_A = 5, MOSTRAR_C_E = 6, MOSTRAR_A_E = 7 };
	int opcion, posicion;
	do {
		system("cls");
		cout << "--------------------------------------------------------------------\n"; //ASCII: 218, 196, 191, 179, 192, 217, 195, 180, 194, 193, 197,
		cout << "****Lista de Asignaturas****\n";
		cout << "--------------------------------------------------------------------\n";
		cout << "1. Insertar una asignatura.\n";
		cout << "2. Eliminar una asignatura.\n";
		cout << "3. Mostrar todas las asignaturas.\n";
		cout << "4. Mostrar cantidad de asignaturas.\n";
		cout << "5. Ingresar a una asignatura.\n";
		cout << "6. Mostrar cantidad de estudiantes en una asignatura.\n";
		cout << "7. Mostrar todas las asignaturas y sus estudiantes respectivos.\n";
		cout << "8. Salir.\n";
		cout << "--------------------------------------------------------------------\n";
		cout << "Seleccione una opción: ";
		while (!(cin >> opcion) || (opcion < 1 || opcion > 8)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "--------------------------------------------------------------------\n";
			cout << "Seleccione una opción válida: ";
		}
		if (lista_asignatura.lista_vacia() && (opcion > 1) && (opcion < 8)) { cout << "Error: Lista Vacía.\n"; opcion = 1; }
		cout << "--------------------------------------------------------------------\n";
		cin.ignore();
		opciones opcion_i = static_cast<opciones>(opcion);
		switch (opcion_i) {
		case INSERTAR:
			cout << "***Se insertará una asignatura***\n";
			cout << "--------------------------------------------------------------------\n";
			cout << "Escriba la posición donde se insertará la asignatura: ";
			while (!(cin >> posicion)) {
				cout << "--------------------------------------------------------------------\n";
				cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Escriba la posición donde se insertará la asignatura: ";
			} cin.ignore();
			cout << "--------------------------------------------------------------------\n";
			lista_asignatura.insertar_asignatura(posicion);
			break;
		case ELIMINAR:
			cout << "***Se eliminará una asignatura***\n";
			cout << "--------------------------------------------------------------------\n";
			cout << "Escriba el código de la asignatura que se eliminará: "; getline(cin, codigo_a);
			cout << "--------------------------------------------------------------------\n";
			lista_asignatura.eliminar_asignatura(codigo_a);
			break;
		case MOSTRAR_A:
			cout << "***Se mostrarán todas las asignaturas***\n";
			cout << "--------------------------------------------------------------------\n";
			lista_asignatura.mostrar_asignaturas();
			break;
		case MOSTRAR_C_A:
			cout << "***Se mostrará la cantidad de asignaturas***\n";
			cout << "--------------------------------------------------------------------\n";
			lista_asignatura.get_cantidad_asignaturas();
			break;
		case INGRESAR_A:
			cout << "***Se ingresará a la lista de estudiantes de una asignatura***\n";
			cout << "--------------------------------------------------------------------\n";
			cout << "Escriba el código de la asignatura a la que se ingresará: "; getline(cin, codigo_a);
			cout << "--------------------------------------------------------------------\n";
			lista_asignatura.ingresar_lista_estudiantes(codigo_a);
		break;
			case MOSTRAR_C_E:
			cout << "***Se mostrará la cantidad de estudiantes de una asignatura***\n";
			cout << "--------------------------------------------------------------------\n";
			cout << "Escriba el código de la asignatura que desea revisar: "; getline(cin, codigo_a);
			cout << "--------------------------------------------------------------------\n";
			lista_asignatura.get_cantidad_estudiantes(codigo_a);
			break;
		case MOSTRAR_A_E:
			cout << "***Se mostrarán las asignaturas y sus respectivos estudiantes***\n";
			cout << "--------------------------------------------------------------------\n";
			lista_asignatura.mostrar_todo();
			break;
		default:
			cout << "Gracias por usar el programa.\n";
			cout << "--------------------------------------------------------------------\n"; system("pause"); return false;
			break;
		}
		system("pause");
	} while (true);
	return 0;
}