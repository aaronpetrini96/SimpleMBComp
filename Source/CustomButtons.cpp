/*
  ==============================================================================

    CustomButtons.cpp
    Created: 31 Mar 2024 5:46:03pm
    Author:  Aaron Petrini

  ==============================================================================
*/

#include "CustomButtons.h"


void AnalyzerButton::resized() 
{
    auto bounds = getLocalBounds();
    auto insetRect = bounds.reduced(4);
    
    randomPath.clear();
    
    juce::Random r;
    
    randomPath.startNewSubPath(insetRect.getX(),
                               insetRect.getY() + insetRect.getHeight() * r.nextFloat());
    
    for (auto x = insetRect.getX()+1;x<insetRect.getRight();x+=2)
    {
        randomPath.lineTo(x, insetRect.getY() + insetRect.getHeight() * r.nextFloat());
    }
}
