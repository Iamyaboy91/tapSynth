/*
  ==============================================================================

    AdsrCpmponent.cpp
    Created: 17 Feb 2024 1:29:44pm
    Author:  斉藤孝亮

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrCpmponent.h"

//==============================================================================
AdsrCpmponent::AdsrCpmponent(juce::AudioProcessorValueTreeState& apvts)
{
    using sliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    attackAttachment = std::make_unique<sliderAttachment> (apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<sliderAttachment> (apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<sliderAttachment> (apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<sliderAttachment> (apvts, "RELEASE", releaseSlider);
    
    setSliderParams(attackSlider);
    setSliderParams(decaySlider);
    setSliderParams(sustainSlider);
    setSliderParams(releaseSlider);
}

AdsrCpmponent::~AdsrCpmponent()
{
}

void AdsrCpmponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    
    
}


void AdsrCpmponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto SliderHeight = bounds.getHeight();
    const auto sliderStartX = 0;
    const auto SliderStartY = 0;
    
    attackSlider.setBounds(sliderStartX, SliderStartY, sliderWidth, SliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, SliderStartY, sliderWidth, SliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, SliderStartY, sliderWidth, SliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, SliderStartY, sliderWidth, SliderHeight);
}
void AdsrCpmponent::setSliderParams(juce::Slider& slider)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
    
}
