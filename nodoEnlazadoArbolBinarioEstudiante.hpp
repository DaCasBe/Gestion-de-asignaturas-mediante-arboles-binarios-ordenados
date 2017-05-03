/*! 	
	\file    nodoEnlazadoArbolBinarioEstudiante.hpp
	\brief   Declaración del TAD NodoEnlazadoArbolBinarioEstudiante: nodo enlazado de árbol binario con el campo informativo Estudiante
	\author  Daniel Castillo Bello
	\date    27-04-2017
	\version 1.0
*/

#ifndef _NodoEnlazadoArbolBinarioEstudiante_HPP_
#define _NodoEnlazadoArbolBinarioEstudiante_HPP_

#include <fstream>
#include "nodoEstudianteInterfaz.hpp"
#include "estudiante.hpp"


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{

/*!
	\class NodoEnlazadoArbolBinarioEstudiante
	\brief Definición de la clase NodoEnlazadoArbolBinarioEstudiante
	\note  Hereda de la clase NodoEstudianteInterfaz
	\attention Todos los métodos han sido definidos como "inline"
*/
class NodoEnlazadoArbolBinarioEstudiante: public NodoEstudianteInterfaz{

/*!		
	\name Atributos o métodos privados
*/
	private:
		Estudiante * _item;                              //!< \brief campo informativo del nodo 
		NodoEnlazadoArbolBinarioEstudiante * _leftTree;  //!< \brief puntero al subárbol izquierdo
		NodoEnlazadoArbolBinarioEstudiante * _rightTree; //!< \brief puntero al subárbol derecho
		NodoEnlazadoArbolBinarioEstudiante * _parent;    //!< \brief puntero al nodo padre

/*!		
	\brief     Función auxiliar para liberar la memoria de los nodos del árbol binario
	\attention Método privado
	\note      Función codificada en el fichero cpp
	\post      El árbol está vacío
	\sa        hasLeftTree, getLeftTree, hasRightTree, getRightTree, ~NodoEnlazadoArbolBinarioEstudiante, setLeftTree, setRightTree, setParent, isEmpty
*/
		void liberarMemoria();


/*!	
	\name Funciones o métodos públicos
*/
	public:

/*!
	\name Constructor
*/

/*!		
	\brief     Constructor no parametrizado 
	\note      Función inline
	\attention Función sobrecargada
	\post      Crea un nuevo objeto de la clase NodoEnlazadoArbolBinarioEstudiante sin estudiante, sin subárboles izquierdo y derecho y sin padre
	\sa        setItem, setLeftTree, setRightTree, setParent, getItem, getLeftTree, getRightTree, getParent
*/
		inline NodoEnlazadoArbolBinarioEstudiante(){
			this->_item = NULL;
			this->setLeftTree(NULL);
			this->setRightTree(NULL);
			this->setParent(NULL);
			
			//Postcondición
			#ifndef NDEBUG
				assert(getLeftTree()==NULL and getRightTree()==NULL and getParent()==NULL);
			#endif
		}
 
/*!		
	\brief     Constructor parametrizado 
	\note      Función inline
	\attention Función sobrecargada
	\param     item: campo informativo del nodo 
	\param     lefTree: puntero al nodo lefTree
	\param     rightTree: puntero al nodo rightTree
	\post      Crea un nuevo objeto de la clase NodoEnlazadoArbolBinarioEstudiante con los valores de los argumentos
	\sa        setItem, setLeftTree, setRightTree, setParent
*/
		inline NodoEnlazadoArbolBinarioEstudiante(ed::Estudiante const & item,NodoEnlazadoArbolBinarioEstudiante* lefTree,NodoEnlazadoArbolBinarioEstudiante* rightTree){
			this->_item = new Estudiante(item);
			this->setLeftTree(lefTree);
			this->setRightTree(rightTree);
			this->setParent(NULL);
			
			//Postcondición
			#ifndef NDEBUG
				assert(getItem()==item and getLeftTree()==lefTree and getRightTree()==rightTree);
			#endif
		}

/*!
	\name Destructor
*/
 
/*!		
	\brief Destructor
	\note  Función inline
	\sa    liberarMemoria
*/
		~NodoEnlazadoArbolBinarioEstudiante(){
			liberarMemoria(); //Liberamos la memoria del árbol
		}


/*!
	\name Observadores
*/

/*!
	\brief   Comprueba si el campo informativo es nulo
	\warning Función de tipo "const": no puede modificar al objeto actual
	\return  Verdadero, si el árbol está vacía; falso, en caso contrario
*/
		inline bool isEmpty() const{
			return (this->_item == NULL);
		}


/*!	
	\brief  Método público que permite conocer el campo informativo del nodo 
	\note   Función inline
	\pre    El árbol no está vacío
	\return Devuelve el valor del atributo _item
	\sa     isEmpty
*/
		 inline ed::Estudiante const & getItem() const{
		 	//Precondición
			#ifndef NDEBUG
			 	assert(this->isEmpty() == false);	
			#endif	

		 	return *(this->_item); //Se devuelve el contenido de la información apuntada por _item
		}


/*!
	\brief  Comprueba si existe el subárbol izquierdo 
	\note   Función inline
	\return Verdadero, si el nodo tiene hijo izquierdo; falso en caso contrario
	\sa     getLeftTree
*/
		inline bool hasLeftTree() const{
			return (this->getLeftTree() != NULL);
		}

/*!
	\brief   Comprueba si existe el subárbol derecho 
	\note    Función inline
	\return  Verdadero, si el nodo tiene hijo derecho; falso en caso contrario
	\sa      getRightTree
*/
		
		inline bool hasRightTree() const{
			return (this->getRightTree() != NULL);
		}

/*!
	\brief   Comprueba si existe el nodo padre 
	\note    Función inline
	\return  Verdadero, si el nodo tiene padre; falso en caso contrario
	\sa  	 getParent
*/
		inline bool hasParent() const{
			return (this->getParent() != NULL);
		}

/*!	
	\brief   Método público que permite acceder al subárbol izquierdo
	\note    Función inline
	\warning Método "const" que no modifica el objeto de la clase
	\return  Devuelve el puntero al nodo _leftTree
*/
		inline NodoEnlazadoArbolBinarioEstudiante *getLeftTree() const {
		 	return this->_leftTree;
		}


/*!	
	\brief   Método público que permite acceder al subárbol derecho
	\note    Función inline
	\warning Método "const" que no modifica el objeto de la clase
	\return  Devuelve el puntero al nodo rightTree
*/
		inline NodoEnlazadoArbolBinarioEstudiante *getRightTree() const{
		 	return this->_rightTree;
		}

/*!	
	\brief   Método público que permite acceder al nodo padre
	\note    Función inline
	\warning Método "const" que no modifica el objeto de la clase
	\return  Devuelve el puntero al nodo rightTree
*/
		inline NodoEnlazadoArbolBinarioEstudiante  *getParent() const{
		 	return this->_parent;
		}

/*!
	\brief   Devuelve el número de elementos o ítems del árbol binario
	\note    Función codificada en el fichero cpp
	\warning Método "const" que no modifica el objeto de la clase
	\return  items que tiene el arbol
	\sa      isEmpty, hasLeftTree, getLeftTree, hasRightTree, getRightTree
*/
	    	int nItems() const;


/*!
	\brief  Comprueba si existe el estudiante buscado;
	\note   Función codificada en el fichero cpp
	\param  item con el nombre y los apellidos del estudiante a buscar
	\return Verdadero, si el ítem existe; falso, en caso contrario
	\sa     isEmpty, getItem, hasLeftTree, getLeftTree, hasRightTree, getRightTree
*/
		bool exists(ed::Estudiante const &item);


/*!
	\brief     Develve un estudiante que existe
	\note      Función codificada en el fichero cpp
	\attention Función sobrecargada
	\warning   Método "const" que no modifica el objeto de la clase
	\param     item con el nombre y los apellidos del estudiante que se quiere obtener
	\pre       Existe el estudiante que se quiere obtener
	\return    Estudiante
	\sa        exists, getItem, getLeftTree, getRightTree
	
*/
		ed::Estudiante const &getEstudiante(ed::Estudiante const & item);


/*!
	\brief     Develve un estudiante que existe
	\note      Función codificada en el fichero cpp
	\attention Función sobrecargada
	\warning   Método "const" que no modifica el objeto de la clase
	\param     indice del estudiante que se quiere obtener
	\pre       El árbol no esta vacío
	\pre       El índice debe ser menor o igual al número del estudiantes del árbol
	\return    Estudiante
	\sa        isEmpty, nItems, hasLeftTree, getLeftTree, getItem, getRightTree
*/
		ed::Estudiante const &getEstudiante(int indice);

/*!
        \brief   Devuelve el menor estudiante del árbol actual
	\note    Función codificada en el fichero cpp
	\warning Método "const" que no modifica el objeto de la clase
	\pre     El árbol no esta vacío
	\return  Estudiante
	\sa      isEmpty, hasLeftTree, getLeftTree, getItem
*/
		ed::Estudiante const &getMinor() const;

/*!
	\name Modificadores
*/

/*!	
	\brief   Método público que permite modificar el campo informativo del nodo
	\note    Función inline
	\warning La clase Estudiante debe tener sobrecargado el operador de asignación "="
	\param   nuevoItem: nuevo valor del campo informativo
	\post    El campo informativo del nodo actual es igual al parámetro pasado como argumento
	\return  void
	\sa      getItem
*/
		inline void setItem(ed::Estudiante const & nuevoItem){
			//Si el ítem actual es nulo
			if (this->_item == NULL){
				//Se reserva memoria y se copia el nuevo ítem
				this->_item = new Estudiante(nuevoItem);
			}

			//Si ya se ha reservado memoria para ítem
			else{
				//Se copia el nuevo ítem en el ítem actual
				*(this->_item) = nuevoItem;
			}
			
			//Postcondición
			#ifndef NDEBUG
				assert(getItem()==nuevoItem);
			#endif
		}		


/*!	
	\brief  Método público que permite modificar el subárbol izquierdo
	\note   Función inline
	\param  lefTree: nuevo puntero al nodo lefTree
	\post   El hijo izquierdo es igual al parámetro pasado como argumento
	\return void
	\sa     getLeftTree
*/
		inline void setLeftTree(NodoEnlazadoArbolBinarioEstudiante *lefTree){
			this->_leftTree = lefTree;
			
			//Postcondición
			#ifndef NDEBUG
				assert(getLeftTree()==lefTree);
			#endif
		}

		
/*!	
	\brief  Método público que permite modificar el subárbol derecho
	\note   Función inline
	\param  rightTree: nuevo puntero al nodo rightTree
	\post   El hijo derecho es igual al parámetro pasado como argumento
	\return void
	\sa     getRightTree
*/
		inline void setRightTree(NodoEnlazadoArbolBinarioEstudiante *rightTree){
			this->_rightTree = rightTree;
			
			//Postcondición
			#ifndef NDEBUG
				assert(getRightTree()==rightTree);
			#endif
		}


/*!	
	\brief  Método público que permite modificar el nodo padre
	\note   Función inline
	\param  parent: nuevo puntero al nodo padre
	\post   El nodo padre es igual al parámetro pasado como argumento
	\return void
	\sa     getParent
*/
		inline void setParent(NodoEnlazadoArbolBinarioEstudiante  *parent){
			this->_parent = parent;
			
			//Postcondición
			#ifndef NDEBUG
				assert(getParent()==parent);
			#endif
		}



/*!
	\brief     Modifica las notas de un estudiante
	\note      Función codificada en el fichero cpp
	\attention Permitirá modificar la nota de teoría y la nota de práctica
	\param     item con el nombre y los apellidos del estudiante a modificar
	\pre       Existe el estudiante con el nombre y los apellidos del item
	\post      Existe el estudiante con el nombre y los apellidos del item
	\return    void
	\sa        exists, setItem
*/
		void setEstudiante(ed::Estudiante const &item);

/*!
	\brief  Inserta un Estudiante de forma ordenada por apellidos y nombre
	\note   Función codificada en el fichero cpp
	\param  item que contiene la informacion del estudiante a insertar
	\pre    No existe el estudiante a insertar
	\post   Existe el estudiante insertado
	\return void
	\sa     exists, isEmpty, setItem, getItem, hasLeftTree, getLeftTree, setLeftTree, setRightTree, setParent, hasRightTree, getRightTree
*/
 		void insert(ed::Estudiante const &item);

/*!
	\brief  Borra el estudiante indicado como parámetro
	\note   Función codificada en el fichero cpp
	\param  item con el nombre y los apellidos del estudiante a borrar
	\pre    Existe el estudiante a borrar
	\post   No existe el estudiante borrado
	\return void
	\sa     exists, getItem, hasLeftTree, hasRightTree, hasParent, getParent, getLeftTree, setLeftTree, setRightTree, setParent, ~NodoEnlazadoArbolBinarioEstudiante, setItem, getMinor
*/
		void remove(ed::Estudiante const &item);


/*!
	\name Escritura
*/

/*!
	\brief  Escribe los estudiantes usando el recorrido "en orden"
	\note   Función codificada en el fichero cpp
	\pre    El árbol no esta vacío
	\return void
	\sa 	isEmpty, getLeftTree, getItem, getRightTree
*/
	 	void inorder();


/*!
	\brief  Graba un nodo en un fichero de texto
	\note   Función codificada en el fichero cpp
	\param  fichero en el que se va a grabar el árbol
	\pre    El árbol no esta vacío
	\return void
	\sa     isEmpty, getItem, hasLeftTree, getLeftTree, hasRightTree, getRightTree
*/
		void grabar(std::ofstream &fichero);

		
// Fin de la clase NodoEnlazadoArbolBinarioEstudiante
};

// Fin del espacio de nombres ed
}

//Fin  _NodoEnlazadoArbolBinarioEstudiante_HPP_
#endif  
