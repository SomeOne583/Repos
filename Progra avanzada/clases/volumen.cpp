// Problema volumen

#include <iostream>
#include <bitset>

int main() {
    int c, vol, pi, pd, vid, vdd;
    std::bitset<16> volumen, voli, vold;

    std::cin >> c;
    for (int i = 0; i < c; i++) {
        std::cin >> vol >> pi >> pd;
        volumen = std::bitset<16>(vol);
        vold = volumen & std::bitset<16>(255);
        voli = volumen>>8;

        vid = voli.to_ullong() * (1 + pi / 100.0);
        vid = vid > 255 ? 255 : vid;

        vdd = vold.to_ullong() * (1 + pd / 100.0);
        vdd = vdd > 255 ? 255 : vdd;

        voli = std::bitset<16> (vid);
        vold = std::bitset<16> (vdd);

        volumen = voli<<8 | vold;
        
        std::cout << volumen.to_ullong() << std::endl;
    }

    return 0;
}