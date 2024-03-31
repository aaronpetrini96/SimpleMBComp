/*
  ==============================================================================

    UtilityComponents.h
    Created: 31 Mar 2024 5:49:05pm
    Author:  Aaron Petrini

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

struct Placeholder : juce::Component
{
    Placeholder();
    
    void paint (juce::Graphics& g) override;

    juce::Colour customColor;
};

struct RotarySlider : juce::Slider
{
    RotarySlider();
   
};
