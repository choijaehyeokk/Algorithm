#include <stdio.h>
#include <stdlib.h>
#include <cstring>


/* 주어진 그래프의 vertex 개수 */

#define VERTEX_NUM 10

 

struct vertx

{

    char vertex;   

    char* edge;

    int visit;     //방문여부

};

// vertex 를 구조체로 나타내고 vertex의 집합을 GRAPH로 한다.

typedef struct vertx    VERTEX;
typedef VERTEX          *GRAPH;
 

 

//vertex 생성

VERTEX make_vertex(char vertex, char* edge)

{

    VERTEX tmp;

    int len= strlen(edge); //입력된 엣지들의 갯수를 구한다.

     

    tmp.vertex = vertex;

    tmp.edge = (char*)malloc(len * sizeof(char));//엣지의 개수만큼 할당

 
    strcpy(tmp.edge, edge); //복사

 

    tmp.visit = 0;

     
	return tmp;
}

 

//그래프 생성
GRAPH make_graph(char* graph[VERTEX_NUM])

{

    int i;
    GRAPH tmp; 
 

    //vertex 개수만큼 생성
    tmp = (GRAPH)malloc(VERTEX_NUM * sizeof(VERTEX));

  
	for(i=0; i<VERTEX_NUM; i++)
        tmp[i] = make_vertex('A'+i , graph[i]);

    return tmp;

}

 

//그래프 출력

void print_graph(GRAPH graph)

{
    int i;

    for(i=0; i<VERTEX_NUM; i++)
    {

        printf("vertex: %c, visit: %d, edge: %s\n", 

                graph[i].vertex, graph[i].visit, graph[i].edge);
    }

}



//그래프 삭제

void delete_graph(GRAPH graph)

{

    int i;

    //vertex 각각 동적할당된 엣지들을 헤제

    for(i=0; i < VERTEX_NUM; i++)

        free(graph[i].edge);
     
    free(graph); //그래프 동적 할당 헤제

}
 

//방문리스트를 가지고 체크를 하는 DFS 함수

void dfs(GRAPH graph, char vertex , char* visited)

{

    char str[2];

    int i;
    int index = vertex - 'A'; //해당 vertex의 인덱스
     
    str[0] = vertex;
    str[1] = '\0';  

 
    if(graph[index].visit == 0) //방문이 안 되었다면

    {
        graph[index].visit += 1; //방문하고
        strcat(visited, str);   //방문리스트에 추가 

         

        for(i =0; graph[index].edge[i] != '\0'; i++)

        {

            //vertex의 엣지들을 모두 dfs 방문한다.

            dfs(graph, graph[index].edge[i], visited);

        }
    }

}
 

//연결성분 찾기

void find_connected_element(GRAPH graph)

{
    char visited[VERTEX_NUM+1] = "";
    int i, j=0;
//visit가 되었는지에 대해 모든 vertex 검색

    for(i=0; i<VERTEX_NUM; i++)

    {

        if(graph[i].visit == 0)

        {
            //해당점이 방문이 안되었으면 dfs하여 연결된 모든 vertex방문리스트 생성

            dfs(graph, graph[i].vertex, visited);

 

            printf("%d connected: %s\n", ++j, visited);

             
            visited[0] = '\0'; //초기화
        }

    }

}

 

int main(void)

{

    char* gra[VERTEX_NUM] = {"BC","ACF","AB","E","D","B","HJ","GI","HJ","GI"};

    GRAPH graph;

 

    graph = make_graph(gra);              //그래프 생성

 

    print_graph(graph);                   //출력

 

    printf("=======================\n\n");

 

    find_connected_element(graph);        //연결성분 찾기

    printf("\n=======================\n");

 

    print_graph(graph);                   //출력
 
    delete_graph(graph);                  //그래프 삭제

     

    return 0;
}
