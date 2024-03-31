# Smart_home_Automation


project Requirements:
# You have 2 ECUs:
 ECU1 :
 ECU1 is responsible for Authentication and ogin.
 ECU1 components :
1. EEPROM
2.RTC
3.Relay
4.Keypad
5. LCD
6. Finger print module
7.Buzzer

 ECU2:
 ECU2 is responsible for automatic Control.
 ECU2 components:

1.Wifi
2.DC Motor
3.Temp Sensor
4. LDR
5. LEDs

6. LCD
7.Keypad
# ECU1 operation :
1.When user wants to enter the house, he
should be authenticated using tow methods.
2. First method is by password entered by
keypad, system should verify this password
against saved password in EEPROM.
3. Second method is by fingerprint of the user.
4. LCD is used to display messages to guide the
user through login process.
5.The user is not allowed to enter the house
unless the identity verification is done.
6.If the user is first time user, system should
register his fingerprint and also accept the
setup of a new password.
7.If user is verified then a welcome screen will
be displayed then Real Time will be displayed.
8.The user last login time will be time stamped
and saved in EEPROM, and displayed every
time user will login.
9.Relay will open the door lock for user to enter
the house.

10. If wrong password is entered more than 3
times , buzzer will fire an alarm
11. After a successful login, ECU1 will send a
signal to ECU2, indicting that our user is in the
house.
# ECU2 operation :
1.User Can control motor fan and lights using
his mobile phone.
2.Data are sent to system over Wi-Fi.
3.User can switch the motor ON/OFF and also
control motor speed , motor has 2 speed at
duty cycle 30 % and duty cycle 70%
4.Temperature Sensor is monitoring the room
temperature and user can view the temp at
any time, on his mobile phone.
5. LDR is used to sense Room Light if there is
SunLight in the room, the Led intensity is
decreased.
6.User can logout from System when he is
leaving the house.

