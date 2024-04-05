#ifndef _SAEJ1939_71_H
#define _SAEJ1939_71_H
/**
 * \file saej1939_71.h
 * \brief Relevant information described in the J1939-71 standard (Vehicle Application Layer)
 * This file does not contain definitions of PGNs and SPNs that are part of configuration optinions.
 *
 * The standard specifies that the data must be send in little engian order.
 * Due to the fact that my pc is already using little endian,
 * no byte swapping is required.
 *
 * Unused bits or bytes should be filled with 0xFF or 1s, respectively.
 *
 * \note Throughout this file, each SPN is named with spn\<spn_num\>,
 * each struct of multiple SPNs is named wiht spns\<pgn_num\>, and the variables
 * declared of these types are named pgn\<pgn_num\>.
 */

/**
 * # Engine controller - 0x00
 *
 * The cyclic transmission PGNs are:
 * 61443 Electronic Engine Controller 2 - EEC2
 * 61444 Electronic Engine Controller 1 - EEC1
 * 65226 DM1
 * 65262 Engine Temperature 1 - ETC1
 * 65263 Engine Fluid Level/Pressure 1 - EFL/P1
 * 65265 Cruise Control/Vehicle Speed - CCVS
 * 65269 Ambient conditions - AMB
 * 65270 Inlet/Exhaust Conditions 1 - IC1
 * 65271 Vehicle Electrical Power - VEP
 */
/**
 * \struct spns61443
 * \brief Electronic Engine Controller 2 - EEC2
 *
 * Transmission: 50ms; length 8B; default priority 3.
 */
struct spns61443 {
    unsigned char spn558  : 2; /*!< accelerator pedal low idle sw, 00=off, 01=on */
    unsigned char spn559  : 2; /*!< accelerator pedal kickdown, 00=0ff, 01=on */
    unsigned char spn1437 : 2; /*!< road speed limit status, 00=active, 01=not active */
    unsigned char u0      : 2; /*!< padding, filled with ones */
    unsigned char spn91      ; /*!< accelerator pedal position, 0.4%/bit, 0% offset */
    unsigned char spn92      ; /*!< percent load at current speed, 1%/bit, o% offset */
    unsigned char spn974     ; /*!< remote accelerator pedal position - not used */
    unsigned char u1[4]      ; /*!< padding, filled with 0xFF */
};
/**
 * \struct spns61444
 * \brief Electronic Engine Controller 1 - EEC1
 *
 * Transmission: 20ms; length 8B; default priority 3.
 */
struct spns61444 {
    unsigned char  spn899  : 4; /*!< Engine torque mode, 0000 - no req, 1 pedal, 2 cruise control etc */
    unsigned char  u0      : 4; /*!<  */
    unsigned char  spn512     ; /*!< Driver's demand engine % torque, 1%/bit, -125% offset */
    unsigned char  spn513     ; /*!< Actal engine % torque, 1%/bit, -125% offset */
    unsigned short spn190     __attribute__((packed)); /*!< Engine speed, 0.125 rpm/bit, 0 offset - rev display */
    unsigned char  spn1483    ; /*!< SA of controlling for engine, 1 sa/bi */
    unsigned char  spn1675 : 4; /*!< Engine starter mode, 0000 no req, etc */
    unsigned char  u1      : 4; /*!<  */
    unsigned char  spn2432    ; /*!< Engine demand - % torque, 1%/bit, -125% offset */
};
 /**
 * \struct spns65262
 * \brief PGN 65262 - Engine Temperature 1 - ETC1
 *
 * Transmission: 1 s; length 8B; default priority 6.
 */
struct spns65262 {
    unsigned char  spn110  ; /*!< Engine coolant temperature, 1C/bit, -40C offset - temperature gauge */
    unsigned char  spn174  ; /*!< Fuel temperature, 1C/bit, -40C offset */
    unsigned short spn175  __attribute__((packed)); /*!< Engine oil temperature 1, 0.03125C/bit, -273C offset */
    unsigned short spn176  __attribute__((packed)); /*!< Turbo oil temperature,  0.03125C/bit, -273C offset */
    unsigned char  spn52   ; /*!< Engine intercooler temperature, 1C/bit, -40C offset  */
    unsigned char  spn1134 ; /*!< Engine intercooler thermostat opening, 0.4%/bit, 0 offset */
};
 /**
 * \struc spn65263
 * \brief Engine Fluid Level/Pressure 1 - EFL/P1
 *
 * Transmission 0.5 s; length 8B; default priority 6
 */
struct spns65263 {
    unsigned char  spn94  ; /*!< Fuel delivery pressure, 4kPa/bit, 0 offset */
    unsigned char  spn22  ; /*!< Extended cranck-case pressure, 0.05kPa/bit, 0 offset */
    unsigned char  spn98  ; /*!< Engine oil level, 0.4%/bit, 0 offset */
    unsigned char  spn100 ; /*!< Engine oil pressure, 4kPa/bit, 0 offset */
    unsigned short spn101  __attribute__((packed)); /*!< Cranckcase pressure, 1/128kPa/bit, -250kPa offset */
    unsigned char  spn109 ; /*!< Coolant pressure, 2kPa/bit, 0 offset */
    unsigned char  spn111 ; /*!< Coolant level, 0.4%/bit, 0 offset */
};
 /**
 * \struct spn65265
 * \brief Cruise Control/Vehicle Speed - CCVS
 *
 * Transmission 100 ms; length 8B; default priority 6
 */
struct spns65265 {
    unsigned char spn69   : 2; /*!< Two speed axle switch, 00-low range, 01-high range */
    unsigned char spn70   : 2; /*!< Parking break switch, 00-not set, 01-set */
    unsigned char spn1633 : 2; /*!< Cruise control pause switch, 00-off, 01-on, 10-err, 11-N/A */
    unsigned char spn84   : 2; /*!< Wheel based vehicle speed, 1/256km/h, 0 offset */
    unsigned char spn595  : 2; /*!< Cruise control active, 00-off, 01-on */
    unsigned char spn596  : 2; /*!< Criuse control enable switch, 00-disabled, 01-enamble */
    unsigned char spn597  : 2; /*!< Brake switch, 00-released, 01-pressed, 10-err, 11-N/A */
    unsigned char spn598  : 2; /*!< Cluch switch, 00-released, 01-pressed */
    unsigned char spn599  : 2; /*!< Cruise control set switch, 00-not set, 01-set */
    unsigned char spn600  : 2; /*!< Cruise control decel switch, 00-not coast, 01-coast */
    unsigned char spn601  : 2; /*!< Cruise control resume switch, 00-not, 01-resume */
    unsigned char spn602  : 2; /*!< Cruise control accelerate switch, 00-not, 01-accelerate */
    unsigned char spn86      ; /*!< Cruise control set speed, 1km/h/bit, 0 offset */
    unsigned char spn976  : 5; /*!< PTO State, 11111-N/A */
    unsigned char spn527  : 3; /*!< Cruise control states, 000-off, 0001-hold etc */
    unsigned char spn968  : 2; /*!< Idle increment switch, 00-off, 01-on */
    unsigned char spn967  : 2; /*!< Idle decrement switch, 00-off, 01-on */
    unsigned char spn966  : 2; /*!< Engine test mode switch, 00-off, 01-on */
    unsigned char spn1237 : 2; /*!< Engine shutdown override switch, 00-off, 01-on */
};
 /**
 * \struct spns65269
 * \brief Ambient conditions - AMB
 *
 * Transmission 1 s; length 8B; default priority 6
 */
struct spns65269 {
    unsigned char  spn108 ; /*!< Barometric pressure, 0.5kPa/bit, 0 offset */
    unsigned short spn170 __attribute__((packed)); /*!< Cab interior temperature, 0.03125C/bit, -273C offset */
    unsigned short spn171 __attribute__((packed)); /*!< Ambient air temperature, 0.03125C/bit, -273C offset - outside temperatue displayed */
    unsigned char  spn172 ; /*!< Air inlet temperature, 1C/bit, -40C offset */
    unsigned short spn79  __attribute__((packed)); /*!< Road surface temperature, 0.03125C/bit, -273C offset */
};
 /**
 * \struct spns65270
 * \brief Inlet/Exhaust Conditions 1 - IC1
 *
 * Transmission 0.5 s; length 8B; default priority 6
 */
struct spns65270 {
    unsigned char  spn81 ; /*!< Particulate trap inlet pressure, 0.5kPa/bit, 0 offset */
    unsigned char  spn102; /*!< Boost pressure, 2kPa/bit, 0 offset */
    unsigned char  spn105; /*!< Intake manifold 1 pressure, 1C/bit, -40C offset */
    unsigned char  spn106; /*!< Air inlet pressure, 2kPa/bit, 0 offset */
    unsigned char  spn107; /*!< Air inlet filter diff pressure, 0.05kPa/bit, 0 offset */
    unsigned short spn173 __attribute__((packed)); /*!< Gas exhaust temperature, 0.03125C/bit, -273C offset */
    unsigned char  spn112; /*!< Coolant filter diff pressure, 0.5kPa/bit, 0 offset */
};
 /**
 * \struct spns65271
 * \brief Vehicle Electrical Power - VEP
 *
 * Transmission 1 s; length 8B; default priority 6
*/
struct spns65271 {
    unsigned char  spn114; /*!< Net baterry current, 1A/bit, -125A offset */
    unsigned char  spn115; /*!< Alternator current, 1A/bit, -125A offset */
    unsigned short spn167 __attribute__((packed)); /*!< Alternator voltage, 0.05V/bit, 0V offset */
    unsigned short spn168 __attribute__((packed)); /*!< Electrical voltage, 0.05V/bit, 0V offset */
    unsigned short spn158 __attribute__((packed)); /*!< Battery voltage, 0.05V/bit, 0V offset */
};


 /* # Transmission controller - 0x03
 * The cyclic transmission PGNs are:
 * 61442 Electronic Transmission Controller 1 - ETC1
 * 61445 Electronic Transmission Controller 2 - ETC2
 * 65098 Electronic Transmission Controller 7 - ETC7 ???
 * 65223 Electronic Transmission Controller 3 - ETC3
 * 65226(DM1)
 * 65272 Transmission Fluids - TF
 * 65415(propritary)
 */
 /**
 * \struct spns61442
 * \brief Electronic Transmission Controller 1 - ETC1
 *
 * Transmission 10 ms; length 8B; default priority 6
 */
struct spns61442 {
    unsigned char  spn560 : 2; /*!< Driveline engaged 00-disengaged, 01-engaged */
    unsigned char  spn573 : 2; /*!< Torque converter lockup engaged 00-disengaged, 01-engaged */
    unsigned char  spn574 : 2; /*!< Shift in progress 00-not in progress, 01-in progress */
    unsigned char  u0     : 2; /*!< padding, filled with 1's */
    unsigned short spn191 __attribute__((packed)); /*!< Output shaft speed 0.125rpm/bit, 0 offset */
    unsigned char  spn522    ; /*!< Percent cluth slip 0.4%/bit, 0 offset */
    unsigned char  spn606 : 2; /*!< Momentary eng overspd enabled 00-disabled, 01-enabled, 11-na */
    unsigned char  spn607 : 2; /*!< Progressive shift disable 00-not disabled, 01-disabled, 11-na */
    unsigned char  u1     : 4; /*!< unused, filled with 0xFF */
    unsigned short spn161 __attribute__((packed)); /*!< Input shaft speed 0.125rpm/bit, 0 offset */
    unsigned char  spn1482   ; /*!< SA of controlling device 1sa/bit, 0 offset */
};
/**
  * \struct spns61445
  * \brief Electronic Transmission Controller 2 - ETC2
  *
  * Transmission 100 ms; length 8B; default priority 6
  */
 struct spns61445 {
    unsigned char  spn524  ; /*!< Selected gear 1 gear/bit, -125 offset */
    unsigned short spn526  __attribute__((packed)); /*!< Actual gear ratio 0.001/bit, 0 offset */
    unsigned char  spn523  ; /*!< Current gear 1 gear/bit, -125 offset */
    unsigned char  spn162_1; /*!< Transmission req change ASCII (R1, N, D) */
    unsigned char  spn162_2;
    unsigned char  spn163_1; /*!< Transmission current range ASCII (R1, N, D) */
    unsigned char  spn163_2;
};


 /**
 * # Brakes controller - 0x0B (11)
 * The cyclic transmission PGNs are:
 * 61441 Electronic Brake Controller 1 - EBC1
 * 64964 Electronic Brake Controller 5 - EBC5 (no idea)
 * 65136 Combination Vehicle Weight - CVW
 * 65196 Wheel Brake Lining Remaining Information - EBC4
 * 65226 (DM1)
 * 65197 Wheel Application Pressure High Range Information - EBC3
 * 65215 Wheel Speed Information - EBC2
 * 65280 (propritary)
 * 65441 (propritary)
 */
 /**
  * \struct spns61441
  * \brief Electronic Brake Controller 1 - EBC1
  *
  * Transmission 100 ms; length 8B; default priority 6
  */
struct spns61441 {
    unsigned char spn561  : 2; /*!< ASR Engine Control Active */
    unsigned char spn562  : 2; /*!< ASR Brake Control Active */
    unsigned char spn563  : 2; /*!< Anti-Lock Braking (ABS) Active */
    unsigned char spn1121 : 2; /*!< EBS Brake Switch */
    unsigned char spn521     ; /*!< Brake Pedal Position */
    unsigned char spn575  : 2; /*!< ABS Off-road Switch */
    unsigned char spn576  : 2; /*!< ASR Off-road Switch */
    unsigned char spn577  : 2; /*!< ASR "Hill Holder" Switch */
    unsigned char spn1238 : 2; /*!< Traction Control Override Switch */
    unsigned char spn972  : 2; /*!< Accelerator Interlock Switch */
    unsigned char spn971  : 2; /*!< Engine Derate Switch */
    unsigned char spn970  : 2; /*!< Auxiliary Engine Shutdown Switch */
    unsigned char spn969  : 2; /*!< Remote Accelerator Enable Switch */
    unsigned char spn973     ; /*!< Engine Retarder Selection */
    unsigned char spn1243 : 2; /*!< ABS Fully Operational */
    unsigned char spn1439 : 2; /*!< EBS Red Warning Signal */
    unsigned char spn1438 : 2; /*!< ABS/EBS Amber Warning Signal (Powered Vehicle) */
    unsigned char spn1793 : 2; /*!< ATC/ASR Information Signal */
    unsigned char spn1481    ; /*!< Source Address of Controlling Device for Brake Control */
    unsigned char u0      : 4;
    unsigned char spn1836 : 2; /*!< Trailer ABS Status */
    unsigned char spn1792 : 2; /*!< Tractor-Mounted Trailer ABS Warning Signal */
};
/**
 * \struct spns65274
 * \brief Brakes - B
 *
 * Transmission 1 s; length 8B; default priority 6
 */
struct spns65274 {
unsigned char spn116 ;    /*!< Brake Application Pressure, 4kPa/bit, 0 offset*/
unsigned char spn117 ;    /*!< Brake Primary Pressure, 4kPa/bit, 0 offse */
unsigned char spn118 ;    /*!< Brake Secondary Pressure, 4kPa/bit, 0 offse */
unsigned char spn619 : 2; /*!< Parking Brake Actuator, 00-inactive, 01-active */
unsigned char u0     : 6; /*!< unused, padding */
unsigned char u1[4]  ;    /*!< padding */
};

 /**
 * # Retarder controller - 0x10 (16)
 * The cyclic transmission PGNs are:
 * 61440 (Electronic Retarder Controller 1 - ERC1),
 * 65226 (DM1)
 * 65275 (Retarder fluids - RF)
 * 65280 (propritary)
 */
 /**
 * \struct spns61440
 * \brief Electronic Retarder Controller 1 - ERC1
 *
 * Transmission 100 ms; length 8B; default priority 6
 */
struct spns61440 {
    unsigned char spn900  : 4; /*!< Retarder torque mode 0000-no req, 1-op, 2-cc etc */
    unsigned char spn571  : 2; /*!< Retarder enable, brake assist sw  00-disable, 01-enable */
    unsigned char spn572  : 2; /*!< Retarder enable, shift assist sw 00-disable, 01-enable */
    unsigned char spn520     ; /*!< Act retarder percent torque (of retarder conf), 1%/bit, -125% offset */
    unsigned char spn1085    ; /*!< Intended retarder percent torque 1%/bit, -125% offset */
    unsigned char spn1082 : 2; /*!< Engine coolant load increase 00-no increase, 01-increase */
    unsigned char spn1667 : 2; /*!< Retarder requesting brake light */
    unsigned char u0      : 4; /*!< padding, filled with 1's */
    unsigned char spn1480    ; /*!< SA of controlling device */
    unsigned char spn1715    ; /*!< Driver's demand percent torque 1%/bit, -125% offset */
    unsigned char spn1716    ; /*!< Retarder selection (curent pos / max pos * 100), non-engine 0.4%/bit, 0 offset */
    unsigned char spn1717    ; /*!< Act max available - percent torque(same as conf) 1%/bit, -125% offset */
};

 /**
 * # Body controller - 0x21 (33)
 * The cyclic transmission PGNs are:
 * 53760 Air Suspension Control 2 - ASC2
 * 65276 Dash Display - DD
 * 65441 (propritary)
 */
 /**
 * \struct spns65276
 * \brief Dash Display - DD
 *
 * Transmission 100 ms; length 8B; default priority 6
 * \note Only the fuel level is used from the readings I have.
 */
struct snps65276 {
    unsigned char  spn80 ; /*!< Washer fluid level 0.4%/bit, 0 offset */
    unsigned char  spn96 ; /*!< Fuel level 0.4%/bit, 0 offset */
    unsigned char  spn95 ; /*!< Fuel level differential pressure 2kPa/bit, 0 offset */
    unsigned char  spn99 ; /*!< Engine oil filter differential pressure 0.5kPa/bit, 0 offset */
    unsigned short spn169; /*!< Cargo ambient temperature 0.03125C/bit, -273 offset */
    unsigned char  u0[2] ; /*!< padding, filld with 0xFF */
};

 /**
 * # Management Computer - 0x27 (39)
 * The cyclic transmission PGNs are:
 * 61440 Electronic Retarder Controller 1 - ERC1
 * 65136 Combination Vehicle Weight - CVW
 * 65216 Service Information - SERV
 * 65226 DM1
 * 65253 Engine Hours, Revolutions - HOURS
 * 65257 Fuel Consumption (Liquid) - LFC
 * 65260 Vehicle Identification - VI
 * 65261 Cruise Control/Vehicle Speed Setup - CCSS
 * 65266 Fuel Economy (Liquid) - LFE
 * 65280 propritary
 * 65441 propritary
 * 65535 propritary
 *
 * Broadcast: Retarder conf ?
 */
 /**
  * \struct spns65136
  * \brief Combination Vehicle Weight - CVW
  *
  * Transmission on request; length variable; default priority 6
  */
 struct spsn65136 {
     unsigned short spn1585; /*!< Powered Vehicle Weight, 10 kg/bit, 0 offset */
     unsigned short spn1760; /*!< Gross Combination Vehicle Weight, 10 kg/bit, 0 offset */
     unsigned char  u0[4];   /* unused */
 };

/**
 * \struct spns65216
 * \brief Service Information - SERV
 *
 * Transmission on request; length 8B; default priority 6
 *
 * There are two acceptable formats for the SERV.
 * Format 1 has only 8 bytes of data and reports the component most in need of
 * service for each category.
 * Fornat 2 uses the transport layer in order to repeat these 8 bytes until
 * all supported service components have beed transmitted.
 */
struct spns65216 {
    unsigned char  spn911; /*!< Service Component Identification, 1 ID/bit, 0 offset */
    unsigned short spn914 __attribute__((packed)); /*!< Service Distance, 5 km/bit, -160,635 km offset */
    unsigned char  spn912; /*!< Service Component Identification, 1 ID/bit, 0 offset */
    unsigned char  spn915; /*!< Service Delay/Calendar Time Based 1 week/not, -125 offset*/
    unsigned char  spn913; /*!< Service Component Identification 1 ID/bit, 0 offset */
    unsigned short spn916 __attribute__((packed)); /*!< Service Component Identification, 1hr/bit, -32127 offset */
};
/**
 * \struct spns65253
 * \brief Engine Hours, Revolutions - HOURS
 *
 * Transmission on request; length 8B; default priority 6
 */
struct spns65253 {
    unsigned long spn247; /*!< Total Engine Hours, 0.05hr/bit, 0 offset */
    unsigned long spn249; /*!< Total Engine Revolutions, 1000r/bit, 0 offset */
};
/**
 * \struct 65257
 * \brief Fuel Consumption (Liquid) - LFC
 *
 * Transmission on request; length 8B; default priority 6
 */
struct spns65257 {
    unsigned long spn182; /*!< Trip Fuel, 0.5l/bit, 0 offset */
    unsigned long spn250; /*!< Total Fuel Used, 0.5l/bit, 0 offset */
};
/**
 * \struct spns65260
 * \brief Vehicle Identification - VI
 *
 * Transmission on request; length variable; default priority 6
 */
struct spns65260 {
    unsigned char spn237[18]; /*!< Vehicle Identification Number, last character '*' */
};
/**
 * \struct spns65261
 * \brief Cruise Control/Vehicle Speed Setup - CCSS
 *
 * Transmission on request; length 8B; default priority 6
 */
struct spns65261 {
    unsigned char spn74; /*!< Maximum Vehicle Speed Limit, 1km/h/bit, 0 offset */
    unsigned char spn87; /*!< Cruise Control High Set Limit Speed, 1km/h/bit, 0 offset */
    unsigned char spn88; /*!< Cruise Control Low Set Limit Speed 1km/h/bit, 0 offset */
    unsigned char u0[5]; /* unused */
};
/**
 * \struct spns65266
 * \brief Fuel Economy (Liquid) - LFE
 *
 * Transmission 100 ms; length 8B; default priority 6
 */
struct spns65266 {
    unsigned short spn183; /*!< Fuel Rate, 0.5l/h/bit, 0 offset */
    unsigned short spn184; /*!< Instantaneous Fuel Economy, 1/512km/kg/bit, 0 offset */
    unsigned short spn185; /*!< Average Fuel Economy, 1/512km/kg/bkg/hit, 0 offset */
    unsigned char  spn51 ; /*!< Throttle Position, 0.4%/bit, 0 offset */
    unsigned char  u0    ; /*!< unused */
};

/**
 * # Pneumatic system controller 0x30 (48)
 * The cyclic transmission PGNs are:
 * 65198 Air Supply Pressure - AIR1
 */
/**
 * \struct spsn65198
 * \brief Air Supply Pressure - AIR1
 *
 * Transmission 1 s; length 8B; default priority 6
 */
struct spns65198 {
    unsigned char spn46  ; /*!< Pneumatic Supply Pressure, 8kPa/bit, 0 offset */
    unsigned char spn1086; /*!< Parking and/or Trailer Air Pressure 8kPa/bit, 0 offset */
    unsigned char spn1087; /*!< Service Brake Air Pressure Circuit #1 8kPa/bit, 0 offset */
    unsigned char spn1088; /*!< Service Brake Air Pressure Circuit #2 8kPa/bit, 0 offset */
    unsigned char spn1089; /*!< Auxiliary Equipment Supply Pressure 8kPa/bit, 0 offset */
    unsigned char spn1090; /*!< Air Suspension Supply Pressure 8kPa/bit, 0 offset */
    unsigned char u0[2]  ; /*!< unused */
};
/**
 * # Tachograph 0xEE (238)
 * The cyclic transmission PGNs are:
 * 55808 Reserved for ISO 15765-2
 * 65132 Tachograph - TCO1
 * 65217 High Resolution Vehicle Distance - VDHR
 * 65254 Time/Date - TD
 * Broadcast: 65131, 65231
 */
/**
 * \struct spns65132
 * \brief Tachograph - TCO1
 *
 * Transmission 50ms; length 8B; default priority 3
 */
struct spns65132 {
    unsigned char  spn1612 : 3; /*!< Driver 1 working state 000-rest, 1-short break, 2-work, 3-driving  */
    unsigned char  spn1613 : 3; /*!< Driver 2 working state 4,5-reserved, 6-error, 7-na */
    unsigned char  spn1611 : 2; /*!< Drive recognize 00-vehicle not in motion, 01-vehicle motion */
    unsigned char  spn1617 : 4; /*!< Driver 1 Time Related States 0000-normal, 1-15' before 4h30', 2-4h30' reached,
                                 *   3-15' before 9h, 4-9h reached, 5-15' before 16h, 6-16h reached */
    unsigned char  spn1615 : 2; /*!< Driver card, driver 1, 00-card not present, 1-card present */
    unsigned char  spn1614 : 2; /*!< Overspeed 00-no overspeed, 01-overspeed */
    unsigned char  spn1618 : 4; /*!< Driver 2 Time Related States, \see spn1617  */
    unsigned char  spn1616 : 2; /*!< Driver card, driver 2, 00-card not present, 1-card present */
    unsigned char  u0      : 2; /*!< unused  */
    unsigned char  spn1622 : 2; /*!< System event, 00-no event, 01-system event */
    unsigned char  spn1621 : 2; /*!< Handling information, 00-no handle information, 01-handle information */
    unsigned char  spn1620 : 2; /*!< Tachograph performance, 00-normal preformance, 01-analysis */
    unsigned char  spn1619 : 2; /*!< Direction indicator, 00-forward, 01-reverse  */
    unsigned short spn1623;     /*!< Tachograph output shaft speed, 0.125rmp/bit, 0 offset */
    unsigned short spn1624;     /*!< Tachograph vehicle speed, 1/256km/h/bit, 0 offset */
};
/**
 * \struct spn65217
 * \brief High Resolution Vehicle Distance - VDHR
 *
 * Transmission 1 s; length 8B; default priority 6
 */
struct spns65217 {
    unsigned long spn917; /*!< High Resolution Total Vehicle Distance 5m/bit, 0 offset*/
    unsigned long spn918; /*!< High Resolution Trip Distance, 5m/bit, 0 offset */
};
/**
 * \struct 65254
 * \brief Time/Date - TD
 *
 * Transmission on request; length 8B; default priority 6
 */
struct spns65254 {
    unsigned char spn959 ; /*!< Seconds, 0.25s/bit, 0 offset */
    unsigned char spn960 ; /*!< Minutes, 1 min/bit, 0 offset */
    unsigned char spn961 ; /*!< Hours, 1 hours/bit, 0 offset */
    unsigned char spn963 ; /*!< Month, 1 month/bit, 0 offset */
    unsigned char spn962 ; /*!< Day, 0.25days/bit, 0 offset */
    unsigned char spn964 ; /*!< Year, 1 year/bit, 1985 offset */
    unsigned char spn1601; /*!< Local minute offset, 1 min/bit, -125 offset */
    unsigned char spn1602; /*!< Local hour offset, 1 hour/bit, -125 offset */
};
 /**
 * \struct spns65251
 * \brief Engine configuration EC
 *
 * Transmission on change / 5 s; length 34B, default priority 6
 * \info Although the standard specifies a length of 34B, my MAN TGX cluster only accepts 28!
 *
 */
struct spns65251 {
    unsigned short spn188  ; /*!< Engine speed at idle, point 1, 0.125rmp/bit, 0 offset */
    unsigned char  spn539  ; /*!< Percent torque at idel, point 1, 1%/bit, -125% offset */
    unsigned short spn528  __attribute__((packed)); /*!< Engine speed at point 2, 0.125rmp/bit, 0 offset - end of green zone */
    unsigned char  spn540  ; /*!< Percent torque at point 2, 1%/bit, -125% offset */
    unsigned short spn529  __attribute__((packed)); /*!< Engine speed at point 3, 0.125rmp/bit, 0 offset - start of green zone */
    unsigned char  spn541  ; /*!< Percent torque at point 3, 1%/bit, -125% offset */
    unsigned short spn530  __attribute__((packed)); /*!< Engine speed at point 4, 0.125rmp/bit, 0 offset */
    unsigned char  spn542  ; /*!< Percent torque at point 4, 1%/bit, -125% offset */
    unsigned short spn531  __attribute__((packed)); /*!< Engine speed at point 5, 0.125rmp/bit, 0 offset */
    unsigned char  spn543  ; /*!< Percent torque at point 5, 1%/bit, -125% offset */
    unsigned short spn532  __attribute__((packed)); /*!< Engine speed at high idel, point 6, 0.125rmp/bit, 0 offset */
    unsigned short spn545  __attribute__((packed)); /*!< Kp of endspeed governor 1/1280%/rpm per bit, 0 offset */
    unsigned short spn544  __attribute__((packed)); /*!< Reference engine torque 1 Nm/bit, 0 offset */
    unsigned short spn533  __attribute__((packed)); /*!< Max momentary eng overspeed, point 7 0.125rmp/bit, 0 offset - start of red zone */
    unsigned char  spn534  ; /*!< Max momentary override time limit, 0.1s/bit, 0 offset */
    unsigned char  spn535  ; /*!< Req speed control range lower limit, 10rpm/bit, 0 offset */
    unsigned char  spn536  ; /*!< Req speed control range upper limit, 10rpm/bit, 0 offse */
    unsigned char  spn537  ; /*!< Req torque control range lower limit, 1%/bit, -125% offset */
    unsigned char  spn538  ; /*!< Req torque control range upper limit, 1%/bit, -125% offset */
    /* unsigned short spn1712 __attribute__((packed)); */ /*!< Ext range req spd ctrl range upper limit, 0.125rmp/bit, 0 offset */
    /* unsigned short spn1794 __attribute__((packed)); */ /*!< Engine moment of inertia,0.004kg*m^2/bit, 0 offset */
    /* unsigned short spn1846 __attribute__((packed)); */ /*!< Default engine torque limit, 1Nm/bit, 0 offset */
};
/**
 * \struct spns65250
 *\brief Transmission configuration TC
 *
 * Transmission on change / request; length 42B (?); prio 6
 * \note Not exactly worth implementing.
 */
struct spns65250 {
    unsigned char spn958; /*!< Number of reverse gears, 1 gear value/bit, 0 offset */
    unsigned char spn957; /*!< Number of forward gears 1 gear value/bit, 0 offset */
    unsigned short spn581[20]; /*!< Rn-R1 D1-Dn, gear ratio 0.001/bit, 0 offset */
};
/**
 * \struct spns65249
 *\brief Retarder configuration TC
 *
 * Retarder on change / request / every 5 s; length 19B; prio 6.
 */
struct spns65249 {
unsigned char  spn901 : 4;                      /*!< Retarder Type, 0=electric/mechanic, 1-hydraulic,
                                                 *   2-cooled friction, 3-engine retarder, 4-exhaust */
unsigned char  spn902 : 4;                      /*!< Retarder Location, 0-(primary) engine rpm, 1-(primary) exhaust,
                                                 *   2-(primary) transmission input, 3-(secondary) transmission output
                                                 *   4-(secondary) driveline */
unsigned char  spn557;                          /*!< Retarder Control Method, 1 step/bit, 0 offset
                                                 *   0: continuous control,1 On/Off control, 2 to 250: number of steps*/
unsigned short spn546 __attribute__ ((packed)); /*!< Retarder Speed At Idle, Point 1, 0.125rpm/bit, 0 offset */
unsigned char  spn551;                          /*!< Percent Torque At Idle, Point 1,  */
unsigned short spn548 __attribute__ ((packed)); /*!< Maximum Retarder Speed, Point 2, 0.125rpm/bit, 0 offset */
unsigned char  spn552;                          /*!< Percent Torque At Maximum Speed, Point 2, 1%/bit, -125 offset */
unsigned short spn549 __attribute__ ((packed)); /*!< Retarder Speed At Point 3, 0.125rpm/bit, 0 offset */
unsigned char  spn553;                          /*!< Percent Torque At Point 3,  1%/bit, -125 offset */
unsigned short spn550 __attribute__ ((packed)); /*!< Retarder Speed At Point 4,  0.125rpm/bit, 0 offset */
unsigned char  spn554;                          /*!< Percent Torque At Point 4, 1%/bit, -125 offset */
unsigned short spn547 __attribute__ ((packed)); /*!< Retarder Speed At Peak Torque, Point 5, 0.125rpm/bit, 0 offset */
unsigned short spn556 __attribute__ ((packed)); /*!< Reference Retarder Torque, 1Nm/bit, 0 offset */
unsigned char  spn555;                          /*!< Percent Torque At Peak Torque, Point 5, 1%/bit, -125 offset */
};

/**
 * \struct spns65088
 * \brief Lighting Data - LD
 *
 * Transmission as requested; length 8B; default priority 6
 *
 * The possible values are:
 *  0-deactivate
 *  1-activate
 *  2-fault
 *  3-not available
 */
struct spns65088 {
unsigned char spn2404 : 2; /*!< Running Light */
unsigned char spn2352 : 2; /*!< Alternate Beam Head Light Data */
unsigned char spn2350 : 2; /*!< Low Beam Head Light Data */
unsigned char spn2348 : 2; /*!< High Beam Head Light Data */
unsigned char spn2388 : 2; /*!< Tractor Front Fog Lights */
unsigned char spn2386 : 2; /*!< Rotating Beacon Light */
unsigned char spn2370 : 2; /*!< Right Turn Signal Lights */
unsigned char spn2368 : 2; /*!< Left Turn Signal Lights */
unsigned char spn2392 : 2; /*!< Back Up Light and Alarm Horn */
unsigned char spn2376 : 2; /*!< Center Stop Light */
unsigned char spn2374 : 2; /*!< Right Stop Light */
unsigned char spn2372 : 2; /*!< Left Stop Light */
unsigned char spn2384 : 2; /*!< Implement Clearance Light */
unsigned char spn2382 : 2; /*!< Tractor Clearance Light */
unsigned char spn2380 : 2; /*!< Implement Marker Light */
unsigned char spn2378 : 2; /*!< Tractor Marker Light */
unsigned char spn2390 : 2; /*!< Rear Fog Lights */
unsigned char spn2358 : 2; /*!< Tractor Underside Mounted Work Lights */
unsigned char spn2360 : 2; /*!< Tractor Rear Low Mounted Work Lights */
unsigned char spn2362 : 2; /*!< Tractor Rear High Mounted Work Lights */
unsigned char spn2364 : 2; /*!< Tractor Side Low Mounted Work Lights */
unsigned char spn2366 : 2; /*!< Tractor Side High Mounted Work Lights */
unsigned char spn2354 : 2; /*!< Tractor Front Low Mounted Work Lights */
unsigned char spn2356 : 2; /*!< Tractor Front High Mounted Work Lights */
unsigned char spn2398 : 2; /*!< Implement OEM Option 2 Light */
unsigned char spn2396 : 2; /*!< Implement OEM Option 1 Light */
unsigned char spn2407 : 2; /*!< Implement Right Facing Work Light */
unsigned char spn2598 : 2; /*!< Implement Left Facing Work Light */
unsigned char u0      : 2; /*!< unused, padding */
unsigned char spn2402 : 2; /*!< Implement Right Forward Work Light */
unsigned char spn2400 : 2; /*!< Implement Left Forward Work Light */
unsigned char spn2394 : 2; /*!< Implement Rear Work Light */
};

/**
 * \struct spns65089
 * \brief Lighting Command - LC
 *
 * Transmission on change of lamp on/off state, 100ms < LC < 1s; length 8B; default priority 3
 *
 * The possible values are:
 *  0-deactivate
 *  1-activate
 *  2-fault
 *  3-not available
 */
struct spns65089 {
unsigned char spn2403 : 2; /*!< Running Light Command */
unsigned char spn2351 : 2; /*!< Alternate Beam Head Light Command */
unsigned char spn2349 : 2; /*!< Low Beam Head Light Command */
unsigned char spn2347 : 2; /*!< High Beam Head Light Command */
unsigned char spn2387 : 2; /*!< Tractor Front Fog Lights Command */
unsigned char spn2385 : 2; /*!< Rotating Beacon Light Command */
unsigned char spn2369 : 2; /*!< Right Turn Signal Lights Command */
unsigned char spn2367 : 2; /*!< Left Turn Signal Lights Command */
unsigned char spn2391 : 2; /*!< Back Up Light and Alarm Horn Command */
unsigned char spn2375 : 2; /*!< Center Stop Light Command */
unsigned char spn2373 : 2; /*!< Right Stop Light Command */
unsigned char spn2371 : 2; /*!< Left Stop Light Command */
unsigned char spn2383 : 2; /*!< Implement Clearance Light Command */
unsigned char spn2381 : 2; /*!< Tractor Clearance Light Command */
unsigned char spn2379 : 2; /*!< Implement Marker Light Command */
unsigned char spn2377 : 2; /*!< Tractor Marker Light Command */
unsigned char spn2389 : 2; /*!< Rear Fog Light Command */
unsigned char spn2357 : 2; /*!< Tractor Underside Mounted Work Lights Command */
unsigned char spn2359 : 2; /*!< Tractor Rear Low Mounted Work Lights Command */
unsigned char spn2361 : 2; /*!< Tractor Rear High Mounted Work Lights Command */
unsigned char spn2363 : 2; /*!< Tractor Side Low Mounted Work Lights Command */
unsigned char spn2365 : 2; /*!< Tractor Side High Mounted Work Lights Command */
unsigned char spn2353 : 2; /*!< Tractor Front Low Mounted Work Lights Command */
unsigned char spn2355 : 2; /*!< Tractor Front High Mounted Work Lights Command */
unsigned char spn2397 : 2; /*!< Implement OEM Option 2 Light Command */
unsigned char spn2395 : 2; /*!< Implement OEM Option 1 Light Command */
unsigned char spn2406 : 2; /*!< Implement Right Facing Work Light Command */
unsigned char spn2597 : 2; /*!< Implement Left Facing Work Light Command */
unsigned char spn2393 : 2; /*!< Lighting Data Request Command */
unsigned char spn2401 : 2; /*!< Implement Right Forward Work Light Command */
unsigned char spn2399 : 2; /*!< Implement Left Forward Work Light Command */
unsigned char spn2405 : 2; /*!< Implement Rear Work Light Command */
};
#endif
