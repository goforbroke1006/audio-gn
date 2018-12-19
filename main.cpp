#include <iostream>
#include <zconf.h>
#include <fstream>
#include <cmath>

#include "wav.h"
#include "music.h"

using namespace std;

int main() {

    ofstream file("result.wav", ios::binary);

//    double hz = 44100;
    double hz = 96000;
    unsigned long duration = 20; // 20 seconds
    unsigned short channelCount = 2; // stereo
    unsigned short bitsPerSample = 16;
    unsigned int subchunk2Size = 0;
    const WAVHEADER &wavheader = createWavHeader(hz, duration, channelCount, bitsPerSample, subchunk2Size);

    file.write(reinterpret_cast<const char *>(&wavheader), sizeof(wavheader));

    constexpr double two_pi = 6.283185307179586476925286766559;
    constexpr double max_amplitude = 32760.0;
//    double frequency = 261.626; // musical note "C"
//    double frequency = 293.6648; // musical note "D"
    double frequency = Piano::KEY_42;


    for (int n = 0; n < subchunk2Size / channelCount; ++n) {
        double amplitude = (double) n / (subchunk2Size / channelCount) * max_amplitude;
        double value = sin((two_pi * n * frequency) / hz);

        { // clean line
            int i1 = (int) (amplitude * value);
            const char *s1 = reinterpret_cast<const char *>(&i1);
            s1 = s1 != nullptr ? s1 : "";
            file.write(s1, sizeof(int));
        }

        { // clean line
            int i1 = (int) (max_amplitude - amplitude * value);
            const char *s1 = reinterpret_cast<const char *>(&i1);
            s1 = s1 != nullptr ? s1 : "";
            file.write(s1, sizeof(int));
        }

    }

    file.close();

    return 0;
}
