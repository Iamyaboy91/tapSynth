/*
  ==============================================================================

    SynthVoice.h
    Created: 5 Feb 2024 2:03:09pm
    Author:  斉藤孝亮

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "Data/OscData.h"
#include "Data/AdsrData.h"
#include "Data/FilterData.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound (juce::SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote (float velocity, bool allowTailOff) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved (int newPitchWheelvalue) override;
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock (juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override;
    
    void updateAdsr(const float attack, const float decay, const float sustain, const float release);
    void updateFilter(const int filterType, const float cutoff, const float resonance);
    void updateModAdsr(const float attack, const float decay, const float sustain, const float release);
    OscData& getOscillator(){ return osc;}
    
    private:
    juce::AudioBuffer<float> synthBuffer;
    
    OscData osc;
    AdsrData adsr;
    AdsrData modAdsr;
    FilterData filter;
    juce::dsp::Gain<float> gain;
   
    bool isPrepared {false};
    
    //return std::sin (x);                  //Sine Wave
    //return x / MathConstants<float>::pi; //Saw Wave
    //return x < 0.0f ? -1.0f : 1.0f;      //Square Wave


};
