/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F15323
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_DoNotDisturbe aliases
#define LED_DoNotDisturbe_TRIS                 TRISAbits.TRISA0
#define LED_DoNotDisturbe_LAT                  LATAbits.LATA0
#define LED_DoNotDisturbe_PORT                 PORTAbits.RA0
#define LED_DoNotDisturbe_WPU                  WPUAbits.WPUA0
#define LED_DoNotDisturbe_OD                   ODCONAbits.ODCA0
#define LED_DoNotDisturbe_ANS                  ANSELAbits.ANSA0
#define LED_DoNotDisturbe_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_DoNotDisturbe_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_DoNotDisturbe_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_DoNotDisturbe_GetValue()           PORTAbits.RA0
#define LED_DoNotDisturbe_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_DoNotDisturbe_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_DoNotDisturbe_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LED_DoNotDisturbe_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LED_DoNotDisturbe_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LED_DoNotDisturbe_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LED_DoNotDisturbe_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED_DoNotDisturbe_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED_Arrumar aliases
#define LED_Arrumar_TRIS                 TRISAbits.TRISA1
#define LED_Arrumar_LAT                  LATAbits.LATA1
#define LED_Arrumar_PORT                 PORTAbits.RA1
#define LED_Arrumar_WPU                  WPUAbits.WPUA1
#define LED_Arrumar_OD                   ODCONAbits.ODCA1
#define LED_Arrumar_ANS                  ANSELAbits.ANSA1
#define LED_Arrumar_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_Arrumar_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_Arrumar_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_Arrumar_GetValue()           PORTAbits.RA1
#define LED_Arrumar_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_Arrumar_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_Arrumar_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_Arrumar_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_Arrumar_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED_Arrumar_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED_Arrumar_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED_Arrumar_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED_Ocupado aliases
#define LED_Ocupado_TRIS                 TRISAbits.TRISA2
#define LED_Ocupado_LAT                  LATAbits.LATA2
#define LED_Ocupado_PORT                 PORTAbits.RA2
#define LED_Ocupado_WPU                  WPUAbits.WPUA2
#define LED_Ocupado_OD                   ODCONAbits.ODCA2
#define LED_Ocupado_ANS                  ANSELAbits.ANSA2
#define LED_Ocupado_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_Ocupado_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Ocupado_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_Ocupado_GetValue()           PORTAbits.RA2
#define LED_Ocupado_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_Ocupado_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_Ocupado_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_Ocupado_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_Ocupado_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_Ocupado_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_Ocupado_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_Ocupado_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set MFRC522_Rst aliases
#define MFRC522_Rst_TRIS                 TRISAbits.TRISA4
#define MFRC522_Rst_LAT                  LATAbits.LATA4
#define MFRC522_Rst_PORT                 PORTAbits.RA4
#define MFRC522_Rst_WPU                  WPUAbits.WPUA4
#define MFRC522_Rst_OD                   ODCONAbits.ODCA4
#define MFRC522_Rst_ANS                  ANSELAbits.ANSA4
#define MFRC522_Rst_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define MFRC522_Rst_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define MFRC522_Rst_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define MFRC522_Rst_GetValue()           PORTAbits.RA4
#define MFRC522_Rst_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define MFRC522_Rst_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define MFRC522_Rst_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define MFRC522_Rst_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define MFRC522_Rst_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define MFRC522_Rst_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define MFRC522_Rst_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define MFRC522_Rst_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RELE aliases
#define RELE_TRIS                 TRISAbits.TRISA5
#define RELE_LAT                  LATAbits.LATA5
#define RELE_PORT                 PORTAbits.RA5
#define RELE_WPU                  WPUAbits.WPUA5
#define RELE_OD                   ODCONAbits.ODCA5
#define RELE_ANS                  ANSELAbits.ANSA5
#define RELE_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RELE_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RELE_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RELE_GetValue()           PORTAbits.RA5
#define RELE_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RELE_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RELE_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RELE_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RELE_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RELE_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RELE_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define RELE_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISCbits.TRISC0
#define SCK1_LAT                  LATCbits.LATC0
#define SCK1_PORT                 PORTCbits.RC0
#define SCK1_WPU                  WPUCbits.WPUC0
#define SCK1_OD                   ODCONCbits.ODCC0
#define SCK1_ANS                  ANSELCbits.ANSC0
#define SCK1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SCK1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SCK1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SCK1_GetValue()           PORTCbits.RC0
#define SCK1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SDI1 aliases
#define SDI1_TRIS                 TRISCbits.TRISC1
#define SDI1_LAT                  LATCbits.LATC1
#define SDI1_PORT                 PORTCbits.RC1
#define SDI1_WPU                  WPUCbits.WPUC1
#define SDI1_OD                   ODCONCbits.ODCC1
#define SDI1_ANS                  ANSELCbits.ANSC1
#define SDI1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SDI1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SDI1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SDI1_GetValue()           PORTCbits.RC1
#define SDI1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISCbits.TRISC2
#define SDO1_LAT                  LATCbits.LATC2
#define SDO1_PORT                 PORTCbits.RC2
#define SDO1_WPU                  WPUCbits.WPUC2
#define SDO1_OD                   ODCONCbits.ODCC2
#define SDO1_ANS                  ANSELCbits.ANSC2
#define SDO1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SDO1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SDO1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SDO1_GetValue()           PORTCbits.RC2
#define SDO1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set MFRC522_CS aliases
#define MFRC522_CS_TRIS                 TRISCbits.TRISC3
#define MFRC522_CS_LAT                  LATCbits.LATC3
#define MFRC522_CS_PORT                 PORTCbits.RC3
#define MFRC522_CS_WPU                  WPUCbits.WPUC3
#define MFRC522_CS_OD                   ODCONCbits.ODCC3
#define MFRC522_CS_ANS                  ANSELCbits.ANSC3
#define MFRC522_CS_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define MFRC522_CS_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define MFRC522_CS_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define MFRC522_CS_GetValue()           PORTCbits.RC3
#define MFRC522_CS_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define MFRC522_CS_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define MFRC522_CS_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define MFRC522_CS_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define MFRC522_CS_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define MFRC522_CS_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define MFRC522_CS_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define MFRC522_CS_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SW_ARR aliases
#define SW_ARR_TRIS                 TRISCbits.TRISC4
#define SW_ARR_LAT                  LATCbits.LATC4
#define SW_ARR_PORT                 PORTCbits.RC4
#define SW_ARR_WPU                  WPUCbits.WPUC4
#define SW_ARR_OD                   ODCONCbits.ODCC4
#define SW_ARR_ANS                  ANSELCbits.ANSC4
#define SW_ARR_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SW_ARR_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SW_ARR_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SW_ARR_GetValue()           PORTCbits.RC4
#define SW_ARR_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SW_ARR_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SW_ARR_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SW_ARR_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SW_ARR_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SW_ARR_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SW_ARR_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SW_ARR_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SW_NP aliases
#define SW_NP_TRIS                 TRISCbits.TRISC5
#define SW_NP_LAT                  LATCbits.LATC5
#define SW_NP_PORT                 PORTCbits.RC5
#define SW_NP_WPU                  WPUCbits.WPUC5
#define SW_NP_OD                   ODCONCbits.ODCC5
#define SW_NP_ANS                  ANSELCbits.ANSC5
#define SW_NP_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SW_NP_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SW_NP_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SW_NP_GetValue()           PORTCbits.RC5
#define SW_NP_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SW_NP_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SW_NP_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SW_NP_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SW_NP_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SW_NP_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SW_NP_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SW_NP_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/