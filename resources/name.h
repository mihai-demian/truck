/**
 * \file name.h
 * \brief A simple file used for generating function prototypes.
 *
 * # Usage
 * Simply call with gcc -E >> \<some_file_name\>, remove the comments, and
 * copy the function prototypes from there to the \ref general.h header file,
 * and the functions to \ref general.c file.
 * I prototyped all functions related to converting phisical units to SPNs into the \ref general.h file.
 */
/**
 * \def constants
 * Constants used for error and not available values.
 * If a component failure prevents the transmission of valid data, the error indicator should be used.
 * If the data is valid and exceeds the defined parameter range, the error indicator should not be used.
 * The data should be transmitted using the appropriate minimum or maximum parameter value.
 */
#define	U8ERR	0xFE
#define	U16ERR	0xFEFF
#define	U32ERR	0xFEFFFFFF
#define	U8NA	0xFF
#define	U16NA	0xFFFF
#define	U32NA	0xFFFFFFFF
#define K1		0.0f
#define K2_U8	250.0f
#define K2_U16	64255.0f
#define K2_U32	4211081215.0f

/**
 * \def unit_to_u*
 * helper macro for creating function names
 */
#define UNIT_TO_U8(sc, ofs, ...)	unsigned char __VA_ARGS__##_##to##_U8_##sc##_##ofs (float in)
#define UNIT_TO_U16(sc, ofs, ...)	unsigned short __VA_ARGS__##_##to##_U16_##sc##_##ofs (float in)
#define UNIT_TO_U32(sc, ofs, ...)	unsigned int __VA_ARGS__##_##to##_U32_##sc##_##ofs (float in)
#define INT_TO_U8					unsigned char gearno_to_U8 (int in)
/**
 * \def u*_to_unit
 * helper macro for creating function names
 */
#define U8_TO_UNIT(sc, ofs, ...)	float __VA_ARGS__##_##from##_U8_##sc##_##ofs (unsigned char in)
#define U16_TO_UNIT(sc, ofs, ...)	float __VA_ARGS__##_##from##_U16_##sc##_##ofs (unsigned short in)
#define U32_TO_UNIT(sc, ofs, ...)	float __VA_ARGS__##_##from##_U32_##sc##_##ofs (unsigned int in)
#define U8_TO_INT					int U8_to_gearno (unsigned char in)

/**
 * \def sc
 * helper macro for writing the scale function
 * that takes in an integer value between K1 and K2
 * and retuns a floating-point number between lo and hi
 * based on the formula
 * (in - k1) / (k2 - k1) * (hilim - lolim) + lolim
 */
#define SC_U8(lolim, hilim)		return ((in) / (K2_U8) * ((hilim) - (lolim)) + (lolim))
#define SC_U16(lolim, hilim)	return ((in) / (K2_U16) * ((hilim) - (lolim)) + (lolim))
#define SC_U32(lolim, hilim)	return ((in) / (K2_U32) * ((hilim) - (lolim)) + (lolim))

/**
 * \def unsc
 * helper macro for writing the unscale function
 * that takes in a floating-point value between lo and hi
 * and returns an integer number between K1 and K2
 * based on the formula
 * (type)((in - lolim) / (hilim - lolim) * (k2 - k1) + k1)
 */
#define UNSC_U8(lolim, hilim)	return (unsigned char)(((in) - (lolim)) / ((hilim) - (lolim)) * (K2_U8))
#define UNSC_U16(lolim, hilim)	return (unsigned short)(((in) - (lolim)) / ((hilim) - (lolim)) * (K2_U16))
#define UNSC_U32(lolim, hilim)	return (unsigned int)(((in) - (lolim)) / ((hilim) - (lolim)) * (K2_U32))
/**
 * \def scale_u*
 * Defines the prototype and function for converting
 * a floating-point phisical value into an unsigned char, short or int
 * value usable for the SPN.
 *
 * \param[in] scale the scale used in standard, for easy corelation
 * \param[in] offset the offset used in standard, for easy corelation
 * \param[in] lo lower limit of the input value
 * \param[in] hi upper limit of the input value
 * \note lo, and hi are floating-point numbers!
 */
#define SCALE_U8(scale, offset, lo, hi, ...)\
U8_TO_UNIT(scale, offset, __VA_ARGS__){\
SC_U8(lo, hi);\
}

#define SCALE_U16(scale, offset, lo, hi, ...)\
U16_TO_UNIT(scale, offset, __VA_ARGS__){\
SC_U16(lo, hi);\
}

#define SCALE_U32(scale, offset, lo, hi, ...)\
U32_TO_UNIT(scale, offset, __VA_ARGS__){\
SC_U32(lo, hi);\
}
/**
 * \def unscale_u*
 * Defines the prototype and function for converting
 * a floating-point number reprezenting a phisical unit
 * into an unsigned char, short, or int.
 *
 * \param[in] scale the scale used in standard, for easy corelation
 * \param[in] offset the offset used in standard, for easy corelation
 * \param[in] lo lower limit of the input value
 * \param[in] hi upper limit of the input value
 * \note lo, and hi are floating-point numbers!
 */
#define UNSCALE_U8(scale, offset, lo, hi, ...)\
UNIT_TO_U8(scale, offset, __VA_ARGS__){\
if ((in) < (lo)) (in) = (lo);\
if ((in) > (hi)) (in) = (hi);\
UNSC_U8(lo, hi);\
}
#define UNSCALE_U16(scale, offset, lo, hi, ...)\
UNIT_TO_U16(scale, offset, __VA_ARGS__){\
if ((in) < (lo)) (in) = (lo);\
if ((in) > (hi)) (in) = (hi);\
UNSC_U16(lo, hi);\
}
#define UNSCALE_U32(scale, offset, lo, hi, ...)\
UNIT_TO_U32(scale, offset, __VA_ARGS__){\
if ((in) < (lo)) (in) = (lo);\
if ((in) > (hi)) (in) = (hi);\
UNSC_U32(lo, hi);\
}
#define GEARNO_TO_U8 \
INT_TO_U8 {\
return (unsigned char)(in + 125);\
}
#define U8_TO_GEARNO \
U8_TO_INT {\
return in - 125;\
}

/* header file
 * !!! End lines with ;
 */
INT_TO_U8;
U8_TO_INT;
UNIT_TO_U32	(5m,		0,			distance);
U32_TO_UNIT	(5m,		0,			distance);
UNIT_TO_U16	(512kml,	0,			eco_liquid);
U16_TO_UNIT	(512kml,	0,			eco_liquid);
UNIT_TO_U16	(005v,		0,			voltage);
U16_TO_UNIT	(005v,		0,			voltage);
UNIT_TO_U16	(001,		0,			gearratio);
U16_TO_UNIT	(001,		0,			gearratio);
UNIT_TO_U16	(00025,		0,			percent);
UNIT_TO_U8	(1,			n125,		percent);
UNIT_TO_U8	(08,		n100,		percent);
UNIT_TO_U8	(1,			0,			percent);
UNIT_TO_U8	(01,		0,			percent);
UNIT_TO_U8	(04,		0,			percent);
U16_TO_UNIT	(00025,		0,			percent);
U8_TO_UNIT	(1,			n125,		percent);
U8_TO_UNIT	(08,		n100,		percent);
U8_TO_UNIT	(1,			0,			percent);
U8_TO_UNIT	(01,		0,			percent);
U8_TO_UNIT	(04,		0,			percent);
UNIT_TO_U8	(5kPa,		0,			pressure);
UNIT_TO_U8	(100kPa,	0,			pressure);
UNIT_TO_U16	(0125kPa,	0,			pressure);
UNIT_TO_U16	(5kPa,		0,			pressure);
UNIT_TO_U16	(2kPa,		0,			pressure);
UNIT_TO_U16	(01kPa,		0,			pressure);
UNIT_TO_U8	(05kPa,		0,			pressure);
UNIT_TO_U8	(2kPa,		0,			pressure);
UNIT_TO_U16	(128kPa,	n250kPa,	pressure);
UNIT_TO_U16	(256kPa,	0,			pressure);
UNIT_TO_U16	(05kPa,		0,			pressure);
UNIT_TO_U8	(16kPa,		0,			pressure);
UNIT_TO_U8	(005kPa,	0,			pressure);
UNIT_TO_U8	(4kPa,		0,			pressure);
UNIT_TO_U8	(8kPa,		0,			pressure);
U8_TO_UNIT	(5kPa,		0,			pressure);
U8_TO_UNIT	(100kPa,	0,			pressure);
U16_TO_UNIT	(0125kPa,	0,			pressure);
U16_TO_UNIT	(5kPa,		0,			pressure);
U16_TO_UNIT	(2kPa,		0,			pressure);
U16_TO_UNIT	(01kPa,		0,			pressure);
U8_TO_UNIT	(05kPa,		0,			pressure);
U8_TO_UNIT	(2kPa,		0,			pressure);
U16_TO_UNIT	(128kPa,	n250kPa,	pressure);
U16_TO_UNIT	(256kPa,	0,			pressure);
U16_TO_UNIT	(05kPa,		0,			pressure);
U8_TO_UNIT	(16kPa,		0,			pressure);
U8_TO_UNIT	(005kPa,	0,			pressure);
U8_TO_UNIT	(4kPa,		0,			pressure);
U8_TO_UNIT	(8kPa,		0,			pressure);
UNIT_TO_U8	(1C,		n40,		temperature);
UNIT_TO_U16	(003125C,	n273,		temperature);
U8_TO_UNIT	(1C,		n40,		temperature);
U16_TO_UNIT	(003125C,	n273,		temperature);
UNIT_TO_U16	(1Nm,		0,			torque);
U16_TO_UNIT	(1Nm,		0,			torque);
UNIT_TO_U16	(256kmh,	0,			velocity);
U16_TO_UNIT	(256kmh,	0,			velocity);
UNIT_TO_U16	(0125rpm,	0,			velocity);
U16_TO_UNIT	(0125rpm,	0,			velocity);
UNIT_TO_U8	(01s,		0,			time);
U8_TO_UNIT	(01s,		0,			time);
UNIT_TO_U8	(1h,		0,			time);
U8_TO_UNIT	(1h,		0,			time);
UNIT_TO_U8	(025s,		0,			time);
U8_TO_UNIT	(025s,		0,			time);
UNIT_TO_U8	(1min,		n125,		time);
U8_TO_UNIT	(1min,		n125,		time);
UNIT_TO_U8	(1min,		0,			time);
U8_TO_UNIT	(1min,		0,			time);
UNIT_TO_U8	(1h,		n125,		time);
U8_TO_UNIT	(1h,		n125,		time);
UNIT_TO_U8	(1m,		0,			time);
U8_TO_UNIT	(1m,		0,			time);
UNIT_TO_U8	(1wk,		n125,		time);
U8_TO_UNIT	(1wk,		n125,		time);
UNIT_TO_U8	(1y,		1985,		time);
U8_TO_UNIT	(1y,		1985,		time);
UNIT_TO_U8	(10rpm,		0,			velocity);
U8_TO_UNIT	(10rpm,		0,			velocity);
UNIT_TO_U8	(1kmh,		0,			velocity);
U8_TO_UNIT	(1kmh,		0,			velocity);
UNIT_TO_U8	(1A,		n125,		current);
U8_TO_UNIT	(1A,		n125,		current);
UNIT_TO_U16	(10kg,		0,			mass);
U16_TO_UNIT	(10kg,		0,			mass);
UNIT_TO_U32	(05l,		0,			fuel);
U32_TO_UNIT	(05l,		0,			fuel);
/* c file
 * DO NOT end lines with ;
 */
GEARNO_TO_U8
U8_TO_GEARNO
SCALE_U32	(5m,		0,		0.0f,		21055406.0f,	distance)
UNSCALE_U32	(5m,		0,		0.0f,		21055406.0f,	distance)
SCALE_U16	(512kml,	0,		0.0f,		125.5f,			eco_liquid)
UNSCALE_U16	(512kml,	0,		0.0f,		125.5f,			eco_liquid)
SCALE_U16	(005v,		0,		0.0f,		3212.75f,		voltage)
UNSCALE_U16	(005v,		0,		0.0f,		3212.75f,		voltage)
SCALE_U16	(001,		0,		0.0f,		624.55f,		gearratio)
UNSCALE_U16	(001,		0,		0.0f,		624.55f,		gearratio)
SCALE_U16	(00025,		0,		0.0f,		1.606375f,		percent)
SCALE_U8	(1,			n125,	-1.25f,		1.25f,			percent)
SCALE_U8	(08,		n100,	-1.0f,		1.0f,			percent)
SCALE_U8	(1,			0,		0.0f,		2.5f,			percent)
SCALE_U8	(01,		0,		0.0f,		1.02f,			percent)
SCALE_U8	(04,		0,		0.0f,		1.0f,			percent)
UNSCALE_U16	(00025,		0,		0.0f,		1.0f,			percent)
UNSCALE_U8	(1,			n125,	-1.25f,		1.25f,			percent)
UNSCALE_U8	(08,		n100,	-1.0f,		1.0f,			percent)
UNSCALE_U8	(1,			0,		0.0f,		2.5f,			percent)
UNSCALE_U8	(01,		0,		0.0f,		1.02f,			percent)
UNSCALE_U8	(04,		0,		0.0f,		1.0f,			percent)
SCALE_U8	(5kPa,		0,		0.0f,		1250.0f,		pressure)
SCALE_U8	(100kPa,	0,		0.0f,		25000.0f,		pressure)
SCALE_U16	(0125kPa,	0,		0.0f,		8031.875f,		pressure)
SCALE_U16	(5kPa,		0,		0.0f,		321275.0f,		pressure)
SCALE_U16	(2kPa,		0,		0.0f,		128510.0f,		pressure)
SCALE_U16	(01kPa,		0,		0.0f,		6425.5f,		pressure)
SCALE_U8	(05kPa,		0,		0.0f,		125.0f,			pressure)
SCALE_U8	(2kPa,		0,		0.0f,		500.0f,			pressure)
SCALE_U16	(128kPa,	n250,	-250.0f,	251.99f,		pressure)
SCALE_U16	(256kPa,	0,		0.0f,		251.0f,			pressure)
SCALE_U16	(05kPa,		0,		0.0f,		32127.5f,		pressure)
SCALE_U8	(16kPa,		0,		0.0f,		4000.0f,		pressure)
SCALE_U8	(005kPa,	0,		0.0f,		12.5f,			pressure)
SCALE_U8	(4kPa,		0,		0.0f,		1000.0f,		pressure)
SCALE_U8	(8kPa,		0,		0.0f,		2000.0f,		pressure)
UNSCALE_U8	(5kPa,		0,		0.0f,		1250.0f,		pressure)
UNSCALE_U8	(100kPa,	0,		0.0f,		25000.0f,		pressure)
UNSCALE_U16	(0125kPa,	0,		0.0f,		8031.875f,		pressure)
UNSCALE_U16	(5kPa,		0,		0.0f,		321275.0f,		pressure)
UNSCALE_U16	(2kPa,		0,		0.0f,		128510.0f,		pressure)
UNSCALE_U16	(01kPa,		0,		0.0f,		6425.5f,		pressure)
UNSCALE_U8	(05kPa,		0,		0.0f,		125.0f,			pressure)
UNSCALE_U8	(2kPa,		0,		0.0f,		500.0f,			pressure)
UNSCALE_U16	(128kPa,	n250,	-250.0f,	251.99f,		pressure)
UNSCALE_U16	(256kPa,	0,		0.0f,		251.0f,			pressure)
UNSCALE_U16	(05kPa,		0,		0.0f,		32127.5f,		pressure)
UNSCALE_U8	(16kPa,		0,		0.0f,		4000.0f,		pressure)
UNSCALE_U8	(005kPa,	0,		0.0f,		12.5f,			pressure)
UNSCALE_U8	(4kPa,		0,		0.0f,		1000.0f,		pressure)
UNSCALE_U8	(8kPa,		0,		0.0f,		2000.0f,		pressure)
SCALE_U8	(1C,		n40,	-40.0f,		210.0f,			temperature)
SCALE_U16	(003125C,	n273,	-273.0f,	1735.0f,		temperature)
UNSCALE_U8	(1C,		n40,	-40.0f,		210.0f,			temperature)
UNSCALE_U16	(003125C,	n273,	-273.0f,	1735.0f,		temperature)
SCALE_U16	(1Nm,		0,		0.0f,		64255.0f,		torque)
UNSCALE_U16	(1Nm,		0,		0.0f,		64255.0f,		torque)
SCALE_U16	(256kmh,	0,		0.0f,		250.996f,		velocity)
UNSCALE_U16	(256kmh,	0,		0.0f,		250.996f,		velocity)
SCALE_U16	(0125rpm,	0,		0.0f,		8031.875f,		velocity)
UNSCALE_U16	(0125rpm,	0,		0.0f,		8031.875f,		velocity)
SCALE_U8	(01s,		0,		0.0f,		25.0f,			time)
UNSCALE_U8	(01s,		0,		0.0f,		25.0f,			time)
SCALE_U8	(1h,		0,		0.0f,		250.0f,			time)
UNSCALE_U8	(1h,		0,		0.0f,		250.0f,			time)
SCALE_U8	(025s,		0,		0.0f,		62.5f,			time)
UNSCALE_U8	(025s,		0,		0.0f,		62.5f,			time)
SCALE_U8	(1min,		n125,	-125.0f,	125.0f,			time)
UNSCALE_U8	(1min,		n125,	-125.0f,	125.0f,			time)
SCALE_U8	(1min,		0,		0.0f,		250.0f,			time)
UNSCALE_U8	(1min,		0,		0.0f,		250.0f,			time)
SCALE_U8	(1h,		n125,	-125.0f,	125.0f,			time)
UNSCALE_U8	(1h,		n125,	-125.0f,	125.0f,			time)
SCALE_U8	(1m,		0,		0.0f,		250.0f,			time)
UNSCALE_U8	(1m,		0,		0.0f,		250.0f,			time)
SCALE_U8	(1wk,		n125,	-125.0f,	125.0f,			time)
UNSCALE_U8	(1wk,		n125,	-125.0f,	125.0f,			time)
SCALE_U8	(1y,		1985,	1985.0f,	2235.0f,		time)
UNSCALE_U8	(1y,		1985,	1985.0f,	2235.0f,		time)
SCALE_U8	(10rpm,		0,		0.0f,		2500.0f,		velocity)
UNSCALE_U8	(10rpm,		0,		0.0f,		2500.0f,		velocity)
SCALE_U8	(1kmh,		0,		0.0f,		250.0f,			velocity)
UNSCALE_U8	(1kmh,		0,		0.0f,		250.0f,			velocity)
SCALE_U8	(1A,		n125,	-125.0f,	125.0f,			current)
UNSCALE_U8	(1A,		n125,	-125.0f,	125.0f,			current)
SCALE_U16	(10kg,		0,		0.0f,		642550.0,		mass)
UNSCALE_U16	(10kg,		0,		0.0f,		642550.0f,		mass)
SCALE_U32	(05l,		0,		0.0f,		2105540607.5f,	fuel)
UNSCALE_U32	(05l,		0,		0.0f,		2105540607.5f,	fuel)
