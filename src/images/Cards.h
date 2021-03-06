#pragma once

namespace Images {
  
  const uint8_t PROGMEM Card_Outline_Comp[] = {
  0x09, 0x0f, 0x97, 0x05, 0x93, 0x49, 0x00, 0x10, 0x90, 0x00, 0x20, 0x20, 0x01, 0x40, 0xe0, 0x30,
  0x5f, 0x00, 0x20, 0x00, 0x20, 0x00, 0x02, 0x00, 0x02, 0x20, 0x00, 0x00,
  };

  const uint8_t PROGMEM Card_Outline_Comp_Mask[] = {
  0x09, 0x0f, 0xfc, 0x79, 0x00,
  };

  const uint8_t PROGMEM Card_Outline_Highlight_Comp[] = {
  0x13, 0x9f, 0x07, 0x00, 0xc2, 0x99, 0x33, 0x67, 0xde, 0x72, 0xe6, 0xcc, 0x99, 0x00, 0xf0, 0x02, 
  0x00, 0xf8, 0xfd, 0x00, 0xc0, 0x0b, 0x00, 0xe0, 0xf7, 0x03, 0x00, 0xaf, 0x80, 0x70, 0xe6, 0xcc, 
  0x99, 0x77, 0x9c, 0x39, 0x73, 0x26, 0xc0, 0x11,
  };

  const uint8_t PROGMEM Card_Faces_Resting[] = {
  0x0d, 0xcf, 0xa7, 0x64, 0x94, 0xf0, 0x1a, 0xc0, 0xab, 0x52, 0x00, 0x44, 0x1f, 0x05, 0x20, 0x14, 
  0x28, 0xa1, 0x00, 0xd8, 0x30, 0x84, 0xc1, 0xcc, 0xad, 0x47, 0x00,
  };

  const uint8_t PROGMEM Card_Faces_Treasure[] = {
  0x0d, 0xcf, 0x27, 0x49, 0x19, 0xaa, 0x40, 0xa3, 0x02, 0x05, 0xd4, 0x14, 0x50, 0x1d, 0x34, 0xf8, 
  0x66, 0xd4, 0x11, 0x28, 0xa8, 0x00, 0x05, 0x40, 0x00, 0x0a, 0xa0, 0x42, 0x21, 0xc3, 0x8e, 0x03, 
  };

  const uint8_t PROGMEM Card_Faces_Event[] = {
  0x0d, 0x8f, 0x8f, 0x04, 0x99, 0xa0, 0x81, 0x82, 0x82, 0x50, 0x98, 0x30, 0x49, 0x3e, 0x3a, 0x06, 
  0x43, 0x04, 0x41, 0x52, 0x46, 0xc2, 0x91, 0x3b,
  };

  const uint8_t PROGMEM Card_Faces_Merchant[] = {
  0x0d, 0xcf, 0x6f, 0xa1, 0xb0, 0x01, 0x81, 0xdd, 0x13, 0x0c, 0xf8, 0xa6, 0x27, 0x06, 0x07, 0xf4, 
  0x42, 0x04, 0x28, 0x80, 0xe1, 0x0d,
  };

  const uint8_t PROGMEM Card_Faces_Trap[] = {
  0x0d, 0x8f, 0x0f, 0x09, 0x25, 0x94, 0x09, 0x26, 0x0b, 0x2c, 0x8b, 0x20, 0xe1, 0x2b, 0x71, 0x0d, 
  0xc3, 0x25, 0x8e, 0x15, 0xb9, 0x98, 0x35, 0x72, 0x00,
  };

  const uint8_t PROGMEM Card_Faces_Monster[] = {
  0x0d, 0x0f, 0x57, 0xeb, 0x60, 0x61, 0xc0, 0x08, 0x15, 0x06, 0x50, 0x31, 0xc1, 0x84, 0xed, 0x76, 
  0xf7, 0x01, 0x12, 0x4a, 0x30, 0x03, 0x90, 0x38, 0x0c, 0x12, 0x36, 0x97, 0x11,
  };

  const uint8_t PROGMEM Card_Faces_Boss[] = {
  0x0d, 0x0f, 0x93, 0xa6, 0x2c, 0x0c, 0x18, 0x01, 0x14, 0x44, 0x00, 0x14, 0x13, 0x4c, 0xd8, 0xd9, 
  0x6c, 0xa6, 0x3a, 0xa0, 0x06, 0x00, 0x18, 0x2a, 0xb0, 0x50, 0x05, 0x6a, 0x20, 0x30, 0x54, 0xce, 
  };

  const uint8_t PROGMEM Card_Faces_Delve[] = {
  0x0d, 0x0f, 0x97, 0x25, 0x13, 0x2a, 0x54, 0x26, 0x46, 0x26, 0x51, 0x26, 0x45, 0xe6, 0xba, 0xcf, 
  0x09, 0x03, 0x18, 0x30, 0x61, 0xc0, 0x84, 0x01, 0x13, 0x06, 0x4c, 0x98, 0x07,
  };

  const uint8_t * const Card_Faces[] = { 
    Card_Faces_Resting,
    Card_Faces_Treasure,
    Card_Faces_Event,
    Card_Faces_Merchant,
    Card_Faces_Trap,
    Card_Faces_Monster,
    Card_Faces_Boss,
    Card_Faces_Delve
  };

  const uint8_t PROGMEM Card_Border_Right_Comp[] = {
  0x05, 0xe7, 0x42, 0xd4, 0x35, 0xaa, 0x1d, 0x70, 0x44, 0x75, 0x61, 0xdb, 0x02, 0xa7, 0xe8, 0x1a,
  0xee, 0x0d, 0x5c, 0x2a, 0x69, 0xb4, 0x37, 0x12, 0x00, 0xd3, 0x44, 0xdd, 0x99,
  };

  const uint8_t PROGMEM Card_Border_Top_Comp[] = {
  0x09, 0x07, 0x37, 0x47, 0x46, 0x96, 0xa7, 0x2c, 0x21, 0x81, 0x5a,
  };

  const uint8_t PROGMEM Card_Border_Bottom_Comp[] = {
  0x09, 0xc7, 0xe6, 0xae, 0xd9, 0xd1, 0xbb, 0x23, 0x20, 0x18,
  };

  const uint8_t PROGMEM Card_Spinning_01_Comp[] = {
  0x09, 0x0f, 0x2f, 0x17, 0x4c, 0x26, 0x02, 0x12, 0x00, 0x04, 0x24, 0xc0, 0xbb, 0x7d, 0x07, 0x00,
  0x04, 0x00, 0x01, 0x40, 0x00, 0x00,
  };

  const uint8_t PROGMEM Card_Spinning_02_Comp[] = {
  0x09, 0x0f, 0x5f, 0x5c, 0x30, 0x99, 0x04, 0xf8, 0xde, 0x7e, 0x00, 0x00, 0x00,
  };

  const uint8_t PROGMEM Card_Spinning_03_Comp[] = {
  0x09, 0x0f, 0x5f, 0x5e, 0x30, 0xf9, 0xfa, 0xbe, 0x03,
  };

  const uint8_t PROGMEM Card_Spinning_04_Comp[] = {
  0x09, 0x0f, 0x5f, 0x5c, 0x30, 0x99, 0x7c, 0x75, 0xbf, 0x03,
  };

  const uint8_t PROGMEM Card_Spinning_05_Comp[] = {
  0x09, 0x0f, 0x2f, 0x17, 0x4c, 0x26, 0x93, 0xc9, 0xe4, 0xf5, 0xfe, 0x1e,
  };

  const uint8_t PROGMEM Card_Spinning_06_Comp[] = {
  0x09, 0x0f, 0x97, 0x05, 0x93, 0xc9, 0x64, 0x32, 0x99, 0x4c, 0xae, 0xfb, 0xfb,
  };

  const uint8_t PROGMEM Card_Spinning_01_05_Mask_Comp[] = {
  0x09, 0x0f, 0x2f, 0x16, 0x9f, 0xbd, 0x7f, 0x1f,
  };

  const uint8_t PROGMEM Card_Spinning_02_04_Mask_Comp[] = {
  0x09, 0x0f, 0x5f, 0x5a, 0x3c, 0xff, 0xce, 0x77, 0x00,
  };

  const uint8_t PROGMEM Card_Spinning_03_Mask_Comp[] = {
  0x09, 0x0f, 0x5f, 0x5c, 0x3c, 0xfb, 0xde, 0x7b,
  };

  const uint8_t PROGMEM Card_Spinning_06_Mask_Comp[] = {
  0x09, 0x0f, 0x2e, 0xfe, 0x2c,
  };

  const uint8_t * const spinning_card[] = { 
    Card_Spinning_06_Comp, 
    Card_Spinning_05_Comp, 
    Card_Spinning_04_Comp, 
    Card_Spinning_03_Comp, 
    Card_Spinning_02_Comp, 
    Card_Spinning_01_Comp, 
    Card_Outline_Comp, 
  };

  const uint8_t * const spinning_mask[] = { 
    Card_Spinning_06_Mask_Comp, 
    Card_Spinning_01_05_Mask_Comp, 
    Card_Spinning_02_04_Mask_Comp, 
    Card_Spinning_03_Mask_Comp, 
    Card_Spinning_02_04_Mask_Comp, 
    Card_Spinning_01_05_Mask_Comp, 
    Card_Outline_Comp_Mask, 
  };

}
