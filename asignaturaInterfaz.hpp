/*!
	\file    asignaturaInterfaz.hpp
	\brief   Definición de la clase abstracta AsignaturaInterfaz
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/

#ifndef __ASIGNATURAINTERFAZ_HPP__
#define __ASIGNATURAINTERFAZ_HPP__

#include <string>

#include "estudiante.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{

/*!
	\class AsignaturaInterfaz
	\brief Especificaciones de la clase virtual pura AsignaturaInterfaz
*/
class AsignaturaInterfaz{

/*!		
	\name \name Métodos públicos de la clase AsignaturaInterfaz
*/

/*!	
	\name Observadores
*/

/*!		
	\brief  Devuelve el código de la asignatura
	\note   Función virtual pura
	\return Número entero que representa el código numérico de la asignatura
*/
	virtual  int getCodigo() const = 0;

/*!		
	\brief  Devuelve el nombre de la asignatura
	\note   Función virtual pura
	\return Cadena que representa el nombre de la asignatura
*/
	virtual std::string getNombre() const = 0;

/*!		
	\brief  Indica si la asignatura tiene o no estudiantes
	\note   Función virtual pura
	\return Verdadero si tiene uno o más estudiantes; falso, en caso contrario
*/
	virtual bool estaVacia()  const = 0;

/*!		
	\brief  Devuelve el número de estudiantes
	\note   Función virtual pura
	\return Número entero que representa el número de estudiantes de la asignatura
*/
	virtual int getNumeroEstudiantes() const = 0;

/*!		
	\brief   Comprueba si existe un estudiante con un nombre y unos apellidos 
	\note    Función virtual pura
	\warning Función sobrecargada
	\param   nombre del estudiante buscado  
	\param   apellidos del estudiante buscado
	\return  Verdadero si existe el estudiante; falso, en caso contrario
*/
	virtual	bool existeEstudiante(std::string const &nombre, std::string const &apellidos) = 0;



/*!		
	\brief   Devuelve el estudiante con un nombre y unos apellidos 
	\note    Función virtual pura
	\warning Función sobrecargada
	\param   nombre del estudiante buscado  
	\param   apellidos del estudiante buscado
	\pre     Debe existir el estudiante con el nombre y apellidos indicados
	\return  Objeto de la clase Estudiante
	\sa      existeEstudiante 
*/
	virtual ed::Estudiante const & getEstudiante(std::string const &nombre, std::string const & apellidos) = 0;

/*!		
	\brief   Devuelve el estudiante que ocupa la posición indicada
	\note    Función virtual pura
	\warning Función sobrecargada
	\param   indice número que indica la posición del estudiante en la asignatura
	\pre     Debe existir el estudiante que ocupe la posición indicada
	\return  Objeto de la clase Estudiante
	\sa      getNumeroEstudiantes
*/
	virtual ed::Estudiante const & getEstudiante(int indice) = 0;


/*!	
	\name Modificadores
*/

/*!		
	\brief  Modifica el código de la asignatura
	\note   Función virtual pura
	\param  codigo: dato de tipo entero que será el nuevo código de la asignatura
	\post   El código de la asignatura deberá tener el código asignado
	\return void
	\sa     getCodigo
*/
	virtual void setCodigo(int codigo) = 0;
	

/*!		
	\brief  Modifica el nombre de la asignatura
	\note   Función virtual pura
	\param  nombre: dato de tipo cadena que será el nuevo nombre de la asignatura
	\post   El nombre de la asignatura deberá tener el nombre asignado
	\return void
	\sa     getNombre
*/
	virtual void setNombre(std::string const &nombre) = 0;
	

/*!		
	\brief  Inserta un estudiante de forma ordenada según los apellidos y el nombre
	\note   Función virtual pura
	\param  nombre del estudiante
	\param  apellidos del estudiante
	\param  teoria: nota de teoría del estudiante
	\param  practica: nota de prácticas del estudiante
	\pre    No debe existir otro estudiante con el mismo nombre y apellidos
	\post   El estudiante está insertado en la asignatura.
	\post   El número de estudiantes debe haberse aumentado en uno
	\return Verdadero, en el caso de que logre insertar el estudiante; falso, en caso contrario
	\sa     existeEstudiante, getNumeroEstudiantes   
*/
	virtual	bool insertarEstudiante(std::string const &nombre, std::string const &apellidos,float teoria, float practica) = 0;


/*!		
	\brief   Devuelve el estudiante con un nombre y unos apellidos 
	\note    Función virtual pura
	\warning Función sobrecargada
	\param   nombre del estudiante buscado  
	\param   apellidos del estudiante buscado
	\pre 	 Debe existir el estudiante con el nombre y apellidos indicados
	\post    No debe existir otro estudiante con el mismo nombre y apellidos
	\post    El número de estudiantes debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el estudiante; falso, en caso contrario
	\sa      existeEstudiante getNumeroEstudiantes
*/
	virtual	bool borrarEstudiante(std::string const &nombre, std::string const &apellidos) = 0;
}; //Fin de la clase AsignaturaInterfaz


} //Fin del espacio de nombres ed

#endif
