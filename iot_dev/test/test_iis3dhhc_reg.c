
#include "unity.h"

#include "iis3dhhc_reg.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_iis3dhhc_init_pointer_null(void)
{
    stmdev_ctx_t dev_ctx = {0};
    static uint8_t whoamI;
    whoamI = 0;
    TEST_ASSERT_EQUAL_INT32(0,iis3dhhc_device_id_get(&dev_ctx, &whoamI));
}

