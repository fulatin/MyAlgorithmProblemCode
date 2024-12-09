#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int q[100000];
int *start,*end;

template<typename T>
T in() {
	T res;
	char c = 0;
	while(!isdigit(c=getchar()));
	res = c-'0';
	while(isdigit(c=getchar())) {
		res = res*10 + c-'0';
	}
	return res;

}

void append(int x) {
	*(end++) = x;
}

void pop() {
	if(start!=end)
		start++;
	else
		printf("ERR_CANNOT_POP\n");
}

void query() {
	if(start==end) {
		printf("ERR_CANNOT_QUERY\n");
	} else {
		printf("%d\n",*start);
	}
}
void size() {
	printf("%lu\n",end-start);
}

int main() {
	int n ;
	n = in<int>();
	start = end = q;
	while(n--) {

		int tp = in<int>();
		if(tp==1) {
			int x = in<int>();
			append(x);
		} else if(tp==2) {
			pop();
		} else if(tp==3) {
			query();
		} else {
			size();
		}
	}

	return 0;
}
