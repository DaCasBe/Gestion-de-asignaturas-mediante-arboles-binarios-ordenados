/*!	
	\file    asignatura.hpp
	\brief   Definición de la clase Asignatura
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/

#ifndef _ASIGNATURA_HPP_
#define _ASIGNATURA_HPP_

#include <cassert>
#include <string>

#include "asignaturaInterfaz.hpp"

#include "nodoEnlazadoArbolBinarioEstudiante.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{

/*!	
	\class Asignatura
	\brief Representa la clase Asignatura
*/
class Asignatura: public ed::AsignaturaInterfaz{

/*!		
	\name Métodos públicos de la clase Asignatura
*/
	private:
		int _codigo;	                               //!<  \brief Código de la asignatura
		std::string _nombre;                           //!<  \brief Nombre de la asignatura
		ed::NodoEnlazadoArbolBinarioEstudiante _arbol; //!<  \brief Árbol binario ordenados de estudiantes de la asignatura

/*!		
	\name  Métodos públicos de la clase Asignatura
*/
	public: 


/*!	
	\name Constructor
*/

/*!		
	\brief     Constructor parametrizado 
	\note      Función inline
	\post      Crea un nuevo objeto de la clase Asignatura con valores por defecto para el codigo y el nombre
	\sa        setCodigo, setNombre
*/
	Asignatura(int codigo=0,std::string const &nombre=""){
		this->setCodigo(codigo);
		this->setNombre(nombre);

		/*
			El constructor de NodoEnlazadoArbolBinarioEstudiante 
    			asigna valores nulos
		*/
	}


/*!	
	\name Observadores
*/

/*!		
	\brief  Devuelve el código de la asignatura
	\note   Función inline
	\return Número entero que representa el código numérico de la asignatura
*/
	inline int getCodigo() const{
		return this->_codigo;
	}

/*!		
	\brief  Devuelve el nombre de la asignatura
	\note   Función inline
	\return Cadena que representa el nombre de la asignatura
*/
	inline std::string getNombre() const{
		return  this->_nombre;
	}


/*!		
	\brief  Indica si la asignatura tiene o no estudiantes
	\note   Función inline
	\return Verdadero si no tiene estudiantes; falso, en caso contrario
*/
	inline bool estaVacia() const{
		//Se usa el método del atributo _arbol
		return (this->_arbol.isEmpty());
	}


/*!		
	\brief  Devuelve el número de estudiantes
	\note   Función inline
	\return Número entero que representa el número de estudiantes de la asignatura
*/
	inline int getNumeroEstudiantes() const{
		//Se usa el método del atributo _arbol
		return this->_arbol.nItems();
	} 


/*!		
	\brief   Comprueba si existe un estudiante con un nombre y unos apellidos 
	\note    Función inline
	\warning Función sobrecargada
	\param   estudiante buscado
	\return  Verdadero si existe el estudiante; falso, en caso contrario
*/
	inline bool existeEstudiante(ed::Estudiante const &estudiante){
		//Se usa el método del atributo _arbol
		return this->_arbol.exists(estudiante);
	}


/*!		
	\brief   Comprueba si existe un estudiante con un nombre y unos apellidos 
	\note    Función inline
	\warning Función sobrecargada
	\param   nombre del estudiante buscado  
	\param   apellidos del estudiante buscado
	\return  Verdadero si existe el estudiante; falso, en caso contrario
*/
	inline bool existeEstudiante(std::string const &nombre, std::string const &apellidos){
		// Se crea un estudiante auxiliar con el nombre y los apellidos
		ed::Estudiante estudiante(nombre,apellidos,0,0);
   
		// Se llama a la función exists de _arbol
		return this->_arbol.exists(estudiante); 
	}


/*!		
	\brief  Devuelve el estudiante con un nombre y unos apellidos
	\note   Función inline
	\param  nombre del estudiante buscado  
	\param  apellidos del estudiante buscado
	\pre    Debe existir el estudiante con el nombre y apellidos indicados
	\return Referencia constante a un objeto de la clase Estudiante
	\sa     existeEstudiante
*/

	inline ed::Estudiante const & getEstudiante(std::string const &nombre, std::string const &apellidos){
		//Precondición
		#ifndef NDEBUG
			assert(existeEstudiante(nombre,apellidos));
		#endif

		ed::Estudiante estudiante(nombre,apellidos,0,0); //Creamos un estudiante con los datos recibidos

		return _arbol.getEstudiante(estudiante); //Devolvemos el estudiante a buscar
	}



/*!		
	\brief     Devuelve el estudiante con un nombre y unos apellidos
	\note      Función inline
	\warning   Función sobrecargada
	\param     estudiante que se busca en la asignatura
	\pre       Debe existir el estudiante 
	\return    Objeto de la clase Estudiante
	\sa        existeEstudiante
*/

	inline ed::Estudiante const & getEstudiante(ed::Estudiante const &estudiante){
		//Precondición
		#ifndef NDEBUG
			assert(existeEstudiante(estudiante));
		#endif

		return _arbol.getEstudiante(estudiante); //Devolvemos el estudiante a buscar
	}



/*!		
	\brief     Devuelve el estudiante que ocupa la posición indicada
	\note      Función inline
	\warning   Función sobrecargada
	\param     indice del estudiante que se busca en la asignatura
	\pre       Debe existir el estudiante 
	\return    Objeto de la clase Estudiante
	\sa        getNumeroEstudiantes
*/
	inline ed::Estudiante const & getEstudiante(int indice){
		//Precondición
		#ifndef NDEBUG
			assert(indice<=getNumeroEstudiantes());
		#endif

		return _arbol.getEstudiante(indice); //Devolvemos el estudiante con el indice recibido
	}


/*!	
	\name Modificadores
*/

/*!		
	\brief  Modifica el código de la asignatura
	\note   Función inline
	\param  codigo: dato de tipo entero que será el nuevo código de la asignatura
	\post   El código de la asignatura deberá tener el código asignado
	\return void
	\sa     getCodigo
*/
	inline void setCodigo(int codigo){
		this->_codigo = codigo;
		
		//Postcondición
		#ifndef NDEBUG
			assert(getCodigo()==codigo);
		#endif
	}
	

/*!		
	\brief  Modifica el nombre de la asignatura
	\note   Función inline
	\param  nombre: dato de tipo cadena que será el nuevo nombre de la asignatura
	\post   El nombre de la asignatura deberá tener el nombre asignado
	\return void
	\sa     getNombre
*/
	inline  void setNombre(std::string const & nombre){
		this->_nombre = nombre;
		
		//Postcondición
		#ifndef NDEBUG
			assert(getNombre()==nombre);
		#endif
	}
	
/*!		
	\brief     Modifica el Estudiante indicado
	\note      Función inline
	\attention Solamente se pueden modificar los atributos que no forman parte de la clave, es decir, la nota de teoría y la de prácticas
	\param     e: objeto de tipo Estudiante
	\pre       La clave del parámetro Estudiante (apellidos y nombre) debe ser igual a la clave del Estudiante actual
	\post      La clave del parámetro Estudiante (apellidos y nombre) debe ser igual a la clave del Estudiante actual
	\return    void
	\sa        existeEstudiante
*/
	inline void setEstudiante(ed::Estudiante const &e){
		//Precondición
		#ifndef NDEBUG
			assert(existeEstudiante(e));
		#endif

		_arbol.setEstudiante(e); //Modificamos el estudiante

		//Postcondición
		#ifndef NDEBUG
			assert(existeEstudiante(e));
		#endif
	}


/*!		
	\brief   Inserta un estudiante de forma ordenada según los apellidos y el nombre
	\note    Función inline
	\warning Función sobrecargada
	\param   nombre del estudiante
	\param   apellidos del estudiante
	\param   teoria: nota de teoría del estudiante
	\param   practica: nota de prácticas del estudiante
	\pre     No debe existir otro estudiante con el mismo nombre y apellidos
	\post    El estudiante está insertado en la asignatura.
	\post    El número de estudiantes debe haberse aumentado en uno
	\return  Verdadero, en el caso de que logre insertar el estudiante; falso, en caso contrario
	\sa      existeEstudiante, getNumeroEstudiantes
*/
	inline bool insertarEstudiante(std::string const &nombre, std::string const &apellidos,float teoria, float practica){
		//Precondición
		#ifndef NDEBUG
			assert(!existeEstudiante(nombre,apellidos));
		#endif

		int old=getNumeroEstudiantes();
		ed::Estudiante estudiante(nombre,apellidos,teoria,practica); //Creamos un estudiante con los datos recibidos

		if(existeEstudiante(estudiante)){ //Ya existe el estudiante
			return false;
		}

		else{ //No existe el estudiante
			_arbol.insert(estudiante); //Insertamos el estudiante

			//Postcondición
			#ifndef NDEBUG
				assert(existeEstudiante(nombre,apellidos) and old==getNumeroEstudiantes()-1);
			#endif

			return true;
		}
	}

/*!		
	\brief   Inserta un estudiante de forma ordenada según los apellidos y el nombre
	\note    Función inline
	\warning Función sobrecargada
	\param   estudiante que se va a insertar
	\pre     El estudiante no debe existir en la asignatura
	\post    El estudiante está insertado en la asignatura
	\post    El número de estudiantes debe haberse aumentado en uno
	\return  Verdadero, en el caso de que logre insertar el estudiante; falso, en caso contrario
	\sa      existeEstudiante, getNumeroEstudiantes
*/
	inline bool insertarEstudiante(ed::Estudiante const &estudiante){
		//Precondición
		#ifndef NDEBUG
			assert(!existeEstudiante(estudiante));
		#endif

		int old=getNumeroEstudiantes();

		if(existeEstudiante(estudiante)){ //Ya existe el estudiante
			return false;
		}

		else{ //No existe el estudiante
			_arbol.insert(estudiante); //Insertamos el estudiante

			//Postcondición
			#ifndef NDEBUG
				assert(existeEstudiante(estudiante) and old==getNumeroEstudiantes()-1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el estudiante con el nombre y apellidos indicados
	\note    Función inline
	\warning Función sobrecargada
	\param   nombre del estudiante buscado  
	\param   apellidos del estudiante buscado
	\pre 	 Debe existir el estudiante con el nombre y apellidos indicados
	\post    No debe existir un estudiante  el nombre y apellidos indicados
	\post    El número de estudiantes debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el estudiante; falso, en caso contrario
	\sa      existeEstudiante getNumeroEstudiantes
*/
	inline bool borrarEstudiante(std::string const &nombre, std::string const &apellidos){
		//Precondición
		#ifndef NDEBUG
			assert(existeEstudiante(nombre,apellidos));
		#endif

		int old=getNumeroEstudiantes();
		ed::Estudiante estudiante(nombre,apellidos,0,0); //Creamos un estudiante con los datos recibidos

		if(!existeEstudiante(estudiante)){ //No existe el estudiante
			return false;
		}

		else{ //Si existe el estudiante
			_arbol.remove(estudiante); //Borramos el estudiante

			//Postcondición
			#ifndef NDEBUG
				assert(!existeEstudiante(nombre,apellidos) and old==getNumeroEstudiantes()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el estudiante indicado
	\note    Función inline
	\warning Función sobrecargada
	\param   estudiante de la asignatura
	\pre     Debe existir el estudiante indicado
	\post    El número de estudiantes debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el estudiante; falso, en caso contrario
	\sa      existeEstudiante, getNumeroEstudiantes
*/
	inline bool borrarEstudiante(ed::Estudiante const &estudiante){
		//Precondición
		#ifndef NDEBUG
			assert(existeEstudiante(estudiante.getNombre(),estudiante.getApellidos()));
		#endif

		int old=getNumeroEstudiantes();

		if(!existeEstudiante(estudiante)){ //No existe el estudiante
			return false;
		}

		else{ //Sí existe el estudiante
			_arbol.remove(estudiante); //Borramos el estudiante

			//Postcondición
			#ifndef NDEBUG
				assert(!existeEstudiante(estudiante.getNombre(),estudiante.getApellidos()) and old==getNumeroEstudiantes()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief   Borra el estudiante indicado
	\note    Función inline
	\warning Función sobrecargada
	\param   pos posición del estudiante que se va a borrar
	\pre     El índice debe ser válido
	\post    El número de estudiantes debe haberse reducido en uno
	\return  Verdadero, en el caso de que logre borrar el estudiante; falso, en caso contrario
	\sa      getNumeroEstudintes
*/
	inline bool borrarEstudiante(int pos){
		//Precondición
		#ifndef NDEBUG
			assert(pos<=getNumeroEstudiantes());
		#endif

		int old=getNumeroEstudiantes();

		if(pos>getNumeroEstudiantes()){ //La posición es mayor que el número de estudiantes
			return false;
		}

		else{ //La posición no es mayor que el número de estudiantes
			_arbol.remove(_arbol.getEstudiante(pos)); //Borramos el estudiante en la posición indicada

			//Postcondición
			#ifndef NDEBUG
				assert(old==getNumeroEstudiantes()+1);
			#endif

			return true;
		}
	}


/*!		
	\brief  Muestra por la pantalla la información de los estudiantes de una asignatura
	\note   Función inline
	\return void
*/
	inline void consultarEstudiantes(){
 		this->_arbol.inorder();
	}


/*!		
	\brief  Carga una asignatura desde un fichero
	\param  nombreFichero: nombre del fichero de la asignatura
	\return Verdadero, si se ha cargado correctamente; falso, en caso contrario
	\sa     insertarEstudiante
*/
	bool cargarFichero(std::string const &nombreFichero);

/*!		
	\brief  Graba una asignatura en un fichero
	\param  nombreFichero: nombre del fichero de la asignatura
	\return Verdadero, si se ha grabado correctamente; falso, en caso contrario
	\sa     getNombre, getCodigo
*/
	bool grabarFichero(std::string const &nombreFichero);
}; //Fin de la clase  Asignatura


} // Fin del espacio de nombres ed

#endif // _ASIGNATURA_HPP_
