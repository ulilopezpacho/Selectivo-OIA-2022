#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define fornr(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define forall(i,a) for(__typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define uniquec(c) (c).resize(unique(all(c))-(c).begin())
#define clr(a,x) memset(a,x,sizeof(a)))

#include <string>
#include <vector>

using namespace std;

int nGlobal, mGlobal;

int getNumeroCompuerta (int i, int j) {
    return i * mGlobal + j;
}

void entramado(int n, int m, int l, int k, vector<int> &a, vector<int> &b, vector<int> &compuertas) {

    nGlobal = n;
    mGlobal = m;

    int compuertaLibre = nGlobal * mGlobal;

    vector<vector<int>> padresPorFila (n, vector<int> (m, -1));
    vector<vector<int>> padresPorFilaInv (n, vector<int> (m, -1));
    vector<vector<int>> representativo (n, vector<int> (m, -1));

    forn (i,n) {
        forn (j,m) {
            padresPorFila[i][j] = getNumeroCompuerta(i,j);
            padresPorFilaInv[i][j] = padresPorFila[i][j];
        }
    }

    forn (i,nGlobal) {
        for (int it = 0; it < mGlobal; it += k) {
            for (int j = it + 1; j < min(it + k, mGlobal); j++) {
                a.push_back(padresPorFila[i][j-1]);
                b.push_back(padresPorFila[i][j]);
                padresPorFila[i][j] = compuertaLibre++;
            }

            for (int j = min(it + k - 2, mGlobal-2); j >= it; j--) {
                a.push_back(padresPorFilaInv[i][j+1]);
                b.push_back(padresPorFilaInv[i][j]);
                padresPorFilaInv[i][j] = compuertaLibre++;
            }
        }

        for (int j = 0; j <= mGlobal - k; j++) {
            if (j % k == 0) {
                representativo[i][j] = padresPorFilaInv[i][j];
                continue;
            }
            a.push_back(padresPorFilaInv[i][j]);
            b.push_back(padresPorFila[i][j+k-1]);
            representativo[i][j] = compuertaLibre++;
        }
    }

    padresPorFila = representativo;
    padresPorFilaInv = representativo;

    for (int j = 0; j <= mGlobal - k; j++) {
        for (int it = 0; it < nGlobal; it += l) {
            for (int i = it + 1; i < min(it + l, nGlobal); i++) {
                a.push_back(padresPorFila[i-1][j]);
                b.push_back(padresPorFila[i][j]);
                padresPorFila[i][j] = compuertaLibre++;
            }

            for (int i = min(it + l - 2, nGlobal-2); i >= it; i--) {
                a.push_back(padresPorFilaInv[i+1][j]);
                b.push_back(padresPorFilaInv[i][j]);
                padresPorFilaInv[i][j] = compuertaLibre++;
            }
        }
    }

    for (int i = 0; i <= nGlobal - l; i++) {
        for (int j = 0; j <= mGlobal - k; j++) {
            if (i % l == 0) {
                representativo[i][j] = padresPorFilaInv[i][j];
                compuertas.push_back(representativo[i][j]);
                continue;
            }
            a.push_back(padresPorFilaInv[i][j]);
            b.push_back(padresPorFila[i+l-1][j]);
            representativo[i][j] = compuertaLibre++;
            compuertas.push_back(representativo[i][j]);
        }
    }
}
