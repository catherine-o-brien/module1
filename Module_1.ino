/*  
 Test the tft.print() viz embedded tft.write() function

 This sketch used font 2, 4, 7
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 Note that yield() or delay(0) must be called in long duration for/while
 loops to stop the ESP8266 watchdog triggering.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */


#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include <cstdlib>
#include <iostream>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

char* lines[] = {
    "I shut my eyes and all the world drops dead;", 
    "I lift my lids and all is born again.",
    "I shut my eyes and all the world drops dead;",
    "I lift my lids and all is born again.",
    "(I think I made you up inside my head.)",
    "The stars go waltzing out in blue and red,",
    "And arbitrary blackness gallops in:",
    "I shut my eyes and all the world drops dead.",
    "I dreamed that you bewitched me into bed",
    "And sung me moon-struck, kissed me quite insane.",
    "(I think I made you up inside my head.)",
    "God topples from the sky, hell's fires fade:",
    "Exit seraphim and Satan's men:",
    "I shut my eyes and all the world drops dead.",
    "I fancied you'd return the way you said,",
    "But I grow old and I forget your name.",
    "(I think I made you up inside my head.)",
    "I should have loved a thunderbird instead;",
    "At least when spring comes they roar back again.",
    "I shut my eyes and all the world drops dead.",
    "(I think I made you up inside my head.)"
};
int num_lines = 21;

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  
  // Fill screen with grey so we can see the effect of printing with and without 
  // a background colour defined
  tft.fillScreen(TFT_CYAN);
  
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'tft.println'
  //  or stay on the line is there is room for the text with tft.print)
  tft.setCursor(0, 0, 2);
 
  
  // Set the font colour to be black with no background, set to font 7
  tft.setTextColor(TFT_BLACK); tft.setTextFont(4);

  title_sequence();
  original_poem();
  
  title_sequence_jumbled();
  poem_jumbled();

}

//Print the title sequence
void title_sequence(){
    tft.fillScreen(TFT_CYAN);
    tft.setCursor(0,0); 
    tft.setTextFont(4);
    tft.println("MAD GIRL'S"); 
    tft.println("LOVE SONG");
    delay(1000);
    tft.setTextFont(4);
    tft.println("");
    tft.println("BY SYLVIA PLATH");
    delay(6000);
}

//Print the title sequence jumbled
void title_sequence_jumbled(){
    tft.fillScreen(TFT_CYAN);
    tft.setCursor(0,0); 
    tft.setTextFont(4);
    tft.println("MaD soNg'S"); 
    tft.println("gIrL LoV3");
    delay(1000);
    tft.setTextFont(4);
    tft.println("");
    tft.println("by LiAtH sp1AvY <3");
    delay(6000);
}

//Print the poem in the correct order
void original_poem(){
  int i = 0;
  while (i < num_lines) {
    tft.fillScreen(TFT_CYAN);
    tft.setCursor(0,0); 
    tft.println(lines[i]);
    i++;
    if (i < num_lines) {
      delay(2000);
      tft.println(lines[i]);
      i++;
    };
    delay(2000);
  }
  tft.fillScreen(TFT_CYAN);
  delay(1000);
}

//Print the poem out of order with a random number generator
void poem_jumbled(){
  int i = 0;

  while (i < num_lines) {
    int rand_1 = rand() % num_lines; 
    int rand_2 = rand() % num_lines;
    tft.fillScreen(TFT_CYAN);
    tft.setCursor(0,0); 
    tft.println(lines[rand_1]);
    i++;
    if (i < num_lines) {
      delay(2000);
      tft.println(lines[rand_2]);
      i++;
    };
    delay(2000);
  }
}



