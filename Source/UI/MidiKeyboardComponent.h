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
    
    enum ColourIds {
        whiteNoteColourId = 0x1005000 , blackNoteColourId = 0x1005001 , keySeparatorLineColourId = 0x1005002 , mouseOverKeyOverlayColourId = 0x1005003 ,
        keyDownOverlayColourId = 0x1005004 , textLabelColourId = 0x1005005 , shadowColourId = 0x1005006
    };

    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiKeyboardComponent)
};
