/*
  ==============================================================================

    LookAndFeel.h
    Created: 31 Mar 2024 5:40:39pm
    Author:  Aaron Petrini

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "RotarySliderWithLabels.h"
#include "CustomButtons.h"
#include "Utilities.h"

struct LookAndFeel : juce::LookAndFeel_V4
{
    void drawRotarySlider (juce::Graphics&,
                                   int x, int y, int width, int height,
                                   float sliderPosProportional,
                                   float rotaryStartAngle,
                                   float rotaryEndAngle,
                           juce::Slider&) override;
    
    void drawToggleButton (juce::Graphics &g,
                           juce::ToggleButton & toggleButton,
                           bool shouldDrawButtonAsHighlighted,
                           bool shouldDrawButtonAsDown) override;
    
    
};
