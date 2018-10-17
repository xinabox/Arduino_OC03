/*
	This is a library for the OC03
	Relay Out Low Voltage

	The board uses I2C for communication.
	The board communicates with the following I2C device:
	* 	PCA9554A
	
	Data Sheets:
	PCA9554A - http://www.ti.com/lit/ds/symlink/pca9554a.pdf
*/

#include <xOC03.h>

/********************************************************
 	Constructor
*********************************************************/
xOC03::xOC03()
{
	PCA9554A_I2C_ADDRESS = 0x38;
}

xOC03::xOC03(uint8_t addr)
{
	PCA9554A_I2C_ADDRESS = addr;
}

/********************************************************
 	Configure OC03
*********************************************************/
bool xOC03::begin(void)
{
	begin(PCA9554A_ALL_OUTPUTS_OFF);
}

bool xOC03::begin(bool state)
{
	write(state);
	xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_CONFIG, PCA9554A_CONF_OUTPUT);
	return true;
}

/********************************************************
 	Write to PIN
*********************************************************/
void xOC03::write(bool state)
{	
	if(state == true){
		xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT, 0x01);
	}else if(state == false){
		xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT, 0x00);
	}
}

/********************************************************
 	Get output pin Status
*********************************************************/
uint8_t xOC03::getStatus(void)
{
	uint8_t pin_state = xCore.read8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT); 
	return pin_state;
}



