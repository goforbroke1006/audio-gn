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

    unsigned int subchunk2Size;
    const WAVHEADER &wavheader = createWavHeader(hz, 20, channelCount, subchunk2Size);

    file.write(reinterpret_cast<const char *>(&wavheader), sizeof(wavheader));

    constexpr double two_pi = 6.283185307179586476925286766559;
    constexpr double max_amplitude = 32760 / 2;
//    double frequency = 261.626; // musical note "C"
    double frequency = Piano::KEY_17;

    for (int n = 0; n < subchunk2Size; n++) {
        double amplitude = (double) n / subchunk2Size * max_amplitude;
        double value = sin((two_pi * n * frequency) / hz);

//        int p1 = (int) (amplitude * value);
//        file.write(reinterpret_cast<const char *>(&p1), sizeof(p1));
//        int p2 = (max_amplitude - amplitude) * value;
//        file.write(reinterpret_cast<const char *>(&p2), sizeof(p2));

        for (int c = 0; c < channelCount; ++c) {
//            int p1 = (int) (amplitude * value);
            int p1 = (max_amplitude - amplitude) * value;
            file.write(reinterpret_cast<const char *>(&p1), sizeof(p1));
        }
    }

    file.close();

    return 0;
}