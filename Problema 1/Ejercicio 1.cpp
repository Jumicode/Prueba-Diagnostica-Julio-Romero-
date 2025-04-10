
/*

1) Dado una cadena C, valide si C se encuentra en notación FEN (Forsyth-Edwards Notation), Forsyth–Edwards Notation. 
FEN es un sistema estándar para describir posiciones específicas en partidas de ajedrez, permitiendo reiniciar el juego desde una posición dada.
Desarrollado inicialmente por David Forsyth y ampliado por Steven J. Edwards,
FEN se utiliza en la Notación de Juego Portátil para definir posiciones iniciales distintas a la estándar

*/



#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include <set>
using namespace std;

// Función para dividir la cadena usando un delimitador
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string token;
    istringstream ss(s);
    while(getline(ss, token, delim)) {
        elems.push_back(token);
    }
    return elems;
}

// Valida el primer campo: disposición de piezas
bool validarDisposicion(const string &campo) {
    // Dividimos por '/' para obtener las 8 filas
    vector<string> filas = split(campo, '/');
    if (filas.size() != 8) return false;

    for (const string &fila : filas) {
        int suma = 0;
        for (char c : fila) {
            if (isdigit(c)) {
                int valor = c - '0';
                if (valor < 1 || valor > 8) return false;
                suma += valor;
            } else {
                // Las piezas válidas: minúsculas y mayúsculas (p, r, n, b, q, k)
                if (string("prnbqkPRNBQK").find(c) == string::npos) return false;
                suma += 1;
            }
        }
        if (suma != 8) return false;
    }
    return true;
}

// Valida el campo del color activo
bool validarColorActivo(const string &campo) {
    return (campo == "w" || campo == "b");
}

// Valida el campo de derechos de enroque
bool validarEnroque(const string &campo) {
    if (campo == "-")
        return true;
    set<char> permitidos = {'K','Q','k','q'};
    for (char c : campo) {
        if (permitidos.find(c) == permitidos.end())
            return false;
    }
    return true;
}

// Valida el campo en passant
bool validarEnPassant(const string &campo) {
    if (campo == "-") return true;
    // Debe tener longitud 2: una letra de a a h y un dígito (generalmente 3 o 6, pero se valida formato general)
    if (campo.length() != 2) return false;
    char file = campo[0];
    char rank = campo[1];
    if (file < 'a' || file > 'h') return false;
    if (!isdigit(rank)) return false; // el dígito
    // Aunque se podría restringir el dígito a 3 o 6, aquí validamos de forma general
    return true;
}

// Valida el campo del medio movimiento (halfmove clock)
bool validarMedioMovimiento(const string &campo) {
    // Debe ser un número entero no negativo
    for (char c : campo) {
        if (!isdigit(c)) return false;
    }
    // Convertir a entero y validar que sea >= 0 (ya que es no negativo)
    // Si el campo es "0" o cualquier número, es válido.
    return true;
}

// Valida el campo del número de movimiento completo (fullmove number)
bool validarNumeroMovimiento(const string &campo) {
    // Debe ser un número entero positivo
    for (char c : campo) {
        if (!isdigit(c)) return false;
    }
    // Convertir a entero y asegurarse de que sea >= 1
    int num = stoi(campo);
    return (num >= 1);
}

// Función principal que valida la cadena FEN
bool esFENValido(const string &fen) {
    vector<string> campos = split(fen, ' ');
    if (campos.size() != 6)
        return false;
    
    if (!validarDisposicion(campos[0])) return false;
    if (!validarColorActivo(campos[1])) return false;
    if (!validarEnroque(campos[2])) return false;
    if (!validarEnPassant(campos[3])) return false;
    if (!validarMedioMovimiento(campos[4])) return false;
    if (!validarNumeroMovimiento(campos[5])) return false;
    
    return true;
}

int main() {
    string fen;
    
    cout << "Ingrese la cadena FEN: ";
    getline(cin, fen);
    
    if (esFENValido(fen))
        cout << "La cadena FEN es valida.\n";
    else
        cout << "La cadena FEN no es valida.\n";
    
    return 0;
}
