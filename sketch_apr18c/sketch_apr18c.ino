int aPin = 10; // A
int bPin = 13; // ________
int cPin = 9; // | |
int dPin = 2; // F | | B
int ePin = 4; // | G |
int fPin = 11; // |________|
int gPin = 12; // | |
int GND1 = 5; // | |
int GND2 = 6; // E | | C
int GND3 = 7; // |________|
int GND4 = 8; //
int num; // D
int dig1 = 1;
int dig2 = 2;
int dig3 = 2;
int dig4 = 1;
int DTime = 4;


void setup()
{
pinMode(aPin, OUTPUT);
pinMode(bPin, OUTPUT);
pinMode(cPin, OUTPUT);
pinMode(dPin, OUTPUT);
pinMode(ePin, OUTPUT);
pinMode(fPin, OUTPUT);
pinMode(gPin, OUTPUT);
pinMode(GND1, OUTPUT);
pinMode(GND2, OUTPUT);
pinMode(GND3, OUTPUT);
pinMode(GND4, OUTPUT);
}
void loop()
{
digitalWrite( GND1, LOW);
digitalWrite( GND2, LOW);
digitalWrite( GND3, LOW);
digitalWrite( GND4, LOW);

digitalWrite( GND4, HIGH); //digit 4
pickNumber(dig4);
delay(DTime);
digitalWrite( GND4, LOW); digitalWrite( GND3, HIGH); //digit 3
pickNumber(dig3);
delay(DTime);
digitalWrite( GND3, LOW); digitalWrite( GND2, HIGH); //digit 2
pickNumber(dig2);
delay(DTime);
digitalWrite( GND2, LOW); digitalWrite( GND1, HIGH); //digit 1
pickNumber(dig1);
delay(DTime);
digitalWrite( GND1, LOW);

} 

void pickNumber(int x){
  switch(x){
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    default: zero(); break;
  }
}

void one()
{
digitalWrite( aPin, HIGH);
digitalWrite( bPin, LOW);
digitalWrite( cPin, LOW);
digitalWrite( dPin, HIGH);
digitalWrite( ePin, HIGH);
digitalWrite( fPin, HIGH);
digitalWrite( gPin, HIGH);
}

void two()
{
digitalWrite( aPin, LOW);
digitalWrite( bPin, LOW);
digitalWrite( cPin, HIGH);
digitalWrite( dPin, LOW);
digitalWrite( ePin, LOW);
digitalWrite( fPin, HIGH);
digitalWrite( gPin, LOW);
}

void three()
{
digitalWrite( aPin, HIGH);
digitalWrite( bPin, HIGH);
digitalWrite( cPin, HIGH);
digitalWrite( dPin, HIGH);
digitalWrite( ePin, LOW);
digitalWrite( fPin, LOW);
digitalWrite( gPin, HIGH);
}

void four()
{
digitalWrite( aPin, LOW);
digitalWrite( bPin, HIGH);
digitalWrite( cPin, HIGH);
digitalWrite( dPin, LOW);
digitalWrite( ePin, LOW);
digitalWrite( fPin, HIGH);
digitalWrite( gPin, HIGH);
}

void five()
{
digitalWrite( aPin, HIGH);
digitalWrite( bPin, LOW);
digitalWrite( cPin, HIGH);
digitalWrite( dPin, HIGH);
digitalWrite( ePin, LOW);
digitalWrite( fPin, HIGH);
digitalWrite( gPin, HIGH);
}

void six()
{
digitalWrite( aPin, HIGH);
digitalWrite( bPin, LOW);
digitalWrite( cPin, HIGH);
digitalWrite( dPin, HIGH);
digitalWrite( ePin, HIGH);
digitalWrite( fPin, HIGH);
digitalWrite( gPin, HIGH);
}

void seven()
{
digitalWrite( aPin, HIGH);
digitalWrite( bPin, HIGH);
digitalWrite( cPin, HIGH);
digitalWrite( dPin, LOW);
digitalWrite( ePin, LOW);
digitalWrite( fPin, LOW);
digitalWrite( gPin, LOW);
}

void eight()
{
digitalWrite( aPin, LOW);
digitalWrite( bPin, LOW);
digitalWrite( cPin, LOW);
digitalWrite( dPin, LOW);
digitalWrite( ePin, LOW);
digitalWrite( fPin, LOW);
digitalWrite( gPin, LOW);
}

void nine()
{
digitalWrite( aPin, LOW);
digitalWrite( bPin, LOW);
digitalWrite( cPin, LOW);
digitalWrite( dPin, LOW);
digitalWrite( ePin, HIGH);
digitalWrite( fPin, LOW);
digitalWrite( gPin, LOW);
}

void zero()
{
digitalWrite( aPin, LOW);
digitalWrite( bPin, LOW);
digitalWrite( cPin, LOW);
digitalWrite( dPin, LOW);
digitalWrite( ePin, LOW);
digitalWrite( fPin, LOW);
digitalWrite( gPin, HIGH);
}
