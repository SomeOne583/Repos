#include <iostream>
#include <vector>
#include <stack>

int main() {
        int N, n = -1, a, b, tmp;
        std::vector<int> l;
        std::stack<int> s;

        bool archivo = true;
        bool bloque = true;
        while (archivo || bloque) {
                std::cin >> N;
                if (N == 0) {
                        if (!bloque) {
                                archivo = false;
                        } else {
                                bloque = false;
                                n = -1;
                                std::cout << std::endl;
                        }
                } else {
                        bloque = true;
                        if (n == -1) {
                                n = N;
                        } else {
                                a = 1;
                                b = 0;
                                while (!s.empty()) {
                                        s.pop();
                                }
                                l.clear();
                
                                l.push_back(N);
                                for (int i = 1; i < n; i++) {
                                        std::cin >> tmp;
                                        l.push_back(tmp);
                                }

                                while (a <= n && b < n) {
                                        if (a == l[b]) {
                                                if (a < n) {
                                                        a++;
                                                }
                                                b++;
                                        } else if (s.size() != 0 && s.top() == l[b]) {
                                                s.pop();
                                                b++;
                                        } else {
                                                s.push(a);
                                                a++;
                                        }
                                }
                                if (b == n) {
                                        std::cout << "Yes" << std::endl;
                                } else {
                                        std::cout << "No" << std::endl;
                                }
                        }
                }
        }
        
        return 0;
}
