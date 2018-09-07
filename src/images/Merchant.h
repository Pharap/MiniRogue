#pragma once

namespace Images {

  #ifndef DEBUG
  const uint8_t PROGMEM Merchant_Only_Comp[] = {
  0x3f, 0x3f, 0x3f, 0x97, 0xe1, 0x60, 0xb1, 0x58, 0x4c, 0x16, 0x93, 0x89, 0x00, 0x06, 0x90, 0x00, 
  0x12, 0x4a, 0xa8, 0xd3, 0xe9, 0xbf, 0x32, 0x13, 0xf3, 0xbd, 0xac, 0xb6, 0x11, 0x04, 0x01, 0x52, 
  0x70, 0x98, 0xb0, 0x00, 0x80, 0x02, 0x38, 0xa0, 0x6b, 0xac, 0xfc, 0x33, 0x61, 0xb1, 0x58, 0x2c, 
  0x9a, 0x2f, 0xc6, 0x35, 0x13, 0x08, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x24, 0xc0, 0xc4, 0xd9, 
  0x00, 0x14, 0x00, 0x10, 0x00, 0x58, 0x30, 0x9c, 0x2b, 0x2b, 0x23, 0xcb, 0xc9, 0x9f, 0xd4, 0x81, 
  0x84, 0x66, 0xf1, 0xfb, 0xd8, 0x6c, 0x76, 0x40, 0x42, 0xd0, 0x10, 0x1a, 0x10, 0x28, 0x41, 0x02, 
  0x14, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x10, 0x80, 0x02, 0x18, 
  0x00, 0x83, 0x29, 0x44, 0x5d, 0x19, 0x7f, 0xb8, 0x7d, 0x66, 0xb3, 0xd9, 0x6c, 0x36, 0x9b, 0xc9, 
  0x62, 0xb2, 0x58, 0x2c, 0xd6, 0x7e, 0xec, 0x00, 0x0a, 0x80, 0x10, 0xa6, 0x6c, 0x4a, 0x28, 0x41, 
  0x20, 0x08, 0x08, 0x80, 0x04, 0x51, 0x91, 0x20, 0x00, 0x02, 0x20, 0x00, 0x02, 0x00, 0xf3, 0x9e, 
  0xf1, 0x97, 0xda, 0x3f, 0x7b, 0xd7, 0x06, 0x10, 0x28, 0x20, 0x90, 0x3a, 0xbc, 0x8e, 0x9d, 0x97, 
  0x40, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 
  0xc0, 0x39, 0xd9, 0x1f, 0x63, 0x01, 0x25, 0x88, 0x8a, 0x08, 0x00, 0x04, 0x11, 0xd1, 0x12, 0x0a, 
  0x2c, 0x3e, 0xb2, 0x7f, 0xf7, 0x86, 0x80, 0x83, 0xc5, 0x67, 0xe7, 0xe6, 0x21, 0x50, 0x00, 0x40, 
  0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x40, 0x00, 0x10, 0x00, 0x04, 0x00, 0x01, 0x60, 0xef, 0x8e, 
  0x0f, 0x03, 0x00, 0x02, 0xe0, 0x64, 0xb2, 0x3f, 0x9b, 0x1f, 0x9f, 0x1f, 0x97, 0x8f, 0xb0, 0x59, 
  0x6c, 0x16, 0x9b, 0xc5, 0x66, 0xb1, 0xb9, 0xe6, 0xc0, 0x64, 0x32, 0x33, 0x5a, 0x70, 0x02, 0x10, 
  0x01, 0x5c, 0x2e, 0x97, 0x4c, 0x0a, 0xb6, 0xed, 0x60, 0x01, 0x07,
  };
  #else
  const uint8_t PROGMEM Merchant_Only_Comp[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  #ifndef DEBUG
  const uint8_t PROGMEM Merchant_Only_Mask_Comp[] = {
  0xbf, 0xff, 0x7f, 0xc6, 0x9c, 0xe6, 0x3c, 0xf9, 0xef, 0xe1, 0xef, 0xee, 0xe1, 0x8f, 0xff, 0x6f, 
  0xe2, 0xb0, 0x4e, 0xf9, 0x73, 0xfe, 0x33, 0xca, 0xe9, 0x4f, 0xf5, 0xef, 0x2a, 0xe3, 0xef, 0xf3, 
  0xef, 0xeb, 0x0b, 0x1c, 0xc2, 0x18, 0x47, 0x9e, 0xe7, 0x34, 0x13, 0x1e, 0xff, 0x23, 0xfb, 0xe4, 
  0x77, 0xbf, 0xf7, 0xef, 0x2c, 0x97, 0x75, 0x59, 0x97, 0x7c, 0x7c, 0x5d, 0x16, 0x10, 0x70, 0x51, 
  };
  #else
  const uint8_t PROGMEM Merchant_Only_Mask_Comp[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  #ifndef DEBUG
  const uint8_t PROGMEM Merchant_Buy_Comp[] = {
  0x1f, 0xbf, 0x83, 0xc1, 0xe6, 0xd5, 0x02, 0x58, 0xc2, 0x2d, 0x8b, 0xe9, 0x31, 0x0b, 0x48, 0x5f,
  0xb1, 0xd8, 0x2c, 0x36, 0x8b, 0xcd, 0x62, 0xb3, 0xd8, 0x2c, 0x36, 0x83, 0x77, 0xcc, 0xc4, 0xc3,
  0x41, 0x32, 0x00, 0xa7, 0x6f, 0x80, 0x05, 0x14, 0xf8, 0x08, 0xe2, 0x2a, 0xaf, 0x3a, 0xa8, 0x08,
  0x5d, 0xf4, 0xe3, 0x16, 0x0b, 0xaa, 0x0a, 0xf1, 0x35, 0xb0, 0x80, 0x02, 0x1f, 0x41, 0x5c, 0xe5,
  0x55, 0x07, 0x15, 0xa1, 0x8b, 0x7e, 0x35, 0x19, 0x1d, 0x69, 0x53, 0x74, 0xe4, 0x0d, 0xb0, 0x80,
  0x02, 0x6f, 0x91, 0x41, 0x05, 0x19, 0xc2, 0x8b, 0x0e, 0x2a, 0x42, 0x17, 0xfd, 0x36, 0x38, 0x90,
  0xa0, 0x45, 0x02, 0x3e, 0x06, 0x16, 0x50, 0xe0, 0x2d, 0x38, 0x10, 0x04, 0x19, 0xc2, 0x8b, 0x0e,
  0x2a, 0x42, 0x17, 0xfd, 0x36, 0x00, 0xc3, 0x8a, 0xcb, 0x00, 0xf0, 0x16, 0x58, 0x40, 0x81, 0xb7,
  0xe0, 0x40, 0x10, 0x64, 0x08, 0x2f, 0x3a, 0xa8, 0x08, 0x5d, 0xf4, 0x0b, 0xbc, 0x74, 0x05, 0x14,
  0x46, 0x20, 0xbe, 0x06, 0x16, 0x50, 0xe0, 0x2d, 0x38, 0x10, 0x04, 0x19, 0xc2, 0x8b, 0x0e, 0x2a,
  0x42, 0x17, 0x7d, 0xc2, 0x2b, 0xaf, 0x5e, 0xbd, 0x7a, 0xf5, 0xea, 0xd5, 0xab, 0x57, 0xaf, 0x5e,
  0xbd, 0x7a, 0xf5, 0xea, 0xd5, 0x33,
  };
  #else
  const uint8_t PROGMEM Merchant_Buy_Comp[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  #ifndef DEBUG
  const uint8_t PROGMEM Merchant_Sell_Comp[] = {
  0x1f, 0xa7, 0x83, 0xc1, 0xe6, 0x15, 0x02, 0x00, 0x53, 0xb8, 0x19, 0x70, 0x01, 0xc7, 0x71, 0x1a,
  0x6f, 0x58, 0x6c, 0x16, 0x9b, 0xc5, 0x66, 0xb1, 0x59, 0x6c, 0x16, 0x9b, 0xc1, 0x57, 0xc0, 0x81,
  0x04, 0x2d, 0x12, 0xf0, 0x31, 0xb0, 0x80, 0x02, 0x8f, 0xdd, 0xb0, 0x17, 0x6f, 0x3a, 0xa8, 0x08,
  0x5d, 0xf4, 0xdb, 0x00, 0x0c, 0x2b, 0x2e, 0x03, 0xc0, 0x5b, 0x60, 0x01, 0x05, 0x1e, 0xbb, 0x61,
  0x2f, 0xde, 0x74, 0x50, 0x11, 0xba, 0xe8, 0xc7, 0x5d, 0x01, 0x85, 0x11, 0x88, 0xaf, 0x81, 0x05,
  0x14, 0x78, 0xec, 0x86, 0xbd, 0x78, 0xd3, 0x41, 0x45, 0xe8, 0xa2, 0x4f, 0x39, 0x22, 0x37, 0xe4,
  0x86, 0xdc, 0x90, 0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x0d, 0xb9, 0x21, 0x37, 0xe4, 0x86, 0xdc, 0x90,
  0x1b, 0x72, 0x43, 0x6e, 0xc8, 0x11,
  };
  #else
  const uint8_t PROGMEM Merchant_Sell_Comp[] = {
  0x00 ,0x07, 0x3d
  };
  #endif

  const uint8_t PROGMEM Merchant_Highlight[] = {
  1, 8,
  0x7E
  };

}