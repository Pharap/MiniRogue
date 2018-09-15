#include "src/utils/Enums.h"
#include "src/utils/FadeEffects.h"

  
enum class Resting_ViewState : uint8_t {
  SelectReward,
  UpdateStats,
};

enum class SelectedItem : uint8_t {
  Food,
  Heal,
  Weapon,
};

Resting_ViewState viewState = Resting_ViewState::SelectReward;
SelectedItem selectedItem = SelectedItem::Food;
SelectedItem prevSelection = SelectedItem::Food;



// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void RestingState_update() { 

  auto justPressed = arduboy.justPressedButtons();

  switch (this->viewState) {

    case Resting_ViewState::SelectReward:

      if ((justPressed & LEFT_BUTTON) && this->selectedItem == SelectedItem::Weapon)     { this->selectedItem = this->prevSelection; }
      if ((justPressed & RIGHT_BUTTON) && this->selectedItem != SelectedItem::Weapon)    { this->prevSelection = this->selectedItem; this->selectedItem = SelectedItem::Weapon; }
      if ((justPressed & DOWN_BUTTON) && this->selectedItem == SelectedItem::Food)       { this->selectedItem = SelectedItem::Heal; }
      if ((justPressed & UP_BUTTON) && this->selectedItem == SelectedItem::Heal)         { this->selectedItem = SelectedItem::Food; }

      if (justPressed & A_BUTTON)   { 

        switch (this->selectedItem) {

          case SelectedItem::Weapon:
            playerStats.incXP(1);
            break;

          case SelectedItem::Food:
            playerStats.food++;
            break;

          case SelectedItem::Heal:
            playerStats.incHP(2);
            break;

        }

        this->viewState = Resting_ViewState::UpdateStats;

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

	static_assert(SelectedItem::Food == static_cast<SelectedItem>(0), "SelectedItem enum changed, please update the settingsHelper array.");
	static_assert(SelectedItem::Heal == static_cast<SelectedItem>(1), "SelectedItem enum changed, please update the settingsHelper array.");
	static_assert(SelectedItem::Weapon == static_cast<SelectedItem>(2), "SelectedItem enum changed, please update the settingsHelper array.");

	static const FlashSettings settingsHelper[] PROGMEM = 
	{
		//SelectedItem::Food
		FlashSettings::FlashFood,
		//SelectedItem::Heal
		FlashSettings::FlashHP,
		//SelectedItem::Weapon
		FlashSettings::FlashXP,
	};

	const uint8_t index = static_cast<uint8_t>(this->selectedItem);
	const FlashSettings settings = static_cast<FlashSettings>(pgm_read_byte(&settingsHelper[index]));
	const bool shouldFlash = (this->viewState == Resting_ViewState::UpdateStats);

	renderPlayerStatistics(shouldFlash, settings);

  if (flash) {

    uint8_t a = 0;
    uint8_t b = 48;
    uint8_t c = 0;
    uint8_t d = 34;
    
    switch (this->selectedItem) {

      case SelectedItem::Food:
        // a = 0;
        // b = 48;
        // c = 0;
        // d = 34;
        break;

      case SelectedItem::Heal:
        // a = 0;
        // b = 48;
        c = 36;
        d = 63;
        break;

      case SelectedItem::Weapon:
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
