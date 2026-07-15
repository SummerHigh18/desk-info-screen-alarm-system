# include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
unsigned long previousBlink = 0;
unsigned long previousDHT = 0;
bool ledState = false;


int thePin = 25;
int theStatus = 0;

void setup() {
  Serial.begin(115200);

  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Some display issue vro, check things once again!"));
    for(;;);
  }

  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);

  pinMode(18, OUTPUT);
  digitalWrite(18, LOW);

  pinMode(thePin, INPUT);
  digitalWrite(thePin, LOW);
}


void loop() {
  theStatus = digitalRead(thePin);

  // if (theStatus == LOW) { // it is set to low coz the sensor isn't behaving properly I presume and simulating motion all the time...
  //   Serial.println("yay!");
  //   display.clearDisplay();

  //   display.setTextSize(1);
  //   display.setCursor(0, 0);

  //   display.print("yo yo, mom is cominggg!! tidy the room asap");
  //   display.display();
  // }
  // unfortunately this thing ain't working properly on the simulator, so I have commented out as for now.

  float temp = dht.readTemperature();
    
  if (millis() - previousDHT >= 2000) {
    previousDHT = millis();
    float humidity = dht.readHumidity();

    if (isnan(temp) || isnan(humidity)) {
      Serial.println("Better check the sensor...");
      return;
    }

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(0, 0);

    display.print("Temp: ");
    display.print(temp);
    display.println(" C");

    display.print("Humidity: ");
    display.print(humidity);
    display.println(" %");

    display.display();
  }



  
  if (temp >= 50) {
    if (millis() - previousBlink >= 500) {
      previousBlink = millis();

      ledState = !ledState;
      digitalWrite(18, ledState);

    }
    display.clearDisplay();
    display.setTextSize(1.5);
    display.setCursor(0, 0);

    display.println("I guess you should    run...");
    display.display();
  }
}