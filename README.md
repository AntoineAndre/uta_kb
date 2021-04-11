# Uta

__Minimalist media controller__

A 3-key handwired macro pad for music control with a rotary encoder.

![main_illustration](https://raw.githubusercontent.com/AntoineAndre/uta_kb/main/docs/main_illustration_uta_kb.png)

## Features

This keyboard is made to easily control mutlimedia playing with four common shortcuts. It has two keys for changing the song (previous and next) and one key to play/pause the music (or any media). The rotary encoder is used to change the volume.

![functions_render](https://raw.githubusercontent.com/AntoineAndre/uta_kb/main/docs/render_front.png)

| Rot_enc | Swich 1 | Switch 2 | Switch 3 |
|---------|---------|----------|----------|
| VOL_DWN |  PREV   |   PLAY   |   NEXT   |
| VOL_UP  |         |   PAUSE  |          |

Which can be summarized in:

![The default uta keymap](https://raw.githubusercontent.com/AntoineAndre/uta_kb/main/docs/keyboard_layout.png)


## Parts

Here are the different parts used for this macro pad:

- [ ] 1x Arduino Pro Micro (Atmega32u4)
- [ ] 1x rotary encoder
- [ ] 3x mechanical switches
- [ ] 3x keycaps
- [ ] 1x L-shaped 2 mm thick aluminium plate (top and front)
- [ ] 1x 2 mm thick aluminium plate (bottom)
- [ ] 3x 4 mm thick aluminium plate (left, right and back)
- [ ] 6x M2 screws

## Case build

The case is build with above mentionned parts, in aluminium<sup>1</sup>. Global dimensions of the macro pad, with the switches and keycaps is __85 x 45 x 27 mm__.

The right side of the case needs to be cut a little near to the bottom plate, in order to let the micro USB cable connect to the Arduino Pro Micro.

Holes of the left, right and back plate (with the 4mm wide aluminium plates) size 1.7 mm in diameter. A M2 threading tool is used to make the screws fix the assembly. Holes on the top plate are a bit larger to ensure that the screws fit properly in the threaded holes.

Bottom plate is fixed with cyanolite glue to the left, right and back plates. This way the keyboard is still unmoutable by removing the top and front parts (that are attached together since a L-shaped plate is used).

Make sure to add some isolant (electric tape for example) and fill the inside of the case so that there isn't any short-circuit (since the case is all in aluminium).

Technical drawing of the case:

![case_drawing](https://raw.githubusercontent.com/AntoineAndre/uta_kb/main/docs/uta_case.png)

The case is then painted with spray paint (same for the keycaps).

<sup>1</sup> It may be easier to 3d print the case, but I don't have and 3d printer now. Making the case in accrylic is also simpler since this material is easier to cut.

## Wiring

Since there are only three keys and an encoder used, the wiring doesn't need to imply a col/row matrix. The three switches are wired to the pins 4, 5 and 6 of the Arduino Pro Micro and the encoder A and B pins are wired to the A0 and A1 pins.

![wiring_schema](https://raw.githubusercontent.com/AntoineAndre/uta_kb/main/docs/wiring_schema.png)

The firmware uses the internal pullup resistor of the microchip, so there isn't any need to add resistor between switches and ground.

There is no formal obligation to respect this wiring. If some pins are changed, don't forget to change them accordingly for the firmware. A list of the actual atmega chip output pins can be seen [here](https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/ProMicro16MHzv1.pdf).

## Firmware

Once the wiring and the case is done, the only thing left is to program the keys. The Arduino Pro Micro can act as a keyboard on its own and there are two options to assign the keys to the switches. First one (lazy one) is to use the Arduino environment and second method uses the qmk firmware to flash the keymap on the Arduino.

### Arduino

For the first method, the program relies on two libraries used are the [HID project](https://github.com/NicoHood/HID) and the [Click encoder](https://github.com/0xPIT/encoder) ones.

The Arduino script for this method is available in the dedicated folder `/firmware`

Main drawback of this method is that there is a latency of 300 ms between each key stroke reading. However, since the rotary encoder is attach to an interrupt function there isn't any latency for the volume function.

Main advantage is that the code is easy to compile on the Arduino chip.

### QMK

Second method directly flashes the keys functions on the Arduino Pro Micro by using the [QMK firmware](https://github.com/qmk/qmk_firmware).

The different configuration files and keymaps are placed in a dedicated folder along with the compiled `.hex` file required to flash the Atmega32u4 using the qmk flash tool.

If different pins are used, they need to be changed in the `config.h` file and remplaced by the former pins of the atmega32u4.

For more information about the compiling and the flashing of a keyboard trhough the QMK tool, please refer to the [documentation](https://docs.qmk.fm/#/).

## Result

After building the case, handwiring the switches and configuring the firmware, the resulting keyboard looks as follow:

![uta_pic](https://raw.githubusercontent.com/AntoineAndre/uta_kb/main/docs/uta_result_pic.jpg)


![uta_pic2](https://raw.githubusercontent.com/AntoineAndre/uta_kb/main/docs/uta_result_pic2.jpg)

## Side notes

There is a list of possible ameliorations to this design:

- [ ] Proper PCB to avoid handwiring and better fixation of the Arduino
- [ ] 3d printable design for the case and the plate
- [ ] Remove the knob and remplace it by a linear encoder (to be placed on the front of the keys)