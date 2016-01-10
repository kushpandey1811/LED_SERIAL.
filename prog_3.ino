/* if RED is pressed then 
 *  if red is already lit it should turn off vice-versa
 *  if any other color is entered then it should turn off all the rest of the LEDs
 */

#include "string.h"
const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;

bool state = LOW;
bool state2 = LOW;
bool state3 = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (LED1 , OUTPUT);
  pinMode (LED2 , OUTPUT);
  pinMode (LED3 , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  // char array[20];
  String array="";
  // array.equalsIgnoreCase();
  // Serial.print("Enter Command = ");
  // for(i=0;i<=11;i++)
  //{
    while(Serial.available())
    {
      char ch = (char)Serial.read();
      delay(5);
      array += ch; // (char)Serial.read();
      //if(array[i]==';')break;
      //memset(array,0,sizeof(array));
      //Serial.flush();
      Serial.print('[');
      Serial.print(ch);
      Serial.println(']');
      
    }
    if(array.length() > 0){
      Serial.println(array);
      Serial.flush();
      check_color(array);
      array="";
      

    }
}

enum co
{
  RED=0,
  GREEN=1,
  BLUE=3,
  YELLOW=2,
};

void check_color(String color)
{
  char array[20];
  String col[]={"RED","GREEN","YELLOW","BLUE"};
  color.toCharArray(array,color.length());
  // String.toCharArray(array_name,length_of_string);
  
  //if(strncmp("RED",array,6)==0)
  if(color.equalsIgnoreCase(col[RED]))
  {
    state = !state; 
    digitalWrite(LED1,state);   
    if(state){
      Serial.print("RED_ON;\n");
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }else{
      Serial.print("RED_OFF\n");
    }
  }
  else if(color.equalsIgnoreCase(col[GREEN]))//(strncmp("GREEN_ON",array,8)==0)
  {
    state2 = !state2; 
    digitalWrite(LED2,state);
    if(state){
      Serial.print("GREEN_ON;\n");
      digitalWrite(LED1, LOW);
      digitalWrite(LED3, LOW);
    }else{
      Serial.print("GREEN_OFF\n");
    }
    // digitalWrite(LED2,HIGH);    Serial.print("GREEN_ON;\n");
  }
  /*else if(strncmp("GREEN_OFF",array,9)==0)
  {
    
    //digitalWrite(LED2,LOW);    Serial.print("GREEN_OFF;\n");
  }*/
  else if(color.equalsIgnoreCase(col[YELLOW]))//(strncmp("YELLOW_ON",array,9)==0)
  {
    state3 = !state3; 
    digitalWrite(LED3,state);
    if(state){
      Serial.print("YELLOW_ON;\n");
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }else{
      Serial.print("YELLOW_OFF\n");
    }
   // digitalWrite(LED3,HIGH);    Serial.print("YELLOW_ON;\n");
  }
  /*else if(strncmp("YELLOW_OFF",array,10)==0)
  {
    digitalWrite(LED3,LOW);    Serial.print("YELLOW_OFF;\n");
  } */ 
  else
  {
    Serial.print("Command Faulty\n");
    Serial.flush();
  }
}
