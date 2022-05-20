#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

const int cantPociones = 10;

vector<vector<char>> ranguitos;
queue<pair<int,int>> rangosAProcesar;
vector<vector<vector<int>>> rangosQueTerminan;
vector<vector<vector<int>>> rangosQueEmpiezan;

string pociones(vector<string> &tablita, string &hilera, vector<int> &combinaciones) {
    int n = int(hilera.size());

    ranguitos.resize(n, vector<char>(n, '.'));
    rangosQueTerminan.resize(n, vector<vector<int>> (10));
    rangosQueEmpiezan.resize(n, vector<vector<int>> (10));

    forn (i, n) {
        ranguitos[i][i] = hilera[i];
        rangosAProcesar.push({i,i});
        rangosQueTerminan[i][int(hilera[i]-'a')].push_back(i);
    }

    while (!rangosAProcesar.empty()) {
        int left, right;
        tie(left, right) = rangosAProcesar.front(); rangosAProcesar.pop();
        //cerr << left << " " << right << endl;
        char pocionActual = ranguitos[left][right];
        int numPocionActual = int(pocionActual - 'a');

        //cerr << "Combinaciones: " << endl;
        if (left > 0) {
            for (int i = 0; i < cantPociones; i++) {
                char combinacion = tablita[i][numPocionActual];
                if (tablita[i][numPocionActual] == '.') continue;
                //cerr << "Si " << char(i+'a') << endl;

                for (int finalTerminado : rangosQueTerminan[left-1][i]) {
                    //cerr << finalTerminado << " " << right << endl;
                    if (ranguitos[finalTerminado][right] != '.') return "PELIGROSA";
                    ranguitos[finalTerminado][right] = combinacion;
                    rangosQueTerminan[right][int(combinacion - 'a')].push_back(finalTerminado);
                    rangosAProcesar.push({finalTerminado, right});
                }
            }
        }
    }

    return "SEGURA";
}
