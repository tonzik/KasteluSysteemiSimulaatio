#include <LiquidCrystal.h>

// Setting the LCD shields pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

long moistureValue1;
long moistureValue2;
long moistureValue3;
long moistureValue4;

// declare moisture values
int moisture1_value = 1023;
int moisture2_value = 100;
int moisture3_value = 0;
int moisture4_value = 0;

int percentValue1 = 0;
int percentValue2 = 0;
int percentValue3 = 0;
int percentValue4 = 0;

// kukkanenTila = 0 | Kukka on kylläinen
// kukkanenTila = 1 | Kukka on janoinen
int kukkanen1Tila = 0;
int kukkanen2Tila = 0;
int kukkanen3Tila = 0;
int kukkanen4Tila = 0;

// pumppuTila = 0 | Pumppu ei ole päällä
// pumppuTila = 1 | Pumppu on päällä
int pumppuTila = 0;

// venttiiliReleTila = 0 | Venttiili on suljettu
// venttiiliReleTila = 1 | Venttiili on auki
int venttiiliReleTila1 = 0;
int venttiiliReleTila2 = 0;
int venttiiliReleTila3 = 0;
int venttiiliReleTila4 = 0;

int looppiViive = 5000;
int kasteluAika = 5000;

void setup() {
  randomSeed(analogRead(0));
  lcd.begin(16, 2);
  Serial.begin(9600);
  tervehdysViesti();
}

void tervehdysViesti() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello beautiful!");
  Serial.println("Hello beautiful!");
  Serial.print("Simuloitu kastelujärjestelmä käynnistyy");
  delay(1000);
  lcd.setCursor(3,1);
  lcd.print(".:: 3 ::.");
  Serial.print(" 3");
  delay(1000);
  lcd.setCursor(3,1);
  lcd.print(".:: 2 ::.");
  Serial.print(", 2");
  delay(1000);
  lcd.setCursor(3,1);
  lcd.print(".:: 1 ::.");
  Serial.println(", 1");
  delay(1000);
  Serial.println(" ");
}

void lueAnturit() {
  // Kosteusarvojen lukeminen antureista ja 
  // arvojen muuttaminen prosenteiksi
  moistureValue1 = random(0, 1024);
  percentValue1 = (moistureValue1)*100L/(1023);

  moistureValue2 = random(0, 1024);
  percentValue2 = (moistureValue2)*100L/(1023);

  moistureValue3 = random(0, 1024);
  percentValue3 = (moistureValue3)*100L/(1023);

  moistureValue4 = random(0, 1024);
  percentValue4 = (moistureValue4)*100L/(1023);

  // Kosteusanturi 1
  if(moistureValue1<=450) {
    kukkanen1Tila = 1;
  }else{
    kukkanen1Tila = 0;
  }

  // Kosteusanturi 2
  if(moistureValue2<=450) {
    kukkanen2Tila = 1;
  }else{
    kukkanen2Tila = 0;
  }

  // Kosteusanturi 3
  if(moistureValue3<=450) {
    kukkanen3Tila = 1;
  }else{
    kukkanen3Tila = 0;
  }

  // Kosteusanturi 4
  if(moistureValue4<=450) {
    kukkanen4Tila = 1;
  }else{
    kukkanen4Tila = 0;
  }
}

void kukatTarkistus() {
  lcd.clear();

  lueAnturit();

  Serial.println("=====================================================/");

  // Anturi 1 / Kukka 1
  lcd.setCursor(0,0);
  lcd.print("K1");
  lcd.setCursor(4,0);
  lcd.print(percentValue1);
  lcd.print("%");
  Serial.print("Anturi 1: ");
  Serial.print(moistureValue1);
  Serial.print(" / ");
  Serial.print(percentValue1);
    if (kukkanen1Tila == 1) {
      venttiiliReleTila1 = 1;
      lcd.setCursor(2,0);
      lcd.print("!");
      Serial.print("%");
      Serial.print(" | Apuva, vettä!!! | Rele: ");
      Serial.println(venttiiliReleTila1);
    }else{
      venttiiliReleTila1 = 0;
      Serial.print("%");
      Serial.print(" | Rele: ");
      Serial.println(venttiiliReleTila1);
    }

  // Anturi 2 / Kukka 2
  lcd.setCursor(8,0);
  lcd.print("K2");
  lcd.setCursor(12,0);
  lcd.print(percentValue2);
  lcd.print("%");
  Serial.print("Anturi 2: ");
  Serial.print(moistureValue2);
  Serial.print(" / ");
  Serial.print(percentValue2);
    if (kukkanen2Tila == 1) {
      venttiiliReleTila2 = 1;
      lcd.setCursor(10,0);
      lcd.print("!");
      Serial.print("%");
      Serial.print(" | Apuva, vettä!!! | Rele: ");
      Serial.println(venttiiliReleTila2);
    }else{
      venttiiliReleTila2 = 0;
      Serial.print("%");
      Serial.print(" | Rele: ");
      Serial.println(venttiiliReleTila2);
    }

  // Anturi 3 / Kukka 3
  lcd.setCursor(0,1);
  lcd.print("K3");
  lcd.setCursor(4,1);
  lcd.print(percentValue3);
  lcd.print("%");
  Serial.print("Anturi 3: ");
  Serial.print(moistureValue3);
  Serial.print(" / ");
  Serial.print(percentValue3);
    if (kukkanen3Tila == 1) {
      venttiiliReleTila3 = 1;
      lcd.setCursor(2,1);
      lcd.print("!");
      Serial.print("%");
      Serial.print(" | Apuva, vettä!!! | Rele: ");
      Serial.println(venttiiliReleTila3);
    }else{
      venttiiliReleTila3 = 0;
      Serial.print("%");
      Serial.print(" | Rele: ");
      Serial.println(venttiiliReleTila3);
    }

  // Anturi 4 / Kukka 4
  lcd.setCursor(8,1);
  lcd.print("K4");
  lcd.setCursor(12,1);
  lcd.print(percentValue4);
  lcd.print("%");
  Serial.print("Anturi 4: ");
  Serial.print(moistureValue4);
  Serial.print(" / ");
  Serial.print(percentValue4);
    if (kukkanen4Tila == 1) {
      venttiiliReleTila4 = 1;
      lcd.setCursor(10,1);
      lcd.print("!");
      Serial.print("%");
      Serial.print(" | Apuva, vettä!!! | Rele: ");
      Serial.println(venttiiliReleTila4);
      Serial.println(" ");
    }else{
      venttiiliReleTila4 = 0;
      Serial.print("%");
      Serial.print(" | Rele: ");
      Serial.println(venttiiliReleTila4);
      Serial.println(" ");
    }

  if (kukkanen1Tila == 1 || kukkanen2Tila == 1 || kukkanen3Tila == 1 || kukkanen4Tila == 1) {
    pumppuTila = 1;
    Serial.println("Joku kukkanen tarttis vettä...");
    //Serial.println(" ");
    kasteleKukat();
  }else{
    pumppuTila = 0;
    Serial.print("Pumppu: ");
    Serial.println(pumppuTila);
    Serial.println(" ");
  }
}

void kasteleKukat() {
  if (pumppuTila == 1) {
    Serial.print("Laitetaan pumppu päälle | pumppu: ");
    Serial.println(pumppuTila);
    Serial.println(" ");
  }

  // Tähän lisätään koodi pumpulle kun se avataan, esim. digitalWrite(pump, HIGH);

  Serial.println("Nyt kastellaan...");
  Serial.println(" ");
  
  delay(kasteluAika);

  // Tähän lisätään koodi pumpulle kun se suljetaan, esim. digitalWrite(pump, LOW);

  if (pumppuTila == 1) {
    pumppuTila = 0;
    Serial.print("Laitetaan pumppu kiinni | pumppu: ");
    Serial.println(pumppuTila);
    //Serial.println(" ");
  }

  if (venttiiliReleTila1 == 1) {
    Serial.println("Venttiili 1 suljetaan");
    //Serial.println(" ");
  }

  if (venttiiliReleTila2 == 1) {
    Serial.println("Venttiili 2 suljetaan");
    //Serial.println(" ");
  }

  if (venttiiliReleTila3 == 1) {
    Serial.println("Venttiili 3 suljetaan");
    //Serial.println(" ");
  }

  if (venttiiliReleTila4 == 1) {
    Serial.println("Venttiili 4 suljetaan");
    //Serial.println(" ");
  }
  


  // Tähän lisätään koodi releille kun ne kastelun jälkeen suljetaan, esim:
  // digitalWrite(relay1, LOW);
  // digitalWrite(relay2, LOW);
  // digitalWrite(relay3, LOW);
  // digitalWrite(relay4, LOW);
}

void loop() {
  kukatTarkistus();
  delay(looppiViive);
}
