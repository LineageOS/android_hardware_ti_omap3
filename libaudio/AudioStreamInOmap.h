/*
 * AudioStreamInOmap.h
 *
 * Audio input stream handler for OMAP.
 *
 * Copyright (C) 2008 Texas Instruments, Inc.
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef _AUDIO_STREAM_IN_OMAP_H_
#define _AUDIO_STREAM_IN_OMAP_H_

#include <hardware_legacy/AudioHardwareInterface.h>
#include <alsa/asoundlib.h>
#include "AudioStreamOmap.h"
#include "AudioHardwareOmap.h"

using namespace android;

class AudioHardwareOmap;

class AudioStreamInOmap : public AudioStreamIn
{
	public:
		AudioStreamInOmap(AudioHardwareOmap *parent);
               ~AudioStreamInOmap();
               status_t set(int format, int channels, uint32_t rate, int buffer_size);
		uint32_t sampleRate() const;
		virtual size_t bufferSize() const;
		virtual int channelCount() const;
		virtual int format() const;
		virtual status_t setGain(float gain);
		virtual ssize_t read(void* buffer, ssize_t bytes);
		virtual status_t dump(int fd, const Vector<String16>& args);
		virtual status_t standby();
	private:
               status_t openStream();
               status_t closeStream();
               int bytesPerFrame() const;

               bool streaming;
               struct StreamProperties properties;
		snd_pcm_t *pcmHandle;
		AudioHardwareOmap *hardware;
		Mutex mLock;
};

#endif
