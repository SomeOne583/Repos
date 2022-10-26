#include <iostream>
#include <vector>

using namespace std;

int main() {
        int c, index;
        string linea;
        vector<string> finds, replaces;

        while (cin >> c && c != 0) {
                finds.clear();
                replaces.clear();
                getline(cin, linea);
                for (int i = 0; i < c; i++) {
                        getline(cin, linea);
                        finds.push_back(linea);
                        getline(cin, linea);
                        replaces.push_back(linea);
                }
                getline(cin, linea);
                for (int i = 0; i < c; i++) {
                        while (linea.find(finds[i]) != string::npos) {
                                index = linea.find(finds[i]);
                                linea.replace(index, finds[i].size(), replaces[i]);
                        }
                }
                cout << linea << endl;
        }
        
        return 0;
}
