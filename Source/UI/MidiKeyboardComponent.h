/*
  ==============================================================================

    MidiKeyboardComponent.h
    Created: 8 Mar 2024 10:58:26am
    Author:  斉藤孝亮

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MidiKeyboardComponent  : public juce::Component

{
public:
    MidiKeyboardComponent();
    ~MidiKeyboardComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    

    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiKeyboardComponent)
};
