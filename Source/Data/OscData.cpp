/*
  ==============================================================================

    OscData.cpp
    Created: 19 Feb 2024 11:03:57am
    Author:  斉藤孝亮

  ==============================================================================
*/

#include "OscData.h"

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
