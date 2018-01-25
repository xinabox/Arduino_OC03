/*************************************************************
	This is an examples for the OC03
	Relay Out Low Voltage
	
	You can buy one on our store!
	-----> https://xinabox.cc/products/OC03/
	
	This example in structs the OC03 to turn its output port
	on and off
	
	The sensor communicates over the I2C Bus.
	
*************************************************************/

/********************* Library Includes *********************/
#include <xOC03.h> // https://github.com/xinabox/xOC03
#include <xCore.h> // https://github.com/xinabox/xCore

/****************** Global sensor objects *******************/
xOC03 OC03;

/********************* SYSTEM VARIABLES *********************/
const int DELAY_TIME = 2000;

/*********************** Sketch Code ************************/
void setup() {
	// Start the Serial Monitor
	Serial.begin(115200);

	#ifdef ESP8266
		Wire.pins(2,14);
	#endif
		
	// Start the I2C Communication
	Wire.begin();
	
	// Start the OC03 port expander
	OC03.begin();

	Serial.println("OC03 Test");
}

void loop() {
	// Switch OUT on
	OC03.write(HIGH);
	delay(DELAY_TIME);
	
	// Switch OUT off
	OC03.write(LOW);
	delay(DELAY_TIME);
	
}