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