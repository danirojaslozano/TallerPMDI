//     ____________________     __          __       ___   ____ ___   ____ 
//    /  _/  _/ ____/ ____/    / /   ____ _/ /_     |__ \ / __ \__ \ / __ \
//    / / / // __/ / __/      / /   / __ `/ __ \    __/ // / / /_/ // / / /
//  _/ /_/ // /___/ /___     / /___/ /_/ / /_/ /   / __// /_/ / __// /_/ / 
// /___/___/_____/_____/    /_____/\__,_/_.___/   /____/\____/____/\____/  
// ____________________________________________________________________________                                                                       
// Libreria MPUandes.h
// Autores: Daniela Rojas, Sebastian Sierra, Miguel Diaz.
// Lectura MPU6050 desde NodeMCU, utilizando I2C. 

#include <Wire.h>
#include <Arduino.h>
#include <MPUandes.h>

//////////////////////////////////////////////////////////
// SET UP
//////////////////////////////////////////////////////////
MPUandes::MPUandes(int sda, int scl)
{
  //Wire.begin(sda, scl);
  // MPU6050 few configuration register addresses
	uint8_t MPU6050_REGISTER_SMPLRT_DIV   =  0x19;
	uint8_t MPU6050_REGISTER_USER_CTRL    =  0x6A;
	uint8_t MPU6050_REGISTER_PWR_MGMT_1   =  0x6B;
	uint8_t MPU6050_REGISTER_PWR_MGMT_2   =  0x6C;
	uint8_t MPU6050_REGISTER_CONFIG       =  0x1A;
	uint8_t MPU6050_REGISTER_GYRO_CONFIG  =  0x1B;
	uint8_t MPU6050_REGISTER_ACCEL_CONFIG =  0x1C;
	uint8_t MPU6050_REGISTER_FIFO_EN      =  0x23;
	uint8_t MPU6050_REGISTER_INT_ENABLE   =  0x38;
	uint8_t MPU6050_REGISTER_ACCEL_XOUT_H =  0x3B;
	uint8_t MPU6050_REGISTER_SIGNAL_PATH_RESET  = 0x68;

  // MPU6050 Slave Device Address
	uint8_t MPU6050SlaveAddress = 0x68;

	int16_t AccelX, AccelY, AccelZ, Temperature, GyroX, GyroY, GyroZ;

}
//////////////////////////////////////////////////////////
// Privados
//////////////////////////////////////////////////////////
void MPUandes::I2C_Write(uint8_t deviceAddress, uint8_t regAddress, uint8_t data){
	Wire.beginTransmission(deviceAddress);
	Wire.write(regAddress);
	Wire.write(data);
	Wire.endTransmission();
}
//////////////////////////////////////////////////////////
// PUBLICO
//////////////////////////////////////////////////////////
// read all 14 register
int MPUandes::Read_Ax(){
	uint8_t deviceAddress = 0x68;
	uint8_t regAddress = 0x3B;
	Wire.beginTransmission(deviceAddress);
	Wire.write(regAddress);
	Wire.endTransmission();
	Wire.requestFrom(deviceAddress, (uint8_t)14);
	AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
	Temperature = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroX = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroY = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroZ = (((int16_t)Wire.read()<<8) | Wire.read());
	return AccelX;
}
int MPUandes::Read_Ay(){
	uint8_t deviceAddress = 0x68;
	uint8_t regAddress = 0x3B;
	Wire.beginTransmission(deviceAddress);
	Wire.write(regAddress);
	Wire.endTransmission();
	Wire.requestFrom(deviceAddress, (uint8_t)14);
	AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
	Temperature = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroX = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroY = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroZ = (((int16_t)Wire.read()<<8) | Wire.read());
	return AccelY;
}
int MPUandes::Read_Az(){
	uint8_t deviceAddress = 0x68;
	uint8_t regAddress = 0x3B;
	Wire.beginTransmission(deviceAddress);
	Wire.write(regAddress);
	Wire.endTransmission();
	Wire.requestFrom(deviceAddress, (uint8_t)14);
	AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
	Temperature = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroX = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroY = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroZ = (((int16_t)Wire.read()<<8) | Wire.read());
	return AccelZ;
}
int MPUandes::Read_T(){
	uint8_t deviceAddress = 0x68;
	uint8_t regAddress = 0x3B;
	Wire.beginTransmission(deviceAddress);
	Wire.write(regAddress);
	Wire.endTransmission();
	Wire.requestFrom(deviceAddress, (uint8_t)14);
	AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
	Temperature = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroX = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroY = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroZ = (((int16_t)Wire.read()<<8) | Wire.read());
	return Temperature;
}
int MPUandes::Read_Gx(){
	uint8_t deviceAddress = 0x68;
	uint8_t regAddress = 0x3B;
	Wire.beginTransmission(deviceAddress);
	Wire.write(regAddress);
	Wire.endTransmission();
	Wire.requestFrom(deviceAddress, (uint8_t)14);
	AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
	Temperature = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroX = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroY = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroZ = (((int16_t)Wire.read()<<8) | Wire.read());
	return GyroX;
}
int MPUandes::Read_Gy(){
	uint8_t deviceAddress = 0x68;
	uint8_t regAddress = 0x3B;
	Wire.beginTransmission(deviceAddress);
	Wire.write(regAddress);
	Wire.endTransmission();
	Wire.requestFrom(deviceAddress, (uint8_t)14);
	AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
	Temperature = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroX = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroY = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroZ = (((int16_t)Wire.read()<<8) | Wire.read());
	return GyroY;
}
int MPUandes::Read_Gz(){
	uint8_t deviceAddress = 0x68;
	uint8_t regAddress = 0x3B;
	Wire.beginTransmission(deviceAddress);
	Wire.write(regAddress);
	Wire.endTransmission();
	Wire.requestFrom(deviceAddress, (uint8_t)14);
	AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
	AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
	Temperature = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroX = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroY = (((int16_t)Wire.read()<<8) | Wire.read());
	GyroZ = (((int16_t)Wire.read()<<8) | Wire.read());
	return GyroZ;
}

//configure MPU6050
void MPUandes::MPU6050_Init(){
	delay(150);
	Wire.beginTransmission(0x68);
	Wire.write(0x19);
	Wire.write(0x07);
	Wire.endTransmission();
	Wire.beginTransmission(0x68);
	Wire.write(0x6B);
	Wire.write(0x01);
	Wire.endTransmission();
	Wire.beginTransmission(0x68);
	Wire.write(0x6C);
	Wire.write(0x00);
	Wire.endTransmission();
	Wire.beginTransmission(0x68);
	Wire.write(0x1A);
	Wire.write(0x00);
	Wire.endTransmission();
	Wire.beginTransmission(0x68);
	Wire.write(0x1B);
	Wire.write(0x00);
	Wire.endTransmission();
	Wire.beginTransmission(0x68);
	Wire.write(0x1C);
	Wire.write(0x00);
	Wire.endTransmission();//set +/-250 degree/second full scale
	Wire.beginTransmission(0x68);
	Wire.write(0x23);
	Wire.write(0x00);
	Wire.endTransmission();// set +/- 2g full scale
	Wire.beginTransmission(0x68);
	Wire.write(0x38);
	Wire.write(0x01);
	Wire.endTransmission();
	Wire.beginTransmission(0x68);
	Wire.write(0x68);
	Wire.write(0x00);
	Wire.endTransmission();
	Wire.beginTransmission(0x68);
	Wire.write(0x6A);
	Wire.write(0x00);
	Wire.endTransmission();

}


// ____________________________________________________________________________________________________________________                                                                           
//
// ╔╦╗┌─┐┌┐┌┬┌─┐┬  ┌─┐  ╦═╗┌─┐ ┬┌─┐┌─┐   ╔═╗┌─┐┌┐ ┌─┐┌─┐┌┬┐┬┌─┐┌┐┌  ╔═╗┬┌─┐┬─┐┬─┐┌─┐   ╔╦╗┬┌─┐┬ ┬┌─┐┬    ╔╦╗┬┌─┐┌─┐ 
//  ║║├─┤││││├┤ │  ├─┤  ╠╦╝│ │ │├─┤└─┐   ╚═╗├┤ ├┴┐├─┤└─┐ │ │├─┤│││  ╚═╗│├┤ ├┬┘├┬┘├─┤   ║║║││ ┬│ │├┤ │     ║║│├─┤┌─┘ 
// ═╩╝┴ ┴┘└┘┴└─┘┴─┘┴ ┴  ╩╚═└─┘└┘┴ ┴└─┘┘  ╚═╝└─┘└─┘┴ ┴└─┘ ┴ ┴┴ ┴┘└┘  ╚═╝┴└─┘┴└─┴└─┴ ┴  ┘╩ ╩┴└─┘└─┘└─┘┴─┘  ═╩╝┴┴ ┴└─┘o
// ____________________________________________________________________________________________________________________
//
