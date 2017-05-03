/*!
	\file   funcionesAuxiliares.hpp
	\brief  Prototipos de las funciones auxiliares del programa principal de la asignatura
	\author Daniel Castillo Bello
	\date   27-04-2017
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "asignatura.hpp" 

namespace ed{
/*!		
	\brief   Menú para acceder a las diferentes funciones
	\return  Entero que indica la opción seleccionada
*/
	int menu();

/*!		
	\brief   Comprueba si la asignatura esta vacía
	\param   asignatura: asignatura de la que se quiere comprobar si esta vacía o no
	\return  void
*/
	void comprobarAsignaturaVacia(ed::Asignatura const &asignatura);

/*!		
	\brief   Carga una asignatura desde un fichero de texto
	\param   asignatura: dato de tipo asignatura en el que se carga la información
	\return  void
	\sa      borrarAsignatura
*/
	void cargarAsignatura(ed::Asignatura &asignatura);

/*!		
	\brief   Graba una asignatura en un fichero de texto
	\param   asignatura: dato de tipo asignatura que contiene la información a grabar
	\return  void
*/
	void grabarAsignatura(ed::Asignatura  &asignatura);

/*!		
	\brief   Muestra los datos de una asignatura por la pantalla
	\param   asignatura: dato de tipo asignatura que contiene la información a mostrar
	\return  void
*/
	void consultarAsignatura(ed::Asignatura &asignatura);
	
/*!		
	\brief   Permite al usuario modificar los datos de una asignatura
	\param   asignatura: dato de tipo asignatura que contiene la información a modificar
	\return  void
*/
	void modificarAsignatura(ed::Asignatura &asignatura);

/*!		
	\brief   Borra una asignatura
	\param   asignatura: dato de tipo asignatura que se pretende borrar
	\return  void
*/
	void borrarAsignatura(ed::Asignatura &asignatura);

/*!		
	\brief   Consulta la información de un estudiante especificado por el usuario
	\param   asignatura: dato de tipo asignatura en el que se encuentra el estudiante
	\return  void
*/
	void consultarEstudianteDeAsignatura(ed::Asignatura &asignatura);

/*!		
	\brief   Inserta un estudiante en una asignatura
	\param   asignatura: dato de tipo asignatura en el que se pretende insertar el estudiante
	\return  void
*/
	void insertarEstudianteEnAsignatura(ed::Asignatura &asignatura);

/*!		
	\brief   Modifica la información de un estudiante especificado por el usuario
	\param   asignatura: dato de tipo asignatura en el que se encuentra el estudiante
	\return  void
*/
	void modificarEstudianteDeAsignatura(ed::Asignatura &asignatura);

/*!		
	\brief   Borra un estudiante especificado por el usuario de una asignatura
	\param   asignatura: dato de tipo asignatura en el que se encuentra el estudiante 
	\return  void
*/
	void borrarEstudianteDeAsignatura(ed::Asignatura &asignatura);
}

//Fin de _FUNCIONESAUXILIARES_HPP_
#endif
