# Aprendiendo de sensores: Acelererómetro y Giroscopio.
El **objetivo** es aprender a utilizar un acelerómetro (MPU6050), identificar cada una de las señales de los ejes, y mostrarlas en el serial. Para ello:
1. Realizar la sesión práctica, donde será necesario instalar la libreria MPUandes.
<br>

Cuando haya verificado el funcionamiento completo de la sesión práctica pasar a la Etapa 3.

### Conceptos claves:

-**MPU6050**: es una unidad de medición inercial o IMU (Inertial Measurment Units) de 6 grados de libertad (DoF) pues combina un acelerómetro de 3 ejes y un giroscopio de 3 ejes. Lo cual significa que es un dispositivo capaz de medir la fuerza de la aceleración y velocidad. Opera con 3.3 voltios, aunque algunas versiones llevan un regulador que permite conectarla a 5V. Utiliza el protocolo de comunicación I2C, esto le permite trabajar con los microcontroladores, tales como Arduino o el NodeMCU. Tiene 8 pines de conexión: INT, AD0, XCL, XDA, SDA, SCL, GND, VCC.

<br/> ![Sensor](/images/mpu.png)<br/>
   
-**Protocolo I2C**: El estándar (Inter-Integrated Circuit) fue desarrollado por Philips en 1982 para la comunicación interna de dispositivos electrónicos en sus artículos. Posteriormente fue adoptado progresivamente por otros fabricantes hasta convertirse en un estándar del mercado. El bus I2C requiere únicamente dos cables para su funcionamiento, uno para la señal de reloj (CLK) y otro para el envío de datos (SDA). En general, cada dispositivo conectado al bus debe tener una dirección única. Si tenemos varios dispositivos similares tendremos que cambiar la dirección o, en caso de no ser posible, implementar un bus secundario. El bus I2C tiene una arquitectura de tipo maestro-esclavo. El dispositivo maestro inicia la comunicación con los esclavos, y puede mandar o recibir datos de los esclavos. Los esclavos no pueden iniciar la comunicación (el maestro tiene que preguntarles), ni hablar entre si directamente.  El bus I2C es síncrono. El maestro proporciona una señal de reloj, que mantiene sincronizados a todos los dispositivos del bus. De esta forma, se elimina la necesidad de que cada dispositivo tenga su propio reloj, de tener que acordar una velocidad de transmisión y mecanismos para mantener la transmisión sincronizada (como en UART).
<br/> ![I2C](/images/i2c.png)<br/>
