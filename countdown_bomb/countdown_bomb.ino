//          TOP
//      RI2     LE1
//          MID
//      RI1     LE2
// DOT      BOT    

// DOT BOT MID TOP RI2 RI1 LE2 LE1
#define COD0 0x5f // 01011111
#define COD1 0x03 // 00000011
#define COD2 0x75 // 01110101
#define COD3 0x73 // 01110011
#define COD4 0x2B // 00101011
#define COD5 0x7A // 01111010
#define COD6 0x6E // 01101110
#define COD7 0x13 // 00010011
#define COD8 0x7F // 01111111
#define COD9 0x3B // 00111011
#define CODE 0x20 // 00100000
#define CODo 0x66 // 01100110
#define CODm 0x1f // 00011111

// SEVEN SEGMENTS PINS
int SS_LE1 = 13;
int SS_LE2 = 9;
int SS_RI1 = 4;
int SS_RI2 = 11;
int SS_TOP = 10;
int SS_MID = 12;
int SS_BOT = 2;
//#define SS_DOT 8

// OTHER SS PINS
int SS_GN1 = 5;
int SS_GN2 = 6;
int SS_GN3 = 7;
int SS_GN4 = 8;

#define TIME 5

//#define ATOI(a) (a & 0x0f)
int pins[] = {SS_LE1, SS_LE2, SS_RI1, SS_RI2, SS_TOP, SS_MID, SS_BOT};
//int digits[] = {SS_GN1, SS_GN2, SS_GN3, SS_GN4};

char segs[] = { COD0, COD1, COD2, COD3, COD4, COD5, COD6, COD7, COD8, COD9 };

void showNum(char val, int count);

#define SECS 1000

#define DOWN

int sTime = SECS;

void setup() 
{
  
  pinMode(SS_LE1, OUTPUT);
  pinMode(SS_LE2, OUTPUT);
  pinMode(SS_RI1, OUTPUT);
  pinMode(SS_RI2, OUTPUT);
  pinMode(SS_TOP, OUTPUT);
  pinMode(SS_MID, OUTPUT);
  pinMode(SS_BOT, OUTPUT);

  pinMode(SS_GN1, OUTPUT);
  pinMode(SS_GN2, OUTPUT);
  pinMode(SS_GN3, OUTPUT);
  pinMode(SS_GN4, OUTPUT);
  
}

#ifdef UP
int num0=0; // DECINE DI MINUTI
int num1=0; // MINUTI 
int num2=0; // DECINE DI SECONDI
int num3=0; // SECONDI
#else
int num1=1; // DECINE DI MINUTI
int num0=0; // MINUTI 
int num2=3; // DECINE DI SECONDI
int num3=0; // SECONDI
#endif

void loop()
{
  
  digitalWrite(SS_GN1, LOW); 
  digitalWrite(SS_GN2, LOW);
  digitalWrite(SS_GN3, LOW);
  digitalWrite(SS_GN4, LOW);
  
  digitalWrite(SS_GN4, HIGH); //digit 4
  showNum(numToSS(num3), 0);
  delay(TIME);  
  digitalWrite( SS_GN4, LOW);
  
  digitalWrite(SS_GN3, HIGH); //digit 3
  showNum(numToSS(num2), 0);
  delay(TIME);
  digitalWrite(SS_GN3, LOW);
  
  digitalWrite(SS_GN2, HIGH); //digit 2
  showNum(numToSS(num1), 0);
  delay(TIME);
  digitalWrite(SS_GN2, LOW);
  
  digitalWrite(SS_GN1, HIGH); //digit 1
  showNum(numToSS(num0), 0);
  delay(TIME);
  digitalWrite(SS_GN1, LOW);

  sTime -= TIME * 4;

#ifdef UP
  
  if (sTime == 0)
  {
    num3++;
    sTime = SECS;
  }
  
  if (num3 > 9)
  {
   num2++;
   num3=0; 
  }
  
  if (num2>5)
  {
    num2=0;
    num1++;
  }
  
  if (num1>9)
  {
    num1=0;
    num0++;
  }
#else
  if (sTime <= 0)
  {
   if (num3 > 0)
   {
     num3--;
     sTime = SECS;
   }
   else if (num2 > 0)
   {
     num2--;
     num3=10;
   }
   else if (num1 > 0)
   {
     num1--;
     num2=5;
     num3=10;
   }
   else if(num0 > 0)
   {
     num0--;
     num1=9;
     num2=5;
     num3=10;
   } 
   else
   {
     //END
     num0 = -1;
     num1 = -1;
     num2 = -1;
     num3 = -1;
   }
  }
#endif
}

char numToSS(int num)
{
  
        if (num > 9 || num < 0)
        {
            // ERROR CODE
            return CODE;  
        }
        
        return segs[num];
        
}

void showNum(const char val, int count)
{
       
       if (count==7)
       {
                return;
       }

       digitalWrite(pins[count], (((val>>count)&0x01)==1)?LOW:HIGH);
       
       showNum((val), (++count));

}
