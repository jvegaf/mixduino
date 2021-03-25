EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel -1347 3072 2    40   Input ~ 0
VU8
Text GLabel -1347 3172 2    40   Input ~ 0
VU7
Text GLabel -1347 2972 2    40   Input ~ 0
VU9
Text GLabel -1347 2872 2    40   Input ~ 0
VU10
Text GLabel -1347 2772 2    40   Input ~ 0
VU11
Text GLabel -1347 2672 2    40   Input ~ 0
VU12
Text GLabel -1347 2572 2    40   Input ~ 0
VU13
Text GLabel -1354 3844 2    40   Input ~ 0
ledL1
Text GLabel -1354 3944 2    40   Input ~ 0
ledL2
Text GLabel -1354 4044 2    40   Input ~ 0
ledL3
Text GLabel -1354 4144 2    40   Input ~ 0
ledL4
Text GLabel -1354 4244 2    40   Input ~ 0
ledL5
Text GLabel -1354 4344 2    40   Input ~ 0
ledR1
Text GLabel -1354 4444 2    40   Input ~ 0
ledR2
Text GLabel -1354 4544 2    40   Input ~ 0
ledR3
Text GLabel -1347 2472 2    40   Input ~ 0
ledR5
Text GLabel -2754 4444 0    40   Input ~ 0
GND
Text GLabel 1780 1710 0    40   Input ~ 0
D8
Text GLabel 1780 1210 0    40   Input ~ 0
D11
Text GLabel 1780 1510 0    40   Input ~ 0
VCC
Text GLabel 1780 1810 0    40   Input ~ 0
GND
$Comp
L Traktorino-rescue:74HC595 leds?
U 1 1 605F8127
P -2054 4294
AR Path="/605F8127" Ref="leds?"  Part="1" 
AR Path="/605D0BAE/605F8127" Ref="leds1"  Part="1" 
F 0 "leds1" H -1904 4894 70  0000 C CNN
F 1 "74HC595" H -2054 3694 70  0000 C CNN
F 2 "74HC595:DIL16" H -2054 4294 60  0001 C CNN
F 3 "" H -2054 4294 60  0000 C CNN
	1    -2054 4294
	1    0    0    -1  
$EndComp
Text GLabel -2754 4344 0    40   Input ~ 0
D8
Text GLabel 1780 1410 0    40   Input ~ 0
D12
Text GLabel -2754 4044 0    40   Input ~ 0
D12
Text GLabel -2754 4144 0    40   Input ~ 0
VCC
Text GLabel -1354 4744 2    40   Input ~ 0
595_out
Text GLabel -2747 3072 0    40   Input ~ 0
GND
Text GLabel -2747 2972 0    40   Input ~ 0
D8
Text GLabel -2747 2672 0    40   Input ~ 0
D12
Text GLabel -2747 2772 0    40   Input ~ 0
VCC
$Comp
L Traktorino-rescue:74HC595 VUR?
U 1 1 605F8145
P -2047 2922
AR Path="/605F8145" Ref="VUR?"  Part="1" 
AR Path="/605D0BAE/605F8145" Ref="VUR1"  Part="1" 
F 0 "VUR1" H -1897 3522 70  0000 C CNN
F 1 "74HC595" H -2047 2322 70  0000 C CNN
F 2 "74HC595:DIL16" H -2047 2922 60  0001 C CNN
F 3 "" H -2047 2922 60  0000 C CNN
	1    -2047 2922
	1    0    0    -1  
$EndComp
Text Label -1336 1963 0    60   ~ 0
VUL1-VUR1
Text Label -2747 2472 2    60   ~ 0
VUL1-VUR1
Text Label -1347 3372 0    60   ~ 0
VUR1-leds1
Text Label -2754 3844 2    60   ~ 0
VUR1-leds1
Text GLabel 2580 1210 2    40   Input ~ 0
VUL1-7
$Comp
L Traktorino-rescue:74HC595 VUL?
U 1 1 605F813F
P -2036 1513
AR Path="/605F813F" Ref="VUL?"  Part="1" 
AR Path="/605D0BAE/605F813F" Ref="VULINE1"  Part="1" 
F 0 "VULINE1" H -1886 2113 70  0000 C CNN
F 1 "74HC595" H -2036 913 70  0000 C CNN
F 2 "74HC595:DIL16" H -2036 1513 60  0001 C CNN
F 3 "" H -2036 1513 60  0000 C CNN
	1    -2036 1513
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 UVU-LINE1
U 1 1 606245C1
P 2180 1610
F 0 "UVU-LINE1" H 2180 2391 50  0000 C CNN
F 1 "74HC595" H 2180 2300 50  0000 C CNN
F 2 "" H 2180 1610 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2180 1610 50  0001 C CNN
	1    2180 1610
	1    0    0    -1  
$EndComp
Text GLabel -1336 1763 2    40   Input ~ 0
VU6
Text GLabel -1336 1663 2    40   Input ~ 0
VU5
Text GLabel -1336 1563 2    40   Input ~ 0
VU4
Text GLabel -1336 1463 2    40   Input ~ 0
VU3
Text GLabel -1336 1363 2    40   Input ~ 0
VU2
Text GLabel -1336 1263 2    40   Input ~ 0
VU1
Text GLabel -1336 1163 2    40   Input ~ 0
VU0
Text GLabel 2580 1310 2    40   Input ~ 0
VUL1-6
Text GLabel 2580 1410 2    40   Input ~ 0
VUL1-5
Text GLabel 2580 1510 2    40   Input ~ 0
VUL1-4
Text GLabel 2580 1610 2    40   Input ~ 0
VUL1-3
Text GLabel 2580 1710 2    40   Input ~ 0
VUL1-2
Text GLabel 2580 1810 2    40   Input ~ 0
VUL1-1
Text GLabel 2580 1910 2    40   Input ~ 0
VUL1-0
Text GLabel 3320 1710 0    40   Input ~ 0
D8
Text GLabel 3320 1210 0    40   Input ~ 0
D11
Text GLabel 3320 1510 0    40   Input ~ 0
VCC
Text GLabel 3320 1810 0    40   Input ~ 0
GND
Text GLabel 3320 1410 0    40   Input ~ 0
D12
Text GLabel 4120 1210 2    40   Input ~ 0
VUL2-7
$Comp
L 74xx:74HC595 UVU-LINE2
U 1 1 6065CCED
P 3720 1610
F 0 "UVU-LINE2" H 3720 2391 50  0000 C CNN
F 1 "74HC595" H 3720 2300 50  0000 C CNN
F 2 "" H 3720 1610 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 3720 1610 50  0001 C CNN
	1    3720 1610
	1    0    0    -1  
$EndComp
Text GLabel 4120 1310 2    40   Input ~ 0
VUL2-6
Text GLabel 4120 1410 2    40   Input ~ 0
VUL2-5
Text GLabel 4120 1510 2    40   Input ~ 0
VUL2-4
Text GLabel 4120 1610 2    40   Input ~ 0
VUL2-3
Text GLabel 4120 1710 2    40   Input ~ 0
VUL2-2
Text GLabel 4120 1810 2    40   Input ~ 0
VUL2-1
Text GLabel 4120 1910 2    40   Input ~ 0
VUL2-0
Text GLabel 4950 1720 0    40   Input ~ 0
D8
Text GLabel 4950 1220 0    40   Input ~ 0
D11
Text GLabel 4950 1520 0    40   Input ~ 0
VCC
Text GLabel 4950 1820 0    40   Input ~ 0
GND
Text GLabel 4950 1420 0    40   Input ~ 0
D12
Text GLabel 5750 1220 2    40   Input ~ 0
VUL3-7
$Comp
L 74xx:74HC595 UVU-LINE3
U 1 1 6066923D
P 5350 1620
F 0 "UVU-LINE3" H 5350 2401 50  0000 C CNN
F 1 "74HC595" H 5350 2310 50  0000 C CNN
F 2 "" H 5350 1620 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5350 1620 50  0001 C CNN
	1    5350 1620
	1    0    0    -1  
$EndComp
Text GLabel 5750 1320 2    40   Input ~ 0
VUL3-6
Text GLabel 5750 1420 2    40   Input ~ 0
VUL3-5
Text GLabel 5750 1520 2    40   Input ~ 0
VUL3-4
Text GLabel 5750 1620 2    40   Input ~ 0
VUL3-3
Text GLabel 5750 1720 2    40   Input ~ 0
VUL3-2
Text GLabel 5750 1820 2    40   Input ~ 0
VUL3-1
Text GLabel 5750 1920 2    40   Input ~ 0
VUL3-0
Text GLabel 6470 1720 0    40   Input ~ 0
D8
Text GLabel 6470 1220 0    40   Input ~ 0
D11
Text GLabel 6470 1520 0    40   Input ~ 0
VCC
Text GLabel 6470 1820 0    40   Input ~ 0
GND
Text GLabel 6470 1420 0    40   Input ~ 0
D12
Text GLabel 7270 1220 2    40   Input ~ 0
VUMASL-7
$Comp
L 74xx:74HC595 UVU-MASTER-L
U 1 1 606776D8
P 6870 1620
F 0 "UVU-MASTER-L" H 6870 2401 50  0000 C CNN
F 1 "74HC595" H 6870 2310 50  0000 C CNN
F 2 "" H 6870 1620 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 6870 1620 50  0001 C CNN
	1    6870 1620
	1    0    0    -1  
$EndComp
Text GLabel 7270 1320 2    40   Input ~ 0
VUMASL-6
Text GLabel 7270 1420 2    40   Input ~ 0
VUMASL-5
Text GLabel 7270 1520 2    40   Input ~ 0
VUMASL-4
Text GLabel 7270 1620 2    40   Input ~ 0
VUMASL-3
Text GLabel 7270 1720 2    40   Input ~ 0
VUMASL-2
Text GLabel 7270 1820 2    40   Input ~ 0
VUMASL-1
Text GLabel 7270 1920 2    40   Input ~ 0
VUMASL-0
Text GLabel 8010 1720 0    40   Input ~ 0
D8
Text GLabel 8010 1220 0    40   Input ~ 0
D11
Text GLabel 8010 1520 0    40   Input ~ 0
VCC
Text GLabel 8010 1820 0    40   Input ~ 0
GND
Text GLabel 8010 1420 0    40   Input ~ 0
D12
Text GLabel 8810 1220 2    40   Input ~ 0
VUMASR-7
$Comp
L 74xx:74HC595 UVU-MASTER-R
U 1 1 606776EF
P 8410 1620
F 0 "UVU-MASTER-R" H 8410 2401 50  0000 C CNN
F 1 "74HC595" H 8410 2310 50  0000 C CNN
F 2 "" H 8410 1620 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 8410 1620 50  0001 C CNN
	1    8410 1620
	1    0    0    -1  
$EndComp
Text GLabel 8810 1320 2    40   Input ~ 0
VUMASR-6
Text GLabel 8810 1420 2    40   Input ~ 0
VUMASR-5
Text GLabel 8810 1520 2    40   Input ~ 0
VUMASR-4
Text GLabel 8810 1620 2    40   Input ~ 0
VUMASR-3
Text GLabel 8810 1720 2    40   Input ~ 0
VUMASR-2
Text GLabel 8810 1820 2    40   Input ~ 0
VUMASR-1
Text GLabel 8810 1920 2    40   Input ~ 0
VUMASR-0
Text GLabel 1780 3720 0    40   Input ~ 0
D8
Text GLabel 1780 3220 0    40   Input ~ 0
D11
Text GLabel 1780 3520 0    40   Input ~ 0
VCC
Text GLabel 1780 3820 0    40   Input ~ 0
GND
Text GLabel 1780 3420 0    40   Input ~ 0
D12
$Comp
L 74xx:74HC595 U?
U 1 1 606A7472
P 2180 3620
F 0 "U?" H 2180 4401 50  0000 C CNN
F 1 "74HC595" H 2180 4310 50  0000 C CNN
F 2 "" H 2180 3620 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2180 3620 50  0001 C CNN
	1    2180 3620
	1    0    0    -1  
$EndComp
Text GLabel 2580 3320 2    40   Input ~ 0
LEDHPL1
Text GLabel 2580 3420 2    40   Input ~ 0
LEDHPL2
Text GLabel 2580 3520 2    40   Input ~ 0
LEDHPL3
Text GLabel 2580 3620 2    40   Input ~ 0
LEDCUEL
Text GLabel 2580 3720 2    40   Input ~ 0
LEDPLAYL
Text GLabel 2580 3820 2    40   Input ~ 0
LEDCUER
Text GLabel 2580 3920 2    40   Input ~ 0
LEDPLAYR
$EndSCHEMATC
