#include "src/utils/Enums.h"
#include "src/utils/FadeEffects.h"

  
enum class Resting_ViewState : uint8_t {
  SelectReward,
  UpdateStats,
};

enum class Resting_SelectedItem : uint8_t {
  Food,
  Heal,
  Weapon,
};

Resting_ViewState resting_ViewState = Resting_ViewState::SelectReward;
Resting_SelectedItem resting_SelectedItem = Resting_SelectedItem::Food;
Resting_SelectedItem resting_PrevSelection = Resting_SelectedItem::Food;




// ----------------------------------------------------------------------------
//  Initialise state ..
//
void RestingState_activate() {

  counter = 0;
  merchantState_SelectedItem = 0;
  errorNumber = 0;
  
  resting_ViewState = Resting_ViewState::SelectReward;
  resting_SelectedItem = Resting_SelectedItem::Food;
  resting_PrevSelection = Resting_SelectedItem::Food;

  event_ViewState = Event_ViewState::RollDice;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void RestingState_update() { 

  auto justPressed = arduboy.justPressedButtons();

  switch (resting_ViewState) {

    case Resting_ViewState::SelectReward:

      if ((justPressed & LEFT_BUTTON) && resting_SelectedItem == Resting_SelectedItem::Weapon)     { resting_SelectedItem = resting_PrevSelection; }
      if ((justPressed & RIGHT_BUTTON) && resting_SelectedItem != Resting_SelectedItem::Weapon)    { resting_PrevSelection = resting_SelectedItem; resting_SelectedItem = Resting_SelectedItem::Weapon; }
      if ((justPressed & DOWN_BUTTON) && resting_SelectedItem == Resting_SelectedItem::Food)       { resting_SelectedItem = Resting_SelectedItem::Heal; }
      if ((justPressed & UP_BUTTON) && resting_SelectedItem == Resting_SelectedItem::Heal)         { resting_SelectedItem = Resting_SelectedItem::Food; }

      if (justPressed & A_BUTTON)   { 

        switch (resting_SelectedItem) {

          case Resting_SelectedItem::Weapon:
            playerStats.incXP(1);
            break;

          case Resting_SelectedItem::Food:
            playerStats.food++;
            break;

          case Resting_SelectedItem::Heal:
            playerStats.incHP(2);
            break;

        }

        resting_ViewState = Resting_ViewState::UpdateStats;

      }

      break;

    case Resting_ViewState::UpdateStats:

      if (counter < FLASH_COUNTER) {

        counter++;

        if (counter == FLASH_COUNTER) {

          currentState = gameStats.incRoom(playerStats); 

        }

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
void RestingState_render() {

  const bool flash = arduboy.getFrameCountHalf(FLASH_DELAY);

  renderBackground(false);
  ardBitmap.drawCompressed(0, 0, Images::Card_Resting_Large_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);


	// Player statistics ..

	static_assert(Resting_SelectedItem::Food == static_cast<Resting_SelectedItem>(0), "SelectedItem enum changed, please update the settingsHelper array.");
	static_assert(Resting_SelectedItem::Heal == static_cast<Resting_SelectedItem>(1), "SelectedItem enum changed, please update the settingsHelper array.");
	static_assert(Resting_SelectedItem::Weapon == static_cast<Resting_SelectedItem>(2), "SelectedItem enum changed, please update the settingsHelper array.");

	static const FlashSettings settingsHelper[] PROGMEM = 
	{
		//SelectedItem::Food
		FlashSettings::FlashFood,
		//SelectedItem::Heal
		FlashSettings::FlashHP,
		//SelectedItem::Weapon
		FlashSettings::FlashXP,
	};

	const uint8_t index = static_cast<uint8_t>(resting_SelectedItem);
	const FlashSettings settings = static_cast<FlashSettings>(pgm_read_byte(&settingsHelper[index]));
	const bool shouldFlash = (resting_ViewState == Resting_ViewState::UpdateStats);

	renderPlayerStatistics(shouldFlash, settings);

  if (flash) {

    uint8_t a = 0;
    uint8_t b = 48;
    uint8_t c = 0;
    uint8_t d = 34;
    
    switch (resting_SelectedItem) {

      case Resting_SelectedItem::Food:
        // a = 0;
        // b = 48;
        // c = 0;
        // d = 34;
        break;

      case Resting_SelectedItem::Heal:
        // a = 0;
        // b = 48;
        c = 36;
        d = 63;
        break;

      case Resting_SelectedItem::Weapon:
        a = 50;
        b = 87;
        // c = 0;
        d = 63;
        break;

    }

    arduboy.drawHorizontalDottedLine(a, b, c, BLACK);
    arduboy.drawHorizontalDottedLine(a, b, d, BLACK);
    arduboy.drawVerticalDottedLine(c, d, a, BLACK);
    arduboy.drawVerticalDottedLine(c, d, b, BLACK);

  }

}
