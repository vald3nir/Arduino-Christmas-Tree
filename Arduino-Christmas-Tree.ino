#include <Adafruit_NeoPixel.h>

// Configurações do NeoPixel
#define PIN 6         // Pino do Arduino conectado ao anel de LEDs
#define NUMPIXELS 24  // Número de LEDs no anel

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Variáveis de animação
int delayTime = 100;  // Delay entre as atualizações (em milissegundos)

// Funções para os efeitos
void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

void theaterChase(uint32_t color, int wait) {
  for (int j = 0; j < 10; j++) {  // Repetir a animação 10 vezes
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i += 3) {
        strip.setPixelColor(i + q, color);  // Liga o LED
      }
      strip.show();
      delay(wait);
      for (int i = 0; i < strip.numPixels(); i += 3) {
        strip.setPixelColor(i + q, 0);  // Apaga o LED
      }
    }
  }
}

void rainbow(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

void setup() {
  strip.begin();
  strip.show();  // Inicializa todos os LEDs apagados
}

void loop() {
  // Efeito: Pisca todas as cores
  colorWipe(strip.Color(255, 0, 0), delayTime);  // Vermelho
  colorWipe(strip.Color(0, 255, 0), delayTime);  // Verde
  colorWipe(strip.Color(0, 0, 255), delayTime);  // Azul

  // Efeito: Teatro
  theaterChase(strip.Color(127, 127, 127), 50);  // Branco
  theaterChase(strip.Color(127, 0, 0), 50);      // Vermelho
  theaterChase(strip.Color(0, 0, 127), 50);      // Azul

  // Efeito: Arco-íris
  rainbow(20);
}
