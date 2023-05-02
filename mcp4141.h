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

#define MCP4141_CS          PORTAbits.RA2
#define MCP4141_SDI         PORTAbits.RA1
#define MCP4141_SCK         PORTAbits.RA0

#define MCP4141_CS_TRIS     TRISAbits.RA2
#define MCP4141_SDI_TRIS    TRISAbits.RA1
#define MCP4141_SCK_TRIS    TRISAbits.RA0

#define MCP4141_WIPER_0     0x00
#define MCP4141_WIPER_1     0x01
#define MCP4141_TCON        0x04
#define MCP4141_STATUS      0x05

static const void Spi_Write(unsigned char byte)
{
    for(unsigned char mask = 0x80; mask; mask >>= 1)
    {
        MCP4141_SCK = 1;
        if(byte & mask) MCP4141_SDI = 1; else MCP4141_SDI = 0;
        MCP4141_SCK = 0;
    }
}

void MCP4141_Write(unsigned char address, unsigned char byte)
{
    MCP4141_CS = 0;
    Spi_Write( address );
    Spi_Write( byte );
    MCP4141_CS = 1;
}

void MCP4141_Init(void)
{
    MCP4141_SCK_TRIS = 0;
    MCP4141_SDI_TRIS = 0;
    MCP4141_CS_TRIS = 0;
    
    MCP4141_CS = 1;
}

#endif
