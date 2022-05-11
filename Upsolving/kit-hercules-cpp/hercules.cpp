#define forn(i,n) for(int i=0;i<(int)(n);i++)
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll calcularCortes (ll actual, ll d, ll r, ll c) {
    actual -= d;
    return min(((actual + (d-r-1)) / (d-r)) + 1, c);
}

long long hercules(long long H, vector<int> &c, vector<int> &d, vector<int> &r, vector<int> &e, vector<int> &u) {

    int n = c.size();
    ll actual = H, cantidad = 0;

    // Guardo en el set el r mas grande de las que ya saque, d mas grande que no usé
    multimap<int,int> before, after;
    map<int,int> elementoALista;
    vector<pair<int,int>> dif (n);

    forn (i,n) {
        dif[i] = make_pair(d[i] - r[i], i);
        after.insert({d[i], i});
    }
    sort(dif.rbegin(), dif.rend());

    int lap = 0;

    for (auto &element: dif) {
        //cout << actual << " " << element.first << " " << element.second << " " << c[element.second] << endl;

        const int i = element.second;

        ll cortes = calcularCortes(actual, d[i], r[i], c[i]);
        cantidad += cortes;

        e.push_back(i);
        u.push_back(cortes);

        if (cortes < c[i]) return cantidad;

        assert(cortes == ll(c[i]));
        actual -= element.first * cortes;

        const pair<int,int> beforeActual = *(before.end());
        const pair<int,int> afterActual = *(after.end());

        if ((actual - beforeActual.first) <= 0) {
            e[elementoALista[beforeActual.second]]--;
            e.push_back(beforeActual.second);
            u.push_back(1);
            return cantidad;
        }

        if ((actual - afterActual.first) <= 0) {
            e.push_back(afterActual.second);
            u.push_back(1);
            return ++cantidad;
        }


        before.insert({r[i], i});
        elementoALista.insert({i, lap});
        after.erase(after.find(d[i]));
        lap++;
    }

    return -1;
} 
