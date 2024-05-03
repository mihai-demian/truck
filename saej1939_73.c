#include "../include/saej1939_73.h"

const unsigned int pgn65228 = 0x00FECC;
const unsigned int pgn65235 = 0x00FED3;

unsigned int spnno_from_spns1214_v1 (struct spns1214v1 *s)
{
	return (((unsigned int)(s->spn1214_2) << 11) | ((unsigned int)(s->spn1214_1) << 3) | (unsigned int)s->spn1214_0);
}

unsigned int spnno_from_spns1214_v2 (struct spns1214v2 *s)
{
	return (((unsigned int)(s->spn1214_1) << 3) | (unsigned int)s->spn1214_0);
}

unsigned int spnno_from_spns1214_v34 (struct spns1214v34 *s)
{
	return (((unsigned int)(s->spn1214_1) << 16) | (unsigned int)s->spn1214_0);
}

struct spns1214v1
spns1214_from_spnno_v1 (unsigned int spnno, unsigned int fmino, unsigned int ocno)
{
	struct spns1214v1 out;
	out.spn1706 = 1;
	if (ocno > 126)
		out.spn1216 = 127;
	else
		out.spn1216 = ocno;
	if (fmino > 31)
		out.spn1215 = 31;
	else
		out.spn1215 = fmino;
	out.spn1214_0 = spnno & 0x7;
	out.spn1214_1 = (spnno >> 3) & 0xFF;
	out.spn1214_2 = spnno >> 11;
	return out;
}

struct spns1214v2
spns1214_from_spnno_v2 (unsigned int spnno, unsigned int fmino, unsigned int ocno)
{
	struct spns1214v2 out;
	out.spn1706 = 1;
	if (ocno > 126)
		out.spn1216 = 127;
	else
		out.spn1216 = ocno;
	if (fmino > 31)
		out.spn1215 = 31;
	else
		out.spn1215 = fmino;
	out.spn1214_0 = spnno & 0x7;
	out.spn1214_1 = spnno >> 3;
	return out;
}

struct spns1214v34
spns1214_from_spnno_v3 (unsigned int spnno, unsigned int fmino, unsigned int ocno)
{
	struct spns1214v34 out;
	out.spn1706 = 1;
	if (ocno > 126)
		out.spn1216 = 127;
	else
		out.spn1216 = ocno;
	if (fmino > 31)
		out.spn1215 = 31;
	else
		out.spn1215 = fmino;
	out.spn1214_0 = spnno & 0xFFFF;
	out.spn1214_1 = spnno >> 16;
	return out;
}

struct spns1214v34
spns1214_from_spnno_v4 (unsigned int spnno, unsigned int fmino, unsigned int ocno)
{
	struct spns1214v34 out;
	out.spn1706 = 0;
	if (ocno > 126)
		out.spn1216 = 127;
	else
		out.spn1216 = ocno;
	if (fmino > 31)
		out.spn1215 = 31;
	else
		out.spn1215 = fmino;
	out.spn1214_0 = spnno & 0xFFFF;
	out.spn1214_1 = spnno >> 16;
	return out;
}
