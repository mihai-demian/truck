#ifndef _J1939_H_
#define _J1939_H_

#include "saej1939_21.h"
#include "saej1939_71.h"
#include "saej1939_73.h"
//#include "saej1939_81.h"

/**
 * \enum source_addresses
 * \brief Source address of the controllers
 */
// #define ENGSA 0x00 /*!< engine controller */
// #define TRSSA 0x03 /*!< transmission controller */
// #define BRKSA 0x0B /*!< brakes controller */
// #define RTDSA 0x10 /*!< retarder controller */
// #define BDYSA 0x21 /*!< body controller */
// #define MCPSA 0x27 /*!< management computer */
// #define TCOSA 0xEE /*!< tachograph */
enum source_addresses {
	ENGSA = 0x00, /*!< engine controller */
	TRSSA = 0x03, /*!< transmission controller */
	BRKSA = 0x0B, /*!< brakes controller */
	RTDSA = 0x10, /*!< retarder controller */
	CCTSA = 0x11, /*!< cruise control */
	BDYSA = 0x21, /*!< body controller */
	MCPSA = 0x27, /*!< management computer */
	TCOSA = 0xEE, /*!< tachograph */
};
/**
 *\enum conf_sizes
 * \brief Macro definitions reprezenting the configuration message size
 */
// #define ENGCONFLEN 28 /*!< Engine configuration */
// #define TRSCONFLEN 42 /*!< Transmission configuration */
// #define RTDCONFLEN 19 /*!< Retarder configuration */
// #define TCOCONFLEN 18 /*!< Tachograph VI and DI */
enum conf_sizes {
	ENGCONFLEN = 28, /*!< Engine configuration */
	TRSCONFLEN = 42, /*!< Transmission configuration */
	RTDCONFLEN = 19, /*!< Retarder configuration */
	TCOCONFLEN = 18, /*!< Tachograph VI and DI */
};
#endif
