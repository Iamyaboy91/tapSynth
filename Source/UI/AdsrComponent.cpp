/*
  ==============================================================================

    AdsrCpmponent.cpp
    Created: 17 Feb 2024 1:29:44pm
    Author:  斉藤孝亮

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent(juce::AudioProcessorValueTreeState& apvts)
{
    using sliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    attackAttachment = std::make_unique<sliderAttachment> (apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<sliderAttachment> (apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<sliderAttachment> (apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<sliderAttachment> (apvts, "RELEASE", releaseSlider);
    
    setSliderParams(attackSlider, attackLabel);
    setSliderParams(decaySlider, decayLabel);
    setSliderParams(sustainSlider, sustainLabel);
    setSliderParams(releaseSlider, releaseLabel);
    

}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced(5);
    auto labelSpace = bounds.removeFromTop(25.0f);
    
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(20);
    g.drawText("Envelope", labelSpace.withX(5), juce::Justification::topLeft);
    g.drawRoundedRectangle(0.0f, 25.0f, getWidth() - 15, getHeight() - 50, 10.0f, 1.0f);
    
}


void AdsrComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(25);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto SliderHeight = bounds.getHeight() - 30;
    const auto sliderStartX = bounds.getX();
    const auto SliderStartY = 45;
    const auto labelHeight = 15;
    const auto labelOffset = 10;
    
    
    
    attackSlider.setBounds(sliderStartX, SliderStartY, sliderWidth, SliderHeight);
    attackLabel.setBounds(attackSlider.getX(), attackSlider.getY() - labelOffset, attackSlider.getWidth(), labelHeight);
    
    decaySlider.setBounds(attackSlider.getRight() + padding, SliderStartY, sliderWidth, SliderHeight);
    decayLabel.setBounds(decaySlider.getX(), decaySlider.getY() - labelOffset, decaySlider.getWidth(), labelHeight);
    
    sustainSlider.setBounds(decaySlider.getRight() + padding, SliderStartY, sliderWidth, SliderHeight);
    sustainLabel.setBounds(sustainSlider.getX(), sustainSlider.getY() - labelOffset, sustainSlider.getWidth(), labelHeight);
    
    releaseSlider.setBounds(sustainSlider.getRight() + padding, SliderStartY, sliderWidth, SliderHeight);
    releaseLabel.setBounds(releaseSlider.getX(), releaseSlider.getY() - labelOffset, releaseSlider.getWidth(), labelHeight);
}
void AdsrComponent::setSliderParams(juce::Slider& slider, juce::Label& label)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
    
    label.setColour(juce::Label::textColourId, juce::Colours::white);
    label.setFont(15.0f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}
