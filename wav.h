//
// Created by goforbroke on 23.11.18.
//

#ifndef AUDIO_GN_WAV_H
#define AUDIO_GN_WAV_H

static const char *const RIFF = "RIFF";
static const char *const WAVE = "WAVE";
static const char *const FMT_ = "fmt ";
static const char *const DATA = "data";

#include <stdexcept>
#include <cstring>

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
                          const unsigned short &bitsPerSample,
                          unsigned int &subchunk2Size) {

    if (bitsPerSample % 8 != 0) {
        throw std::logic_error("Unexpected bitsPerSample value - is not multiple to 8!");
    }

    auto numSamples = (unsigned int) (duration * sampleRate);

    unsigned int subchunk1Size = 16;

    subchunk2Size = numSamples * numChannels * bitsPerSample / 8;

    WAVHEADER wavheader = WAVHEADER{};

    strncpy(wavheader.chunkId, RIFF, sizeof(wavheader.chunkId));
    wavheader.chunkSize = 4 + (8 + subchunk1Size) + (8 + subchunk2Size);
    strncpy(wavheader.format, WAVE, sizeof(wavheader.format));
    strncpy(wavheader.subchunk1Id, FMT_, sizeof(wavheader.subchunk1Id));
    wavheader.subchunk1Size = subchunk1Size;
    wavheader.audioFormat = 1;
    wavheader.numChannels = numChannels;
    wavheader.sampleRate = sampleRate;
    wavheader.byteRate = sampleRate * numChannels * bitsPerSample / 8;
    wavheader.blockAlign = numChannels * bitsPerSample / 8;
    wavheader.bitsPerSample = bitsPerSample;
    strncpy(wavheader.subchunk2Id, DATA, sizeof(wavheader.subchunk2Id));
    wavheader.subchunk2Size = subchunk2Size;

    if (44 != sizeof(wavheader)) {
        throw std::logic_error("Unexpected WAV headers length!");
    }

    return wavheader;
}

#endif //AUDIO_GN_WAV_H
