EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 8268 11693 portrait
encoding utf-8
Sheet 1 1
Title "TFM Luces: Mota"
Date "2021-08-01"
Rev "1.0"
Comp "Jesús Muñoz Martínez"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:Earth #PWR03
U 1 1 610790BF
P 2700 1800
F 0 "#PWR03" H 2700 1550 50  0001 C CNN
F 1 "Earth" H 2700 1650 50  0001 C CNN
F 2 "" H 2700 1800 50  0001 C CNN
F 3 "~" H 2700 1800 50  0001 C CNN
	1    2700 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1800 2700 1800
Wire Wire Line
	1550 1800 1550 1750
Wire Wire Line
	1550 1600 1550 1650
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 6107ECB5
P 1200 1650
F 0 "J1" H 1118 1775 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 1118 1776 50  0001 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2_1x02_P5.00mm_Horizontal" H 1200 1650 50  0001 C CNN
F 3 "~" H 1200 1650 50  0001 C CNN
	1    1200 1650
	-1   0    0    -1  
$EndComp
Text Label 1600 1800 0    50   ~ 0
N_in
Text Label 1600 1600 0    50   ~ 0
L_in
Wire Wire Line
	1550 1650 1450 1650
Wire Wire Line
	1450 1500 1450 1650
Connection ~ 1450 1650
Wire Wire Line
	1450 1650 1400 1650
$Comp
L power:PWR_FLAG #FLG02
U 1 1 6108DEA0
P 1450 1900
F 0 "#FLG02" H 1450 1975 50  0001 C CNN
F 1 "PWR_FLAG" H 1450 2073 50  0000 C CNN
F 2 "" H 1450 1900 50  0001 C CNN
F 3 "~" H 1450 1900 50  0001 C CNN
	1    1450 1900
	1    0    0    1   
$EndComp
Wire Wire Line
	1450 1900 1450 1750
Wire Wire Line
	1400 1750 1450 1750
Connection ~ 1450 1750
Wire Wire Line
	1450 1750 1550 1750
Text Notes 2050 2000 0    50   ~ 0
POWER
$Comp
L RF_Module:ESP-07 U3
U 1 1 6106940C
P 4700 3700
F 0 "U3" H 5100 3050 50  0000 C CNN
F 1 "ESP-12" H 4400 3000 50  0000 C CNN
F 2 "LUCES:ESP-12" H 4700 3700 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 4350 3800 50  0001 C CNN
	1    4700 3700
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR016
U 1 1 610702C6
P 4700 4600
F 0 "#PWR016" H 4700 4350 50  0001 C CNN
F 1 "Earth" H 4700 4450 50  0001 C CNN
F 2 "" H 4700 4600 50  0001 C CNN
F 3 "~" H 4700 4600 50  0001 C CNN
	1    4700 4600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 61070BCC
P 3650 2500
F 0 "SW1" H 3650 2785 50  0000 C CNN
F 1 "RESET" H 3650 2694 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_PTS645" H 3650 2700 50  0001 C CNN
F 3 "~" H 3650 2700 50  0001 C CNN
	1    3650 2500
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR08
U 1 1 610733D5
P 3300 2900
F 0 "#PWR08" H 3300 2650 50  0001 C CNN
F 1 "Earth" H 3300 2750 50  0001 C CNN
F 2 "" H 3300 2900 50  0001 C CNN
F 3 "~" H 3300 2900 50  0001 C CNN
	1    3300 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 610E6E77
P 3150 3500
F 0 "R1" V 2943 3500 50  0000 C CNN
F 1 "220k(1%)" V 3034 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3080 3500 50  0001 C CNN
F 3 "~" H 3150 3500 50  0001 C CNN
	1    3150 3500
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 610E7634
P 3450 3750
F 0 "R2" V 3243 3750 50  0000 C CNN
F 1 "100k(1%)" V 3334 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3380 3750 50  0001 C CNN
F 3 "~" H 3450 3750 50  0001 C CNN
	1    3450 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3500 3300 3500
$Comp
L power:Earth #PWR010
U 1 1 610E9CD7
P 3450 4000
F 0 "#PWR010" H 3450 3750 50  0001 C CNN
F 1 "Earth" H 3450 3850 50  0001 C CNN
F 2 "" H 3450 4000 50  0001 C CNN
F 3 "~" H 3450 4000 50  0001 C CNN
	1    3450 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 4000 3450 3900
$Comp
L Converter_ACDC:HLK-PM01 PS1
U 1 1 610F328D
P 2200 1700
F 0 "PS1" H 2200 2025 50  0000 C CNN
F 1 "HLK-PM01" H 2200 1934 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 2200 1400 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=54" H 2600 1350 50  0001 C CNN
	1    2200 1700
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:AMS1117-3.3 U2
U 1 1 610F616D
P 3450 1600
F 0 "U2" H 3450 1842 50  0000 C CNN
F 1 "AMS1117-3.3" H 3450 1751 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 3450 1800 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 3550 1350 50  0001 C CNN
	1    3450 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 610F8926
P 2950 1750
F 0 "C3" H 3065 1796 50  0000 L CNN
F 1 "10uF" H 3065 1705 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 2988 1600 50  0001 C CNN
F 3 "~" H 2950 1750 50  0001 C CNN
	1    2950 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 610F98FB
P 3850 1750
F 0 "C5" H 3965 1796 50  0000 L CNN
F 1 "C10uF" H 3965 1705 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3888 1600 50  0001 C CNN
F 3 "~" H 3850 1750 50  0001 C CNN
	1    3850 1750
	1    0    0    -1  
$EndComp
Connection ~ 2950 1600
Wire Wire Line
	2950 1600 2600 1600
Wire Wire Line
	3750 1600 3850 1600
$Comp
L power:Earth #PWR06
U 1 1 610FCFEA
P 2950 1950
F 0 "#PWR06" H 2950 1700 50  0001 C CNN
F 1 "Earth" H 2950 1800 50  0001 C CNN
F 2 "" H 2950 1950 50  0001 C CNN
F 3 "~" H 2950 1950 50  0001 C CNN
	1    2950 1950
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR012
U 1 1 610FDD2E
P 3850 1950
F 0 "#PWR012" H 3850 1700 50  0001 C CNN
F 1 "Earth" H 3850 1800 50  0001 C CNN
F 2 "" H 3850 1950 50  0001 C CNN
F 3 "~" H 3850 1950 50  0001 C CNN
	1    3850 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1950 3850 1900
Wire Wire Line
	2950 1950 2950 1900
$Comp
L power:Earth #PWR09
U 1 1 610FEADD
P 3450 1950
F 0 "#PWR09" H 3450 1700 50  0001 C CNN
F 1 "Earth" H 3450 1800 50  0001 C CNN
F 2 "" H 3450 1950 50  0001 C CNN
F 3 "~" H 3450 1950 50  0001 C CNN
	1    3450 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 1900 3450 1950
$Comp
L power:Earth #PWR02
U 1 1 61107325
P 2350 3900
F 0 "#PWR02" H 2350 3650 50  0001 C CNN
F 1 "Earth" H 2350 3750 50  0001 C CNN
F 2 "" H 2350 3900 50  0001 C CNN
F 3 "~" H 2350 3900 50  0001 C CNN
	1    2350 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 611086C2
P 1250 3700
F 0 "J2" H 1168 3825 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 1168 3826 50  0001 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2_1x02_P5.00mm_Horizontal" H 1250 3700 50  0001 C CNN
F 3 "~" H 1250 3700 50  0001 C CNN
	1    1250 3700
	-1   0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 6108CBED
P 1450 1500
F 0 "#FLG01" H 1450 1575 50  0001 C CNN
F 1 "PWR_FLAG" H 1450 1673 50  0000 C CNN
F 2 "" H 1450 1500 50  0001 C CNN
F 3 "~" H 1450 1500 50  0001 C CNN
	1    1450 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 3700 1500 3700
Connection ~ 1500 3700
Wire Wire Line
	1750 3300 1950 3300
$Comp
L power:+5V #PWR01
U 1 1 6111B532
P 2350 2700
F 0 "#PWR01" H 2350 2550 50  0001 C CNN
F 1 "+5V" H 2365 2873 50  0000 C CNN
F 2 "" H 2350 2700 50  0001 C CNN
F 3 "" H 2350 2700 50  0001 C CNN
	1    2350 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR07
U 1 1 6111BF12
P 3000 1450
F 0 "#PWR07" H 3000 1300 50  0001 C CNN
F 1 "+5V" H 3015 1623 50  0000 C CNN
F 2 "" H 3000 1450 50  0001 C CNN
F 3 "" H 3000 1450 50  0001 C CNN
	1    3000 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1450 3000 1600
Wire Wire Line
	2950 1600 3000 1600
Connection ~ 3000 1600
Wire Wire Line
	3000 1600 3150 1600
Wire Wire Line
	2350 2700 2350 2750
$Comp
L power:+3.3V #PWR014
U 1 1 6111EDAA
P 4200 1450
F 0 "#PWR014" H 4200 1300 50  0001 C CNN
F 1 "+3.3V" H 4215 1623 50  0000 C CNN
F 2 "" H 4200 1450 50  0001 C CNN
F 3 "" H 4200 1450 50  0001 C CNN
	1    4200 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1450 4200 1600
Wire Wire Line
	4200 1600 3850 1600
Connection ~ 3850 1600
$Comp
L power:+3.3V #PWR015
U 1 1 6112135F
P 4700 2250
F 0 "#PWR015" H 4700 2100 50  0001 C CNN
F 1 "+3.3V" H 4715 2423 50  0000 C CNN
F 2 "" H 4700 2250 50  0001 C CNN
F 3 "" H 4700 2250 50  0001 C CNN
	1    4700 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2250 4700 2400
Wire Wire Line
	1450 3800 1700 3800
$Comp
L Sensor_Current:ACS712xLCTR-05B U1
U 1 1 610F08A4
P 2350 3500
F 0 "U1" H 2550 3150 50  0000 C CNN
F 1 "ACS712xLCTR-05B" H 2400 2950 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 2450 3150 50  0001 L CIN
F 3 "http://www.allegromicro.com/~/media/Files/Datasheets/ACS712-Datasheet.ashx?la=en" H 2350 3500 50  0001 C CNN
	1    2350 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3500 3000 3500
$Comp
L Device:C C2
U 1 1 6112B688
P 2850 3800
F 0 "C2" H 2965 3846 50  0000 L CNN
F 1 "1nF" H 2965 3755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2888 3650 50  0001 C CNN
F 3 "~" H 2850 3800 50  0001 C CNN
	1    2850 3800
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR05
U 1 1 6112BE63
P 2850 4050
F 0 "#PWR05" H 2850 3800 50  0001 C CNN
F 1 "Earth" H 2850 3900 50  0001 C CNN
F 2 "" H 2850 4050 50  0001 C CNN
F 3 "~" H 2850 4050 50  0001 C CNN
	1    2850 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 4050 2850 3950
Wire Wire Line
	2850 3650 2850 3600
Wire Wire Line
	2850 3600 2750 3600
$Comp
L Device:C C1
U 1 1 6112DB5C
P 2750 2900
F 0 "C1" H 2865 2946 50  0000 L CNN
F 1 "0.1uF" H 2865 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2788 2750 50  0001 C CNN
F 3 "~" H 2750 2900 50  0001 C CNN
	1    2750 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2750 2750 2750
Connection ~ 2350 2750
Wire Wire Line
	2350 2750 2350 3100
$Comp
L power:Earth #PWR04
U 1 1 6112F428
P 2750 3100
F 0 "#PWR04" H 2750 2850 50  0001 C CNN
F 1 "Earth" H 2750 2950 50  0001 C CNN
F 2 "" H 2750 3100 50  0001 C CNN
F 3 "~" H 2750 3100 50  0001 C CNN
	1    2750 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3100 2750 3050
Wire Wire Line
	1500 3700 1950 3700
Wire Wire Line
	1500 3550 1500 3700
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 6113F392
P 6550 3400
F 0 "J3" H 6630 3392 50  0000 L CNN
F 1 "LUX_meter" H 6630 3301 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S4B-XH-A-1_1x04_P2.50mm_Horizontal" H 6550 3400 50  0001 C CNN
F 3 "~" H 6550 3400 50  0001 C CNN
	1    6550 3400
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR022
U 1 1 6114F1A4
P 6250 3400
F 0 "#PWR022" H 6250 3150 50  0001 C CNN
F 1 "Earth" H 6250 3250 50  0001 C CNN
F 2 "" H 6250 3400 50  0001 C CNN
F 3 "~" H 6250 3400 50  0001 C CNN
	1    6250 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	6350 3400 6250 3400
Wire Wire Line
	6350 3300 6250 3300
Wire Wire Line
	6250 3300 6250 3150
$Comp
L power:+3.3V #PWR021
U 1 1 6115177C
P 6250 3150
F 0 "#PWR021" H 6250 3000 50  0001 C CNN
F 1 "+3.3V" H 6265 3323 50  0000 C CNN
F 2 "" H 6250 3150 50  0001 C CNN
F 3 "" H 6250 3150 50  0001 C CNN
	1    6250 3150
	1    0    0    -1  
$EndComp
Text Label 5550 3600 0    50   ~ 0
SCL
Text Label 5550 3500 0    50   ~ 0
SDA
Wire Wire Line
	1550 1800 1700 1800
Wire Wire Line
	1550 1600 1750 1600
Wire Wire Line
	1750 1600 1750 3300
Connection ~ 1750 1600
Wire Wire Line
	1750 1600 1800 1600
Wire Wire Line
	1700 1800 1700 3800
Connection ~ 1700 1800
Wire Wire Line
	1700 1800 1800 1800
$Comp
L power:PWR_FLAG #FLG03
U 1 1 6110B475
P 1500 3550
F 0 "#FLG03" H 1500 3625 50  0001 C CNN
F 1 "PWR_FLAG" H 1500 3723 50  0000 C CNN
F 2 "" H 1500 3550 50  0001 C CNN
F 3 "~" H 1500 3550 50  0001 C CNN
	1    1500 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 611A4A8D
P 5350 2850
F 0 "R5" V 5143 2850 50  0000 C CNN
F 1 "470" V 5234 2850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 5280 2850 50  0001 C CNN
F 3 "~" H 5350 2850 50  0001 C CNN
	1    5350 2850
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR019
U 1 1 611A9635
P 5800 2500
F 0 "#PWR019" H 5800 2250 50  0001 C CNN
F 1 "Earth" H 5800 2350 50  0001 C CNN
F 2 "" H 5800 2500 50  0001 C CNN
F 3 "~" H 5800 2500 50  0001 C CNN
	1    5800 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3300 4100 3300
$Comp
L power:+3.3V #PWR011
U 1 1 611D108D
P 3500 3250
F 0 "#PWR011" H 3500 3100 50  0001 C CNN
F 1 "+3.3V" H 3515 3423 50  0000 C CNN
F 2 "" H 3500 3250 50  0001 C CNN
F 3 "" H 3500 3250 50  0001 C CNN
	1    3500 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3300 3500 3300
Wire Wire Line
	3500 3300 3500 3250
$Comp
L Device:R R3
U 1 1 611B73CA
P 3800 3300
F 0 "R3" V 3900 3300 50  0000 C CNN
F 1 "12K" V 3700 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3730 3300 50  0001 C CNN
F 3 "~" H 3800 3300 50  0001 C CNN
	1    3800 3300
	0    -1   -1   0   
$EndComp
Connection ~ 3450 3500
Wire Wire Line
	3450 3600 3450 3500
Wire Wire Line
	4100 3500 3450 3500
$Comp
L Device:R R4
U 1 1 611D5E28
P 4100 2750
F 0 "R4" V 4200 2750 50  0000 C CNN
F 1 "12K" V 4000 2750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 4030 2750 50  0001 C CNN
F 3 "~" H 4100 2750 50  0001 C CNN
	1    4100 2750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR013
U 1 1 611D65BB
P 4100 2550
F 0 "#PWR013" H 4100 2400 50  0001 C CNN
F 1 "+3.3V" H 4115 2723 50  0000 C CNN
F 2 "" H 4100 2550 50  0001 C CNN
F 3 "" H 4100 2550 50  0001 C CNN
	1    4100 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2550 4100 2600
$Comp
L Device:R R8
U 1 1 611D9FBD
P 5650 4000
F 0 "R8" V 5550 4150 50  0000 C CNN
F 1 "12K" V 5550 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 5580 4000 50  0001 C CNN
F 3 "~" H 5650 4000 50  0001 C CNN
	1    5650 4000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 611DE14C
P 5550 3100
F 0 "R6" V 5650 3150 50  0000 C CNN
F 1 "12K" V 5650 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 5480 3100 50  0001 C CNN
F 3 "~" H 5550 3100 50  0001 C CNN
	1    5550 3100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R7
U 1 1 611DE7A6
P 5550 3300
F 0 "R7" V 5500 3150 50  0000 C CNN
F 1 "12K" V 5500 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 5480 3300 50  0001 C CNN
F 3 "~" H 5550 3300 50  0001 C CNN
	1    5550 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5400 3300 5300 3300
Wire Wire Line
	5400 3100 5350 3100
$Comp
L power:+3.3V #PWR018
U 1 1 611E5853
P 5750 2950
F 0 "#PWR018" H 5750 2800 50  0001 C CNN
F 1 "+3.3V" H 5765 3123 50  0000 C CNN
F 2 "" H 5750 2950 50  0001 C CNN
F 3 "" H 5750 2950 50  0001 C CNN
	1    5750 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2950 5750 3100
Wire Wire Line
	5750 3300 5700 3300
Wire Wire Line
	5700 3100 5750 3100
Connection ~ 5750 3100
Wire Wire Line
	5750 3100 5750 3300
Wire Wire Line
	5350 3000 5350 3100
Connection ~ 5350 3100
Wire Wire Line
	5350 3100 5300 3100
Wire Wire Line
	5750 2500 5800 2500
Wire Wire Line
	4100 2900 4100 3100
Wire Wire Line
	3850 2500 3900 2500
Wire Wire Line
	3900 2500 3900 2850
Wire Wire Line
	3900 3100 4100 3100
Connection ~ 4100 3100
Connection ~ 3900 2850
Wire Wire Line
	3900 2850 3900 3100
Wire Wire Line
	3400 2850 3400 2500
Wire Wire Line
	3400 2500 3450 2500
Wire Wire Line
	3400 2850 3300 2850
Wire Wire Line
	3300 2850 3300 2900
Wire Wire Line
	3800 2850 3900 2850
Wire Wire Line
	3500 2850 3400 2850
Connection ~ 3400 2850
$Comp
L Device:C C6
U 1 1 612245FF
P 4950 2650
F 0 "C6" H 5065 2696 50  0000 L CNN
F 1 "100uF" H 5065 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4988 2500 50  0001 C CNN
F 3 "~" H 4950 2650 50  0001 C CNN
	1    4950 2650
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR017
U 1 1 61224D6B
P 4950 2800
F 0 "#PWR017" H 4950 2550 50  0001 C CNN
F 1 "Earth" H 4950 2650 50  0001 C CNN
F 2 "" H 4950 2800 50  0001 C CNN
F 3 "~" H 4950 2800 50  0001 C CNN
	1    4950 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2500 4950 2400
Wire Wire Line
	4950 2400 4700 2400
Connection ~ 4700 2400
Wire Wire Line
	4700 2400 4700 2900
$Comp
L power:Earth #PWR020
U 1 1 610F1AA3
P 5850 4100
F 0 "#PWR020" H 5850 3850 50  0001 C CNN
F 1 "Earth" H 5850 3950 50  0001 C CNN
F 2 "" H 5850 4100 50  0001 C CNN
F 3 "~" H 5850 4100 50  0001 C CNN
	1    5850 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 4000 5850 4000
Wire Wire Line
	5850 4000 5850 4100
$Comp
L Connector_Generic:Conn_01x04 J5
U 1 1 61105D68
P 6750 2700
F 0 "J5" H 6830 2692 50  0000 L CNN
F 1 "SERIAL" H 6830 2601 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6750 2700 50  0001 C CNN
F 3 "~" H 6750 2700 50  0001 C CNN
	1    6750 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3600 6350 3600
Wire Wire Line
	5300 3500 6350 3500
$Comp
L power:+3.3V #PWR026
U 1 1 61119506
P 6450 2450
F 0 "#PWR026" H 6450 2300 50  0001 C CNN
F 1 "+3.3V" H 6465 2623 50  0000 C CNN
F 2 "" H 6450 2450 50  0001 C CNN
F 3 "" H 6450 2450 50  0001 C CNN
	1    6450 2450
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR028
U 1 1 61119B2F
P 6500 3000
F 0 "#PWR028" H 6500 2750 50  0001 C CNN
F 1 "Earth" H 6500 2850 50  0001 C CNN
F 2 "" H 6500 3000 50  0001 C CNN
F 3 "~" H 6500 3000 50  0001 C CNN
	1    6500 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3000 6500 2900
Wire Wire Line
	6500 2900 6550 2900
Wire Wire Line
	6550 2600 6450 2600
Wire Wire Line
	6450 2600 6450 2450
Wire Wire Line
	5300 3200 6000 3200
Wire Wire Line
	6000 3200 6000 2700
Wire Wire Line
	6000 2700 6550 2700
Wire Wire Line
	5300 3400 6100 3400
Wire Wire Line
	6100 3400 6100 2800
Wire Wire Line
	6100 2800 6550 2800
Wire Wire Line
	6150 4000 6150 3700
Wire Wire Line
	6150 3700 5300 3700
Wire Wire Line
	5350 2500 5350 2700
$Comp
L Jumper:Jumper_2_Open JP1
U 1 1 611C9B64
P 5550 2500
F 0 "JP1" H 5550 2735 50  0000 C CNN
F 1 "Jumper_2_Open" H 5550 2644 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5550 2500 50  0001 C CNN
F 3 "~" H 5550 2500 50  0001 C CNN
	1    5550 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 611F8F9C
P 3650 2850
F 0 "C4" V 3398 2850 50  0000 C CNN
F 1 "470pF" V 3489 2850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3688 2700 50  0001 C CNN
F 3 "~" H 3650 2850 50  0001 C CNN
	1    3650 2850
	0    1    1    0   
$EndComp
Text Notes 1050 1950 0    50   ~ 0
AC INPUT
Text Notes 1100 3950 0    50   ~ 0
AC OUTPUT
Text Label 5900 3700 0    50   ~ 0
PIR
Wire Wire Line
	6150 4000 6550 4000
Wire Wire Line
	6350 3900 6350 3850
Wire Wire Line
	6550 3900 6350 3900
Wire Wire Line
	6450 4100 6450 4150
Wire Wire Line
	6550 4100 6450 4100
$Comp
L Connector_Generic:Conn_01x03 J6
U 1 1 61138385
P 6750 4000
F 0 "J6" H 6830 4042 50  0000 L CNN
F 1 "PIR" H 6830 3951 50  0000 L CNN
F 2 "Connector_JST:JST_XH_S3B-XH-A-1_1x03_P2.50mm_Horizontal" H 6750 4000 50  0001 C CNN
F 3 "~" H 6750 4000 50  0001 C CNN
	1    6750 4000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR025
U 1 1 61132D04
P 6350 3850
F 0 "#PWR025" H 6350 3700 50  0001 C CNN
F 1 "+5V" H 6365 4023 50  0000 C CNN
F 2 "" H 6350 3850 50  0001 C CNN
F 3 "" H 6350 3850 50  0001 C CNN
	1    6350 3850
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR027
U 1 1 6113275D
P 6450 4150
F 0 "#PWR027" H 6450 3900 50  0001 C CNN
F 1 "Earth" H 6450 4000 50  0001 C CNN
F 2 "" H 6450 4150 50  0001 C CNN
F 3 "~" H 6450 4150 50  0001 C CNN
	1    6450 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3800 5450 3800
Wire Wire Line
	4700 4400 4700 4600
Text Label 6350 4950 0    50   ~ 0
PWM
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 611193F3
P 6550 4450
F 0 "J4" H 6630 4442 50  0000 L CNN
F 1 "TRIAC" H 6630 4351 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6550 4450 50  0001 C CNN
F 3 "~" H 6550 4450 50  0001 C CNN
	1    6550 4450
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR029
U 1 1 61119F5E
P 6300 4700
F 0 "#PWR029" H 6300 4450 50  0001 C CNN
F 1 "Earth" H 6300 4550 50  0001 C CNN
F 2 "" H 6300 4700 50  0001 C CNN
F 3 "~" H 6300 4700 50  0001 C CNN
	1    6300 4700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR023
U 1 1 6111A45C
P 6100 4600
F 0 "#PWR023" H 6100 4450 50  0001 C CNN
F 1 "+5V" H 6000 4600 50  0000 C CNN
F 2 "" H 6100 4600 50  0001 C CNN
F 3 "" H 6100 4600 50  0001 C CNN
	1    6100 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 4650 6300 4650
Wire Wire Line
	6300 4650 6300 4700
Text Label 6200 4450 0    50   ~ 0
ZC
Wire Wire Line
	6350 4350 5300 4350
Wire Wire Line
	5300 4000 5500 4000
Wire Wire Line
	5950 4450 6350 4450
Wire Wire Line
	5300 3900 5950 3900
Text Label 6200 4350 0    50   ~ 0
DIM
Wire Wire Line
	5300 4350 5300 4100
Wire Wire Line
	5950 3900 5950 4450
$Comp
L Connector_Generic:Conn_01x03 J7
U 1 1 6114ABD3
P 6700 5050
F 0 "J7" H 6780 5092 50  0000 L CNN
F 1 "PWM/0-10V" H 6780 5001 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6700 5050 50  0001 C CNN
F 3 "~" H 6700 5050 50  0001 C CNN
	1    6700 5050
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR030
U 1 1 6114B2BA
P 6400 5200
F 0 "#PWR030" H 6400 4950 50  0001 C CNN
F 1 "Earth" H 6400 5050 50  0001 C CNN
F 2 "" H 6400 5200 50  0001 C CNN
F 3 "~" H 6400 5200 50  0001 C CNN
	1    6400 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 5150 6400 5150
Wire Wire Line
	6400 5150 6400 5200
Wire Wire Line
	6500 4950 5450 4950
Wire Wire Line
	5450 3800 5450 4950
$Comp
L power:+5V #PWR024
U 1 1 6115602D
P 6200 5100
F 0 "#PWR024" H 6200 4950 50  0001 C CNN
F 1 "+5V" H 6100 5100 50  0000 C CNN
F 2 "" H 6200 5100 50  0001 C CNN
F 3 "" H 6200 5100 50  0001 C CNN
	1    6200 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 5050 6300 5050
Wire Wire Line
	6300 5050 6300 5100
Wire Wire Line
	6300 5100 6200 5100
Wire Wire Line
	6350 4550 6200 4550
Wire Wire Line
	6200 4550 6200 4600
Wire Wire Line
	6200 4600 6100 4600
$EndSCHEMATC
