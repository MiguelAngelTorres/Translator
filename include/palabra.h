/**
  * @file palabra.h
  * @brief Fichero cabecera del TDA palabra
  *
  */
#ifndef __PALABRA
#define __PALABRA

using namespace std;

/**
  *  @brief T.D.A. Palabra
  *
  * Una instancia @e w del tipo de datos abstracto @c palabra es un objeto
  * que representa un término en un idioma de partida y varias traducciones posibles de 
  * dicho término en otro idioma.
  *
  *
  * @author Miguel Ángel Torres
  * @date Octubre 2015
  */

class palabra{
	private:
/**
  * @page repConjuntoPalabra Rep del TDA Palabra
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.termino[0]!="" y \e rep.termino[1]!=""
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA palabra representa los términos
  *
  * rep.termino[0-rep.n]
  *
  */
		void Resize(int nuevo_n);
		const int Reserva();
		string* termino ;
		int n ;
		int reservados;	
	public:
/**
  * @brief Constructor del TDA palabra
  * @return Crea un objeto de tipo palabra con sus campos vacios, luego es necesario cargar la palabra o el objeto estará vació.
  */
		palabra();

/**
  * @brief Constructor de copia del TDA palabra
  * @param w Palabra que va a ser copiada
  * @return Devuelve una nueva palabra con una copia de los campos de w
  */
		palabra(const palabra& w);
		
/**
  * @brief Cargar una palabra con información
  * @param d Cadena de términos con un orden especifico
  * @note MIRE PRECONDICION DE LA FUNCION
  * @pre La cadena deberá estar estructurada de la siguiente forma :
  *		palabra_origen;traducción;traducción;traducción....
  */
		void cargar(const string d);

/**
  * @brief Destructor del TDA Palabra
  * @return Destruye el objeto Palabra
  */
		~palabra();
		
/**
  * @brief Devolución de terminos
  * @return Devuelve un puntero a string que marca el inicio del vector de un término y sus traducciones.
  * La primera posición del vector la ocupa el término en el idioma origen, las restantes son las traducciones del mismo.
  */
		string* Terminos();
	
/**
  * @brief Tamaño de la palabra
  * @return Devuelve el número de términos de la palabra, contando tanto el término en el idioma origen
  * como los términos de su traducción.
  */
		const int Tamanio();

/**
  * @brief Operador de asignación del TDA palabra
  * @param original Palabra que va a ser copiada
  * @return Devuelve la nueva palabra para poder encadenar asignaciones
  */
	 	palabra& operator=(const palabra &original);
		
};

#endif
