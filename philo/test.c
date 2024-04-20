#include <libc.h>
#include <sys/time.h>

int main ()
{
	struct timeval time;

	gettimeofday(&time, NULL);
}
