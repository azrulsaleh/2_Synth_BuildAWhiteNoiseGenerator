/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (800, 600);

//    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
//        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
//    {
//        RuntimePermissions::request (RuntimePermissions::recordAudio, [&] (bool granted) { if (granted)  setAudioChannels (0, 2); });
//    }
//    else
//    {
//        setAudioChannels (0, 2);
//    }
    
    setAudioChannels (0, 2);
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    String message;
    message << "Preparing to play audio..." << newLine;
    message << " samplesPerBlockExpected = " << samplesPerBlockExpected << newLine;
    message << " sampleRate = " << sampleRate;
    Logger::getCurrentLogger()->writeToLog(message);
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    //No output
        //bufferToFill.clearActiveBufferRegion();
    
    //Stereo noise
        //for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel) {
        //    auto* buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
        //    
        //    for (auto sample = 0; sample < bufferToFill.numSamples; ++sample) {
        //        buffer[sample] = (random.nextFloat() * 0.25f) - 0.125f;
        //    }
        //}
    
    //Mono noise
        auto* buffer1 = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
        auto* buffer2 = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample) {
            auto r = (random.nextFloat() * 0.2f) - 0.1f;
            buffer1[sample] = r;
            buffer2[sample] = r;
        }
}

void MainComponent::releaseResources()
{
    Logger::getCurrentLogger()->writeToLog("Releasing audio resources");
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
