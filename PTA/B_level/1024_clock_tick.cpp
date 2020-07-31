#include <stdio.h>

int main(int argc, char *argv[])
{
    static int  CLK_TCK = 100;
    int hours, minutes, seconds = 0;
    int start_tick, end_tick, run_time, reside_tick = 0;
    
    scanf("%d %d", &start_tick, &end_tick);
    
    run_time = (end_tick - start_tick) / CLK_TCK;
    reside_tick = (end_tick - start_tick) % CLK_TCK;
    if (reside_tick >= 50) {
        run_time += 1;
    }
    
    
    hours = run_time / 3600;
    minutes =  (run_time % 3600) / 60;
    seconds = run_time % 60;
    
    printf("%02d:%02d:%02d", hours, minutes, seconds);
    return 0;
}

