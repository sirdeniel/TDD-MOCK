
#include "unity.h"

#include "iis3dhhc_reg.h"
#include "mock_spi.h"
EZM_SPI	app_sensor;
void setUp(void)
{
}

void tearDown(void)
{
}

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

void test_iis3dhhc_init_pointer_null(void)
{
    stmdev_ctx_t dev_ctx = {0};
    static uint8_t whoamI;
    whoamI = 0;
    TEST_ASSERT_EQUAL_INT32(SENSOR_E_NULL_PTR,iis3dhhc_device_id_get(&dev_ctx, &whoamI));
}

void test_iis3dhhc_init_pointer_ok(void)
{
    stmdev_ctx_t dev_ctx = {0};
    static uint8_t whoamI = 20;
    static uint8_t SENSOR_BUS;
    uint8_t reg_whoamI_mock = IIS3DHHC_WHO_AM_I;
    uint8_t whoamI_mock = IIS3DHHC_ID;
    dev_ctx.read_reg = platform_read;
    dev_ctx.write_reg = platform_write;
    dev_ctx.handle = &SENSOR_BUS;

    ezm_spi_read_ExpectAndReturn(&app_sensor,reg_whoamI_mock,&whoamI_mock,1,SENSOR_OK);
    ezm_spi_read_IgnoreArg_data();
    ezm_spi_read_ReturnThruPtr_data(&whoamI_mock);
    TEST_ASSERT_EQUAL_INT32(SENSOR_OK,iis3dhhc_device_id_get(&dev_ctx, &whoamI));
    TEST_ASSERT_EQUAL_HEX(IIS3DHHC_ID,whoamI);
}

void test_iis3dhhc_init_with_reset_set(void)
{
    stmdev_ctx_t dev_ctx = {0};
    static uint8_t SENSOR_BUS;
    uint8_t reg_ctrl_reg1 = IIS3DHHC_CTRL_REG1;
    uint8_t data_ctrl_reg1 = 0x00;

    dev_ctx.read_reg = platform_read;
    dev_ctx.write_reg = platform_write;
    dev_ctx.handle = &SENSOR_BUS;

    ezm_spi_read_ExpectAndReturn(&app_sensor,reg_ctrl_reg1,&data_ctrl_reg1,1,SENSOR_OK);
    ezm_spi_read_IgnoreArg_data();
    ezm_spi_read_ReturnThruPtr_data(&data_ctrl_reg1);

    ezm_spi_write_ExpectAndReturn(&app_sensor,reg_ctrl_reg1,&data_ctrl_reg1,1,SENSOR_OK);
    ezm_spi_write_IgnoreArg_data();
    TEST_ASSERT_EQUAL_INT32(SENSOR_OK,iis3dhhc_reset_set(&dev_ctx, PROPERTY_ENABLE));
}