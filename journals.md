# Desk Info screen + Alarm system! Build Journal

## Jul 13, 2026, 6:42 AM

I connected the ESP-32 with the OLED display and ran some test codes to see if the OLED works, and it does!

---

## Jul 13, 2026, 7:07 AM

now connected the DHT sensor to the board
I guess the sensor's labes is not perfectly correct sice the DATA pin is called SDA which is not true, so yeah I took help of internet to find out the wiring and functioning of it

<img width="728" height="502" alt="image" src="https://github.com/user-attachments/assets/a96f0ce4-c8dd-42e8-8801-1a3bd8d63751" />


---

## Jul 13, 2026, 9:41 AM

tested the temperature sensor with an example code, and it works!
Now just display this stuff on to the screen.

---

## Jul 13, 2026, 10:54 AM

Yay!
I wrote the code and took help of Internet and GPT to understand the void and loop and some C++, and then found 2-3 tutorials on Instructables about a similar project, so took help for the code from there!

---

## Jul 14, 2026, 12:29 PM

now I tried adding the buzzer, but apparently it doesn't work, so I will debug this when I have the components

---

## Jul 14, 2026, 1:12 PM

after the temperature display working properly, I added a Red LED indicating an Alarm and a buzzer such that if the temperature >= 50, they both gets activated!  

<img width="781" height="507" alt="image" src="https://github.com/user-attachments/assets/05e738ba-bcc7-4445-8111-1305929fac7c" />

---

## Jul 15, 2026, 2:46 PM

I also added a PIR sensor!!!

---

## Jul 15, 2026, 5:31 PM

Done with the PIR sensor! Now whenever someone crosses it, It gets displayed on my screen!!
there are few bugs for the motion getting detected automatically in the simulator, but it would not be an issue with the actual component hopefully :)

<img width="1021" height="586" alt="image" src="https://github.com/user-attachments/assets/07180d1c-70e1-4f20-bc30-a90cadcb5cfa" />
