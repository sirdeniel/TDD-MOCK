#include "unity.h"
#include "mock_adc.h"
#include "temperatura.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_temperatura_NeedToImplement(void)
{
    adc_get_sample_ExpectAndReturn(155);
    TEST_ASSERT_TRUE(is_temperature_over_limit());
}
