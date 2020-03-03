# TALLER

El **objetivo** general de este taller es desarrollar conocimientos básicos en electrónica. Aprendiendo conocimientos de microcontroladores, sensores y protocolos de comunicaciones. Para ello se desarrollará paso a paso la configuración de un dispositivo capaz de medir aceleración, velocidad, temperatura y enviar los datos a través de un WiFi.

Los materiales necesarios son:<br/>
-Computador con Arduino IDE instalado. <br/>
-NodeMCU (ESP8266).<br/>
-MPU6050.<br/>
-Protoboard.<br/>
-Cable (Jumpers).<br/>


   
   
### Conceptos Claves:
- **Microcontrolador**: Los microcontroladores son circuitos integrados que en su interior contienen una unidad central de procesamiento (CPU), unidades de memoria RAM y ROM, periféricos y puertos de entrada y salida. Todo microcontrolador requiere de un programa para realizar una función específica, el cual se almacena en la memoria ROM. El propósito general de los microcontroladores es el de leer y ejecutar los programas que escribe el usuario. En este orden de ideas, las aplicaciones de los microcontroladores son innumerables: es común encontrar microcontroladores en campos como la robótica, automatización, telecomunicaciones, en la industria del entretenimiento, entre otros. 

- **NodeMCU**: es una tarjeta de desarrollo similar a Arduino, especialmente orientada al Internet de las cosas (IoT). Está basado en el SoC (System on Chip) ESP8266, un chip altamente integrado, diseñado para las necesidades de un mundo conectado. Integra un potente procesador con Arquitectura de 32 bits (más potente que el Arduino Due) y conectividad Wifi. Al trabajar dentro del entorno Arduino podremos utilizar un lenguaje que ya conocemos y hacer uso de un IDE sencillo de utilizar, además de hacer uso de toda la información sobre proyectos y librerías disponibles en internet. La tarjeta NodeMCU está diseñada especialmente para trabajar en protoboard. Posee un regulador de voltaje en placa que le permite alimentarse directamente del puerto USB. Los pines de entradas/salidas trabajan a 3.3V. El chip CP2102 se encarga de la comunicación USB-Serial.
![Microcontrolador](/images/esp.png)
![](/images/esquema.png)

- **Arduino IDE**: La programación del NodeMCU se realiza a través del programa Arduino IDE, que se encuentra disponible para la descarga [aquí](https://www.arduino.cc/en/Main/Software) . Se debe seleccionar entre los sistemas operativos disponibles y después JUST DOWNLOAD para inicial la descarga

- **Comunicación Serial**: Las comunicaciones seriales son una manera muy básica de transmitir información, que se basa en transmitir un bit (HIGH o LOW) a la vez. Gran cantidad de dispositivos utilizan comunicación serial, ya que permite transmitir pequeñas cantidades de información de manera eficiente. A este tipo de transición también se le conoce en la literatura como UART, y se puede identificar por los pines RX (recepción) y TX (transmisión) que tienen los dispositivos que la usan. A continuación se muestra el esquema de conexiones utilizado para comunicación serial entre dos dispositivos: 
![Conexiones para comunicación seria entre dispositivos](/images/serial.png)
<br/>
    
