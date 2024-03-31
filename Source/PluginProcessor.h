/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

/*
 GUI ROAD MAP
 1. GLOBAL CONTROLS (x-over sliders, gain sliders)
 2. MAIN BAND CONTROLS (attack, release, threshold, ratio) below global
 3. ADD SOLO, MUTE, BYPASS
 4. BAND SELECT FUNCTIONALITY (one set of control for all bands)
 5. BAND SELECT BUTTONS REFLECT SOLO MUTE BYPASS STATE
 6. CUSTOM LOOK AND FEEL FOR SLIDERS AND TOGGLE BUTTONS
 7. SPECTRUM ANALYZER OVERVIEW
 8. DATA STRUCTORS FOR SPECTRUM ANALYZER
 9. FIFO USAGE IN pluginProcessor::processBlock
 10. iMPLEMENTATION OF THE ANALYZER PRE COMPUTED PATHS
 11. DRAWING CROSSOVERS ON TOP OF ANALYZER PLOT
 12. DRAWING GAIN REDUCTION ON TOP OF ANALYZER
 13. ANALYZER BYPASS
 14. GLOBAL BYPASS BUTTON
 */

#include <JuceHeader.h>
#include "Params.h"
#include "CompressorBand.h"
//==============================================================================
/**
*/
class SimpleMBCompAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    SimpleMBCompAudioProcessor();
    ~SimpleMBCompAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    using APVTS = juce::AudioProcessorValueTreeState;
    static APVTS::ParameterLayout createParameterLayout();
    
    APVTS apvts {*this,nullptr,"Parameters",createParameterLayout()};
    

private:

    std::array<CompressorBand,3> compressors;
    CompressorBand& lowBandComp = compressors[0];
    CompressorBand& midBandComp = compressors[1];
    CompressorBand& highBandComp = compressors[2];
    
    using Filter = juce::dsp::LinkwitzRileyFilter<float>;
    //      FC0  FC1
    Filter  LP1 , AP2,
            HP1, LP2,
                 HP2;

    juce::AudioBuffer<float> apBuffer;
    
    juce::AudioParameterFloat* lowMidCrossover {nullptr};
    juce::AudioParameterFloat* midHighCrossover {nullptr};
    
    std::array<juce::AudioBuffer<float>,3> filterBuffers;
    
    juce::dsp::Gain<float> inputGain, outputGain;
    juce::AudioParameterFloat* inputGainParam {nullptr};
    juce::AudioParameterFloat* outputGainParam {nullptr};
    
    template<typename T, typename U>
    void applyGain(T& buffer, U& gain)
    {
        auto block = juce::dsp::AudioBlock<float>(buffer);
        auto ctx = juce::dsp::ProcessContextReplacing<float>(block);
        gain.process(ctx);
    }
    
    void updateState();
    void splitBands(const juce::AudioBuffer<float>& inputBuffer);
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleMBCompAudioProcessor)
};
