/*
  ==============================================================================

    FilterComponent.h
    Created: 29 Feb 2024 10:58:20am
    Author:  斉藤孝亮

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class FilterComponent  : public juce::Component
{
public:
    FilterComponent(juce::AudioProcessorValueTreeState& apvts, juce::String fltSelectorId, juce::String fltCutoffId, juce::String fltResId);
    ~FilterComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox filterTypeSelector { "Filter Type" };
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeSelectorAttachment;
    
    juce::Slider filterCutoffSlider;
    juce::Slider filterResonanceSlider;
    
    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    std::unique_ptr<Attachment> filterCutoffAttachment;
    std::unique_ptr<Attachment> filterResAttachment;
    
    juce::Label filterSelectorLabel { "Filter Type", "Filter Type" };
    juce::Label filterCutoffLabel { "Filter Freq", "Filter Freq" };
    juce::Label filterResLabel { "Filter Resonance", "Filter Resonance" };
    
    void setSliderWithLabels(juce::Slider &slider, juce::Label &label,juce::AudioProcessorValueTreeState& apvts, juce::String paramId,  std::unique_ptr<Attachment>& attachment);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};

//Component is any visualelements in JUCE
