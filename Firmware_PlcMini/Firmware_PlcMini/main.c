
#include "plc.h"

uint8_t x =0;

  
int main(void)
{

	plc_init();
	
    while (1) 
    {	
		plc_read_all_input(&Input_data);						    
		
		
		 OUT1_Tog( IN1_up or IN2_up );
		 
		 OUT2_Wr( (IN3 or OUT2_Rd) and (not IN6) );			    
							
						
		plc_write_all_output(Output_data);
    }
}

 