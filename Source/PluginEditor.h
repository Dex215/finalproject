/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class OgDistAudioProcessorEditor  : public juce::AudioProcessorEditor, 
                                    public juce::Slider::Listener
{
public:
    OgDistAudioProcessorEditor (OgDistAudioProcessor&);
    ~OgDistAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OgDistAudioProcessor& audioProcessor;
    juce::Slider gainSlider;
    juce::Slider volSlider;
    Slider toneSlider;

    ImageComponent mImageComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OgDistAudioProcessorEditor)

};