ifeq ($(OS),Windows_NT)
SHELL = $(ComSpec)
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/Display.cpp.o \
	project/LedControl.cpp.o \
	project/WordClock.cpp.o \

PLATFORM_CORE_OBJS = \
	core/PluggableUSB.cpp.o \
	core/wiring_pulse.c.o \
	core/Tone.cpp.o \
	core/wiring.c.o \
	core/wiring_shift.c.o \
	core/IPAddress.cpp.o \
	core/wiring_digital.c.o \
	core/WString.cpp.o \
	core/Print.cpp.o \
	core/new.cpp.o \
	core/abi.cpp.o \
	core/wiring_pulse.S.o \
	core/HardwareSerial.cpp.o \
	core/Stream.cpp.o \
	core/HardwareSerial1.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/hooks.c.o \
	core/HardwareSerial2.cpp.o \
	core/HardwareSerial3.cpp.o \
	core/WInterrupts.c.o \
	core/wiring_analog.c.o \
	core/main.cpp.o \
	core/CDC.cpp.o \
	core/USBCore.cpp.o \
	core/WMath.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \

TARGETS = \
	WordClock.hex \

all: $(TARGETS)

WordClock.hex: WordClock.elf
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-objcopy" -O ihex -R .eeprom  "./WordClock.elf" "./WordClock.hex"

WordClock.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -w -Os -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p  -o "./WordClock.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS) "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-size" -A "./WordClock.elf"

project/Display.cpp.o: ../../Display.cpp project/Display.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"

project/Display.cpp.d: ;

-include project/Display.cpp.d 

project/LedControl.cpp.o: ../../LedControl.cpp project/LedControl.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"

project/LedControl.cpp.d: ;

-include project/LedControl.cpp.d 

project/WordClock.cpp.o: ../../WordClock.cpp project/WordClock.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"

project/WordClock.cpp.d: ;

-include project/WordClock.cpp.d 


core/PluggableUSB.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/wiring_pulse.c.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/Tone.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/wiring.c.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_shift.c.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/IPAddress.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/wiring_digital.c.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/WString.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d

core/Print.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/new.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/abi.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/wiring_pulse.S.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/Stream.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/HardwareSerial1.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/HardwareSerial0.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/hooks.c.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/HardwareSerial2.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/HardwareSerial3.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/WInterrupts.c.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/wiring_analog.c.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/main.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/CDC.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/USBCore.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/WMath.cpp.o: /Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/cores/arduino" -I"/Users/pinterlaszlo/.arduinocdt/packages/arduino/hardware/avr/1.6.15/variants/eightanaloginputs" "$<" -o "$@"
	"/Users/pinterlaszlo/.arduinocdt/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d



