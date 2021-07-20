#include <stdio.h>

int main() {
int m, n = 0;
scanf("%d %d", &m, &n);

for (int i = m; i <= n; i++) {
if (i == 1) {
continue;
}

int flag = 1;

for (int j = 2; j * j <= i; j++) {
if (i % j == 0) {
flag = 0;
break;
}
}

if (flag) printf("%d\n", i);
}

return 0;
}
