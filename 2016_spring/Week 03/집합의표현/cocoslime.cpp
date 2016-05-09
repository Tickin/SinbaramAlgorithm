#include <stdio.h>
#include <string.h>


int cache[1000000];
int arr2_size=0;
int cache_size = 0;


int temp_a, temp_b;

int plusSet(int, int);
bool check(int, int);
int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n+1; i++){
		cache[i] = i;
	}
	while (m--){
		int type;
		scanf("%d", &type);
		if (type == 0){
			int a, b;
			scanf("%d %d", &a, &b);
			plusSet(a, b);
		}
		else{
			int a, b;
			scanf("%d %d", &a, &b);
			if (check(a, b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}

int plusSet(int a, int b){
	if (cache[a] == a && cache[b] == b){//Root Root
		if (a <= b){
			cache[b] = a;
			return a;
		}
		else{
			cache[a] = b;
			return b;
		}
	}

	//Node,Root
	if (cache[a] != a && cache[b] == b){
		int temp = plusSet(cache[a], b);
		cache[a] = temp;
		cache[b] = temp;
		return temp;
		
		

	}
	else if (cache[a] == a && cache[b] != b){
		int temp = plusSet(a, cache[b]);
		cache[a] = temp;
		cache[b] = temp;
		return temp;
	}

	else if (cache[a] != a && cache[b] != b){
		int temp = plusSet(cache[a], cache[b]);
		cache[a] = temp;
		cache[b] = temp;
		return temp;
	
	}
	/*
	if (arr[a] == arr[b] == NULL){//ตัดู New
		if (a < b) {
			cache[cache_size] = a;
			arr2[arr2_size] = &cache[cache_size];
			arr[b] = &arr2[arr2_size];
			arr[a] = &arr2[arr2_size];
			arr2_size++;
			cache_size++;
			return;
		}
		else {
			cache[cache_size] = b;
			arr2[arr2_size] = &cache[cache_size];
			arr[a] = &arr2[arr2_size];
			arr[b] = &arr2[arr2_size];
			arr2_size++;
			cache_size++;
			return;
		}
	}
	//Root, Root
	if (**arr[a] == a && **arr[b] == b){
		if (a < b){
			*arr[b] = *arr[a];
			return;
		}
		else {
			*arr[a] = *arr[b];
			return;
		}
	}
	
	//Node,Root
	if (arr[a] != NULL && **arr[b] == b){
		plusSet(**arr[a], b);
	}
	else if (arr[b] != NULL && **arr[a] == a){
		plusSet(a, **arr[b]);
	}
	
	//New,Root
	if (arr[a] == NULL && **arr[b] == b){
		if (a < b){

			**arr[b] = a;
			arr[a] = arr[b];
			return;
		}
		else {
			arr[a] = arr[b];
			return;

		}
		
	}
	else if (arr[b] == NULL && **arr[a] == a){
		if (a > b){

			**arr[a] = b;
			arr[b] = arr[a];
			return;
		}
		else {
			arr[b] = arr[a];
			return;

		}

	}

	//New,Node
	if (arr[a] == NULL && arr[b] != NULL){
		plusSet(a, **arr[b]);
	}
	else if (arr[b] == NULL && arr[a] != NULL){
		plusSet(**arr[a], b);
	}

	//Node,Node
	if (arr[a] != NULL && arr[b] != NULL){
		plusSet(**arr[a], **arr[b]);
		return;
	}
	*/
}



bool check(int a, int b){
	bool res;
	if (cache[a] == a && cache[b] == b){
		if (cache[a] == cache[b]){
			temp_a = a;
			temp_b = b;
			return true;
		}
		else{
			temp_a = a;
			temp_b = b;
			return false;
		}
			
	}

	else if (cache[a] == a && cache[b] != b){
		res = check(a, cache[b]);
		
		cache[b] = temp_b;
		
	}

	else if (cache[a] != a&& cache[b] == b){
		res = check(cache[a], b);
		cache[a] = temp_a;
		
	}

	else if (cache[a] != a && cache[b] != b){
		res = check(cache[a], cache[b]);
		cache[a] = temp_a;
		cache[b] = temp_b;
	}
	return res;
}