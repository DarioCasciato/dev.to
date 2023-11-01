And welcome back to a new article in the firmware 101 series! In this article we won't focus on how to do things, but more on with what to do things. I will list the best VS-Code extensions for embedded development. I will also list some other extensions that are not directly related to embedded development, but are very useful.

## Disclaimer

The Extensions that i will list are my personal favorites. These extensions are a must have for me and i use them in every project. I am not sponsored by any of the extension developers.

## Extensions

### [C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

This is the most important extension. It is developed by Microsoft and is the official C/C++ extension for VS-Code. It is a must have for embedded development. It provides IntelliSense, debugging, and code browsing capabilities. The IntelliSense aspect of this extension is the most important one. It provides code completion, parameter info, and member lists.

### [PlatformIO](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

If you are developing firmware for commonly used boards like Arduino, ESP8266 or ESP32, PlatformIO is a must have. This extension allows you to directly upload your code to the board and it also provides a serial monitor. It also has a library manager that allows you to easily add libraries to your project. PlatformIO also has a very nice feature called "Project Tasks". This allows you to run common tasks like building, uploading, cleaning, etc. with a single click. After you get comfortable with using PlatformIO, **you will never go back to the Arduino IDE**.

### [Error Lens](https://marketplace.visualstudio.com/items?itemName=usernamehw.errorlens)

The Error Lens extension is one of my favourite extension for VS-Code. Instead of showing errors with squiggly lines, it shows the error message directly on the codeline where the error is. Th error is more visible and you don't have to hover over the squiggly line to see the error message and save time.

### [Notes](https://marketplace.visualstudio.com/items?itemName=dionmunk.vscode-notes)

The Notes extension adds a new tab in the left sidebar. In this tab you can add general notes that are not related to a specific file. These Notes are markdown friendly and you can add links, images, etc. to them. I like to use it when i am working on a project and need to design the structure of the flash memory, or allocating pins for peripherals. e.g.:



### [GitHub Copilot](https://marketplace.visualstudio.com/items?itemName=GitHub.copilot)

Copilot is the only extension in this list that is a paid service. Copilot is a artifical intelligence that knows your workspace and gives you completions based on your code. It costs you 10$ a month but its worth it and it saves you a lot of time. here is an example of copilot in action in one of my newest projects:



Even if these are small snippets, over the project they save you a lot of time.


## Finale & your favourite extensions

These are my favourite extensions for VS-Code. I hope you found some new extensions that you can use in your projects! comment down below what your favourite extensions are for embedded development. I hope you enjoyed this article and see you in the next one!

May your code be bug-free!