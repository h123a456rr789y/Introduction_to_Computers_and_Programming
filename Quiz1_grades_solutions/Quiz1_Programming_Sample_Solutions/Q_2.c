/***********************************************************
How to finish this question without compute the days?
(for example day 0 ~ 31 is Jan, day 32~59 is Feb, etc.)
IDEA: take advantage of switch-case and the effect of break
	  , just need to copy/paste the elements in switch-case
	  and make a slight modification to them.
***********************************************************/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{

    int month, date, day;
    printf("Please enter the date and the number of days: ");
    scanf("%d/%d %d",&month, &date, &day);
	// First add all days to the current date
    date = day + date;
	
	// Now, all you have to do is to minus the days of the month,
	// in order to find out whether the result is in that month
    switch(month)
    {
        case 1:
            date = date  - 31;
			// If the result is in that month, show messages and jump out of switch.
            if(date <= 0)	
            {
                printf("His birthday is %d/%d\n", month, (date + 31));
                break;
            }
			// If the result is not in that month, it need to compute further.
			// Because there is no break before case 2, the program will continue to compute.
            month = month + 1;
        case 2:
            date = date  - 28;
            if(date <= 0)
            {
                printf("His birthday is %d/%d\n", month, (date + 28));
                break;
            }
            month = month + 1;
        case 3:
            date = date  - 31;
            if(date <= 0)
            {
                printf("His birthday is %d/%d\n", month, (date + 31));
                break;
            }
            month = month + 1;
        case 4:
            date = date  - 30;
            if(date <= 0)
            {
                printf("His birthday is %d/%d\n", month, (date + 30));
                break;
            }
            month = month + 1;
        case 5:
            date = date  - 31;
            if(date <= 0)
            {
                printf("His birthday is %d/%d\n", month, (date + 31));
                break;
            }
            month = month + 1;
        case 6:
            date = date  - 30;
            if(date <= 0)
            {
                printf("His birthday is %d/%d\n", month, (date + 30));
                break;
            }
            else
            {
				// If compute to June, and still got remaining days, the birthday is in next year!
                printf("His birthday is in next year.\n");
                break;
            }
        default:
            break;
    }
    return 0;
}
