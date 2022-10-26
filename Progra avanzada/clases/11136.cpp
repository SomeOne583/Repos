#include <iostream>
#include <map>

int main() {
        int d, b, tmp;
        long t;
        std::map<int, int> urna;
        std::map<int, int>::iterator urnaI, urnaF;

        while (std::cin >> d && d != 0) {
                t = 0;
                for (int i = 0; i < d; i++) {
                        std::cin >> b;
                        for (int j = 0; j < b; j++) {
                                std::cin >> tmp;
                                urna[tmp]++;
                        }

                        urnaI = urna.begin();
                        urnaF = urna.end();
                        urnaF--;

                        t = t + urnaF->first - urnaI->first;

                        if (urnaI->second == 1) {
                                urna.erase(urnaI);
                        } else {
                                urnaI->second--;
                        }
                        if (urnaF->second == 1) {
                                urna.erase(urnaF);
                        } else {
                                urnaF->second--;
                        }
                }
                std::cout << t << std::endl;
                urna.clear();
        }
}
