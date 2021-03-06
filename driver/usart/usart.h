#ifndef USART_H
#define USART_H

/* includes */
#include "stm32f10x_conf.h"
#include <stdio.h>


/* definations */
#define USART1_PIN_RX   GPIO_Pin_10
#define USART1_PIN_TX   GPIO_Pin_9

#ifdef __GNUC__
    /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
    #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
    #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
    #define GETCHAR_PROTOTYPE int fgetc( FILE *f )
#endif /* __GNUC__ */

/* functions */
void usart_init( USART_TypeDef* USARTx, u32 baud_rate );
void my_putc( u8 ch );
u8 my_getc( void );

#endif
