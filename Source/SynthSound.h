/*
  ==============================================================================

    SynthSound.h
    Created: 5 Feb 2024 2:03:41pm
    Author:  斉藤孝亮

  ==============================================================================
*/

#pragma once
#include<JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
    public:
    bool appliesToNote (int midiNoteNumber) override { return  true;   }
    bool appliesToChannel (int midiChannel) override {return true; }
    
};
