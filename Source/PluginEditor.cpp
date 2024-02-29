/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TapSynthAudioProcessorEditor::TapSynthAudioProcessorEditor (TapSynthAudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p), osc(audioProcessor.apvts, "OSC1WAVETYPE","FMFREQ", "FMDEPTH"),adsr(audioProcessor.apvts),filter(audioProcessor.apvts, "FILTERTYPE", "FILTERCUTOFF", "FILTERRES")
{
    setSize (500, 400);
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
    

    
}
TapSynthAudioProcessorEditor::~TapSynthAudioProcessorEditor()
{
}

//==============================================================================
void TapSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void TapSynthAudioProcessorEditor::resized()
{
    osc.setBounds(5, 5, getWidth() / 2, 200); //oscに与えられた領域
    adsr.setBounds(getWidth() / 2, 5, getWidth() / 2, 200);
    filter.setBounds(getRight(), 5, getWidth(), getHeight());
}


