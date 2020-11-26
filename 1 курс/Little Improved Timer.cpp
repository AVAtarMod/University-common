#include <unistd.h>
#include <iostream>
#include <ctime>

struct my_time {
	int hours;
	int minutes;
	int seconds;
};

void update(my_time *t);
void display(my_time t);
void mydelay(unsigned int delay);

int main() {
	std::cout << "Вычисление задержки...\n";

    unsigned int start_time =  clock(); // начальное время
	struct my_time systime;
	systime.hours = 0;
	systime.minutes = 0;
	systime.seconds = 0;
	
	for (int i = 0;i<10	;i++) {
		update(&systime);
		display(systime);
	}
    unsigned int end_time = clock(); // конечное время
    unsigned int latency = (end_time - start_time)/10; // искомое время


	unsigned int delay = 1000000 - latency;
	std::cout << "Задержка = " << delay << " микросекунд\n\n";
	systime.hours = 0;
	systime.minutes = 0;
	systime.seconds = 0;
	for (;;) {
		update(&systime);
		display(systime);
		mydelay(delay);
	}

	return 0;
}

void update(my_time *t)
{
	t->seconds++;
	if (t->seconds == 60)
	{
		t->seconds = 0;
		t->minutes++;
	}
	if (t->minutes == 60)
	{
		t->minutes = 0;
		t->hours++;
	}
	if (t->hours == 24) t->hours = 0;
}

void display(my_time t)
{
	printf("%02d:", t.hours);
	printf("%02d:", t.minutes);
	printf("%02d\n", t.seconds);
}

void mydelay(unsigned int delay)
{
	usleep(delay);
}
