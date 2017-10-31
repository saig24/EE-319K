// SysTick.c
// Implements two busy-wait based delay routines
#include <stdint.h>
// Initialize SysTick with busy wait running at bus clock.
#define NVIC_ST_CTRL_R      (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile unsigned long *)0xE000E014))//reload is the counter register
#define NVIC_ST_CURRENT_R   (*((volatile unsigned long *)0xE000E018))
void SysTick_Init(void){
	NVIC_ST_CTRL_R = 0;//Disable
	NVIC_ST_RELOAD_R = 0x00FFFFFF;// set to max value 
	NVIC_ST_CURRENT_R = 0;// Clears current
	NVIC_ST_CTRL_R = 5;// 0101 Clk and enable
}
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTick_Wait(uint32_t delay){//in terms of cycles
	NVIC_ST_RELOAD_R = delay-1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
}

// Time delay using busy wait.
// waits for count*10ms
// 10000us equals 10ms
void SysTick_Wait10ms(uint32_t delay){//in terms of 10ms
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//1
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000-1);//2
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//3
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//4
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//5
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//6
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//7
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}
	NVIC_ST_RELOAD_R = (delay)*(10000);//8
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R &0x00010000)==0){
	}

}

