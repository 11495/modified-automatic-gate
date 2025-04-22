#include <IRremote.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

// Pin Definitions
const int IR_PIN_IN = 2;        // IR sensor for entry
const int IR_PIN_OUT = 3;       // IR sensor for exit
const int MOTOR_PIN1 = 9;       // Motor driver input 1 (for DC motor)
const int MOTOR_PIN2 = 10;      // Motor driver input 2
const int LED_PIN_ENTRY = 4;    // LED to show entry access
const int LED_PIN_EXIT = 5;     // LED to show exit access
const int MOTOR_ENABLE_PIN = 6; // Enable motor control

// Initialize LED Dot Matrix
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

// Initialize IR Receiver
IRrecv irrecv(IR_PIN_IN);
decode_results results;

// Servo to control the gate (DC motor setup for simplicity)
Servo gateMotor;
int motorPos = 0;  // Motor position (0 = closed, 90 = open)

int visitorCount = 0;

void setup() {
  // Start Serial Monitor
  Serial.begin(9600);

  // Motor Setup
  gateMotor.attach(11);  // Pin for the servo motor (use motor driver if needed)
  
  // LED Setup
  pinMode(LED_PIN_ENTRY, OUTPUT);
  pinMode(LED_PIN_EXIT, OUTPUT);

  // IR Sensor Setup
  irrecv.enableIRIn();  // Start the IR receiver
  
  // LED Dot Matrix Setup
  matrix.begin(HT16K33_I2C_ADDRESS);  // Set the address for the matrix
  matrix.setRotation(3); // Rotate the matrix for proper display orientation
}

void loop() {
  // Check for IR input for entry
  if (irrecv.decode(&results)) {
    long int decCode = results.value;
    Serial.println(decCode);
    irrecv.resume();  // Receive the next value

    // If the entry sensor detects a signal
    if (decCode == 1234) {  // Example IR code for entry (you can customize this)
      openGate();
      displayWelcome();
      digitalWrite(LED_PIN_ENTRY, HIGH);  // Green LED for entry access
      delay(5000);  // Stay in the open position for 5 seconds (customize as needed)
      closeGate();
      digitalWrite(LED_PIN_ENTRY, LOW);   // Turn off entry LED
    }

    // If the exit sensor detects a signal
    if (decCode == 5678) {  // Example IR code for exit (you can customize this)
      openGate();
      displayThanks();
      digitalWrite(LED_PIN_EXIT, HIGH);  // Green LED for exit access
      delay(5000);  // Stay in the open position for 5 seconds (customize as needed)
      closeGate();
      digitalWrite(LED_PIN_EXIT, LOW);   // Turn off exit LED
    }
  }

  // Record and count visitors
  if (digitalRead(IR_PIN_IN) == HIGH) {
    visitorCount++;
    delay(2000);  // Delay to avoid multiple triggers from one person
  }

  if (digitalRead(IR_PIN_OUT) == HIGH) {
    visitorCount--;
    delay(2000);  // Delay to avoid multiple triggers from one person
  }

  // Display visitor count (Optional: Add this on the dot matrix or serial)
  Serial.print("Visitor Count: ");
  Serial.println(visitorCount);
}

void openGate() {
  gateMotor.write(90);  // Rotate the motor to open the gate
  Serial.println("Gate Opened");
}

void closeGate() {
  gateMotor.write(0);   // Rotate the motor to close the gate
  Serial.println("Gate Closed");
}

void displayWelcome() {
  matrix.clear();
  matrix.setCursor(0, 0);
  matrix.print("Welcome");
  matrix.writeDisplay();
}

void displayThanks() {
  matrix.clear();
  matrix.setCursor(0, 0);
  matrix.print("Thank you");
  matrix.setCursor(0, 8);
  matrix.print("for visiting");
  matrix.writeDisplay();
}
