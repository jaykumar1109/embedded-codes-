#inlcude<avr/io.h>
#include<utill/delay.h>
 void delay_ms(uint16_t ms)
 { 
    while(ms--)
    { 
        _delay_ms(1);

    }
 }

 int main(void)
 { 
DDRB=|=(1<<PB0); //Set PB0 as output


while(1)
{
    PORTB|=(1<<PB0);//LED ON
    delay_ms(500);
    PORTB &=~(1<<PB0); //LED OFF
    delay_ms(500);
    
}
 }