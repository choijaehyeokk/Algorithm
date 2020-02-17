#include <stdio.h>
#include <stdlib.h>
#include <cstring>


/* �־��� �׷����� vertex ���� */

#define VERTEX_NUM 10

 

struct vertx

{

    char vertex;   

    char* edge;

    int visit;     //�湮����

};

// vertex �� ����ü�� ��Ÿ���� vertex�� ������ GRAPH�� �Ѵ�.

typedef struct vertx    VERTEX;
typedef VERTEX          *GRAPH;
 

 

//vertex ����

VERTEX make_vertex(char vertex, char* edge)

{

    VERTEX tmp;

    int len= strlen(edge); //�Էµ� �������� ������ ���Ѵ�.

     

    tmp.vertex = vertex;

    tmp.edge = (char*)malloc(len * sizeof(char));//������ ������ŭ �Ҵ�

 
    strcpy(tmp.edge, edge); //����

 

    tmp.visit = 0;

     
	return tmp;
}

 

//�׷��� ����
GRAPH make_graph(char* graph[VERTEX_NUM])

{

    int i;
    GRAPH tmp; 
 

    //vertex ������ŭ ����
    tmp = (GRAPH)malloc(VERTEX_NUM * sizeof(VERTEX));

  
	for(i=0; i<VERTEX_NUM; i++)
        tmp[i] = make_vertex('A'+i , graph[i]);

    return tmp;

}

 

//�׷��� ���

void print_graph(GRAPH graph)

{
    int i;

    for(i=0; i<VERTEX_NUM; i++)
    {

        printf("vertex: %c, visit: %d, edge: %s\n", 

                graph[i].vertex, graph[i].visit, graph[i].edge);
    }

}



//�׷��� ����

void delete_graph(GRAPH graph)

{

    int i;

    //vertex ���� �����Ҵ�� �������� ����

    for(i=0; i < VERTEX_NUM; i++)

        free(graph[i].edge);
     
    free(graph); //�׷��� ���� �Ҵ� ����

}
 

//�湮����Ʈ�� ������ üũ�� �ϴ� DFS �Լ�

void dfs(GRAPH graph, char vertex , char* visited)

{

    char str[2];

    int i;
    int index = vertex - 'A'; //�ش� vertex�� �ε���
     
    str[0] = vertex;
    str[1] = '\0';  

 
    if(graph[index].visit == 0) //�湮�� �� �Ǿ��ٸ�

    {
        graph[index].visit += 1; //�湮�ϰ�
        strcat(visited, str);   //�湮����Ʈ�� �߰� 

         

        for(i =0; graph[index].edge[i] != '\0'; i++)

        {

            //vertex�� �������� ��� dfs �湮�Ѵ�.

            dfs(graph, graph[index].edge[i], visited);

        }
    }

}
 

//���Ἲ�� ã��

void find_connected_element(GRAPH graph)

{
    char visited[VERTEX_NUM+1] = "";
    int i, j=0;
//visit�� �Ǿ������� ���� ��� vertex �˻�

    for(i=0; i<VERTEX_NUM; i++)

    {

        if(graph[i].visit == 0)

        {
            //�ش����� �湮�� �ȵǾ����� dfs�Ͽ� ����� ��� vertex�湮����Ʈ ����

            dfs(graph, graph[i].vertex, visited);

 

            printf("%d connected: %s\n", ++j, visited);

             
            visited[0] = '\0'; //�ʱ�ȭ
        }

    }

}

 

int main(void)

{

    char* gra[VERTEX_NUM] = {"BC","ACF","AB","E","D","B","HJ","GI","HJ","GI"};

    GRAPH graph;

 

    graph = make_graph(gra);              //�׷��� ����

 

    print_graph(graph);                   //���

 

    printf("=======================\n\n");

 

    find_connected_element(graph);        //���Ἲ�� ã��

    printf("\n=======================\n");

 

    print_graph(graph);                   //���
 
    delete_graph(graph);                  //�׷��� ����

     

    return 0;
}
