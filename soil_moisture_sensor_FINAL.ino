#define soilWet 450   // Define max value we consider soil 'wet'
#define soilDry 650   // Define min value we consider soil 'dry'
#define sensorPower 7
#define sensorPin A0

void setup() {
    pinMode(sensorPower, OUTPUT);
    digitalWrite(sensorPower, LOW);
    Serial.begin(9600);
}

void loop() {
    int moisture = readSensor();
    Serial.print("Analog Output: ");
    Serial.println(moisture);

    if (moisture < soilWet) {
        Serial.println("Status: Soil is too wet");
    } else if (moisture >= soilWet && moisture < soilDry) {
        Serial.println("Status: Soil moisture is perfect, no need to water!");
    } else {
        Serial.println("Status: Soil is too dry - time to water!");
    }
    delay(1000);
    Serial.println();
}

int readSensor() {
    digitalWrite(sensorPower, HIGH);
    delay(10);                            
    int val = analogRead(sensorPin);    
    digitalWrite(sensorPower, LOW);        
    return val;     

    delay(5000);                       
}