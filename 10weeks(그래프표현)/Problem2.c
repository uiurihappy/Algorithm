#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

//인접행렬 - 배열

//간선
typedef struct edge { 
	int vertex1;
	int vertex2;
	int weight;		//가중치
}EDGE;

//그래프 ADT
typedef struct graph { 
	EDGE edges[21];
	int vertices[6];
	int adjacency[6][6];	//인접
	int edgeSize;
}GRAPH;

//간선 삽입
void insertEdge(int v1, int v2, int w, GRAPH* graph) {
	EDGE* edge = graph->edges;
	int index = -1;

	//간접 리스트에 중복 검사 및 추가
	for (int i = 0; i < graph->edgeSize; i++) {
		if (edge[i].vertex1 == v1 && edge[i].vertex2 == v2) {
			edge[i].weight = w;
			index = i;
			break;
		}
		if (edge[i].vertex1 == v2 && edge[i].vertex2 == v1) {
			edge[i].weight = w;
			index = i;
			break;
		}
	}

	if (index == -1) 
		index = graph->edgeSize;

	edge[index].vertex1 = v1;
	edge[index].vertex2 = v2;
	edge[index].weight = w;

	//인접
	graph->adjacency[v1][v2] = index;
	graph->adjacency[v2][v1] = index;

	graph->edgeSize += 1;
}

void initGraph(GRAPH* graph) {
	graph->edgeSize = 0;

	//init
	for (int i = 0; i < 6; i++) {
		graph->vertices[i] = i;
		for (int j = 0; j < 6; j++)
			graph->adjacency[i][j] = -1;
	}

	insertEdge(1 - 1, 2 - 1, 1, graph);
	insertEdge(1 - 1, 3 - 1, 1, graph);
	insertEdge(1 - 1, 4 - 1, 1, graph);
	insertEdge(1 - 1, 6 - 1, 2, graph);

	insertEdge(2 - 1, 3 - 1, 1, graph);
	insertEdge(3 - 1, 5 - 1, 4, graph);

	insertEdge(5 - 1, 5 - 1, 4, graph);
	insertEdge(5 - 1, 6 - 1, 3, graph);

}

void deleteEdge(int v1, int v2, GRAPH* graph) {
	EDGE* edge = graph->edges;

	//그래프에 정점 a 혹은 b가 존재하지 않으면 아무 것도 하지 않고 –1을 출력
	if (v1 < 0 || v1 > 5 || v2 < 0 || v2 > 5) {
		printf("-1\n");
		return;
	}

	//어차피 insert에서 중복 검사하므로 따로 삭제 X
	graph->adjacency[v1][v2] = -1;
	graph->adjacency[v2][v1] = -1;

	graph->edgeSize -= 1;
}

void updateEdge(int v1, int v2, int w, GRAPH* graph) {
	EDGE* edge = graph->edges;

	//그래프에 정점 a 혹은 b가 존재하지 않으면 아무 것도 하지 않고 –1을 출력
	if (v1 < 0 || v1 > 5 || v2 < 0 || v2 > 5) {
		printf("-1\n");
		return;
	}
	//간선 존재 여부
	if (graph->adjacency[v1][v2] == -1)
		insertEdge(v1, v2, w, graph);
	else
		edge[graph->adjacency[v1][v2]].weight = w;
}

void printEdge(int v, GRAPH* graph) {
	EDGE* edge = graph->edges;
	int index;

	//존재하지 않는 노드번호
	if (v < 0 || v > 5) { 
		printf("-1\n");
		return;
	}

	for (int i = 0; i < 6; i++) {
		index = graph->adjacency[v][i];

		if (index == -1)
			continue;
		// 간선 노드, 가중치
		printf(" %d %d", i + 1, edge[index].weight);
	}
	printf("\n");
}

int main() {
	GRAPH graph;
	char order;
	int a, b, w;

	initGraph(&graph);

	while (1) {
		scanf("%c", &order);
		getchar();

		if (order == 'a') {
			scanf("%d", &a); //node
			getchar();

			printEdge(a - 1, &graph);
		}
		else if (order == 'm') {
			//a b 가중치
			scanf("%d %d %d", &a, &b, &w);
			getchar();

			if (w != 0)		//간선 변경
				updateEdge(a - 1, b - 1, w, &graph);
			else			//간선 삭제
				deleteEdge(a - 1, b - 1, &graph);
		}
		else if (order == 'q')
			break;
	}
	return 0;
}