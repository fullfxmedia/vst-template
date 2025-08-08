#include "PluginProcessor.h"
#include "PluginEditor.h"

VSTTemplateAudioProcessor::VSTTemplateAudioProcessor()
  : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true)
                                    .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
    apvts(*this, nullptr, "PARAMS", createParams()) {}

juce::AudioProcessorValueTreeState::ParameterLayout VSTTemplateAudioProcessor::createParams() {
  std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
  return { params.begin(), params.end() };
}

VSTTemplateAudioProcessor::~VSTTemplateAudioProcessor() {}

void VSTTemplateAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {}
void VSTTemplateAudioProcessor::releaseResources() {}

bool VSTTemplateAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const {
  return layouts.getMainInputChannelSet() == layouts.getMainOutputChannelSet();
}

void VSTTemplateAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
  for (int ch = 0; ch < buffer.getNumChannels(); ++ch) {
      auto* samples = buffer.getWritePointer(ch);
      for (int i = 0; i < buffer.getNumSamples(); ++i) {
          // Process each sample
      }
  }
}

juce::AudioProcessorEditor* VSTTemplateAudioProcessor::createEditor()
{
    return new VSTTemplateAudioProcessorEditor(*this);
}

bool VSTTemplateAudioProcessor::hasEditor() const { return true; }

const juce::String VSTTemplateAudioProcessor::getName() const { return "VSTTemplate"; }

bool VSTTemplateAudioProcessor::acceptsMidi() const { return false; }
bool VSTTemplateAudioProcessor::producesMidi() const { return false; }
bool VSTTemplateAudioProcessor::isMidiEffect() const { return false; }
double VSTTemplateAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int VSTTemplateAudioProcessor::getNumPrograms() { return 1; }
int VSTTemplateAudioProcessor::getCurrentProgram() { return 0; }
void VSTTemplateAudioProcessor::setCurrentProgram(int) {}
const juce::String VSTTemplateAudioProcessor::getProgramName(int) { return {}; }
void VSTTemplateAudioProcessor::changeProgramName(int, const juce::String&) {}

void VSTTemplateAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    // Save plugin state here
    juce::MemoryOutputStream stream(destData, true);
    // stream.writeFloat(someValue);
}

void VSTTemplateAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    // Restore plugin state here
    juce::MemoryInputStream stream(data, static_cast<size_t>(sizeInBytes), false);
}

// Required factory function
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VSTTemplateAudioProcessor();
}
