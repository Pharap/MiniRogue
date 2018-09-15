#include "src/images/Images.h"
#include "src/fonts/Font3x5.h"
#include "src/utils/Utils.h"


struct MonsterStats {
  uint8_t hp;
  uint8_t dmg;
};

char const itemUsed_Caption_01[] PROGMEM = " You~used~an~ice~spell.\n  ~Monster~is~frozen\n     for~one~turn.";
char const itemUsed_Caption_02[] PROGMEM = " You~used~a~fire~spell.\n   ~Monster~loses~10\n      HP~points.";
char const itemUsed_Caption_03[] PROGMEM = "~You~used~a~poison~spell.\n  ~Deal~2~extra~damage\n       per~turn.";
char const itemUsed_Caption_04[] PROGMEM = "You~used~a~healing~spell.\n   ~You~have~gained~8\n    ~extra~HP~points.";

char const * const itemUsed_Captions[] = {
	itemUsed_Caption_01,
	itemUsed_Caption_02,
	itemUsed_Caption_03,
	itemUsed_Caption_04,
};

char const bossDice_Caption_01[] PROGMEM = " Gain~a~Fire~Wand!";
char const bossDice_Caption_02[] PROGMEM = " Gain~an~Ice~Wand!";
char const bossDice_Caption_03[] PROGMEM = "Gain~a~Poison~Wand!";
char const bossDice_Caption_04[] PROGMEM = "Gain~a~Healing~Wand!";
char const bossDice_Caption_05[] PROGMEM = "  Gain~an~Armour!";
char const bossDice_Caption_06[] PROGMEM = "Upgrade~your~Weapon!";
char const bossDice_Caption_07[] PROGMEM = "Gain 2 Gold Pieces!";

char const * const bossDice_Captions[] = {
	bossDice_Caption_01,
	bossDice_Caption_02,
	bossDice_Caption_03,
	bossDice_Caption_04,
	bossDice_Caption_05,
	bossDice_Caption_06,
}; 


enum class FightMonster_ViewState : uint8_t {
  HighlightMonsterStats,
  HighlightPlayerStats,
  RollDice,
  DiceSelection,
  WandSelection,
  Defend,
  MonsterDead,
  MonsterDead_Wait,
  PlayerDead,
  ItemIceUsed,
  ItemFireUsed,
  ItemPoisonUsed,
  ItemHealingUsed
};

// enum class FightMonster_SelectedElement : int8_t {
//   None = -1,
//   ItemFire,
//   ItemIce,
//   ItemPoison,
//   ItemHealing,
//   Dice1,
//   Dice2,
//   Dice3,
//   Dice4,
//   Action,
// };


FightMonster_ViewState fightMonster_ViewState = FightMonster_ViewState::RollDice;
FightMonster_ViewState fightMonster_NextState = FightMonster_ViewState::RollDice;
FightMonster_ViewState fightMonster_LastState = FightMonster_ViewState::RollDice;

MonsterStats monsterStats;

FightMonster_SelectedElement fightMonster_SelectedElement = FightMonster_SelectedElement::None;
uint8_t dices[4];
uint8_t dice_Sixes[4];
uint8_t diceMonster = 0;
bool dice_Retain[4];

uint8_t ice = 0;
bool poison = false;


// ----------------------------------------------------------------------------
//  Get the previous dice selection.  Dices need to be 6 to select ..
//
FightMonster_SelectedElement prevDiceSelection(FightMonster_SelectedElement element) {

	if (element > FightMonster_SelectedElement::Dice4 && dices[3] == 6) 							{ return FightMonster_SelectedElement::Dice4; }
	if (element > FightMonster_SelectedElement::Dice3 && dices[2] == 6) 							{ return FightMonster_SelectedElement::Dice3; }
	if (element > FightMonster_SelectedElement::Dice2 && dices[1] == 6) 							{ return FightMonster_SelectedElement::Dice2; }
	if (element > FightMonster_SelectedElement::Dice1 && dices[0] == 6) 							{ return FightMonster_SelectedElement::Dice1; }

	return element;

}


// ----------------------------------------------------------------------------
//  Get the next dice or action selection.  Dices need to be 6 to select ..
//
FightMonster_SelectedElement nextDiceSelection(FightMonster_SelectedElement element) {

	if (element < FightMonster_SelectedElement::Dice1 && dices[0] == 6) 							{ return FightMonster_SelectedElement::Dice1; }
	if (element < FightMonster_SelectedElement::Dice2 && dices[1] == 6) 							{ return FightMonster_SelectedElement::Dice2; }
	if (element < FightMonster_SelectedElement::Dice3 && dices[2] == 6) 							{ return FightMonster_SelectedElement::Dice3; }
	if (element < FightMonster_SelectedElement::Dice4 && dices[3] == 6) 							{ return FightMonster_SelectedElement::Dice4; }
	if (element < FightMonster_SelectedElement::Action) 															{ return FightMonster_SelectedElement::Action; }

	return element;

}


// ----------------------------------------------------------------------------
//  Get the previous wand selection ..
//
FightMonster_SelectedElement prevWandSelection(FightMonster_SelectedElement element) {

	if (element > FightMonster_SelectedElement::ItemHealing && playerStats.items[static_cast<uint8_t>(Wand::Healing)] > 0) 	{ return FightMonster_SelectedElement::ItemHealing; }
	if (element > FightMonster_SelectedElement::ItemFire && playerStats.items[static_cast<uint8_t>(Wand::Fire)] > 0) 				{ return FightMonster_SelectedElement::ItemFire; }
	if (element > FightMonster_SelectedElement::ItemIce && playerStats.items[static_cast<uint8_t>(Wand::Ice)] > 0) 					{ return FightMonster_SelectedElement::ItemIce; }
	if (element > FightMonster_SelectedElement::ItemPoison && playerStats.items[static_cast<uint8_t>(Wand::Poison)] > 0) 		{ return FightMonster_SelectedElement::ItemPoison; }

	return element;

}


// ----------------------------------------------------------------------------
//  Get the next wand or action selection ..
//
FightMonster_SelectedElement nextWandSelection(FightMonster_SelectedElement element) {

	if (element < FightMonster_SelectedElement::ItemHealing && playerStats.items[static_cast<uint8_t>(Wand::Healing)] > 0) 	{ return FightMonster_SelectedElement::ItemHealing; }
	if (element < FightMonster_SelectedElement::ItemFire && playerStats.items[static_cast<uint8_t>(Wand::Fire)] > 0) 				{ return FightMonster_SelectedElement::ItemFire; }
	if (element < FightMonster_SelectedElement::ItemIce && playerStats.items[static_cast<uint8_t>(Wand::Ice)] > 0) 					{ return FightMonster_SelectedElement::ItemIce; }
	if (element < FightMonster_SelectedElement::ItemPoison && playerStats.items[static_cast<uint8_t>(Wand::Poison)] > 0) 		{ return FightMonster_SelectedElement::ItemPoison; }
	if (element < FightMonster_SelectedElement::Action) 																																		{ return FightMonster_SelectedElement::Action; }

	return element;

}


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void FightMonsterState_activate() {

	counter = 0;
	diceMonster = 0;
	ice = 0;
	poison = false;

  fightMonster_ViewState = FightMonster_ViewState::RollDice;
  fightMonster_NextState = FightMonster_ViewState::RollDice;
  fightMonster_LastState = FightMonster_ViewState::RollDice;
	fightMonster_SelectedElement = FightMonster_SelectedElement::None;

	for (uint8_t i = 0; i < 4; i++) {

		dices[i] = 0;
		dice_Retain[i]= false;

	}

	setDiceSelection(false);

	switch (currentState) {

		case GameStateType::Monster:
			monsterStats.hp = (gameStats.level + 1) + random(1, 7); 
			monsterStats.dmg = gameStats.getMonsterDMG();
			break;

		case GameStateType::BossMonster:
			monsterStats.hp = 10 + (gameStats.getAreaId() * 5);
			monsterStats.dmg = gameStats.getBossMonsterDMG();
			break;

		case GameStateType::MonsterFromEvent:
			monsterStats.hp = (gameStats.level + 1) * 2;
			monsterStats.dmg = 5;
			break;

		default: break;

	}

	fightMonster_NextState = FightMonster_ViewState::RollDice;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void FightMonsterState_update() {

  auto justPressed = arduboy.justPressedButtons();

	switch (fightMonster_ViewState) {

		case FightMonster_ViewState::HighlightMonsterStats:
		case FightMonster_ViewState::HighlightPlayerStats:

			if (justPressed & A_BUTTON) { counter = FLASH_COUNTER - 1; }
			
			if (counter < FLASH_COUNTER) {

				counter++;

				if (counter == FLASH_COUNTER) {

					counter = 0;
					fightMonster_ViewState = fightMonster_NextState;
					arduboy.resetFrameCount();

				}

			}
			break;

		case FightMonster_ViewState::RollDice:

			fightMonster_LastState = FightMonster_ViewState::RollDice;

			if (justPressed & A_BUTTON) { 

				counter = sizeof(DiceDelay); 

				for (uint8_t i = 0; i < playerStats.xpTrack; i++) {
					if (!dice_Retain[i]) dices[i] = random(1, 7);
				}

			}

			if (counter < sizeof(DiceDelay)) {
				
				if (arduboy.everyXFrames(pgm_read_byte(&DiceDelay[counter]))) {

					for (uint8_t i = 0; i < playerStats.xpTrack; i++) {
						if (!dice_Retain[i]) dices[i] = random(1, 7);
					}

					counter++;
					arduboy.resetFrameCount();

				}

			}
			else {


				// Highlight first available dice option ..

				fightMonster_SelectedElement = FightMonster_SelectedElement::ItemPoison;
				fightMonster_SelectedElement = nextDiceSelection(fightMonster_SelectedElement);

				setDiceSelection(true); 
				fightMonster_ViewState = FightMonster_ViewState::DiceSelection;

			}
			break;

		case FightMonster_ViewState::DiceSelection:

			if (justPressed & LEFT_BUTTON) 		{ fightMonster_SelectedElement = prevDiceSelection(fightMonster_SelectedElement); }
			if (justPressed & RIGHT_BUTTON)		{ fightMonster_SelectedElement = nextDiceSelection(fightMonster_SelectedElement); }
			
			if (justPressed & A_BUTTON) {

				switch (fightMonster_SelectedElement) {

					case FightMonster_SelectedElement::Dice1 ... FightMonster_SelectedElement::Dice4:

						counter = 0;
						dice_Retain[static_cast<uint8_t>(fightMonster_SelectedElement) - 4] = false;
						dice_Sixes[static_cast<uint8_t>(fightMonster_SelectedElement) - 4]++;
						fightMonster_ViewState= FightMonster_ViewState::RollDice;
						break;

					case FightMonster_SelectedElement::Action:
						{
							uint8_t dmg = getMonsterDMG();

							monsterStats.hp = clamp(monsterStats.hp - dmg, 0, 30);	
							setDiceSelection(false);

							if (monsterStats.hp == 0) { 

								monsterIsDead();

							}
							else {
								
								counter = 0;
								fightMonster_LastState= FightMonster_ViewState::DiceSelection;
								fightMonster_SelectedElement = FightMonster_SelectedElement::Action;

								if (dmg != 0) {

									fightMonster_ViewState = FightMonster_ViewState::HighlightMonsterStats;

									if (playerStats.itemCount() == 0) {

										if (ice == 0) {
											fightMonster_NextState = FightMonster_ViewState::Defend;
										}
										else {
											fightMonster_NextState = FightMonster_ViewState::RollDice;
										}
										
									}
									else {

										fightMonster_NextState = FightMonster_ViewState::WandSelection;

									}

								}
								else {

									if (playerStats.itemCount() == 0) {

										if (ice == 0) {
											fightMonster_ViewState = FightMonster_ViewState::Defend;
										}
										else {
											fightMonster_ViewState = FightMonster_ViewState::RollDice;
										}

									}
									else {

										fightMonster_ViewState = FightMonster_ViewState::WandSelection;

									}

								}
								
							}

						}
						break;

					default: break;

				}
			
			}

			break;

		case FightMonster_ViewState::WandSelection:

			fightMonster_LastState = FightMonster_ViewState::WandSelection;

			if (justPressed & UP_BUTTON || justPressed & LEFT_BUTTON) 			{ fightMonster_SelectedElement = prevWandSelection(fightMonster_SelectedElement); }
			if (justPressed & DOWN_BUTTON || justPressed & RIGHT_BUTTON) 		{ fightMonster_SelectedElement = nextWandSelection(fightMonster_SelectedElement); }
			
			if (justPressed & A_BUTTON) {

				switch (fightMonster_SelectedElement) {

					case FightMonster_SelectedElement::ItemFire:

						playerStats.items[static_cast<uint8_t>(Wand::Fire)]--;
						monsterStats.hp = clamp(monsterStats.hp - 10, 0, 30);	
						setDiceSelection(false);

						if (monsterStats.hp == 0) { 

							monsterIsDead();

						}
						else {

							fightMonster_LastState = FightMonster_ViewState::WandSelection;
							fightMonster_ViewState = FightMonster_ViewState::ItemFireUsed;

						}
						break;

					case FightMonster_SelectedElement::ItemIce:
						ice = 1;
						fightMonster_ViewState = FightMonster_ViewState::ItemIceUsed;
						playerStats.items[static_cast<uint8_t>(Wand::Ice)]--;
						break;

					case FightMonster_SelectedElement::ItemPoison:
						poison = true;
						fightMonster_ViewState = FightMonster_ViewState::ItemPoisonUsed;
						playerStats.items[static_cast<uint8_t>(Wand::Poison)]--;
						break;

					case FightMonster_SelectedElement::ItemHealing:
						fightMonster_ViewState = FightMonster_ViewState::ItemHealingUsed;
						playerStats.items[static_cast<uint8_t>(Wand::Healing)]--;
						playerStats.incHP(8);
						break;

					default: 
						if (ice == 0) {
							fightMonster_ViewState = FightMonster_ViewState::Defend;
						}
						else {
							fightMonster_ViewState = FightMonster_ViewState::RollDice;
						}
						break;

				}
			
			}

			break;

		case FightMonster_ViewState::Defend:

			playerStats.decHP(clamp(monsterStats.dmg - playerStats.armour, 0, 50));

			if (playerStats.hp == 0) {

				fightMonster_ViewState = FightMonster_ViewState::HighlightPlayerStats;
				fightMonster_NextState = FightMonster_ViewState::PlayerDead;

			}
			else {

				setDiceSelection(false);
				fightMonster_ViewState = FightMonster_ViewState::HighlightPlayerStats;
				fightMonster_NextState = FightMonster_ViewState::RollDice;
			}
			
			break;

		case FightMonster_ViewState::MonsterDead:

			if (justPressed & A_BUTTON) { 
				gameStats.monsterDefeated = true;
        currentState = gameStats.incRoom(playerStats); 
			}
			
			if (counter < FLASH_COUNTER) {

				counter++;

				if (counter == FLASH_COUNTER) {

					fightMonster_LastState = fightMonster_ViewState;
					fightMonster_ViewState = FightMonster_ViewState::MonsterDead_Wait;

				}

			}

			break;

		case FightMonster_ViewState::MonsterDead_Wait:

			if (justPressed & A_BUTTON) {

				gameStats.monsterDefeated = true;
        currentState = gameStats.incRoom(playerStats); 

			}

			break;

		case FightMonster_ViewState::PlayerDead:

			if (justPressed & A_BUTTON) {
				currentState = GameStateType::PlayerDead;
			}

			break;

		case FightMonster_ViewState::ItemIceUsed:

			if (justPressed & A_BUTTON) {
				fightMonster_ViewState = FightMonster_ViewState::RollDice;
			}

			break;
			
		case FightMonster_ViewState::ItemFireUsed:
		case FightMonster_ViewState::ItemPoisonUsed:
		case FightMonster_ViewState::ItemHealingUsed:

			if (justPressed & A_BUTTON) {
				fightMonster_ViewState = FightMonster_ViewState::Defend;
			}

			break;

	}

}


void monsterIsDead() {

	switch (currentState) {

		case GameStateType::Monster:
			playerStats.incXP(gameStats.getMonsterReward());
			break;

		case GameStateType::BossMonster:
		 	{
				playerStats.incXP(gameStats.getAreaId() + 2);
				playerStats.incGold(gameStats.getAreaId() < 2 ? 2 : 3);
				playerStats.bossesKilled++;

        diceMonster = random(1, 7);
        if (playerStats.itemCount() >= 2 && diceMonster < 5) diceMonster = 7;

				switch (diceMonster) {

					case 1 ... 4:   playerStats.items[diceMonster - 1]++; break;
					case 5:         playerStats.incArmour(1); break;
					case 6:         playerStats.incXP(2); break;
					case 7:         playerStats.incGold(2); break;

					break;

				}

			}

		  break;

		case GameStateType::MonsterFromEvent:
			playerStats.incXP(2);
			break;

		default: break;

	}

	fightMonster_ViewState = FightMonster_ViewState::MonsterDead;
	
}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void FightMonsterState_render() {

	bool flash = arduboy.getFrameCountHalf(20);


	// Draw background ..

  renderBackground(true);
	ardBitmap.drawCompressed(0, 0, Images::Monster_Stats_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);

	{
		uint8_t const *imageName = nullptr;
		uint8_t const *maskName = nullptr;

		switch (currentState) {

			case GameStateType::Monster:
			case GameStateType::MonsterFromEvent:

				imageName = Images::Monster_Only_Comp;
				maskName = Images::Monster_Only_Mask_Comp;
				break;

			case GameStateType::BossMonster:

				imageName = Images::BossMonster_Only_Comp;
				maskName = Images::BossMonster_Only_Mask_Comp;
				break;

			default: break;

		}

		ardBitmap.drawCompressed(85, 0, maskName, BLACK, ALIGN_NONE, MIRROR_NONE);
		ardBitmap.drawCompressed(58, 0, imageName, WHITE, ALIGN_NONE, MIRROR_NONE);
		ardBitmap.drawCompressed(35, 0, Images::Monster_LHS_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);

	}


	// Monster statistics ..
	{

		if (fightMonster_ViewState== FightMonster_ViewState::HighlightMonsterStats && flash) {
			font3x5.setTextColor(BLACK);
			arduboy.fillRect(20, 2, (monsterStats.hp < 10 ? 5 : 10), 7, WHITE);
		}

		font3x5.setCursor(21, 2);
		font3x5.print(monsterStats.hp);
		font3x5.setTextColor(WHITE);
		font3x5.setCursor(21, 10);
		font3x5.print(monsterStats.dmg);

	}


	// Inventory ..

	if (fightMonster_ViewState == FightMonster_ViewState::WandSelection || fightMonster_LastState == FightMonster_ViewState::WandSelection) {

		ardBitmap.drawCompressed(0, 19, Images::Monster_Items_Comp, WHITE, ALIGN_NONE, MIRROR_NONE);

		font3x5.setCursor(21, 23);
		font3x5.print(playerStats.items[static_cast<uint8_t>(Wand::Fire)]);
		font3x5.setCursor(21, 33);
		font3x5.print(playerStats.items[static_cast<uint8_t>(Wand::Ice)]);
		font3x5.setCursor(21, 43);
		font3x5.print(playerStats.items[static_cast<uint8_t>(Wand::Poison)]);
		font3x5.setCursor(21, 53);
		font3x5.print(playerStats.items[static_cast<uint8_t>(Wand::Healing)]);

	}


	// Dice ..

	if (fightMonster_ViewState == FightMonster_ViewState::DiceSelection || fightMonster_ViewState == FightMonster_ViewState::RollDice || fightMonster_LastState == FightMonster_ViewState::DiceSelection) {
		for (uint8_t i = 0; i < playerStats.xpTrack; i++) {
			SpritesB::drawOverwrite(3 + (i * 10), 52, Images::Dice, dices[i]);
		}
	}


	// Marker ..
	
	if ((fightMonster_SelectedElement == FightMonster_SelectedElement::Action && flash) || (fightMonster_SelectedElement != FightMonster_SelectedElement::Action)) {

		uint8_t x = 0;
		uint8_t y = 0;

		if (fightMonster_ViewState == FightMonster_ViewState::DiceSelection) 			{	x = 3 + (playerStats.xpTrack * 10);	y = 53;	}
		if (fightMonster_ViewState == FightMonster_ViewState::WandSelection) 			{ x = 26; y = 53;	}

		if (x > 0) SpritesB::drawOverwrite(x, y, Images::Marker, 0);

	}


	// Highlighted item ..
	{

		if (fightMonster_ViewState== FightMonster_ViewState::DiceSelection || fightMonster_ViewState == FightMonster_ViewState::WandSelection) {

		  if (!flash) {
			
				uint8_t x = 0;
				uint8_t y = 0;

				switch (fightMonster_SelectedElement) {

					case FightMonster_SelectedElement::ItemFire ... FightMonster_SelectedElement::ItemHealing:
						x = 3;
						y = 22 + (static_cast<uint8_t>(fightMonster_SelectedElement) * 10);
						break;

					case FightMonster_SelectedElement::Dice1 ... FightMonster_SelectedElement::Dice4:
						x = 3 + ((static_cast<uint8_t>(fightMonster_SelectedElement) - 4) * 10);
						y = 52;
						break;

					default: break;
		
				}

				if (x > 0) SpritesB::drawPlusMask(x, y, Images::Dice_Highlight_SelfMasked, 0);

			}

		}

	}


	// Player statistics ..

	const FlashSettings settings = ((fightMonster_ViewState == FightMonster_ViewState::HighlightPlayerStats) ? FlashSettings::FlashHP : FlashSettings::None);

	renderPlayerStatistics(true, settings);


	// Messages ..

	switch (fightMonster_ViewState) {

		case FightMonster_ViewState::HighlightPlayerStats:
	
			if (fightMonster_NextState == FightMonster_ViewState::PlayerDead) {
				renderPlayerDead();
			}

			break;
			
		case FightMonster_ViewState::MonsterDead:
		case FightMonster_ViewState::MonsterDead_Wait:

			if (fightMonster_ViewState != FightMonster_ViewState::MonsterDead_Wait) {

				FlashSettings settings = FlashSettings::FlashXP;

				if (currentState == GameStateType::BossMonster) {

					settings |= FlashSettings::FlashGold;
					if(diceMonster == 5) settings |= FlashSettings::FlashArmour;

				}

				renderPlayerStatistics(true, settings);

			}

			if (currentState == GameStateType::BossMonster) {

    	 	renderMessageBox(20, 23, 88, 26);
			 	font3x5.setCursor(26, 28);
			 	font3x5.print(F("You~killed~the~Boss.\n"));
			 	font3x5.print(FlashString(bossDice_Captions[diceMonster - 1]));

			}
			else {
			
				renderMonsterDead();

			}
			break;

		case FightMonster_ViewState::PlayerDead:

			renderPlayerDead();
			break;

		case FightMonster_ViewState::ItemIceUsed:
		case FightMonster_ViewState::ItemFireUsed:
		case FightMonster_ViewState::ItemPoisonUsed:
		case FightMonster_ViewState::ItemHealingUsed:

   	 	renderMessageBox(15, 17, 100, 32);
			font3x5.setCursor(20, 21);
			font3x5.print(FlashString(itemUsed_Captions[ static_cast<uint8_t>(fightMonster_ViewState) - static_cast<uint8_t>(FightMonster_ViewState::ItemIceUsed) ]));
			break;

		default: break;

	}

}



// ----------------------------------------------------------------------------
//  Get the damage inflicted on the monster this roll of the dice ..
//
uint8_t getMonsterDMG() {

	uint8_t damage = 0;

	for (uint8_t i = 0; i < playerStats.xpTrack; i++) {
		if (dices[i] != 1) {
			damage = damage + dices[i] + (dice_Sixes[i] * 6);
		}
	}

	return damage + (poison ? 5 : 0);

}


// ----------------------------------------------------------------------------
//  Clear dice selection array ready to roll again ..
//
void  setDiceSelection(bool value) {

	for (uint8_t i = 0; i < playerStats.xpTrack; i++) {

		dice_Retain[i] = value;

		if (!value) {
			dice_Sixes[i] = 0;
			if (ice > 0) ice--;
		}

	}

}
