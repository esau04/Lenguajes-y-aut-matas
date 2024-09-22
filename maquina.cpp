#include <iostream>
#include <string>

using namespace std;

enum State {q0, q1, q2};

bool procesarPalabra(const string& palabra) {
    State estadoActual = q0;  

    for (size_t i = 0; i < palabra.length(); ++i) {
        char c = palabra[i];
        switch (estadoActual) {
            case q0:
                if (c == 'a') {
                    estadoActual = q1;  
                } else if (c == 'b') {
                    estadoActual = q2;  
                } else {
                    return false;  
                }
                break;
            case q1:
                if (c == 'a') {
                    estadoActual = q1;  
                } else if (c == 'b') {
                    estadoActual = q1;  
                } else {
                    return false;  
                }
                break;
            case q2:
                if (c == 'a') {
                    return false;  
                } else if (c == 'b') {
                    estadoActual = q2; 
                } else {
                    return false;  
                }
                break;
        }
    }
    return (estadoActual == q1 || estadoActual == q2);
}

int main() {
    string palabra;

    cout << "Ingrese una palabra compuesta por 'a' y 'b': ";
    cin >> palabra;

    if (procesarPalabra(palabra)) {
        cout << "Palabra aceptada." << endl;
    } else {
        cout << "Palabra no aceptada." << endl;
    }

    return 0;
}



