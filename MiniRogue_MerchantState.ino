#include "src/utils/Enums.h"
#include "src/utils/FadeEffects.h"
#include "src/fonts/Font3x5.h"

char const error_01[] PROGMEM = "   You need\n  more gold!";
char const error_02[] PROGMEM = "~You dont have\n one to sell!";
char const error_03[] PROGMEM = " ~You already\n have enough!";

char const * const error_Captions[] = {
	error_01,
	error_02,
	error_03,
};

enum class Merchant_ViewState : uint8_t {
  Buying,
  Selling,
};

Merchant_ViewState viewState = Merchant_ViewState::Buying;

uint8_t selectedItem = 0;
uint8_t errorNumber = 0;

FlashSettings settings;



// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void MerchantState_update() { 

  auto justPressed = arduboy.justPressedButtons();

  if (justPressed > 0) this->errorNumber = 0;

  switch (this->viewState) {

    case Merchant_ViewState::Buying:

      if ((justPressed & UP_BUTTON) && this->selectedItem > 0)            this->selectedItem--;
      if ((justPressed & DOWN_BUTTON) && this->selectedItem < 6)          this->selectedItem++;

      if (justPressed & A_BUTTON) {

        switch (this->selectedItem) {

          case 0:
            
            if (playerStats.gold == 0) {
              this->errorNumber = 1;
            } 
            else if (playerStats.food == 10) { 
              this->errorNumber = 3;
            } 
            else {
              this->settings |= FlashSettings::FlashFood; 
              playerStats.incFood(1); 
              playerStats.decGold(1); 
            }   
            
            break;

          case 1:

            if (playerStats.gold == 0) {
              this->errorNumber = 1;
            } 
            else if (playerStats.hp == 20) { 
              this->errorNumber = 3;
            } 
            else { 
              this->settings |= FlashSettings::FlashHP;
              playerStats.incHP(1); 
              playerStats.decGold(1);
            }   
            
            break;

          case 2:

            if (playerStats.gold < 3) {
              this->errorNumber = 1;
            } 
            else if (playerStats.hp == 20) { 
              this->errorNumber = 3;
            } 
            else { 
              this->settings |= FlashSettings::FlashHP;
              playerStats.incHP(4); 
              playerStats.decGold(3); 
            }   
            
            break;

          case 3 ... 5:

            if (playerStats.gold >= 8) {

              if (playerStats.itemCount() < 2) { 

                playerStats.items[this->selectedItem - 3]++; 
                playerStats.decGold(8); 
                this->settings |= FlashSettings::FlashGold;

              }
              else {
                this->errorNumber = 3;
              }

            }
            else {
              this->errorNumber = 1;
            }   
            
           break;

          case 6:

            if (playerStats.gold >= 6) {

              if (playerStats.armour < 5) { 

                playerStats.incArmour(1); 
                playerStats.decGold(6); 
                this->settings |= FlashSettings::FlashArmour;

              }
              else {
                this->errorNumber = 3;
              }

            }
            else {
              this->errorNumber = 1;
            }   

        }

      constexpr FlashSettings flashTest = (FlashSettings::FlashHP | FlashSettings::FlashXP | FlashSettings::FlashFood| FlashSettings::FlashArmour);

      if ((this->settings & flashTest) != FlashSettings::None)
        this->settings |= FlashSettings::FlashGold;

        }

			break;

    case Merchant_ViewState::Selling:

      if ((justPressed & UP_BUTTON) && this->selectedItem > 0)            this->selectedItem--;
      if ((justPressed & DOWN_BUTTON) && this->selectedItem < 4)          this->selectedItem++;
      
      if (justPressed & A_BUTTON) {

        if (this->selectedItem <= 2) {

          if (playerStats.items[this->selectedItem] > 0) {

            playerStats.items[this->selectedItem]--;
            playerStats.incGold(4);
            this->settings |= FlashSettings::FlashGold;

          }
          else {
            this->errorNumber = 2;
          }

        }
        else {

          if (playerStats.armour > 0) {

            playerStats.decArmour(1);
            playerStats.incGold(3);
            this->settings |= (FlashSettings::FlashGold | FlashSettings::FlashArmour);

          }
          else {
            this->errorNumber = 2;
          }

        }

      } 

      break;

  }

  if ((justPressed & LEFT_BUTTON) || (justPressed & RIGHT_BUTTON)) {
    
    this->viewState = static_cast<Merchant_ViewState>(!static_cast<bool>(this->viewState));
    this->selectedItem = 0;

  }

  if (justPressed & B_BUTTON) {

    currentState = gameStats.incRoom(playerStats); 

  }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void MerchantState_render() {


  // Render common parts ..

  renderBackground(true);
  ardBitmap.drawCompressed(39, 0, Images::Merchant_Only_Mask_Comp, BLACK, ALIGN_NONE, MIRROR_NONE);
  ardBitmap.drawCompressed(39, 0, Images::Merchant_Only_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
  
  arduboy.drawFastHLine(35, 60, 51, WHITE);
  arduboy.drawHorizontalDottedLine(35, 87, 62, WHITE);
  arduboy.drawHorizontalDottedLine(36, 87, 63, WHITE);

  {
    
    uint8_t const *imageName = nullptr;

    switch (this->viewState) {

      case Merchant_ViewState::Buying:
        imageName = Images::Merchant_Buy_Comp;
        break;

      case Merchant_ViewState::Selling:
        imageName = Images::Merchant_Sell_Comp;
        break;

    }

    ardBitmap.drawCompressed(2, 1, imageName, WHITE, ALIGN_NONE, MIRROR_NONE);

  }


  // Highlight ..

  Sprites::drawOverwrite(2, 7 + (selectedItem * 8), Images::Merchant_Highlight, 0);
  Sprites::drawOverwrite(33, 7 + (selectedItem * 8), Images::Merchant_Highlight, 0);


  // Error Message ?

  if (this->errorNumber > 0) {

    renderMessageBox(31, 23, 64, 26);
    font3x5.setCursor(36, 28);
  	font3x5.print(FlashString(error_Captions[ this->errorNumber - 1]));

  }

  renderPlayerStatistics(true, this->settings);

}
