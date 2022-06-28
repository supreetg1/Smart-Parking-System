#include <LiquidCrystal.h>

#define slot1   A0
#define slot2   A1
#define slot3   A2

#define M1      8
#define M2      9

String Card1 = "36484848485553485457531013";
String Card2 = "36484848485554554948521013";
String Card3 = "36484848485553535353491013";
String Card4 = "36484848485549485651551013";
String content = "";

LiquidCrystal lcd (7, 6, 5, 4, 3, 2);

int Counter = 0;
String apiKey = "6SC1BSCADO4JCT7G";                  //  Enter your Write API key from ThingSpeak
int flag0 = 1, flag1 = 1, flag2 = 1;
int full = 0;
String SLOT1_state, SLOT2_state, SLOT3_state;
bool S1Flag = 0, S2Flag = 0, S3Flag = 0, S4Flag = 0;


void Parking_availabe()
{
  if (digitalRead(slot1) == 1)
  {
    flag0 = 0;
    SLOT1_state = "FULL";
  }
  else
  {
    flag0 = 1;
    SLOT1_state = "Free";
  }
  if (digitalRead(slot2) == 1)
  {
    flag1 = 0;
    SLOT2_state = "FULL";
  }
  else
  {
    flag1 = 1;
    SLOT2_state = "Free";
  }
  if (digitalRead(slot3) == 1)
  {
    flag2 = 0;
    SLOT3_state = "FULL";
  }
  else
  {
    flag2 = 1;
    SLOT3_state = "Free";
  }
  LCD_disp(flag0, flag1, flag2);

  delay(500);
  Counter++;
}


void LCD_disp(int a, int b, int c)
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  1    2    3   ");
  lcd.setCursor(0, 1);
  if (flag0 == 0)
  {
    lcd.print("Full");
  }
  else
  {
    lcd.print("Free");
  }
  lcd.setCursor(5, 1);
  if (flag1 == 0)
  {
    lcd.print("Full");
  }
  else
  {
    lcd.print("Free");
  }
  lcd.setCursor(10, 1);
  if (flag2 == 0)
  {
    lcd.print("Full");
  }
  else
  {
    lcd.print("Free");
  }
  if (flag0 == 0 & flag1 == 0 & flag2 == 0 )
  {
    full = 1;
  }
  else
  {
    full = 0;
  }
  delay(500);
}



void setup()
{
  Serial.begin(9600);
  pinMode(slot1 , INPUT);
  pinMode(slot2 , INPUT);
  pinMode(slot3 , INPUT);
  pinMode(M1 , OUTPUT);
  pinMode(M2 , OUTPUT);
  digitalWrite(M1 , LOW);
  digitalWrite(M2, LOW);
  //  Serial.println("Approach your reader card...");
  //  Serial.println();
  //  Serial.println("Connecting to ");
  //  Serial.println(ssid);
  lcd.begin(16, 2);
  lcd.setCursor (0, 0);
  lcd.print ( "    WEL-COME    " );
  lcd.setCursor (0, 1);
  lcd.print ( "  CAR PARKING   " );
  delay(1000);
}

void loop()
{

  Parking_availabe();
  if (Serial.available() > 0)
  {
    content = "";
    while (Serial.available() > 0)
    {
      content += Serial.read();
      //      content = Serial.readStringUntil('\n');
      delay(2);
    }

    //    Serial.println(content);
    if (content == Card1)
    {
      Parking_availabe();
      if (full == 1)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  NOT AVAILABLE ");
        delay(1000);
      }
      else
      {
        if (S1Flag == 0)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Wel Come  IN");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Name:supreet gokarn");
          lcd.setCursor(0, 1);
          lcd.print("ID:123456");
          Serial.println("$#@" + apiKey + "#&field1=Name:supreet gokarn  ID:123456  IN#");
          digitalWrite(M1, HIGH);
          delay(2000);
          digitalWrite(M1, LOW);
          delay(5000);
          digitalWrite(M2, HIGH);
          delay(2000);
          digitalWrite(M2, LOW);
          S1Flag = 1;
        }
        else
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Thank You   EXIT");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Name:supreet gokarn");
          lcd.setCursor(0, 1);
          lcd.print("ID:123456  EXIT");
          Serial.println("$#@" + apiKey + "#&field1=Name:supreet gokarn  ID:123456  EXIT#");
          digitalWrite(M1, HIGH);
          delay(2000);
          digitalWrite(M1, LOW);
          delay(5000);
          digitalWrite(M2, HIGH);
          delay(2000);
          digitalWrite(M2, LOW);
          S1Flag = 0;
        }
      }
    }
    else if (content == Card2)
    {
      Parking_availabe();
      if (full == 1)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  NOT AVAILABLE ");
        delay(1000);
      }
      else
      {
        if (S2Flag == 0)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Wel Come  IN");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Name:omkar pattanshetti");
          lcd.setCursor(0, 1);
          lcd.print("ID:123456");
          Serial.println("$#@" + apiKey + "#&field2=Name:omkar pattanshetti  ID:123456  IN#");
          digitalWrite(M1, HIGH);
          delay(2000);
          digitalWrite(M1, LOW);
          delay(5000);
          digitalWrite(M2, HIGH);
          delay(2000);
          digitalWrite(M2, LOW);
          S2Flag = 1;
        }
        else
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Thank You   EXIT");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Name:omkar pattanshetti");
          lcd.setCursor(0, 1);
          lcd.print("ID:123456");
          Serial.println("$#@" + apiKey + "#&field2=Name:omkar pattanshetti  ID:123456  EXIT#");
          digitalWrite(M1, HIGH);
          delay(2000);
          digitalWrite(M1, LOW);
          delay(5000);
          digitalWrite(M2, HIGH);
          delay(2000);
          digitalWrite(M2, LOW);
          S2Flag = 0;
        }
      }
    }
    else if (content == Card3)
    {
      Parking_availabe();
      if (full == 1)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  NOT AVAILABLE ");
        delay(1000);
      }
      else
      {
        if (S3Flag == 0)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Wel Come  IN");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Name:Ayesha shekh");
          lcd.setCursor(0, 1);
          lcd.print("ID:123456");
          Serial.println("$#@" + apiKey + "#&field3=Name:Ayesha shekh  ID:123456  IN#");
          digitalWrite(M1, HIGH);
          delay(2000);
          digitalWrite(M1, LOW);
          delay(5000);
          digitalWrite(M2, HIGH);
          delay(2000);
          digitalWrite(M2, LOW);
          S3Flag = 1;
        }
        else
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Thank You   EXIT");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Name:Ayesha shekh");
          lcd.setCursor(0, 1);
          lcd.print("ID:123456");
          Serial.println("$#@" + apiKey + "#&field3=Name:Ayesha shekh  ID:123456  EXIT#");
          digitalWrite(M1, HIGH);
          delay(2000);
          digitalWrite(M1, LOW);
          delay(5000);
          digitalWrite(M2, HIGH);
          delay(2000);
          digitalWrite(M2, LOW);
          S3Flag = 0;
        }
      }
    }
    //    else if (content == Card4)
    //    {
    //      Parking_availabe();
    //      if (full == 1)
    //      {
    //        lcd.clear();
    //        lcd.setCursor(0, 0);
    //        lcd.print("  NOT AVAILABLE ");
    //        delay(1000);
    //      }
    //      else
    //      {
    //        if (S4Flag == 0)
    //        {
    //          lcd.clear();
    //          lcd.setCursor(0, 0);
    //          lcd.print("Wel Come  IN");
    //          delay(1000);
    //          lcd.clear();
    //          lcd.setCursor(0, 0);
    //          lcd.print("Name:Ajay4");
    //          lcd.setCursor(0, 1);
    //          lcd.print("ID:123456");
    //          Serial.println("$#@" + apiKey + "#&field4=Name:Ajay4  ID:123456  IN#");
    //          digitalWrite(M1, HIGH);
    //          delay(2000);
    //          digitalWrite(M1, LOW);
    //          delay(5000);
    //          digitalWrite(M2, HIGH);
    //          delay(2000);
    //          digitalWrite(M2, LOW);
    //          S4Flag = 1;
    //        }
    //        else
    //        {
    //          lcd.clear();
    //          lcd.setCursor(0, 0);
    //          lcd.print("Thank You   EXIT");
    //          delay(1000);
    //          lcd.clear();
    //          lcd.setCursor(0, 0);
    //          lcd.print("Name:unknown");
    //          lcd.setCursor(0, 1);
    //          lcd.print("ID:123456");
    //          Serial.println("$#@" + apiKey + "#&field4=Name:unknown  ID:123456  EXIT#");
    //          digitalWrite(M1, HIGH);
    //          delay(2000);
    //          digitalWrite(M1, LOW);
    //          delay(5000);
    //          digitalWrite(M2, HIGH);
    //          delay(2000);
    //          digitalWrite(M2, LOW);
    //          S4Flag = 0;
    //        }
    //      }
    //    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    CARD NOT    ");
      lcd.setCursor(0, 1);
      lcd.print("   REGISTERED   ");
      delay(1000);
    }
  }
}