// Define the analog pin connected to the LM35 sensor
const int lm35Pin = A0;
// Define the onboard LED pin
const int ledPin = 13;
void setup() {
 // Set the LED pin as an output
 pinMode(ledPin, OUTPUT);
 // Begin serial communication at 9600 baud rate
 Serial.begin(9600);
}
void loop() {
 // Read the analog value from the LM35 sensor
 int sensorValue = analogRead(lm35Pin);
 // Convert the analog value to voltage (0 to 5V)
 float voltage = sensorValue * (5.0 / 1023.0);
 // Convert voltage to temperature in Celsius (10 mV per degree with LM35)
 float temperatureC = voltage * 100;
 // Print temperature to serial monitor
 Serial.print("Temperature: ");
 Serial.print(temperatureC);
 Serial.println(" °C");
 // Check if temperature falls below 30 degrees Celsius
 if (temperatureC < 30) {
 // Blink the LED every 250 milliseconds
 digitalWrite(ledPin, HIGH);
 delay(250);
 digitalWrite(ledPin, LOW);
 delay(250);
 }
 // Check if temperature rises above 30 degrees Celsius
 else if (temperatureC > 30) {
 // Blink the LED every 500 milliseconds
 digitalWrite(ledPin, HIGH);
 delay(500);
 digitalWrite(ledPin, LOW);
 delay(500);
 }
}
// delay function
void delay(int milliseconds) {
 for (int i = 0; i < milliseconds; i++) {
 // Loop until the desired delay is reached
 for (volatile int j = 0; j < 1000; j++) {
 // This inner loop creates a delay of approximately 1 millisecond
 // The 'volatile' keyword is used to prevent the compiler from optimizing the loop
away
 }
 } }