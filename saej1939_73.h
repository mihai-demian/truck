#ifndef _J1939_71_H_
#define _J1939_71_H_
/**
 * \file
 * \brief Relevant information described in the J1939-73 standard.
 */
/**
 * \def bit masks
 * \brief byte masks
 */
#define FMI_MASK 0x1F
#define B2SPN_MASK 0xE0
#define UINT_B0SPN (~(~0 << 8))
/**
 * \def bit shifting
 * \brief bit shifting operations
 */
#define B1SPN_SHIFT 8
#define B2SPN_SHIFT 16
/**
 * \struct spnfmi
 * \brief
 */
struct spnfmi_s {
    unsigned char spnb3    ; /*!< LSB of SPN */
    unsigned char spnb2    ; /*!< 2nd byte of SPN */
    unsigned char fmi   : 3; /*!< Failure Mode Indicator */
    unsigned char spnb1 : 5; /*!< MSB of SPN */
    unsigned char oc    : 7; /* Occurence Count */
    unsigned char cm    : 1; /* Conversion Method */
};
/**
 * \union spnfmi
 * \brief union between struct spnfmi and unsigned long int.
 */
union spnfmi {
    struct spnfmi_s scatter;
    unsigned char   gather[4];
};
/**
 * \struct lamps_status
 * \brief contains the lamp names within the DM1
 */
struct lamps_status {
    unsigned char pls   : 2; /*!< protect lamp status, 00-off, 01-on */
    unsigned char awls  : 2; /*!< amber warning light status 00-off, 01-on */
    unsigned char rsls  : 2; /*!< red stop lamp status 00-off, 01-on */
    unsigned char mils  : 2; /*!< malfunction indicator lamp status 00-off, 01-on */

};
struct lamps_flash {
    unsigned char fpl   : 2; /*!< flash protect lamp 00-1Hz, 01-2Hz*/
    unsigned char fawl  : 2; /*!< flash amber warning light 00-1Hz, 01-2Hz */
    unsigned char frsl  : 2; /*!< flash red stop lamp 00-1Hz, 01-2Hz */
    unsigned char fmil  : 2; /*!< flash malfunction indicator lamp 00-1Hz, 01-2Hz */
};
/**
 * \union lamps
 * \brief union between struct lamps_s and an array of 2 bytes.
 */
struct lamps {
    union {
        struct lamps_status ls;
        unsigned char status;
    } statuses;
    union {
        struct lamps_flash lf;
        unsigned char  flash;
    } flashes;
};
/**
 * \struct spns65226
 * \brief Reprezents the contents of DM1 (Active Diagnostic Trouble Codes) message used in cyclic transmission.
 *
 * Transmission 1 s; default priority 6.
 * \Note When the Occurence count is not available it should be set all ones which is a value of 127.
 */
struct spns65226 {
    struct lamps lamps;
    union spnfmi  dtc;
    unsigned char u0[2]    ; /* unsused, filled with 0xFF */
};
/**
 * \struct spns65226_bcm
 * \brief Reprezents the contents of DM1 (Active Diagnostic Trouble Codes) message used in cyclic BAM transmission,
 * when there is more than one active fault message.
 *
 * Transmission on change; default priority 6.
 */
struct spns65226_bcm {
    struct lamps   lamps;
    union spnfmi  dtc[DF_MAX_LEN - 2];
};

/**
 * \brief Create an SPN number from the \ref dm1_message struct.
 * \param dm pointer to a \ref dm1_message part of an union
 * \returns a number containig the SPN
 */
//unsigned int dm1frame_to_spn (struct spns65226 const *structin);

/**
 * \brief Create a \ref dm1_message SPN part of tMAXFRAhe union from a number.
 * \param dm pointer to a \ref dm1_message struct
 * \param spn_no the spn number to conert
 * \returns 0 on success, -1 on error
 */
//int spn_to_dm1frame (dm1_message_u *dm, unsigned int spn_no);
#endif /* _SAEJ1939_71_H */
