#include "src/utils/Enums.h"

char const level_Caption_01[] PROGMEM = "Easy:";
char const level_Caption_02[] PROGMEM = "Normal:";
char const level_Caption_03[] PROGMEM = "Hard:";
char const level_Caption_04[] PROGMEM = "Hell:";

char const * const level_Captions[] = {
	level_Caption_01,
	level_Caption_02,
	level_Caption_03,
	level_Caption_04,
};

enum class GameOver_ViewState : uint8_t {
  PlayerDead,
  Winner,
  HighScore
};

GameOver_ViewState gameOver_ViewState = GameOver_ViewState::PlayerDead;
uint8_t score = 123;
uint8_t highScore = 146;

#define EEPROM_START                  EEPROM_STORAGE_SPACE_START + 130
#define EEPROM_START_C1               EEPROM_START
#define EEPROM_START_C2               EEPROM_START + 1
#define EEPROM_SCORE                  EEPROM_START + 2


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void GameOverState_activate() {
	
	initEEPROM(false);

	switch (currentState) {

		case GameStateType::PlayerDead:
			gameOver_ViewState = GameOver_ViewState::PlayerDead; 
			break;

		case GameStateType::Winner:
			gameOver_ViewState = GameOver_ViewState::Winner; 
			break;

		default: break;

	}

	score = 0;
	score += (gameStats.skillLevel * 3);
	score += (playerStats.xpTrack * 2);
	score += ((gameStats.level + 1) * 3);
	score += (playerStats.hp * 2);
	score += (playerStats.food);
	score += (playerStats.armour);
	score += (playerStats.gold * 2);
	score += (playerStats.bossesKilled * 2);
	score += (playerStats.itemCount());

	highScore = EEPROM.read(EEPROM_SCORE);

	if (score > highScore) {

		highScore = score;
		EEPROM.update(EEPROM_SCORE, score);

	}

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void GameOverState_update() { 

  auto justPressed = arduboy.justPressedButtons();

  if (justPressed & A_BUTTON) { 
		
		switch (gameOver_ViewState) {

			case GameOver_ViewState::PlayerDead:
			case GameOver_ViewState::Winner: 
				gameOver_ViewState = GameOver_ViewState::HighScore; 
				break;

			case GameOver_ViewState::HighScore:
				currentState = GameStateType::TitleScreen; 
				break;

		}

	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void GameOverState_render() {

	renderTitleBackground(gameOver_ViewState != GameOver_ViewState::HighScore);

	switch (gameOver_ViewState) {

		case GameOver_ViewState::PlayerDead:
			ardBitmap.drawCompressed(29, 21, Images::Title_Game_Over_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
			break;

		case GameOver_ViewState::Winner:
			ardBitmap.drawCompressed(24, 15, Images::Winner_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
			break;

		case GameOver_ViewState::HighScore:
			{
				ardBitmap.drawCompressed(20, 21, Images::High_Score_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);

				font3x5.setCursor(23, 20);
				font3x5.print(FlashString(level_Captions[ static_cast<uint8_t>(gameStats.skillLevel) ]));
				font3x5.setCursor(56, 20);
				renderTwoDigitNumeric(gameStats.skillLevel * 3);

				font3x5.setCursor(33, 29);
				renderTwoDigitNumeric(playerStats.xpTrack * 2);
				renderTwoDigitNumeric((gameStats.level + 1) * 3);
				renderTwoDigitNumeric(playerStats.hp * 2);
				renderTwoDigitNumeric(playerStats.food);

				font3x5.setCursor(56, 29);
				renderTwoDigitNumeric(playerStats.armour);
				renderTwoDigitNumeric(playerStats.gold * 2);
				renderTwoDigitNumeric(playerStats.bossesKilled * 2);
				renderTwoDigitNumeric(playerStats.itemCount());

				font3x5.setCursor(95, 20);
				renderThreeDigitNumeric(score);
				font3x5.setCursor(95, 29);
				renderThreeDigitNumeric(highScore);

			}
			break;


	}


}

void renderTwoDigitNumeric(uint8_t val) { 

	if (val < 10) font3x5.print(F("0"));
	font3x5.print(val);
	font3x5.print(F("\n"));

}

void renderThreeDigitNumeric(uint8_t val) { 

	if (val < 100) font3x5.print(F("0"));
	if (val < 10) font3x5.print(F("0"));

	font3x5.print(val);
	font3x5.print(F("\n"));

}


/* ----------------------------------------------------------------------------
 *   Is the EEPROM initialised?
 *
 *   Looks for the characters 'A' and 'R' in the first two bytes of the EEPROM
 *   memory range starting from byte EEPROM_STORAGE_SPACE_START.  If not found,
 *   it resets the settings ..
 */

const uint8_t letter1 = 'M'; 
const uint8_t letter2 = 'R'; 

void initEEPROM(bool forceClear) {

  byte c1 = EEPROM.read(EEPROM_START_C1);
  byte c2 = EEPROM.read(EEPROM_START_C2);

  if (forceClear || c1 != letter1 || c2 != letter2) { 

    uint8_t score = 0;

    EEPROM.update(EEPROM_START_C1, letter1);
    EEPROM.update(EEPROM_START_C2, letter2);
    EEPROM.put(EEPROM_SCORE, score);

  }

}