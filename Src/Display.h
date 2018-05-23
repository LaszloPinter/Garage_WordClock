/*
 * WiledCore.h
 *
 *  Created on: Dec 4, 2016
 *      Author: pinterlaszlo
 */
#include <Arduino.h>
#include "LedControl.h"
#include "Time.h"
#include "DS1302RTC.h"

#ifndef WILEDCORE_H_
#define WILEDCORE_H_

class Display {
public:
	void init();
	void loop();
	unsigned long READ_MILLIS = 1000; //How much milliseconds between two clock reads.
	unsigned long lastReadTime = 0;

	unsigned long TIME_SET_DELAY = 2000; //How much milliseconds after the last rotation before going back to normal mode
	unsigned long lastRotationTime = 0;
	boolean timeChangedManually = false;

	const byte ROTARY_CLK_PIN = 3;
	const byte ROTARY_DT_PIN = 2;
	const byte ROTARY_SW_PIN = 4;

	boolean isMinuteMode = true;

	unsigned long BUTTON_DEBOUNCE_MILLIS = 8;
	unsigned long lastButtonTime = 0;
	bool isModeChanged = false;
	int lastButtonState = HIGH;

	int lastEncoded = 0;
	void rotatedLeft();
	void rotatedRight();

	const int DIN_PIN = 7;
	const int CS_PIN = 6;
	const int CLK_PIN = 5;
	const int NUM_DEVICES = 4;

	const int RTC_CLK_PIN = 9;
	const int RTC_DAT_PIN = 10;
	const int RTC_RST_PIN = 11;


	const int ADDR_TOP_LEFT = 3;
	const int ADDR_TOP_RIGHT = 2;
	const int ADDR_BOT_LEFT = 1;
	const int ADDR_BOT_RIGHT = 0;

	// min >
	const int OFFSET = 2;
	const int PAST5 = 5 - OFFSET;
	const int PAST10 = 10 - OFFSET;
	const int PAST15 = 15 - OFFSET;
	const int PAST20 = 20 - OFFSET;
	const int PAST25 = 25 - OFFSET;
	const int PAST30 = 30 - OFFSET;

	const int TO25 = 35 - OFFSET;
	const int TO20 = 40 - OFFSET;
	const int TO15 = 45 - OFFSET;
	const int TO10 = 50 - OFFSET;
	const int TO5 = 55 - OFFSET;
	const int TO0 = 60 - OFFSET;

	int hrs = 5;
	int min = 50;

	uint64_t frameTopLeft = 0;
	uint64_t frameTopRight = 0;
	uint64_t frameBotLeft = 0;
	uint64_t frameBotRight = 0;

	LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN, NUM_DEVICES);
	DS1302RTC rtc = DS1302RTC(RTC_RST_PIN, RTC_DAT_PIN, RTC_CLK_PIN);

private:

	void initFrame(byte addr);
	static void onRotary();
	void checkRTC();
	void checkManualSet();
	void checkButton();
	void forceTimeOnRTC();

	void clearAllFrames();
	void pushAllFrames();
	void pushFrame(uint64_t image, int addr);
	void updateFrames();
	void setTime(int hrs, int minutes);
	void onTimeChanged();
	void checkEncoder();
	void handleEncoder();

	void updateItIs();
	void updateOne();
	void updateTwo();
	void updateThree();
	void updateFour();
	void updateFive();
	void updateSix();
	void updateSeven();
	void updateEight();
	void updateNine();
	void updateTen();
	void updateEleven();
	void updateTwelve();
	void updateTo();
	void updatePast();
	void updateHalf();
	void updateQuarter();
	void updateTwenty();
	void updateMinuteFive();
	void updateMinuteTen();
	void updateOclock();
	void updateBorder();

	int fp(int pnt);
	void chunkTime();

	const uint64_t TOP_EDGE[9] = {
	  0x0000000000000000,
	  0x0000000000000001,
	  0x0000000000000003,
	  0x0000000000000007,
	  0x000000000000000f,
	  0x000000000000001f,
	  0x000000000000003f,
	  0x000000000000007f,
	  0x00000000000000ff
	};

	const uint64_t RIGHT_EDGE[9] = {
	  0x0000000000000000,
	  0x0000000000000080,
	  0x0000000000008080,
	  0x0000000000808080,
	  0x0000000080808080,
	  0x0000008080808080,
	  0x0000808080808080,
	  0x0080808080808080,
	  0x8080808080808080
	};

	const uint64_t BOT_EDGE[9] = {
	  0x0000000000000000,
	  0x8000000000000000,
	  0xc000000000000000,
	  0xe000000000000000,
	  0xf000000000000000,
	  0xf800000000000000,
	  0xfc00000000000000,
	  0xfe00000000000000,
	  0xff00000000000000
	};

	const uint64_t LEFT_EDGE[9] = {
	  0x0000000000000000,
	  0x0100000000000000,
	  0x0101000000000000,
	  0x0101010000000000,
	  0x0101010100000000,
	  0x0101010101000000,
	  0x0101010101010000,
	  0x0101010101010100,
	  0x0101010101010101
	};

};

#endif /* WILEDCORE_H_ */
