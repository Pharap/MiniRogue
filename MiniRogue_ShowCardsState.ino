#include "src/utils/Enums.h"
#include "src/fonts/Font3x5.h"


char const area_Caption_01[] PROGMEM = ":~The~Black~Sewers";
char const area_Caption_02[] PROGMEM = ":~Poisonous~Dungeons";
char const area_Caption_03[] PROGMEM = ":~Undead~Catacombs";
char const area_Caption_04[] PROGMEM = ":~Flaming~Underworld";
char const area_Caption_05[] PROGMEM = ":~Sunken~Keep~of~Og!";

char const * const area_Captions[] = {
	area_Caption_01,
	area_Caption_02,
	area_Caption_03,
	area_Caption_04,
	area_Caption_05,
};

enum class ShowCards_ViewState : uint8_t {
  DealCards,
  PlayCard,
  PlayerDead
};

ShowCards_ViewState showCards_ViewState = ShowCards_ViewState::DealCards;

int8_t displayCard = 0;           
uint8_t numberOfCardsToDisplay = 6;

constexpr const static int8_t STARVED_TO_DEATH = -1; 
constexpr const static uint8_t DEAL_DELAY = 5; 
constexpr const static uint8_t CARD_SHOW_NONE = -1;
constexpr const static uint8_t CARD_SHOW_ALL = 127;
constexpr const static uint8_t CARD_NONE_SELECTED = 255;

const int8_t  cardPositionX[] PROGMEM = { -1, 19, 19, 39, 59, 59, 79 };
const uint8_t cardPositionY[] PROGMEM = { 23, 8, 36, 23, 8, 36, 23 };
const uint8_t cardIndexToRoom[] PROGMEM = { 1, 2, 2, 3, 4, 4, 5 };


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void ShowCardsState_activate() {

	counter = 0;
	displayCard = 0;
	numberOfCardsToDisplay = (gameStats.isLastLevelInArea() ? 7 : 6);
  arduboy.resetFrameCount();

	if (gameStats.room <= 0) {

		showCards_ViewState = ShowCards_ViewState::DealCards;
		displayCard = 0;
		counter = NO_OF_CARDS_IN_FLIP;


		// Shuffle cards ..

		cards[6] = GameStateType::BossMonster;
		
		for (uint8_t i = 0; i < 10; i++) { 
			
			uint8_t x = random(0, 6);
			uint8_t y = random(0, 6);
			swap(cards[x], cards[y]);

		}

		if (playerStats.food == STARVED_TO_DEATH) {

  		displayCard = CARD_SHOW_ALL;
			showCards_ViewState = ShowCards_ViewState::PlayerDead;
      playerStats.food = 0;
  		gameStats.room = 0;

		}
		else {

			gameStats.room = 1;
			
		}

cards[0] = GameStateType::Trap;		//SJH  
playerStats.hp = 0; //sjh

	}
	else {

		displayCard = CARD_SHOW_ALL;
  	counter = NO_OF_CARDS_IN_FLIP;
		showCards_ViewState = ShowCards_ViewState::PlayCard;
		
	}
  
}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void ShowCardsState_update() {
	
  auto justPressed = arduboy.justPressedButtons();

	switch (showCards_ViewState) {

		case ShowCards_ViewState::DealCards:

			if (arduboy.everyXFrames(DEAL_DELAY)) {

				if (displayCard < numberOfCardsToDisplay) {
					displayCard++;
				}
				else {
					displayCard = CARD_SHOW_ALL;
        	showCards_ViewState = ShowCards_ViewState::PlayCard;
					counter = NO_OF_CARDS_IN_FLIP;
				}

			}
			break;

		case ShowCards_ViewState::PlayCard:

			if ((justPressed & UP_BUTTON) && (gameStats.selectedCard == 2 || gameStats.selectedCard == 5)) 		{ gameStats.selectedCard--;}
			if ((justPressed & DOWN_BUTTON) && (gameStats.selectedCard == 1 || gameStats.selectedCard == 4)) 	{ gameStats.selectedCard ++; }

			if (justPressed & A_BUTTON) { 
		
				currentState = cards[gameStats.selectedCard]; 
				
			}

			break;

		case ShowCards_ViewState::PlayerDead:

      if (justPressed & A_BUTTON) { 
        currentState = GameStateType::PlayerDead;
			}

			break;

	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void ShowCardsState_render() {
	
	uint8_t room = gameStats.room;


	// Display area names ..

	font3x5.setTextColor(WHITE);
	font3x5.setCursor(0, 0);

	font3x5.print("L");
	font3x5.print(gameStats.getAreaId() + 1);
	font3x5.print("~A");
	font3x5.print(gameStats.level + 1);
	font3x5.print(FlashString(area_Captions[gameStats.getAreaId()]));


	// Draw background ..

	ardBitmap.drawCompressed(105, 0, Images::Health_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);	
	for (int8_t i = -1; i < 93; i = i + 10) {
		ardBitmap.drawCompressed(i, 18, Images::Card_Border_Top_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
		ardBitmap.drawCompressed(i, 50, Images::Card_Border_Bottom_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);
	}
	ardBitmap.drawCompressed(97, 18, Images::Card_Border_Right_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);


	// Player statistics ..

	const FlashSettings settings = ((showCards_ViewState == ShowCards_ViewState::PlayerDead) ? FlashSettings::FlashFood : FlashSettings::None);

	renderPlayerStatistics(true, settings);

  const bool flash = arduboy.getFrameCountHalf(12);

	for (uint8_t i = 0; i < 7; i++) {

		if (displayCard >= i) {

			int8_t x =  pgm_read_byte(&cardPositionX[i]);
			uint8_t y = pgm_read_byte(&cardPositionY[i]);
			uint8_t r = pgm_read_byte(&cardIndexToRoom[i]);


      // Draw cards as they are being dealt ..

			if (counter == NO_OF_CARDS_IN_FLIP || (room != r && counter > 0) || counter == 0) {

        renderSpinningCard(x, y, 6, 13);

			}


      // Draw card highlight ..


			if (displayCard == CARD_SHOW_ALL && (gameStats.selectedCard == i) && flash && room != 0) {

        ardBitmap.drawCompressed(x, y, Images::Card_Outline_Highlight_Comp, BLACK, ALIGN_NONE, MIRROR_NONE);

			}

      if (room != 0) {

        if ((room > r) || (room == r && counter == 0) || (i == 6 && numberOfCardsToDisplay == 6)) {

          arduboy.fillRect(x + 3, y + 4, 14, 21, BLACK);
          ardBitmap.drawCompressed(x + 3, y + 6, Images::Card_Faces[(i == 6 && numberOfCardsToDisplay == 6 ? 7 : static_cast<uint8_t>(cards[i]) - 1)], WHITE, ALIGN_NONE, MIRROR_NONE);

        }

        if (room == r && counter > 0 && displayCard == CARD_SHOW_ALL) {

					renderSpinningCard(x, y, counter - 1, 13);

        }

      }

		}

	}

	if (counter > 0 && displayCard == CARD_SHOW_ALL) counter --;


	// Are we dead?

  if (showCards_ViewState == ShowCards_ViewState::PlayerDead) {

    renderPlayerDead(PLAYER_DEAD_DEFAULT_Y);

	}

}

