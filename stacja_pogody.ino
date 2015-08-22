 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //piny w arduino - LCD

#include "DHT.h" 
//#define DHTPIN 6 //pin w arduino dla DHT11
//#define DHTTYPE DHT11 
//DHT dht(DHTPIN, DHTTYPE); 
 
#define DHT1PIN 6 
#define DHT2PIN 7   
#define DHT1TYPE DHT11 
#define DHT2TYPE DHT22  
 
DHT dht1(DHT1PIN, DHT1TYPE); 
DHT dht2(DHT2PIN, DHT2TYPE); 

void setup() {
  Serial.begin(9600); //inicjalizacja komunikacji szeregowej
//dht.begin(); //inicjalizacja sensora DHT11
dht1.begin(); //inicjalizacja sensora DHT11
dht2.begin(); //inicjalizacja sensora DHT22
  
}
void loop() {
  
 int h1 = dht1.readHumidity(); //odczyt wilgotnosci
 int t1 = dht1.readTemperature(); // odczyt temperatury
 
 int h2 = dht2.readHumidity(); //odczyt wilgotnosci
 int t2 = dht2.readTemperature(); // odczyt temperatury
      
  // wyswietlanie na LCD
  lcd.begin(16, 2);
  //linia 1 
  if(t1 <=19){
  lcd.print("Zimno ");
   }else if((t1 >=20) && (t1 <=24)){
  lcd.print("Pokojowa ");
   }else if ((t1 >=25) && (t1 <=27)){
  lcd.print("Cieplo");
  }else if (t1 >=28){
  lcd.print("Goraco");
  }
  //lcd.print("Pogoda ");
  
  lcd.setCursor(9, 0);
  lcd.print(t1);
  lcd.print((char)223);
  lcd.print("/");
  lcd.print(h1);
  lcd.print("%");
  
  //linia2
  lcd.setCursor(0, 1);
  
 if(t2 <19){
   lcd.print("B.zimno ");
 }else if((t2 >=20) && (t2 <=24)){
   lcd.print("Zimno ");
 }else if ((t2 >=25) && (t2 <=27)){
   lcd.print("Przymr.");
 }else if ((t2 >=25) && (t2 <=27)){
   lcd.print("Chlod");
 }else if ((t2 >=25) && (t2 <=27)){
   lcd.print("Przymr.");
 }

//i inne temp do  t>30
  
  lcd.setCursor(9, 1);
  lcd.print(t2);
  lcd.print((char)223);
  lcd.print(h2);
  lcd.print("%");
 
  delay(10000); //odczyt co 10 sekund
 
}
