#ifndef _J1939_21_H_
#define _J1939_21_H_
/**
 * \file saej1939_21.h
 * \brief Relevant information described in the J1939-21 standard (Data Link layer).
 */
/**
 * \def standard_sizes
 * \brief various defines
 */
#define DF_MAX_LEN    1785 /*!< Maximum length of the Data field */
#define PDU_THRESHOLD 240  /*!< Defines the boundary between PDU1 and PDU2 */
#define ONE_FRAMELEN   8    /*!< Standard data field length */
const int DFMAXLEN = 1785, PDUTHRESHOLD = 240, ONEFRAMELEN = 8;
/**
 * \def standard_priorities
 * \brief define standard priorities
 */
// #define BAM_PRIO  7 /*!< Defines the default priority transport protocol messages. */
// #define OTHR_PRIO 6 /*!< Defines the default priority for all other messages. */
// #define CNTR_PRIO 3 /*!< Defines the default control message priority (status). */
const int BAM_PRIO = 7, OTHR_PRIO = 6, CNTR_PRIO = 3;
/**
 * \def unused
 * macro definitions reprezenting values for unused bytes, shorts and ints
 */
// #define ONE_UNUSED	0xFF
// #define TWO_UNUSED	0xFFFF
// #define FOUR_UNUSED	0xFFFFFFFF
const unsigned char		ONE_UNUSED = 0xFF;
const unsigned short	TWO_UNUSED = 0xFFFF;
const unsigned int		FOUR_UNUSED = 0xFFFFFFFF;
/**
 * \def error_indication
 * macro definitions reprezenting values for erronious phisical values, shorts and ints
 */
// #define ONE_ERROR	0xFE
// #define TWO_ERROR	0xFEFF
// #define FOUR_ERROR	0xFEFFFFFF
const unsigned char		ONE_ERROR = 0xFE;
const unsigned short	TWO_ERROR = 0xFEFF;
const unsigned int		FOUR_ERROR = 0xFEFFFFFF;
/**
 * \enum two_bit_values
 * \brief used to represent all two, three, and four bit values throughtout the J1939 stadard.
 * This values could be found under different names, such OFF or not pressed or deactivated.
 * The two_bit_values are used for different meaning in other enums. The names are the binary
 * reprezentation of the value used in the standard.
 */
enum two_bit_values {
	B00 = 0,
	B01 = 1,
	B10 = 2,
	B11 = 3
};
/**
 * \enum three_bit_values
 * \brief used to represent all values between 4 and 7.
 */
enum three_bit_values {
	B100 = 4,
	B101 = 5,
	B110 = 6,
	B111 = 7
};
/**
 * \enum four_bit_values
 * \brief used to represent all values between 8 and 15.
 */
enum four_bit_values {
	B1000 = 8,
	B1001 = 9,
	B1010 = 10,
	B1011 = 11,
	B1100 = 12,
	B1101 = 13,
	B1110 = 14,
	B1111 = 15
};
/**
 * \struct spns59904
 * \brief Request PGN
 * Len 3B, prio 6
 * PGN 59904 (00EA00)
 * The data field contains the requested PGN.
 */
struct pgn59904 {
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
struct pgn59362 {
	union {
		struct spns59362 {
			unsigned char	control;	/*!< Control byte {0=Positive Acknowledgement
										 * 1=Negative Acknowledgement, 2=Access Denied, 3=Cannot respond} */
			unsigned char	grpfnct;	/*!< control group functions */
			unsigned char	u0[3];		/*!< unused, filled with 0xFF */
			unsigned int	reqpgn;		/*!< PGN of requested information */
		} pgn59362;
		unsigned char bytes[ONE_FRAMELEN]; /* one byte less than the struct spns59362 */
	} data;
	unsigned int pgnno;
};

#endif /* _J1939_21_H_ */
