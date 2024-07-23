#include "../include/general.h"
#ifdef __cplusplus
extern "C" {
#endif
unsigned char gearno_to_U8 (int in) {return (unsigned char)(in + 125);}
int U8_to_gearno (unsigned char in) {return in - 125;}
float distance_from_U32_5m_0 (unsigned int in){return ((in) / (4211081215.0f) * ((21055406.0f) - (0.0f)) + (0.0f));}
unsigned int distance_to_U32_5m_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (21055406.0f)) (in) = (21055406.0f);return (unsigned int)(((in) - (0.0f)) / ((21055406.0f) - (0.0f)) * (4211081215.0f));}
float eco_liquid_from_U16_512kml_0 (unsigned short in){return ((in) / (64255.0f) * ((125.5f) - (0.0f)) + (0.0f));}
unsigned short eco_liquid_to_U16_512kml_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (125.5f)) (in) = (125.5f);return (unsigned short)(((in) - (0.0f)) / ((125.5f) - (0.0f)) * (64255.0f));}
float voltage_from_U16_005v_0 (unsigned short in){return ((in) / (64255.0f) * ((3212.75f) - (0.0f)) + (0.0f));}
unsigned short voltage_to_U16_005v_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (3212.75f)) (in) = (3212.75f);return (unsigned short)(((in) - (0.0f)) / ((3212.75f) - (0.0f)) * (64255.0f));}
float gearratio_from_U16_001_0 (unsigned short in){return ((in) / (64255.0f) * ((624.55f) - (0.0f)) + (0.0f));}
unsigned short gearratio_to_U16_001_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (624.55f)) (in) = (624.55f);return (unsigned short)(((in) - (0.0f)) / ((624.55f) - (0.0f)) * (64255.0f));}
float percent_from_U16_00025_0 (unsigned short in){return ((in) / (64255.0f) * ((1.606375f) - (0.0f)) + (0.0f));}
float percent_from_U8_1_n125 (unsigned char in){return ((in) / (250.0f) * ((1.25f) - (-1.25f)) + (-1.25f));}
float percent_from_U8_08_n100 (unsigned char in){return ((in) / (250.0f) * ((1.0f) - (-1.0f)) + (-1.0f));}
float percent_from_U8_1_0 (unsigned char in){return ((in) / (250.0f) * ((2.5f) - (0.0f)) + (0.0f));}
float percent_from_U8_01_0 (unsigned char in){return ((in) / (250.0f) * ((1.02f) - (0.0f)) + (0.0f));}
float percent_from_U8_04_0 (unsigned char in){return ((in) / (250.0f) * ((1.0f) - (0.0f)) + (0.0f));}
unsigned short percent_to_U16_00025_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (1.0f)) (in) = (1.0f);return (unsigned short)(((in) - (0.0f)) / ((1.0f) - (0.0f)) * (64255.0f));}
unsigned char percent_to_U8_1_n125 (float in){if ((in) < (-1.25f)) (in) = (-1.25f);if ((in) > (1.25f)) (in) = (1.25f);return (unsigned char)(((in) - (-1.25f)) / ((1.25f) - (-1.25f)) * (250.0f));}
unsigned char percent_to_U8_08_n100 (float in){if ((in) < (-1.0f)) (in) = (-1.0f);if ((in) > (1.0f)) (in) = (1.0f);return (unsigned char)(((in) - (-1.0f)) / ((1.0f) - (-1.0f)) * (250.0f));}
unsigned char percent_to_U8_1_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (2.5f)) (in) = (2.5f);return (unsigned char)(((in) - (0.0f)) / ((2.5f) - (0.0f)) * (250.0f));}
unsigned char percent_to_U8_01_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (1.02f)) (in) = (1.02f);return (unsigned char)(((in) - (0.0f)) / ((1.02f) - (0.0f)) * (250.0f));}
unsigned char percent_to_U8_04_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (1.0f)) (in) = (1.0f);return (unsigned char)(((in) - (0.0f)) / ((1.0f) - (0.0f)) * (250.0f));}
float pressure_from_U8_5kPa_0 (unsigned char in){return ((in) / (250.0f) * ((1250.0f) - (0.0f)) + (0.0f));}
float pressure_from_U8_100kPa_0 (unsigned char in){return ((in) / (250.0f) * ((25000.0f) - (0.0f)) + (0.0f));}
float pressure_from_U16_0125kPa_0 (unsigned short in){return ((in) / (64255.0f) * ((8031.875f) - (0.0f)) + (0.0f));}
float pressure_from_U16_5kPa_0 (unsigned short in){return ((in) / (64255.0f) * ((321275.0f) - (0.0f)) + (0.0f));}
float pressure_from_U16_2kPa_0 (unsigned short in){return ((in) / (64255.0f) * ((128510.0f) - (0.0f)) + (0.0f));}
float pressure_from_U16_01kPa_0 (unsigned short in){return ((in) / (64255.0f) * ((6425.5f) - (0.0f)) + (0.0f));}
float pressure_from_U8_05kPa_0 (unsigned char in){return ((in) / (250.0f) * ((125.0f) - (0.0f)) + (0.0f));}
float pressure_from_U8_2kPa_0 (unsigned char in){return ((in) / (250.0f) * ((500.0f) - (0.0f)) + (0.0f));}
float pressure_from_U16_128kPa_n250 (unsigned short in){return ((in) / (64255.0f) * ((251.99f) - (-250.0f)) + (-250.0f));}
float pressure_from_U16_256kPa_0 (unsigned short in){return ((in) / (64255.0f) * ((251.0f) - (0.0f)) + (0.0f));}
float pressure_from_U16_05kPa_0 (unsigned short in){return ((in) / (64255.0f) * ((32127.5f) - (0.0f)) + (0.0f));}
float pressure_from_U8_16kPa_0 (unsigned char in){return ((in) / (250.0f) * ((4000.0f) - (0.0f)) + (0.0f));}
float pressure_from_U8_005kPa_0 (unsigned char in){return ((in) / (250.0f) * ((12.5f) - (0.0f)) + (0.0f));}
float pressure_from_U8_4kPa_0 (unsigned char in){return ((in) / (250.0f) * ((1000.0f) - (0.0f)) + (0.0f));}
float pressure_from_U8_8kPa_0 (unsigned char in){return ((in) / (250.0f) * ((2000.0f) - (0.0f)) + (0.0f));}
unsigned char pressure_to_U8_5kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (1250.0f)) (in) = (1250.0f);return (unsigned char)(((in) - (0.0f)) / ((1250.0f) - (0.0f)) * (250.0f));}
unsigned char pressure_to_U8_100kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (25000.0f)) (in) = (25000.0f);return (unsigned char)(((in) - (0.0f)) / ((25000.0f) - (0.0f)) * (250.0f));}
unsigned short pressure_to_U16_0125kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (8031.875f)) (in) = (8031.875f);return (unsigned short)(((in) - (0.0f)) / ((8031.875f) - (0.0f)) * (64255.0f));}
unsigned short pressure_to_U16_5kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (321275.0f)) (in) = (321275.0f);return (unsigned short)(((in) - (0.0f)) / ((321275.0f) - (0.0f)) * (64255.0f));}
unsigned short pressure_to_U16_2kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (128510.0f)) (in) = (128510.0f);return (unsigned short)(((in) - (0.0f)) / ((128510.0f) - (0.0f)) * (64255.0f));}
unsigned short pressure_to_U16_01kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (6425.5f)) (in) = (6425.5f);return (unsigned short)(((in) - (0.0f)) / ((6425.5f) - (0.0f)) * (64255.0f));}
unsigned char pressure_to_U8_05kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (125.0f)) (in) = (125.0f);return (unsigned char)(((in) - (0.0f)) / ((125.0f) - (0.0f)) * (250.0f));}
unsigned char pressure_to_U8_2kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (500.0f)) (in) = (500.0f);return (unsigned char)(((in) - (0.0f)) / ((500.0f) - (0.0f)) * (250.0f));}
unsigned short pressure_to_U16_128kPa_n250 (float in){if ((in) < (-250.0f)) (in) = (-250.0f);if ((in) > (251.99f)) (in) = (251.99f);return (unsigned short)(((in) - (-250.0f)) / ((251.99f) - (-250.0f)) * (64255.0f));}
unsigned short pressure_to_U16_256kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (251.0f)) (in) = (251.0f);return (unsigned short)(((in) - (0.0f)) / ((251.0f) - (0.0f)) * (64255.0f));}
unsigned short pressure_to_U16_05kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (32127.5f)) (in) = (32127.5f);return (unsigned short)(((in) - (0.0f)) / ((32127.5f) - (0.0f)) * (64255.0f));}
unsigned char pressure_to_U8_16kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (4000.0f)) (in) = (4000.0f);return (unsigned char)(((in) - (0.0f)) / ((4000.0f) - (0.0f)) * (250.0f));}
unsigned char pressure_to_U8_005kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (12.5f)) (in) = (12.5f);return (unsigned char)(((in) - (0.0f)) / ((12.5f) - (0.0f)) * (250.0f));}
unsigned char pressure_to_U8_4kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (1000.0f)) (in) = (1000.0f);return (unsigned char)(((in) - (0.0f)) / ((1000.0f) - (0.0f)) * (250.0f));}
unsigned char pressure_to_U8_8kPa_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (2000.0f)) (in) = (2000.0f);return (unsigned char)(((in) - (0.0f)) / ((2000.0f) - (0.0f)) * (250.0f));}
float temperature_from_U8_1C_n40 (unsigned char in){return ((in) / (250.0f) * ((210.0f) - (-40.0f)) + (-40.0f));}
float temperature_from_U16_003125C_n273 (unsigned short in){return ((in) / (64255.0f) * ((1735.0f) - (-273.0f)) + (-273.0f));}
unsigned char temperature_to_U8_1C_n40 (float in){if ((in) < (-40.0f)) (in) = (-40.0f);if ((in) > (210.0f)) (in) = (210.0f);return (unsigned char)(((in) - (-40.0f)) / ((210.0f) - (-40.0f)) * (250.0f));}
unsigned short temperature_to_U16_003125C_n273 (float in){if ((in) < (-273.0f)) (in) = (-273.0f);if ((in) > (1735.0f)) (in) = (1735.0f);return (unsigned short)(((in) - (-273.0f)) / ((1735.0f) - (-273.0f)) * (64255.0f));}
float torque_from_U16_1Nm_0 (unsigned short in){return ((in) / (64255.0f) * ((64255.0f) - (0.0f)) + (0.0f));}
unsigned short torque_to_U16_1Nm_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (64255.0f)) (in) = (64255.0f);return (unsigned short)(((in) - (0.0f)) / ((64255.0f) - (0.0f)) * (64255.0f));}
float velocity_from_U16_256kmh_0 (unsigned short in){return ((in) / (64255.0f) * ((250.996f) - (0.0f)) + (0.0f));}
unsigned short velocity_to_U16_256kmh_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (125.0f)) (in) = (125.0f);return (unsigned short)(((in) - (0.0f)) / ((250.996f) - (0.0f)) * (64255.0f));}
float velocity_from_U16_0125rpm_0 (unsigned short in){return ((in) / (64255.0f) * ((8031.875f) - (0.0f)) + (0.0f));}
unsigned short velocity_to_U16_0125rpm_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (8031.875f)) (in) = (8031.875f);return (unsigned short)(((in) - (0.0f)) / ((8031.875f) - (0.0f)) * (64255.0f));}
float time_from_U8_01s_0 (unsigned char in){return ((in) / (250.0f) * ((25.0f) - (0.0f)) + (0.0f));}
unsigned char time_to_U8_01s_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (25.0f)) (in) = (25.0f);return (unsigned char)(((in) - (0.0f)) / ((25.0f) - (0.0f)) * (250.0f));}
float time_from_U8_1h_0 (unsigned char in){return ((in) / (250.0f) * ((250.0f) - (0.0f)) + (0.0f));}
unsigned char time_to_U8_1h_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (250.0f)) (in) = (250.0f);return (unsigned char)(((in) - (0.0f)) / ((250.0f) - (0.0f)) * (250.0f));}
float time_from_U8_025s_0 (unsigned char in){return ((in) / (250.0f) * ((62.5f) - (0.0f)) + (0.0f));}
unsigned char time_to_U8_025s_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (62.5f)) (in) = (62.5f);return (unsigned char)(((in) - (0.0f)) / ((62.5f) - (0.0f)) * (250.0f));}
float time_from_U8_1min_n125 (unsigned char in){return ((in) / (250.0f) * ((125.0f) - (-125.0f)) + (-125.0f));}
unsigned char time_to_U8_1min_n125 (float in){if ((in) < (-125.0f)) (in) = (-125.0f);if ((in) > (125.0f)) (in) = (125.0f);return (unsigned char)(((in) - (-125.0f)) / ((125.0f) - (-125.0f)) * (250.0f));}
float time_from_U8_1min_0 (unsigned char in){return ((in) / (250.0f) * ((250.0f) - (0.0f)) + (0.0f));}
unsigned char time_to_U8_1min_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (250.0f)) (in) = (250.0f);return (unsigned char)(((in) - (0.0f)) / ((250.0f) - (0.0f)) * (250.0f));}
float time_from_U8_1h_n125 (unsigned char in){return ((in) / (250.0f) * ((125.0f) - (-125.0f)) + (-125.0f));}
unsigned char time_to_U8_1h_n125 (float in){if ((in) < (-125.0f)) (in) = (-125.0f);if ((in) > (125.0f)) (in) = (125.0f);return (unsigned char)(((in) - (-125.0f)) / ((125.0f) - (-125.0f)) * (250.0f));}
float time_from_U8_1m_0 (unsigned char in){return ((in) / (250.0f) * ((250.0f) - (0.0f)) + (0.0f));}
unsigned char time_to_U8_1m_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (250.0f)) (in) = (250.0f);return (unsigned char)(((in) - (0.0f)) / ((250.0f) - (0.0f)) * (250.0f));}
float time_from_U8_1wk_n125 (unsigned char in){return ((in) / (250.0f) * ((125.0f) - (-125.0f)) + (-125.0f));}
unsigned char time_to_U8_1wk_n125 (float in){if ((in) < (-125.0f)) (in) = (-125.0f);if ((in) > (125.0f)) (in) = (125.0f);return (unsigned char)(((in) - (-125.0f)) / ((125.0f) - (-125.0f)) * (250.0f));}
float time_from_U8_1y_1985 (unsigned char in){return ((in) / (250.0f) * ((2235.0f) - (1985.0f)) + (1985.0f));}
unsigned char time_to_U8_1y_1985 (float in){if ((in) < (1985.0f)) (in) = (1985.0f);if ((in) > (2235.0f)) (in) = (2235.0f);return (unsigned char)(((in) - (1985.0f)) / ((2235.0f) - (1985.0f)) * (250.0f));}
float velocity_from_U8_10rpm_0 (unsigned char in){return ((in) / (250.0f) * ((2500.0f) - (0.0f)) + (0.0f));}
unsigned char velocity_to_U8_10rpm_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (2500.0f)) (in) = (2500.0f);return (unsigned char)(((in) - (0.0f)) / ((2500.0f) - (0.0f)) * (250.0f));}
float velocity_from_U8_1kmh_0 (unsigned char in){return ((in) / (250.0f) * ((250.0f) - (0.0f)) + (0.0f));}
unsigned char velocity_to_U8_1kmh_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (250.0f)) (in) = (250.0f);return (unsigned char)(((in) - (0.0f)) / ((250.0f) - (0.0f)) * (250.0f));}
float current_from_U8_1A_n125 (unsigned char in){return ((in) / (250.0f) * ((125.0f) - (-125.0f)) + (-125.0f));}
unsigned char current_to_U8_1A_n125 (float in){if ((in) < (-125.0f)) (in) = (-125.0f);if ((in) > (125.0f)) (in) = (125.0f);return (unsigned char)(((in) - (-125.0f)) / ((125.0f) - (-125.0f)) * (250.0f));}
float mass_from_U16_10kg_0 (unsigned short in){return ((in) / (64255.0f) * ((642550.0) - (0.0f)) + (0.0f));}
unsigned short mass_to_U16_10kg_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (642550.0f)) (in) = (642550.0f);return (unsigned short)(((in) - (0.0f)) / ((642550.0f) - (0.0f)) * (64255.0f));}
float fuel_from_U32_05l_0 (unsigned int in){return ((in) / (4211081215.0f) * ((2105540607.5f) - (0.0f)) + (0.0f));}
unsigned int fuel_to_U32_05l_0 (float in){if ((in) < (0.0f)) (in) = (0.0f);if ((in) > (2105540607.5f)) (in) = (2105540607.5f);return (unsigned int)(((in) - (0.0f)) / ((2105540607.5f) - (0.0f)) * (4211081215.0f));}
#ifdef __cplusplus
}
#endif
