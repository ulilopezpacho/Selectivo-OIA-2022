#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
typedef long long ll;

map<long long, long long> DP;

long long INF = 2e18;
int cantEspadas;

long long hercules(long long H, vector<int> &c, vector<int> &d, vector<int> &r, vector<int> &e, vector<int> &u) {
    DP[H] = 0LL;
    cantEspadas = int(c.size());

    for (int i = 0; i < cantEspadas; i++) {
        map<long long, long long> newDP = DP;
        ll diferencia = -ll(d[i]) + ll(r[i]);

        for (auto a: DP) {
            for (int j = 1; j <= c[i]; j++) {
                ll temporal = a.first + (diferencia * (j-1)) - ll(d[i]);

                if (temporal <= 0) {
                    newDP[0] = a.second + j;
                    break;
                }

                ll nuevaPosicion = a.first + (diferencia * j);
                newDP[nuevaPosicion] = a.second + j;
            }
        }

        DP = newDP;
    }

    if (DP.count(0) > 0) return DP[0];
    else return -1;
}
