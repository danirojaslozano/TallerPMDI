# TALLER

El **objetivo** general de este taller es desarrollar conocimientos básicos en electrónica. Aprendiendo conocimientos de microcontroladores, sensores y protocolos de comunicaciones. Para ello se desarrollará paso a paso la configuración de un dispositivo capaz de medir aceleración, velocidad, temperatura y enviar los datos a través de un WiFi.

Los materiales necesarios son:<br/>
-Computador con Arduino IDE instalado. <br/>
-NodeMCU (ESP8266).<br/>
-MPU6050.<br/>
-Protoboard.<br/>
-Cable (Jumpers).<br/>

Para el desarrollo del taller se proponen 3 etapas, cada una de ellas tiene una carpeta con las instrucciones y el material extra necesario para desarrollarlo:
1. Aprendiendo de Microcontroladores y conexiones.
2. Sensor de aceleración y velocidad.
3. Conección WiFi servidor. 
   
   
### Conceptos Claves:
- **Microcontrolador**: Los microcontroladores son circuitos integrados que en su interior contienen una unidad central de procesamiento (CPU), unidades de memoria RAM y ROM, periféricos y puertos de entrada y salida. Todo microcontrolador requiere de un programa para realizar una función específica, el cual se almacena en la memoria ROM. El propósito general de los microcontroladores es el de leer y ejecutar los programas que escribe el usuario. En este orden de ideas, las aplicaciones de los microcontroladores son innumerables: es común encontrar microcontroladores en campos como la robótica, automatización, telecomunicaciones, en la industria del entretenimiento, entre otros. 

- **NodeMCU**: es una tarjeta de desarrollo similar a Arduino, especialmente orientada al Internet de las cosas (IoT). Está basado en el SoC (System on Chip) ESP8266, un chip altamente integrado, diseñado para las necesidades de un mundo conectado. Integra un potente procesador con Arquitectura de 32 bits (más potente que el Arduino Due) y conectividad Wifi. Al trabajar dentro del entorno Arduino podremos utilizar un lenguaje que ya conocemos y hacer uso de un IDE sencillo de utilizar, además de hacer uso de toda la información sobre proyectos y librerías disponibles en internet. La tarjeta NodeMCU está diseñada especialmente para trabajar en protoboard. Posee un regulador de voltaje en placa que le permite alimentarse directamente del puerto USB. Los pines de entradas/salidas trabajan a 3.3V. El chip CP2102 se encarga de la comunicación USB-Serial.<br/>
  
![Microcontrolador](/images/esp.png) ![](/images/esquema.png)
 <br/>

- **Arduino IDE**: La programación del NodeMCU se realiza a través del programa Arduino IDE, que se encuentra disponible para la descarga [aquí](https://www.arduino.cc/en/Main/Software) . Se debe seleccionar entre los sistemas operativos disponibles y después JUST DOWNLOAD para inicial la descarga

- **Comunicación Serial**: Las comunicaciones seriales son una manera muy básica de transmitir información, que se basa en transmitir un bit (HIGH o LOW) a la vez. Gran cantidad de dispositivos utilizan comunicación serial, ya que permite transmitir pequeñas cantidades de información de manera eficiente. A este tipo de transición también se le conoce en la literatura como UART, y se puede identificar por los pines RX (recepción) y TX (transmisión) que tienen los dispositivos que la usan. A continuación se muestra el esquema de conexiones utilizado para comunicación serial entre dos dispositivos: <br/>

![Conexiones para comunicación seria entre dispositivos](/images/serial.png)
<br/>

-**MPU6050**: es una unidad de medición inercial o IMU (Inertial Measurment Units) de 6 grados de libertad (DoF) pues combina un acelerómetro de 3 ejes y un giroscopio de 3 ejes. Lo cual significa que es un dispositivo capaz de medir la fuerza de la aceleración y velocidad. Opera con 3.3 voltios, aunque algunas versiones llevan un regulador que permite conectarla a 5V. Utiliza el protocolo de comunicación I2C, esto le permite trabajar con los microcontroladores, tales como Arduino o el NodeMCU. Tiene 8 pines de conexión: INT, AD0, XCL, XDA, SDA, SCL, GND, VCC.

<br/> ![Sensor](/images/mpu.png)<br/>
   
-**Protocolo I2C**: El estándar (Inter-Integrated Circuit) fue desarrollado por Philips en 1982 para la comunicación interna de dispositivos electrónicos en sus artículos. Posteriormente fue adoptado progresivamente por otros fabricantes hasta convertirse en un estándar del mercado. El bus I2C requiere únicamente dos cables para su funcionamiento, uno para la señal de reloj (CLK) y otro para el envío de datos (SDA). En general, cada dispositivo conectado al bus debe tener una dirección única. Si tenemos varios dispositivos similares tendremos que cambiar la dirección o, en caso de no ser posible, implementar un bus secundario. El bus I2C tiene una arquitectura de tipo maestro-esclavo. El dispositivo maestro inicia la comunicación con los esclavos, y puede mandar o recibir datos de los esclavos. Los esclavos no pueden iniciar la comunicación (el maestro tiene que preguntarles), ni hablar entre si directamente.  El bus I2C es síncrono. El maestro proporciona una señal de reloj, que mantiene sincronizados a todos los dispositivos del bus. De esta forma, se elimina la necesidad de que cada dispositivo tenga su propio reloj, de tener que acordar una velocidad de transmisión y mecanismos para mantener la transmisión sincronizada (como en UART).
<br/> ![I2C](/images/i2c.png)<br/>

-**IP**: (Internet Protocol) Es un protocolo de comunicaciones que se encarga de establecer la comunicación través de la red. Para esto, a cada dispositivo se le asigna una especie de matrícula o nombre conocido como dirección IP que le permite ser llamado e identificarse con los otros dispositivos. “Es la manera que tiene el Internet de saber quién es quién”. Cada vez que se escribe una dirección como por ejemplo www.google.com el navegador debe traducir ese texto a una dirección IP con el fin de poder conectarse a la página deseada. Una dirección IP se compone de un numero de 32 bits dividido en 4 grupos cada uno de 8 bits, es por esta razón que cada número solo puede variar entre 0 y 255. Existe 2 tipos de IP: <br/>
	-IP publica: Dirección que se asigna a un usuario o dispositivo en toda la red.
	-IP privada: Dirección de los dispositivos dentro de una red especifica.<br/>
Es posible que se duplique, o que dos dispositivos tengan la misma IP privada siempre y cuando la red en la que se encuentren sea diferente. Por el contrario, no es posible encontrar dos dispositivos con la misma IP pública. <br/>

-**WiFi**: Es una tecnología utilizada en la creación de redes de área local de manera inalámbrica. En la cual se reciben los datos de Internet para luego ser convertidos a ondas de radio, que son emitidas por un router. Seguido a esto, un dispositivo que logra capturarlas tiene la capacidad de iniciar una solicitud de descarga para después decodificarlas en información. Siendo así, una red WiFi es una manera de realizar una unión entra una red de datos fija con diferentes dispositivos inalámbricos. Debido a que el método de transmisión se basa en ondas de radio, es común ver que las redes puedan sufrir de interferencia por equipos electrónicos o inclusive otras redes WiFi que se encuentren cercanas. También al ser una red inalámbrica puede llegar a presentar menores velocidad y una mayor dificultad para garantizar su seguridad. Pero, por otro lado, brinda una mayor simplicidad en su uso, nos se requiere de cableado, hay una gran compatibilidad entre dispositivos y hay posibilidad de tener un acceso simultaneo a múltiples dispositivos.

-**UDP**: (User Datagram protocol) Es un protocolo de transporte de información dentro de las redes IP. Su importancia radica en la velocidad que ofrece en el momento de realizar transmisiones de datos, la cual se da de manera rápida, al no necesitar que se haya establecido previamente una conexión entre el emisor y el receptor. Basta con solo indicar la dirección IP de destino. A pesar de esto, el protocolo no esta en la capacidad de garantizar el orden de los paquetes enviados ni la seguridad y la integridad de los paquetes de datos. Es por esto por lo que unos de sus principales usos es la transmisión de video o de audio en tiempo real, pues no hay tiempo de enviar de nuevo paquetes perdidos cuando se esta escuchando o grabando a alguien. En estos casos, la importancia radica en transmitir la información lo más rápido posible. Existen otros tipos de protocolos como por ejemplo TCP, que se orienta por direcciones y manejan un mayor orden en su transmisión. Cada vez que se envía una secuencia de información se recibe la misma secuencia con el fin de retransmitir las partes que se hayan perdido o reorganizar el mensaje en caso de ser necesario. Siendo así este tipo de protocolo es útil para aplicaciones que requieren harta confiabilidad pero que a su vez tienen un tiempo de transición menos crítico.

