#include <ResponsiveAnalogRead.h>
const int ANALOG_PIN = A0;
ResponsiveAnalogRead analog(ANALOG_PIN, true);


int pixeller[8];
int gecikme = 5;
int noise = 0;
// çoklayıcı 1
int latchPin1 = 5;
int clockPin1 = 6;
int dataPin1 = 4;
byte leds1 = 0;
// çoklayıcı 2
int latchPin2 = 9;
int clockPin2 = 10;
int dataPin2 = 8;
byte leds2 = 0;
// çoklayıcı 3
int latchPin3 = 13;
int clockPin3 = 12;
int dataPin3 = 11;
byte leds_Yan = 0;

int dizi_NoIR[8];

int dizi_NoIR2[8];

void setup() {

  Serial.begin(9600);
  //  çoklayıcı 1
  pinMode(latchPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);
  //   çoklayıcı 2
  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  //   çoklayıcı 3

  pinMode(latchPin3, OUTPUT);
  pinMode(dataPin3, OUTPUT);
  pinMode(clockPin3, OUTPUT);
  //check_noise();
 //ayarla();
}
void ayarla() {
  leds_Yan = 0;
  leds2 = 0;

  son_led_off1();
  son_led_off3();
  son_led_off2();
 
  int i = 0;
  while (i < 8) {
    bitWrite(leds_Yan, i, HIGH);
    digitalWrite(latchPin3, LOW);
    shiftOut(dataPin3, clockPin3, MSBFIRST, leds_Yan); //diğer taraftan başlaması için LSBFIRST kullanabiliriz
    digitalWrite(latchPin3, HIGH);
    Serial.print(i);
    Serial.println(" 'yi engelle !");
    if (Serial.available() > 0) {
      int val = Serial.parseInt(); //read int or parseFloat for ..float...
      Serial.println(val);
      if (val == i) {
        analog.update();
        analog.setSnapMultiplier(0.001);
        dizi_NoIR[i] = analog.getValue();
        Serial.println("Tamam");
        i++;
         
        son_led_off3();
    leds_Yan = 0;
      }

    }

  }


}
int fark = 00;

void loop() {
  if (Serial.available() > 0) {
    fark = Serial.parseInt(); //read int or parseFloat for ..float...
    //Serial.println(val);
  }
  harita_sifirla();
  leds1 = 0;
  leds2 = 0;
  leds_Yan = 0;
  son_led_off1();
  son_led_off2();
  int gecici = 0;

  for (int j = 0; j < 8; j++)
  {
    bitWrite(leds_Yan, j, HIGH);
    digitalWrite(latchPin3, LOW);
    shiftOut(dataPin3, clockPin3, MSBFIRST, leds_Yan); //diğer taraftan başlaması için LSBFIRST kullanabiliriz
    digitalWrite(latchPin3, HIGH);
    delay(gecikme);
    analog.update();
    analog.setSnapMultiplier(0.1);
    int x = analog.getValue();
    Serial.print(x );
    Serial.print(" ");
//    if (j == 0) {
//      if ( x > dizi_NoIR[j] - 50) {
//        pixeller[j] = 1;
//      }
//    }
//    if (j == 1) {
//      if ( x > dizi_NoIR[j] - 90) {
//        pixeller[j] = 1;
//      }
//    }
//    if (j == 2) {
//      if ( x > dizi_NoIR[j] - 35 - fark) {
//        pixeller[j] = 1;
//      }
//    }
//    if (j == 3) {
//      if ( x > dizi_NoIR[j] - 55 - fark) {
//        pixeller[j] = 1;
//      }
//    }
//    if (j == 4) {
//      if ( x > dizi_NoIR[j] - 75 - fark) {
//        pixeller[j] = 1;
//      }
//    }
//    if (j == 5) {
//      if ( x > dizi_NoIR[j] - 65 - fark) {
//        pixeller[j] = 1;
//      }
//    }
//    if (j == 6) {
//      if ( x > dizi_NoIR[j] - 10 - fark) {
//        pixeller[j] = 1;
//      }
//    }
//    if (j == 7) {
//      if ( x > dizi_NoIR[j] - 75 - fark) {
//        pixeller[j] = 1;
//      }
//    }

/**
     if (j == 0) {
      if ( x > 600 && x < 720) {
        pixeller[j] = 1;
      }

      }
      if (j == 1) {
      if ( x > 580) {
        pixeller[j] = 1;
        // pixeller[0]=0;
      }
      if ( x > 635 && gecici > 710) {
        pixeller[j] = 1;
        pixeller[j - 1] = 1;
      }
      }
      if (j == 2) {
      if ( x > 520) {
        pixeller[j] = 1;
        //pixeller[0]=0;
        //pixeller[1]=0;
      }
      }
      if (j == 3) {
      if ( x > 430) {
        pixeller[j] = 1;
      }
      }
      if (j == 4) {
      if ( x > 600) {
        pixeller[j] = 1;
      }
      }
      if (j == 5) {
      if ( x > 600) {
        pixeller[j] = 1;

      }
      }
      if (j == 6 ) {
      if ( x > 685) {
        pixeller[j] = 1;

      }
      }
      if (j == 7 ) {
      if ( x > 750) {
        pixeller[j] = 1;

      }
      }
   **/
    // akşam
    /** if (j == 0) {
       if ( x > 800 && x<870){
         pixeller[j]=1;
       }

      }
      if (j == 1) {
       if ( x > 760){
         pixeller[j]=1;
       // pixeller[0]=0;
       }
       if ( x > 840 && gecici > 890){
         pixeller[j]=1;
         pixeller[j-1]=1;
       }
      }
      if (j == 2) {
       if ( x > 710){
         pixeller[j]=1;
           //pixeller[0]=0;
           //pixeller[1]=0;
       }
      }
      if (j == 3) {
       if ( x > 600){
         pixeller[j]=1;
       }
      }
      if (j == 4) {
       if ( x > 730){
         pixeller[j]=1;
       }
      }
      if (j == 5) {
       if ( x > 750){
         pixeller[j]=1;

       }
      }
      if (j == 6 ) {
       if ( x > 840){
         pixeller[j]=1;

       }
      }
      if (j == 7 ) {
       if ( x > 920){
         pixeller[j]=1;

       }
      }
    **/
    // öğleden sonra
   
         if (j == 0) {
          if ( x > 710){
            pixeller[3]=1;
          }
        }
        if (j == 1) {
          if ( x > 410){
            pixeller[2]=1;
            pixeller[0]=0;
          }
        }
        if (j == 2) {
          if ( x > 620){
            pixeller[1]=1;
            // pixeller[0]=0;
             //  pixeller[1]=0;
          }
        }
        if (j == 3) {
          if ( x > 520){
            pixeller[0]=1;
          }
        }
//        if (j == 4) {
//          if ( x > 730){
//            pixeller[j]=1;
//          }
//        }
//        if (j == 5) {
//          if ( x > 750){
//            pixeller[j]=1;
//
//          }
//        }
//        if (j == 6 ) {
//          if ( x > 840){
//            pixeller[j]=1;
//
//          }
//        }
//        if (j == 7 ) {
//          if ( x > 910){
//            pixeller[j]=1;
//
//          }
//        }

         
    son_led_off3();
    leds_Yan = 0;

  }
  Serial.println();
   //yazdir();
   //   yazdir_new();
  /**    for (int i = 1; i < 8; i++) // --------------Birinci Mutltiplixer --------------------------------------------
       {
         bitWrite(leds1,i,HIGH);
          digitalWrite(latchPin1, LOW);
          shiftOut(dataPin1, clockPin1, MSBFIRST, leds1); //diğer taraftan başlaması için LSBFIRST kullanabiliriz
          digitalWrite(latchPin1, HIGH);
          delay(gecikme);
          int x=analogRead(sensor_X);
          if(x>900){
               y_ekseni_tara(i-1);
          }
         bitWrite(leds1,i,LOW);
         son_led_off1();
       }

         bitWrite(leds1,0,HIGH);
          digitalWrite(latchPin1, LOW);
          shiftOut(dataPin1, clockPin1, MSBFIRST, leds1); //diğer taraftan başlaması için LSBFIRST kullanabiliriz
          digitalWrite(latchPin1, HIGH);
          delay(gecikme);
          int x=analogRead(sensor_X);
          if(x>900){
               y_ekseni_tara(7);

          }
         bitWrite(leds1,0,LOW);
         son_led_off1();
   **/
  /**      for (int i = 1; i < 8; i++) // --------------Ikinci Mutltiplixer --------------------------------------------
       {
         bitWrite(leds2,i,HIGH);
          digitalWrite(latchPin2, LOW);
          shiftOut(dataPin2, clockPin2, MSBFIRST, leds2); //diğer taraftan başlaması için LSBFIRST kullanabiliriz
          digitalWrite(latchPin2, HIGH);
          delay(gecikme);
          int x1=analogRead(sensor_X);
          if(x1>900){
            y_ekseni_tara(i+7);
          }
         bitWrite(leds2,i,LOW);
         son_led_off2();
       }

       bitWrite(leds2,0,HIGH);
          digitalWrite(latchPin2, LOW);
          shiftOut(dataPin2, clockPin2, MSBFIRST, leds2); //diğer taraftan başlaması için LSBFIRST kullanabiliriz
          digitalWrite(latchPin2, HIGH);
          delay(gecikme);
          int x1=analogRead(sensor_X);
          if(x1>900){
            y_ekseni_tara(15);
          }
         bitWrite(leds2,0,LOW);
         son_led_off2();
  **/

} // end of the loop
void yazdir() {
  for (int i = 0; i < 4 ; i++) {
    Serial.print(pixeller[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void yazdir_new() {
  for (int i = 0; i < 4 ; i++) {
    if (pixeller[i] == 1) {
      Serial.print((i+1) * 120);
      Serial.print(" ");
    }
    else   {
      Serial.print(0);
      Serial.print(" ");
    }

  }
  Serial.println();
}
void harita_sifirla() {
  for (int x = 0; x < 8; x++) {
    pixeller[x] = 0;
  }
}
//------------------------------------
void check_noise() {
  son_led_off1();
  son_led_off2();
  son_led_off3();
  for (int i = 0; i < 10; i++) {
    analog.update();
    analog.setSnapMultiplier(0.01);
    int x = analog.getValue();
    int temp = 1022 - x;
    Serial.println(temp);
    noise = noise + temp;
    delay(100);

  }
  noise = noise / 50;
}
//------------------------------------
void son_led_off1()
{
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin1, LSBFIRST, leds1);
  digitalWrite(latchPin1, HIGH);
}
void son_led_off2()
{
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, LSBFIRST, leds2);
  digitalWrite(latchPin2, HIGH);
}
void son_led_off3()
{
  digitalWrite(latchPin3, LOW);
  shiftOut(dataPin3, clockPin3, LSBFIRST, leds_Yan);
  digitalWrite(latchPin3, HIGH);
}
