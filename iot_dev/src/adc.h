#ifndef ADC_H
#define ADC_H
#include <stdint.h>

typedef struct {
    uint8_t channel;
    uint32_t clock_rate;
    uint32_t sample_rate;
} adc_config_t;
void adc_initialize_configuration (adc_config_t * configuration);

uint8_t adc_get_sample (void);
void adc_initialize (uint8_t channel);
#endif // ADC_H
