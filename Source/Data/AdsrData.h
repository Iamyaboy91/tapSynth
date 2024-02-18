/*
  ==============================================================================

    AdsrData.h
    Created: 17 Feb 2024 1:30:21pm
    Author:  斉藤孝亮
 refer to: "Let's Build a Synth with Juce Part 6 - Object Oriented Concepts (ADSR)"
  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
    public:
        void updateADSR(const float attack, const float decay, const float sustain, const float release);
    private:
        juce::ADSR::Parameters adsrParams;

};
