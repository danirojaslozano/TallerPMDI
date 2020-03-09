#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


#define     LED0      D1
#define     LED1      D2
const char* ssid = "ProyectoAgrosavia1";
const char* password = "agrosavia";
int Id_client = 1; //Identificación del cliente
int p = 0; //Indicador de cada dato (paquete) enviado
int contconexion = 0;
WiFiUDP     Udp;

#include <MPUandes.h>
const int scl = D6;
const int sda = D7;

int AccelScaleFactor = 2048;
int GyroScaleFactor = 131;

MPUandes acelerometro = MPUandes(sda, scl);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(sda, scl);
  delay(100);
  acelerometro.MPU6050_Init();
  delay(2000);
  // Setting The Mode Of Pins
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);

  WiFi.mode(WIFI_STA); //para que no inicie el SoftAP en el modo normal
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED and contconexion < 50) //Cuenta hasta 50 si no se puede conectar lo cancela
  {
    ++contconexion;
    delay(250);
    Serial.print(".");
    digitalWrite(LED0, HIGH); //El led de la board parpadea mientras intenta conectar a la red
    delay(250);
    digitalWrite(LED0, LOW);
  }
  if (contconexion < 50)
  {
    //Se está usando el código con IP dinámica por problemas con la ip fija. (funciona igualmente bien con IP dinámica)
    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.gatewayIP());
    digitalWrite(LED0, HIGH);  //El led se queda predido si se conecta a la red
  }
  else
  {
    Serial.println("");
    Serial.println("Error de conexion");
    digitalWrite(LED0, LOW);
  }

}
int Ax1, Ay1, Az1, Gx1, Gy1, Gz1;
double Ax, Ay, Az, Gx, Gy, Gz;
String msg = "";
void loop() {
  Ax1 = (int)acelerometro.Read_Ax();
  Ay1 = (int)acelerometro.Read_Ay();
  Az1 = (int)acelerometro.Read_Az();
  Gx1 = (int)acelerometro.Read_Gx( );
  Gy1 = (int)acelerometro.Read_Gy( );
  Gz1 = (int)acelerometro.Read_Gz();
  //divide each with their sensitivity scale factor
  Ax = (double)Ax1 / AccelScaleFactor;
  Ay = (double)Ay1 / AccelScaleFactor;
  Az = (double)Az1 / AccelScaleFactor;
  Gx = (double)Gx1 / GyroScaleFactor;
  Gy = (double)Gy1 / GyroScaleFactor;
  Gz = (double)Gz1 / GyroScaleFactor;

  Serial.print("Ax: "); Serial.print(Ax);
  Serial.print(" Ay: "); Serial.print(Ay);
  Serial.print(" Az: "); Serial.print(Az);
  Serial.print(" Gx: "); Serial.print(Gx);
  Serial.print(" Gy: "); Serial.print(Gy);
  Serial.print(" Gz: "); Serial.println(Gz);

  Udp.beginPacket("192.168.0.103", 9001);  //// Esta ip es la ip del computador servidor y el puerto debe coincidir
  digitalWrite(LED1, HIGH);
  msg = String(Ax) + "#" + String(Ay) + "#" + String(Az) + "#" + String(Gx) + "#" + String(Gy) + "#" + String(Gz) + "#" + String(Id_client) + "#" + String(p); //El mensaje completo contiene el id del cliente y el numero de paquete enviado
  for (int i = 0; i < msg.length(); i++)
  {
    int old = micros();
    Udp.write(msg[i]);
    while (micros() - old < 87);
  }

  Udp.endPacket();
  digitalWrite(LED1, LOW);

  p = p + 1;
  delay(2000);
}
