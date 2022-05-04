#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

long long INF = 2e18;
int cantEspadas;
int n = 0;

long long hercules(long long H, vector<int> &c, vector<int> &d, vector<int> &r, vector<int> &e, vector<int> &u) {
    n = c.size();
    vector<pair<int,int> > ordenar (n);

    for (int i = 0; i < n; i++) {
        ordenar[i] = make_pair(-d[i] + r[i], i);
    }

    long long estadoActual = H;
    long long respuesta = 0;
    sort(ordenar.begin(), ordenar.end());

    for (auto a: ordenar) {
        int i, dif;
        tie (i, dif) = a;

        ll mustEnd = max(estadoActual, ll(r[i]));
        ll candVeces = ll(dif)+(mustEnd-1)/mustEnd;

        if (candVeces < c[i]) {
            respuesta += candVeces;
            return respuesta;
        }
        else respuesta += ll(c[i]);
        
        
    }
    if (estadoActual == 0) return respuesta;
    else return -1;
}
