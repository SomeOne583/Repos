// Problema 10340 AllInAll

#include <iostream>

int main() {
        std::string s, t;
        int a, b;

        while (std::cin >> s >> t) {
                a = 0;
                b = 0;
                while (a < s.length() && b < t.length()) {
                        if (s[a] == t[b]) {
                                a++;
                                b++;
                        } else {
                                b++;
                        }
                }
                if (a == s.length()) {
                        std::cout << "Yes" << std::endl;
                } else {
                        std::cout << "No" << std::endl;
                }
        }

        return 0;
}