// SFMLMusic.cpp: implementation of the SFMLSoundEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "SFMLSoundEngine.h"
#include "SFMLMusic.h"
#include "../../../All2D_System.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SFMLMusic::SFMLMusic()
{
    iID         = -1;
    szFilename  = "";
    init();
}

SFMLMusic::SFMLMusic( int id, const char *filename )
{
    iID         = id;
    szFilename	= filename;
    init();
}

SFMLMusic::~SFMLMusic() {}


// sound
int SFMLMusic::load( int id, const char *filename)
{
	szFilename	= filename;
    if (!music.openFromFile(szFilename)){
        return -1;
    }
 	// Datei öffnen
    init();
 	// return success
	return 0;
}

void SFMLMusic::play()
{
    music.setLoop(false);
    music.play();
}

void SFMLMusic::loop()
{
    music.setLoop(true);
    music.play();
}

void SFMLMusic::stop()
{
    music.stop();
}


bool SFMLMusic::isPlaying(){
    return (music.getStatus()==sf::SoundSource::Status::Playing);
}

int SFMLMusic::getID(){ return iID; }
char const * SFMLMusic::getSource(){ return szFilename; }

void SFMLMusic::setVolume(float volume){
    fVolume=volume;
    music.setVolume(fVolume);
}

float SFMLMusic::getVolume(){ return fVolume; }

void SFMLMusic::free(){
    stop();
}


int SFMLMusic::init()
{
    fVolume     = 1.0f;
    return 0;
}
