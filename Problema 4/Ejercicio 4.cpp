/*

4) Para un programa en un lenguaje L, dado un cadena C escrito en L, muestre y cuente la ocurrencia de la palabra E en C.

*/
#include <iostream> 
#include <string>   
#include <vector> 


using namespace std;


int main ()
{
string cadenaC;
string palabraE;
int cont = 0;
vector<size_t> posiciones; 



 cout << "Introduce la cadena de texto completa (C):"<<endl;
 getline(cin, cadenaC);
 
 
 cout << "Introduce la palabra a buscar (E):"<<endl;
 cin >> palabraE;
 
 
 
if (palabraE.empty()) {
        cerr << "Error: La palabra a buscar (E) no puede estar vacia." << endl;
        return 1; // Termina el programa con un código de error
}


cout << "\nBuscando '" << palabraE << "' en '" << cadenaC << "'..." << endl;


 size_t pos = cadenaC.find(palabraE, 0);

   while (pos != string::npos) {
        // Se encontró la palabra
        cont++; // Incrementa el contador
        posiciones.push_back(pos); // Guarda la posición encontrada

        // Prepara la siguiente búsqueda
        pos = cadenaC.find(palabraE, pos + 1);
    }



     if (cont > 0) {
        cout << "\nSe encontro la palabra '" << palabraE << "' en las siguientes posiciones (indice base 0):" << endl;
   
        for (size_t p : posiciones) {
            cout << "- Posicion: " << p << endl;
        }
        cout << "\nTotal de ocurrencias encontradas: " << cont << endl;
    } else {
        cout << "\nLa palabra '" << palabraE << "' no se encontro en la cadena." << endl;
    }

return 0; 	

}