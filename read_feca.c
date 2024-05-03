#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <byteswap.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <net/if.h>
#include <linux/can/j1939.h>


#include "../include/saej1939_73.h"



int main (int argc, char *argv[])
{
	unsigned char buf_bam[] = {
0x41, 0x00, 0x60, 0x09, 0x71, 0xC0, 0x5D,
0x54, 0xE0, 0x15, 0x20, 0x2F, 0x27, 0x1A,
0x70, 0x17, 0x80, 0x0C, 0x19, 0xFF, 0xFF,
	};
	unsigned char buf[8];
	int i;
	struct sockaddr_can cansend = {
		.can_family = AF_CAN,
		.can_addr.j1939 = {.pgn = J1939_NO_PGN, .name = J1939_NO_NAME, .addr = 0x00}
	};
	struct sockaddr_can dest = {
		.can_family = AF_CAN,
		.can_addr.j1939 = {.pgn = 0xFECA, .name = J1939_NO_NAME, .addr = J1939_NO_ADDR}
	};
	struct timeval last, now, interval = {.tv_sec = 1, .tv_usec = 0};
	cansend.can_ifindex = if_nametoindex ("vcan0");
	int cansend_sock, broadcast = 1;


	unsigned int spnv1, spnv2, spnv3;
	struct dm1 {
		union {
			struct spns65226 pgn65226;
			unsigned char bytes[8];
		};
		unsigned int pgnno;
	} dm1;
	struct dm1_bam {
		union {
			struct spns65226_bcm pgn65226_bam;
			unsigned char bytes[1785];
		};
		unsigned int pgnno;
	} dm1_bam;

	//sscanf (argv[1], "%2X%2X%2X%2X%2X%2X%2X%2X", &buf[0], &buf[1], &buf[2], &buf[3], &buf[4], &buf[5], &buf[6], &buf[7]);
	//sscanf (argv[2], "%2X", &cansend.can_addr.j1939.addr);

	cansend_sock = socket (PF_CAN, SOCK_DGRAM, CAN_J1939);
	setsockopt (cansend_sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast));
	bind (cansend_sock, (struct sockaddr *) &cansend, sizeof (cansend));

	for (i = 0; i < sizeof(buf_bam); i++) {
		dm1_bam.bytes[i] = buf_bam[i];
	}
	printf ("The 3 spns are:\n");

	for (i = 0; i < (sizeof(buf_bam) - 2) / 4; i++ ) {
		spnv1 = spnno_from_spns1214_v1  (&dm1_bam.pgn65226_bam.fail[i].v1);
		spnv2 = spnno_from_spns1214_v2  (&dm1_bam.pgn65226_bam.fail[i].v2);
		spnv3 = spnno_from_spns1214_v34 (&dm1_bam.pgn65226_bam.fail[i].v34);
		printf ("v1: %u,\tv2: %u,\tv3/v4: %u\n", spnv1, spnv2, spnv3);
	}
	printf ("\n");
	dm1.pgn65226.ls.spn987  = 1;
	dm1.pgn65226.ls.spn624  = 1;
	dm1.pgn65226.ls.spn623  = 1;
	dm1.pgn65226.ls.spn1213 = 3;
	dm1.pgn65226.ls.spn3041 = 3;
	dm1.pgn65226.ls.spn3040 = 3;
	dm1.pgn65226.ls.spn3039 = 3;
	dm1.pgn65226.ls.spn3038 = 3;
	//dm1.pgn65226.fail.v1 = spns1214_from_spnno_v1 (1208, 3, 10);
	dm1.pgn65226.u0[0] = 0xff;
	dm1.pgn65226.u0[1] = 0xff;

	dm1.pgn65226.fail.v1 = spns1214_from_spnno_v1 (1208, 3, 10);

	printf ("DEBUG v1: %u\n", spnno_from_spns1214_v1(&dm1.pgn65226.fail.v1));
	//while (1) {
		sendto (cansend_sock, dm1.bytes, sizeof (dm1.bytes), 0, (struct sockaddr *)&dest, sizeof (dest));
		//sleep (1);
		//break;
	//}

}
