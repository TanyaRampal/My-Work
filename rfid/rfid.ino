#define RELAY_PIN 13                                                                                             
#include <LiquidCrystal.h>            // Header inclusio
char j=0,x;
char Card_No[12];
char rfid_N0[12]="30004F89689E";
LiquidCrystal lcd(6,7,12,11,10,9);
 
void setup() 
{
     pinMode(RELAY_PIN,OUTPUT);
     lcd.begin(16, 2);                // Set up th
//     e LCD's number of columns and rows:
     lcd.setCursor(0,0);              // Position the LCD cursor
     lcd.print("RFID Based Login");   // Print a message to the LCD.
     lcd.setCursor(0,1);              // Position the LCD cursor
     lcd.print("     System     "); 
     Serial.begin(9600);              // Initialize the serial communications:
     delay(1000);
     lcd.clear();
     lcd.setCursor(0,0); 
     lcd.print("Use your Tag to ");
     lcd.setCursor(0,1);
     lcd.print("Login           "); 
     digitalWrite(RELAY_PIN,HIGH);
}
 
void loop() 
{ 
  if (Serial.available()>0) 
  {
    x=Serial.read();          
    Card_No[j] =x;                    // Save the read_data to an array
    j++;
    if(j==12)                         // After intake of 12 character 
    {  
      Card_No[j]='\0';
      j=0;
      lcd.setCursor(0,0);
      lcd.print("Found           ");
      delay(500); 
      lcd.setCursor(0,0);
      lcd.print("ID:             ");
      lcd.setCursor(3,0); 
      lcd.print(Card_No); 
      delay(3000);
      if(!strcmp(rfid_N0,Card_No))
      {          
        // Matching found in read_dat & card_id
         digitalWrite(RELAY_PIN,LOW);
         delay(5000);
         digitalWrite(RELAY_PIN,HIGH);
        delay(5000);
         lcd.setCursor(0,0); 
         lcd.print("Login Succeeded "); 
         delay(3000); 
         lcd.clear();
         lcd.print("   THANK YOU    "); 
         delay(3000);
         Serial.println("Allowed");
          
      }
      else                            // No matching found in read_dat & card_id
      {  
         lcd.setCursor(0,0); 
         lcd.print("Login Failed    ");  
         delay(3000);
         
         Serial.println("Not Allowed");
      }
      lcd.clear();
    }  
  }
  else                                // If not read data go to show the tag again
  {
    lcd.setCursor(0,0); 
    lcd.print("Use your Tag to ");
    lcd.setCursor(0,1);
    lcd.print("Login           ");  
  }
}