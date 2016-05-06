#include <stdio.h>
int parents[1000001];
int N, M, op, a, b, aTop, bTop, i;
int findTop( int point ) {
	while( parents[point] != point )
		point = parents[point];
	return point;
}
void checkSame( int a, int b ) {
	if( a == b ) printf("YES\n");
	else {
		aTop = findTop(a);
		bTop = findTop(b);
		if( aTop == bTop ) 
			printf("YES\n");
		else 
			printf("NO\n");
	}
}
int main() {
	int N, M; scanf("%d %d", &N, &M);
	for(i=0; i<=N; i++) parents[i] = i;

	while( M-- ) {
		scanf("%d %d %d", &op, &a, &b);
		if( op == 0 ) {
			if( a == b ) continue;
			else {
				aTop = findTop( a );
				bTop = findTop( b );
				if( aTop > bTop ) 
					parents[aTop] = bTop;
				else
					parents[bTop] = aTop;
			}
		} else {
			checkSame( a, b );
		}
	}
}