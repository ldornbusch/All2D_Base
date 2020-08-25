// Sound.h: interface for the Sound class.
//
//////////////////////////////////////////////////////////////////////

#pragma once




/**
 * defines the base interface for all representations of a sound.
 * offers methods for controlling the playback of a sound.
 *
 * @author dbug 20020130
 * @version SETest 0.1
 * @since SETest 0.1
 */
class Sound
{
public:

	Sound(){};
	virtual ~Sound(){};

	/**
	 * Plays the sound once and then stops. If the sound is
	 * already playing then it is stopped and restarted.
	 */
	virtual void play()=0;

	/**
	 * Plays the sound over and over again (looping).
	 * If the sound is already playing then it is stopped and
	 * restarted.
	 */
	virtual void loop()=0;

	/**
	 * Stops playing the sound.
	 */
	virtual void stop()=0;

	/**
	 * Returns true if play() or loop() has been invoked on the sound and
	 * the stop() hasn't been called after that. This method doesn't reflect
	 * the fact if the sound can be heard or not at the moment.
	 */
	virtual bool isPlaying()=0;

    /**
    * Sets the volume of the sound. Value of 0.0 means that the sound should be
    * inaudible and value of 1.0 means the sound is played at its normal volume.
    * Values above 1.0 are treated as 1.0 and values below 0.0 are treated as 0.0.
    *
    * NOTE: This feature is optional as it can't be supported on all platform implementations,
    * but all implementations offer at least a "do nothing" method.
    *
    *@param volume The sounds volume.
    */
    virtual void setVolume( float volume )=0;

    /**
    * Returns the volume of the sound. Value of 0.0 means that the sound should be
    * inaudible and value of 1.0 means the sound is played at its normal volume.
    *
    *@return The sounds volume.
    */
    virtual float getVolume()=0;

    /**
    * starts the playing sound at the current volume and interpolates the volume
    * so it reaches targetVolume after ms_seconds passed(which is in milliseconds).
    *
    *@param targetVolume The sounds volume to reach after a specific time.
    *@param ms_seconds The time until the sound reaches the specified volume
    */
    virtual void fade(float targetVolume, float ms_seconds)=0;

	/**
	 * Frees all the resources that are used by the sound representation.
	 * This method is quite slow to execute and should preferrably be called upon
	 * exiting the game or between level changes etc.
	 */
	virtual void free()=0;

	/**
	 * Returns the id associated with this sound
	 */
	virtual int getID()=0;

	/**
	 * Returns the source (filename) of this sound
	 */
	virtual const char* getSource()=0;
};
