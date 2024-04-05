#ifndef _J1939_H_
#define _J1939_H_

#include "saej1939_21.h"
#include "saej1939_71.h"
#include "saej1939_73.h"
#include "saej1939_81.h"

/**
 * \def engsa
 * \brief Source address of the engine controller
 */
#define ENGSA 0x00
/**
 *\def sizes
 * macro definitions reprezenting the engine configuration pgn size
 */
#define ENGCONFLEN 28
 /**
 * \def trssa
 * \brief Source address of the engine controller
 */
#define TRSSA 0x03
/**
 *\def sizes
 * macro definitions reprezenting the transmission configuration pgn size
 */
#define TRSCONFLEN 42
 /**
 * \def bdysa
 * \brief Source address of the engine controller
 */
#define BDYSA 0x21
 /**
 * \def brksa
 * \brief Source address of the engine controller
 */
#define BRKSA 0x0B
 /**
 * \def rtdsa
 * \brief Source address of the engine controller
 */
#define RTDSA 0x10
/**
 *\def sizes
 * macro definitions reprezenting the retarder configuration pgn size
 */
#define RTDCONFLEN 19

#endif
