#include <iostream>
#include <vector>

using namespace std;

int main() {
        int c, amplitud, picos;
        vector<int> amplitudes;

        while (cin >> c && c != 0) {
                amplitudes.clear();
                while (c--) {
                        cin >> amplitud;
                        amplitudes.push_back(amplitud);
                }
                picos = 0;
                if ((amplitudes.back() > amplitudes[0] && amplitudes[1] > amplitudes[0]) || (amplitudes.back() < amplitudes[0] && amplitudes[1] < amplitudes[0])) {
                        picos++;
                }
                for (int i = 1; i < amplitudes.size() - 1; i++) {
                        if ((amplitudes[i - 1] > amplitudes[i] && amplitudes[i + 1] > amplitudes[i]) || (amplitudes[i - 1] < amplitudes[i] && amplitudes[i + 1] < amplitudes[i])) {
                                picos++;
                        }
                }
                if ((amplitudes[amplitudes.size() - 2] > amplitudes.back() && amplitudes[0] > amplitudes.back()) || (amplitudes[amplitudes.size() - 2] < amplitudes.back() && amplitudes[0] < amplitudes.back())) {
                        picos++;
                }
                cout << picos << endl;
        }

        return 0;
}
