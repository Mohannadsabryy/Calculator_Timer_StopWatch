Objectives:
The goal of this project is to design a simple calculator with 2 extra features: a timer and a stopwatch. The calculator shall do the basic operations that are addition, subtraction, multiplication, and division. The timer and stopwatch features will be both handled separately by the hardware. 
By the end of this project,You must master the following: 
1. Timers: You will be using at least two timers one for the stopwatch mode and the other for the timer mode. 
2. GPIO: You will be using the LCD and a keypad and some push buttons. 
3. Interrupts: You will use interrupts also in this project for the push buttons and timers.


Features:
In this project you will have 3 main Modes. And there is a button that when we clicked on it whenever we are in any application we will return back to the main screen in order to choose one of these modes.

1- Calculator Mode:
In this mode you will be asked to take inputs from the user and print that input on the LCD. You will take two numbers (each more than 1 digit) and a sign between them. Use the keypad numbers to get the numbers.
Print the numbers and the sign on the LCD before printing the result.

KeyPad Format:

![image](https://github.com/user-attachments/assets/c482b4b8-b5b0-477b-9e11-cd60632c5452)

2- Timer Mode:
In this mode user is asked to press on minutes button and each press increase one minutes and for seconds he press on another button and each press also increases one second. There is a button for reset timer and button to start timer when we clicked on it ; it will start counting down until it reaches zero so that the blue led will be turned on.

KeyPad format:

![image](https://github.com/user-attachments/assets/e3d21be3-597d-425e-a4da-1feb7aeec19c)

 

You can design it as like you want.


3- StopWatch Mode:
In this mode the user will be using three buttons, one to start the stopwatch, one to pause the stopwatch, and one to reset the value back to 00:00. When you switch to this mode initially present 00:00 on the LCD. 
Whenever the user presses on the start button start incrementing the stopwatch.

KeyPad format:

![image](https://github.com/user-attachments/assets/4a1e7fec-b78e-4ff7-a792-11a69283b2b7)


Architecture of Project:


![image](https://github.com/user-attachments/assets/3ee51799-b5b3-4e47-90ca-5402eccbb437)
 

Test of the Project:
https://drive.google.com/drive/folders/1td5_N8DopOdWUwHVoDfY0tnOIyOc-X9u?usp=drive_link
