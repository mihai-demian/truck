#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/saej1939_73.h"



int main (int argc, char *argv[])
{
	if (argc != 2) {
		printf ("Usage: %s can-frame(8 bytes)\n", argv[0]);
	}

	unsigned char buf[8];
	int i;
	unsigned int spnv1, spnv2, spnv3;

	struct dm1 {
		union {
			struct spns65226 pgn65226;
			unsigned char bytes[8];
		};
		unsigned int pgnno;
	} dm1;

	sscanf (argv[1], "%2X%2X%2X%2X%2X%2X%2X%2X", &buf[0], &buf[1], &buf[2], &buf[3], &buf[4], &buf[5], &buf[6], &buf[7]);

	for (i = 0; i < 8; i++) {
		dm1.bytes[i] = buf[i];
	}
	spnv1 = spnno_from_spns1214_v1 (&dm1.pgn65226.fail.v1);
	spnv2 = spnno_from_spns1214_v2 (&dm1.pgn65226.fail.v2);
	spnv3 = spnno_from_spns1214_v34 (&dm1.pgn65226.fail.v34);

	printf ("The 3 spns are:\n");
	printf ("v1: %u, v2: %u, v3/v4: %u", spnv1, spnv2, spnv3);
	printf ("\n");

}
