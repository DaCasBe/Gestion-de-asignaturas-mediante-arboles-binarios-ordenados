/*!	
	\file    estudiante.cpp
	\brief   Código auxiliar de las funciones de la clase Estudiante
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/


#include <iostream>
#include <stdio.h>

//Eliminar el comentario si se desea usar atof en la sobrecarga del operador >>
//#include <stdlib.h>

#include "estudiante.hpp"
#include "macros.hpp"

//Se han utilizado los calificadores ed:: y std:: en vez de las sentencias siguientes
//using namespace ed;
//using namespace std;

/*
	Definiciones de las funciones lectura y escritura de la clase Estudiante
*/

void ed::Estudiante::leerEstudiante(){
	std::cout << IYELLOW << "Introduce el nombre: " << RESET;
	//Uso de getline para leer nombres compuestos separados por espacios
	std::getline(std::cin,this->_nombre);

	//Esta sentencia no permite leer nombres compuestos con espacios en blanco
	//std::cin >> this->_nombre;

	std::cout << IYELLOW << "Introduce los apellidos: " << RESET;
	//Uso de getline para leer los apellidos separados por espacios
	std::getline(std::cin,this->_apellidos);

	//Esta sentencia no permite leer dos apellidos separados por espacios en blanco
	//std::cin >> this->_apellidos;

	std::cout << IYELLOW << "Introduce la nota de teoría: " << RESET;
	std::cin >> this->_teoria;

	std::cout << IYELLOW << "Introduce la nota de práctica: " << RESET;
	std::cin >> this->_practica;

	//Se elimina el salto de línea para evitar problemas en una posterior lectura de cadenas 
	std::cin.ignore();
}


void ed::Estudiante::escribirEstudiante()const{
	std::cout << BBLUE << "Nombre: " << BLUE << this->getNombre() << RESET << std::endl;

	std::cout << BBLUE << "Apellidos: " << BLUE << this->getApellidos() << RESET << std::endl;

	std::cout << BBLUE << "Nota de teoría: " << BLUE << this->getTeoria() << RESET << std::endl;

	std::cout << BBLUE << "Nota de prácticas: " << BLUE << this->getPractica() << RESET << std::endl;

	std::cout << BBLUE << "Nota final: " << BLUE << this->getFinal() << RESET << std::endl;
}

ed::Estudiante &ed::Estudiante::operator=(const ed::Estudiante &e){
	//Se comprueba que no sean el mismo objeto
	if (this != &e){
		this->setNombre(e.getNombre());
		this->setApellidos(e.getApellidos());

		this->setTeoria(e.getTeoria());
		this->setPractica(e.getPractica());
	}

	//Postcondición
	#ifndef NDEBUG
		assert((*this)==e);
	#endif
	
	//Se devuelve el objeto actual
	return *this;
}


bool ed::Estudiante::operator==(const ed::Estudiante & e) const{
	return ((this->getNombre() == e.getNombre()) and (this->getApellidos() == e.getApellidos()));
}


bool ed::Estudiante::operator <(const ed::Estudiante & e) const{
	if (this->getApellidos() < e.getApellidos()){
		return true;
	}

	else if ((this->getApellidos() == e.getApellidos()) and (this->getNombre() < e.getNombre())){
		return true;
	}

	else{
		return false;
	}
}

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{

std::istream &operator>>(std::istream &i, ed::Estudiante &e){
	std::getline(i,e._nombre);

	std::getline(i,e._apellidos);

	i >> e._teoria;
	//Se elimina el salto de línea del flujo de entrada para evitar problemas con la posterior lectura de cadenas
	i.ignore();

	i >> e._practica;
	//Se elimina el salto de línea del flujo de entrada para evitar problemas con la posterior lectura de cadenas
	i.ignore();

	/*Forma alternativa para la lectura de datos numéricos usando una variable auxiliar: cadena
	std::string cadena;

	std::getline(i,cadena);
	e._teoria = atof(cadena.c_str());

	std::getline(i,cadena);
	e._practica = atof(cadena.c_str());*/

	//Se devuelve el flujo de entrada
	return i;
}


std::ostream &operator<<(std::ostream &o, ed::Estudiante const &e){
	o << e._nombre << std::endl;
	o << e._apellidos << std::endl;

	o << e._teoria << std::endl;
	o << e._practica << std::endl;

	//Se devuelve el flujo de salida
	return o;
}

} //Fin del espacio de nombres ed
