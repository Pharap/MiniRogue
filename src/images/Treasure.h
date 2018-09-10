#pragma once

namespace Images {

  #ifndef DEBUG
  const uint8_t PROGMEM Chest_Background_Comp[] = {
  0xd7, 0xbf, 0x1e, 0xf9, 0xef, 0x13, 0x47, 0xff, 0xcf, 0x16, 0x9c, 0xbd, 0x7a, 0xf5, 0xcf, 0xc1, 
  0x99, 0xab, 0x67, 0x5e, 0xf3, 0xe7, 0xf0, 0xea, 0xd5, 0x33, 0x7f, 0xe6, 0xa5, 0x6b, 0x09, 0x00, 
  0x10, 0x88, 0x11, 0x02, 0x16, 0x38, 0x12, 0x4e, 0x84, 0x13, 0x61, 0x8e, 0x70, 0xa1, 0x04, 0x0c, 
  0x65, 0x8e, 0x70, 0x22, 0x9c, 0x40, 0x39, 0x95, 0x43, 0x0c, 0x00, 0x00, 0x00, 0x27, 0xf5, 0x82, 
  0xdc, 0x90, 0x8c, 0x49, 0x89, 0x10, 0xca, 0x85, 0x8c, 0x22, 0x37, 0xe4, 0x86, 0x3c, 0x00, 0x2a, 
  0x04, 0x8c, 0x81, 0x00, 0x00, 0xb8, 0x96, 0xae, 0x1f, 0x1e, 0x40, 0x20, 0x06, 0x10, 0x48, 0x8c, 
  0x40, 0x0c, 0x20, 0x10, 0x15, 0x04, 0x62, 0x00, 0x81, 0x18, 0x80, 0xbd, 0xf7, 0xde, 0x07, 0xd6, 
  0x42, 0x6e, 0xc8, 0x0d, 0xb9, 0x71, 0xd8, 0x27, 0x20, 0x80, 0x06, 0xb8, 0xec, 0x2b, 0x72, 0x43, 
  0x6e, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0xe4, 0x86, 0x5c, 0xf7, 0x05, 0x88, 0x02, 0x01, 0x4e, 0xfb, 
  0xc0, 0x0d, 0xb9, 0x21, 0x37, 0x64, 0x2d, 0x0e, 0x7b, 0xef, 0xbd, 0x01, 0x62, 0x00, 0x81, 0xa8, 
  0x20, 0x10, 0x03, 0x08, 0xc4, 0x00, 0xc6, 0x04, 0x10, 0x88, 0x01, 0x04, 0x72, 0x8e, 0x17, 0x40, 
  0x2e, 0x08, 0x5c, 0x28, 0x17, 0xea, 0x81, 0x72, 0xc1, 0x76, 0x24, 0x63, 0x14, 0xe8, 0x02, 0x5c, 
  0x34, 0x14, 0x19, 0x2c, 0xe4, 0x86, 0xdc, 0x38, 0xec, 0x13, 0x10, 0x40, 0x03, 0x5c, 0xf6, 0x15, 
  0xb9, 0x21, 0x37, 0xe4, 0x86, 0xdc, 0x90, 0x1b, 0x72, 0x43, 0xae, 0xfb, 0x02, 0x44, 0x81, 0x00, 
  0xa7, 0x7d, 0xe0, 0x86, 0xdc, 0x90, 0xc5, 0x40, 0x4a, 0xca, 0x12, 0x58, 0x05, 0x3a, 0x46, 0x32, 
  0x5a, 0xb9, 0x50, 0x0e, 0x96, 0x0b, 0x20, 0x17, 0xca, 0x05, 0x81, 0x8b, 0x59,
  };
  #else
  const uint8_t PROGMEM Chest_Background_Comp[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  #ifndef DEBUG
  const uint8_t PROGMEM Chest_Open_Comp[] = {
  0x3b, 0x9f, 0x6f, 0xa8, 0x30, 0x00, 0x51, 0x28, 0x00, 0x80, 0x50, 0x00, 0x22, 0x14, 0x80, 0x08, 
  0x05, 0x20, 0x42, 0x01, 0x88, 0x50, 0x00, 0x22, 0x14, 0x80, 0x08, 0x05, 0x04, 0x00, 0x0a, 0x80, 
  0x00, 0x14, 0x00, 0x01, 0x01, 0x08, 0xa2, 0x88, 0x22, 0x8a, 0x22, 0x12, 0x50, 0x44, 0x00, 0x00, 
  0x04, 0x04, 0xa0, 0x00, 0x08, 0x40, 0x01, 0x00, 0x84, 0x02, 0x10, 0xa1, 0x00, 0x44, 0x28, 0x00, 
  0x11, 0x0a, 0x40, 0x84, 0x02, 0x10, 0xa1, 0x00, 0x00, 0x42, 0x01, 0x88, 0x50, 0x00, 0x40, 0x60, 
  0x80, 0xe5, 0x9b, 0xfb, 0x00, 0x00, 0x00, 0x80, 0x08, 0x00, 0x80, 0x00, 0x8c, 0x85, 0x37, 0xf0, 
  0x06, 0xde, 0xc0, 0xf3, 0xfe, 0x7b, 0xec, 0x23, 0x78, 0x03, 0x6f, 0xe0, 0x0d, 0x64, 0xad, 0x04, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xec, 0xdf, 0xb1, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xc0, 0xde, 0x83, 0x33, 0x67, 0xce, 0x5c, 0xf6, 0xdf, 0x63, 0x3f, 0xe2, 0xcc, 0x99, 0xcb, 0xde, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x61, 0x7f, 0x90, 0x13, 0xe5, 0xc0, 0xec, 0xa0, 0x08, 0x80, 
  0x06, 0x31, 0x80, 0x0a, 0x85, 0x8a, 0x80, 0x00, 0x2a, 0x29, 0x98, 0x2c, 0x41, 0x30, 0x58, 0x41, 
  0x10, 0x04, 0x01, 0x11, 0x63, 0x44, 0x68, 0x08, 0xa2, 0x55, 0x84, 0x34, 0x20, 0x9a, 0x82, 0x50, 
  0x41, 0x10, 0x04, 0x41, 0x10, 0x4d, 0x00, 0x90, 0x08, 0x82, 0x20, 0x08, 0x42, 0x86, 0x9d, 0x31, 
  0x0d, 0x31, 0x20, 0x49, 0x08, 0x00, 0x52, 0x46, 0x27, 0x07, 0xca, 0x89, 0x03,
  };
  #else
  const uint8_t PROGMEM Chest_Open_Comp[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  #ifndef DEBUG
  const uint8_t PROGMEM Chest_Closed_Comp[] = {
  0x3b, 0x97, 0xff, 0xc0, 0xef, 0xf3, 0x30, 0x4f, 0xb4, 0xa8, 0x6c, 0x54, 0x36, 0x2a, 0x27, 0xe7, 
  0x20, 0x1b, 0x48, 0x00, 0x02, 0xc4, 0x39, 0xc8, 0x09, 0x95, 0x8d, 0xca, 0x46, 0x65, 0xa3, 0xb2, 
  0x51, 0xd9, 0xa8, 0x6c, 0x54, 0x4e, 0x61, 0x4c, 0x03, 0x04, 0x20, 0x01, 0x76, 0x18, 0x53, 0xd9, 
  0xa8, 0x6c, 0x54, 0x36, 0x2a, 0x2d, 0xa7, 0x79, 0x98, 0x77, 0x16, 0xb2, 0x06, 0x08, 0x74, 0x80, 
  0xc0, 0x14, 0x04, 0x58, 0x00, 0x02, 0x2c, 0x00, 0x01, 0x16, 0x80, 0x70, 0x01, 0x81, 0x0e, 0x10, 
  0x06, 0x08, 0x08, 0x17, 0x10, 0xe8, 0x00, 0x01, 0x16, 0x80, 0x00, 0x0b, 0x0a, 0xb0, 0x00, 0x04, 
  0x58, 0x00, 0x02, 0x2c, 0x28, 0xc0, 0x02, 0x10, 0x60, 0x01, 0x08, 0xa3, 0x80, 0x70, 0x01, 0x01, 
  0x61, 0x80, 0x30, 0x0a, 0x08, 0x1b, 0x40, 0x80, 0x05, 0x20, 0xc0, 0x02, 0x10, 0x60, 0x01, 0x08, 
  0x4e, 0x40, 0x18, 0x05, 0x84, 0xb1, 0x90, 0x05,
  };
  #else
  const uint8_t PROGMEM Chest_Closed_Comp[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  const unsigned char PROGMEM Chest_Dice_01[] ={
  0x11, 0x97, 0x0f, 0x39, 0x02, 0x47, 0xe0, 0x31, 0x0f, 0xb8, 0xf9, 0x55, 0xe5, 0x62, 0x38, 0x79, 
  0xce, 0x91, 0x23, 0xe6, 0xc2, 0x5f, 0x08,
  };

  const unsigned char PROGMEM Chest_Dice_02[] ={
  0x11, 0x97, 0xaf, 0x38, 0xe7, 0xc8, 0x7b, 0x1e, 0x70, 0xf3, 0x3b, 0xc0, 0x49, 0xbc, 0x09, 0x6f, 
  0x73, 0xe4, 0x88, 0xb9, 0xf0, 0x17, 0x02,
  };

  const unsigned char PROGMEM Chest_Dice_03[] ={
  0x11, 0xd7, 0x77, 0x8e, 0xe0, 0x0d, 0x78, 0xce, 0x63, 0xf0, 0xa3, 0x3d, 0x41, 0x6e, 0xdc, 0x39, 
  0xe6, 0x01, 0x97, 0xc8, 0x1f, 0x09,
  };

  const unsigned char PROGMEM Chest_Dice_04[] ={
  0x11, 0xd7, 0x47, 0xe4, 0x98, 0x63, 0x6e, 0xbc, 0xe0, 0x31, 0xf8, 0x21, 0x4e, 0x39, 0x8d, 0x23, 
  0xe1, 0xc6, 0x31, 0x0f, 0xb8, 0x44, 0xfe, 0x48,
  };

  const unsigned char PROGMEM Chest_Dice_05[] ={
  0x11, 0xd7, 0xaf, 0x7b, 0x43, 0x6e, 0xde, 0x79, 0x0c, 0x7e, 0xd5, 0x13, 0x83, 0x03, 0x7a, 0xe5, 
  0x98, 0x07, 0x5c, 0x22, 0x7f, 0x24,
  };

  const unsigned char PROGMEM Chest_Dice_06[] ={
  0x11, 0xd7, 0x67, 0xce, 0x9c, 0x7d, 0xce, 0x63, 0xe4, 0xc8, 0x43, 0x8e, 0xc0, 0x35, 0x27, 0xe0, 
  0xcc, 0x31, 0x77, 0x2f, 0x80, 0xfc, 0x91, 0x00,
  };

  const uint8_t * const Chest_Dice[] = { 
    Chest_Dice_01, 
    Chest_Dice_02, 
    Chest_Dice_03, 
    Chest_Dice_04, 
    Chest_Dice_05, 
    Chest_Dice_06, 
  };

};