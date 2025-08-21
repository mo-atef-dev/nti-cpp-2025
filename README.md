# NTI C++ 2025
Repository for NTI Embedded Linux (C++ section) 2025 training

You can find the training files in the folder C++.

## Instructions for debugging in VS Code

1. Click the gear icon to add a debug configuration. If you can't see this icon make sure you are in a cpp file.
![Step 1](Images/step-1.png)

2. Choose the option `(gdb) Launch`
![Step 2](Images/step-2.png)

3. A new file called `launch.json` will be generated in the ".vscode" folder. Open this file and change the option called "program" as shown in the image. Replace the name "main" with whatever name you have given to your program
![Step 3](Images/step-3.png)

4. :warning: For trainees using Windows, you also have to add the debugger path as `gdb.exe`
![Step 3](Images/step-3-windows.jpeg)

5. :warning: Make sure that you add the `-g` compiler flag in the Makefile as shown in the image
![Step 4](Images/step-4.png)

6. Clean and build your program
![Step 5](Images/step-5.png)

7. Add a breakpoint and start debugging using the `(gdb) Launch` option to test if the debugger is working
![Step 6](Images/step-6.png)
![Step 7](Images/step-7.png)
![Step 8](Images/step-8.png)
