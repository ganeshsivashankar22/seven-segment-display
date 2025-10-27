  #include<LPC21xx.h>

   #define seg1 1<<8

   #define seg2 1<<9
	#define seg3 1<<10
	#define seg4 1<<11

   #define seg 0xff<<0

   void four_seg_display(unsigned int );

   unsigned char seg_lut[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};

   void delay(unsigned int sec)

   {

   T0PR=15000-1;

   T0TCR=0x01;

   while(T0TC<sec);

   T0TCR=0x03;

   T0TCR=0x00;


   }

   int main()

   {

	 IODIR0=seg|seg1|seg2|seg3|seg4;

	 while(1)

	 {

	 four_seg_display(4567);

	}

   }

   void four_seg_display(unsigned int s)

   {

   IOCLR0=seg;

   IOSET0=seg_lut[s/1000];

   IOCLR0=seg1;

   delay(5);

   IOSET0=seg1;


   IOCLR0=seg;

   IOSET0=seg_lut[(s/100)%10];

   IOCLR0=seg2;

   delay(5);

   IOSET0=seg2;
   
   IOCLR0=seg;

   IOSET0=seg_lut[(s/10)%10];

   IOCLR0=seg3;

   delay(5);

   IOSET0=seg3;
   
   IOCLR0=seg;

   IOSET0=seg_lut[s%10];

   IOCLR0=seg4;

   delay(5);

   IOSET0=seg4;


   }


