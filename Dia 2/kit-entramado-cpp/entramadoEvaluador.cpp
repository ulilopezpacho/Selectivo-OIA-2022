#include <iostream>
#include <string>
#include <vector>
#include "entramado.cpp"

using namespace std;

void entramado(int n, int m, int l, int k, vector<int> &a, vector<int> &b, vector<int> &compuertas);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    cin >> m;
    int l;
    cin >> l;
    int k;
    cin >> k;
    vector<int> a;
    a.resize(0);
    vector<int> b;
    b.resize(0);
    vector<int> compuertas;
    compuertas.resize(0);
    entramado(n, m, l, k, a, b, compuertas);
    for (int i = 0; i < int(a.size()); i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    for (int i = 0; i < int(b.size()); i++) {
        if (i > 0) cout << " ";
        cout << b[i];
    }
    cout << "\n";
    for (int i = 0; i < int(compuertas.size()); i++) {
        if (i > 0) cout << " ";
        cout << compuertas[i];
    }
    cout << "\n";
    return 0;
}
