/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F15323
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "main.h"
#include <string.h>


char key[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
char writeData[] = "maseletrico";
uint8_t spiReadByte;
uint8_t status;
char str[MAX_LEN];
char char_send[8];
char read[10];


/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    TMR0_StartTimer();
    MFRC522_Init();
    
    LED_DoNotDisturbe_SetLow();
    LED_Ocupado_SetHigh();
    LED_Arrumar_SetHigh();
    RELE_SetLow();
    RELE_ESPERA=false;

    while (1) {
        //Find cards, return card type - Don't remove this sub
        status = MFRC522_Request(PICC_REQIDL, str);
        //Anti-collision, return card serial number 4 bytes
        status = MFRC522_Anticoll(str);
        memcpy(serNum, str, 5);
        if (status == MI_OK) //if ther is a new card detected
        {
            SetFormatRDM630(); // take serNum and format it and return read
             LED_Ocupado_SetLow();
             MFRC522_Init();
             RELE_ESPERA=false;
             TARGET_INSERIDO=true;
             RELE_SetHigh();

        } else if(status == MI_NOTAGERR) {
            MFRC522_Halt();   // Command card into hibernation
            if(!RELE_ESPERA && TARGET_INSERIDO){
                RELE_ESPERA=true;
                TARGET_INSERIDO=false;
                cont1S=0x00;
                contPiscaLED=0x00;
            }else{
                // LED_VM_SetHigh();
            }
            __delay_ms(200); // wait for low consuption
        }
        //LED arrumar quarto
        if(!SW_ARR_GetValue()){
            LED_Arrumar_SetLow();
        }else{
            LED_Arrumar_SetHigh();
        }
        //LED nao perturbe
        if(!SW_NP_GetValue()){
            LED_DoNotDisturbe_SetLow();
        }else{
            LED_DoNotDisturbe_SetHigh();
        }
    }

}

void Write_MFRC522(char addr, char val) {
    MFRC522_CS_SetLow();
    //Address Format: 0XXXXXX0
    spiReadByte = SPI1_Exchange8bit((addr << 1)&0x7E);
    spiReadByte = SPI1_Exchange8bit(val);
    MFRC522_CS_SetHigh();
}

char Read_MFRC522(char addr) {
    MFRC522_CS_SetLow();
    //Address Format: 1XXXXXX0
    spiReadByte = SPI1_Exchange8bit(((addr << 1)&0x7E) | 0x80);
    spiReadByte = SPI1_Exchange8bit(0x00);
    MFRC522_CS_SetHigh();
    return spiReadByte;
}

void MFRC522_Init(void) {
    MFRC522_Rst_SetHigh(); //RESET AND POWER DOWN - SEE DATASHEET MFRC522
    MFRC522_Reset();

    //Timer: TPrescaler*TreloadVal/6.78MHz = 24ms
    Write_MFRC522(TModeReg, 0x8D); //Tauto=1; f(Timer) = 6.78MHz/TPreScaler
    Write_MFRC522(TPrescalerReg, 0x3E); //TModeReg[3..0] + TPrescalerReg
    Write_MFRC522(TReloadRegL, 30);
    Write_MFRC522(TReloadRegH, 0);

    Write_MFRC522(TxAutoReg, 0x40); //100%ASK
    Write_MFRC522(ModeReg, 0x3D); //CRC Initial value 0x6363        ???

    //ClearBitMask(Status2Reg, 0x08);     //MFCrypto1On=0
    //Write_MFRC522(RxSelReg, 0x86);      //RxWait = RxSelReg[5..0]
    //Write_MFRC522(RFCfgReg, 0x7F);      //RxGain = 48dB

    AntennaOn(); //Open the antenna

}

char MFRC522_Request(char reqMode, char *TagType) {
    char status;
    uint8_t backBits; //The received data bits
    Write_MFRC522(BitFramingReg, 0x07); //TxLastBists = BitFramingReg[2..0]        ???
    TagType[0] = reqMode;
    status = MFRC522_ToCard(PCD_TRANSCEIVE, TagType, 1, TagType, &backBits);

    if ((status != MI_OK) || (backBits != 0x10)) {
        status = MI_ERR;
    }

    return status;
}

void MFRC522_Reset(void) {
    Write_MFRC522(CommandReg, PCD_RESETPHASE);
}

void AntennaOn(void) {
    char temp;
    temp = SPI1_Exchange8bit(TxControlReg);
    if (!(temp & 0x03)) {
        SetBitMask(TxControlReg, 0x03);
    }
}

void SetBitMask(char reg, char mask) {
    char tmp;
    tmp = Read_MFRC522(reg);
    Write_MFRC522(reg, tmp | mask); // set bit mask
}

char MFRC522_ToCard(char command, char *sendData, char sendLen, char *backData, uint8_t *backLen) {
    char status = MI_ERR;
    char irqEn = 0x00;
    char waitIRq = 0x00;
    char lastBits;
    char n;
    int i;

    switch (command) {
        case PCD_AUTHENT: //Certification cards close
        {
            irqEn = 0x12;
            waitIRq = 0x10;
            break;
        }
        case PCD_TRANSCEIVE: //Transmit FIFO data
        {
            irqEn = 0x77;
            waitIRq = 0x30;
            break;
        }
        default:
            break;
    }

    Write_MFRC522(CommIEnReg, irqEn | 0x80); //Interrupt request
    ClearBitMask(CommIrqReg, 0x80); //Clear all interrupt request bit
    SetBitMask(FIFOLevelReg, 0x80); //FlushBuffer=1, FIFO Initialization

    Write_MFRC522(CommandReg, PCD_IDLE); //NO action; Cancel the current command???

    //Writing data to the FIFO
    for (i = 0; i < sendLen; i++) {
        Write_MFRC522(FIFODataReg, sendData[i]);
    }

    //Execute the command
    Write_MFRC522(CommandReg, command);
    if (command == PCD_TRANSCEIVE) {
        SetBitMask(BitFramingReg, 0x80); //StartSend=1,transmission of data starts
    }

    //Waiting to receive data to complete
    i = 2000; //i according to the clock frequency adjustment, the operator M1 card maximum waiting time 25ms???
    do {
        //CommIrqReg[7..0]
        //Set1 TxIRq RxIRq IdleIRq HiAlerIRq LoAlertIRq ErrIRq TimerIRq
        n = Read_MFRC522(CommIrqReg);
        i--;
    } while ((i != 0) && !(n & 0x01) && !(n & waitIRq));

    ClearBitMask(BitFramingReg, 0x80); //StartSend=0

    if (i != 0) {
        if (!(Read_MFRC522(ErrorReg) & 0x1B)) //BufferOvfl Collerr CRCErr ProtecolErr
        {
            status = MI_OK;
            if (n & irqEn & 0x01) {
                status = MI_NOTAGERR; //??
            }

            if (command == PCD_TRANSCEIVE) {
                n = Read_MFRC522(FIFOLevelReg);
                lastBits = Read_MFRC522(ControlReg) & 0x07;
                if (lastBits) {
                    *backLen = (n - 1)*8 + lastBits;
                } else {
                    *backLen = n * 8;
                }

                if (n == 0) {
                    n = 1;
                }
                if (n > MAX_LEN) {
                    n = MAX_LEN;
                }

                //Reading the received data in FIFO
                for (i = 0; i < n; i++) {
                    backData[i] = Read_MFRC522(FIFODataReg);
                }
            }
        } else {
            status = MI_ERR;
        }

    }

    //SetBitMask(ControlReg,0x80);           //timer stops
    //Write_MFRC522(CommandReg, PCD_IDLE);

    return status;
}

void ClearBitMask(char reg, char mask) {
    char tmp;
    tmp = Read_MFRC522(reg);
    Write_MFRC522(reg, tmp & (~mask)); // clear bit mask
}

char MFRC522_Anticoll(char *serNum) {
    char status;
    char i;
    char serNumCheck = 0;
    int unLen;


    //ClearBitMask(Status2Reg, 0x08);                //TempSensclear
    //ClearBitMask(CollReg,0x80);                        //ValuesAfterColl
    Write_MFRC522(BitFramingReg, 0x00); //TxLastBists = BitFramingReg[2..0]

    serNum[0] = PICC_ANTICOLL;
    serNum[1] = 0x20;
    status = MFRC522_ToCard(PCD_TRANSCEIVE, serNum, 2, serNum, &unLen);

    if (status == MI_OK) {
        //Check card serial number
        for (i = 0; i < 4; i++) {
            serNumCheck ^= serNum[i];
        }
        if (serNumCheck != serNum[i]) {
            status = MI_ERR;
        }
    }

    //SetBitMask(CollReg, 0x80);                //ValuesAfterColl=1

    return status;
}

void SetFormatRDM630(void) {
    /*uchar checksum1;

    checksum1 = serNum[0] ^ serNum[1] ^ serNum[2] ^ serNum[3] ^ serNum[4];*/
    //uchar_send[0] = 2;

    char_send[0] = Separate_hexP10(serNum[0]);
    char_send[1] = Separate_hexP1(serNum[0]);
    char_send[2] = Separate_hexP10(serNum[1]);
    char_send[3] = Separate_hexP1(serNum[1]);
    char_send[4] = Separate_hexP10(serNum[2]);
    char_send[5] = Separate_hexP1(serNum[2]);
    char_send[6] = Separate_hexP10(serNum[3]);
    char_send[7] = Separate_hexP1(serNum[3]);
    //uchar_send[9] = Separate_hexP10(serNum[4]);
    //uchar_send[10] = Separate_hexP1(serNum[4]);

    // uchar_send[11] = Separate_hexP10(checksum1);
    //uchar_send[12] = Separate_hexP1(checksum1);

    //uchar_send[13] = 3;
    // uchar_send[14] = 0;
    read[0] = char_send[0];
    read[1] = char_send[1];
    read[2] = char_send[2];
    read[3] = char_send[3];
    read[4] = char_send[4];
    read[5] = char_send[5];
    read[6] = char_send[6];
    read[7] = char_send[7];

}

char Separate_hexP10(char val) {
    val = val & 0xF0;
    val = val >> 4;
    if (val < 10) {
        return val + 48;
    } else {
        return val + 55;
    }
}

char Separate_hexP1(char val) {
    val = val & 0x0F;
    if (val < 10) {
        return val + 48;
    } else {
        return val + 55;
    }
}

void MFRC522_Halt(void)
{
  char status;
  int unLen;
  char buff[4];

  buff[0] = PICC_HALT;
  buff[1] = 0;
  CalulateCRC(buff, 2, &buff[2]);

  status = MFRC522_ToCard(PCD_TRANSCEIVE, buff, 4, buff,&unLen);
}

void CalulateCRC(char *pIndata, char len, char *pOutData)
{
  char i, n;

  ClearBitMask(DivIrqReg, 0x04);                        //CRCIrq = 0
  SetBitMask(FIFOLevelReg, 0x80);                        //Clear the FIFO pointer
  //Write_MFRC522(CommandReg, PCD_IDLE);

  //Writing data to the FIFO
  for (i=0; i<len; i++)
  {
    Write_MFRC522(FIFODataReg, *(pIndata+i));
  }
  Write_MFRC522(CommandReg, PCD_CALCCRC);

  //Wait CRC calculation is complete
  i = 0xFF;
  do
  {
    n = Read_MFRC522(DivIrqReg);
    i--;
  }
  while ((i!=0) && !(n&0x04));                        //CRCIrq = 1

  //Read CRC calculation result
  pOutData[0] = Read_MFRC522(CRCResultRegL);
  pOutData[1] = Read_MFRC522(CRCResultRegM);
}
/**
 End of File
 */