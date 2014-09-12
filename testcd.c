#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DESC_LEN   1024
#define CMD_NUM    7
#define CMD_LEN    7

typedef struct DataNode
{
   char cmd[CMD_LEN];
   char desc[DESC_LEN];
   struct DataNode *next;
} tDataNode;

char cmd[CMD_NUM][CMD_LEN] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main()
{
    tDataNode *head = NULL;
    /*Init cmd list */
    int i;
    tDataNode *p = NULL;
    for(i = 0; i < CMD_NUM; i++)
    {
       p = (tDataNode*) malloc(sizeof(tDataNode));
       strcpy(p -> cmd, cmd[i]);
       snprintf(p->desc, DESC_LEN, "This is %d cmd.", i + 1);
       p -> next = head;
       head = p;
    }
    printf("menu list:\n");
    p = head;
    while(p != NULL)
    {vi
      printf("%s - %s \n", p -> cmd,p -> desc);
      p = p -> next;
    }

    /* cmd line begins */
    while(1)
    {
       char command[CMD_LEN];
	   printf("Input a char cmd >");
       scanf("%s", command);
       p = head;
       while(p != NULL)
       {
           if(strcmp(p -> cmd, command) == 0)
           {
               printf("%s - %s \n", p -> cmd, p->desc);
               break;
           } 
           p = p->next;
       }
    }
    return 0;
}
