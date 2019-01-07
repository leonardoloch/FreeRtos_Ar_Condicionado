#define __AVR_ATmega328P__
# include <avr/io.h>


void adc_init(void){
 ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));    //16Mhz/128 = 125Khz the ADC reference clock
 ADMUX |= (1<<REFS0);                //Voltage reference from Avcc (5v)
 ADCSRA |= (1<<ADEN);                //Turn on ADC
 ADCSRA |= (1<<ADSC);                //Do an initial conversion because this one is the slowest and to ensure that everything is up and running
}
 
uint16_t read_adc(uint8_t channel){
 ADMUX &= 0xF0;                    //Clear the older channel that was read
 ADMUX |= channel;                //Defines the new ADC channel to be read
 ADCSRA |= (1<<ADSC);                //Starts a new conversion
 while(ADCSRA & (1<<ADSC))
 {
	PORTD ^= (1 << PD7);
 }           //Wait until the conversion is done
  

 return ADCW;                    //Returns the ADC value of the chosen channel
}

uint16_t adc_read(uint8_t ch)
{
  // select the corresponding channel 0~7
  // ANDing with �7' will always keep the value
  // of �ch� between 0 and 7
  ch &= 0b00000111;  // AND operation with 7
  ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
 
  // start single convertion
  // write �1' to ADSC
  ADCSRA |= (1<<ADSC);
 
  // wait for conversion to complete
  // ADSC becomes �0' again
  // till then, run loop continuously
  PORTD ^= (1 << PD7);
  while(ADCSRA & (1<<ADSC));
 
  return (ADC);
}
void adc_init1()
{
    // AREF = AVcc
    ADMUX = (1<<REFS0);
 
    // ADC Enable and prescaler of 128
    // 16000000/128 = 125000
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

void set_pwm(void) {
    
	(TCCR2B |=(1<<CS22));	
	TCCR2A =0B10100011;
	(DDRD |=(1<<PD3));
	(DDRB |=(1<<PB3));
	
}

