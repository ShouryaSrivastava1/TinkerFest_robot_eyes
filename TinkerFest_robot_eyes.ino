#include <Adafruit_NeoPixel.h>

#define LED_PIN     3           // Data pin connected to the NeoPixel matrix
#define MATRIX_WIDTH  6        // Width of the matrix
#define MATRIX_HEIGHT 7        // Height of the matrix
#define NUM_LEDS    (MATRIX_WIDTH * MATRIX_HEIGHT)

Adafruit_NeoPixel matrix = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int eye_closed_first_frame_num[] = {1,2,3,4,5, 6, 36,37,38,39,40,41,42};
int eye_closed_second_frame_num[] = {7,8,9,10,11,12, 30,31,32,33,34,35};
int eye_closed_third_frame_num[] = {13,14,15,16,17,18,25,26,27,28, 29};
int eyes_cross_ver_num[] = {3, 4, 9, 10, 15, 16, 17, 20, 21, 22, 27, 28, 33,34, 39, 40};
int eyes_cross_hor_num[] = {13,14, 18, 19,20,24,25, 26, 17, 23, 29, 30};


void Startup()
{
  int i = 0;
  int speed_mul = 1;
  int index = 0;

  bool s = true;
  bool a = true;
  while(NUM_LEDS - index > -10){
  matrix.setPixelColor(i, matrix.Color(255,0,0));
  matrix.show();
  delay(100 / speed_mul);
  float sped = 100 / speed_mul;
  i++;
  
  if(i + 1 % 3 != 0)
  {
    matrix.setPixelColor(i - 3, matrix.Color(0,0,0));
    // matrix.setPixelColor(NUM_LEDS - 1, matrix.Color(0,0,0));
    matrix.show();
  }
  if(i > NUM_LEDS - index)
  {
    speed_mul++;
    i = 0;
    if(speed_mul > 20) speed_mul = 20;
    index++;
    matrix.setPixelColor(NUM_LEDS - index, matrix.Color(255,0,0));
    matrix.show();
    // Serial.println(NUM_LEDS - index);
  }
  if(a){
    if(NUM_LEDS - index < -1)
    {
      if(s)
      {
        for(int i = 0; i < 42; i++)
        {
          matrix.setPixelColor(i, matrix.Color(0,0,0));
        }
        matrix.show();
        delay(1000);
      }
      s = false;
      for(int b = 0; b < 255; b++)
      {
        for(int i = 0; i < 42; i++)
        {
          matrix.setPixelColor(i, matrix.Color(b,0,0));
        }
        matrix.show();
        delay(50);
      }
    a = false;
    }
  }
  }
}

void eyes_open_state()
{
  for (int i = 0; i < NUM_LEDS; i++) {
    matrix.setPixelColor(i - 1, matrix.Color(255,0,0));
  }
  matrix.show();
}

void make_cross()
{
for (int i = 0; i < NUM_LEDS; i++) {
    matrix.setPixelColor(i, matrix.Color(0, 0, 0));
  }
  for(int x = 0; x < sizeof(eyes_cross_hor_num) / sizeof(eyes_cross_hor_num[0]); x++)
  {
    matrix.setPixelColor(eyes_cross_hor_num[x] - 1, matrix.Color(255,0,0));
  }
  for(int y = 0; y < sizeof(eyes_cross_ver_num) / sizeof(eyes_cross_ver_num[0]); y++)
  {
    matrix.setPixelColor(eyes_cross_ver_num[y] - 1, matrix.Color(255,0,0));
  }

  matrix.show();
}
void Eyes_close_n_open()
{
  Eyes_close_first_frame();
  delay(50);
  Eyes_close_Second_frame();
  delay(50);
  Eyes_close_third_frame();
  delay(200);
  eyes_open_third_frame();
  delay(50);
  eyes_open_second_frame();
  delay(50);
  eyes_open_first_frame();
  delay(25);
 
}
void Eyes_close_first_frame() {
  // Set all pixels to black first

  // Set specific pixels for the closed eye effect
  for (int i = 0; i < sizeof(eye_closed_first_frame_num) / sizeof(eye_closed_first_frame_num[0]); i++) {
    matrix.setPixelColor(eye_closed_first_frame_num[i] - 1, matrix.Color(0,0,0));
  }
 
  matrix.show(); // Update the matrix display once after setting all the pixels
}
void Eyes_close_Second_frame() {
  // Set all pixels to black first

  // Set specific pixels for the closed eye effect
  for (int i = 0; i < sizeof(eye_closed_second_frame_num) / sizeof(eye_closed_second_frame_num[0]); i++) {
    matrix.setPixelColor(eye_closed_second_frame_num[i] - 1, matrix.Color(0,0,0));
  }
 
  matrix.show(); // Update the matrix display once after setting all the pixels
}

void Eyes_close_third_frame()
{
  for (int i = 0; i < sizeof(eye_closed_third_frame_num) / sizeof(eye_closed_third_frame_num[0]); i++) {
    matrix.setPixelColor(eye_closed_third_frame_num[i] - 1, matrix.Color(0,0,0));
  }
 
  matrix.show(); // Update the matrix display once after setting all the pixels
}

void eyes_open_first_frame()
{
  // Set specific pixels for the closed eye effect
  for (int i = 0; i < sizeof(eye_closed_first_frame_num) / sizeof(eye_closed_first_frame_num[0]); i++) {
    matrix.setPixelColor(eye_closed_first_frame_num[i] - 1, matrix.Color(255 ,0 ,0));
  }
 
  matrix.show(); // Update the matrix display once after setting all the pixels
}

void eyes_open_second_frame()
{
   // Set specific pixels for the closed eye effect
  for (int i = 0; i < sizeof(eye_closed_second_frame_num) / sizeof(eye_closed_second_frame_num[0]); i++) {
    matrix.setPixelColor(eye_closed_second_frame_num[i] - 1, matrix.Color(255,0,0));
  }
 
  matrix.show(); // Update the matrix display once after setting all the pixels
}

void eyes_open_third_frame()
{
  for (int i = 0; i < sizeof(eye_closed_third_frame_num) / sizeof(eye_closed_third_frame_num[0]); i++) {
    matrix.setPixelColor(eye_closed_third_frame_num[i] - 1, matrix.Color(255,0,0));
  }
 
  matrix.show(); // Update the matrix display once after setting all the pixels
}

void setup() {
  matrix.begin();
  matrix.setBrightness(255);  // Set the brightness (0-255)

  // Initialize all pixels to white
  for (int i = 0; i < NUM_LEDS; i++) {
    matrix.setPixelColor(i, matrix.Color(0, 0, 0));
  }
  matrix.show();
  eyes_open_state();
  delay(500);
}

void loop() {
  // Set pixels for the open eye effectopen();
  for(int i  = 0; i < 2; i++)
  {
    Eyes_close_n_open();
    delay(1000);
  }
  make_cross();
  delay(2000);

}