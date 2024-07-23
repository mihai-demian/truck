#include <stdio.h>
#include <stdlib.h>
#include "../include/saej1939.h"

int main (int argc, char *argv[])
{
	int spn, fmi, oc;
	int i;
	struct dm1 {
		union {
			struct spns65226 pgn65226;
			unsigned char b[8];
		};
	} dm1;
	if (argc < 4) {
		printf ("Usage: %s spn fmi oc\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	for (i = 0; i < 8; i++)
		dm1.b[i] = 0xFF;

	spn = atoi (argv[1]);
	fmi = atoi (argv[2]);
	oc = atoi (argv[3]);

	dm1.pgn65226.fail.v1 = spns1214_from_spnno_v1 (spn, fmi, oc);
	for (i = 0; i < 8; i++)
		printf ("%02X ", dm1.b[i]);
	printf ("\n");
}
