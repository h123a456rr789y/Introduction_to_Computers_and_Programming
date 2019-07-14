/**********************************************************************
===IDEA===
Define a function P(n, k), which will return # of ways.
n represents # of remaining cookies (haven't be shared).
k represents # of cookies that Mike is going to share with a friend.

===Recursive Relation===
The total # of ways to share the cookie can be represented by a recursive relation
P(n, k) = 0						, if n < 0 or k = 0
		[WHY?] n < 0 => Remaining cookies can't be negative!
		[WHY?] k = 0 => Can Mike share cookie with number zero?
		[THUS] It is an illegal way to share cookies, so return 0
		
		= 1						, if n = 0 and k > 0
		[WHY?] There is no remaining cookies, share successfully.
		[THUS] # of ways to share cookies should be added by 1, so return 1.
		
		= P(n-k, k) + P(n, k-1) , if n > 0
		[WHY?] The first term represents ways to share n cookies 
			   will have "at least" one sharing with k cookies. => k is shared
		[WHY?] The second term represents ways to share n cookies 
			   will consists of all sharings less than(<) k cookies. => k isn't shared
		[THUS] Add two kind of ways to share cookies

===How to start?===
Because the question requires sharing from the most to the least,
the first call will be P(n, n)
**********************************************************************/

#include <stdio.h>
// A stack is going to store the # of cookies that every friends gets.
// 30 = 1 + 1 + ... + 1 (30's 1), so the size 30 is enough.
int top = -1;
int stk[30];
int intPartition(int, int);
void showStack();


int main (void)
{
    int sum ,largestNumber;
    while(1)
    {
        printf ("Enter the number of cookies: ");
        scanf("%d", &sum);
        largestNumber = sum;
        printf ("There are %d ways to share cookies.\n\n\n", intPartition(sum,largestNumber));
    }

    return 0;
}

void showStack()
{
    int i;
    for(i = 0 ; i <= top ; i++)
        printf("%d ", stk[i]);
    printf("\n");
}

int intPartition(int sum, int largestNumber)
{
	// Illegal partition
	// If illegal, the partition is wrong, do nothing but return 0.
    if(sum < 0 || largestNumber == 0)
    {
        return 0;
    }

	// Show the stack which consists of # of cookies that each friend gets.
    if (sum == 0 && largestNumber > 0)
    {
        showStack();
        return 1;
    }

	// Otherwise, keep finding the way to share cookies
    if (sum > 0 && largestNumber > 0)
    {
		// The first term of recursion relation means that "largestNum" is already shared.
		// Push current "largestNumber"	to stack to record the content of sharing
        top++;
        stk[top] = largestNumber;
        int remain = intPartition(sum - largestNumber, largestNumber);
		
		// The second term of recursion relation doesn't involve the sharing with largestNum,
		// It's necessary to pop the largestNumber that just be pushed before it call the second term(function)
        top--;
        return remain + intPartition(sum, largestNumber - 1);
    }
    return 0;
}
