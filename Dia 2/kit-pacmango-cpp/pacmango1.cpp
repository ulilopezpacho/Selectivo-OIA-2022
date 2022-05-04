#include <string>
#include <vector>
#include <queue>
#include <utility>

#define forn(i, n) for (int i = 0; i < n; i++)

using namespace std;
vector<int> ady[100001];
vector<bool> ghostVisited;
vector<int> pacManVisited;

int n = 0, m;

int pacmango(vector<int> &a, vector<int> & b, int P, int S, vector<int> &F, vector<int> &movimientos) {
    
    m = int(a.size());

    forn (i, m) {
        ady[a[i]].push_back(b[i]);
        ady[b[i]].push_back(a[i]);
        n = max(n, a[i]);
        n = max(n, b[i]);
    }

    ghostVisited.resize(n + 1);
    pacManVisited.resize(n + 1, -1);

    pair<queue<int>, queue<int> > nextPacMan, nextGhost;
    
    nextPacMan.first.push(P);
    pacManVisited[P] = 0;

    for (auto a: F) {
        nextGhost.first.push(a);
        ghostVisited[a] = true;
    }

    int totalGhostCovered = 1;
    int turn = 0;
    int worstResult = 0;
    bool isPacmanTurn = false;
    
    while (totalGhostCovered < n) {

        if (isPacmanTurn) {
            turn++;
            while (!nextPacMan.first.empty()) {

                int actual = nextPacMan.first.front();
                nextPacMan.first.pop();
                if (actual == S) continue;

                for (auto next: ady[actual]) {
                    if (ghostVisited[next] || pacManVisited[next] == actual) continue;
                    pacManVisited[next] = turn;
                    nextPacMan.second.push(next);
                }
                
                if (!ghostVisited[actual]) {
                    pacManVisited[actual] = turn;
                    worstResult = max(worstResult, turn);
                    nextPacMan.second.push(actual);
                }

                cout << "PACMAN: " << actual << " " << pacManVisited[actual] << endl;
            }
            
            swap(nextPacMan.first, nextPacMan.second);
            isPacmanTurn = false;
        
        } else {

            while (!nextGhost.first.empty()) {
                int actual = nextGhost.first.front();
                nextGhost.first.pop();

                for (auto next: ady[actual]) {
                    if (ghostVisited[next]) continue;
                    totalGhostCovered++;
                    cout << totalGhostCovered << " " << n;
                    ghostVisited[next] = true;
                    nextGhost.second.push(next);
                }

            }
            
            swap(nextGhost.first, nextGhost.second);
            isPacmanTurn = true;
        }
    }

    if (pacManVisited[S] == -1) return worstResult;
    else return pacManVisited[S];
}
