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
uint8_t dice = 1;

void setup() {

	arduboy.boot();
	arduboy.flashlight();
	arduboy.systemButtons();
	arduboy.audio.begin();
	arduboy.initRandomSeed();
	arduboy.setFrameRate(60);

	currentState = GameStateType::SplashScreen;

  for (uint8_t i = 0; i < 6; i++) { 
    cards[i] = static_cast<GameStateType>(i + 1); 
  }

  cards[6] = GameStateType::BossMonster;

}

void loop() {

	if (!arduboy.nextFrame()) return;

	arduboy.pollButtons();
	arduboy.clear();

	switch (currentState) {

		case GameStateType::Resting:
			if (currentState != savedCurrentState) { RestingState_activate(); savedCurrentState = currentState; }
			RestingState_update();
			RestingState_render();
			break;

		case GameStateType::Treasure:
			if (currentState != savedCurrentState) { TreasureState_activate(); savedCurrentState = currentState; }
			TreasureState_update();
			TreasureState_render();
			break;

		case GameStateType::Event:
			if (currentState != savedCurrentState) { EventState_activate();	savedCurrentState = currentState; }
			EventState_update();
			EventState_render();
			break;

		case GameStateType::Merchant:
			if (currentState != savedCurrentState) { MerchantState_activate(); savedCurrentState = currentState; }
			MerchantState_update();
			MerchantState_render();
			break;

		case GameStateType::Trap:
			if (currentState != savedCurrentState) { TrapState_activate(); savedCurrentState = currentState; }
			TrapState_update();
			TrapState_render();
			break;

		case GameStateType::Monster:
		case GameStateType::BossMonster:
		case GameStateType::MonsterFromEvent:
			if (currentState != savedCurrentState) { FightMonsterState_activate(); savedCurrentState = currentState; }
			FightMonsterState_update();
			FightMonsterState_render();
			break;

		case GameStateType::ShowCards:
			if (currentState != savedCurrentState) { ShowCardsState_activate();	savedCurrentState = currentState; }
			ShowCardsState_update();
			ShowCardsState_render();
			break;

		case GameStateType::SplashScreen:
			if (currentState != savedCurrentState) { SplashScreenState_activate(); savedCurrentState = currentState; }
			SplashScreenState_update();
			SplashScreenState_render();
			break;

		case GameStateType::TitleScreen:
			if (currentState != savedCurrentState) { TitleScreenState_activate(); savedCurrentState = currentState; }
			TitleScreenState_update();
			TitleScreenState_render();
			break;

		case GameStateType::Winner:
		case GameStateType::PlayerDead:
			if (currentState != savedCurrentState) { GameOverState_activate(); savedCurrentState = currentState; }
			GameOverState_update();
			GameOverState_render();
			break;

		default: break;

	}

	arduboy.display();

}
