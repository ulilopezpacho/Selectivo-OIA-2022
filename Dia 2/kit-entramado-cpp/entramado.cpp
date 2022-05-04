#include <string>
#include <vector>

using namespace std;

void entramado(int n, int m, int l, int k, vector<int> &a, vector<int> &b, vector<int> &compuertas) {
    
    int nuevoNodo = n * m;
    int cantidad = k;

    if (n == 1) {
        for (int i = 0; i < (m - k + 1); i++) {
            int end = i + k;
            vector<int> casoActual, casoActualSiguiente;

            for (int j = i; j < end; j++) {
                casoActual.push_back(j);
            }

            while (casoActual.size() > 1) {
                for (int ac = 0; ac < casoActual.size(); ac += 2) {
                    casoActualSiguiente.push_back(nuevoNodo);

                    if (ac == casoActual.size() - 1) {
                        a.push_back(casoActual[ac-1]);
                        b.push_back(casoActual[ac]);
                    } else {
                        a.push_back(casoActual[ac]);
                        b.push_back(casoActual[ac+1]);
                    }

                    nuevoNodo++;
                }
                casoActual.clear();
                swap(casoActual, casoActualSiguiente);
            }

            compuertas.push_back(nuevoNodo-1);
        }
    }
}
