# Hackpad Project Submission

This repository contains the full source and production package for a Seeed XIAO RP2040 macropad.

## 1. Create and connect a GitHub repository

If you have not already created a remote repo, use this flow:

```bash
git init
git add .
git commit -m "Initial hackpad submission package"
git branch -M main
git remote add origin https://github.com/<your-username>/<your-repo>.git
git push -u origin main
```

If you already created a repo on GitHub first, clone it and copy these project files into that clone, then run:

```bash
git add .
git commit -m "Add hackpad design, firmware, and production files"
git push
```

## 2. Project structure

Top-level folders in this project:

- CAD
- PCB
- Firmware
- production
- gallery

### CAD

Single assembled case/model source file:

- CAD/full_macropad.step

### PCB

KiCad source files:

- PCB/schem.kicad_pro
- PCB/schem.kicad_sch
- PCB/schem.kicad_pcb

### Firmware

Firmware source files:

- Firmware/qmk/xiao_macropad (QMK port only)

### production

Manufacturing/build outputs:

- production/gerbers.zip
- production/Top.step
- production/Bottom.step
- production/knurled_knob v12.step
- production/firmware.uf2

## 3. Production file checklist

1. PCB Gerbers: Present as production/gerbers.zip
2. Case part exports: Present as STEP files in production/
3. Firmware binary: Place the compiled UF2 at production/firmware.uf2

QMK compile command (from qmk_firmware):

```bash
qmk compile -kb xiao_macropad -km default
```

After compile, copy the generated UF2 into production/ and rename it to firmware.uf2.

## 4. QMK coding keymap (default)

This keymap is intentionally set up for coding workflows:

- Key 1 (SW1): Ctrl+S (Save)
- Key 2 (SW2): Ctrl+F (Find)
- Key 3 (SW3): Ctrl+/ (Toggle comment)
- Key 4 (SW4): Ctrl+Z (Undo)
- Encoder press (SW5): Ctrl+Shift+B (Build task)
- Encoder clockwise: Ctrl+PgDn (Next tab)
- Encoder counter-clockwise: Ctrl+PgUp (Previous tab)

## 5. Required screenshots

README embeds:

### Overall Hackpad

![Overall Hackpad](gallery/Screenshot%202026-03-24%20031019.png)

### Schematic

![Schematic](gallery/Screenshot%202026-03-23%20221114.png)

### PCB

![PCB](gallery/Screenshot%202026-03-24%20030428.png)

### Case Assembly

![Case Assembly](gallery/Screenshot%202026-03-24%20031019.png)

## 6. BOM

| Item | Qty | Notes |
|---|---:|---|
| Seeed XIAO RP2040 (through-hole) | 1 | Main MCU |
| MX-compatible mechanical switch | 4 | SW1-SW4 |
| EC11 rotary encoder with push switch | 1 | SW5 |
| SSD1306 0.91 inch 128x32 I2C OLED | 1 | Display module |
| Keycaps | 4 | For switch keys |
| Encoder knob | 1 | Rotary control |
| PCB | 1 | 2-layer design |
| 3D printed case parts | 2+ | Top and bottom (plus any extra parts) |

## 7. Design requirements quick check

- MCU: Seeed XIAO RP2040 through-hole footprint used
- PCB source present and intended as 2-layer design
- Input count: 5 total inputs (4 keys + 1 encoder press) plus encoder rotation
- Case and PCB source/manufacturing files included

If you want, I can also generate a small pre-flight script that checks these required files automatically before you submit.