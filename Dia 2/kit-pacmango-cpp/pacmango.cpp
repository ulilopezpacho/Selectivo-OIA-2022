#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <unordered_map>
#include <iostream>
#include <tuple>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < n; i++)

using namespace std;
vector<int> ady[100002];
vector<bool> ghostVisited;
vector<int> pacManVisited;

unordered_map<int,int> anteriores [100002];
int n = 0, m;

int pacmango(vector<int> &a, vector<int> & b, int P, int S, vector<int> &F, vector<int> &movimientos) {
    
    m = int(a.size());

    forn (i, m) {
        ady[a[i]].push_back(b[i]);
        ady[b[i]].push_back(a[i]);
        n = max(n, a[i]);
        n = max(n, b[i]);
    }
    
    forn (i, n) ady[i+1].push_back(i+1);
    queue<tuple<bool, int, int>> process;
    bool anterior = false;
    int paso = 0, last = -1;

    ghostVisited.resize(n + 1, false);
    pacManVisited.resize(n + 1, -1);

    process.push(make_tuple(true, P, 0));
    pacManVisited[P] = 0;

    for (auto a: F) {
        process.push(make_tuple(false, a, -1));
        ghostVisited[a] = true;
    }

    while (!process.empty()) {

        bool esPacMan; int nodo, step;
        tie(esPacMan, nodo, step) = process.front();
        process.pop();
        //cout << (esPacMan? "Pacman": "Fantasma") << " " << nodo << " " << step << endl;

        if (esPacMan && nodo != S) {
            if (ghostVisited[nodo]) continue;
            for (int siguiente: ady[nodo]) {

                if (ghostVisited[siguiente] || pacManVisited[siguiente] == step+1) continue;
                pacManVisited[siguiente] = step + 1;

                //Backtracing
                anteriores[siguiente].insert({step+1, nodo});
                paso = step + 1;
                last = siguiente;

                process.push(make_tuple(true, siguiente, step+1));

            }
        } else if (!esPacMan) {
            for (int siguiente: ady[nodo]) {
                if (ghostVisited[siguiente]) continue;
                ghostVisited[siguiente] = true;
                process.push(make_tuple(false, siguiente, -1));
            }
        }
    }

    int backtracing = S, backtracingStep = pacManVisited[S];
    if (pacManVisited[S] == -1) {
        backtracing = last;
        backtracingStep = paso;
    }
    //cout << pacManVisited[S] << endl;

    while (backtracingStep > 0) {
        //cout << backtracing << " " << backtracingStep << " " << paso << endl;
        //for (auto a: anteriores[backtracing]) cout << "(" << a.first <<", " << a.second << ") ";
        //cout << endl;
        movimientos.push_back(backtracing);
        backtracing = anteriores[backtracing][backtracingStep];
        backtracingStep--;
    }

    reverse(movimientos.begin(), movimientos.end());

    if (pacManVisited[S] == -1) return paso;
    else return pacManVisited[S];
}
