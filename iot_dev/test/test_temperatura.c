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

void test_initializaton_but_dont_care_about_channel(void)
{
    adc_initialize_Expect(0);
    adc_initialize_IgnoreArg_channel();
    temperature_initialize();
}

void test_initialization_with_pointer_to_config_struct (void)
{
    adc_config_t expected_config = {0};
    expected_config.channel = 3;
    expected_config.clock_rate = 40000000;
    expected_config.sample_rate = 1000;
    adc_initialize_configuration_Expect(&expected_config);
    temperature_initialize_with_config();
}