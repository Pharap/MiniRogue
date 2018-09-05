#pragma once

namespace Images {

  const uint8_t PROGMEM Dice[] = {
  9, 9,
  0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0x01, 0x01, 0x01, 0x11, 0x01, 0x01, 0x01, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0x01, 0x05, 0x01, 0x01, 0x01, 0x41, 0x01, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0x01, 0x41, 0x01, 0x11, 0x01, 0x05, 0x01, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0x01, 0x45, 0x01, 0x01, 0x01, 0x45, 0x01, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0x01, 0x45, 0x01, 0x11, 0x01, 0x45, 0x01, 0xfe, 
  0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 

  0xfe, 0x01, 0x55, 0x01, 0x01, 0x01, 0x55, 0x01, 0xfe, 
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
  0x8b, 0xff, 0x7b, 0x63, 0x6d, 0xb0, 0x96, 0x52, 0x4b, 0x69, 0xb4, 0x37, 0xd8, 0x87, 0x4a, 0x6a, 
  0x0d, 0xb5, 0x94, 0x5a, 0xaa, 0x3b, 0x73, 0xef, 0xe8, 0x5a, 0x4a, 0x59, 0x6c, 0x16, 0x5b, 0x3b, 
  0x60, 0xec, 0xb3, 0x4b, 0x55, 0x8a, 0x14, 0x29, 0x52, 0xb0, 0x6d, 0x81, 0xec, 0x83, 0xae, 0xa5, 
  0x8b, 0xcd, 0x62, 0x33, 0xdc, 0x1b, 0x60, 0x6f, 0xac, 0x0d, 0xd6, 0x52, 0x6a, 0x29, 0x8d, 0xf6, 
  0x06, 0xfb, 0x50, 0x49, 0xad, 0xa1, 0x96, 0x52, 0x4b, 0x75, 0x67, 0xee, 0x1d, 0x5d, 0x4b, 0x29, 
  0x8b, 0xcd, 0x62, 0x6b, 0x07, 0x0c,
  };

  const uint8_t PROGMEM Health_Comp[] = {
  0x17, 0xb7, 0x4f, 0x80, 0xc1, 0x04, 0x8e, 0x0d, 0x30, 0x79, 0x04, 0x2c, 0xe0, 0x37, 0x3b, 0x61, 
  0xce, 0xa1, 0x8f, 0xb9, 0xf1, 0x83, 0xbd, 0x09, 0x83, 0x05, 0x7e, 0xc4, 0x1f, 0xaf, 0x1c, 0x18, 
  0x9c, 0x7c, 0x0b, 0x08, 0xfc, 0xea, 0x86, 0x22, 0x08, 0xae, 0xf4, 0x29, 0xb0, 0x81, 0xdf, 0xe7, 
  0x71, 0x5c, 0xd6, 0x09, 0x78, 0xce, 0x95, 0x5f, 0xe9, 0x39, 0xb7, 0x1e, 0x79, 0x8d, 0xfc, 0x3a, 
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

}