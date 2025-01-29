/***
MBus.cpp - Library to emulate Alpine M-Bus commands

Copyright 2012 Oliver Mueller
Copyright 2020 Marcin Dymczyk

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***/

#ifndef MBUS_H
#define MBUS_H

#include "Arduino.h"
#include "TeensyTimerTool.h"

#define Shutdown 0x11142
#define Ping 0x18
#define Status 0x18 // Not really clear what it means.
#define Play 0x11101
#define Pause 0x11102
#define Stop 0x11140
#define FastFwd 0x11105
#define FastBwd 0x11109
#define FastFwdPause 0x11106
#define FastBwdPause 0x1110A
#define PingOK 0x98ull
#define Wait 0x9F00000ull
#define Resume 0x11181
#define ResumeP 0x11182
#define ChangePrefix 0x113

void printMessage(uint64_t msg);

// Check this: https://github.com/picohari/atmega128_alpine-mbus-emulator/blob/master/mbus_emul.c#L327

class MBus {
  public:
    MBus(uint8_t in, uint8_t out);
    void send(const uint64_t message);
    boolean receive(uint64_t* message);

    enum ChangerErrorCode {
      kNormal,
      kHighTemperature,
      kDiscChangeIssue,
      kStuckDisc
    };

    enum ChangingStatus {
      kInProgress,
      kNoMagazine,
      kNoDisc,
      kNoTrack,
      kDone
    };

    enum PlayState {
      kPreparing = 1,
      kStopped = 2,
      kPaused = 3,
      kPlaying = 4,
      kSpinup = 5,
      kFastForward = 6,
      kFastReverse = 7
    };

    struct DiskTrackChange {
      uint8_t disc;
      uint8_t track;
      PlayState play_state;
    };

    void sendPlayingTrack(uint8_t track_number, int16_t track_time_sec,
                          PlayState play_state);
    void sendChangingDisc(uint8_t disc_number, uint8_t track_number,
                          ChangingStatus changing_status);
    void sendDiscInfo(uint8_t disc_number, uint8_t total_tracks,
                      uint16_t total_time_sec);
    void sendChangerErrorCode(ChangerErrorCode code);

    DiskTrackChange interpretSetDiskTrackMessage(const uint64_t message);

    // Somewhat mysterious initialization messages.
    void sendInit();
    void sendAvailableDiscs();
    void sendWait();

    boolean checkParity(uint64_t* message);

  private:
    void sendZero();
    void sendOne();
    void writeHexBitwise(uint8_t message);
    
    uint8_t pin_in_;
    uint8_t pin_out_;
};

#endif
