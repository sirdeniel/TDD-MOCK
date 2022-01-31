#ifndef ADC_H
#define ADC_H
#include <stdint.h>

uint8_t adc_get_sample (void);
void adc_initialize (uint8_t channel);
#endif // ADC_H
