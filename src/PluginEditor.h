#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class VSTTemplateAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
  VSTTemplateAudioProcessorEditor(VSTTemplateAudioProcessor&);
  ~VSTTemplateAudioProcessorEditor() override = default;

  void paint(juce::Graphics&) override;
  void resized() override;

private:
    VSTTemplateAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VSTTemplateAudioProcessorEditor);
};
