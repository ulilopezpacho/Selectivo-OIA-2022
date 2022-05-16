#include <iostream>
#include <string>
#include <vector>

using namespace std;

string minarbol(string &s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string returnedValue;
    returnedValue = minarbol(s);
    cout << returnedValue << "\n";
    return 0;
}
