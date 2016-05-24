#include "traductor.h"
#include "palabra.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con las traducciones"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   cout << "voy a crear traductor"<< endl ;
   traductor T;
   cout << "voy a cargar el traductor"<< endl ;
   f>>T; //Cargamos en memoria, en el traductor.
   
   string a;
   cout<<"Dime una palabra en el idioma origen:";
   getline(cin,a);
   
   int nacep=0;
  string* trads=T.GetTraduccion(a,nacep);
   
   
   /* Escrbimos*/
   cout<<a<<"-->";
   for (int i=0;i<nacep; ++i)
     cout<<trads[i]<<';';
   cout<<endl;
   
   
   



}
