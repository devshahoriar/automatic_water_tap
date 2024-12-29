
# Automatic Water Tap Project 🚰

An **Automatic Water Tap** system designed to promote hygiene and conserve water by using a relay module, ultrasonic sensor, Arduino, and a mini water pump. This project ensures water flows only when an object (like a hand) is detected under the tap.

---

## 📋 Table of Contents
1. [Overview](#overview)
2. [Features](#features)
3. [Components](#components)
4. [Circuit Diagram](#circuit-diagram)
5. [Step-by-Step Instructions](#step-by-step-instructions)
6. [Testing](#testing)
7. [Prototyping Images and Videos](#prototyping-images-and-videos)
8. [Results](#results)
9. [Future Enhancements](#future-enhancements)
10. [License](#license)

---

## Overview
This project combines the power of **Arduino microcontroller** and **ultrasonic sensors** to create a touch-free automatic water tap system. Perfect for kitchens, bathrooms, or public places, it helps maintain hygiene by avoiding direct contact with the tap.

---

## Features
- **Automatic Water Flow:** Water starts flowing when an object is detected within a specific range.
- **Energy Efficient:** Uses a relay module to control the water pump, reducing unnecessary power consumption.
- **Compact Design:** Easy to integrate into existing systems.

---

## Components
Here are the hardware components required for the project:
- Arduino Uno (or compatible microcontroller)
- Ultrasonic Sensor (e.g., HC-SR04)
- Relay Module
- Mini Water Pump
- Power Supply (e.g., 5V DC adapter)
- Jumper Wires
- Water Reservoir (for testing)

---

## Circuit Diagram
![Circuit Diagram Placeholder](path/to/your/circuit_diagram.jpg)  
*Replace the above placeholder with your actual circuit diagram.*

---

## Step-by-Step Instructions
Follow these steps to build and test the Automatic Water Tap project:

### Step 1: Gather Components
Collect all the necessary components listed above and ensure they are functioning.

### Step 2: Assemble the Circuit
1. Connect the **ultrasonic sensor** to the Arduino as follows:
   - **VCC** to 5V
   - **GND** to GND
   - **TRIG** to Arduino digital pin 7
   - **ECHO** to Arduino digital pin 6
2. Connect the **relay module**:
   - **Signal pin** to Arduino digital pin 8
   - **VCC** to 5V
   - **GND** to GND
3. Connect the **mini water pump** to the relay module as per its specifications.

### Step 3: Upload the Code
Upload the following Arduino code to your board:
```cpp
#define TRIG_PIN 7
#define ECHO_PIN 6
#define RELAY_PIN 8

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Pump is off initially
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1; // Convert to cm

  if (distance > 0 && distance <= 10) { // Object detected within 10 cm
    digitalWrite(RELAY_PIN, HIGH); // Turn on pump
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off pump
  }

  delay(200);
}
```

### Step 4: Testing
- Power up the circuit and place your hand or an object near the ultrasonic sensor.
- Observe if the water pump activates when an object is detected.

---

## Testing
During testing, ensure the following:
1. The ultrasonic sensor accurately detects objects within a range of **10 cm**.
2. The relay module switches the water pump ON/OFF as per the sensor's input.
3. The water pump runs smoothly without delays or interruptions.

---

## Prototyping Images and Videos
### Images
![Prototype Image Placeholder](path/to/your/prototype_image.jpg)  
*Replace the above placeholder with your actual prototype image.*

### Video
![Prototype Video Placeholder](path/to/your/prototype_video.mp4)  
*Replace the above placeholder with a link to your project video.*

---

## Results
- **Accuracy:** The sensor successfully detects objects within 10 cm and activates the pump.
- **Efficiency:** The relay module efficiently manages the water pump's operation.
- **Outcome:** The system meets all design expectations and demonstrates practical usability.

---

## Future Enhancements
- Add an **LED indicator** to show system status.
- Implement **adjustable detection range** via a potentiometer.
- Integrate a **mobile app** for remote control and monitoring.

---

## License
This project is licensed under the MIT License. Feel free to use and modify the project for educational or personal use.

---

## Contributing
We welcome contributions! If you have ideas for improvements or spot a bug, feel free to create an issue or submit a pull request.

---

Happy Coding! 🚀
