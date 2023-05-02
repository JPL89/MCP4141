// @File		MCP4141.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		02/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef MCP4141_H
#define MCP4141_H

// PINOUT
#define MCP4141_CS          PORTAbits.RA2
#define MCP4141_SDI         PORTAbits.RA1
#define MCP4141_SCK         PORTAbits.RA0

#define MCP4141_CS_TRIS     TRISAbits.RA2
#define MCP4141_SDI_TRIS    TRISAbits.RA1
#define MCP4141_SCK_TRIS    TRISAbits.RA0

// ADDRESS MAP
#define MCP4141_ADDR_WIPER_0     	0x00
#define MCP4141_ADDR_WIPER_1     	0x01
#define MCP4141_ADDR_TCON        	0x04
#define MCP4141_ADDR_STATUS      	0x05

// COMMAND
#define MCP4141_CMD_WRITE     		0x00
#define MCP4141_CMD_READ     		0x0C
#define MCP4141_CMD_INCREMENT		0x04
#define MCP4141_CMD_DECREMENT      	0x08

// @Function: Spi_Write
// @Return: void
// @Param: void
// @Description: Write one byte to CHIP
static const void Spi_Write(unsigned char byte)
{
    for(unsigned char mask = 0x80; mask; mask >>= 1)
    {
        MCP4141_SCK = 1;
		if(byte & mask) MCP4141_SDI = 1; else MCP4141_SDI = 0;
		MCP4141_SCK = 0;
    }
}

// @Function: MCP4141_Write
// @Return: void
// @Param: unsigned char, unsigned char
// @Description: Send data
void MCP4141_Write(unsigned char address, unsigned char data)
{
    MCP4141_CS = 0;
    Spi_Write( address );
    Spi_Write( data );    
    MCP4141_CS = 1;
}

// @Function: MCP4141_Increment
// @Return: void
// @Param: void
// @Description: Increment value
void MCP4141_Increment(void)
{
    MCP4141_CS = 0;
    Spi_Write( MCP4141_Increment );    
    MCP4141_CS = 1;
}

// @Function: MCP4141_Decrement
// @Return: void
// @Param: void
// @Description: Decrement value
void MCP4141_Decrement(void)
{
    MCP4141_CS = 0;
    Spi_Write( MCP4141_Decrement );    
    MCP4141_CS = 1;
}

// @Function: MCP4141_Init
// @Return: unsigned char
// @Param: unsigned char
// @Description: Initialize SPI
void MCP4141_Init(void)
{
    MCP4141_SCK_TRIS = 0;
    MCP4141_SDI_TRIS = 0;
    MCP4141_CS_TRIS = 0;
    
    MCP4141_CS = 1;
}

#endif
