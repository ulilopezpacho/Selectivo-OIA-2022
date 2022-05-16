#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pacmango(vector<int> &a, vector<int> & b, int P, int S, vector<int> &F, vector<int> &movimientos);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int M;
    cin >> M;
    int K;
    cin >> K;
    int P;
    cin >> P;
    int S;
    cin >> S;
    vector<int> F;
    F.resize(K);
    for (int i0 = 0; i0 < K; i0++) {
        cin >> F[i0];
    }
    vector<int> a;
    vector<int> b;
    a.resize(M);
    b.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
        cin >> b[i];
    }
    vector<int> movimientos;
    movimientos.resize(0);
    int returnedValue;
    returnedValue = pacmango(a,b,P,S,F,movimientos);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(movimientos.size()); i++) {
        if (i > 0) cout << " ";
        cout << movimientos[i];
    }
    cout << "\n";
    return 0;
}
