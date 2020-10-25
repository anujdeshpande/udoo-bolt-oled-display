#include <Wire.h>
#include <SeeedGrayOLED.h>
    
int yoffset = 6;
int textoffset = 56;

void setup() {
    Serial.begin(9600);
    Serial.println("Setting up!");
    Wire.begin();
    SeeedGrayOled.init(SH1107G);  //initialize SEEED Gray OLED display

    SeeedGrayOled.clearDisplay();           //clear the screen and set start position to top left corner
    SeeedGrayOled.setInverseDisplay();       //Set display to Normal mode
    SeeedGrayOled.setVerticalMode();        // Set to vertical mode for displaying text

    SeeedGrayOled.setTextXY(2, yoffset);
    SeeedGrayOled.putString("CPU  :");
    
    SeeedGrayOled.setTextXY(4, yoffset);
    SeeedGrayOled.putString("RAM  :");    

    SeeedGrayOled.setTextXY(6, yoffset);
    SeeedGrayOled.putString("Temp :");

    SeeedGrayOled.setTextXY(2, yoffset+textoffset);
    SeeedGrayOled.putString("X");
    SeeedGrayOled.setTextXY(4, yoffset+textoffset);
    SeeedGrayOled.putString("X");
    SeeedGrayOled.setTextXY(6, yoffset+textoffset);
    SeeedGrayOled.putString("X");
}

void loop() {
    while (Serial.available() > 0) {

	int cpu = Serial.parseInt();
	int ram = Serial.parseInt();
	int temp = Serial.parseInt();

	if (Serial.read() == '\n') {
//      cpu = constrain(cpu, 0, 100);
//      ram = constrain(ram, 0, 100);
//      temp = constrain(temp, 0, 100);
//      Serial.print(cpu);
//      Serial.print(ram);
//      Serial.println(temp);

	    SeeedGrayOled.setTextXY(2, yoffset+textoffset);
	    SeeedGrayOled.putNumber(cpu);
      
	    SeeedGrayOled.setTextXY(4, yoffset+textoffset);
	    SeeedGrayOled.putNumber(ram);
      
	    SeeedGrayOled.setTextXY(6, yoffset+textoffset);
	    SeeedGrayOled.putNumber(temp);
	}
    }
}
