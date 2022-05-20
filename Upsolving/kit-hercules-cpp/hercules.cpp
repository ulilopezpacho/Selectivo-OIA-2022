#define forn(i,n) for(int i=0;i<(int)(n);i++)
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

typedef long long ll;

ll calcularCortes (ll actual, ll d, ll r, ll c) {
    actual -= d;
    return min(((actual + (d-r-1)) / (d-r)) + 1, c);
}

long long hercules(long long H, vector<int> &c, vector<int> &d, vector<int> &r, vector<int> &e, vector<int> &u) {

    int n = int(c.size());
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

        const int i = element.second;
        ll cortes = calcularCortes(actual, d[i], r[i], c[i]);
        assert(cortes <= c[i]);
        cantidad += cortes;
        
        e.push_back(i);
        u.push_back(int(cortes));
        elementoALista.insert({i, lap});
        after.erase(after.find(d[i]));

        const ll cabezasRemovidas = element.first * cortes;
        if ((cortes < c[i]) || (cabezasRemovidas >= (actual - r[i]))) return cantidad;

        assert(cortes == ll(c[i]));
        actual -= cabezasRemovidas;

        pair<int,int> beforeActual, afterActual;
        if (!before.empty()) beforeActual = *(before.end());
        if (!after.empty()) afterActual = *(after.end());
    
        if (!before.empty() && (actual - beforeActual.first) <= 0) {
            const int ubicacionE = elementoALista[beforeActual.second];
            if ((--e[ubicacionE]) <= 0) {
                e.erase(e.begin() + ubicacionE);
                u.erase(u.end() + ubicacionE);
                cantidad--;
            }
            e.push_back(beforeActual.second);
            u.push_back(1);
            return cantidad;
        }

        if (!after.empty() && (actual - afterActual.first) <= 0) {
            e.push_back(afterActual.second);
            u.push_back(1);
            return cantidad + 1;
        }

        before.insert({r[i], i});
        lap++;
    }

    e.clear();
    u.clear();
    return -1;
} 
