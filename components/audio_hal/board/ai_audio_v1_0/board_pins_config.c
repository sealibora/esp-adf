#include "esp_log.h"
#include "driver/gpio.h"
#include "board_pins_config.h"

static const char *TAG = "AI_AUDIO";

esp_err_t get_i2c_pins(i2c_port_t port, i2c_config_t *i2c_config)
{
    BOARD_PARAMETER_CHECK(TAG, i2c_config, return ESP_FAIL);
    if (port == I2C_NUM_0 || port == I2C_NUM_1) {
        i2c_config->sda_io_num = IIC_DATA;
        i2c_config->scl_io_num = IIC_CLK;
    } else {
        i2c_config->sda_io_num = -1;
        i2c_config->scl_io_num = -1;
        ESP_LOGE(TAG, "i2c port %d is not supported", port);
        return ESP_FAIL;
    }
    return ESP_OK;
}

esp_err_t get_i2s_pins(i2s_port_t port, i2s_pin_config_t *i2s_config)
{
    BOARD_PARAMETER_CHECK(TAG, i2s_config, return ESP_FAIL);
    if (port == I2S_NUM_0 || port == I2S_NUM_1) {
        i2s_config->bck_io_num = IIS_SCLK;
        i2s_config->ws_io_num = IIS_LCLK;
        i2s_config->data_out_num = IIS_DSIN;
        i2s_config->data_in_num = IIS_DOUT;
    } else {
        memset(i2s_config, -1, sizeof(i2s_pin_config_t));
        ESP_LOGE(TAG, "i2s port %d is not supported", port);
        return ESP_FAIL;
    }
    return ESP_OK;
}

int8_t get_sdcard_open_file_num_max(void)
{
    return SDCARD_OPEN_FILE_NUM_MAX;
}
