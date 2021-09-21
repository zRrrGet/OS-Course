#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 100
#define MAX_R 1000

int n;
int shared_b[SIZE];
int p_ready, c_ready;

void produce(void){
    for(;;) {
        if (p_ready) {
            int v = rand() % MAX_R;
            if (n < SIZE) {
                shared_b[n] = v;
                printf("write %d at %d\n", shared_b[n], n);
                n++;
                c_ready = 1;
            }
            else {
                p_ready = 0;
                printf("oof, no space left\n");
            }
        }
    }

}

void consume(void){
    for(;;) {
        if (c_ready){
            if (n > 0) {
                n--;
                printf("read %d at %d\n", shared_b[n], n);
                p_ready = 1;
            }
            else {
                c_ready = 0;
                printf("oof, empty buffer\n");
            }
        }
    }
}

int main()
{
    srand(time(0));
    pthread_t p, c;
    c_ready = 0;
    p_ready = 1;
    pthread_create(&p, NULL, produce, NULL);
    pthread_create(&c, NULL, consume, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

}

