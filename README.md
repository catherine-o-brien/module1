For my first project with my ESP32, I wanted to combine my dual loves of poetry and programming. To do this, I wrote a simple program that prints the text of Sylvia Plath’s “Mad Girl’s Love Song”– but there’s a twist. The device first prints the text in its correct order, and then prints a scrambled version of the poem. This jumbling of Plath’s carefully curated words symbolizes her descent into madness through her life and through this poem, ultimately leading to her tragic death. By using the random number generator in \<cstdlib\>, the device creates a unique randomization of the lines each time it runs. 

If you’re new to the world of embedded systems and looking for a fun and creative way to start, this simple Arduino project is a great way to dip your toes in and learn the basics. Learn how to try this project out for yourself below!


<!--more-->

# MATERIALS

* **Arduino ESP-32 TTGO T-display** [like this one](https://www.amazon.com/LILYGO-T-Display-Arduino-Development-CH9102F/dp/B099MPFJ9M)
* **USB-C cord** (make sure that your cord support data transfer, not just power!) [see more about this here](https://www.dignited.com/50330/usb-data-cable-vs-usb-charging-cable/)
* **Arduino IDE** [download here](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE) 


# STEPS

## 1. Turning ESP-32 on
I used a USB-C cable connected to my laptop to power my ESP-32. If your device doesn’t seem to be working, you might try flipping your USB-C cable over and reinserting it.You may also use a 5V lithium battery. 

## 2. Flashing example code to ESP-32
To flash code onto my ESP-32, I downloaded the Arduino IDE, available [here](https://www.arduino.cc/en/software). 

If you're using a Mac and running Big Sur or above, you may need to download [this driver](http://www.wch-ic.com/downloads/CH341SER_MAC_ZIP.html). 

I opened the IDE and selected in the dropdown menu the port where my ESP-32 was connected.

My goal here was to flash example code to ensure that my device was working properly. To do that, I used the default example codes installed into the IDE. To access those, I looked through the menu to find File → Examples → TFT_eSPI → 160 x 128. I used Pong_v3. 

To flash this code to my device, I pushed the right-facing arrow in the upper left corner. 

When the code had successfully compiled and written to the ESP-32, my device displayed the Pong game. Once the code has been flashed onto the ESP-32, it will not need to be plugged into your computer to run– whenever your ESP-32 is plugged into power, it will run that code. 

## 3. Writing original code
Arduinos use a programming language based on C++, which means that C++ code will run in this IDE. 

For my project, I wrote a program in C++ that displayed the text of Sylvia Plath’s poem “Mad Girl’s Love Song” once correctly, and then once jumbled. 

# CREDITS

I completed this project for Module 1 of Mark Santolucito’s Creative Embedded Systems course at Barnard College. See more about the assignment and his work on his website [here](http://www.marksantolucito.com/COMS3930/spring2023/mod1)!
