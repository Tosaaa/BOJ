// https://www.acmicpc.net/problem/11375
// Max Flow
// Ford-Fulkerson with BFS (Edmonds-Karp)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 6
#define INF INT_MAX

typedef struct QueueNode {
    int val;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
    int n;
} Queue;

Queue* init_queue();
void enqueue(Queue *queue, int val);
int dequeue(Queue *queue);
int isEmpty(Queue *queue);
void del_queue(Queue *queue);

typedef struct GraphNode {
    int val;
    int weight;
    struct GraphNode *next;
} GraphNode;

typedef struct Graph {
    int V;
    int E; // # of directed edges
    GraphNode **adj;
} Graph;

Graph *init_graph(int v); // v nodes, returns a graph with weight = 0 for diagonal elements, INF otherwise.
void addEdge(Graph *graph, int v, int w); // v->w (directed)
void setEdgeWeight(Graph *graph, int v, int w, int weight); // v->w (directed)
int isEdge(Graph *graph, int v, int w); // returns 1 if there is an edge from v to w, otherwise 0.
void del_graph(Graph *graph);
void traversal(Graph *graph); // prints adjacency matrix

void maxFlow(Graph *graph, int s, int t);
int findPath(Graph *graph, int s, int t, int *path);
int findPathUtil(Graph *graph, Queue *queue, int s, int t, int *visited, int *path);

Queue* init_queue() {
    Queue *queue = malloc(sizeof *queue);
    queue->front = NULL;
    queue->rear = NULL;
    queue->n = 0;
    return queue;
}

void enqueue(Queue *queue, int val) {
    QueueNode *new_node = malloc(sizeof *new_node);
    new_node->val = val;
    new_node->next = NULL;
    if (isEmpty(queue))
        queue->front = new_node;
    else
        queue->rear->next = new_node;
    queue->rear = new_node;
    queue->n++;
    return;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        fprintf(stdout, "Error: queue is empty.\n");
        return -1; // user should aware that -1 indicates error.
    }
    QueueNode *node = queue->front;
    int val = node->val;
    queue->front = node->next;
    free(node);
    queue->n--;
    return val;
}

int isEmpty(Queue *queue) {
    //if (queue == NULL)
    return !(queue->n);
}

void del_queue(Queue *queue) {
    if (queue == NULL) return;
    if (isEmpty(queue)) {
        free(queue);
        return;
    }
    QueueNode *walk;
    QueueNode *temp;
    walk = queue->front;
    while (walk != NULL) {
        temp = walk;
        walk = walk->next;
        free(temp);
    }
    free(queue);
    return;
}

Graph *init_graph(int v) { 
    Graph *graph = malloc(sizeof *graph);
    graph->V = v;
    graph->E = 0;
    graph->adj = calloc(v, sizeof *(graph->adj));
    return graph;
}

void addEdge(Graph *graph, int v, int w) { // adjacency list based on linked list.
    graph->E++; // assuming there was no edge between v, w
    GraphNode *node = malloc(sizeof *node);
    node->val = w;
    node->next = NULL;
    node->weight = 1;

    if (graph->adj[v] == NULL) {
        graph->adj[v] = node;
        return;
    }

    GraphNode *walk = graph->adj[v];
    for (; walk->next != NULL; walk = walk->next); // walk becomes tail.
    walk->next = node;
    return;
}

void setEdgeWeight(Graph *graph, int v, int w, int weight) {
    if (weight == 0 || weight == INF) return;
    graph->E++; // assuming there was no edge between v, w
    GraphNode *node = malloc(sizeof *node);
    node->val = w;
    node->next = NULL;
    node->weight = weight;

    if (graph->adj[v] == NULL) {
        graph->adj[v] = node;
        return;
    }

    GraphNode *walk = graph->adj[v];
    for (; walk->next != NULL; walk = walk->next); // walk becomes tail.
    walk->next = node;
    return;
}

int isEdge(Graph *graph, int v, int w) {
    GraphNode *walk = graph->adj[v];
    while (walk != NULL) {
        if (walk->val == w)
            return 1;
        walk = walk->next;
    }
    return 0;
}

void del_graph(Graph *graph) {
    if (graph == NULL) return;
    if (graph->V == 0) {
        free(graph);
        return;
    }

    GraphNode *walk;
    GraphNode *temp;
    for (int i = 0; i < graph->V; i++) {
        walk = graph->adj[i];
        while (walk != NULL) {
            temp = walk;
            walk = walk->next;
            free(temp);
        }
    }
    free(graph->adj);
    free(graph);
    return;
}

void traversal(Graph *graph) { // adj mat으로 출력?
    int v = graph->V;
    GraphNode *walk;
    for (int i = 0; i < v; i++) {
        walk = graph->adj[i];
        while (walk != NULL) {
            printf("%d -> %d: %d\n", i, walk->val, walk->weight);
            walk = walk->next;
        }
        printf("----------\n");
    }
}

// s: source, t: sink, O(VE^2)?
void maxFlow(Graph *graph, int s, int t) {
    if (s == t) {
        printf("source is equal to sink\n");
        return;
    } else if (t >= graph->V) {
        printf("sink is too large\n");
        return;
    }
    int maxflow = 0;
    int *path = malloc(sizeof *path * graph->V);

    // 최대 VE번 반복
    while (1) {
        for (int i = 0; i < graph->V; i++)
            path[i] = -1;

        //O(E)
        if (!findPath(graph, s, t, path)) {  // no path, max_flow found
            //printf("Max Flow found: %d\n", maxflow);
            break;
        } else {  // update
            int len = 0;
            for (int i = 0; i < graph->V; i++) {
                if (path[i] == -1) break;
                printf("%d ", path[i]);
                len++;
            }
            printf("\n");

            // find min
            GraphNode *walk;
            int min = INF;

            // 아래 반복문은 최악의 경우 O(E)
            for (int i = 0; i < len; i++) {
                //printf("%d -> %d\n", path[i], path[i+1]);
                walk = graph->adj[path[i]];
                while (walk != NULL) {
                    if (walk->val == path[i + 1] && walk->weight < min) {
                        min = walk->weight;
                    }
                    walk = walk->next;
                }
            }
            maxflow += min;  // add incremented flow
            //printf("incremented flow: %d, current maxflow: %d\n", min, maxflow);
            //traversal(graph);

            //increase forward flow (decrease weight)
            // 아래 반복문은 최악의 경우 O(E)
            for (int i = 0; i < len; i++) {
                walk = graph->adj[path[i]];
                while (walk != NULL) {
                    if (walk->val == path[i + 1]) {
                        walk->weight -= min;
                    }
                    walk = walk->next;
                }
            }
            //traversal(graph);

            //decrease backward flow (increase weight)
            // 아래 반복문은 최악의 경우 O(E)
            for (int i = len - 1; i > 0; i--) {
                int isEdge = 0;
                //printf("%d -> %d\n", path[i], path[i-1]);
                walk = graph->adj[path[i]];
                while (walk != NULL) {
                    if (walk->val == path[i - 1]) {
                        walk->weight += min;
                        isEdge = 1;
                    }
                    walk = walk->next;
                }
                if (!isEdge) setEdgeWeight(graph, path[i], path[i - 1], min);
            }
            //traversal(graph);
        }
    }
    //free(path);
    return;
}

// use BFS to find a residual capacity(증가 경로) from source to sink => Edmonds-Karp
int findPath(Graph *graph, int s, int t, int *path) {
    int *visited = calloc(graph->V, sizeof *visited);
    Queue *queue = init_queue();
    int valid = findPathUtil(graph, queue, s, t, visited, path);
    free(visited);
    del_queue(queue);
    return valid;
}

int findPathUtil(Graph *graph, Queue *queue, int s, int t, int *visited, int *path) {
    visited[s] = 1;
    enqueue(queue, s);
    int valid = 0;

    // storing parents
    int *p = malloc(sizeof *p * graph->V);
    for (int i = 0; i < graph->V; i++)
        p[i] = -1;

    while (!isEmpty(queue)) {
        int r = dequeue(queue);
        // found path from source to sink
        if (r == t) {
            valid = 1;  // to check if there is a path.
            break;
        }

        GraphNode *walk = graph->adj[r];
        while (walk != NULL) {
            if (!visited[walk->val] && (walk->weight > 0)) {
                enqueue(queue, walk->val);
                visited[walk->val] = 1;
                p[walk->val] = r;  // sets parent info
            }
            walk = walk->next;
        }
    }

    // if there is no path
    if (!valid) {
        free(p);
        return 0;
    } else {
        // backtrack to create path
        int idx = 0;
        path[idx++] = t;
        while (p[t] != s) {
            path[idx++] = p[t];
            t = p[t];
        }
        path[idx] = s;

        //reverse array
        int tmp;
        for (int i = 0; i <= idx / 2; i++) {
            tmp = path[i];
            path[i] = path[idx - i];
            path[idx - i] = tmp;
        }

        free(p);
        return 1;
    }
}

int main() {
    Graph *graph = init_graph(MAX_SIZE);

    //traversal(graph);
    maxFlow(graph, 0, 5);

    del_graph(graph);
}