#ifndef _J1939_H_
#define _J1939_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "saej1939_21.h"
#include "saej1939_71.h"
#include "saej1939_73.h"
#include "proprietary.h"

/**
 * \enum source_addresses
 * \brief Source address of the controllers
 */
enum source_addresses {
	ENGSA = 0x00, /*!< engine controller */
#define ENGSA ENGSA
	TRSSA = 0x03, /*!< transmission controller */
#define TRSSA TRSSA
	BRKSA = 0x0B, /*!< brakes controller */
#define BRKSA BRKSA
	RTDSA = 0x10, /*!< retarder controller */
#define RTDSA RTDSA
	ICLSA = 0x17, /*!< instrument cluster */
#define ICLSA ICLSA
	BDYSA = 0x21, /*!< body controller */
#define BDYSA BDYSA
	MCPSA = 0x27, /*!< management computer */
#define MCPSA MCPSA
	ERTSA = 0x29, /*!< retarder, exhaust, engine */
#define ERTSA ERTSA
	SUSSA = 0x2F, /*!< suspension controller */
#define SUSSA SUSSA
	PSCSA = 0x30, /*!< pneumatic controller */
#define PCSSA PCSSA
	TCOSA = 0xEE, /*!< tachograph */
#define TCOSA TCOSA
};

/**
 *\enum conf_sizes
 * \brief Macro definitions reprezenting the configuration message size
 */
enum conf_sizes {
	ENGCONFLEN = 28, /*!< Engine configuration */
#define ENGCONFLEN ENGCONFLEN
	TRSCONFLEN = 42, /*!< Transmission configuration */
#define TRSCONFLEN TRSCONFLEN
	RTDCONFLEN = 19, /*!< Retarder configuration */
#define RTDCONFLEN RTDCONFLEN
	TCOCONFLEN = 18, /*!< Tachograph VI and DI */
#define TCOCONFLEN TCOCONFLEN
};

/**
 * \enum pgn_numbers
 * \brief Definiton of all PGN numbers defined.
 */
enum pgn_numbers {
	PGN56832 = 56832,
#define PGN56832 PGN56832
	PGN59392 = 59392,
#define PGN59392 PGN59392
	PGN59904 = 59904,
#define PGN59904 PGN59904
	PGN61440 = 61440,
#define PGN61440 PGN61440
	PGN61441 = 61441,
#define PGN61441 PGN61441
	PGN61442 = 61442,
#define PGN61442 PGN61442
	PGN61443 = 61443,
#define PGN61443 PGN61443
	PGN61444 = 61444,
#define PGN61444 PGN61444
	PGN61445 = 61445,
#define PGN61445 PGN61445
	PGN65088 = 65088,
#define PGN65088 PGN65088
	PGN65089 = 65089,
#define PGN65089 PGN65089
	PGN65131 = 65131,
#define PGN65131 PGN65131
	PGN65132 = 65132,
#define PGN65132 PGN65132
	PGN65136 = 65136,
#define PGN65136 PGN65136
	PGN65196 = 65196,
#define PGN65196 PGN65196
	PGN65198 = 65198,
#define PGN65198 PGN65198
	PGN65216 = 65216,
#define PGN65216 PGN65216
	PGN65217 = 65217,
#define PGN65217 PGN65217
	PGN65223 = 65223,
#define PGN65223 PGN65223
	PGN65226 = 65226,
#define PGN65226 PGN65226
	PGN65228 = 65228,
#define PGN65228 PGN65228
	PGN65235 = 65235,
#define PGN65235 PGN65235
	PGN65249 = 65249,
#define PGN65249 PGN65249
	PGN65250 = 65250,
#define PGN65250 PGN65250
	PGN65251 = 65251,
#define PGN65251 PGN65251
	PGN65253 = 65253,
#define PGN65253 PGN65253
	PGN65254 = 65254,
#define PGN65254 PGN65254
	PGN65257 = 65257,
#define PGN65257 PGN65257
	PGN65260 = 65260,
#define PGN65260 PGN65260
	PGN65261 = 65261,
#define PGN65261 PGN65261
	PGN65262 = 65262,
#define PGN65262 PGN65262
	PGN65263 = 65263,
#define PGN65263 PGN65263
	PGN65265 = 65265,
#define PGN65265 PGN65265
	PGN65266 = 65266,
#define PGN65266 PGN65266
	PGN65269 = 65269,
#define PGN65269 PGN65269
	PGN65270 = 65270,
#define PGN65270 PGN65270
	PGN65271 = 65271,
#define PGN65271 PGN65271
	PGN65272 = 65272,
#define PGN65272 PGN65272
	PGN65274 = 65274,
#define PGN65274 PGN65274
	PGN65275 = 65275,
#define PGN65275 PGN65275
	PGN65276 = 65276,
#define PGN65276 PGN65276
	PGN65291 = 65291,
#define PGN65291 PGN65291
	PGN65441 = 65441,
#define PGN65441 PGN65441
	PGN65442 = 65442,
#define PGN6542 PGN6542
	PGN65443 = 65443,
#define PGN65443 PGN65443
	PGN65444 = 65444,
#define PGN65444 PGN65444
};

#ifdef __cplusplus
}
#endif

#endif /* _SAEJ1939_71_H */
