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
#define MAX_NO_PGNS   8672 /*!< Defines the maximum number of PGNs.*/
#define DF_MAX_LEN    1785 /*!< Maximum length of the Data field */
#define PDU_THRESHOLD 240 /*!< Defines the boundary between PDU1 and PDU2 */
#define ONEFRAMELEN   8 /*!< Standard data field length */
#define GDA_ADDR      255 /*!< Defines the global destination address */
/**
 * \def standard_priorities
 * \brief define standard priorities
 */
#define BAM_PRIO 7 /*!< Defines the default priority transport protocol messages. */
#define OTHR_PRIO 6 /*!< Defines the default priority for all other messages. */
#define CNTR_PRIO 3 /*!< Defines the default control message priority (status). */
/**
 * \def unused
 * macro definitions reprezenting values for unused bytes, shorts and ints
 */
#define ONE_UNUSED	0xFF
#define TWO_UNUSED	0xFFFF
#define FOUR_UNUSED	0xFFFFFFFF
/**
 * \def error_indication
 * macro definitions reprezenting values for erronious phisical values, shorts and ints
 */
#define ONE_ERROR	0xFE
#define TWO_ERROR	0xFEFF
#define FOUR_ERROR	0xFEFFFFFF
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

#endif /* _J1939_21_H_ */
