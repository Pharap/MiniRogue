#include "src/utils/Enums.h"
#include "src/utils/FadeEffects.h"
#include "src/fonts/Font3x5.h"


char const eventDice_Caption_01[] PROGMEM = "Found~Loot   ~+2~Gold";
char const eventDice_Caption_02[] PROGMEM = "Health~Potion   +2~HP";
char const eventDice_Caption_03[] PROGMEM = "Found~Meat    +1~Food";
char const eventDice_Caption_04[] PROGMEM = "Whetstone       +2~XP";
char const eventDice_Caption_05[] PROGMEM = "Found~Shield    +1~AR";
char const eventDice_Caption_06[] PROGMEM = "Monster         5~DMG";

char const * const eventDice_Captions[] = {
	eventDice_Caption_01,
	eventDice_Caption_02,
	eventDice_Caption_03,
	eventDice_Caption_04,
	eventDice_Caption_05,
	eventDice_Caption_06,
};

enum class Event_ViewState : uint8_t {
	RollDice,
	UpdateStats,
	PlayerDead
};

Event_ViewState event_ViewState = Event_ViewState::RollDice;


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void EventState_activate() {

  counter = 0;
  dice = 0;
  event_ViewState = Event_ViewState::RollDice;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void EventState_update() { 

  auto justPressed = arduboy.justPressedButtons();

  switch (event_ViewState) {

    case Event_ViewState::RollDice:
      
			if (counter < NO_OF_CARDS_IN_FLIP_13 - 1) {

				dice = random(1, 7);
				counter++;

			}      
			else {

        switch (dice) {

          case 1: playerStats.incGold(2);     break;
          case 2: playerStats.incHP(2);       break;
          case 3: playerStats.incFood(1);     break;
          case 4: playerStats.incXP(2);       break;
          case 5: playerStats.incArmour(1);   break;
          case 6:                             break;

        }

        event_ViewState = Event_ViewState::UpdateStats;
        counter = 0;

			}
			break;

    case Event_ViewState::UpdateStats:

      if (justPressed & A_BUTTON) { counter = FLASH_COUNTER; justPressed = A_BUTTON; }

      if (counter < FLASH_COUNTER) {

        counter++;

      }
      else {

        if (justPressed & A_BUTTON) { 

          if (dice < 6) {
            
            currentState = gameStats.incRoom(playerStats); 

          }
          else {
            currentState = GameStateType::MonsterFromEvent;
          }

        }

      }

      break;

		case Event_ViewState::PlayerDead:

      if (justPressed & A_BUTTON) { 
        currentState = GameStateType::PlayerDead;
			}

			break;

  }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void EventState_render() {
  

  // Render common parts ..

  for (int8_t i = -12; i < 80; i = i + 20) {
    ardBitmap.drawCompressed(i, 40, Images::Event_Background_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
  }

  renderBackground(true);
  
  switch (event_ViewState) {

    case Event_ViewState::RollDice:

      renderLargeSpinningCard(28, 8, counter);
      
      if (counter < NO_OF_CARDS_IN_FLIP_13) {

        if (Images::Large_Spinning_Inlays[counter] > 0) {
          for (uint8_t i = 0, j = 0; i < Images::Large_Spinning_Inlays[counter]; i++, j = j + 2) {
            ardBitmap.drawCompressed(32 + (counter * 2) + j, 8, Images::Large_Spinning_Card_Inlay, WHITE, ALIGN_NONE, MIRROR_NONE);
          }
        }

      }
      else {

        ardBitmap.drawCompressed(30, 10, Images::Event_Dice[dice - 1], WHITE, ALIGN_NONE, MIRROR_NONE);

      }

      break;

    case Event_ViewState::UpdateStats:

      renderLargeSpinningCard(28, 8, 0);
      ardBitmap.drawCompressed(30, 10, Images::Event_Dice[dice - 1], WHITE, ALIGN_NONE, MIRROR_NONE);
      font3x5.setCursor(4, 0);
      EventState_printEventName();

      break;

    case Event_ViewState::PlayerDead:

      renderPlayerDead();
      break;

  }

	// Player statistics ..

	static const FlashSettings diceHelper[] PROGMEM =
	{
		FlashSettings::None,
		FlashSettings::FlashGold,
		FlashSettings::FlashHP,
		FlashSettings::FlashFood,
		FlashSettings::FlashXP,
	};

	const FlashSettings settings = (dice < 5) ? static_cast<FlashSettings>(pgm_read_byte(&diceHelper[dice])) : FlashSettings::None;
	const bool shouldFlash = (event_ViewState == Event_ViewState::UpdateStats && counter < FLASH_COUNTER);

	renderPlayerStatistics(shouldFlash, settings);

}

void EventState_printEventName() {

  font3x5.print(FlashString(eventDice_Captions[dice - 1]));

}