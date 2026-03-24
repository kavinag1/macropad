# QMK build options for Seeed XIAO RP2040 macropad
MCU = RP2040
BOOTLOADER = rp2040

# Features used in this port.
ENCODER_ENABLE = yes
EXTRAKEY_ENABLE = yes
OLED_ENABLE = yes
LTO_ENABLE = yes

# Keep firmware lean.
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = yes
