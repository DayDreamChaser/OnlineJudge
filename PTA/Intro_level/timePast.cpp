#include <stdio.h>

int main(void)
{
    int all_min;
    int time, past;
    int min, hour;
    scanf("%d %d", &time, &past);
    
    all_min = (time / 100) * 60 +(time % 100);
    /* time past*/
    all_min += past;
    hour = all_min / 60;
    min = all_min % 60;
    if ( min < 10 ) {
  		printf("%d0%d\n", hour, min);
    } else {
  		printf("%d%d\n", hour, min);
    }

    return 0;	
}