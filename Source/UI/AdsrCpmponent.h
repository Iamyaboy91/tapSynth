/*
  ==============================================================================

    AdsrCpmponent.h
    Created: 17 Feb 2024 1:29:44pm
    Author:  斉藤孝亮

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrCpmponent  : public juce::Component
{
public:
    AdsrCpmponent(juce::AudioProcessorValueTreeState& apvts);
    ~AdsrCpmponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void setSliderParams(juce::Slider& slider);
    
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    
    using sliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    std::unique_ptr<sliderAttachment> attackAttachment;
    std::unique_ptr<sliderAttachment> decayAttachment;
    std::unique_ptr<sliderAttachment> sustainAttachment;
    std::unique_ptr<sliderAttachment> releaseAttachment;
   
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrCpmponent)
};
