//     ____________________     __          __       ___   ____ ___   ____ 
//    /  _/  _/ ____/ ____/    / /   ____ _/ /_     |__ \ / __ \__ \ / __ \
//    / / / // __/ / __/      / /   / __ `/ __ \    __/ // / / /_/ // / / /
//  _/ /_/ // /___/ /___     / /___/ /_/ / /_/ /   / __// /_/ / __// /_/ / 
// /___/___/_____/_____/    /_____/\__,_/_.___/   /____/\____/____/\____/  
// ____________________________________________________________________________                                                                       
// Libreria MPUandes.h
// Autores: Daniela Rojas, Sebastian Sierra, Miguel Diaz.
// Lectura MPU6050 desde NodeMCU, utilizando I2C. 


#ifndef MPUandes_h
#define MPUandes_h

#include <Wire.h>
#include <Arduino.h>


class MPUandes
{
  public :
    MPUandes(int sda, int scl);
    void MPU6050_Init() ;
    int Read_Ax();
    int Read_Ay();
    int Read_Az();
    int Read_Gx();
    int Read_Gy();
    int Read_Gz();
    int Read_T();
    
  private:
    int sda;
    int scl;
    uint8_t deviceAddress;
    uint8_t regAddress;
    // MPU6050 few configuration register addresses
    uint8_t MPU6050_REGISTER_SMPLRT_DIV   ;
    uint8_t MPU6050_REGISTER_USER_CTRL    ;
    uint8_t MPU6050_REGISTER_PWR_MGMT_1   ;
    uint8_t MPU6050_REGISTER_PWR_MGMT_2   ;
    uint8_t MPU6050_REGISTER_CONFIG       ;
    uint8_t MPU6050_REGISTER_GYRO_CONFIG  ;
    uint8_t MPU6050_REGISTER_ACCEL_CONFIG ;
    uint8_t MPU6050_REGISTER_FIFO_EN      ;
    uint8_t MPU6050_REGISTER_INT_ENABLE   ;
    uint8_t MPU6050_REGISTER_ACCEL_XOUT_H ;
    uint8_t MPU6050_REGISTER_SIGNAL_PATH_RESET ;

    // MPU6050 Slave Device Address
    uint8_t MPU6050SlaveAddress;
    
    void I2C_Write(uint8_t deviceAddress, uint8_t regAddress, uint8_t data) ;

    int16_t AccelX, AccelY, AccelZ, Temperature, GyroX, GyroY, GyroZ;

};
#endif

// ____________________________________________________________________________________________________________________                                                                           
//
// ╔╦╗┌─┐┌┐┌┬┌─┐┬  ┌─┐  ╦═╗┌─┐ ┬┌─┐┌─┐   ╔═╗┌─┐┌┐ ┌─┐┌─┐┌┬┐┬┌─┐┌┐┌  ╔═╗┬┌─┐┬─┐┬─┐┌─┐   ╔╦╗┬┌─┐┬ ┬┌─┐┬    ╔╦╗┬┌─┐┌─┐ 
//  ║║├─┤││││├┤ │  ├─┤  ╠╦╝│ │ │├─┤└─┐   ╚═╗├┤ ├┴┐├─┤└─┐ │ │├─┤│││  ╚═╗│├┤ ├┬┘├┬┘├─┤   ║║║││ ┬│ │├┤ │     ║║│├─┤┌─┘ 
// ═╩╝┴ ┴┘└┘┴└─┘┴─┘┴ ┴  ╩╚═└─┘└┘┴ ┴└─┘┘  ╚═╝└─┘└─┘┴ ┴└─┘ ┴ ┴┴ ┴┘└┘  ╚═╝┴└─┘┴└─┴└─┴ ┴  ┘╩ ╩┴└─┘└─┘└─┘┴─┘  ═╩╝┴┴ ┴└─┘o
// ____________________________________________________________________________________________________________________
//
