#include <iostream>
#include <zconf.h>
#include <fstream>
#include <cmath>

#include "wav.h"
#include "music.h"

using namespace std;

int main() {

    ofstream file("result.wav", ios::binary);

    unsigned short channelCount = 2;
    double hz = 44100;

    unsigned int subchunk2Size = 0;
    const WAVHEADER &wavheader = createWavHeader(hz, 20, channelCount, subchunk2Size);

    file.write(reinterpret_cast<const char *>(&wavheader), sizeof(wavheader));

    constexpr double two_pi = 6.283185307179586476925286766559;
    constexpr double max_amplitude = 32760.0 / 2;
//    double frequency = 261.626; // musical note "C"
//    double frequency = 293.6648; // musical note "D"
    double frequency = Piano::KEY_42;

    for (int n = 0; n < subchunk2Size; ++n) {
//        int rnd1 = n % 24;
//        int rnd2 = n % 9;

        double amplitude = (double) n / subchunk2Size * max_amplitude;
        double value = sin((two_pi * n * frequency) / hz);

        int i1 = (int) (amplitude * value /*+ rnd1 + rnd2*/);
        const char *s1 = reinterpret_cast<const char *>(&i1);
        s1 = s1 != nullptr ? s1 : "";

        int i2 = (int) ((max_amplitude /*- rnd1 - rnd2*/ - amplitude) * value);
        const char *s2 = reinterpret_cast<const char *>(&i2);
        s2 = s2 != nullptr ? s2 : "";

        file.write(s1, sizeof(int));
        file.write(s2, sizeof(int));
    }

    file.close();

    return 0;
}
