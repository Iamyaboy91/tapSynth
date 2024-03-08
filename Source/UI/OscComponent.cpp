/*
  ==============================================================================

    OscComponent.cpp
    Created: 19 Feb 2024 1:33:04pm
    Author:  斉藤孝亮

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId, juce::String fmFreqId, juce::String fmDepthId)
{
    juce::StringArray choices{"Sine", "Saw", "Square"};
    oscWaveSelector.addItemList(choices, 1);
    
    addAndMakeVisible(oscWaveSelector);
    
    oscWaveSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorId, oscWaveSelector);
    
    oscWaveSelectorLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    oscWaveSelectorLabel.setFont(15.0f);
    oscWaveSelectorLabel.setJustificationType(juce::Justification::left);
    addAndMakeVisible(oscWaveSelectorLabel);
    
    setSliderWithLabels(fmFreqSlider, fmFreqLabel, apvts, fmFreqId, fmFreqAttachment);
    setSliderWithLabels(fmDepthSlider, fmDepthLabel, apvts, fmDepthId, fmDepthAttachment);
    
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced(5);
    auto labelSpace = bounds.removeFromTop(25);
    
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(20);
    g.drawText("Oscillator", labelSpace.withX(5), juce::Justification::topLeft);
    g.drawRoundedRectangle(bounds.toFloat(), 5.0f, 2.0f);

}

void OscComponent::resized()
{
    auto bounds = getLocalBounds().reduced(10);
    const auto sliderPosY = 50;
    const auto sliderWidth = bounds.getWidth() / 3 ;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;

    
    oscWaveSelector.setBounds(10, sliderPosY, sliderWidth, 30);
    oscWaveSelectorLabel.setBounds( 10,  sliderPosY - labelYOffset, 90, labelHeight);
    
    fmFreqSlider.setBounds(oscWaveSelector.getRight(), sliderPosY, sliderWidth, sliderHeight);
    fmFreqLabel.setBounds(fmFreqSlider.getX(), fmFreqSlider.getY() - labelYOffset, fmFreqSlider.getWidth(), labelHeight );
    
    fmDepthSlider.setBounds(fmFreqSlider.getRight(), sliderPosY, sliderWidth, sliderHeight);
    fmDepthLabel.setBounds(fmDepthSlider.getX() , fmDepthSlider.getY() - labelYOffset, fmDepthSlider.getWidth(), labelHeight );

}


void OscComponent::setSliderWithLabels(juce::Slider& slider, juce::Label &label,juce::AudioProcessorValueTreeState& apvts, juce::String paramId,  std::unique_ptr<Attachment> &attachment)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);
    
    attachment = std::make_unique<Attachment>(apvts, paramId, slider);
    
    label.setColour(juce::Label::textColourId, juce::Colours::white);
    label.setFont(15.0f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}
