// NullMusic.h: interface for the NullMusic class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "../../Music.h"

class NullMusic : public Music
{
public:
	NullMusic(){}
	virtual ~NullMusic(){}
	// sound
	void play(){};
	void loop(){};
	void stop(){};
	bool isPlaying(){return false;};
	void fade(float targetVolume, float ms_seconds){};
	void free(){};
	int getID(){return -1;};
	const char* getSource(){return "";};
	float getVolume(){return 0.f;};
	void setVolume(float v){};
};
