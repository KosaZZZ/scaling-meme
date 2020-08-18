#include <FastLED.h>
FASTLED_USING_NAMESPACE

#define DATA_PIN            3
#define NUM_LEDS            60
#define LED_TYPE            WS2812B
#define COLOR_ORDER         GRB
#define BRIGHTNESS          255
#define TEXTONSERIALSTART   "serialOk"
void NewRainbow();
void RedBlue();
void Rainbow2();
void Solid();
//int Done = 0; //to później zmienić
int mode;
int red;
int green;
int blue;
int HUE;
int p = 1;
int i;
int serialread;
int done = 1;
int r;
int g;
int b;
//////////////////////////////////////////////////////////////////////////

CRGB leds[NUM_LEDS];
void setup() {
  // put your setup code here, to run once:
    FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
        .setCorrection( TypicalLEDStrip )
        .setDither(BRIGHTNESS < 255);
   Serial.begin(9600);
   delay(10);
   Serial.write(TEXTONSERIALSTART);

}

 void loop() {
     // if (Serial.available() > 0){ 
     // char a = Serial.read();
     // if (a = "1") {Serial.print(a);}
     // if (serialread == 1 || serialread == 2) {
      //  mode = serialread;
      //}
      //}
   
   
  // put your main code here, to run repeatedly:
  //if (Serial.available() > 0) {
   // tryb = Serial.read();
   // Serial.write(tryb);
//}
//tryb=1;
//  if (tryb == 1){
//    if (Done == 0){
//      rainbow();
//      }
// for (int i = 0; i >= 0; i++){
//  int led = 255/NUM_LEDS*i;
//  leds[i] = CHSV(led[i]++, 255, 255);
//    FastLED.show();
//     delay(50);
//
//    }
//    }

if (mode == 1) {
NewRainbow();
}

if (mode == 2){
  fill_solid( leds, NUM_LEDS, CRGB(50, 0, 200));
    FastLED.show();
  
 }  
if (mode == 3){
  fill_solid( leds, NUM_LEDS, CRGB(0, 0, 0));
    FastLED.show();

}
if (mode == 4) {
RedBlue();
}

if (mode == 5) {
Rainbow2();
}
//if (mode == 6) {
//Solid();
//}
}   

//void rainbow() {
//  
//     for (int i = 0; i <= NUM_LEDS; i++){
//      
//         int led = 255/NUM_LEDS*i;
//         leds[i] = CHSV(led, 255, 100);
//         Done = 1;
//     }
     
void serialEvent() {
   while (Serial.available() > 0) {
     mode = Serial.parseInt();
     Serial.print(mode);
     while(Serial.available())    
     Serial.read();               // Clearing serial buffer
     
     if (mode == 6) {
      Serial.read();
      while(Serial.available() <= 0) {}
      r = Serial.parseInt();
      Serial.write("A");
      
      Serial.read();
      while(Serial.available() <= 0) {}
      g = Serial.parseInt();
      Serial.write("B");
      
      Serial.read();
      while(Serial.available() <= 0) {}
      b = Serial.parseInt();
      Serial.write("C"); 
      
      Solid(); 
     
     }
  } 
}
void NewRainbow() {
    for (i = 0; i < 60; i++) {
            delay(15);
      //if (Serial.available() > 0) {
        //serialread = Serial.read();
       // if (serialread == 1 || serialread == 2) {
        //mode = serialread;
       // }
      //}
     // if (mode != 1) {
      //  break;
     // }
      HUE = 255/60*g;
      g++;
      leds[i] = CHSV(HUE, 255, 255);
      FastLED.show();  
    }
     
    p = p + 10;
  
  }     

void RedBlue() {
  int delaytime = 250;
  int half = NUM_LEDS/2;
  for(i = 0; i<half; i++) {
    leds[i] = CRGB::Blue;
  }
  for(i = half; i<NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  //fill_solid(leds, half, CRGB::Red);
  FastLED.show();
  delay(delaytime);
  for(i = 0; i<half; i++) {
    leds[i] = CRGB::Black;
  }
  for(i = half; i<NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }
  //fill_solid(leds, half, CRGB::Red);
  FastLED.show();
  delay(delaytime);
}
void Rainbow2() {
    for (i = 0; i < 60; i++) {
           // delay(1);
      //if (Serial.available() > 0) {
        //serialread = Serial.read();
       // if (serialread == 1 || serialread == 2) {
        //mode = serialread;
       // }
      //}
     // if (mode != 1) {
      //  break;
     // }
      HUE = 255/60*g;
      g++;
      leds[i] = CHSV(HUE, 255, 255);  
      //FastLED.show();     
    }
    FastLED.show();
    delay(100);
     
    p = p + 10;
  
  }     
void Solid() {
 /* while (Serial.available() > 0) {
  red = Serial.parseInt();
    while(Serial.available()) 
  Serial.read();
  green = Serial.parseInt();
    while(Serial.available()) 
  Serial.read();
  blue = Serial.parseInt();
  while(Serial.available()) 
  Serial.read();
}*/

  for (i = 0; i < NUM_LEDS; i++) {
    leds[i].r = r;
    leds[i].g = g;
    leds[i].b = b;
    FastLED.show();
    delay(15);
  }
  done = 1;
}
      


 
