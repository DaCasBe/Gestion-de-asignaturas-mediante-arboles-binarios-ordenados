/*!
	\file    principalAsignatura.cpp
	\brief   Programa principal de la practica e de ED, Asignatura de estudiantes
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/

/*!
	\mainpage Implementación de una asignatura utilizando un árbol doblemente enlazado y ordenado de estudiantes
	\author   Daniel Castillo Bello
	\date     27-04-2017
	\version  1.0
*/

#include <iostream>
#include <stdio.h>

#include <string>

#include "asignatura.hpp"
#include "estudiante.hpp"

#include "funcionesAuxiliares.hpp"
#include "macros.hpp"


int main(){
	ed::Asignatura asignatura;
	int opcion;

	do{
		//Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		LUGAR(5,1);

		//Se ejecuta la opción del menú elegida
		switch(opcion){
			case 0: 
				std::cout << INVERSE;
				std::cout << "Fin del programa" << std::endl;
				std::cout << RESET;

				break;

			case 1: 
				std::cout << "[1] Comprobar si la asignatura está vacía" << std::endl;
				ed::comprobarAsignaturaVacia(asignatura);

				break;

			case 2: 
				std::cout << "[2] Cargar la asignatura de un fichero" << std::endl;
				ed::cargarAsignatura(asignatura);

				break;

			case 3: 
				std::cout << "[3] Grabar la asignatura en un fichero" << std::endl;
				ed::grabarAsignatura(asignatura);

				break;

			case 4: 
				std::cout << "[4] Consultar datos de la asignatura: " << std::endl; 
				ed::consultarAsignatura(asignatura);

				break;

			case 5: 
				std::cout << "[5] Modificar datos de la asignatura: código o nombre" << std::endl;
				ed::modificarAsignatura(asignatura);

				break;

			case 6: 
				std::cout << "[6] Borrar una asignatura" << std::endl;
				ed::borrarAsignatura(asignatura);

				break;


			case 7: 
				std::cout << "[7] Consultar un estudiante" << std::endl;
				consultarEstudianteDeAsignatura(asignatura);

				break;

			case 8: 
				std::cout << "[8] Insertar un estudiante" << std::endl;
				insertarEstudianteEnAsignatura(asignatura);

				break;

			case 9: 
				std::cout << "[9] Modificar un estudiante" << std::endl;
				modificarEstudianteDeAsignatura(asignatura);

				break;

			case 10: 
				std::cout << "[10] Borrar un estudiante" << std::endl;
				borrarEstudianteDeAsignatura(asignatura);

				break;

			default:
				LUGAR(25,25);
				std::cout << INVERSE;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
			  	std::cout << RED;
				std::cout << " --> " << opcion << std::endl;
				std::cout << RESET;
		}
  
		if (opcion !=0){
			LUGAR(30,25);
			std::cout << "pulse ";
			std::cout << UNDERLINE;
			std::cout << IYELLOW;
			std::cout << "ENTER";
			std::cout << RESET;
			std::cout << " para ";
			std::cout << INVERSE;
			std::cout << "continuar"; 
			std::cout << RESET;
			getchar();
			std::cout << CLEAR_SCREEN;
		}
	}while(opcion!=0);

	return 0;
}
