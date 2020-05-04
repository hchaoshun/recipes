#include <semaphore.h>

//多线程按顺序打印ABC
class PrintABC{
    public:
        PrintABC() {
            sem_init(&first, 0, 1);
            sem_init(&second, 0, 0);
            sem_init(&third, 0, 0);
        }

        ~PrintABC() {
            sem_destroy(&first);
            sem_destroy(&second);
            sem_destroy(&third);
        }

        void printA() {
            for (int i = 0; i < 10; i++) {
                sem_wait(&first);
                printf("A");
                sem_post(&second);
            }
        }

        void printB() {
            for (int i = 0; i < 10; i++) {
                sem_wait(&second);
                printf("B");
                sem_post(&third);
            }
        }

        void printC() {
            for (int i = 0; i < 10; i++) {
                sem_wait(&third);
                printf("C");
                sem_post(&first);
            }
        }

    private:
        sem_t first;
        sem_t second;
        sem_t third;

};
