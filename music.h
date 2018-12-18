#ifndef AUDIO_GN_MUSIC_H
#define AUDIO_GN_MUSIC_H

class Guitar {
public:
    static const double e;
    static const double A;
    static const double D;
    static const double G;
    static const double B;
    static const double E;
};

const double Guitar::e = 82.407;
const double Guitar::A = 110.000;
const double Guitar::D = 146.832;
const double Guitar::G = 195.998;
const double Guitar::B = 246.942;
const double Guitar::E = 329.628;

class BassGuitar {
public:
    static const double E;
    static const double A;
    static const double D;
    static const double G;
};

const double BassGuitar::E = 41.204;
const double BassGuitar::A = 55.000;
const double BassGuitar::D = 73.416;
const double BassGuitar::G = 97.999;

class Cello {
public:
    static const double C;
    static const double G;
    static const double D;
    static const double A;
};

const double Cello::C = 65.4064;
const double Cello::G = 97.9989;
const double Cello::D = 146.832;
const double Cello::A = 220.000;


// @link https://en.wikipedia.org/wiki/Piano_key_frequencies

class Piano {
public:
    // sub-contra-octave
    static const double KEY_01; // A͵͵
    static const double KEY_02; // A♯͵͵/B♭͵͵
    static const double KEY_03; // B͵͵
    
    // contra-octave
    static const double KEY_04; // C͵
    static const double KEY_05;
    static const double KEY_06; // D͵
    static const double KEY_07;
    static const double KEY_08; // E͵
    static const double KEY_09; // F͵
    static const double KEY_10;
    static const double KEY_11; // G͵
    static const double KEY_12;
    static const double KEY_13; // A͵
    static const double KEY_14;
    static const double KEY_15; // B͵

    // great octave
    static const double KEY_16; // C great octave
    static const double KEY_17; // C♯/D♭
    static const double KEY_18; // D
    static const double KEY_19; // D♯/E♭
    static const double KEY_20; // E
    static const double KEY_21; // F
    static const double KEY_22; // F♯/G♭
    static const double KEY_23; // G
    static const double KEY_24; // G♯/A♭
    static const double KEY_25; // A
    static const double KEY_26; // A♯/B♭
    static const double KEY_27; // B


    static const double KEY_40; //
    static const double KEY_41; //
    static const double KEY_42; //

    static const double KEY_49; //

};

const double Piano::KEY_01 = 27.50000;
const double Piano::KEY_02 = 29.13524;
const double Piano::KEY_03 = 30.86771;

const double Piano::KEY_04 = 32.70320;
const double Piano::KEY_05 = 34.64783;
const double Piano::KEY_06 = 36.70810;
const double Piano::KEY_07 = 38.89087;
const double Piano::KEY_08 = 41.20344;
const double Piano::KEY_09 = 43.65353;
const double Piano::KEY_10 = 46.24930;
const double Piano::KEY_11 = 48.99943;
const double Piano::KEY_12 = 51.91309;
const double Piano::KEY_13 = 55.00000;
const double Piano::KEY_14 = 58.27047;
const double Piano::KEY_15 = 61.73541;

// great octave
const double Piano::KEY_16 = 65.40639;
const double Piano::KEY_17 = 69.29566;
const double Piano::KEY_18 = 73.41619;
const double Piano::KEY_19 = 77.78175;
const double Piano::KEY_20 = 82.40689;
const double Piano::KEY_21 = 87.30706;
const double Piano::KEY_22 = 92.49861;
const double Piano::KEY_23 = 97.99886;
const double Piano::KEY_24 = 103.8262;
const double Piano::KEY_25 = 110.0000;
const double Piano::KEY_26 = 116.5409;
const double Piano::KEY_27 = 123.4708;


const double Piano::KEY_40 = 261.6256;
const double Piano::KEY_41 = 277.1826;
const double Piano::KEY_42 = 293.6648;

const double Piano::KEY_49 = 440.0000;

#endif //AUDIO_GN_MUSIC_H
