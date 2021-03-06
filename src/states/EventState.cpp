#include "EventState.h"
#include "../images/Images.h"
#include "../utils/Utils.h"
#include "../utils/Enums.h"
#include "../fonts/Font3x5.h"

constexpr const static uint8_t NO_OF_CARDS_IN_FLIP = 13; 


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void EventState::activate(StateMachine & machine) {

  (void)machine;
  
  viewState = ViewState::RollDice;
  counter = 0;
  dice = 0;

}

// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void EventState::update(StateMachine & machine) { 

	auto & arduboy = machine.getContext().arduboy;
	auto & playerStats = machine.getContext().playerStats;
	auto & gameStats = machine.getContext().gameStats;
  auto justPressed = arduboy.justPressedButtons();

  switch (this->viewState) {

    case ViewState::RollDice:
      
			if (counter < NO_OF_CARDS_IN_FLIP - 1) {

				this->dice = random(1, 7);
				counter++;

			}      
			else {

        switch (this->dice) {

          case 1: playerStats.incGold(2);     break;
          case 2: playerStats.incHP(2);       break;
          case 3: playerStats.incFood(1);     break;
          case 4: playerStats.incXP(2);       break;
          case 5: playerStats.incArmour(1);   break;
          case 6:                             break;

        }

        this->viewState = ViewState::UpdateStats;
        this->counter = 0;

			}
			break;

    case ViewState::UpdateStats:

      if (justPressed & A_BUTTON) { this->counter = FLASH_COUNTER; justPressed = A_BUTTON; }

      if (this->counter < FLASH_COUNTER) {

        this->counter++;

      }
      else {

        if (justPressed & A_BUTTON) { 

          if (this->dice < 6) {
            
            machine.changeState(gameStats.incRoom(playerStats)); 

          }
          else {
            machine.changeState(GameStateType::MonsterFromEvent);
          }

        }

      }

      break;

		case ViewState::PlayerDead:

      if (justPressed & A_BUTTON) { 
        machine.changeState(GameStateType::PlayerDead);
			}

			break;

  }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void EventState::render(StateMachine & machine) {

  auto & ardBitmap = machine.getContext().ardBitmap;
  

  // Render common parts ..

  for (int8_t i = -12; i < 80; i = i + 20) {
    ardBitmap.drawCompressed(i, 40, Images::Event_Background_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
  }

  BaseState::renderBackground(machine, true);
  
  switch (this->viewState) {

    case ViewState::RollDice:

      BaseState::renderLargeSpinningCard(machine, 28, 8, this->counter);
      
      if (counter < NO_OF_CARDS_IN_FLIP) {

        if (Images::Large_Spinning_Inlays[this->counter] > 0) {
          for (uint8_t i = 0, j = 0; i < Images::Large_Spinning_Inlays[this->counter]; i++, j = j + 2) {
            ardBitmap.drawCompressed(32 + (this->counter * 2) + j, 8, Images::Large_Spinning_Card_Inlay, WHITE, ALIGN_NONE, MIRROR_NONE);
          }
        }

      }
      else {

        ardBitmap.drawCompressed(30, 10, Images::Event_Dice[this->dice - 1], WHITE, ALIGN_NONE, MIRROR_NONE);

      }

      break;

    case ViewState::UpdateStats:

      BaseState::renderLargeSpinningCard(machine, 28, 8, 0);
      ardBitmap.drawCompressed(30, 10, Images::Event_Dice[this->dice - 1], WHITE, ALIGN_NONE, MIRROR_NONE);
      font3x5.setCursor(4, 0);
      printEventName();

      break;

    case ViewState::PlayerDead:

      BaseState::renderPlayerDead();
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

	const FlashSettings settings = (this->dice < 5) ? static_cast<FlashSettings>(pgm_read_byte(&diceHelper[this->dice])) : FlashSettings::None;
	const bool shouldFlash = (this->viewState == ViewState::UpdateStats && this->counter < FLASH_COUNTER);

	BaseState::renderPlayerStatistics(machine, shouldFlash, settings);

}

void EventState::printEventName() {

  font3x5.print(FlashString(eventDice_Captions[this->dice - 1]));

}