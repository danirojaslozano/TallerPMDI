# Aprendiendo Conexiones WiFi y Sevidor
El **objetivo** es aprender a conectarse a un WiFi a través del ESP8266. Además enviar y recibir paquetes con protocolo UDP. Para ello:
1. Identificar SSID, pasword de la red WiFi a utilizar.
2. Conectar el computador a la red, y reconocer la IP asignada.
3. Realizar la sesión práctica.
4. Correr servidor, verificar funcionamiento.

Después de concluir esta etapa, el día uno del taller fue finalizado. 
Continuará...

### Conceptos claves:

-**IP**: (Internet Protocol) Es un protocolo de comunicaciones que se encarga de establecer la comunicación través de la red. Para esto, a cada dispositivo se le asigna una especie de matrícula o nombre conocido como dirección IP que le permite ser llamado e identificarse con los otros dispositivos. “Es la manera que tiene el Internet de saber quién es quién”. Cada vez que se escribe una dirección como por ejemplo www.google.com el navegador debe traducir ese texto a una dirección IP con el fin de poder conectarse a la página deseada. Una dirección IP se compone de un numero de 32 bits dividido en 4 grupos cada uno de 8 bits, es por esta razón que cada número solo puede variar entre 0 y 255. Existe 2 tipos de IP: <br/>
	-IP publica: Dirección que se asigna a un usuario o dispositivo en toda la red.
	-IP privada: Dirección de los dispositivos dentro de una red especifica.<br/>
Es posible que se duplique, o que dos dispositivos tengan la misma IP privada siempre y cuando la red en la que se encuentren sea diferente. Por el contrario, no es posible encontrar dos dispositivos con la misma IP pública. <br/>

-**WiFi**: Es una tecnología utilizada en la creación de redes de área local de manera inalámbrica. En la cual se reciben los datos de Internet para luego ser convertidos a ondas de radio, que son emitidas por un router. Seguido a esto, un dispositivo que logra capturarlas tiene la capacidad de iniciar una solicitud de descarga para después decodificarlas en información. Siendo así, una red WiFi es una manera de realizar una unión entra una red de datos fija con diferentes dispositivos inalámbricos. Debido a que el método de transmisión se basa en ondas de radio, es común ver que las redes puedan sufrir de interferencia por equipos electrónicos o inclusive otras redes WiFi que se encuentren cercanas. También al ser una red inalámbrica puede llegar a presentar menores velocidad y una mayor dificultad para garantizar su seguridad. Pero, por otro lado, brinda una mayor simplicidad en su uso, nos se requiere de cableado, hay una gran compatibilidad entre dispositivos y hay posibilidad de tener un acceso simultaneo a múltiples dispositivos.

-**UDP**: (User Datagram protocol) Es un protocolo de transporte de información dentro de las redes IP. Su importancia radica en la velocidad que ofrece en el momento de realizar transmisiones de datos, la cual se da de manera rápida, al no necesitar que se haya establecido previamente una conexión entre el emisor y el receptor. Basta con solo indicar la dirección IP de destino. A pesar de esto, el protocolo no esta en la capacidad de garantizar el orden de los paquetes enviados ni la seguridad y la integridad de los paquetes de datos. Es por esto por lo que unos de sus principales usos es la transmisión de video o de audio en tiempo real, pues no hay tiempo de enviar de nuevo paquetes perdidos cuando se esta escuchando o grabando a alguien. En estos casos, la importancia radica en transmitir la información lo más rápido posible. Existen otros tipos de protocolos como por ejemplo TCP, que se orienta por direcciones y manejan un mayor orden en su transmisión. Cada vez que se envía una secuencia de información se recibe la misma secuencia con el fin de retransmitir las partes que se hayan perdido o reorganizar el mensaje en caso de ser necesario. Siendo así este tipo de protocolo es útil para aplicaciones que requieren harta confiabilidad pero que a su vez tienen un tiempo de transición menos crítico.

