/*
 * DisplayCore.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: pinterlaszlo
 */
#include "Display.h"

#include <Arduino.h>
#include "LedControl.h"

int i = 0;
static Display* self;

void Display::init() {
	self = this;
	initFrame(0);
	initFrame(1);
	initFrame(2);
	initFrame(3);

	pinMode(ROTARY_CLK_PIN, INPUT_PULLUP);
	pinMode(ROTARY_DT_PIN, INPUT_PULLUP);
	pinMode(ROTARY_SW_PIN, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(ROTARY_CLK_PIN), onRotary, CHANGE);
	attachInterrupt(digitalPinToInterrupt(ROTARY_DT_PIN), onRotary, CHANGE);

}

void Display::forceTimeOnRTC() {
    tmElements_t time;
    time.Hour = hrs;
    time.Minute = min;
    time.Second = 55;
    rtc.set(makeTime(time));
}

void Display::checkRTC() {
	if(!timeChangedManually && (millis() - lastReadTime > READ_MILLIS)) {
		lastReadTime = millis();
		  tmElements_t tm;
		  rtc.read(tm);
		  setTime(tm.Hour, tm.Minute);
	}
}

void Display::checkManualSet() {
	if(timeChangedManually && (millis() - lastRotationTime > TIME_SET_DELAY)) {
		forceTimeOnRTC();
		timeChangedManually = false;
	}
}

void Display::checkButton() {
	int read = digitalRead(ROTARY_SW_PIN);
	if (read != lastButtonState) {
	    lastButtonTime = millis();
	 }

	if(millis() - lastButtonTime > BUTTON_DEBOUNCE_MILLIS) {
		if (read == LOW) {
			if (!isModeChanged) {
				isMinuteMode = !isMinuteMode;
				isModeChanged = true;
			}
		} else {
			isModeChanged = false;
		}
	}

	lastButtonState = read;
}

static void Display::onRotary() {
	cli();
	self->handleEncoder();
	sei();
}

void Display::rotatedLeft() {
	if (isMinuteMode) {
		min -= 1;
	} else {
		hrs -= 1;
	}
	onTimeChanged();
}

void Display::rotatedRight() {
	if (isMinuteMode) {
		min += 1;
	} else {
		hrs += 1;
	}
	onTimeChanged();
}

void Display::handleEncoder() {
	delay(2);
	timeChangedManually = true;
	lastRotationTime = millis();
	int MSB = digitalRead(ROTARY_DT_PIN);
	int LSB = digitalRead(ROTARY_CLK_PIN);
	int encoded = (MSB<<1)|LSB;
	int sum = (lastEncoded << 2)|encoded;

	if (sum == 0b1101  || sum == 0b0010) { //|| sum == 0b0100 || sum == 0b0010 || sum == 0b1011
		rotatedRight();
	}

	if (sum == 0b1110  || sum == 0b0001) { //|| sum == 0b0111 || sum == 0b0001 || sum == 0b1000
		rotatedLeft();
	}
	lastEncoded = encoded;
}

void Display::chunkTime() {
	while (min < 0) {
		min += 60;
		hrs -= 1;
	}

	while (min >= 60) {
		min -= 60;
		hrs += 1;
	}

	while (hrs < 1) {
		hrs += 12;
	}

	while (hrs >= 13) {
		hrs -= 12;
	}
}

void Display::initFrame(byte addr) {
	display.clearDisplay(addr);
	display.shutdown(addr, false);
	display.setIntensity(addr, 15);
}

void Display::clearAllFrames() {
	frameTopLeft = 0;
	frameTopRight = 0;
	frameBotLeft = 0;
	frameBotRight = 0;
}

void Display::pushAllFrames() {
	pushFrame(frameTopLeft, ADDR_TOP_LEFT);
	pushFrame(frameTopRight, ADDR_TOP_RIGHT);
	pushFrame(frameBotLeft, ADDR_BOT_LEFT);
	pushFrame(frameBotRight, ADDR_BOT_RIGHT);
}

void Display::updateFrames() {
	clearAllFrames();
	updateItIs();
	updateOne();
	updateTwo();
	updateThree();
	updateFour();
	updateFive();
	updateSix();
	updateSeven();
	updateEight();
	updateNine();
	updateTen();
	updateEleven();
	updateTwelve();
	updateMinuteFive();
	updateMinuteTen();
	updateQuarter();
	updateTwenty();
	updateHalf();
	updatePast();
	updateTo();
	updateOclock();
	updateBorder();
}

void Display::setTime(int hrs, int minutes) {
	this->hrs = hrs;
	this->min = minutes;
	onTimeChanged();
}

void Display::pushFrame(uint64_t image, int addr) {
	for (int i = 0; i < 8; i++) {
		byte row = (image >> i * 8) & 0xFF;
		for (int j = 0; j < 8; j++) {
			display.setLed(addr, i, j, bitRead(row, j));
		}
	}
}

void Display::onTimeChanged() {
	chunkTime();
	updateFrames();
	pushAllFrames();
}

void Display::loop() {
	checkManualSet();
	checkRTC();
	checkButton();

}

//Here comes the hotstepper
void Display::updateItIs() {
	frameTopLeft += 0x00000000006c0000;
}

void Display::updateOne() {
	if ((hrs == 12 && min > TO25) || (hrs == 1 && min <= TO25)) {
		//frameTopLeft += 0x1c00000000000000;
		frameTopLeft = frameTopLeft | 0x1c00000000000000;

	}
}

void Display::updateTwo() {
	if ((hrs == 1 && min > TO25) || (hrs == 2 && min <= TO25)) {
		//frameTopLeft += 0xe000000000000000;
		frameTopLeft = frameTopLeft | 0xe000000000000000;
	}
}

void Display::updateThree() {
	if ((hrs == 2 && min > TO25) || (hrs == 3 && min <= TO25)) {
		//frameTopRight += 0x1f00000000000000;
		frameTopRight = frameTopRight | 0x1f00000000000000;
	}
}

void Display::updateFour() {
	if ((hrs == 3 && min > TO25) || (hrs == 4 && min <= TO25)) {
		//frameBotLeft += 0x000000000000003c;
		frameBotLeft = frameBotLeft | 0x000000000000003c;
	}
}

void Display::updateFive() {
	if ((hrs == 4 && min > TO25) || (hrs == 5 && min <= TO25)) {
		//frameBotLeft += 0x00000000000000c0;
		//frameBotRight += 0x0000000000000003;
		frameBotLeft = frameBotLeft | 0x00000000000000c0;
		frameBotRight = frameBotRight | 0x0000000000000003;
	}
}

void Display::updateSix() {
	if ((hrs == 5 && min > TO25) || (hrs == 6 && min <= TO25)) {
		//frameBotRight += 0x000000000000001c;
		frameBotRight = frameBotRight | 0x000000000000001c;
	}
}

void Display::updateSeven() {
	if ((hrs == 6 && min > TO25) || (hrs == 7 && min <= TO25)) {
		//frameTopLeft += 0x0080000000000000;
		//frameTopRight += 0x000f000000000000;
		frameTopLeft = frameTopLeft | 0x0080000000000000;
		frameTopRight = frameTopRight | 0x000f000000000000;
	}
}

void Display::updateEight() {
	if ((hrs == 7 && min > TO25) || (hrs == 8 && min <= TO25)) {
		//frameBotLeft += 0x00000000007c0000;
		frameBotLeft = frameBotLeft | 0x00000000007c0000;

	}
}

void Display::updateNine() {
	if ((hrs == 8 && min > TO25) || (hrs == 9 && min <= TO25)) {
		//frameBotLeft += 0x0000000000003c00;
		frameBotLeft = frameBotLeft | 0x0000000000003c00;

	}
}

void Display::updateTen() {
	if ((hrs == 9 && min > TO25) || (hrs == 10 && min <= TO25)) {
		//frameBotLeft += 0x000000001c000000;
		frameBotLeft = frameBotLeft | 0x000000001c000000;
	}
}

void Display::updateEleven() {
	if ((hrs == 10 && min > TO25) || (hrs == 11 && min <= TO25)) {
		//frameBotLeft += 0x0000000000800000;
		//frameBotRight += 0x00000000001f0000;
		frameBotLeft = frameBotLeft | 0x0000000000800000;
		frameBotRight = frameBotRight | 0x00000000001f0000;
	}
}

void Display::updateTwelve() {
	if ((hrs == 11 && min > TO25) || (hrs == 12 && min <= TO25)) {
		//frameBotLeft += 0x0000000000008000;
		//frameBotRight += 0x0000000000001f00;
		frameBotLeft = frameBotLeft | 0x0000000000008000;
		frameBotRight = frameBotRight | 0x0000000000001f00;
	}
}

void Display::updateTo() {
	if (min < TO0 && min > TO25) {
		//frameTopRight += 0x0000180000000000;
		frameTopRight = frameTopRight | 0x0000180000000000;
	}
}

void Display::updatePast() {
	if (min > PAST5 && min <= TO25) {
		//frameTopLeft += 0x003c000000000000;
		frameTopLeft = frameTopLeft | 0x003c000000000000;

	}
}

void Display::updateQuarter() {
	if ((min > PAST15 && min <= PAST20) || (min > TO15 && min <= TO10)) {
		//frameTopLeft += 0x00000000f8000000;
		//frameTopRight += 0x0000000003000000;
		frameTopLeft = frameTopLeft | 0x00000000f8000000;
		frameTopRight = frameTopRight | 0x0000000003000000;
	}
}

void Display::updateHalf() {
	if (min > PAST30 && min <= TO25) {
		//frameTopLeft += 0x00003c0000000000;
		frameTopLeft = frameTopLeft | 0x00003c0000000000;
	}
}

void Display::updateTwenty() {
	if ((min > PAST20 && min <= PAST30) || (min <= TO15 && min > TO25)) {
		//frameTopLeft += 0x000000fc00000000;
		frameTopLeft = frameTopLeft | 0x000000fc00000000;
	}
}

void Display::updateMinuteTen() {
	if ((min > PAST10 && min <= PAST15) || (min > TO10 && min <= TO5)) {
		frameTopLeft = frameTopLeft | 0x0000800000000000;
		frameTopRight = frameTopRight | 0x0000030000000000;
	}
}

void Display::updateMinuteFive() {
	if ((min > PAST5 && min <= PAST10) || (min >= PAST25 && min <= PAST30)
			|| (min > TO25 && min <= TO20) || (min > TO5 && min < TO0)) {
		//frameTopRight += 0x0000001e00000000;
		frameTopRight = frameTopRight | 0x0000001e00000000;
	}
}

void Display::updateOclock() {
	if (min >= TO0 || min <= PAST5) {
		//frameBotLeft += 0x0000000080000000;
		//frameBotRight += 0x000000001f000000;
		frameBotLeft = frameBotLeft | 0x0000000080000000;
		frameBotRight = frameBotRight | 0x000000001f000000;
	}
}

int Display::fp(int pnt) {
	if (pnt < 0) {
		pnt = 0;
	}
	if (pnt > 8) {
		pnt = 8;
	}
	return pnt;
}

void Display::updateBorder() {
	int m = min + 1 + 8;
	int topLeft = fp(m - 52 - 8);
	int topRight = fp(m - 8);
	int rightTop = fp(m - 15);
	int rightBot = fp(m - 23);
	int botRight = fp(m - 30);
	int botLeft = fp(m - 38);
	int leftBot = fp(m - 45);
	int leftTop = fp(m - 53);

	frameTopLeft = frameTopLeft | TOP_EDGE[topLeft] | LEFT_EDGE[leftTop];
	frameTopRight = frameTopRight | TOP_EDGE[topRight] | RIGHT_EDGE[rightTop];
	frameBotRight = frameBotRight | RIGHT_EDGE[rightBot] | BOT_EDGE[botRight];
	frameBotLeft = frameBotLeft | LEFT_EDGE[leftBot] | BOT_EDGE[botLeft];
}
