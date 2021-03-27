EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74xx:CD74HC4067M U?
U 1 1 606035D2
P 3200 2100
F 0 "U?" H 3200 3116 50  0000 C CNN
F 1 "CD74HC4067M" H 3200 3025 50  0000 C CNN
F 2 "Package_SO:SOIC-24W_7.5x15.4mm_P1.27mm" H 4100 1100 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/cd74hc4067.pdf" H 2850 2950 50  0001 C CNN
	1    3200 2100
	1    0    0    -1  
$EndComp
$Comp
L Traktorino-rescue:4067D-RESCUE-DJ_0 MUXpots?
U 1 1 6061332A
P -3350 2025
F 0 "MUXpots?" H -3650 3150 50  0000 L BNN
F 1 "4067D" H -3650 725 50  0000 L BNN
F 2 "40xx:40xx-DIL24-6" H -3350 2175 50  0001 C CNN
F 3 "" H -3350 2025 60  0000 C CNN
	1    -3350 2025
	-1   0    0    1   
$EndComp
$Comp
L Traktorino-rescue:4067D-RESCUE-DJ_0 MUXbuttons?
U 1 1 60613330
P -1650 2025
F 0 "MUXbuttons?" H -1950 3150 50  0000 L BNN
F 1 "4067D" H -1950 725 50  0000 L BNN
F 2 "40xx:40xx-DIL24-6" H -1650 2175 50  0001 C CNN
F 3 "" H -1650 2025 60  0000 C CNN
	1    -1650 2025
	-1   0    0    1   
$EndComp
Wire Notes Line
	-850 625  -850 3425
Text GLabel -2150 1525 0    60   Input ~ 0
GND
Text GLabel -2150 1675 0    60   Input ~ 0
VCC
Text GLabel -2850 2425 2    60   Input ~ 0
potCF
Text GLabel -2850 2325 2    60   Input ~ 0
potL1
Text GLabel -2850 2225 2    60   Input ~ 0
potL2
Text GLabel -2850 2125 2    60   Input ~ 0
potL3
Text GLabel -2850 1825 2    60   Input ~ 0
potL6
Text GLabel -2850 1925 2    60   Input ~ 0
potL5
Text GLabel -2850 2025 2    60   Input ~ 0
potL4
Text GLabel -2850 2625 2    60   Input ~ 0
D7
Text GLabel -3850 1525 0    60   Input ~ 0
GND
Text GLabel -3850 1675 0    60   Input ~ 0
VCC
Text GLabel -3850 2425 0    60   Input ~ 0
A0
Text GLabel -2850 3025 2    60   Input ~ 0
GND
Text GLabel -2850 2925 2    60   Input ~ 0
D4
Text GLabel -2850 2725 2    60   Input ~ 0
D6
Text GLabel -2850 2825 2    60   Input ~ 0
D5
Text GLabel -2850 1725 2    60   Input ~ 0
potL7
Text GLabel -2850 1625 2    60   Input ~ 0
potMain
Text GLabel -2850 1525 2    60   Input ~ 0
potR7
Text GLabel -2850 1425 2    60   Input ~ 0
potR6
Text GLabel -2850 1325 2    60   Input ~ 0
potR5
Text GLabel -2850 1225 2    60   Input ~ 0
potR4
Text GLabel -2850 1125 2    60   Input ~ 0
potR3
Text GLabel -2850 1025 2    60   Input ~ 0
potR2
Text GLabel -2850 925  2    60   Input ~ 0
potR1
Text GLabel -2150 2425 0    60   Input ~ 0
A1
Text GLabel -1150 2625 2    60   Input ~ 0
D7
Text GLabel -1150 2725 2    60   Input ~ 0
D6
Text GLabel -1150 2825 2    60   Input ~ 0
D5
Text GLabel -1150 2925 2    60   Input ~ 0
D4
Text GLabel -1150 3025 2    60   Input ~ 0
GND
Text GLabel -1150 2425 2    60   Input ~ 0
BL1
Text GLabel -1150 2325 2    60   Input ~ 0
BL2
Text GLabel -1150 2225 2    60   Input ~ 0
BL3
Text GLabel -1150 2125 2    60   Input ~ 0
BL4
Text GLabel -1150 2025 2    60   Input ~ 0
BL5
Text GLabel -1150 1925 2    60   Input ~ 0
BL6
Text GLabel -1150 1525 2    60   Input ~ 0
Bshift
Text GLabel -1150 1425 2    60   Input ~ 0
BR6
Text GLabel -1150 1325 2    60   Input ~ 0
BR5
Text GLabel -1150 1225 2    60   Input ~ 0
BR4
Text GLabel -1150 1125 2    60   Input ~ 0
BR3
Text GLabel -1150 1025 2    60   Input ~ 0
BR2
Text GLabel -1150 925  2    60   Input ~ 0
BR1
Text GLabel 3200 1100 1    40   Input ~ 0
VCC
$Comp
L power:GND #PWR?
U 1 1 606138F8
P 3200 3200
F 0 "#PWR?" H 3200 2950 50  0001 C CNN
F 1 "GND" H 3205 3027 50  0000 C CNN
F 2 "" H 3200 3200 50  0001 C CNN
F 3 "" H 3200 3200 50  0001 C CNN
	1    3200 3200
	1    0    0    -1  
$EndComp
Text GLabel 2700 2700 0    40   Input ~ 0
A0
Text GLabel 2700 2000 0    40   Input ~ 0
D4
Text GLabel 2700 2100 0    40   Input ~ 0
D5
Text GLabel 2700 2200 0    40   Input ~ 0
D6
Text GLabel 2700 2300 0    40   Input ~ 0
D7
Text GLabel 2700 1600 0    40   Input ~ 0
GND
$EndSCHEMATC
