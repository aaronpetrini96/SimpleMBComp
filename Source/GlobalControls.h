/*
  ==============================================================================

    GlobalControls.h
    Created: 31 Mar 2024 5:59:11pm
    Author:  Aaron Petrini

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "RotarySliderWithLabels.h"
#include "Params.h"

struct GlobalControls: juce::Component
{
    GlobalControls (juce::AudioProcessorValueTreeState& apvts);
    void paint(juce::Graphics& g) override;
    void resized() override;
    
private:
    using RSWL = RotarySliderWithLabels;
    std::unique_ptr <RSWL> inGainSlider, lowMidXoverSlider, midHighXoverSlider, outGainSlider;
    
    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    
    std::unique_ptr<Attachment> lowmidXoverSliderAttachment,
                                midHighXoverSliderAttachment,
                                inGainSliderAttachment,
                                outGainSliderAttachment;
    
    
};
