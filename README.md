# Generatively Scrambling Sylvia Plath's Poetry With An Arduino ESP-32

For my first project with my ESP-32, I wanted to combine my dual loves of poetry and programming. To do this, I wrote a simple program that prints the text of Sylvia Plath’s “Mad Girl’s Love Song”– but there’s a twist. The device first prints the text in its correct order, and then prints a scrambled version of the poem. This jumbling of Plath’s carefully curated words symbolizes her descent into madness through her life and through this poem, ultimately leading to her tragic death. By using the random number generator in \<cstdlib\>, the device creates a unique randomization of the lines each time it runs. 

If you’re new to the world of embedded systems and looking for a fun and creative way to start, this simple Arduino project is a great way to dip your toes in and learn the basics. Learn how to try this project out for yourself below!

[View this project on my website](https://catherine-o-brien.github.io/scrambled-poetry)

<!--more-->

## MATERIALS

* **Arduino ESP-32 TTGO T-display** [like this one](https://www.amazon.com/LILYGO-T-Display-Arduino-Development-CH9102F/dp/B099MPFJ9M)
* **USB-C cord** (make sure that your cord support data transfer, not just power!) [see more about this here](https://www.dignited.com/50330/usb-data-cable-vs-usb-charging-cable/)
* **Arduino IDE** [download here](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE) 


## STEPS

### 1. Turning ESP-32 on
I used a USB-C cable connected to my laptop to power my ESP-32. If your device doesn’t seem to be working, you might try flipping your USB-C cable over and reinserting it.You may also use a 5V lithium battery. 

### 2. Flashing example code to ESP-32
To flash code onto my ESP-32, I downloaded the Arduino IDE, available [here](https://www.arduino.cc/en/software). 

If you're using a Mac and running Big Sur or above, you may need to download [this driver](http://www.wch-ic.com/downloads/CH341SER_MAC_ZIP.html). 

I opened the IDE and selected in the dropdown menu the port where my ESP-32 was connected.

My goal here was to flash example code to ensure that my device was working properly. To do that, I used the default example codes installed into the IDE. To access those, I looked through the menu to find File → Examples → TFT_eSPI → 160 x 128. I used Pong_v3. 

To flash this code to my device, I pushed the right-facing arrow in the upper left corner. 

When the code had successfully compiled and written to the ESP-32, my device displayed the Pong game. Once the code has been flashed onto the ESP-32, it will not need to be plugged into your computer to run– whenever your ESP-32 is plugged into power, it will run that code. 

### 3. My code 
Arduinos use a programming language based on C++, which means that C++ code will run in this IDE. 

For my project, I wrote a program in C++ that displayed the text of Sylvia Plath’s poem “Mad Girl’s Love Song” once correctly, and then once jumbled. 

I used the library <TFT_eSPI.h>, which includes graphics and the font library for the ST7735 driver chip. My code invokes that library using this line: 
``` TFT_eSPI tft = TFT_eSPI(). ```

I hardcoded the text of the poem and the number of lines into the code like so: 
```
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
```

The core loop of the program tells the ESP-32 to alternate between running the correct title sequence and poem text, and the scrambled title sequence and poem text:

```
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
```

To print the poem's text correctly, the program first clears the screen by filling it with the background color TFT_CYAN. Then, it iterates through the array of the poems lines, printing 2 at a time in order to fit them on the small screen of the ESP-32. The delay() function tells the ESP-32 to wait before executing the next operation so that there is time for the viewer to actually read the text on the screen. 

```
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
```

To print the scrambled version of the poem's text, I used the random number generator included in <cstdlib>. It clears the screen by filling it with the background color TFT_CYAN. Next, the program gets 2 random numbers that are smaller than the size of the array, and prints the lines of the poem to which those numbers index. It completes this process as many times as there are lines in the poem. Once again, I used the delay() function to provide ample time for the viewer to read the text of the poem before the ESP-32 moves on to the next operation. 
  
```
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
```

## CREDITS

I completed this project for Module 1 of Mark Santolucito’s Creative Embedded Systems course at Barnard College. See more about the assignment and his work on his website [here](http://www.marksantolucito.com/COMS3930/spring2023/mod1)!
