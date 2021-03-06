//힙 정렬
//힙 정렬은 힙 트리 구조를 이용하는 정렬 방법
//힙이 무엇인가
//
//이진트리란 컴퓨터가 데이터를 표현할 때 데이터를 각 노드에 담은 뒤에 노드를 두 개씩 이어 붙이는 구조를 말한다.
// -> 이러한 데이터를 노드라고도한다.
// -> 자식이 최대 2개 (2개,1개, 없음)
//가장 아래쪽을 리프노드
//가장 위를 루트 노드라고 한다.
//트리는 가지가 뻗어나가는 것처럼 연결된다.
// 완전 이진트리란 데이터가 왼쪽 오른쪽 차곡차곡 들어간다.
// 중간 노드가 비어있지 않고 빽빽하게 차있다.
// 왼쪽 노드부터 채워진다. 같은 차수에서는 왼쪽 왼오 채우고 오른쪽 왼오 채우는 것
// 힙이란 최소값이나 최대값을 빠르게 찾아내기 위해 완전 이진 트리를 이용
// 최대힙이란 부모 노드가 자식 보다 큰 것
// 한 노드로 최대힙이 형성이 안되는 경우가 있는데 그러면 자식중에 제일 큰 값과 자신하고 바꾸는 것
// 힙 생성 알고리즘을 통해 최대힙을 유지
//아래쪽으로 내려가면서 힙을 유지할 수 있도록 계속 해준다.
// 힙 생성 알고리즘 시간 복잡도 == 한번의 heapify는 트리의 높이 == logn, 모든 정점 n에 대해 수행 => O(nlogn)
		//실제로는 특정 숫자 1/2만 수행해도 힙정렬 수행 가능 => O(1/2 n log n) -> 1/2n이 logn보다 더 크니까 ->n으로 바꿈
		//-> n/2 * log2n -> log2n이 n/2보다 작으니 O(N)이 된다????????????? 
		
		
	//완전 이진 트리는 차례대로 담아도 문제 없다.
	//이후 heap구조로 만들어준다. 9개 데이터면 9번 연산이면 만들어진다 
	//상향식과 하향식 두가지 방법이 존재
	//heap가장 위에 값을 아래로 옮겨주고 다시 heapify수행하고 반복 -> 정렬이 수행된다.
	 
#include<stdio.h>

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};

int main(void){
	//먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다. 
	for(int i = 1; i< number; i++){
		int c= i;
		do {
			int root = (c-1)/2; //root는 자기 자신의 부모를 의미한다. 
			if(heap[root] < heap[c]){ //자식이 더크면 바꿔준다. 
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root; //자식의 부모로 이동해서 반복 수행 
		}while(c !=0); //최상단 부모면 종료 
	}
	//이게 nlogn?????? 
	//힙이 만들어졌으므로 크기를 줄여가며 반복적으로 힙을 구성 n번 반복하면 힙 정렬이 만들어진다. 
	for(int i = number -1; i>=0; i--){
		int temp = heap[0]; //루트 노드와 가장 마지막 노드를 바꾸어준다. 
		heap[0] = heap[i]; //가장 큰 값을 마지막으로 보낸다.
		heap[i] = temp; 
		int root =0;
		int c=1;
		do{
			//힙구조를 다시 만든다. 
			c =2*root +1; 
			//c는 루트의 자식이 된다.
			if(heap[c] < heap[c+1] && c<i-1){ //c가 i-1보다 커질수는 없게 한다. //범위 벗어나지 않도록 
				c++; //왼쪽과 오른쪽 중 더 큰 값을 c에 담는다. 
			}
			//루트보다 자식이 더 크다면 교환
			if(heap[root] < heap[c] && c <i){
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c; //c를 다시 root로 이동 // 재귀적 힙 구조 만든다. 
		}while(c<i);
	}
	for(int i = 0; i< number; i++){
		printf("%d\n", heap[i]);
	}
}
