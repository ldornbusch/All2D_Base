
#pragma once

#include<SFML/Audio.hpp>

class SFMLMusic : public Music
{
public:
	SFMLMusic();
    SFMLMusic(int id, const char *filename);
	virtual ~SFMLMusic();

    int load(int id, const char *filename);

	// sound
	void play();
	void loop();
	void stop();

	bool isPlaying();

	void free();
	void updateStatus();

	int getID();
	virtual const char* getSource();

    // sample
    void setVolume(float volume);
    float getVolume();

private:
	int init();

	int		iID;
	const char  *szFilename;
	float fVolume;
    sf::Music music;
};
