#include <Esplora.h>
#include <TFT.h>  // Librería para manejar la pantalla TFT

#define BUZZER_PIN 5

TFT screen = TFT();

void setup() {
  screen.begin();
  screen.background(0, 0, 0);  // Pantalla en negro
  pinMode(BUZZER_PIN, OUTPUT);
  screen.stroke(255, 255, 255);  // Color blanco
  screen.setTextSize(2);
  screen.text("Esperando sonido...", 10, 10);
}

void loop() {
  int micValue = Esplora.readMicrophone();
  
  if (micValue > 50) {
    tone(BUZZER_PIN, 1000, 200);  // Frecuencia de 1000Hz durante 200ms
    screen.background(0, 0, 255);  // Cambiar el fondo a azul
    screen.stroke(255, 255, 255);
    screen.setTextSize(2);
    screen.text("Sonido detectado!", 10, 40);
    delay(1000);  // Esperar un segundo
    screen.background(0, 0, 0);  // Volver al fondo negro
    screen.text("Esperando sonido...", 10, 10);
  }
}
