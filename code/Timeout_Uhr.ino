#include <Wire.h>
#include "Adafruit_MCP23017.h"
Adafruit_MCP23017 mcp;
void setup() {
  // put your setup code here, to run once:
  mcp.begin();      // use default address 0
  for (int i = 0; i < 16; i++) {
    mcp.pinMode(i, OUTPUT);
  }
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  start();
  if(!digitalRead(2)&&!digitalRead(3)){
    countdown120();  
  }
  
  if(!digitalRead(3)){
    countdown60();  
  }
  if(!digitalRead(2)){
    countdown300();    
  }

  delay(200);
  
}

void printEiner(int ziffer) {
  switch (ziffer) {
    case 0: {
        mcp.digitalWrite(0, HIGH);
        mcp.digitalWrite(1, HIGH);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, HIGH);
        mcp.digitalWrite(4, HIGH);
        mcp.digitalWrite(5, HIGH);
        mcp.digitalWrite(6, LOW);} break;
    case 1:{
        mcp.digitalWrite(0, LOW);
        mcp.digitalWrite(1, HIGH);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, LOW);
        mcp.digitalWrite(4, LOW);
        mcp.digitalWrite(5, LOW);
        mcp.digitalWrite(6, LOW);} break;
    case 2:{
        mcp.digitalWrite(0, HIGH);
        mcp.digitalWrite(1, HIGH);
        mcp.digitalWrite(2, LOW);
        mcp.digitalWrite(3, HIGH);
        mcp.digitalWrite(4, HIGH);
        mcp.digitalWrite(5, LOW);
        mcp.digitalWrite(6, HIGH);} break;
    case 3:{
        mcp.digitalWrite(0, HIGH);
        mcp.digitalWrite(1, HIGH);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, HIGH);
        mcp.digitalWrite(4, LOW);
        mcp.digitalWrite(5, LOW);
        mcp.digitalWrite(6, HIGH);} break;
    case 4:{
        mcp.digitalWrite(0, LOW);
        mcp.digitalWrite(1, HIGH);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, LOW);
        mcp.digitalWrite(4, LOW);
        mcp.digitalWrite(5, HIGH);
        mcp.digitalWrite(6, HIGH);} break;
    case 5:{
        mcp.digitalWrite(0, HIGH);
        mcp.digitalWrite(1, LOW);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, HIGH);
        mcp.digitalWrite(4, LOW);
        mcp.digitalWrite(5, HIGH);
        mcp.digitalWrite(6, HIGH);} break;
    case 6:{
        mcp.digitalWrite(0, HIGH);
        mcp.digitalWrite(1, LOW);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, HIGH);
        mcp.digitalWrite(4, HIGH);
        mcp.digitalWrite(5, HIGH);
        mcp.digitalWrite(6, HIGH);} break;
    case 7:{
        mcp.digitalWrite(0, HIGH);
        mcp.digitalWrite(1, HIGH);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, LOW);
        mcp.digitalWrite(4, LOW);
        mcp.digitalWrite(5, LOW);
        mcp.digitalWrite(6, LOW);} break;
    case 8:{
        mcp.digitalWrite(0, HIGH);
        mcp.digitalWrite(1, HIGH);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, HIGH);
        mcp.digitalWrite(4, HIGH);
        mcp.digitalWrite(5, HIGH);
        mcp.digitalWrite(6, HIGH);} break;
    case 9:{
        mcp.digitalWrite(0, HIGH);
        mcp.digitalWrite(1, HIGH);
        mcp.digitalWrite(2, HIGH);
        mcp.digitalWrite(3, HIGH);
        mcp.digitalWrite(4, LOW);
        mcp.digitalWrite(5, HIGH);
        mcp.digitalWrite(6, HIGH);} break;
    }
}

void printZehner(int ziffer) {
  switch (ziffer) {
    case 0: {
        mcp.digitalWrite(8, HIGH);
        mcp.digitalWrite(9, HIGH);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, HIGH);
        mcp.digitalWrite(12, HIGH);
        mcp.digitalWrite(13, HIGH);
        mcp.digitalWrite(14, LOW);} break;
    case 1:{
        mcp.digitalWrite(8, LOW);
        mcp.digitalWrite(9, HIGH);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, LOW);
        mcp.digitalWrite(12, LOW);
        mcp.digitalWrite(13, LOW);
        mcp.digitalWrite(14, LOW);} break;
    case 2:{
        mcp.digitalWrite(8, HIGH);
        mcp.digitalWrite(9, HIGH);
        mcp.digitalWrite(10, LOW);
        mcp.digitalWrite(11, HIGH);
        mcp.digitalWrite(12, HIGH);
        mcp.digitalWrite(13, LOW);
        mcp.digitalWrite(14, HIGH);} break;
    case 3:{
        mcp.digitalWrite(8, HIGH);
        mcp.digitalWrite(9, HIGH);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, HIGH);
        mcp.digitalWrite(12, LOW);
        mcp.digitalWrite(13, LOW);
        mcp.digitalWrite(14, HIGH);} break;
    case 4:{
        mcp.digitalWrite(8, LOW);
        mcp.digitalWrite(9, HIGH);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, LOW);
        mcp.digitalWrite(12, LOW);
        mcp.digitalWrite(13, HIGH);
        mcp.digitalWrite(14, HIGH);} break;
    case 5:{
        mcp.digitalWrite(8, HIGH);
        mcp.digitalWrite(9, LOW);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, HIGH);
        mcp.digitalWrite(12, LOW);
        mcp.digitalWrite(13, HIGH);
        mcp.digitalWrite(14, HIGH);} break;
    case 6:{
        mcp.digitalWrite(8, HIGH);
        mcp.digitalWrite(9, LOW);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, HIGH);
        mcp.digitalWrite(12, HIGH);
        mcp.digitalWrite(13, HIGH);
        mcp.digitalWrite(14, HIGH);} break;
    case 7:{
        mcp.digitalWrite(8, HIGH);
        mcp.digitalWrite(9, HIGH);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, LOW);
        mcp.digitalWrite(12, LOW);
        mcp.digitalWrite(13, LOW);
        mcp.digitalWrite(14, LOW);} break;
    case 8:{
        mcp.digitalWrite(8, HIGH);
        mcp.digitalWrite(9, HIGH);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, HIGH);
        mcp.digitalWrite(12, HIGH);
        mcp.digitalWrite(13, HIGH);
        mcp.digitalWrite(14, HIGH);} break;
    case 9:{
        mcp.digitalWrite(8, HIGH);
        mcp.digitalWrite(9, HIGH);
        mcp.digitalWrite(10, HIGH);
        mcp.digitalWrite(11, HIGH);
        mcp.digitalWrite(12, LOW);
        mcp.digitalWrite(13, HIGH);
        mcp.digitalWrite(14, HIGH);} break;
  }
}

void countdown60(){
  int zeit = 60;
  for(int i = zeit; i>=0;i--){
    int zehner = i/10;
    int einer = i%10;
    Serial.print(zehner);
    Serial.print(einer);
    printZehner(zehner);
    printEiner(einer);  
    delay(1000);
  }  
  
}
void countdown300(){
  int zeit = 300;
  
  for(int minuten = 5; minuten>0;minuten--){
    printZehner(0);
    for(int i = 0; i <3;i++){
      printEiner(minuten);
      delay(500);
      printEiner(0);
      delay(500);
    }
    int zeit = 60;
    for(int i = zeit; i>=0;i--){
      int zehner = i/10;
      int einer = i%10;
      Serial.print(zehner);
      Serial.print(einer);
      printZehner(zehner);
      printEiner(einer);  
      delay(1000);
    }  
  }
}

void countdown120(){
  int zeit = 120;
  
  for(int minuten = 2; minuten>0;minuten--){
    printZehner(0);
    for(int i = 0; i <3;i++){
      printEiner(minuten);
      delay(500);
      printEiner(0);
      delay(500);
    }
    int zeit = 60;
    for(int i = zeit; i>=0;i--){
      int zehner = i/10;
      int einer = i%10;
      Serial.print(zehner);
      Serial.print(einer);
      printZehner(zehner);
      printEiner(einer);  
      delay(1000);
    }  
  }
}

void start(){
  printZehner(0);
  printEiner(0);  
}
