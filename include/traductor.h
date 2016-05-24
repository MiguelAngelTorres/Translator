/**
  * @file traductor.h
  * @brief Fichero cabecera del TDA Traductor
  *
  */

 /*! \mainpage Pagina Principal del Proyecto Traductor
  * \image html logodelproyecto.jpg Realizado por Miguel Ángel Torres López 
  * \image html logodelproyecto.jpg
  * \section intro_sec Introducción
  *
  * Este es un proyecto desarrollado con el fin de simplificar la búsqueda de traducciones de un idioma a otro.
  * Esta pensado para un uso personal y permite la versatilidad que un cuaderno común no posee, ya que permite buscar
  * palabras y sus posibles traducciones a otro idioma de manera rápida y sencilla.
  *
  * \section use_sec Uso 
  *
  * \subsection step1 Paso 1: Creación de una libreta
  *
  * Con el fin de almacenar tantas palabras con sus respectivas traducciones como sea posible, será necesario crear un fichero
  * con la extension .txt que almacene las palabras con sus traducciones, debe tener el siguiente formato:
  *
  *  @include prueba_spanish_english
  * SIENDO EL ÚLTIMO \n IMPRESCINDIBLE PARA QUE EL PROGRAMA FUNCIONE CORRECTAMENTE
  *
  * \subsection step2 Paso 2: Búsqueda de traducciones
  *
  * Una vez creado el fichero libreta, solo será necesario cargarla tal y como se muestra en el ejecutable de
  * prueba que viene al final de este paso.
  * Ahora cuando hayas aprendido muchas palabras en un idioma y no te acuerdes de una en concreto, no será necesario recorrer
  * una y otra vez tu libreta buscandola, basta con ejecutar tu programa y escribir la palabra deseada.
  *
  * @include pruebatraductor.cpp
  */
#ifndef __TRADUCTOR
#define __TRADUCTOR

#include <string>
#include "palabra.h"
using namespace std;

/**
  *  @brief T.D.A. Traductor
  *
  * Una instancia @e T del tipo de datos abstracto @c traductor es un objeto
  * que representa un conjunto de palabras en un idioma concreto y sus posibles traducciones.
  *
  *
  * Un ejemplo de su uso:
  * @include pruebatraductor.cpp
  *
  * @author Miguel Ángel Torres
  * @date Octubre 2015
  */

class traductor{
	private:
/**
  * @page repConjuntoTraductor Rep del TDA Traductor
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.entradas!=NULL
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Traductor representa las palabras
  *
  * rep.entradas[0-rep.nentr]
  *
  */

		void Resize(int nuevo_n);
		int Reservados();
		palabra *entradas ;
		int nentr ;
		int entrres ;
	public:
/**
  * @brief Constructor por defecto de la clase
  * @return Crea un objeto traductor con ninguna defenición. Es necesario usar el operador >> para cargar definiciones.
  */
		traductor();

/**
  * @brief Destructor de la clase
  * @return Destruye el objeto traductor
  */
		~traductor();
		
/**
  * @brief Constructor de copia de la clase
  * @param orig Traductor que se va a copiar para construir el nuevo objeto
  * @return Crea un traductor con las mismas palabras que orig
  */
		traductor(const traductor& orig);

/**
  * @brief Número de palabras del traductor
  * @return Devuelve el número total de palabras que contiene el traductor en la actualidad
  */	
		int Tamanio() const ;

/**
  * @brief Operador de asignación de la clase
  * @param trad Traductor que se va a asignar.
  * @return Convierte el traductor en una copia de trad
  */
		traductor& operator=(const traductor& trad);

/**
  * @brief Añade palabras a Traductor
  * @param w objeto del TDA palabra que se va a adherir a traductor
  */
		void Aniade(palabra w);

/**
  * @brief Busca las traducciones
  * @param busqueda Palabra que se va a intentar traducir
  * @param nacep Número de traducciones encontradas para busqueda
  * @return Devuelve un puntero a string con el vector formado por la palabra buscada (0) y las traducciones (1-nacep)
  * @pre nacep es un parametro pasado por referencia, se perderá su valor para dar el número de traduccioens de busqueda
  */
		string* GetTraduccion(string busqueda, int& nacep);
};

/**
  * @brief Cargar traductor a partir de un flujo de datos
  * @param f Flujo desde el que se van a introducir las palabras
  * @param datos Traductor al que se van a cargar las palabras.
  * @return Devuelve el flujo para permitir encadenar varios flujos
  * @pre En el flujo, las palabras deberán estar agrupadas de la siguiente forma :
  *		palabra_origen;traducción;traducción;traducción....\n
  *     ES IMPRESCINDIBLE QUE EL DOCUMENTO TERMINE CON UN RETORNO DE CARRO
  */
		istream& operator>>(istream& f, traductor& datos);

#endif
