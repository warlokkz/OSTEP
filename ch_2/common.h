#include <sys/time.h>

void Spin(int time)
{
    long pause;
    clock_t now, then;

    pause = time * 1000 * (CLOCKS_PER_SEC/1000);
    now = then = clock();
            
    while ((now - then) < pause)
    {
        now = clock();
    }
}
