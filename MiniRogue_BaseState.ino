#include "src/utils/Enums.h"
#include "src/utils/FadeEffects.h"
#include "src/fonts/Font3x5.h"


void renderSpinningCard(int8_t x, int8_t y, uint8_t i, uint8_t ySpacing) {

  const auto spinning_mask = Images::spinning_mask[i];
  const auto spinning_card = Images::spinning_card[i];

  for (uint8_t j = 0; j < 4; ++j) {

    const uint8_t xOffset = ((j % 2) ? 10 : 0);
    const uint8_t yOffset = ((j < 2) ? y : y + ySpacing);
    ardBitmap.drawCompressed(x + xOffset, yOffset, spinning_mask, BLACK, ALIGN_NONE, j);

  }

  for (uint8_t j = 0; j < 4; ++j) {

    const uint8_t xOffset = ((j % 2) ? 10 : 0);
    const uint8_t yOffset = ((j < 2) ? y : y + ySpacing);
    ardBitmap.drawCompressed(x + xOffset, yOffset, spinning_card, WHITE, ALIGN_NONE, j);

  }

}

void renderLargeSpinningCard(int8_t x, int8_t y, uint8_t i) {

	const auto spinning_card = Images::Large_Spinning_Cards[i];

	for(uint8_t j = 0; j < 4; ++j) {

		const uint8_t xOffset = ((j % 2) ? 16 : 0);
		const uint8_t yOffset = ((j < 2) ? y : y + 16);
		ardBitmap.drawCompressed(x + xOffset, yOffset, spinning_card, WHITE, ALIGN_NONE, j);

	}

}

void renderTitleBackground(bool drawLowerLines) {

	ardBitmap.drawCompressed(0, 0, Images::Title_Blank_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
	ardBitmap.drawCompressed(64, 0, Images::Title_Blank_Comp, WHITE, ALIGN_NONE, MIRROR_HORIZONTAL);
  
  if (drawLowerLines) {
    arduboy.drawFastHLine(17, 49, 94);
    arduboy.drawFastHLine(17, 51, 94);
    arduboy.drawHorizontalDottedLine(17, 110, 53);
  }

}

void renderMessageBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h) {

  arduboy.fillRect(x, y, w, h, BLACK);
  arduboy.drawFastHLine(x + 3, y + 2, w - 6);
  arduboy.drawFastHLine(x + 3, y + h - 3, w - 6);
  arduboy.drawFastVLine(x + 2, y + 3, h - 6);
  arduboy.drawFastVLine(x + w - 3, y + 3, h - 6);

}

void renderPlayerDead(uint8_t y) {

  Sprites::drawExternalMask(36, y, Images::Message_PlayerDead, Images::Message_PlayerDead_Mask, 0, 0);

}

void renderMonsterDead() {

  renderMessageBox(34, 24, 60, 18);
  font3x5.setCursor(40, 29);
  font3x5.print(F("Enemy Killed"));

}

void renderBackground(bool renderCorners) {

  if (renderCorners) ardBitmap.drawCompressed(0, 0, Images::Background_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
  for (uint8_t y= 0; y < 64; y = y + 10)  ardBitmap.drawCompressed(89, y, Images::Background_Divider_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
  ardBitmap.drawCompressed(105, 0, Images::Health_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);

}

void renderPlayerStatistics(bool overallFlash, FlashSettings settings){

  const bool flash = arduboy.getFrameCountHalf(FLASH_DELAY) && overallFlash;

  for (uint8_t x = 0; x < 6; x++) {
    
    uint8_t val = 0;
    bool flag = false;

    switch (x)  {

      case 0:   
        val = playerStats.xpTrack;       
        break;

      case 1:   
        val = playerStats.xp;       
        flag = ((settings & FlashSettings::FlashXP) != 0);
        break;

      case 2:   
        val = playerStats.hp;
        flag = ((settings & FlashSettings::FlashHP) != 0);
        break;

      case 3:   
        val = playerStats.armour;
        flag = ((settings & FlashSettings::FlashArmour) != 0);
        break;

      case 4:   
        val = playerStats.gold;
        flag = ((settings & FlashSettings::FlashGold) != 0);
        break;

      case 5:   
        val = playerStats.food;
        flag = ((settings & FlashSettings::FlashFood) != 0);
        break;

    }

    if (flag && flash) {
      font3x5.setTextColor(BLACK);
      arduboy.fillRect(119, (x * 9), (val < 10 ? 5 : 10), 7, WHITE);
    }

    font3x5.setCursor(120, (x * 9));
    font3x5.print(val);
    font3x5.setTextColor(WHITE);  

  }

  {

    uint8_t position = 0;

    for (uint8_t x = 0; x < 4; x ++ ) {

      if (playerStats.items[x] > 0) { drawItem(position, Images::Wands[x]); position++; }
      if (playerStats.items[x] > 1) { drawItem(position, Images::Wands[x]); position++; }

    }

    arduboy.drawRect(106, 55, 9, 9, WHITE);
    arduboy.drawRect(117, 55, 9, 9, WHITE);

  }

}

void drawItem(uint8_t position, uint8_t const *imageName) {

  Sprites::drawOverwrite(107 + (position * 11), 56, imageName, 0);

}