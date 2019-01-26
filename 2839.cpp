#include <iostream>

using namespace std;

int main()
{
	int n, a;
	scanf("%d", &n);

	int ans = -1;
	for (a = 0; a * 5 <= n; a++)
		if ((n - a * 5) % 3 == 0)
			ans = a + ((n - a * 5) / 3);

	printf("%d", ans);
}