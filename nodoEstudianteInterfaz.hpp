/*! 
	\file    nodoEstudianteInterfaz.hpp
	\brief   Declaración de la clase NodoEstudianteInterfaz
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/

#ifndef _NODOESTUDIANTEINTERFAZ_HPP_
#define _NODOESTUDIANTEINTERFAZ_HPP_

#include "estudiante.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{

/*!
	\class NodoEstudianteInterfaz
	\brief Indica los métodos virtuales puros deberán ser redefinidos en las clases herederas
*/
class NodoEstudianteInterfaz{

/*!	
	\name Funciones o métodos públicos de la clase Nodo
*/
	public:


/*!
	\brief     Destructor de la clase 
	\warning   Función virtual pura: se debe redefinir en la clase heredera
	\attention Es necesario especificar esta función para liberar memoria en la clase heredera
	\post      El árbol está vacío
*/
	virtual ~NodoEstudianteInterfaz(){
	
	}

/*!
	\name Observadores
*/

/*!	
	\brief   Método público que permite conocer el campo informativo del nodo: un estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\pre     El árbol no está vacío
	\return  Devuelve el valor del campo informativo del nodo, es decir, una referencia a un Estudiante
*/
	virtual const ed::Estudiante & getItem() const = 0;

/*!	
	\brief   Método público que permite modificar el campo informativo del nodo: un estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\post    El valor del campo informativo debe ser igual al item pasado como argumento
	\return  void
	\sa      getItem
*/
	virtual void setItem(ed::Estudiante const &item) = 0;

// Fin de la clase NodoDoble
}; 

// Fin del espacio de nombres ed
}

//Fin  _NODOESTUDIANTEINTERFAZ_HPP_
#endif  
