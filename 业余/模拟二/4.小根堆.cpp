/*小根堆 
(1)插入 
void up(int* heap, int n, int u) {
	while(u > 1 && heap[u] < heap[u / 2]) {\
		swap(heap[u], headp[u / 2]);
		u /= 2;
	}
}
int heap[N]; 
heap[n] = x;
up(n);

(2)建堆 
int down(int* heap, int n, int u) {
	int t = u;
	if(t * 2 <= n && heap[t * 2] < heap[t])
		t = t * 2;
	if(t * 2 + 1 <= n && heap[t * 2 + 1] < heap[t])
		t = t * 2 + 1;
	if(t != u) {
		swap(heap[t], heap[u]);
		down(heap, n, t);
	} 
}
void create(int* heap, int n) {
	for(int i = n / 2; i; i--) {
		down(i);
	}
}
*/
