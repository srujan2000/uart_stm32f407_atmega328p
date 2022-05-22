volatile char *UCSR0_A = (char*)0xC0;
volatile char *UCSR0_B = (char*)0xC1; 
volatile char *UCSR0_C = (char*)0xC2; 
volatile short *UBBR_0 = (short*)0xC4;
volatile short *UDR_0   = (short*)0xC6;  


void setup() {
  init_USART();
  char x;
  while(1){
    x = usart_rx();
    Serial.print(x);
  }
}


void init_USART(){

  *UCSR0_B = 0x18;
  *UCSR0_C = 0x06;
  *UBBR_0 = 104; 
}

unsigned char usart_rx()
{
  while (((*UCSR0_A>>7)&0x01)==0);
  return *UDR_0;
}

void delay1(){
  volatile long i;
}
