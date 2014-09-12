/******************************************************************************/
/* Copyright (C) cd.com, stu@USTC,2014-2015                                   */
/*                                                                            */
/* FILE NAME            : testcd.c                                            */
/* PRINCIPAL AUTHOR     : Cuidandan                                           */
/* SUBSYSTEM NAME       : testcd                                              */
/* MODULE NAME          : testcd                                              */
/* LANGUAGE             : c                                                   */
/* TARGET ENVIRONMENT   : ANY                                                 */
/* DATE OF FIRST RELEASE: 2014/09/11                                          */
/* DESCRIPTION          : This is a testcd program                            */
/******************************************************************************/

/*
 * Revision log;
 *  
 * Created by Cuidandan,2014/09/11
 *  
 */ 
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define DESC_LEN   1024
#define cmd_num    7
#define cmd_len    7

typedef struct DataNode
{
   char cmd[cmd_len];
   char desc[DESC_LEN];
   struct DataNode *next;
} tDataNode;
char cmd[cmd_num][cmd_len] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
main()
{
    tDataNode *head=NULL;
    /*Init cmd list */
    int i;
    tDataNode * p= NULL;

    for(i = 0; i < cmd_num; i++)
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
       char command[cmd_len];
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
