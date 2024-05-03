#ifndef _J1939_73_H_
#define _J1939_73_H_
/**
 * \file saej1939_73.h
 * \brief Relevant information described in the J1939-73 standard.
 */

/**
 * \struct spns1214v1
 * \brief Helper struct for creating the spns65226 and 65226_bcm structs,
 * based on version 1 of interpretation.
 */
struct spns1214v1 {
	unsigned char spn1214_2		; /*!< MSB of SPN */
	unsigned char spn1214_1		; /*!< 2nd byte of SPN */
	unsigned char spn1215	: 5	; /*!< Failure Mode Indicator (FMI) - Defines the type of failure detected. */
	unsigned char spn1214_0	: 3	; /*!< 3 LSB of SPN */
	unsigned char spn1216	: 7	; /*!< Occurence Count (OC) */
	unsigned char spn1706	: 1	; /*!< Conversion Method (CM) */
};

/**
 * \struct spns1214v2
 * \brief Helper struct for creating the spns65226 and 65226_bcm structs,
 * based on version 2 of interpretation.
 */
struct spns1214v2 {
	unsigned short spn1214_1; 	 /*!< MSB of SPN */
	unsigned char  spn1215	: 5; /*!< Failure Mode Indicator (FMI) - Defines the type of failure detected. */
	unsigned char  spn1214_0: 3; /*!< 3 LSB of SPN */
	unsigned char  spn1216	: 7; /*!< Occurence Count (OC) */
	unsigned char  spn1706	: 1; /*!< Conversion Method (CM) */
};


/**
 * \struct spns1214v34
 * \brief Helper struct for creating the spns65226 and 65226_bcm structs,
 * based on version 3 and 4 of interpretation.
 * Contains the 19-bit Suspect Parameter Number (SPN), Failure Mode Identification (FMI),
 * and Occurence Count (OC). The Conversion Method (CM) differes from v3 to v4, but the data
 * structure is the same.
 * \note In my endeavour to keep declaration names consistent throughtout the header files,
 * the names may not exactly overlap with the functions they represent.
 */
struct spns1214v34 {
	unsigned short spn1214_0; 	 /*!< LSB of SPN */
	unsigned char  spn1215	: 5; /*!< Failure Mode Indicator (FMI) - Defines the type of failure detected. */
	unsigned char  spn1214_1: 3; /*!< 3 MSB of SPN */
	unsigned char  spn1216	: 7; /*!< Occurence Count (OC) */
	unsigned char  spn1706	: 1; /*!< Conversion Method (CM) */
};

/**
 * \union spns1214
 * \brief helper union for creating the DM1, DM2, and the respective bcm messages.
 */
union spns1214 {
	struct spns1214v1   v1;
	struct spns1214v2   v2;
	struct spns1214v34  v34;
};

/**
 * \struct lamps_status
 * \brief  Helper struct for creating the spns65226 and 65226_bcm structs.
 * Contains the lamp status and lamp flash SPNs within the DM1
 */
struct lamp_status {
	unsigned char spn987 : 2; /*!< protect lamp status, 00-off, 01-on */
	unsigned char spn624 : 2; /*!< amber warning light status 00-off, 01-on */
	unsigned char spn623 : 2; /*!< red stop lamp status 00-off, 01-on */
	unsigned char spn1213: 2; /*!< malfunction indicator lamp status 00-off, 01-on */
	unsigned char spn3041: 2; /*!< flash protect lamp 00-1Hz, 01-2Hz, 11-na/don't flash*/
	unsigned char spn3040: 2; /*!< flash amber warning light 00-1Hz, 01-2Hz , 11-na/don't flash*/
	unsigned char spn3039: 2; /*!< flash red stop lamp 00-1Hz, 01-2Hz , 11-na/don't flash*/
	unsigned char spn3038: 2; /*!< flash malfunction indicator lamp 00-1Hz, 01-2Hz , 11-na/don't flash*/
};
/**
 * \struct spns65226
 * \brief Reprezents the contents of DM1 (Active Diagnostic Trouble Codes) and
 * DM2 (Previously Active Diagnostic Trouble Codes, pgn65227) message used in cyclic transmission.
 *
 * Transmission 1 s; default priority 6.
 * \Note When the Occurence count is not available it should be set all ones which is a value of 127.
 */
struct spns65226 {
	struct lamp_status	ls;
	union spns1214		fail;
	unsigned char		u0[2]; /* not sused, filled with 0xFF */
};

/**
 * \struct spns65226_bcm
 * \brief Reprezents the contents of DM1 (Active Diagnostic Trouble Codes) message used in cyclic BAM transmission,
 * when there is more than one active fault message.
 *
 * Transmission on change; default priority 6.
 */
struct spns65226_bcm {
	struct lamp_status	ls;
	union spns1214		fail[445];
	unsigned char		u0[3]; /* not used */
};

/**
 * \brief All the Previously Active Diagnostic Trouble Codes should be erased using DM3
 * (Diagnostic Data Clear/Reset Of Previously Active DTCs). The diagnostic data
 * associated with active trouble codes will not be affected. On request using PGN 59904.
 * A positive acknowledgement or a nevative acknowledgement shall be sent back, unless
 * the request was sent to the global address.
 * Data length = 0.
 */
extern const unsigned int pgn65228; // = 0x00FECC;

/**
 * \brief All the Active Diagnostic Trouble Codes should be erased using DM11
 * (Diagnostic Data Clear/Reset For Active DTCs). On request using PGN 59904.
 * A positive acknowledgement or a nevative acknowledgement shall be sent back, unless
 * the request was sent to the global address.
 * Data length = 0.
 */
extern const unsigned int pgn65235; // = 0x00FED3;

/**
 * \brief Convert to and from struct spn1214 (part of DM1) to readable integer numbers.
 */
/**
 * \brief Converts a spns1214 struct to an integer number.
 * \param s - pointer to spns1214 struct
 * \return the formatted value of spns1214 for sending to cluster.
 */
unsigned int spnno_from_spns1214_v1 (struct spns1214v1 *s);
unsigned int spnno_from_spns1214_v2 (struct spns1214v2 *s);
unsigned int spnno_from_spns1214_v34 (struct spns1214v34 *s);

/**
 * \brief Converts a spns1214 struct to an integer number.
 * \param spnno SPN number
 * \param fmino FMI number
 * \param ocno Occurence count
 * \return struct spns1214 according to conversion version
 */
struct spns1214v1
spns1214_from_spnno_v1 (unsigned int spnno, unsigned int fmino, unsigned int ocno);
struct spns1214v2
spns1214_from_spnno_v2 (unsigned int spnno, unsigned int fmino, unsigned int ocno);
struct spns1214v34
spns1214_from_spnno_v3 (unsigned int spnno, unsigned int fmino, unsigned int ocno);
struct spns1214v34
spns1214_from_spnno_v4 (unsigned int spnno, unsigned int fmino, unsigned int ocno);
#endif /* _SAEJ1939_73_H */
