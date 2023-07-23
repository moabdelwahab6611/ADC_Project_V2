/* 
 * File     : application.c
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on May 21, 2023, 5:38 PM
 */

/**************************Includes-Section*****************************/
#include "application.h"
/***********************************************************************/

/***********************************************************************/
uint16 adc_result_1;
volatile uint8 adc_flag;
   
void ADC_DefaultInterruptHandler(void);

adc_config_t adc_1 =
{
    .ADC_InterruptHandler = ADC_DefaultInterruptHandler,
    .acquisition_time = ADC_12_TAD,
    .adc_channel = ADC_CHANNEL_AN0,
    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .result_format = ADC_RESULT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};

void ADC_DefaultInterruptHandler(void)
{
    Std_ReturnType ret = E_NOT_OK;
    adc_flag++;
    ret = ADC_GetConversionResult(&adc_1, &adc_result_1);
}
/***********************************************************************/

/***********************Main Function-Section***************************/
int main() 
{ 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    while(1)
    {   
       ret =  ADC_StartConversion_Interrupt(&adc_1, ADC_CHANNEL_AN0);
       
    }
    return (EXIT_SUCCESS);
}
/***********************************************************************/

/*************************Functions-Section*****************************/
void application_intialize(void)
{
    Std_ReturnType ret = E_NOT_OK;   
    ecu_layer_intialize();
    ret = ADC_Init(&adc_1);
}
/***********************************************************************/