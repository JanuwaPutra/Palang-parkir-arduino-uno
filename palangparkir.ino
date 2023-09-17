#include <LiquidCrystal.h>// initialize the library with the numbers of the interface pins

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

#include <Servo.h> //includes the servo library



Servo myservo1;



int ir_s1 = 2;

int ir_s2 = 4;



int Total = 6;

int Space;



int flag1 = 0;

int flag2 = 0;



void setup() {

pinMode(ir_s1, INPUT);

pinMode(ir_s2, INPUT);

  

myservo1.attach(3);

myservo1.write(0);



lcd.begin(16, 2);  

lcd.setCursor (0,0);

lcd.print("  Parkiran  ");

lcd.setCursor (0,1);

lcd.print("  Mandalika     ");

delay (2000);

lcd.clear();  



Space = Total;

}



void loop(){ 

 

if(digitalRead (ir_s1) == LOW && flag1==0){

if(Space>0){flag1=1;

if(flag2==0){myservo1.write(90); Space = Space-1;}

}else{

lcd.setCursor (0,0);

lcd.print(" Maaaf Parkiran ");  

lcd.setCursor (0,1);

lcd.print("    Penuh        "); 

delay (1000);

lcd.clear(); 

}

}



if(digitalRead (ir_s2) == LOW && flag2==0){flag2=1;

if(flag1==0){myservo1.write(90); Space = Space+1;}

}



if(flag1==1 && flag2==1){

delay (1000);

myservo1.write(0);

flag1=0, flag2=0;

}



lcd.setCursor (0,0);

lcd.print("Total Parkir: ");

lcd.print(Total);



lcd.setCursor (0,1);

lcd.print("Sisa Parkir: ");

lcd.print(Space);

}
