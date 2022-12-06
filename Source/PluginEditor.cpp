/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OgDistAudioProcessorEditor::OgDistAudioProcessorEditor (OgDistAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    auto bgImage = ImageCache::getFromMemory(BinaryData::green_mammoth_png, BinaryData::green_mammoth_pngSize);
    
    if (!bgImage.isNull())
        mImageComponent.setImage(bgImage, RectanglePlacement::stretchToFit);
    else
        jassert(!bgImage.isNull()); 
    addAndMakeVisible(mImageComponent);


    addAndMakeVisible(gainSlider);
    gainSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle(Slider::NoTextBox, true, 100,25);
    gainSlider.setRange(20, 200.0);
    gainSlider.setValue(110.0);   
    gainSlider.addListener(this);

    addAndMakeVisible(volSlider);
    volSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    volSlider.setTextBoxStyle(Slider::NoTextBox, true, 100, 25);
    volSlider.setRange(-48.0, -12.0);
    volSlider.setValue(-30.0);
    volSlider.addListener(this);

    getLookAndFeel().setColour(Slider::thumbColourId, Colours::black);
    //getLookAndFeel().setColour(Slider::rotarySliderOutlineColourId, Colours::grey);
    // 
    //addAndMakeVisible(toneSlider);
    //toneSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    //toneSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    //toneSlider.setRange(-48.0, 0.0);
    //toneSlider.setValue(-1.0);
    //toneSlider.addListener(this);

    
    setSize (300, 400);
}

OgDistAudioProcessorEditor::~OgDistAudioProcessorEditor()
{
}

//==============================================================================
void OgDistAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::beige);
}

void OgDistAudioProcessorEditor::resized()

{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    //gainSlider.setbounds(200 / 2, 200 / 2, 100, 100);
    gainSlider.setBounds(300 / 3 - 40, 400 / 3 - 100, 80, 80);
    volSlider.setBounds(300 * 2/3 - 40, 400 / 3 - 100, 80, 80);
    toneSlider.setBounds(300 - 40, 400 / 3 - 60, 80, 80);
    mImageComponent.setBoundsRelative(0.0, 0.0, 1, 1);
}

void OgDistAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.distortionAmount = pow(10, gainSlider.getValue()/20);

    }

    if (slider == &volSlider)

    {

        audioProcessor.volume = pow(10, volSlider.getValue() / 20);
        //to get this I was helped by a tutorial linked here: https://www.youtube.com/watch?v=KgxHyTL9HVQ&t=870s
    }
}