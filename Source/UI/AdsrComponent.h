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
class AdsrComponent  : public juce::Component
{
public:
    AdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId,juce::String sustainId,juce::String releaseId);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    void setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment);
    
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    
    using sliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    std::unique_ptr<sliderAttachment> attackAttachment;
    std::unique_ptr<sliderAttachment> decayAttachment;
    std::unique_ptr<sliderAttachment> sustainAttachment;
    std::unique_ptr<sliderAttachment> releaseAttachment;
    
    juce::Label attackLabel {"Attack", "A" };
    juce::Label decayLabel {"Decay", "D" };
    juce::Label sustainLabel {"Sustain", "S" };
    juce::Label releaseLabel {"Release", "R" };
    

   
//    attackAttachment = std::make_unique<sliderAttachment> (apvts, "ATTACK", attackSlider);
//    decayAttachment = std::make_unique<sliderAttachment> (apvts, "DECAY", decaySlider);
//    sustainAttachment = std::make_unique<sliderAttachment> (apvts, "SUSTAIN", sustainSlider);
//    releaseAttachment = std::make_unique<sliderAttachment> (apvts, "RELEASE", releaseSlider);
    juce::String componentName {""};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
