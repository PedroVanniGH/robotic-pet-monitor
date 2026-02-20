   #include <SoftwareSerial.h> 
 
 
 
  int m1a = 10;  // Motor 1, pin 10 del Arduino va al pin 15 del L293B. 
 
  int m1b = 9;   // Motor 1, pin 9 del Arduino va al pin 10 del L293B. 
 
  int m2a = 12;  // Motor 2, pin 12 del Arduino va al pin 2 del L293B. 
 
  int m2b = 11;  // Motor 2, pin 11 del Arduino va al pin 7 del L293B. 
 
  char val; 
 
 
 
  // Configura la comunicación serial con el HC-06 
 
  SoftwareSerial BTSerial(2, 3); // RX, TX 
 
 
 
  void setup()  
 
  {   
    delay(1000);
 
    pinMode(m1a, OUTPUT); 
 
    pinMode(m1b, OUTPUT); 
 
    pinMode(m2a, OUTPUT); 
 
    pinMode(m2b, OUTPUT); 
 
     
 
    Serial.begin(9600);    // Serial para la comunicación normal 
 
    BTSerial.begin(9600);  // Serial para la comunicación Bluetooth 
 
  } 
 
 
 
  void loop() 
 
  { 
 
    if (BTSerial.available() > 0)  // Verifica si hay datos disponibles del Bluetooth
    { 
        val = BTSerial.read();       // Lee el carácter recibido
        Serial.println(val);         // Imprime el valor en el monitor serial
    } 
 
    // Control de motores basado en el comando recibido
    if (val == 'F')  // Hacia adelante
    { 
        digitalWrite(m1a, LOW);  // Motor 1 adelante
        digitalWrite(m1b, HIGH);   
        digitalWrite(m2a, HIGH);  // Motor 2 adelante
        digitalWrite(m2b, LOW);   
    } 
    else if (val == 'B')  // Hacia atrás
    { 
        digitalWrite(m1a, HIGH);   // Motor 1 atrás
        digitalWrite(m1b, LOW);  
        digitalWrite(m2a, LOW);   // Motor 2 atrás
        digitalWrite(m2b, HIGH);  
    } 
    else if (val == 'L')  // Izquierda
    { 
        digitalWrite(m1a, LOW);   // Motor 1 detenido
        digitalWrite(m1b, LOW);   
        digitalWrite(m2a, HIGH);  // Motor 2 adelante
        digitalWrite(m2b, LOW);   
    } 
    else if (val == 'R')  // Derecha
    { 
        digitalWrite(m1a, LOW);  // Motor 1 adelante
        digitalWrite(m1b, HIGH);   
        digitalWrite(m2a, LOW);   // Motor 2 detenido
        digitalWrite(m2b, LOW);   
    } 
    else if (val == 'S')  // Stop - Carrito detenido
    { 
        digitalWrite(m1a, LOW);   
        digitalWrite(m1b, LOW);   
        digitalWrite(m2a, LOW);   
        digitalWrite(m2b, LOW);   
    } 
 
  } 


