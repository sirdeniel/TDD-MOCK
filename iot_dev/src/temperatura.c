#include "temperatura.h"
#include "adc.h"

bool is_temperature_over_limit (void)
{
  return (adc_get_sample() > 150);
}

void temperature_initialize (void)
{
    adc_initialize(3);
}

void temperature_initialize_with_config (void)
{
    adc_config_t config = {0}; 
    config.channel = 3; 
    config.clock_rate = 40000000;
    config.sample_rate = 1000;
    adc_initialize_configuration(&config); 
}