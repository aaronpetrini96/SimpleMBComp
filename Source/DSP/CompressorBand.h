/*
  ==============================================================================

    CompressorBand.h
    Created: 31 Mar 2024 6:11:01pm
    Author:  Aaron Petrini

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

struct CompressorBand
{
    juce::AudioParameterFloat* attack {nullptr};
    juce::AudioParameterFloat* release {nullptr};
    juce::AudioParameterFloat* threshold {nullptr};
    juce::AudioParameterChoice* ratio {nullptr};
    juce::AudioParameterBool* bypassed {nullptr};
    juce::AudioParameterBool* mute {nullptr};
    juce::AudioParameterBool* solo {nullptr};
    
    void prepare(const juce::dsp::ProcessSpec& spec);
    
    void updateCompressorSettings();
    
    void process(juce::AudioBuffer<float>& buffer);
    
private:
    juce::dsp::Compressor<float> compressor;
    
};
