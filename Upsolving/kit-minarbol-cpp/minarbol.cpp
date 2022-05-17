#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>

using namespace std;

int n;
vector<int> arbol [250001];
string resultado = "";

int compareTreeInterno (int leave1, int leave2) {
    int izquierda = arbol[leave1].size();
    int derecha = arbol[leave2].size();

    for (int i = 0; i < min(izquierda, derecha); i++) {
        int siguienteIzquierda = arbol[leave1][i];
        int siguienteDerecha = arbol[leave2][i];

        int result = compareTreeInterno(siguienteIzquierda, siguienteDerecha);
        if (result != 0) return result;
    }

    if (izquierda == derecha) return 0;
    if (izquierda > derecha) return -1;
    if (izquierda < derecha) return 1;
}

bool compareTree (int leave1, int leave2) {
    int comparacion = compareTreeInterno(leave1, leave2);
    if (comparacion == -1) return true;
    if (comparacion == 1) return false;
    return false;
}

void ordenarArbol (int actual) {
    for (auto a: arbol[actual]) {
        ordenarArbol(a);
    }

    sort(arbol[actual].begin(), arbol[actual].end(), compareTree);
}

void generateString (int actual) {
    resultado += '(';
    for (int a: arbol[actual]) {
        generateString(a);
    }
    resultado += ')';
}

string minarbol(string &s) {

    n = s.size();

    stack<int> stack;
    int counter = 0;

    stack.push(0);

    for (int i = 1; i < n; i++) {
        if (s[i] == '(') {
            counter++;
            arbol[stack.top()].push_back(counter);
            stack.push(counter);
        } else {
            stack.pop();
        }
    }

    ordenarArbol(0);
    generateString(0);
    return resultado;
}
