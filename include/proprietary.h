#ifdef __cplusplus
extern "C" {
#endif

/**
 * \file proprietary.h
 * \brief Contains descriptions of proprietary PGNs.
 */

/**
 * \struct spns65441
 * \brief Auxiliary state I/O body controller #1 - AUX_STAT_ZBR1 (18FFA121)
 *
 * Transmission: 1s / on change; length 8B; default priority 6.
 */
struct spns65441 {
    unsigned char u0       : 4; /*!< no function */
    unsigned char fuel_low : 2; /*!< info, fuel level low in current tank, 00=0ff, 01=on, 10=err, 11=na */
    unsigned char r_gear   : 2; /*!< reverse gear engaged (man gearbox), 00=off, 01=on, 10=err, 11=na */
    unsigned char e_off    : 2; /*!< info EMERGENCY OFF, 00=off, 01=on, 10=err, 11=na */
	unsigned char u1       : 6; /*!< unused, filled with 1s */
    unsigned char u2[6]       ; /*!< unused, filled with 0xFF */
};

/**
 * \struct spns65442
 * \brief (18FFA221)
 *
 * Transmission: 1s; length 8B; default priority 6.
 */
struct spns65442 {
	unsigned char noidea1     :2;
	unsigned char flash_abs   :2;
	unsigned char noidea3     :2;
	unsigned char tractor_abs :2;
	unsigned char noidea4     :2;
	unsigned char noidea5     :2;
	unsigned char noidea6     :2;
	unsigned char noidea7     :2;
	unsigned char park_brk    :2; /*!< parking brake lamp, 00=off, 01=on */
	unsigned char noidea8     :2;
	unsigned char eng_brk_ret :2; /*!< engine break in vehicles with retarder, 00=off, 01=on */
	unsigned char eng_brk     :2; /*!< engine break in vehicles without retarder */
	unsigned char noidea10    :2;
	unsigned char noidea11    :2;
	unsigned char noidea12    :2;
	unsigned char no_ridelvl  :2; /*!< auto level lamp + no valid level set */
	unsigned char washer_fluid:2; /*!< washer fluid warning level lamp */
	unsigned char str_oil     :2; /*!< steer oil pressure fluid low */
	unsigned char greasefault :2; /*!< grease fault on central lube icon */
	unsigned char interlock   :2; /*!< code invalid interlock active */
	unsigned char blackice    :2; /*!< black ice warning message */
	unsigned char noidea14    :2;
	unsigned char noidea15    :2;
	unsigned char noidea16    :2;
	unsigned char pto         :2; /*!< PTO lamp */
	unsigned char pto_2       :2; /*!< PTO lamp lvl 2 */
	unsigned char trailer_abs :2; /*!< traier abs */
	unsigned char pto_3       :2; /*!< PTO lamp lvl 3 */
	unsigned char retarder    :4; /*!< displayed retarder level, up to 6 */
	unsigned char noidea20    :4;
};
/**
 * \struct spns65443
 * \brief (18FFA321)
 *
 * Transmission: 1s; length 8B; default priority 6.
 */
struct spns65443 {
	unsigned char turn_left   :2; /*!< left turn indicator lamp */
	unsigned char turn_right  :2; /*!< right turn indicator lamp */
	unsigned char noidea1     :2; /*!<  */
	unsigned char noidea2     :2; /*!<  */
	unsigned char noidea3     :2; /*!<  */
	unsigned char noidea4     :2; /*!<  */
	unsigned char turn_noise  :2; /*!< turn signal click sound */
	unsigned char noidea5     :2; /*!<  */
	unsigned char high_beam   :2; /*!< high beam indicator lamp */
	unsigned char low_beam    :2; /*!< low beam indicator lamp */
	unsigned char noidea6     :2; /*!<  */
	unsigned char noidea7     :2; /*!<  */
	unsigned char noidea8     :2; /*!<  */
	unsigned char noidea9     :2; /*!<  */
	unsigned char noidea10    :2; /*!<  */
	unsigned char noidea11    :2; /*!<  */
	unsigned char li_test_st  :2; /*!< light test message */
	unsigned char noidea12    :2; /*!<  */
	unsigned char li_test_end :2; /*!< light test end message */
	unsigned char noidea13    :2; /*!<  */
	unsigned char noidea14    :2; /*!<  */
	unsigned char noidea15    :2; /*!<  */
	unsigned char eng_start   :2; /*!< engine start message */
	unsigned char r_pre_glow  :2; /*!< repeat pre-glow message */
	unsigned char li_test_ab  :2; /*!< light test abort message */
	unsigned char apply_pb    :2; /*!< apply parking break message */
	unsigned char sh_N        :2; /*!< shift to neutral message */
	unsigned char noidea16    :2; /*!<  */
	unsigned char u0            ; /*!<  */
};
/**
 * \struct spns65444
 * \brief (18FFA421)
 *
 * Transmission: 1s; length 8B; default priority 6.
 * 18FFA421#3CF3CF0000FFFFFF
 */
struct spns65444 {
	unsigned char noidea1 :2; /*!<  */
	unsigned char noidea2 :2; /*!<  */
	unsigned char noidea3 :2; /*!<  */
	unsigned char esp_fail:2; /*!< ESP failure message */
	unsigned char noidea4 :2; /*!<  */
	unsigned char noidea5 :2; /*!<  */
	unsigned char noidea6 :2; /*!<  */
	unsigned char noidea7 :2; /*!<  */
	unsigned char noidea8 :2; /*!<  */
	unsigned char noidea9 :2; /*!<  */
	unsigned char noidea10:2; /*!<  */
	unsigned char noidea11:2; /*!<  */
	unsigned char noidea12:2; /*!<  */
	unsigned char noidea13:2; /*!<  */
	unsigned char noidea14:2; /*!<  */
	unsigned char noidea15:2; /*!<  */
	unsigned char noidea16:2; /*!<  */
	unsigned char noidea17:2; /*!<  */
	unsigned char noidea18:2; /*!<  */
	unsigned char noidea19:2; /*!<  */
	unsigned char noidea20:2; /*!<  */
	unsigned char noidea21:2; /*!<  */
	unsigned char noidea22:2; /*!<  */
	unsigned char noidea23:2; /*!<  */
	unsigned char noidea24:2; /*!<  */
	unsigned char noidea25:2; /*!<  */
	unsigned char noidea26:2; /*!<  */
	unsigned char noidea27:2; /*!<  */
	unsigned char noidea28  ; /*!<  */
};
#ifdef __cplusplus
}
#endif
