//Read TEMPERATURE AND DISPLAY ONlcd/sERIAL
#define LM35_PIN A0
#define LCD_ADDR 0x27
float ReadTemperature(void)
{
     int raw=analogRead(LM35_PIN);
     float voltage=(raw/1023.0)*5000; //mV
     float temp=voltage/10.0 //10mV per degree
     return temp;

}

void DisplayTemperature(void)
{ 
    static float temps[10]; //Moving average
    static uint8_t index=0;
    float sum=0;

    temps[index++]=ReadTemperature();
    if(index>=10)index=0;

    for(uint8_t i=0;i<10;i++) sum+=temps[i];
    float avg=sum/10.0;
    printf("Temp:%.1f degree C\n",avg);

    if(avg>30.0)SER_BIT(PORTB,0); //Turn on fan
    else CLR_BIT(PORTB,0);

}


