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
AdsrComponent::AdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId,juce::String sustainId,juce::String releaseId)
{
    componentName = name;
    
    setSliderWithLabel(attackSlider, attackLabel, apvts, attackId, attackAttachment);
    setSliderWithLabel(decaySlider, decayLabel, apvts, decayId, decayAttachment);
    setSliderWithLabel(sustainSlider, sustainLabel, apvts, sustainId, sustainAttachment);
    setSliderWithLabel(releaseSlider, releaseLabel, apvts, releaseId, releaseAttachment);
    

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
    g.drawText(componentName, labelSpace.withX(5), juce::Justification::topLeft);
    g.drawRoundedRectangle(bounds.toFloat(), 5.0f, 2.0f);
    
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
void AdsrComponent::setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& sliderAttachment)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
    
    sliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);
    
    label.setColour(juce::Label::textColourId, juce::Colours::white);
    label.setFont(15.0f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}
