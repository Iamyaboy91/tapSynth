/*
  ==============================================================================

    OscData.h
    Created: 19 Feb 2024 11:03:57am
    Author:  斉藤孝亮

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OscData : public juce::dsp::Oscillator<float>
{
public:
    void setWaveType(const int choice);
    
private:
    
};
