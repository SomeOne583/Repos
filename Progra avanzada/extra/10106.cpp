#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool ordena(string &a, string &b) {
        return a.size() > b.size();
}

string suma(string a, string b) {
        int residuo = 0, acum;
        string resultado, tmp;
        vector<string> nums;

        reverse(a.begin(), a.end());
        nums.push_back(a);

        reverse(b.begin(), b.end());
        nums.push_back(b);

        sort(nums.begin(), nums.end(), ordena);

        for (int i = 0; i < nums[0].size(); i++) {
                acum = 0;
                for (int j = 0; j < nums.size(); j++) {
                        if (i >= nums[j].size()) {
                                break;
                        }
                        acum += nums[j][i] - 48;
                }
                acum += residuo;
                residuo = acum / 10;
                tmp = to_string(acum % 10);
                reverse(tmp.begin(), tmp.end());
                resultado += tmp;
        }
        if (residuo > 0) {
                tmp = to_string(residuo);
                reverse(tmp.begin(), tmp.end());
                resultado += tmp;
        }
        reverse(resultado.begin(), resultado.end());
        return resultado;
}

int main() {
        string a, b;
        while (cin >> a) {
                cin >> b;

                
        }

        return 0;
}
