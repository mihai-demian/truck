#include <stdio.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <linux/can/j1939.h>

#include "../include/saej1939.h"

struct v3 {
	unsigned long int spn;
	unsigned char fmi;
	unsigned char cm;
	unsigned char oc;
};

struct v3 version_3 (union spnfmi *dtc);

int main ()
{
	struct sockaddr_can sock = {.can_family = AF_CAN,
		.can_addr.j1939 = {.addr = J1939_NO_ADDR, .name = J1939_NO_NAME, .pgn = J1939_NO_PGN}},
	peer = {.can_family = AF_CAN,
		.can_addr.j1939 = {.addr = J1939_NO_ADDR, .name = J1939_NO_NAME, .pgn = J1939_NO_PGN}};
	struct v3 diag;
	char buffer[DF_MAX_LEN];
	socklen_t peerlen = sizeof(peer);
	int ret_val, recvlen, broadcast = 1;
	int sock_fd, peer_fd;
	int i, j, k;
	struct spns65226_bcm pgn65226_bcm;
	sock.can_ifindex = if_nametoindex ("can0");
	sock_fd = socket(PF_CAN, SOCK_DGRAM, CAN_J1939);
	ret_val = setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast));
	if (ret_val < 0)
		fprintf (stderr, "Error setting socket options\n");
	ret_val = bind (sock_fd, (void *)&sock, sizeof (sock));
	if (ret_val < 0)
		fprintf (stderr, "Error bind\n");
	while (1) {
		recvlen = recvfrom (sock_fd, buffer, sizeof(buffer), 0, (void *)&peer, &peerlen);
		if (recvlen < 0)
			fprintf (stderr, "Error reading from socket peer...\n");
		if (peer.can_addr.j1939.pgn == 0xFECA) {
			pgn65226_bcm.lamps.statuses.status = buffer[0];
			pgn65226_bcm.lamps.flashes.flash   = buffer[1];
			for (i = 2, j = 0, k = 0; i < recvlen; i++, k++) {
				pgn65226_bcm.dtc[j].gather[k] = buffer[i];
				if (k == 3) {
					k = 0;
					j++;
				}
			}
		}
		printf ("Received from: %.2x, pgn: %d, len: %d\n", peer.can_addr.j1939.addr, peer.can_addr.j1939.pgn, recvlen);
		printf ("pgn65226_bcm.lamps.scatter:\n");
		printf ("pls\tawls\trsls\tmils\tfpl\tfawl\tfrsl\tfmil\n");
		printf ("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
				pgn65226_bcm.lamps.statuses.ls.pls,
				pgn65226_bcm.lamps.statuses.ls.awls,
				pgn65226_bcm.lamps.statuses.ls.rsls,
				pgn65226_bcm.lamps.statuses.ls.mils,
				pgn65226_bcm.lamps.flashes.lf.fpl,
				pgn65226_bcm.lamps.flashes.lf.fawl,
				pgn65226_bcm.lamps.flashes.lf.frsl,
				pgn65226_bcm.lamps.flashes.lf.fmil);
		printf ("SPN\tFMI\tCM\tOC\n");
		for (i = 0; i < recvlen / 4; i++) {
			diag = version_3 (&pgn65226_bcm.dtc[i]);
			printf ("%ld\t%d\t%d\t%d", diag.spn, diag.fmi, diag.cm, diag.oc);
			printf ("\n");
		}
		printf ("\n");
	}

}

/**
 * \brief returns the first 2 bytes of the received bcm, representing the lamp status and flash.
 */
// struct spns65226 lamps (struct spns65226_bcm bcm);
// {
//
// }
/**
 * \brief returns the dtc of the bcm using version 1 of the interpretation.
 */
// struct spnfmi version_1 (struct spns65226_bcm bcm)
// {
//
// }
/**
 * \brief returns the dtc of the bcm using version 2 of the interpretation.
 */
// struct spnfmi version_2 (struct spns65226_bcm bcm)
// {
//
// }
/**
 * \brief returns the dtc of the bcm using version 3 of the interpretation.
 */
struct v3 version_3 (union spnfmi *dtc)
{
	struct v3 out;
	const unsigned char ocm = (~0) >> 1;
	const unsigned char cmm = 1 << 7;
	const unsigned char fmim = (~0) >> 3;
	const unsigned char msb3m = (~0) << 5;
	out.oc = (dtc->gather[3] & ocm);
	out.cm = (dtc->gather[3] & cmm) >> 7;
	out.fmi = dtc->gather[2] & fmim;
	out.spn = (((dtc->gather[2] & msb3m)>> 5) << 16)
		+ ((dtc->gather[1]) << 8) + dtc->gather[0];
	return out;
}
/**
 * \brief returns the dtc of the bcm using version 4 of the interpretation.
 * \note: the returned result is WRONG if CM == 1!!!
 */
// struct spnfmi version_4 (struct spns65226_bcm bcm)
// {
//
// }
