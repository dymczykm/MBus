## Alpine M-Bus library for Arduino

This is a heavily modified library forked from:
https://github.com/Olstyle/MBus

The changes include:
* added several new protocol messages, including more detailed changing messages and error messages
* introduced interrupts to handle receiving of messages
* introduced messages specific to Alpine 7909 and potentially other early Alpine headunits
* reformatted the code to fit the Google c++ styleguide I'm more used to

Since commits in October 2023, the library has been developed and tested on Teensy 4.0/4.1.

### Other M-Bus references
* https://github.com/4nykey/rockbox/blob/master/apps/plugins/alpine_cdc.c
* http://web.archive.org/web/20100308084922/http://kiora.ath.cx/alpine/
* https://github.com/picohari/atmega128_alpine-mbus-emulator
* https://github.com/kjanesch/pseudochanger (Panasonic version)
* https://www.avrfreaks.net/projects/alpine-m-bus-communication-audio-input-activation
* https://github.com/timotto/UbarCDC/tree/master
* https://github.com/timotto/AsyncMBus


### Original readme of Oliver Mueller

This is an Arduino library to emulate Alpines M-Bus which is used on a variety of car radios.
You can send and receive messages as well as send special messages which trick the radio in believing it communicates with an cd changer.

Electrically, you'd want to have a piece of circuitry to split the send and receive line which is shown here(not my website):
http://www.hohensohn.info/mbus/index.htm
I also used this site for reference on the bus itself.


### License

Copyright 2012 Oliver Mueller
Copyright 2020-2023 Marcin Dymczyk

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
