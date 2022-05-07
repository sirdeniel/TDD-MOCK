// #ifdef TEST

#include "unity.h"

#include "asm330lhhx_reg.h"
#include "mock_spi.h"
#include "sensor_def.h"

EZM_SPI	app_sensor;

static int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp,
                             uint16_t len)
{
    int32_t resp = 0;
    resp = ezm_spi_read(&app_sensor,reg, bufp, len);
    return resp;
}

static int32_t platform_write(void *handle, uint8_t reg, uint8_t *bufp,
                              uint16_t len)
{
    int32_t resp = 0;
    resp = ezm_spi_write(&app_sensor,reg, bufp, len);
    return resp;
}

void setUp(void)
{
}

void tearDown(void)
{
}

void test_asm330lhhx_init(void)
{
    stmdev_ctx_t dev_ctx;
    // dev_ctx.write_reg = platform_write;
    // dev_ctx.read_reg = platform_read;
    static uint8_t whoamI;
    whoamI = 0;
    // TEST_IGNORE_MESSAGE("Need to Implement asm330lhhx_reg");
    TEST_ASSERT_EQUAL_INT32(SENSOR_E_NULL_PTR,asm330lhhx_device_id_get(&dev_ctx, &whoamI));
}

// #endif // TEST
