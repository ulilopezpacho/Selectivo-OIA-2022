#include <iostream>
#include <string>
#include <vector>
#include "hercules.cpp"

using namespace std;

long long hercules(long long H, vector<int> &c, vector<int> &d, vector<int> &r, vector<int> &e, vector<int> &u);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    long long H;
    cin >> H;
    vector<int> c;
    vector<int> d;
    vector<int> r;
    c.resize(N);
    d.resize(N);
    r.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        cin >> d[i];
        cin >> r[i];
    }
    vector<int> e;
    e.resize(0);
    vector<int> u;
    u.resize(0);
    long long returnedValue;
    returnedValue = hercules(H,c,d,r,e,u);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(e.size()); i++) {
        if (i > 0) cout << " ";
        cout << e[i];
    }
    cout << "\n";
    for (int i = 0; i < int(u.size()); i++) {
        if (i > 0) cout << " ";
        cout << u[i];
    }
    cout << "\n";
    return 0;
}
