#include "NRF24L01.h"




void CS_Enalbe(void){
	HAL_GPIO_WritePin(NRF24_CS_PORT, NRF24_CS_PIN, GPIO_PIN_RESET);
}

void CS_Disable(void){
	HAL_GPIO_WritePin(NRF24_CS_PORT, NRF24_CS_PIN, GPIO_PIN_SET);
}

void CE_Enable(void){
	HAL_GPIO_WritePin(NRF24_CE_PORT, NRF24_CE_PIN, GPIO_PIN_RESET);
}

void CE_Disable(void){
	HAL_GPIO_WritePin(NRF24_CE_PORT, NRF24_CE_PIN, GPIO_PIN_RESET);
}




// Write a single byte to the device
void NRF24_WriteReg(uint8_t reg, uint8_t data){

	uint8_t buf[2];
	buf[0] = reg | 1<<5;  // write 1 in 5th position from datasheet
	buf[1] = data;

	CS_Enalbe();

	// Senda data to to deivce with SPI
	HAL_SPI_Transmit(NRF24_SPI, buf, 2, 500);

	CS_Disable();
}



// Write multiple single bytes to the device
void NRF24_WriteRegMulti(uint8_t reg, uint8_t *data, int size){

	uint8_t buf[2];
	buf[0] = reg | 1<<5;  // write 1 in 5th position from datasheet

	CS_Enalbe();

	// Senda data to to deivce with SPI
	HAL_SPI_Transmit(NRF24_SPI, &reg, 2, 500);
	HAL_SPI_Transmit(NRF24_SPI, data, size, 500);

	CS_Disable();
}


// Read one byte from thedevice
uint8_t NRF24_ReadReg(uint8_t reg){

	uint8_t data=0;

	CS_Enalbe();

	// Senda data to to deivce with SPI
	HAL_SPI_Transmit(NRF24_SPI, &reg, 1, 500);
	HAL_SPI_Receive(NRF24_SPI, &data, 1, 500);

	CS_Disable();

	return data;
}


// Read multiple bytes from thedevice
void NRF24_ReadRegMulti(uint8_t reg, uint8_t *data, int size){

	CS_Enalbe();

	// Senda data to to deivce with SPI
	HAL_SPI_Transmit(NRF24_SPI, &reg, 1, 500);
	HAL_SPI_Receive(NRF24_SPI, data, size, 500);

	CS_Disable();
}




// Send command to NRF, no need to specify register
void NRF24_Cmd(uint8_t cmd){

	CS_Enalbe();

	// Senda data to to deivce with SPI
	HAL_SPI_Transmit(NRF24_SPI, &cmd, 1, 500);

	CS_Disable();
}




void NRF24_Init(void){

	// Reset
	CE_Disable();
	CS_Disable();

	NRF24_WriteReg(CONFIG, 0);

	NRF24_WriteReg(EN_AA, 0); // disable auto acknowledgmnet

	NRF24_WriteReg(EN_RXADDR, 1); // not enabling any data pipe

	NRF24_WriteReg(SETUP_AW, 0x03); // 5 bytes for the tx/rx addr

	NRF24_WriteReg(SETUP_RETR, 0); // disable retransmission

	NRF24_WriteReg(RF_CH, 0); // channel selection for transmission, put any number

	NRF24_WriteReg(RF_SETUP, 0x0E); // set data rate and transmission power, power = 0dB, dataRate = 2Mbps
}





