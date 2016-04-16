#include <stdio.h>
#include <stdint.h>

int main()
{
   uint16_t mem_loc = 0b1111111011111110;
   uint8_t lower_eight_bits = 0;
   uint8_t upper_eight_bits = 0;

   lower_eight_bits = mem_loc & 0b0000000011111111;
   upper_eight_bits = (mem_loc & 0b1111111100000000) >> 8;

   printf("mem_loc: 0x%04x\n", mem_loc);
   printf("lower_eight_bits: 0x%02x\n", lower_eight_bits);
   printf("upper_eight_bits: 0x%02x\n", upper_eight_bits);
   return 0;
}
