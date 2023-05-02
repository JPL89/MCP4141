// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "config.h"
#include "mcp4141.h"

void main(void)
{
    __delay_ms(500); 
    
    MCP4141_Init();
    
    for(unsigned char i = 0; i < 255; i++)
    {
        MCP4141_Write(0, i);
        __delay_ms(10);    
    }
    
    while(1)
    {                            
    }
    
    return;
}