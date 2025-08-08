#include "PluginEditor.h"

VSTTemplateAudioProcessorEditor::VSTTemplateAudioProcessorEditor(VSTTemplateAudioProcessor& p)
  : AudioProcessorEditor(&p), processor(p) {

  // Call addAndMakeVisible for each component

  setSize(300, 200);
}

void VSTTemplateAudioProcessorEditor::paint(juce::Graphics& g) {
  g.fillAll(juce::Colours::black);
}

void VSTTemplateAudioProcessorEditor::resized() {
}
