
#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 3

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    long duration;
    int distance;
    
    // Ultrahangos impulzus küldése
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    // Visszaverődött impulzus mérési ideje
    duration = pulseIn(ECHO_PIN, HIGH);
    
    // Távolság számítása (hangsebesség: 343 m/s)
    distance = duration * 0.034 / 2;
    
    Serial.print("Távolság: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Ha a tárgy 20 cm-nél közelebb van, kapcsolja be a LED-et
    if (distance < 20) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    delay(500);
}
