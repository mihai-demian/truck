#ifndef _J1939_21_H_
#define _J1939_21_H_
#ifdef __cplusplus
extern "C" {
#endif
/**
 * \file saej1939_21.h
 * \brief Relevant information described in the J1939-21 standard (Data Link layer).
 */
/**
 * \def standard_sizes
 * \brief various defines
 */
enum saej1939_21_sizes {
	ONEFRAMELEN = 8,	/*!< Maximum length of the Data field */
#define ONEFRAMELEN ONEFRAMELEN
	PDUTHRESHOLD = 240,	/*!< Defines the boundary between PDU1 and PDU2 */
#define PDUTHRESHOLD PDUTHRESHOLD
	DFMAXLEN = 1785,	/*!< Standard data field length */
#define DFMAXLEN DFMAXLEN
};

/**
 * \def standard_priorities
 * \brief define standard priorities
 */
enum saej1939_21_priorities {
	CNTRPRIO = 3,	/*!< Defines the default priority transport protocol messages. */
#define CNTRPRIO CNTRPRIO
	OTHRPRIO = 6,	/*!< Defines the default priority for all other messages. */
#define OTHRPRIO OTHRPRIO
	BAMPRIO = 7,	/*!< Defines the default control message priority (status). */
#define BAMPRIO	BAMPRIO
};

/**
 * \def unused
 * macro definitions reprezenting values for unused bytes, shorts and ints
 */
const unsigned char ONEUNUSED = 0xFF;
#define	ONEUNUSED	ONEUNUSED
const unsigned short TWOUNUSED = 0xFFFF;
#define	TWOUNUSED	TWOUNUSED
const unsigned int FOURUNUSED = 0xFFFFFFFF;
#define	FOURUNUSED	FOURUNUSED

/**
 * \def error_indication
 * macro definitions reprezenting values for erronious phisical values, shorts and ints
 */
const unsigned char		ONEERROR = 0xFE;
#define ONE_ERROR	ONEERROR
const unsigned short	TWOERROR = 0xFEFF;
#define TWO_ERROR	TWOERROR
const unsigned int		FOURERROR = 0xFEFFFFFF;
#define FOUR_ERROR	FOURERROR

/**
 * \enum saej1939_21_bit_values
 * \brief used to represent all two, three, four, and five bit values throughtout the J1939 stadard.
 * This values could be found under different names, such OFF or not pressed or deactivated.
 * The names are the binary reprezentation of the value used in the standard.
 */
enum bit_values {
	B00		=	0,
#define	B00	B00
	B01		=	1,
#define B01	B01
	B10		=	2,
#define	B10	B10
	B11		=	3,
#define	B11	B11
	B100	=	4,
#define	B100	B100
	B101	=	5,
#define	B101	B101
	B110	=	6,
#define	B110	B110
	B111	=	7,
#define	B111	B111
	B1000	=	8,
#define	B1000	B1000
	B1001	=	9,
#define	B1001	B1001
	B1010	=	10,
#define	B1010	B1010
	B1011	=	11,
#define B1011	B1011
	B1100	=	12,
#define	B1100	B1100
	B1101	=	13,
#define	B1101	B1101
	B1110	=	14,
#define	B1110	B1110
	B1111	=	15,
#define	B1111	B1111
	B10000	=	16,
#define	B10000	B10000
	B10001	=	17,
#define B10001	B10001
	B10010	=	18,
#define B10010	B10010
	B10011	=	19,
#define	B10011	B10011
	B10100	=	20,
#define B10100	B10100
	B10101	=	21,
#define	B10101	B10101
	B10110	=	22,
#define	B10110	B10110
	B10111	=	23,
#define B10111	B10111
	B11000	=	24,
#define	B11000	B11000
	B11001	=	25,
#define	B11001	B11001
	B11010	=	26,
#define B11010	B11010
	B11011	=	27,
#define	B11011	B11011
	B11100	=	28,
#define B11100	B11100
	B11101	=	29,
#define	B11101	B11101
	B11110	=	30,
#define	B11110	B11110
	B11111	=	31,
#define	B11111	B11111
};

/**
 * \struct spns59904
 * \brief Request PGN
 * Len 3B, prio 6
 * PGN 59904 (00EA00)
 * The data field contains the requested PGN.
 */
struct spns59904 {
	union {
		unsigned int	reqpgn;
		unsigned char	bytes[3]; /* one byte less than the struct spns59904 */
	} data;
	unsigned int pgnno;
};


/**
 * \struct spns59392
 * \brief Acknowledgement PGN
 * Transmission: upon receive of PGN that requires ack; length 8B; default priority 3.
 */
struct pgn59392 {
	union {
		struct spns59362 {
			unsigned char	control;	/*!< Control byte {0=Positive Acknowledgement
										 * 1=Negative Acknowledgement, 2=Access Denied, 3=Cannot respond} */
			unsigned char	grpfnct;	/*!< control group functions */
			unsigned char	u0[3];		/*!< unused, filled with 0xFF */
			unsigned int	reqpgn;		/*!< PGN of requested information */
		} pgn59362;
		unsigned char bytes[ONEFRAMELEN]; /* one byte less than the struct spns59362 */
	} data;
	unsigned int pgnno;
};
#ifdef __cplusplus
}
#endif
#endif /* _J1939_21_H_ */
