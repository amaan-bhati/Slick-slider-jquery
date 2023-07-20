#include <stdio.h>

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2)
{
    if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 <= d2))
    {
        return 0; // No fine, book returned on or before the due date
    }
    else if (y1 == y2 && m1 == m2)
    {
        return 15 * (d1 - d2); // Fine based on days late in the same month
    }
    else if (y1 == y2 && m1 > m2)
    {
        return 500 * (m1 - m2); // Fine based on months late in the same year
    }
    else
    {
        return 10000; // Fixed fine, book returned after the calendar year
    }
}

int main()
{
    int d1, m1, y1, d2, m2, y2;
    scanf("%d %d %d", &d1, &m1, &y1);
    scanf("%d %d %d", &d2, &m2, &y2);

    int fine = libraryFine(d1, m1, y1, d2, m2, y2);
    printf("%d\n", fine);

    return 0;
}