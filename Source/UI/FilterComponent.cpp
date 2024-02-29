/*
  ==============================================================================

    FilterComponent.cpp
    Created: 29 Feb 2024 10:58:20am
    Author:  斉藤孝亮

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent(juce::AudioProcessorValueTreeState& apvts, juce::String fltSelectorId, juce::String fltCutoffId, juce::String fltResId)
{
    juce::StringArray choices{ "Low-Pass", "Band-Pass", "High-Pass" };
    filterTypeSelector.addItemList(choices, 1);
    addAndMakeVisible(filterTypeSelector);
    filterTypeSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, fltSelectorId, filterTypeSelector);
    filterSelectorLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    filterSelectorLabel.setFont(15.0f);
    filterSelectorLabel.setJustificationType(juce::Justification::left);
    
    setSliderWithLabels(filterCutoffSlider, filterCutoffLabel, apvts, fltCutoffId, filterCutoffAttachment);
    setSliderWithLabels(filterResonanceSlider, filterResLabel, apvts, fltResId, filterResAttachment);
}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced(5);
    auto labelSpace = bounds.removeFromTop(25.0f);
    
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(20);
    g.drawText("Filters", labelSpace.withX(5), juce::Justification::topLeft);
    g.drawRoundedRectangle(0.0f, 20.0f, getWidth() - 15, getHeight()- 50, 10.0f, 1.0f);
}

void FilterComponent::resized()
{
    const auto sliderPosY = 80;
    const auto sliderWidth = 100;
    const auto sliderHeight = 60;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
    
    filterTypeSelector.setBounds(10, 10, 90, 20);
    filterCutoffSlider.setBounds(0, sliderPosY, sliderWidth, sliderHeight);
    filterCutoffLabel.setBounds(filterCutoffSlider.getX(), filterCutoffSlider.getY() - labelYOffset, filterCutoffSlider.getWidth(), labelHeight );
    
    filterResonanceSlider.setBounds(filterCutoffSlider.getRight(), sliderPosY, sliderWidth, sliderHeight);
    filterResLabel.setBounds(filterCutoffSlider.getX() , filterResonanceSlider.getY() - labelYOffset, filterResonanceSlider.getWidth(), labelHeight );

}

void FilterComponent::setSliderWithLabels(juce::Slider& slider, juce::Label &label,juce::AudioProcessorValueTreeState& apvts, juce::String paramId,  std::unique_ptr<Attachment> &attachment)
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

