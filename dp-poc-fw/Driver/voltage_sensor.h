/*
 * voltage_sensor.h
 *
 * Created: 6/20/2024 12:26:16 PM
 *
 *  Author: Dewmith
 */


#ifndef VOLTAGE_SENSOR_H_
#define VOLTAGE_SENSOR_H_

void voltage_sensor_init();
double get_voltage_rms();
uint16_t get_voltage_pp();

#endif /* VOLTAGE_SENSOR_H_ */