#define forn(i,n) for(int i=0;i<(int)(n);i++)
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>


using namespace std;

typedef long long ll;

ll cuentitaFinal (ll H, ll )

long long hercules(long long H, vector<int> &c, vector<int> &d, vector<int> &r, vector<int> &e, vector<int> &u) {

    int n = c.size();
    ll actual = H, cantidad = 0;

    // Guardo en el set el r mas grande de las que ya saque, d mas grande que no usé
    multiset<int> before, after;
    vector<pair<int,int>> dif (n);

    forn (i,n) {
        dif[i] = make_pair(d[i] - r[i], i);
        after.insert(d[i]);
    }
    sort(dif.rbegin(), dif.rend());

    for (auto &e: dif) {
        cout << actual << " " << e.first << " " << e.second << " " << c[e.second] << endl;
        int i = e.second;
        actual -= (e.first * c[i]);

        before.insert(r[i]);
        after.erase(after.find(d[i]));

        if (actual <= 0) {

            return cantidad;
        }
        if (actual - *(before.end()) <= 0) return cantidad;
        if (actual - *(after.begin()) <= 0) return cantidad+1;
                cantidad += c[i];
    }

    return -1;
} 
