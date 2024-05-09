My missunderstanding of DM1 (FECA) messages grows by the day...
if i send the message 18FECA00#55FFB804030AFFFF, the cluster displays the diagnosis message 16416.
if i send the message 18FECA00#55FF0804030AFFFF, the cluster displays the diagnosis message 16416.

I think I've cracked it! 
The encoding is done using version 1 of standard, but with a mask of 0x0F of byte 3(closest to can id).

Using feva_v1.c together with saej1939_73.c

spnv1 = 1208, fmiv1 = 3, cmv1 = 1, ocv1 = 10 - test from saej1939-73 standard

spnv2 = 309248, fmiv2 = 3, cmv2 = 1, ocv2 = 10 - test from saej1939-73 standard

spnv34= 38656, fmiv34= 3, cmv34= 1, ocv34= 10 - test from saej1939-73 standard

spnv1 = 14336, fmiv1 = 3, cmv1 = 1, ocv1 = 10 - test from saej1939-73 standard

spnv2 = 1208, fmiv2 = 3, cmv2 = 1, ocv2 = 10 - test from saej1939-73 standard

spnv34= 151, fmiv34= 3, cmv34= 1, ocv34= 10 - test from saej1939-73 standard

spnv1 = 16416, fmiv1 = 3, cmv1 = 1, ocv1 = 10 - test from saej1939-73 standard

spnv2 = 9664, fmiv2 = 3, cmv2 = 1, ocv2 = 10 - test from saej1939-73 standard

spnv34= 1208, fmiv34= 3, cmv34= 1, ocv34= 10 - test from saej1939-73 standard

spnv1 = 16416, fmiv1 = 3, cmv1 = 0, ocv1 = 10 - test from saej1939-73 standard

spnv2 = 9664, fmiv2 = 3, cmv2 = 0, ocv2 = 10 - test from saej1939-73 standard

spnv34= 1208, fmiv34= 3, cmv34= 0, ocv34= 10 - test from saej1939-73 standard

spnv1 = 8101, fmiv1 = 4, cmv1 = 1, ocv1 = 126 - ECAM Control unit defective; RAM fault

spnv2 = 499869, fmiv2 = 4, cmv2 = 1, ocv2 = 126

spnv34= 390163, fmiv34= 4, cmv34= 1, ocv34= 126

spnv1 = 8201, fmiv1 = 4, cmv1 = 1, ocv1 = 1 - ECAM Control unit defective; watchdog reset

spnv2 = 2593, fmiv2 = 4, cmv2 = 1, ocv2 = 1

spnv34= 65860, fmiv34= 4, cmv34= 1, ocv34= 1

spnv1 = 8131, fmiv1 = 4, cmv1 = 1, ocv1 = 1 - STON Failure of vehicle identification message (chassis number) - I do not send it

spnv2 = 508443, fmiv2 = 4, cmv2 = 1, ocv2 = 1

spnv34= 260163, fmiv34= 4, cmv34= 1, ocv34= 1

spnv1 = 3048, fmiv1 = 3, cmv1 = 1, ocv1 = 7 - EDC Overrun test undervoltage monitoring

spnv2 = 256264, fmiv2 = 3, cmv2 = 1, ocv2 = 7

spnv34= 32033, fmiv34= 3, cmv34= 1, ocv34= 7

spnv1 = 3049, fmiv1 = 3, cmv1 = 1, ocv1 = 7

spnv2 = 256265, fmiv2 = 3, cmv2 = 1, ocv2 = 7

spnv34= 97569, fmiv34= 3, cmv34= 1, ocv34= 7

spnv1 = 4001, fmiv1 = 0, cmv1 = 0, ocv1 = 0

spnv2 = 500361, fmiv2 = 0, cmv2 = 0, ocv2 = 0

spnv34= 128081, fmiv34= 0, cmv34= 0, ocv34= 0

spnv1 = 3198, fmiv1 = 8, cmv1 = 1, ocv1 = 6

spnv2 = 293518, fmiv2 = 8, cmv2 = 1, ocv2 = 6

spnv34= 429905, fmiv34= 8, cmv34= 1, ocv34= 6

spnv1 = 3210, fmiv1 = 4, cmv1 = 1, ocv1 = 11

spnv2 = 297610, fmiv2 = 4, cmv2 = 1, ocv2 = 11

spnv34= 168273, fmiv34= 4, cmv34= 1, ocv34= 11

spnv1 = 4001, fmiv1 = 0, cmv1 = 0, ocv1 = 0

spnv2 = 499721, fmiv2 = 0, cmv2 = 0, ocv2 = 0

spnv34= 128001, fmiv34= 0, cmv34= 0, ocv34= 0

spnv1 = 4029, fmiv1 = 4, cmv1 = 1, ocv1 = 15

spnv2 = 506125, fmiv2 = 4, cmv2 = 1, ocv2 = 15

spnv34= 390945, fmiv34= 4, cmv34= 1, ocv34= 15

spnv1 = 4038, fmiv1 = 4, cmv1 = 1, ocv1 = 5

spnv2 = 508174, fmiv2 = 4, cmv2 = 1, ocv2 = 5

spnv34= 456737, fmiv34= 4, cmv34= 1, ocv34= 5

spnv1 = 4038, fmiv1 = 4, cmv1 = 1, ocv1 = 7

spnv2 = 508174, fmiv2 = 4, cmv2 = 1, ocv2 = 7

spnv34= 456737, fmiv34= 4, cmv34= 1, ocv34= 7

spnv1 = 4039, fmiv1 = 4, cmv1 = 1, ocv1 = 6

spnv2 = 508175, fmiv2 = 4, cmv2 = 1, ocv2 = 6

spnv34= 522273, fmiv34= 4, cmv34= 1, ocv34= 6

spnv1 = 3407, fmiv1 = 2, cmv1 = 1, ocv1 = 5

spnv2 = 346767, fmiv2 = 2, cmv2 = 1, ocv2 = 5

spnv34= 502097, fmiv34= 2, cmv34= 1, ocv34= 5

spnv1 = 2048, fmiv1 = 8, cmv1 = 1, ocv1 = 10

spnv2 = 136, fmiv2 = 8, cmv2 = 1, ocv2 = 10

spnv34= 17, fmiv34= 8, cmv34= 1, ocv34= 10

