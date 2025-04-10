/*

2) Dado un número entero no negativo n, 
a) genere los coeficientes del polinomio (x+1)n, muestre el resultado de polinomio y 
b) muestre por pasos el cálculo para x dado, f(x) = (x+1)n ,según el polinomio generado.

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Función para generar el vector de coeficientes de (x+1)ⁿ utilizando la fórmula de Pascal
vector<long long> generarCoeficientes(int n) {
    vector<long long> coef(n + 1, 0);
    coef[0] = 1; // El primer coeficiente siempre es 1

    // Se utiliza la relación recursiva para el triángulo de Pascal:
    // C(n, k) = C(n, k-1) * (n - k + 1) / k
    for (int k = 1; k <= n; k++) {
        coef[k] = coef[k - 1] * (n - k + 1) / k;
    }
    return coef;
}

// Función para mostrar el polinomio (x+1)ⁿ en forma extendida
void mostrarPolinomio(int n, const vector<long long>& coef) {
    cout << "(x+1)^" << n << " = ";
    // Recorremos de mayor a menor exponente para obtener el formato:
    // x^n + coef[n-1]*x^(n-1) + ... + coef[1]*x + coef[0]
    for (int i = n; i >= 0; i--) {
        long long c = coef[n - i]; // Observa: coef[0] corresponde a x^n y coef[n] a x^0
        // Si el coeficiente es mayor a 0 y no es el primer término, se agrega " + "
        if (i != n)
            cout << " + ";
        
        // Mostramos el coeficiente solo si es distinto de 1 o el exponente es 0
        if (c != 1 || i == 0)
            cout << c;

        if (i >= 2) // Cuando el exponente es mayor o igual a 2, mostramos x^i
            cout << "x^" << i;
        else if (i == 1) // Exponente 1 solamente muestra "x"
            cout << "x";
    }
    cout << "\n";
}

// Función para evaluar el polinomio f(x) = (x+1)ⁿ usando los coeficientes
// y mostrar paso a paso el cálculo.
void evaluarPolinomio(int n, const vector<long long>& coef, double x) {
    double resultado = 0.0;
    cout << "\nEvaluacion de f(" << x << ") = (x+1)^" << n << ":\n";

    // Seguimos el mismo orden que al mostrar: de x^n a x^0
    for (int i = n; i >= 0; i--) {
        long long c = coef[n - i]; // coeficiente correspondiente
        double potencia = pow(x, i);
        double termino = c * potencia;
        
        // Mostrar detalle del cálculo de cada término:
        cout << "Termino para x^" << i << ": ";
        if (c != 1 || i == 0)
            cout << c << " * ";
        cout << "(" << x << ")^" << i << " = " << c << " * " << potencia << " = " << termino << "\n";
        
        resultado += termino;
    }
    cout << "Suma total = " << resultado << "\n";
}

int main() {
    int n;
    double x;

    // Parte A: Generación del polinomio (x+1)^n
    cout << "Ingrese un numero entero no negativo para n: ";
    cin >> n;

    if(n < 0) {
        cout << "El numero debe ser no negativo.\n";
        return 1;
    }

    // Generar los coeficientes usando el triángulo de Pascal
    vector<long long> coeficientes = generarCoeficientes(n);

    // Mostrar el polinomio en forma extendida
    mostrarPolinomio(n, coeficientes);

    // Parte B: Evaluación del polinomio para un valor x dado
    cout << "\nIngrese un valor para x: ";
    cin >> x;
    evaluarPolinomio(n, coeficientes, x);

    return 0;
}
