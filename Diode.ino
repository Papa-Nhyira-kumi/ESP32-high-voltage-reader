// Define GPIO pin connected to voltage divider
const int signalPin = 34; // Must be an ADC-capable pin
const float voltageThreshold = 1.0; // "Safe" voltage threshold in volts

// Calibration values
const float maxADC = 4095.0;
const float vRef = 3.3; // ADC reference voltage

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // 12-bit ADC
}

void loop() {
  int adcValue = analogRead(signalPin);
  float voltage = (adcValue / maxADC) * vRef;

  Serial.print("Voltage: ");
  Serial.print(voltage, 2);
  Serial.println(" V");

  if (voltage < voltageThreshold) {
    Serial.println("⚠️ Signal is SAFE!");
  } else {
    Serial.println("🚨 Signal is HIGH!");
  }

  delay(500); // Check every 0.5s
}
