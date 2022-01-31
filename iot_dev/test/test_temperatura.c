#include "unity.h"
#include "mock_adc.h"
#include "temperatura.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_temperature_over_limit(void)
{
    adc_get_sample_ExpectAndReturn(151);
    TEST_ASSERT_TRUE(is_temperature_over_limit());
}

void test_temperature_not_over_limit(void)
{
    adc_get_sample_ExpectAndReturn(150);
    TEST_ASSERT_FALSE(is_temperature_over_limit());
}

void test_correct_channel_is_initialized(void)
{
    adc_initialize_Expect(3);
    temperature_initialize();
}