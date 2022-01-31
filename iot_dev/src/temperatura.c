#include "temperatura.h"
#include "adc.h"

bool is_temperature_over_limit (void)
{
  return (adc_get_sample() > 150);
}