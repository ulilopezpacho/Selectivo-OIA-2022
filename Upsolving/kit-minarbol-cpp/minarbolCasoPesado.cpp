#include <fstream>

using namespace std;

int main () {
    const int cantidad = 250000;
    ofstream out ("minarbolExtremo.in");
    for (int i = 0; i < cantidad; i++) out << "(";
    for (int i = 0; i < cantidad; i++) out << ")";
}