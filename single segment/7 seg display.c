#include<LPC21xx.h>
#define seg_d 0xff
void delay(unsigned int sec)
{
T0PR=15000-1;
T0TCR=0x01;
while(T0TC<sec);
T0TCR=0x03;
T0TCR=0x00;
}
unsigned char seg_lut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
int main()
{
unsigned char i=0;
 IODIR0=seg_d ;
 
 while(i<10)
 {
 IOCLR0=seg_d ;
 IOSET0=seg_lut[i++];
  delay(500);
 }
 }
 


