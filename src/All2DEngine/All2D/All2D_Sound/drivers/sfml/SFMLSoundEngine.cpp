// SFMLSoundEngine.cpp: implementation of the SFMLSoundEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "SFMLSoundEngine.h"
#include "SFMLSample.h"
#include "SFMLMusic.h"
#include "../null/NullMusic.h"
#include "../null/NullSample.h"
#include "../../../All2D_System.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SFMLSoundEngine::SFMLSoundEngine() { bInitialized=false; }
SFMLSoundEngine::~SFMLSoundEngine(){ free(); }

void SFMLSoundEngine::setDataSource(const char* szPath)
{
}

Sample* SFMLSoundEngine::loadSample(const char* filename)
{
	if (!bInitialized) return new NullSample();

	SFMLSample* smp = new SFMLSample();
	smp->load(samples.size(),filename);
	samples.insert(samples.end(),smp);
	return smp;
}

Music* SFMLSoundEngine::loadMusic(const char* filename)
{
	SFMLMusic* retVal = new SFMLMusic();
	if (retVal->load(tracks.size(),filename)==0){
        tracks.insert(tracks.end(), retVal);
	}else{
        delete retVal;
        retVal = 0;
	}
	return retVal;
}

void SFMLSoundEngine::playSample(unsigned int id)
{
	if (!bInitialized) return;
	if (id<samples.size()) samples[id]->play();
}

void SFMLSoundEngine::playMusic(unsigned int id)
{
	if (!bInitialized) return;
	if (id<tracks.size()){
        for(size_t i = 0; i<tracks.size(); ++i){
            tracks[i]->stop();
        }
        tracks[id]->play();
	}
}

int SFMLSoundEngine::loadedSamples()
{
	return samples.size();
}

int SFMLSoundEngine::loadedMusic()
{
	return tracks.size();
}

void SFMLSoundEngine::free()
{
	for (unsigned int i=0; i<samples.size(); i++) {
		samples[i]->free();
	}
	samples.clear();

	for (unsigned int i=0; i<tracks.size(); i++) {
		tracks[i]->free();
	}
	tracks.clear();
}

const char* SFMLSoundEngine::getDriverInfo() {
  return "SFML Sounddriver";
}

void SFMLSoundEngine::init()
{
    // is initialized
    bInitialized=true;
}


void SFMLSoundEngine::updateStatus()
{
	if (!bInitialized) return;
	for (unsigned int i=0; i<samples.size(); i++) {
		((SFMLSample*)samples[i])->updateStatus();
	}
}
