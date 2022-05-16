#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> arbol;

bool compareTree (int leave1, int leave2) {

    if (arbol[leave1].empty()) return false;
    if (arbol[leave2].empty()) return true;
    
    int size = int(min(arbol[leave1].size(), arbol[leave2].size()));
    for (int i = 0; i < size; i++) {

    }

    if (recursionIzquierda.empty()) return true;
    else return false;
}

void ordenarArbol (int actual) {
    for (auto a: arbol[actual]) {
        ordenarArbol(a);
    }

    sort(arbol.begin(), arbol.end(), compareTree);
}

string minarbol(string &s) {

    n = s.size();

    // Reconstrucción del arbol
    
    stack<int> stack;
    int counter = 0;
    stack.push(0);

    for (int i = 1; i < n; i++) {
        if (s[i] == '(') {
            counter++;
            arbol.push_back(vector<int>());
            arbol[stack.top()].push_back(counter);
            stack.push(counter);
        } else {
            stack.pop();
        }
    }

    // Fin reconstrucción arbol


}
