#pragma once

#define VENDOR_ID 0x4B56
#define PRODUCT_ID 0x0001
#define DEVICE_VER 0x0001
#define MANUFACTURER kavin
#define PRODUCT xiao_macropad

#define MATRIX_ROWS 1
#define MATRIX_COLS 5

// Direct switch wiring from your KiCad net mapping.
// SW1=D8(GP2), SW2=D9(GP4), SW3=D10(GP3), SW4=D7(GP1), Encoder switch=D3(GP29)
#define DIRECT_PINS { { GP2, GP4, GP3, GP1, GP29 } }

// Encoder A/B from your PCB: D1(GP27), D2(GP28)
#define ENCODERS_PAD_A { GP27 }
#define ENCODERS_PAD_B { GP28 }
#define ENCODER_RESOLUTION 4

// OLED SSD1306 I2C wiring from your PCB: SDA=D5(GP7), SCL=D6(GP0)
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP7
#define I2C1_SCL_PIN GP0
#define OLED_DISPLAY_128X32
#define OLED_BRIGHTNESS 120

#define DEBOUNCE 5
