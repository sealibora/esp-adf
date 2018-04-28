#ifndef _BOARD_PINS_CONFIG_H_
#define _BOARD_PINS_CONFIG_H_

#include <string.h>
#include "driver/i2c.h"
#include "driver/i2s.h"
#include "driver/spi_common.h"
#include "driver/spi_master.h"
#include "driver/spi_slave.h"


 #ifdef __cplusplus
 extern "C" {
 #endif
 
 /* SD card related */
 #define SD_CARD_INTR_GPIO           GPIO_NUM_34
 #define SD_CARD_INTR_SEL            GPIO_SEL_34
 #define SDCARD_OPEN_FILE_NUM_MAX   5
 
 //#define GPIO_AUXIN_DETECT           39
 
 /* LED indicators */
 #define GPIO_LED_GREEN              22
 #define GPIO_LED_RED                -1
 
 /* I2C gpios */
 #define IIC_CLK                     32
 #define IIC_DATA                    33
 
 /* PA */
 #define GPIO_PA_EN                  GPIO_NUM_21
 #define GPIO_SEL_PA_EN              GPIO_SEL_21
 
 /* Press button related */
 #define GPIO_SEL_REC                GPIO_SEL_36    //SENSOR_VP
 #define GPIO_SEL_MODE               GPIO_SEL_13    //SENSOR_VN
 #define GPIO_REC                    GPIO_NUM_36
 #define GPIO_MODE                   GPIO_NUM_13
 
 /* Touch pad related */
 #define TOUCH_SEL_SET               GPIO_SEL_19
 #define TOUCH_SEL_PLAY              GPIO_SEL_23
 #define TOUCH_SEL_VOLUP             GPIO_SEL_18
 #define TOUCH_SEL_VOLDWN            GPIO_SEL_5

 #define TOUCH_SET                   GPIO_NUM_19
 #define TOUCH_PLAY                  GPIO_NUM_23
 #define TOUCH_VOLUP                 GPIO_NUM_18
 #define TOUCH_VOLDWN                GPIO_NUM_5
 
 /* I2S gpios */
 #define IIS_SCLK                    27
 #define IIS_LCLK                    26
 #define IIS_DSIN                    25
 #define IIS_DOUT                    35
 
 #ifdef __cplusplus
 }
 #endif

#define BOARD_PARAMETER_CHECK(TAG, a, action) if(!(a)) { \
        ESP_LOGE(TAG, "LINE: %d, (%s): %s", __LINE__, __FUNCTION__, "Invalid parameter"); \
        action; \
    }

/**
 * @brief                  Get i2c pins configuration
 *
 * @param      port        i2c port number to get configuration
 * @param[in]  i2c_config  i2c configuration parameters
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t get_i2c_pins(i2c_port_t port, i2c_config_t *i2c_config);

esp_err_t get_i2s_pins(i2s_port_t port, i2s_pin_config_t *i2s_config);

/**
 * @brief                  Get spi pins configuration
 *
 * @param[in]      spi_config               spi bus configuration parameters
 * @param[in]  spi_device_interface_config  spi device configuration parameters
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */

/**
 * @brief  Get sdcard maximum number of open files
 *
 * @return  -1      error
 *          Others  max num
 */
int8_t get_sdcard_open_file_num_max(void);


#endif
