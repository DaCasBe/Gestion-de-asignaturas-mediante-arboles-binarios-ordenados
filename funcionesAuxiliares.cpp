/*!
	\file   funcionesAuxiliares.hpp
	\brief  Código de las funciones auxiliares del programa principal de la asignatura
	\author Daniel Castillo Bello
	\date   27-04-2017
*/

#include <iostream>
#include <string>

#include "funcionesAuxiliares.hpp"
#include "estudiante.hpp"

#include "macros.hpp"

int ed::menu(){
	int opcion, posicion;

	//Se muestran las opciones del menú
	posicion=8;

	//Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	LUGAR(5,10);
   	std::cout << BBLUE;
	std::cout << "Programa principial | Opciones del menú   ";
	std::cout << RESET;

	LUGAR(posicion++,10);
	std::cout << IGREEN << "[1] Comprobar si la asignatura está vacía";

	LUGAR(posicion++,10);
	std::cout << "[2] Cargar la asignatura de un fichero";

	LUGAR(posicion++,10);
	std::cout << "[3] Grabar la asignatura en un fichero";

	LUGAR(posicion++,10);
	std::cout << "[4] Consultar datos de la asignatura: código, nombre, lista de estudiantes";

	LUGAR(posicion++,10);
	std::cout << "[5] Modificar datos de la asignatura: código o nombre";

	LUGAR(posicion++,10);
	std::cout << "[6] Borrar una asignatura";


	LUGAR(posicion++,10);
	std::cout << "[7] Consultar un estudiante";

	LUGAR(posicion++,10);
	std::cout << "[8] Insertar un estudiante";

	LUGAR(posicion++,10);
	std::cout << "[9] Modificar un estudiante";

	LUGAR(posicion++,10);
	std::cout << "[10] Borrar un estudiante";

	LUGAR(posicion++,10);
	std::cout << GREEN << "[0] Salir";

	LUGAR(posicion++,20);
	std::cout << IYELLOW;
	std::cout << "Opción: ";
	std::cout << RESET;

	//Se lee el número de opción
	std::cin >> opcion;

	//Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
}

void ed::comprobarAsignaturaVacia(ed::Asignatura const &asignatura){
	std::cout << std::endl << IPURPLE "La asignatura de nombre < " << asignatura.getNombre() << " > ";

	if (asignatura.estaVacia()){ //La asignatura está vacía
		std::cout << "está vacía" << RESET;
	}

	else{ //La asignatura no está vacía
		std::cout << "no está vacía" << RESET;
	}
}

void ed::cargarAsignatura(ed::Asignatura &asignatura){
	if(!asignatura.estaVacia()){ //La asignatura no está vacía
		borrarAsignatura(asignatura); //Borramos la asignatura
	}

	std::string nombreFichero;

	//Pedimos al usuario el nombre del fichero con la información de la asignatura a cargar
	std::cout << std::endl << YELLOW << "Introduzca el nombre del fichero " << BIYELLOW << "(no olvide la extensión .txt): " << RESET;
	std::cin >> nombreFichero;

	if(!asignatura.cargarFichero(nombreFichero)){ //No se ha podido cargar la asignatura
		std::cout << std::endl << BIRED << "Error: no se pudo abrir el fichero" << RESET << std::endl;
		std::cin.ignore();
	}

	else{ //Se ha podido cargar la asignatura
		std::cout << std::endl << CYAN << "Asignatura cargada correctamente" << RESET << std::endl;
		std::cin.ignore();
	}
}

void ed::grabarAsignatura(ed::Asignatura  &asignatura){
	if(asignatura.estaVacia()){ //La asignatura está vacía
		std::cout << std::endl << BIRED << "Error: no hay ningún estudiante cargado" << RESET << std::endl;
	}

	else{ //La asignatura no está vacía
		std::string nombreFichero;

		//Pedimos al usuario el nombre del fichero en el que grabar la información de la asignatura
		std::cout << std::endl << BIYELLOW << "Introduzca el nombre del fichero (no olvide la extensión .txt): " << RESET;
		std::cin >> nombreFichero;

		if(!asignatura.grabarFichero(nombreFichero)){ //No se ha podido grabar la asignatura
			std::cout << std::endl << std::endl << BIRED << "Error: no se pudo abrir el fichero" << RESET << std::endl;
		}

		else{ //Se ha podido grabar la asignatura
			std::cout << std::endl << CYAN << "Asignatura grabada correctamente" << RESET << std::endl;
			std::cin.ignore();
		}
	}
}

void ed::consultarAsignatura(ed::Asignatura  &asignatura){
	if(asignatura.estaVacia()){ //La asignatura está vacía
		std::cout << std::endl << BIRED << "Error: no hay ningún estudiante cargado" << RESET << std::endl;
	}

	else{ //La asignatura no está vacía
		//Mostramos la información de la asignatura
		std::cout << std::endl << BBLUE << "Código de la asignatura: " << BLUE << asignatura.getCodigo() << RESET << std::endl << std::endl;
		std::cout << BBLUE << "Nombre de la asignatura: " << BLUE << asignatura.getNombre() << RESET << std::endl << std::endl;
		std::cout << BBLUE << "Lista de estudiantes de la asignatura:" << BLUE << std::endl;

		asignatura.consultarEstudiantes();
		
		std::cout << RESET;
	}
}

void ed::modificarAsignatura(ed::Asignatura &asignatura){
	int opcion;
	int codigo;
	std::string nombre;

	do{
		//Mostramos los datos de la asignatura
		std::cout << std::endl << BIBLUE << "Datos actuales de la asignatura: " << RESET << std::endl;
		std::cout << BBLUE << "Código: " << BLUE << asignatura.getCodigo() << RESET << std::endl;
		std::cout << BBLUE << "Nombre: " << BLUE << asignatura.getNombre() << RESET << std::endl << std::endl;

		//Preguntamos al usuario qué desea modificar
		std::cout << BGREEN << "Indique qué dato desea modificar: " << RESET << std::endl;
		std::cout << IGREEN << "(1) código" << std::endl;
		std::cout << "(2) nombre" << std::endl;
		std::cout << GREEN << "(0) salir" << RESET << std::endl;
		std::cout << IYELLOW << "Opción: " << RESET;
		std::cin >> opcion;

		switch(opcion){
			case 0: //Salir
				break;

			case 1: //Modificar código
				//Pedimos al usuario el nuevo código de la asignatura
				std::cout << std::endl << IPURPLE "Nuevo código: " << RESET;
				std::cin >> codigo;

				asignatura.setCodigo(codigo); //Modificamos el código de la asignatura

				break;

			case 2: //Modificar nombre
				//Pedimos al usuario el nuevo nombre de la asignatura
				std::cin.ignore();
				std::cout << std::endl << IPURPLE << "Nuevo nombre: " << RESET;
				getline(std::cin,nombre);

				asignatura.setNombre(nombre); //Modificamos el nombre de la asignatura

				break;

			default: //Opción incorrecta
				std::cout << std::endl << BIRED << "Error: opción incorrecta" << RESET << std::endl << std::endl;

				break;
		}
	}while(opcion!=0);
}

void ed::borrarAsignatura(ed::Asignatura &asignatura){
	asignatura.setCodigo(0); //Borramos el código de la asignatura
	asignatura.setNombre(""); //Borramos el nombre de la asignatura

	//Borramos la lista de estudiantes
	while(!asignatura.estaVacia()){	
		asignatura.borrarEstudiante(0);
	}

	std::cout << std::endl << CYAN << "Asignatura borrada correctamente" << RESET << std::endl;
}

void ed::consultarEstudianteDeAsignatura(ed::Asignatura &asignatura){
	if(asignatura.estaVacia()){ //La asignatura está vacía
		std::cout << std::endl << BIRED << "Error: no hay ningún estudiante cargado" << RESET << std::endl;
	}

	else{ //La asignatura no está vacía
		std::string nombre;
		std::string apellidos;

		//Pedimos al usuario los datos del estudiante a consultar
		std::cout << std::endl << BIYELLOW << "Introduzca el nombre y los apellidos del estudiante" << RESET << std::endl;
		std::cout << IYELLOW << "Nombre: " << RESET;
		getline(std::cin,nombre);
		std::cout << IYELLOW << "Apellidos: " << RESET;
		getline(std::cin,apellidos);

		if(!asignatura.existeEstudiante(nombre,apellidos)){ //No existe el estudiante indicado por el usuario
			std::cout << std::endl << BIRED << "Error: el estudiante " << nombre << " " << apellidos << " no pertenece a la asignatura" << RESET << std::endl;
		}

		else{ //Existe el estudiante indicado por el usuario
			//Mostramos las notas del estudiante
			std::cout << std::endl << BBLUE << "Notas de " << asignatura.getEstudiante(nombre,apellidos).getNombre() << " " << asignatura.getEstudiante(nombre,apellidos).getApellidos() << RESET << std::endl;
			std::cout << BBLUE << "Teoría: " << BLUE << asignatura.getEstudiante(nombre,apellidos).getTeoria() << RESET << std::endl;
			std::cout << BBLUE << "Practíca: " << BLUE << asignatura.getEstudiante(nombre,apellidos).getPractica() << RESET << std::endl;
			std::cout << BBLUE << "Final: " << BLUE << asignatura.getEstudiante(nombre,apellidos).getFinal() << RESET << std::endl;
		}
	}
}

void ed::insertarEstudianteEnAsignatura(ed::Asignatura &asignatura){
	ed::Estudiante estudiante;

	std::cout << std::endl << BIYELLOW << "Introduzca los datos del estudiante" << RESET << std::endl;
	estudiante.leerEstudiante(); //Pedimos al usuario la información del estudiante a insertar

	if(!asignatura.existeEstudiante(estudiante)){ //No existe el estudiante indicado por el usuario
		if(!asignatura.insertarEstudiante(estudiante)){ //No se ha podido insertar el estudiante
			std::cout << std::endl << BIRED << "Error: no se ha podido insertar el estudiante indicado" << RESET << std::endl;
		}

		else{ //Se ha podido insertar el estudiante
			std::cout << std::endl << CYAN << "Estudiante insertado correctamente" << RESET << std::endl;
		}
	}

	else{ //Existe el estudiante indicado por el usuario
		std::cout << std::endl << BIRED << "Error: ya existe el estudiante indicado" << RESET << std::endl;
	}
}

void ed::modificarEstudianteDeAsignatura(ed::Asignatura &asignatura){
	if(asignatura.estaVacia()){ //La asignatura está vacía
		std::cout << std::endl << BIRED << "Error: no hay ningún estudiante cargado" << RESET << std::endl;
	}
	
	else{ //La asignatura no está vacía
		int opcion;
		bool control;
		std::string nombre;
		std::string apellidos;
		float nota;
		ed::Estudiante estudiante;
		ed::Estudiante nuevoEstudiante;

		//Pedimos al usuario el nombre y los apellidos del estudiante a modificar
		std::cout << BIYELLOW << "Introduzca el nombre y los apellidos del estudiante: " << RESET << std::endl;
		std::cout << IYELLOW << "Nombre: " << RESET;
		std::getline(std::cin,nombre);
		std::cout << IYELLOW << "Apellidos: " RESET;
		std::getline(std::cin,apellidos);

		control=asignatura.existeEstudiante(nombre,apellidos);	

		if(control){ //Existe el estudiante indicado por el usuario
			estudiante=asignatura.getEstudiante(nombre,apellidos);

			do{
				//Mostramos los datos del estudiante
				std::cout << std::endl << BIBLUE << "Datos actuales del estudiante: " << RESET << std::endl;
				estudiante.escribirEstudiante();
		
				//Preguntamos al usuario qué desea modificar
				std::cout << std::endl;
				std::cout << BGREEN << "Indique qué dato desea modificar: " << RESET << std::endl;
				std::cout << IGREEN << "(1) nombre" << std::endl;
				std::cout << "(2) apelllidos" << std::endl;
				std::cout << "(3) nota de teoría " << std::endl;
				std::cout << "(4) nota prácticas" << std::endl;
				std::cout << GREEN << "(0) salir" << RESET << std::endl;
				std::cout << IYELLOW "Opción: " << RESET;
				std::cin >> opcion;
				std::cin.ignore(); //Se elimina el salto de línea del flujo de entrada
			
				switch(opcion){
					case 0: 
						//Fin de las modificaciones
						break;
					case 1:
						nuevoEstudiante=estudiante;

						std::cout << std::endl << IPURPLE << "Nuevo nombre: " << RESET;
						std::getline(std::cin,nombre);
						nuevoEstudiante.setNombre(nombre);

						//Se comprueba que no existe otro estudiante con la misma clave
						if(!asignatura.existeEstudiante(nuevoEstudiante)){
							//Como se ha modificado un campo de la clave, se borra el antiguo estudiante y se inserta el estudiante modficado de forma ordenada
							asignatura.borrarEstudiante(estudiante);									
							asignatura.insertarEstudiante(nuevoEstudiante);	

							estudiante=nuevoEstudiante;
						}
					
						//Se indica que ya existe un estudiante con la misma clave
						else{
							std::cout << BIRED << "Error: no se puede modificar el nombre porque tendría la misma clave que otro estudiante" << RESET << std::endl;
						}
					
						break;

					case 2:
						nuevoEstudiante=estudiante;

						std::cout << std::endl << IPURPLE << "Nuevos apellidos: " << RESET;
						std::getline(std::cin,apellidos);
						nuevoEstudiante.setApellidos(apellidos);

						//Se comprueba que no existe otro estudiante con la misma clave
						if(!asignatura.existeEstudiante(nuevoEstudiante)){
							//Como se ha modificado un campo de la clave, se borra el antiguo estudiante y se inserta el estudiante modficado de forma ordenada
							asignatura.borrarEstudiante(estudiante);									
							asignatura.insertarEstudiante(nuevoEstudiante);	

							estudiante=nuevoEstudiante;
						}
					
						//Se indica que ya existe un estudiante con la misma clave
						else{
							std::cout << std::endl << BIRED << "Error: no se puede modificar el nombre porque tendría la misma clave que otro estudiante" << RESET << std::endl;
						}
					
						break;

					case 3:
						std::cout << std::endl << IPURPLE << "Nueva nota de teoría: " << RESET;
						std::cin >> nota;
						estudiante.setTeoria(nota);

						//Se modifica su nota
						asignatura.setEstudiante(estudiante);
					
						break;

					case 4:
						std::cout << std::endl << IPURPLE << "Nueva nota de prácticas: " << RESET;
						std::cin >> nota;
						estudiante.setPractica(nota);

						//Se modifica su nota
						asignatura.setEstudiante(estudiante);
					
						break;

					default:
						std::cout << BIRED << "Error: opción incorrecta" << RESET << std::endl;
				}
			}while (opcion != 0);
		}
	
		else{
			std::cout << std::endl << BIRED << "Error: el estudiante " << nombre << " " << apellidos << " no pertenece a la asignatura" << RESET;
		}
	}
}


void ed::borrarEstudianteDeAsignatura(ed::Asignatura &asignatura){
	if(asignatura.estaVacia()){ //La asignatura está vacía
		std::cout << std::endl << BIRED << "Error: no hay ningún estudiante cargado" << RESET << std::endl;
	}
	
	else{ //La asignatura no está vacía
		bool control;
		std::string nombre;
		std::string apellidos;
		ed::Estudiante estudiante;

		//Pedimos al usuario el nombre y los apellidos del estudiante a borrar
		std::cout << BIYELLOW << "Introduzca el nombre y los apellidos del estudiante" << RESET << std::endl;
		std::cout << IYELLOW << "Nombre: " << RESET;
		std::getline(std::cin,nombre);
		std::cout << IYELLOW << "Apellidos: " << RESET;
		std::getline(std::cin,apellidos);

		control=asignatura.existeEstudiante(nombre,apellidos);	

		if(control){ //Existe el estudiante indicado por el usuario
			asignatura.borrarEstudiante(nombre,apellidos); //Borramos el estudiante indicado

			control=asignatura.existeEstudiante(nombre,apellidos);	

			if(control){ //No se ha borrado el estudiante indicado
				std::cout << std::endl << BIRED << "Error: el estudiante no ha podido ser borrado" << RESET << std::endl;
			}

			else{ //Se ha borrado el estudiante indicado
				std::cout << std::endl << CYAN << "El estudiante ha sido borrado correctamente" << RESET << std::endl;
			}
		}	

		else{ //No existe el estudiante indicado por el usuario
			std::cout << std::endl << BIRED "Error: el estudiante "<< nombre << " " << apellidos << " no pertenece a la asignatura" << RESET;
		}
	}
}
