/*
  ==============================================================================

    UtilityComponents.cpp
    Created: 31 Mar 2024 5:49:05pm
    Author:  Aaron Petrini

  ==============================================================================
*/

#include "UtilityComponents.h"

Placeholder::Placeholder()
{
    juce::Random r;
    customColor = juce::Colour(r.nextInt(255),r.nextInt(255),r.nextInt(255));
}

void Placeholder::paint (juce::Graphics& g) 
{
  g.fillAll(customColor);
}


RotarySlider::RotarySlider() :
juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
             juce::Slider::TextEntryBoxPosition::NoTextBox)
{ }
