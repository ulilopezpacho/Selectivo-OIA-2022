#include <iostream>
#include <string>
#include <vector>
#include "pociones.cpp"

using namespace std;

string pociones(vector<string> &tablita, string &hilera, vector<int> &combinaciones);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string hilera;
    cin >> hilera;
    vector<string> tablita;
    tablita.resize(10);
    for (int i0 = 0; i0 < 10; i0++) {
        cin >> tablita[i0];
    }
    vector<int> combinaciones;
    combinaciones.resize(0);
    string returnedValue;
    returnedValue = pociones(tablita, hilera, combinaciones);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(combinaciones.size()); i++) {
        if (i > 0) cout << " ";
        cout << combinaciones[i];
    }
    cout << "\n";
    return 0;
}
