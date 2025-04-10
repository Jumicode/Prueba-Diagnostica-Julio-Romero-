/*

3) implemente la evaluación de expresiones aritméticas considerando los operadores +,-,*,/ 
y los operandos pueden ser ingresados en notación científica (125E25,5E-8 para denotar 12x1025, 5x10-8 respectivamente),
 la entrada al programa será una cadena de caracteres con la expresión, ejemplo de expresión a evaluar: (125E10 – 1e15)/5E-85*15.

*/

#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
using namespace std;

string entrada;
size_t pos = 0;

// Función que salta los espacios en blanco en la entrada.
void saltarEspacios() {
    while (pos < entrada.size() && isspace(entrada[pos])) {
        pos++;
    }
}

// Función que analiza un número (incluyendo notación científica)
// Ejemplos válidos: 125, -12.5, +3.4, 125E10, 5e-8, etc.
double analizarNumero() {
    saltarEspacios();
    size_t inicio = pos;
    
    // Opcional: signo inicial
    if (pos < entrada.size() && (entrada[pos] == '+' || entrada[pos] == '-')) {
        pos++;
    }
    
    // Parte entera y/o decimal
    bool hayPunto = false;
    while (pos < entrada.size() && (isdigit(entrada[pos]) || entrada[pos] == '.')) {
        if (entrada[pos] == '.') {
            if (hayPunto)
                break; // Solo se permite un punto decimal.
            hayPunto = true;
        }
        pos++;
    }
    
    // Parte del exponente (opcional)
    if (pos < entrada.size() && (entrada[pos] == 'E' || entrada[pos] == 'e')) {
        pos++;  // Consumir 'E' o 'e'
        // Signo opcional en el exponente
        if (pos < entrada.size() && (entrada[pos] == '+' || entrada[pos] == '-')) {
            pos++;
        }
        // Debe haber al menos un dígito en el exponente
        if (pos >= entrada.size() || !isdigit(entrada[pos])) {
            throw runtime_error("Formato de exponente inválido en numero");
        }
        while (pos < entrada.size() && isdigit(entrada[pos])) {
            pos++;
        }
    }
    
    string numStr = entrada.substr(inicio, pos - inicio);
    try {
        return stod(numStr);
    } catch(const exception &e) {
        throw runtime_error("Error al convertir el numero: " + numStr);
    }
}

// Prototipos de funciones recursivas.
double analizarExpresion();
double analizarTermino();
double analizarFactor();

// Función que analiza un factor: un número o una expresión entre paréntesis.
double analizarFactor() {
    saltarEspacios();
    if (pos < entrada.size() && entrada[pos] == '(') {
        pos++;  // consumir '('
        double valor = analizarExpresion();
        saltarEspacios();
        if (pos >= entrada.size() || entrada[pos] != ')')
            throw runtime_error("Falta ')' en la expresion");
        pos++;  // consumir ')'
        return valor;
    }
    // Se espera un número.
    return analizarNumero();
}

// Función que analiza un término: maneja multiplicación y división.
double analizarTermino() {
    double valor = analizarFactor();
    while (true) {
        saltarEspacios();
        if (pos < entrada.size() && entrada[pos] == '*') {
            pos++;  // consumir '*'
            double factor = analizarFactor();
            valor *= factor;
        } else if (pos < entrada.size() && entrada[pos] == '/') {
            pos++;  // consumir '/'
            double divisor = analizarFactor();
            if (divisor == 0)
                throw runtime_error("Division por cero");
            valor /= divisor;
        } else {
            break;
        }
    }
    return valor;
}

// Función que analiza la expresión: maneja suma y resta.
double analizarExpresion() {
    double valor = analizarTermino();
    while (true) {
        saltarEspacios();
        if (pos < entrada.size() && entrada[pos] == '+') {
            pos++;  // consumir '+'
            valor += analizarTermino();
        } else if (pos < entrada.size() && entrada[pos] == '-') {
            pos++;  // consumir '-'
            valor -= analizarTermino();
        } else {
            break;
        }
    }
    return valor;
}

int main() {
    cout << "Ingrese una expresion a evaluar :\n";
    getline(cin, entrada);

    try {
        pos = 0;
        double resultado = analizarExpresion();
        saltarEspacios();
        if (pos != entrada.size())
            throw runtime_error("Caracteres inesperados al final de la expresion");
        cout << "El resultado es: " << resultado << "\n";
    } catch(const exception &e) {
        cerr << "Error: " << e.what() << "\n";
    }
    
    return 0;
}
