#include "src/utils/Enums.h"
#include "src/utils/FadeEffects.h"
#include "src/fonts/Font3x5.h"
  
enum class Trap_ViewState : uint8_t {
  SkillCheck,
  SkillCheckResult,
  RollDice,
  UpdateStats,
  PlayerDead
};


Trap_ViewState viewState = Trap_ViewState::SkillCheck;


constexpr const static uint8_t NO_OF_CARDS_IN_FLIP = 13; 


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void TrapState_update() { 

  auto justPressed = arduboy.justPressedButtons();

  switch (this->viewState) {

    case Trap_ViewState::SkillCheckResult:

      if (justPressed & A_BUTTON) { counter = FLASH_COUNTER; }

      if (counter < FLASH_COUNTER) {

        counter++;

      }
			else {

        if (justPressed & A_BUTTON) {

          if (dice <= playerStats.xpTrack) {

            currentState = gameStats.incRoom(playerStats); 

          }
          else {

            counter = 0;
            this->viewState = Trap_ViewState::RollDice;

          }

        }

			}
			break;

    case Trap_ViewState::SkillCheck:
    case Trap_ViewState::RollDice:
      
			if (counter < NO_OF_CARDS_IN_FLIP - 1) {

        dice = random(1, 7);
        counter++;

			}
			else {

        if (this->viewState == Trap_ViewState::RollDice) {

          switch (dice) {

            case 1: playerStats.decFood(1);       break;
            case 2: playerStats.decGold(1);       break;
            case 3: playerStats.decArmour(1);     break;
            case 4: playerStats.decHP(1);         break;
            case 5: if (playerStats.xp > 1)       playerStats.xp--;       break;

            case 6: 
              
              playerStats.decHP(2); 
              
              if (playerStats.hp > 0) {
                gameStats.dropArea();
              }

            break;

          }


          // Have we died?

          if (playerStats.hp > 0) {

            arduboy.resetFrameCount();
            counter = 0;
            this->viewState = Trap_ViewState::UpdateStats;

          }
          else {

            viewState = Trap_ViewState::PlayerDead;

          }

        }
        else {
          
          counter = 0;
          arduboy.resetFrameCount();
          this->viewState = Trap_ViewState::SkillCheckResult;

        }

			}
			break;

    case Trap_ViewState::UpdateStats:

      if (counter < FLASH_COUNTER) {

        counter++;

      }
      else {

        if (justPressed & A_BUTTON) {

          currentState = gameStats.incRoom(playerStats); 

        }

      }

      break;

		case Trap_ViewState::PlayerDead:

      if (justPressed & A_BUTTON) {
				currentState = GameStateType::PlayerDead;
			}

      break;

  }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void TrapState_render() {

  const bool flash = arduboy.getFrameCountHalf(FLASH_DELAY);


  // Render common parts ..

  renderBackground(true);
  ardBitmap.drawCompressed(0, 40, Images::Trap_LHS_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
  ardBitmap.drawCompressed(79, 40, Images::Trap_RHS_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);

  for (uint8_t i = 9; i < 70; i = i + 14) {
    ardBitmap.drawCompressed(i, 40, Images::Trap_Single_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
  }

  switch (this->viewState) {

    case Trap_ViewState::SkillCheck:
    case Trap_ViewState::SkillCheckResult:

      font3x5.setCursor(3, 3);
      font3x5.print(F("Evade~trap?"));
      font3x5.setCursor(66, 3);
      SpritesB::drawOverwrite(51, 2, Images::Dice, dice);

      if (viewState == Trap_ViewState::SkillCheckResult) {

        if (counter < FLASH_COUNTER && flash) font3x5.setTextColor(BLACK);

        if (dice <= playerStats.xpTrack) {

          if (counter < FLASH_COUNTER && flash) arduboy.fillRect(64, 3, 15, 7, WHITE);
          font3x5.print(F("Yes"));

        }
        else {

          if (counter < FLASH_COUNTER && flash) arduboy.fillRect(64, 3, 11, 7, WHITE);
          font3x5.print(F("No"));

        }

        font3x5.setTextColor(WHITE);

      }

      break;

    case Trap_ViewState::RollDice:

      renderLargeSpinningCard(28, 8, counter);

      if (counter < NO_OF_CARDS_IN_FLIP) {

        if (Images::Large_Spinning_Inlays[counter] > 0) {
          for (uint8_t i = 0, j = 0; i < Images::Large_Spinning_Inlays[counter]; i++, j = j + 2) {
            ardBitmap.drawCompressed(32 + (counter * 2) + j, 8, Images::Large_Spinning_Card_Inlay, WHITE, ALIGN_NONE, MIRROR_NONE);
          }
        }

      }
      else {

        ardBitmap.drawCompressed(30, 10, Images::Trap_Dice[dice - 1], WHITE, ALIGN_NONE, MIRROR_NONE);

      }

      break;

    case Trap_ViewState::UpdateStats:

      renderLargeSpinningCard(28, 8, 0);
      ardBitmap.drawCompressed(30, 10, Images::Trap_Dice[dice - 1], WHITE, ALIGN_NONE, MIRROR_NONE);
      font3x5.setCursor(4, 0);
      printTrapName();

      break;

    case Trap_ViewState::PlayerDead:

      renderPlayerDead();
      break;

  }

  static const FlashSettings diceHelper[] PROGMEM = {
    FlashSettings::None,
    FlashSettings::FlashFood,
    FlashSettings::FlashGold,
    FlashSettings::FlashArmour,
    FlashSettings::FlashHP,
    FlashSettings::FlashXP,
  };

	// Player statistics ..

	const FlashSettings settings = (dice < 6) ? static_cast<FlashSettings>(pgm_read_byte(&diceHelper[dice])) : FlashSettings::None;
	const bool shouldFlash = (this->viewState == Trap_ViewState::UpdateStats && counter < FLASH_COUNTER);

	renderPlayerStatistics(shouldFlash, settings);

}

char const trapDice_Caption_01[] PROGMEM = "Mildew       ~-1~Food";
char const trapDice_Caption_02[] PROGMEM = "Tripwire     ~-1~Gold";
char const trapDice_Caption_03[] PROGMEM = "Rusted~Armour   -1~AR";
char const trapDice_Caption_04[] PROGMEM = "Spring~Blade    -1~HP";
char const trapDice_Caption_05[] PROGMEM = "Moving~Walls    -1~XP";
char const trapDice_Caption_06[] PROGMEM = "Pit     ~-2~HP,~+Fall";

char const * const trapDice_Captions[] = {
	trapDice_Caption_01,
	trapDice_Caption_02,
	trapDice_Caption_03,
	trapDice_Caption_04,
	trapDice_Caption_05,
	trapDice_Caption_06,
};

void TrapState_printTrapName() {

  font3x5.print(FlashString(trapDice_Captions[dice - 1]));

}
