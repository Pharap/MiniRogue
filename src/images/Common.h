#pragma once

namespace Images {

  // const uint8_t PROGMEM Dice[] = {
  // 9, 9,
  // 0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 
  // 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  // 0xfe, 0x01, 0x01, 0x01, 0x11, 0x01, 0x01, 0x01, 0xfe, 
  // 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  // 0xfe, 0x01, 0x05, 0x01, 0x01, 0x01, 0x41, 0x01, 0xfe, 
  // 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  // 0xfe, 0x01, 0x41, 0x01, 0x11, 0x01, 0x05, 0x01, 0xfe, 
  // 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  // 0xfe, 0x01, 0x45, 0x01, 0x01, 0x01, 0x45, 0x01, 0xfe, 
  // 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  // 0xfe, 0x01, 0x45, 0x01, 0x11, 0x01, 0x45, 0x01, 0xfe, 
  // 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  // 0xfe, 0x01, 0x55, 0x01, 0x01, 0x01, 0x55, 0x01, 0xfe, 
  // 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
  // };

  const uint8_t PROGMEM Dice[] = {
  9, 9,
  0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  0xfe, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0xff, 0xbf, 0xff, 0xef, 0xff, 0xfb, 0xff, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0xff, 0xbb, 0xff, 0xff, 0xff, 0xbb, 0xff, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,  

  0xfe, 0xff, 0xbb, 0xff, 0xef, 0xff, 0xbb, 0xff, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0xff, 0xab, 0xff, 0xff, 0xff, 0xab, 0xff, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
  };


  const uint8_t PROGMEM Dice_Highlight_SelfMasked[] = {
  9, 9,
  0xaa, 0xff, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00,
  0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0xaa, 0xff, 
  0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00,
  0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00, 0x01,
  };

  const uint8_t PROGMEM Marker[] = {
  4, 8,
  0x00, 0x3e, 0x1c, 0x08,
  };

  const uint8_t PROGMEM Background_Comp[] = {
  0xd7, 0xbf, 0x1e, 0xf9, 0xef, 0x13, 0x47, 0xff, 0x5f, 0x21, 0xe4, 0xbf, 0x56, 0x59,
  };
  
  const uint8_t PROGMEM Background_Divider_Comp[] = {
  0x8b, 0xcf, 0x7b, 0x63, 0x6d, 0xb0, 0x96, 0x52, 0x4b, 0x69, 0xb4, 0x37, 0x56, 0xce, 0x9c, 0x73, 
  0xeb, 0xad, 0xb7, 0x4c,
  };

  const uint8_t PROGMEM Health_Comp[] = {
  // 0x17, 0xb7, 0x4f, 0x80, 0xc1, 0x04, 0x8e, 0x0d, 0x30, 0x79, 0x04, 0x2c, 0xe0, 0x37, 0x3b, 0x61, 
  // 0xce, 0xa1, 0x8f, 0xb9, 0xf1, 0x83, 0xbd, 0x09, 0x83, 0x05, 0x7e, 0xc4, 0x1f, 0xaf, 0x1c, 0x18, 
  // 0x9c, 0x7c, 0x0b, 0x08, 0xfc, 0xea, 0x86, 0x22, 0x08, 0xae, 0xf4, 0x29, 0xb0, 0x81, 0xdf, 0xe7, 
  // 0x71, 0x5c, 0xd6, 0x09, 0x78, 0xce, 0x95, 0x5f, 0xe9, 0x39, 0xb7, 0x1e, 0x79, 0x8d, 0xfc, 0x3a, 
  // };
  0x17, 0xf7, 0x4f, 0x91, 0x20, 0x41, 0x06, 0x32, 0x90, 0xb7, 0x40, 0x81, 0xdf, 0x0a, 0x1c, 0x08, 
  0x70, 0xeb, 0x06, 0xc2, 0x43, 0x40, 0xe0, 0x67, 0xdb, 0xc0, 0x18, 0x8c, 0xe1, 0x7b, 0x10, 0x7e, 
  0x77, 0x41, 0x17, 0x25, 0xac, 0x3e, 0x47, 0x7e, 0x7a, 0x42, 0x09, 0xac, 0x43, 0xde, 0xb1, 0x5c, 
  0xfc, 0x4e, 0x26, 0xa3, 0x45, 0x9a, 0x91, 0xf7, 0xdc, 0xf8, 0x7d, 0xbd, 0xe5, 0xb4, 0x2e, 0xe2, 
  0x6b, 0xe0, 0x02, 0xfc, 0x2e,
  };

  const uint8_t PROGMEM Message_PlayerDead[] = {
  52, 15,
  0x00, 0x00, 0xf8, 0x04, 0xc4, 0xa4, 0x64, 0xa4, 0xe4, 0xc4, 0x04, 0x04, 0x04, 0x64, 0x84, 0x64, 
  0x04, 0x84, 0x44, 0x84, 0x04, 0xc4, 0x04, 0xc4, 0x04, 0x04, 0xe4, 0x24, 0xc4, 0x04, 0xa4, 0x04, 
  0x84, 0x44, 0x84, 0x04, 0x84, 0x44, 0xe4, 0x04, 0x04, 0x04, 0xc4, 0xe4, 0xa4, 0x64, 0xa4, 0xc4, 
  0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x13, 0x11, 0x13, 0x11, 0x10, 0x10, 0x10, 
  0x10, 0x10, 0x13, 0x10, 0x10, 0x11, 0x12, 0x11, 0x10, 0x11, 0x12, 0x11, 0x10, 0x10, 0x13, 0x12, 
  0x11, 0x10, 0x13, 0x10, 0x11, 0x13, 0x12, 0x10, 0x11, 0x12, 0x13, 0x10, 0x10, 0x10, 0x10, 0x11, 
  0x13, 0x11, 0x13, 0x10, 0x10, 0x0f, 0x00, 0x00, 
  };

  const uint8_t PROGMEM Message_MonsterDead[] = {
  50, 15,
  0x00, 0x00, 0xf8, 0x04, 0x04, 0xe4, 0xa4, 0x04, 0xc4, 0x44, 0x84, 0x04, 0x84, 0x44, 0x84, 0x04, 
  0xc4, 0x44, 0x84, 0x44, 0x84, 0x04, 0xc4, 0x04, 0xc4, 0x04, 0x04, 0x04, 0xe4, 0x84, 0x64, 0x04, 
  0xa4, 0x04, 0xe4, 0x04, 0xe4, 0x04, 0x84, 0x44, 0x84, 0x04, 0x84, 0x44, 0xe4, 0x04, 0x04, 0xf8, 
  0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x13, 0x12, 0x10, 0x13, 0x10, 0x13, 0x10, 0x11, 0x13, 
  0x12, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x10, 0x15, 0x13, 0x10, 0x10, 0x10, 0x13, 0x10, 
  0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x11, 0x13, 0x12, 0x10, 0x11, 0x12, 0x13, 0x10, 
  0x10, 0x0f, 0x00, 0x00, 
  };

  const uint8_t PROGMEM FireWand[] = {
  7, 7,
  0x00, 0x1a, 0x24, 0x32, 0x24, 0x1a, 0x00,
  };

  const uint8_t PROGMEM IceWand[] = {
  7, 7,
  0x00, 0x2a, 0x18, 0x36, 0x0c, 0x2a, 0x00, 
  };

  const uint8_t PROGMEM PoisonWand[] = {
  7, 7,
  0x00, 0x0c, 0x3a, 0x16, 0x3a, 0x0c, 0x00, 
  };

  const uint8_t PROGMEM HealingWand[] = {
  7, 7,
  0x41, 0x0c, 0x1a, 0x3c, 0x1e, 0x0c, 0x41,
  };

  #ifndef DEBUG
  const unsigned char PROGMEM Large_Spinning_Card_01[] ={
  0x1f, 0x1f, 0x97, 0x05, 0x93, 0x89, 0x80, 0x04, 0x00, 0x01, 0x09, 0x00, 0x02, 0x12, 0x00, 0x04,
  0x24, 0x00, 0x08, 0x48, 0x00, 0x10, 0x90, 0x00, 0x20, 0x20, 0x01, 0x40, 0x40, 0x02, 0x80, 0x80,
  0x04, 0x00, 0x01, 0x09, 0x00, 0x02, 0x12, 0x00, 0x04, 0x24, 0x00, 0x4c, 0xf6, 0xba, 0xef, 0x3b,
  0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20,
  0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08,
  0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x00, 0xf7, 0x7d, 0xdf, 0x77, 0x00, 0x40,
  0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10,
  0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04,
  0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0xee, 0xfb, 0xbe, 0x36, 0x13, 0x80, 0x20, 0x20,
  0x00, 0x41, 0x40, 0x00, 0x82, 0x80, 0x00, 0x04, 0x01, 0x01, 0x08, 0x02, 0x02, 0x10, 0x04, 0x04,
  0x20, 0x08, 0x08, 0x40, 0x10, 0x10, 0x80, 0x20, 0x20, 0x00, 0x41, 0x40, 0x00, 0x82, 0x80, 0x00,
  0x04, 0x01, 0x99, 0x4c, 0x58, 0x17,
  };
  #else
  const uint8_t PROGMEM Large_Spinning_Card_01[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  #ifndef DEBUG
  const unsigned char PROGMEM Large_Spinning_Card_02[] ={
  0x1f, 0x1f, 0x2f, 0x17, 0x4c, 0x26, 0x02, 0x12, 0x00, 0x04, 0x24, 0x00, 0x08, 0x48, 0x00, 0x10,
  0x90, 0x00, 0x20, 0x20, 0x01, 0x40, 0x40, 0x02, 0x80, 0x80, 0x04, 0x00, 0x01, 0x09, 0x00, 0x02,
  0x12, 0x00, 0x04, 0x24, 0x00, 0x4c, 0xf6, 0xfa, 0xde, 0xbe, 0x03, 0x00, 0x02, 0x80, 0x00, 0x20,
  0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08,
  0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x70, 0xdf, 0xdf,
  0xdb, 0x77, 0x00, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40,
  0x00, 0x10, 0x00, 0x04, 0x00, 0xee, 0xfb, 0x7b, 0x6b, 0x33, 0x01, 0x08, 0x02, 0x02, 0x10, 0x04,
  0x04, 0x20, 0x08, 0x08, 0x40, 0x10, 0x10, 0x80, 0x20, 0x20, 0x00, 0x41, 0x40, 0x00, 0x82, 0x80,
  0x00, 0x04, 0x01, 0x01, 0x08, 0x02, 0x02, 0x10, 0x04, 0x64, 0x32, 0x61, 0xbd, 0x04,
  };
  #else
  const uint8_t PROGMEM Large_Spinning_Card_02[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  #ifndef DEBUG
  const unsigned char PROGMEM Large_Spinning_Card_03[] ={
  0x1f, 0x1f, 0x5f, 0x5a, 0x30, 0x99, 0x08, 0x48, 0x00, 0x10, 0x90, 0x00, 0x20, 0x20, 0x01, 0x40,
  0x40, 0x02, 0x80, 0x80, 0x04, 0x00, 0x01, 0x09, 0x00, 0x02, 0x12, 0x00, 0x04, 0x24, 0x00, 0x4c,
  0xf6, 0xfa, 0x3d, 0xfb, 0x0e, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02,
  0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00,
  0xc0, 0x7d, 0xff, 0x9e, 0x7d, 0x07, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00,
  0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40,
  0x00, 0xe0, 0xbe, 0x7f, 0xcf, 0xda, 0x4c, 0x00, 0x82, 0x80, 0x00, 0x04, 0x01, 0x01, 0x08, 0x02,
  0x02, 0x10, 0x04, 0x04, 0x20, 0x08, 0x08, 0x40, 0x10, 0x10, 0x80, 0x20, 0x20, 0x00, 0x41, 0x40,
  0x26, 0x13, 0xd6, 0x97, 0x00,
  };
  #else
  const uint8_t PROGMEM Large_Spinning_Card_03[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  #ifndef DEBUG
  const unsigned char PROGMEM Large_Spinning_Card_04[] ={
  0x1f, 0x1f, 0x5f, 0x5e, 0x30, 0x99, 0x08, 0x48, 0x00, 0x10, 0x90, 0x00, 0x20, 0x20, 0x01, 0x40,
  0x40, 0x02, 0x80, 0x80, 0x04, 0x00, 0x01, 0x09, 0x00, 0x93, 0xbd, 0x7e, 0xef, 0xbe, 0x03, 0x00,
  0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00, 0x02, 0x80,
  0x00, 0x20, 0x00, 0x70, 0xdf, 0xbf, 0x77, 0xdf, 0x01, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04,
  0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0xb8, 0xef, 0xdf,
  0xbb, 0x36, 0x13, 0x80, 0x20, 0x20, 0x00, 0x41, 0x40, 0x00, 0x82, 0x80, 0x00, 0x04, 0x01, 0x01,
  0x08, 0x02, 0x02, 0x10, 0x04, 0x64, 0x32, 0x61, 0x7d, 0x19,
  };
  #else
  const uint8_t PROGMEM Large_Spinning_Card_04[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  const unsigned char PROGMEM Large_Spinning_Card_05[] ={
  0x1f, 0x1f, 0xbf, 0x64, 0xc1, 0x64, 0x22, 0x20, 0x01, 0x40, 0x40, 0x02, 0x80, 0x80, 0x04, 0x00,
  0x01, 0x09, 0x00, 0x93, 0xbd, 0xfe, 0x1e, 0xfb, 0x0e, 0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0x20,
  0x00, 0x08, 0x00, 0x02, 0x80, 0x00, 0xc0, 0x7d, 0xff, 0x3d, 0xf6, 0x1d, 0x00, 0x10, 0x00, 0x04,
  0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x80, 0xfb, 0xfe, 0x7b, 0xac, 0xcd, 0x04,
  0x20, 0x08, 0x08, 0x40, 0x10, 0x10, 0x80, 0x20, 0x20, 0x00, 0x41, 0x40, 0x26, 0x13, 0xd6, 0x2f,
  0x01,
  };
  const unsigned char PROGMEM Large_Spinning_Card_06[] ={
  0x1f, 0x1f, 0xbf, 0x6c, 0xc1, 0x64, 0x22, 0x20, 0x01, 0x40, 0x40, 0x02, 0xc0, 0x64, 0xaf, 0xbf,
  0xd7, 0xbe, 0x03, 0x00, 0x02, 0x80, 0x00, 0x20, 0x00, 0x70, 0xdf, 0x7f, 0xaf, 0x7d, 0x07, 0x00,
  0x04, 0x00, 0x01, 0x40, 0x00, 0xe0, 0xbe, 0xff, 0x5e, 0x6b, 0x33, 0x01, 0x08, 0x02, 0x02, 0x10,
  0x04, 0x64, 0x32, 0x61, 0xfd, 0x32,
  };

  const unsigned char PROGMEM Large_Spinning_Card_07[] ={
  0x1f, 0x1f, 0xbf, 0x74, 0xc1, 0x64, 0x32, 0xd9, 0xeb, 0xef, 0xb9, 0xdf, 0xef, 0xbf, 0xe7, 0x7e,
  0xbf, 0xff, 0x9e, 0x6b, 0x33, 0x99, 0x4c, 0x58, 0xbf, 0x14,
  };

  const unsigned char PROGMEM Large_Spinning_Card_08[] ={
  0x1f, 0x9f, 0xbf, 0x6b, 0x85, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x8d, 0xac, 0xbf, 0xd7, 0xfe, 0xfe,
  0xfe, 0x7b, 0xed, 0xef, 0xef, 0xbf, 0xd8, 0x5a, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0x64, 0xad, 0x5f,
  0x06,
  };

  const unsigned char PROGMEM Large_Spinning_Card_09[] ={
  0x1f, 0x9f, 0xbf, 0x63, 0x85, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0xb2, 0xfe,
  0x1e, 0xfb, 0xf7, 0xed, 0xbf, 0xc7, 0xfe, 0x7d, 0xfb, 0x2f, 0xb2, 0x16, 0x72, 0x43, 0x6e, 0xc8,
  0x0d, 0xb9, 0x21, 0x37, 0x64, 0xad, 0x5f, 0x02,
  };

  const unsigned char PROGMEM Large_Spinning_Card_10[] ={
  0x1f, 0x9f, 0xdf, 0x5d, 0xe1, 0x86, 0xdc, 0x90, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0xb9, 0x21,
  0x37, 0xb2, 0x7e, 0xef, 0xfe, 0xfd, 0xfb, 0xf7, 0xee, 0xdf, 0xbf, 0x7f, 0xf1, 0x5a, 0xc8, 0x0d,
  0xb9, 0x21, 0x37, 0xe4, 0x86, 0xdc, 0x90, 0x1b, 0x72, 0x43, 0xd6, 0xfa, 0x32,
  };

  const unsigned char PROGMEM Large_Spinning_Card_11[] ={
  0x1f, 0x9f, 0xdf, 0x59, 0xe1, 0x86, 0xdc, 0x90, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0xb9, 0x21,
  0x37, 0xe4, 0x86, 0xdc, 0xc8, 0xfa, 0x3d, 0xfb, 0xef, 0xb3, 0x7f, 0xcf, 0xfe, 0xfb, 0xec, 0x5f,
  0xb4, 0x16, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0xe4, 0x86, 0xdc, 0x90, 0x1b, 0x72,
  0x43, 0xd6, 0xfa, 0x12,
  };

  const unsigned char PROGMEM Large_Spinning_Card_12[] ={
  0x1f, 0x9f, 0xef, 0x56, 0xb8, 0x21, 0x37, 0xe4, 0x86, 0xdc, 0x90, 0x1b, 0x72, 0x43, 0x6e, 0xc8,
  0x0d, 0xb9, 0x21, 0x37, 0xe4, 0x86, 0xdc, 0xc8, 0xfa, 0xde, 0xfe, 0xfb, 0xed, 0xef, 0xed, 0xbf,
  0xdf, 0xfe, 0xe2, 0x5a, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0xe4, 0x86, 0xdc, 0x90, 0x1b, 0x72, 0x43,
  0x6e, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0x64, 0xad, 0x97,
  };

  const unsigned char PROGMEM Large_Spinning_Card_13[] ={
  0x1f, 0x9f, 0x7b, 0x85, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0xe4, 0x86, 0xdc,
  0x90, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0xb2, 0xee, 0xfb, 0xef, 0xbb, 0xef,
  0xfb, 0xef, 0xbb, 0x5f, 0xac, 0x85, 0xdc, 0x90, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0xb9, 0x21,
  0x37, 0xe4, 0x86, 0xdc, 0x90, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0x59, 0xeb, 0x02,
  };

  const unsigned char PROGMEM Large_Spinning_Card_Inlay[] ={
  0x01, 0x1f, 0x20, 0x20, 0x01, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x21, 0x08, 0x08,
  };
  
  // const uint8_t * const Large_Spinning_Cards[] = { 
  // Large_Spinning_Card_01, 
  // Large_Spinning_Card_02, 
  // Large_Spinning_Card_03, 
  // Large_Spinning_Card_04, 
  // Large_Spinning_Card_05, 
  // Large_Spinning_Card_06, 
  // Large_Spinning_Card_07, 
  // Large_Spinning_Card_08, 
  // Large_Spinning_Card_09, 
  // Large_Spinning_Card_10, 
  // Large_Spinning_Card_11, 
  // Large_Spinning_Card_12, 
  // Large_Spinning_Card_13, 
  // };

  const uint8_t * const Large_Spinning_Cards[] = { 
  Large_Spinning_Card_13, 
  Large_Spinning_Card_12, 
  Large_Spinning_Card_11, 
  Large_Spinning_Card_10, 
  Large_Spinning_Card_09, 
  Large_Spinning_Card_08, 
  Large_Spinning_Card_07, 
  Large_Spinning_Card_08, 
  Large_Spinning_Card_09, 
  Large_Spinning_Card_10, 
  Large_Spinning_Card_11, 
  Large_Spinning_Card_12, 
  Large_Spinning_Card_13, 
  };

  const uint8_t Large_Spinning_Inlays[] = { 
    12, 10, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0
  };

  const uint8_t PROGMEM Message_Box[] ={
  52, 15,
  0x00, 0x00, 0xf8, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xf8, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00, 
  };

}