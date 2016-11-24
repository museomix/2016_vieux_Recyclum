#include "FastLED.h"
#define NUM_LEDS 8
CRGB leds[NUM_LEDS];

int tessonAnalog = A0;
#define vitrineDigi 5
int buttonAnalog = A1;
int messageDigi = 6;
int trappeAnalog = A3;
int cpt = 0;
int blinkfreq = 200;
int freq = 100;
int token = 0;
 // VALEURS POSSIBLES DU TOKEN
 // 0 = toutes les LEDs éteintes et emplacement poterie vide (action suivante : scratcher le bout de poterie sur l'emplacement vide)
 // 1 = LED vitrine clignotante (action suivante : appuyer sur le bouton)
 // 2 = LED vitrine figée et LED trappe clignotante (action suivante : ouvrir la trappe)
 // 3 = toutes les LEDs éteintes mais bout de poterie toujours en place (action suivante : enlever le bout de poterie)

void setup() {
  pinMode(tessonAnalog, INPUT);
  pinMode(vitrineDigi, OUTPUT);
  pinMode(buttonAnalog, INPUT);
  pinMode(messageDigi, OUTPUT);
  pinMode(trappeAnalog, INPUT);
  FastLED.addLeds<NEOPIXEL, vitrineDigi>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop() {
  int value = 0;
  value = analogRead(trappeAnalog);
  Serial.println(value);
  switch(token) {
  case 0: // Si le tesson est en place, allumer la vitrine
    value = analogRead(tessonAnalog);
    //Serial.println(value);
    if(value > 1000) {
      for(int i = 0 ; i < NUM_LEDS ; i++)
        leds[i] = CRGB::White;
      FastLED.show();
      token++;
      cpt = 0;
    }
    break;
  case 1: // Si le bouton est pressé, allumer la trappe
    cpt++;
    value = analogRead(buttonAnalog);
    //Serial.println(cpt);
    if(value < 100) {
      digitalWrite(messageDigi, HIGH);
      token++;
      cpt = 0;
    } else if(cpt >= blinkfreq/freq && cpt < blinkfreq*2/freq) {
      for(int i = 0 ; i < NUM_LEDS ; i++)
        leds[i] = CRGB::Black;
      FastLED.show();
    } else if(cpt >= blinkfreq*2/freq ) {
      for(int i = 0 ; i < NUM_LEDS ; i++)
        leds[i] = CRGB::White;
      FastLED.show();
      cpt = 0;
    }
    break;
  case 2: // Si la trappe est ouverte, tout eteindre
    cpt++;
    value = analogRead(trappeAnalog);
    //Serial.println(value);
    if(value > 100) {
      for(int i = 0 ; i < NUM_LEDS ; i++)
        leds[i] = CRGB::Black;
      FastLED.show();
      digitalWrite(messageDigi, LOW);
      token++;
    } else if(cpt >= blinkfreq/freq && cpt < blinkfreq*2/freq ) {
      digitalWrite(messageDigi, LOW);
    } else if(cpt >= blinkfreq*2/freq ) {
      digitalWrite(messageDigi, HIGH);
      cpt = 0;
    }
    break;
  case 3: // Si le capteur de lumière est tjr recouvert, atteindre qu'il soit découvert
    value = analogRead(tessonAnalog);
    //Serial.println(value);
    if(value < 1000) {
      token = 0;
    }
    break;
  }
  // pause the program for X milliseconds to avoid energy consumption
  delay(freq);
}

