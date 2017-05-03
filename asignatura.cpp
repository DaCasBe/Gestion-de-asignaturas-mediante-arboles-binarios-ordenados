/*!	
	\file    asignatura.cpp
	\brief   Definición de la clase Asignatura
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/

//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>

// Para usar atof
#include <stdlib.h>

#include "asignatura.hpp"

bool ed::Asignatura::cargarFichero(std::string const &nombreFichero){
	std::ifstream fichero;
	ed::Estudiante estudiante;
	char nombre[30];
	char codigo[5];

	fichero.open(nombreFichero.c_str()); //Abrimos el fichero con el nombre recibido

	if(!fichero){ //No se ha podido abrir el fichero
		return false;
	}

	else{ //Se ha podido abrir el fichero
		//Leemos del fichero el nombre y el código de la asignatura
		fichero.getline(nombre,30,'\n');
		setNombre(nombre);
		fichero.getline(codigo,5,'\n');
		setCodigo(atoi(codigo));

		while(fichero >> estudiante){ //Leemos del fichero los datos de un estudiante
			if(!insertarEstudiante(estudiante)){ //Insertamos el estudiante
				std::cout << "No ha podido insertarse un estudiante" << std::endl;

				return false;
			}
		}

		fichero.close(); //Cerramos el fichero

		return true;
	}
}

bool ed::Asignatura::grabarFichero(std::string const &nombreFichero){
	std::ofstream fichero;

	fichero.open(nombreFichero.c_str()); //Abrimos el fichero con el nombre recibido

	if(!fichero){ //No se ha podido abrir el fichero
		return false;
	}

	else{ //Se ha podido abrir el fichero
		//Escribimos en el fichero el nombre y el código de la asignatura
		fichero << getNombre() << std::endl;
		fichero << getCodigo() << std::endl;

		_arbol.grabar(fichero); //Escribimos el en fichero la lista de estudiantes

		fichero.close(); //Cerramos el fichero

		return true;
	}
}
