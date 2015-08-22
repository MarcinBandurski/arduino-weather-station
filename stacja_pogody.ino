 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //piny w arduino - LCD

#include "DHT.h" 
#define DHTPIN 6 //pin w arduino dla DHT11
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 
 

void setup() {
  Serial.begin(9600); //inicjalizacja komunikacji szeregowej
dht.begin(); //inicjalizacja sensora DHT11
  
}
void loop() {
  
 int h = dht.readHumidity(); //odczyt wilgotnosci
 int t = dht.readTemperature(); // odczyt temperatury
      
  // wyswietlanie na LCD
  lcd.begin(16, 2);
  //linia 1 
  if(t <=19){
  lcd.print("Zimno ");
   }else if((t >=20) && (t <=24)){
  lcd.print("Pokojowa ");
   }else if ((t >=25) && (t <=27)){
  lcd.print("Cieplo");
  }else if (t >=28){
  lcd.print("Goraco");
  }
  //lcd.print("Pogoda ");
  
  lcd.setCursor(9, 0);
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("/");
  lcd.print(h);
  lcd.print("%");
  
  //linia2
  lcd.setCursor(0, 1);
  
//  if(t <19){
//    lcd.print("B.zimno ");
//  }elseq if((t >=20) && (t <=24)){
//    lcd.print("Zimno ");
//  }else if ((t >=25) && (t <=27)){
//    lcd.print("Przymr.");
//  }else if ((t >=25) && (t <=27)){
//    lcd.print("Chlod");
//  }else if ((t >=25) && (t <=27)){
//    lcd.print("Przymr.");
//  }

//i inne temp do  t>30
  
  lcd.setCursor(9, 1);
  lcd.print("--");
  lcd.print((char)223);
  lcd.print("/--");
  lcd.print("%");
 
  delay(10000); //odczyt co 10 sekund
 
}
