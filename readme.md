# Arduino Weight Scale with TFT Display and Touch Interface

This project uses a custom board with a ESP32 to create a weight scale with a TFT display and touch interface. The weight is measured using an HX711 load cell amplifier and displayed on a TFT screen using the LVGL graphics library.

## Components

- Arduino board
- HX711 load cell amplifier
- CrowPanel 4.3"-HMI ESP32 Display 480x272 RGB TFT LCD Touch Screen
- Load cell
- Connecting wires

## Libraries

The following libraries are used in this project:

- `Arduino.h`
- `Wire.h`
- `SPI.h`
- `lvgl.h`
- `HX711.h`

## Hardware Details

### CrowPanel 4.3"-HMI ESP32 Display

- **Model:** CrowPanel ESP32 Display 4.3 Inch module
- **Resolution:** 480x272
- **Touch Type:** Resistive Touch Screen
- **Display Type:** TFT-LCD Screen
- **Main Processor:** ESP32-S3-WROOM-1-N4R2
- **Frequency:** 240 MHz
- **Flash:** 4MB
- **SRAM:** 512KB
- **PSRAM:** 2MB
- **Display Driver:** NV3047
- **Interfaces:**
  - 1x TF Card Slot
  - 2x GPIO
  - 1x Speaker
  - 2x UART1
  - 1x UART0
- **External Power Supply:** DC5V-2A
- **Active Area:** 95.04x53.86mm (W x H)
- **Package Includes:**
  - 1x CrowPanel ESP32 Display-4.3 Inch module
  - 1x USB-A to Type-C Cable
  - 1x Crowtail/Grove to 4pin DuPont cable
  - 1x Resistive touch pen

For more details, visit the [product page](https://www.elecrow.com/esp32-display-4-3-inch-hmi-display-rgb-tft-lcd-touch-screen.html).

## Setup

1. **Hardware Connections:**

   - Connect the load cell to the HX711 module.
   - Connect the HX711 module to the Arduino:
     - DOUT to pin 37
     - SCK to pin 38
   - Connect the CrowPanel 4.3" display and touch screen to the Arduino as per the display's documentation.

2. **Software Setup:**
   - Install the required libraries in the Arduino IDE.
   - Load the provided code into the Arduino IDE.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
