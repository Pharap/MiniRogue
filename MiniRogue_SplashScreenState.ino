#include "src/utils/Enums.h"
#include "src/utils/FadeEffects.h"


FadeOutEffect fadeOutEffect;


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void SplashScreenState::activate() {

  fadeOutEffect.reset(0, HEIGHT, 1); 

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void SplashScreenState::update() { 

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void SplashScreenState::render() {

  ardBitmap.drawCompressed(30, 14, Images::BootLogo, WHITE, ALIGN_NONE, MIRROR_NONE);

  if (!fadeOutEffect.isComplete()) {

    fadeOutEffect.draw(arduboy);
    fadeOutEffect.update();

  }

  if (fadeOutEffect.isComplete()) currentState = GameStateType::TitleScreen;

}