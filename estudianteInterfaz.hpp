/*! 	
	\file    estudianteInterfaz.hpp
	\brief   Declaración del TAD estudianteInterfaz
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/

#ifndef _ESTUDIANTEINTERFAZ_HPP_
#define _ESTUDIANTEINTERFAZ_HPP_

#include <string>


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{


/*!
	\class EstudianteInterfaz
	\brief Indica los métodos virtuales puros de interfaz que serán redefinidos en las clase heredera
*/
class EstudianteInterfaz{

/*!	
	\name Funciones o métodos públicos de la clase EstudianteInterfaz
*/
	public:

/*!		
	\brief Destructor  
	\note  Función virtual
	\sa    setNombre, setApellidos, setTeoria, setPractica
*/
	virtual ~EstudianteInterfaz(){
	
	}

/*!
	\name Observadores
*/

/*!	
	\brief   Método público que permite conocer el nombre del estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\return  Devuelve el nombre del estudiante
*/
	virtual const std::string &getNombre() const = 0;

		
/*!	
	\brief   Método público que permite conocer los apellidos del estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\return  Devuelve los apellidos del estudiante
*/
	virtual const std::string &getApellidos() const = 0;

		
/*!	
	\brief   Método público que permite conocer la nota de teoría del estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\return  Devuelve la nota de teoría del estudiante
*/
	virtual float getTeoria() const = 0;

		
/*!	
	\brief   Método público que permite conocer la nota de prácticas del estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\return  Devuelve la nota de prácticas del estudiante
*/
	virtual float getPractica() const = 0;


/*!
	\name Modificadores
*/
		
/*!	
	\brief   Método público que permite modificar el nombre del estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\param   nombre: nuevo nombre del estudiante
	\post    El nombre del estudiante es igual al parámetro pasado como argumento
	\return  void
	\sa      getNombre
*/
	virtual void setNombre(const std::string & nombre) = 0;

		
/*!	
	\brief   Método público que permite modificar los apellidos del estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\param   apellidos: nuevos apellidos del estudiante
	\post    Los apellidos del estudiante son iguales al parámetro pasado como argumento
	\return  void
	\sa      getApellidos
*/
	virtual void setApellidos(const std::string & apellidos) = 0;

		
/*!	
	\brief   Método público que permite modificar la nota de teoría del estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\param   teoria: nueva nota de teoría del estudiante
	\post    La nota de teoría del estudiante es igual al parámetro pasado como argumento
	\return  void
	\sa      getTeoria
*/
	virtual void setTeoria(const float & teoria) = 0;

		
/*!	
	\brief   Método público que permite modificar la nota de prácticas del estudiante
	\warning Función virtual pura: se debe redefinir en la clase heredera
	\param   practica: nueva nota de prácticas del estudiante
	\post    La nota de prácticas del estudiante es igual al parámetro pasado como argumento
	\return  void
	\sa      getPractica
*/
	virtual void setPractica(const float & practica) = 0;
		
//Fin de la clase EstudianteInterfaz
};

//Fin del espacio de nombres ed
}

//Fin  _ESTUDIANTEINTERFAZ_HPP_
#endif  
