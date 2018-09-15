#include "src/utils/Enums.h"
#include "src/utils/FadeEffects.h"
#include "src/fonts/Font3x5.h"

enum class Treasure_ViewState : uint8_t {
InitialRoll,
RollDice,
UpdateStats
};

Treasure_ViewState treasure_ViewState = Treasure_ViewState::InitialRoll;

bool foundTreasure = false;


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void TreasureState_activate() { 

  counter = 0;
  dice = 0;
  foundTreasure = false;
  treasure_ViewState = Treasure_ViewState::InitialRoll;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void TreasureState_update() { 

  auto justPressed = arduboy.justPressedButtons();

  switch (treasure_ViewState) {

    case Treasure_ViewState::InitialRoll:

      if (counter < sizeof(DiceDelay) && (justPressed & A_BUTTON)) { 
        
        counter = sizeof(DiceDelay); 
        dice = random(1, 7);

      }
            
			if (counter < sizeof(DiceDelay)) {
				
				if (arduboy.everyXFrames(pgm_read_byte(&DiceDelay[counter]))) {

					dice = random(1, 7);
					counter++;
					arduboy.resetFrameCount();

				}

			}
			else {

        if (dice >= 5) {
          
          if (justPressed & A_BUTTON) {

            counter = NO_OF_CARDS_IN_FLIP;
            treasure_ViewState = Treasure_ViewState::RollDice;
            dice = random(1, 7);

          }

        }
        else {

          playerStats.incGold(gameStats.monsterDefeated ? 2 : 1);
          counter = 0;
          treasure_ViewState = Treasure_ViewState::UpdateStats;   

        }

			}
			break;

    case Treasure_ViewState::RollDice:

			if (counter > 0) {

				dice = random(1, 7);
				counter--;

			} 
			else {
          
        foundTreasure = true;
        if (playerStats.itemCount() >= 2 && dice < 5) dice = 7;

        switch (dice) {

          case 1 ... 4:   playerStats.items[dice - 1]++; break;
          case 5:         playerStats.incArmour(1); break;
          case 6:         playerStats.incXP(2); break;
          case 7:         playerStats.incGold(2); break;

        }
          
        counter = 0;
        treasure_ViewState = Treasure_ViewState::UpdateStats;
        playerStats.incGold(gameStats.monsterDefeated ? 2 : 1);

			}
			break;


    case Treasure_ViewState::UpdateStats:

      if (counter < FLASH_COUNTER) {

        counter++;

      }

      if (justPressed & A_BUTTON) {

        currentState = gameStats.incRoom(playerStats); 

      }

      break;

  }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void TreasureState_render() {
  
  const bool flash = arduboy.getFrameCountHalf(FLASH_DELAY);


  // Render common parts ..

  renderBackground(true);
  ardBitmap.drawCompressed(0, 0, Images::Chest_Background_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);

  switch (treasure_ViewState) {

    case Treasure_ViewState::InitialRoll:

      if (counter < sizeof(DiceDelay)) {
       
        ardBitmap.drawCompressed(14, 16, Images::Chest_Closed_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
        SpritesB::drawSelfMasked(48, 1, Images::Dice, dice);
      
        font3x5.setCursor(3, 2);
        font3x5.print(F("Open~chest:"));

      }
      else {

        TreasureState_renderChestResults();

      }

      break;

    case Treasure_ViewState::RollDice:

      TreasureState_renderSelectTreasure();
      break;

    case Treasure_ViewState::UpdateStats:

      if (foundTreasure) {

        TreasureState_renderSelectTreasure();

      }
      else {

        TreasureState_renderChestResults();

      }

      break;

  }


	// Player statistics ..

	FlashSettings settings = FlashSettings::FlashGold;

	if (dice == 6)        		              settings |= FlashSettings::FlashXP;
	else if (dice == 5)    		              settings |= FlashSettings::FlashArmour;
	else if (dice == 4 && foundTreasure)	  settings |= FlashSettings::FlashHP;

	const bool shouldFlash = (treasure_ViewState == Treasure_ViewState::UpdateStats && counter < FLASH_COUNTER);

	renderPlayerStatistics(shouldFlash, settings);

  if (treasure_ViewState == Treasure_ViewState::UpdateStats && foundTreasure && counter < FLASH_COUNTER && flash) {

    font3x5.setCursor(8, 0);
    TreasureState_printCaption(dice - 1); 

  }

}

void TreasureState_printCaption(uint8_t index) {

  font3x5.print(FlashString(treasureDice_Captions[index]));

}


void TreasureState_renderSelectTreasure() {

  ardBitmap.drawCompressed(14, 8, Images::Chest_Open_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);

  if (treasure_ViewState == Treasure_ViewState::RollDice && counter > 0) {

    renderSpinningCard(34, 13, counter - 1, 5);

  }
  else {

    renderSpinningCard(34, 13, 0, 5);
    ardBitmap.drawCompressed(35, 15, Images::Chest_Dice[dice - 1], WHITE, ALIGN_NONE, MIRROR_NONE);

  }

}


void TreasureState_renderChestResults() { 

  font3x5.setHeight(9);
  font3x5.setCursor(3, 2);
  SpritesB::drawOverwrite(48, 1, Images::Dice, dice);
  ardBitmap.drawCompressed(14, 16, Images::Chest_Closed_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
  
  if (dice >= 5) {

    TreasureState_printCaption(7);

  }
  else {

    TreasureState_printCaption(8);

  }

  font3x5.setHeight(8);

}
