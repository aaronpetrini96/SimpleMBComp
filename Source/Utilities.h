/*
  ==============================================================================

    Utilities.h
    Created: 31 Mar 2024 5:52:05pm
    Author:  Aaron Petrini

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

template <
typename Attachment,
typename APVTS,
typename Params,
typename ParamName,
typename SliderType
        >
void makeAttachment(std::unique_ptr<Attachment>& attachment,
                    APVTS& apvts,
                    const Params& params,
                    const ParamName& name,
                    SliderType& slider)
{
    attachment = std::make_unique<Attachment>(apvts, params.at(name),slider);
}


template <
typename APVTS,
typename Params,
typename Name
        >
juce::RangedAudioParameter& getParam(APVTS& apvts, const Params& params, const Name& name)
{
    auto param = apvts.getParameter(params.at(name));
    jassert(param != nullptr);
    
    return *param;
}




juce::String getValString(const juce::RangedAudioParameter& param, bool getLow, juce::String suffix);



template<typename T>
bool truncateKiloValue (T& value)
{
    if(value>static_cast<T>(999))
    {
        value/=static_cast<T>(1000);
        return true;
    }
}


template <
typename Labels,
typename ParamsType,
typename SuffixType >
void addLabelPairs(Labels& labels, const ParamsType& param, const SuffixType& suffix)
{
    labels.clear();
    labels.add({0.f,getValString(param,true,suffix)});
    labels.add({1.f,getValString(param,false,suffix)});
}


void drawModuleBackground(juce::Graphics& g, juce::Rectangle<int> bounds);
