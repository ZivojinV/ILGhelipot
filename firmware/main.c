/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
 */

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
 */
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/TMR0.h"
/*
    Main application
 */ uint16_t adc_rezultat;
uint16_t zbir;
uint16_t konacni_zbir;
void Tajmer(void) {
    static int stanye;
    static int koeficijent_dejstva;

    if (stanye == 0) {
        koeficijent_dejstva = konacni_zbir;
        IO_RA2_SetHigh();
        TMR0_CounterSet(0xFFFF - konacni_zbir);
        stanye = 1;
    } else {
        IO_RA2_SetLow();
        TMR0_CounterSet(0XFFFF - 32768 + konacni_zbir);
        stanye = 0;
    }
    TMR0_Start();
}

int main(void) {

    SYSTEM_Initialize();
    TMR0_Initialize();
    TMR0_OverflowCallbackRegister(Tajmer);
    TMR0_CounterSet(500);
    uint16_t brojac = 0;


    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    ADC_SelectChannel(channel_ANA5);
    ADC_StartConversion();
    while (1) {
        IO_RC3_SetHigh();
        if (ADC_IsConversionDone()) {
            IO_RC2_SetHigh();
            adc_rezultat = ADC_GetConversionResult();
            zbir += adc_rezultat;
            brojac += 1;
            if (brojac == 32) {
                ADC_SelectChannel(channel_ANA5);
                ADC_StartConversion();
                konacni_zbir = zbir;
                brojac = 0;
                zbir = 0;
                
            }
            IO_RC2_SetLow();
        }
        IO_RC3_SetLow();
    }
}