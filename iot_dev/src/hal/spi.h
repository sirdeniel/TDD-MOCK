#ifndef SPI_H
#define SPI_H
typedef int EZM_SPI;

int ezm_spi_read(EZM_SPI *my_obj,uint8_t reg_addr, uint8_t *data, uint32_t len);
int ezm_spi_write(EZM_SPI *my_obj,uint8_t reg_addr, uint8_t *data, uint32_t len);
#endif // SPI_H
