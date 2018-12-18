//
// Created by goforbroke on 23.11.18.
//

#ifndef AUDIO_GN_WAV_H
#define AUDIO_GN_WAV_H

#include <stdexcept>

struct WAVHEADER {
    char chunkId[4]; // text "RIFF"
    unsigned int chunkSize;
    char format[4]; // text "WAVE"
    char subchunk1Id[4]; // "fmt " text
    unsigned int subchunk1Size;
    unsigned short audioFormat; // 1 - linear, value greate 1 mean some compression type
    unsigned short numChannels; // 1 - mono, 2 - stereo
    unsigned int sampleRate; // frequency, 8000 Hz, 44100 Hz
    unsigned int byteRate; // sampleRate * numChannels * bitsPerSample/8
    unsigned short blockAlign; // bytes count in one sample with al channels (numChannels * bitsPerSample/8)
    unsigned short bitsPerSample; // depth - 8 bit, 16 bit, etc
    char subchunk2Id[4]; // text "data"
    unsigned int subchunk2Size; // data block size
};

WAVHEADER createWavHeader(const double &sampleRate,
                          const unsigned long &duration,
                          const unsigned short &numChannels,
                          unsigned int &subchunk2Size) {

    unsigned int numSamples = duration * sampleRate;
    
    unsigned int subchunk1Size = 16;
    unsigned short bitsPerSample = 8;
    subchunk2Size = numSamples * numChannels * bitsPerSample / 8;
    
    WAVHEADER wavheader = WAVHEADER{};

    wavheader.chunkId[0] = 'R';
    wavheader.chunkId[1] = 'I';
    wavheader.chunkId[2] = 'F';
    wavheader.chunkId[3] = 'F';

    wavheader.chunkSize = 4 + (8 + subchunk1Size) + (8 + subchunk2Size);

    wavheader.format[0] = 'W';
    wavheader.format[1] = 'A';
    wavheader.format[2] = 'V';
    wavheader.format[3] = 'E';

    wavheader.subchunk1Id[0] = 'f';
    wavheader.subchunk1Id[1] = 'm';
    wavheader.subchunk1Id[2] = 't';
    wavheader.subchunk1Id[3] = ' ';

    wavheader.subchunk1Size = subchunk1Size;
    wavheader.audioFormat = 1;
    wavheader.numChannels = numChannels;
    wavheader.sampleRate = sampleRate;
    wavheader.byteRate = sampleRate * numChannels * bitsPerSample / 8;
    wavheader.blockAlign = numChannels * bitsPerSample / 8;
    wavheader.bitsPerSample = bitsPerSample;

    wavheader.subchunk2Id[0] = 'd';
    wavheader.subchunk2Id[1] = 'a';
    wavheader.subchunk2Id[2] = 't';
    wavheader.subchunk2Id[3] = 'a';

    
    wavheader.subchunk2Size = subchunk2Size;

    if (44 != sizeof(wavheader)) {
        throw std::logic_error("Unexpected WAV headers length!");
    }

    return wavheader;
}

#endif //AUDIO_GN_WAV_H
