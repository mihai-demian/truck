/**
 * try to understand FECA messages creation and decomposition
 */

#include <stdio.h>
#include "../include/saej1939.h"

unsigned char data[] = {
	/* 0 */ 0x00, 0x97, 0x03, 0x8A, /* spn=1208, fmi=3, cm=1, oc=10 in v1 */
	/* 4 */ 0x97, 0x00, 0x03, 0x8A, /* spn=1208, fmi=3, cm=1, oc=10 in v2 */
	/* 8 */ 0xB8, 0x04, 0x03, 0x8A, /* spn=1208, fmi=3, cm=1, oc=10 in v3 */
	/* 12 */0xB8, 0x04, 0x03, 0x0A, /* spn=1208, fmi=3, cm=1, oc=10 in v4 */
	/* These messages are taken from the cluster using candump. */
	/* 18ECFF17#200E0002FFCAFE00 */
	/* 18EBFF17#01C0FF13F4A4FE44 */
	/* 18EBFF17#0201248143F86481 */
	/* When sent back: */
	/* 16 */0x13, 0xF4, 0xA4, 0xFE, /* displays spn 8101 on cluster */
	/* 20 */0x44, 0x01, 0x24, 0x81, /* nothing is displyed */
	/* 24 */0x43, 0xF8, 0x64, 0x81, /* nothing is displyed */
	/* Taken from a truck */
	/* 28 */0x21, 0x7D, 0x03, 0x87, /* displays spn 3048 on cluster */
	/* 32 */0x21, 0x7D, 0x23, 0x87,
	/* 36 */0x51, 0xF4, 0x20, 0x00,
	/* 40 */0x51, 0x8F, 0xC8, 0x86,
	/* 44 */0x51, 0x91, 0x44, 0x8B,
	/* 48 */0x01, 0xF4, 0x20, 0x00,
	/* 52 */0x21, 0xF7, 0xA4, 0x8F,
	/* 56 */0x21, 0xF8, 0xC4, 0x85,
	/* 60 */0x21, 0xF8, 0xC4, 0x87,
	/* 64 */0x21, 0xF8, 0xE4, 0x86,
	/* 68 */0x51, 0xA9, 0xE2, 0x85, /* */
	/* 72 */0x11, 0x00, 0x08, 0x8A, /* displays spn 2048 on cluster */
};

int main (int argc, char *argv[])
{
	union as {
		struct spns65226 dm1;
		unsigned char bytes[8];
	} message;
	int spnv1, spnv2, spnv34;
	int fmiv1, fmiv2, fmiv34;
	int ocv1, ocv2, ocv34;
	int cmv1, cmv2, cmv34;
	unsigned long int i;
	for (i = 0; i < sizeof(data); i+=4) {
		message.bytes[2] = data[i];
		message.bytes[3] = data[i+1];
		message.bytes[4] = data[i+2];
		message.bytes[5] = data[i+3];
		spnv1 = spnno_from_spns1214_v1(&message.dm1.fail.v1);
		spnv2 = spnno_from_spns1214_v2(&message.dm1.fail.v2);
		spnv34= spnno_from_spns1214_v34(&message.dm1.fail.v34);
		/* fmi, oc, and cm should be the same */
		fmiv1  = message.dm1.fail.v1 .spn1215;
		fmiv2  = message.dm1.fail.v2 .spn1215;
		fmiv34 = message.dm1.fail.v34.spn1215;
		ocv1   = message.dm1.fail.v1 .spn1216;
		ocv2   = message.dm1.fail.v2 .spn1216;
		ocv34  = message.dm1.fail.v34.spn1216;
		cmv1   = message.dm1.fail.v1 .spn1706;
		cmv2   = message.dm1.fail.v2 .spn1706;
		cmv34  = message.dm1.fail.v34.spn1706;

		printf ("spnv1 = %d, fmiv1 = %d, cmv1 = %d, ocv1 = %d\n", spnv1, fmiv1, cmv1, ocv1);
		printf ("spnv2 = %d, fmiv2 = %d, cmv2 = %d, ocv2 = %d\n", spnv2, fmiv2, cmv2, ocv2);
		printf ("spnv34= %d, fmiv34= %d, cmv34= %d, ocv34= %d\n", spnv34, fmiv34, cmv34, ocv34);
	}
	printf ("\n");
}
