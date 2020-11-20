#include "usart.h"	  

static void usart_gpio( void ) {
    GPIO_InitTypeDef uio;
    
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1, ENABLE );
    
    uio.GPIO_Mode   = GPIO_Mode_AF_PP;
    uio.GPIO_Pin    = USART1_PIN_TX;
    uio.GPIO_Speed  = GPIO_Speed_50MHz;
    GPIO_Init( GPIOA, &uio );
    
    uio.GPIO_Mode   = GPIO_Mode_IPU;
    uio.GPIO_Pin    = USART1_PIN_RX;
    uio.GPIO_Speed  = GPIO_Speed_50MHz;
    GPIO_Init( GPIOA, &uio );
}

void usart_init( USART_TypeDef* USARTx, u32 baud_rate ) {
    USART_InitTypeDef us_s;
    
    usart_gpio();

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1, ENABLE );
    
    us_s.USART_Mode                 = USART_Mode_Tx | USART_Mode_Rx;
    us_s.USART_BaudRate             = baud_rate;
    us_s.USART_WordLength           = USART_WordLength_8b;
    us_s.USART_Parity               = USART_Parity_No;
    us_s.USART_StopBits             = USART_StopBits_1;
    us_s.USART_HardwareFlowControl  = USART_HardwareFlowControl_None;
    USART_Init( USARTx, &us_s );
    USART_Cmd( USARTx, ENABLE );

}

void my_putc( u8 ch ) 
{
    while ( !( USART1->SR & USART_FLAG_TC ) );
    USART1->DR = ch;
}

u8 my_getc( void ) 
{
    while ( !( USART1->SR & USART_FLAG_RXNE ) );
    return USART1->DR;
}

PUTCHAR_PROTOTYPE 
{
    if ( ch == '\n' ) {
        my_putc( '\r' );
    }
    my_putc( (u8)ch );
    return ch;
}

GETCHAR_PROTOTYPE 
{
    return my_getc();
}


void USART1_IRQHandler( void ) 
{
    if ( USART_GetITStatus( USART1, USART_IT_RXNE ) ) {
        USART_ClearITPendingBit( USART1, USART_IT_RXNE );
    }
}


