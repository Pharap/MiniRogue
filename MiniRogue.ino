#include "src/utils/Arduboy2Ext.h"
#include "src/ardBitmap/ArdBitmap.h"
#include "src/utils/Enums.h"
#include "src/images/Images.h"
#include "src/fonts/Font3x5.h"

#ifndef DEBUG
ARDUBOY_NO_USB
#endif

Arduboy2Ext arduboy;
ArdBitmap<WIDTH, HEIGHT> ardBitmap;
PlayerStats playerStats;
GameStats gameStats;
GameStateType currentState;
GameStateType savedCurrentState;
GameStateType cards[7];

char const treasureDice_Caption_01[] PROGMEM = " Gain~a~Fire~Wand!";
char const treasureDice_Caption_02[] PROGMEM = " Gain~an~Ice~Wand!";
char const treasureDice_Caption_03[] PROGMEM = "Gain~a~Poison~Wand!";
char const treasureDice_Caption_04[] PROGMEM = "Gain~a~Healing~Wand!";
char const treasureDice_Caption_05[] PROGMEM = "  Gain~an~Armour!";
char const treasureDice_Caption_06[] PROGMEM = "Upgrade~your~Weapon!";
char const treasureDice_Caption_07[] PROGMEM = "Gain~2~Gold~Pieces!";
char const treasureDice_Caption_08[] PROGMEM = "Open~chest:\nGold~and~treasure!";
char const treasureDice_Caption_09[] PROGMEM = "Open~chest:\nYou~found~gold~only!";

char const * const treasureDice_Captions[] = {
	treasureDice_Caption_01,
	treasureDice_Caption_02,
	treasureDice_Caption_03,
	treasureDice_Caption_04,
	treasureDice_Caption_05,
	treasureDice_Caption_06,
	treasureDice_Caption_07,
	treasureDice_Caption_08,
	treasureDice_Caption_09,
}; 


uint8_t counter = 0;
Font3x5 font3x5;

void setup() {

	arduboy.boot();
	arduboy.flashlight();
	arduboy.systemButtons();
	arduboy.audio.begin();
	arduboy.initRandomSeed();
	arduboy.setFrameRate(60);

	this->currentState = GameStateType::SplashScreen;

  for (uint8_t i = 0; i < 6; i++) { 
    this->cards[i] = static_cast<GameStateType>(i + 1); 
  }

  this->cards[6] = GameStateType::BossMonster;

}

void loop() {

	auto &arduboy = this->context.arduboy;
	if (!arduboy.nextFrame()) return;

	arduboy.pollButtons();
	arduboy.clear();
	arduboy.display();
	
	switch (currentState) {

		case Resting:
			if (currentState != savedCurrentState) { 
				RestingState_activate();
			}
			RestingState_
	Treasure,
	Event,
  Merchant,
  Trap,
  Monster,
  BossMonster,
  MonsterFromEvent,
  GamePlay,
  ShowCards,
	SplashScreen,
	TitleScreen,
  Winner,
  PlayerDead
	}


}
