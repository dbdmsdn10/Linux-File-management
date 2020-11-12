#include <time.h>
long CarculDate(int year, int month, int day)
{
    int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int i;
    long total = 0L;
    total = (year - 1) * 365L + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    if (!(year % 4) && year % 100 || !(year % 400))
        months[1]++;
    for (i = 0; i < month - 1; i++)
        total += months[i];
    total += day;
    return total;
}
