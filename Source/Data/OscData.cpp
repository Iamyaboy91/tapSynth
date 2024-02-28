/*
  ==============================================================================

    OscData.cpp
    Created: 19 Feb 2024 11:03:57am
    Author:  斉藤孝亮

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec &spec)
{
    fmOsc.prepare(spec);
    prepare (spec);
}


void OscData::setWaveType(const int choice)
{
    switch (choice) 
    {
        case 0:
        // sine wave
            initialise([](float x) {return std::sin (x);});
            break;
            
        case 1:
        // saw wave
            initialise([](float x) {return x / juce::MathConstants<float>::pi;});
            break;
            
        case 2:
        // square wave
            initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f;});
            break;

        default:
            jassertfalse;
            break;

    }
    
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    for(int ch = 0; ch < block.getNumChannels(); ++ch)
    {
        for(int s = 0; s < block.getNumSamples(); ++s)
        {
            fmMod = fmOsc.processSample(block.getSample(ch, s)) * fmDepth;
        }
    }
    
    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz (midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
}


void OscData::setFmParams (const float depth, const float freq)
{
    fmOsc.setFrequency(freq);
    fmDepth =  depth;
    auto currentFreq = juce::MidiMessage::getMidiNoteInHertz (lastMidiNote) + fmMod;
    setFrequency(currentFreq >= 0 ? currentFreq : currentFreq * -1.0f);
}
//========================================================================================式１ ? 式２ : 式３
//　条件演算子(三項演算子)。まず式１が評価されtrueならば式２が評価され、falseなら式３が評価されて最終的な結果となる。式２と式3は同じ型(暗黙的に変換できればOKもしくはthrow)である必要がある。C言語では?:の優先順位は代入演算子=よりも高いがC++においては同じであることに注意。
//========================================================================================
