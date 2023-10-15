//  단일 링크드 리스트 구현 ---->

//  헤더 파일 -->

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  데이터 및 주소를 저장하는 노드 구조체 -->

typedef struct Node
{
    int data;               //  데이터를 저장하는 정수 변수
    struct Node *next;      //  다음 노드의 주소를 저장하는 자기 참조 포인터
} nd;

//  함수 선언 -->

nd* f_ins(nd*);             //  처음 위치에 노드를 삽입하는 함수
nd* l_ins(nd*);             //  노드를 마지막 위치에 삽입하는 함수
nd* c_ins(nd*, int);        //  사용자 정의 위치에 노드를 삽입하는 함수

nd* f_del(nd*);             //  링크드 리스트의 처음 노드를 삭제하는 함수
nd* l_del(nd*);             //  링크드 리스트의 마지막 노드를 삭제하는 함수
nd* c_del(nd*, int);        //  사용자 정의 위치에서 노드를 삭제하는 함수

nd* rev(nd*);               //  링크드 리스트를 뒤집는 함수

void f_view(nd*);           //  링크드 리스트의 전체 데이터를 출력하는 함수
void c_view(nd*, int);      //  특정 노드 데이터를 링크드 리스트에서 출력하는 함수

void nd_cn(int);            //  링크드 리스트의 노드 수를 출력하는 함수

//  메인 기능 -->

int main()
{
    nd *head = NULL;         //  처음 노드의 주소를 저장하는 변수
    int node_count = 0;      //  링크드 리스트 내의 노드를 세는 변수
    char con, pos, choice;   //  선택 사항을 입력하고 계속할지, 위치를 옮길지 선택합니다.

    //  작업 메뉴 -->

    menu:

    system("cls");
    printf("\n# -------- 링크드 리스트 -------- #\n");
    printf("\n작업 ---->\n");
    printf("\n[I] 노드를 삽입하려면");
    printf("\n[D] 노드를 삭제하려면");
    printf("\n[V] 데이터를 출력하려면");
    printf("\n[N] 노드를 출력하려면");
    printf("\n[R] 리스트를 뒤집으려면");
    printf("\n\n작업 선택 ----> ");
    scanf(" %c", &choice);

    //  작업 옵션 확인 -->

    switch (choice)
    {
        //  삽입하려면 -->

        case 'I' :
        case 'i' :

            //  더 많은 옵션 확인 -->
            system("cls");
            printf("\n삽입할 위치를 선택하세요 ---->\n");
            printf("\n[F] 처음 위치에 삽입");
            printf("\n[L] 마지막 위치에 삽입");
            printf("\n[C] 원하는 위치에 삽입하려면");
            printf("\n\n작업 선택 ----> ");
            scanf(" %c", &pos);

            switch (pos)
            {
                case 'F' :
                case 'f' :

                    //  처음 위치에 노드를 삽입하는 함수
                    head = f_ins(head);
                    node_count ++;
                    break;

                case 'L' :
                case 'l' :

                    //  마지막 위치에 노드를 삽입하는 함수
                    head = l_ins(head);
                    node_count ++;
                    break;

                case 'C' :
                case 'c' :

                    //  특정 위치에 노드를 삽입하는 기능
                    head = c_ins(head, node_count);
                    node_count ++;
                    break;

                default:

                    //  잘못된 입력 선택에 대한 메시지
                    printf("\n잘못된 작업 !\n");
                    break;
            }
            break;

        case 'D' :
        case 'd' :

            //  더 많은 옵션 확인 -->
            system("cls");
            printf("\n삭제할 위치를 선택하세요 ---->\n");
            printf("\n[F] 처음 노드를 삭제하려면");
            printf("\n[L] 마지막 노드를 삭제하려면");
            printf("\n[C] 사용자 정의 노드를 삭제하려면");
            printf("\n\n작업 선택 ----> ");
            scanf(" %c", &pos);

            switch (pos)
            {
                case 'F' :
                case 'f' :

                    //  처음 노드를 삭제하는 함수
                    head = f_del(head);
                    node_count --;
                    break;

                case 'L' :
                case 'l' :

                    //  마지막 노드를 삭제하는 함수
                    head = l_del(head);
                    node_count --;
                    break;

                case 'C' :
                case 'c' :

                    //  사용자 정의 노드를 삭제하는 기능
                    head = c_del(head, node_count);
                    node_count --;
                    break;

                default:

                    //  잘못된 입력 선택에 대한 메시지
                    printf("\n잘못된 작업 !\n");
                    sleep(2);
                    goto menu;
                    break;
            }
            break;

        case 'V' :
        case 'v' :

            //  더 자세히 볼 수 있는지 확인 -->
            system("cls");
            printf("\n출력할 작업을 선택하세요 ---->\n");
            printf("\n[A] 링크드 리스트 내의 모든 데이터를 출력하려면");
            printf("\n[S] 특정 노드의 데이터를 출력하려면");
            printf("\n\n작업 선택 ----> ");
            scanf(" %c", &pos);

            switch (pos)
            {
                case 'A' :
                case 'a' :

                    //  기능: 링크드 리스트 전체 출력
                    f_view(head);
                    break;

                case 'S' :
                case 's' :

                    //  특정 노드의 데이터를 출력하는 기능
                    c_view(head, node_count);
                    break;

                default :

                    //  잘못된 입력 선택에 대한 메시지
                    printf("\n잘못된 작업 !\n");
                    break;
            }
            break;

        case 'N' :
        case 'n' :

            //  노드 수 출력 기능
            nd_cn(node_count);
            break;

        case 'R' :
        case 'r' :

            //  링크드 리스트를 뒤집는 함수
            head = rev(head);
            break;

        default :

            //  잘못된 입력 선택에 대한 메시지
            printf("\n잘못된 작업 !\n");
            break;
    }

    //  계속 작업할 것인지 확인 -->

    printf("\n작업을 계속하시겠습니까 ? [Y/N] --> ");
    scanf(" %c", &con);

    if (con=='Y' || con=='y')
    {
        goto menu;  //  True이면 메뉴로 이동
    }
    else
    {
        printf("\n감사합니다\n");
        sleep(3);
        exit(0);    //  그 외의 경우 종료
    }

    return 0;
}

//  함수 정의 -->

nd* f_ins(nd *head)
{
    int val;                                    //  데이터 값을 저장하기 위한 변수
    nd *new_node = (nd *)malloc(sizeof(nd));    //  새 노드 할당

    //  메모리가 할당되었는지 확인
    if (new_node == NULL)
    {
        //  메모리가 할당되지 않은 경우
        printf("\n죄송합니다! 메모리가 할당되지 않았습니다\n");
        return head;
    }

    //  입력 값을 저장
    printf("\n데이터 입력 --> ");
    scanf("%d", &val);

    //  새 노드에 연결하고 헤드를 업데이트
    new_node->data = val;
    new_node->next = head;
    head = new_node;

    return head;
}

nd* l_ins(nd *head)
{
    int val;                                    //  데이터 값을 저장하기 위한 변수
    nd *temp = head;                            //  마지막 노드에 도달하기 위한 임시 포인터
    nd *new_node = (nd *)malloc(sizeof(nd));    //  새로운 노드 할당

    //  메모리가 할당되었는지 확인
    if (new_node == NULL)
    {
        //  메모리가 할당되지 않은 경우
        printf("\n죄송합니다! 메모리가 할당되지 않았습니다\n");
        return head;
    }

    printf("\n데이터 입력 --> ");
    scanf("%d", &val);

    //  노드가 존재하지 않는지 확인
    if (head == NULL)
    {
        //  헤드 정보를 사용하여 새 노드를 업데이트
        new_node->data = val;
        new_node->next = head;
        head = new_node;

        return head;
    }
    //  이미 노드가 있는 경우
    else
    {
        //  마지막 노드까지 이동
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        //  임시 정보를 사용하여 새 노드 업데이트
        new_node->data = val;
        temp->next = new_node;
        new_node->next = NULL;
    }

    return head;
}

nd* c_ins(nd *head, int node_count)
{
    int i,val,indx;                             //  반복 및 인덱스를 저장하기 위한 변수
    nd *exc = head;                             //  임시 노드 및 주소 교환을 위한 포인터
    nd *temp = head->next;                      //  특정 노드로 이동하기 위한 포인터
    nd *new_node = (nd *)malloc(sizeof(nd));    //  삽입할 새로운 노드

    //  삽입할 노드 위치 입력
    printf("\n 삽입할 노드 위치를 입력하세요 --> ");
    scanf("%d", &indx);

    //  -ve 인덱스 조건 확인
    if (indx<=0)
    {
        printf("\n잘못된 인덱스입니다! [범위 밖]\n");
        return head;
    }

    //  첫 번째 노드 상태 확인
    if (indx == 1)
    {
        //  인덱스 1에 노드 삽입 함수
        head = f_ins(head);
    }

    //  인덱스가 마지막 노드인지 확인
    if (indx == (node_count+1))
    {
        head = l_ins(head);
        return head;
    }

    //  인덱스가 노드 범위를 초과하는지 확인
    if (indx > node_count)
    {
        printf("\n잘못된 인덱스입니다! [범위 밖]\n");
        return head;
    }

    //  노드 사이에 삽입
    else
    {
        printf("\n데이터 입력 --> ");
        scanf("%d", &val);

        for (i=1; i<indx-1; i++)
        {
            //  지정된 노드로 이동
            temp = temp->next;
            exc = exc->next;
        }

        //  노드 주소 업데이트 및 노드 삭제
        new_node->data = val;
        new_node->next = exc->next;
        exc->next = new_node;
    }

    return head;
}

nd* f_del(nd *head)
{
    //  링크드 리스트가 비어 있는지 확인
    if (head == NULL)
    {
        printf("\n링크드 리스트가 비어 있습니다!\n");
        return head;
    }

    nd *temp = head;        //  이동할 임시 포인터

    //  다음 노드로 헤드 업데이트 및 임시 삭제
    head = head->next;
    free(temp);

    return head;
}

nd* l_del(nd *head)
{
    //  링크드 리스트가 비어 있는지 확인
    if (head == NULL)
    {
        printf("\n링크드 리스트가 비어 있습니다!\n");
        return head;
    }

    nd *temp = head;         //  이동할 임시 포인터
    nd *exc = head->next;    //  Temp의 다음 노드를 가리키는 포인터

    //  마지막 노드까지 Temp로 이동
    while (exc->next != NULL)
    {
        //  Temp와 Exc를 마지막 노드로 업데이트
        temp = temp->next;
        exc = exc->next;
    }

    //  마지막에서 두 번째 노드에 NULL 할당 및 마지막 노드 삭제
    temp->next = NULL;
    free(exc);

    return head;
}

nd* c_del(nd *head, int node_count)
{
    int i, indx;    //  반복 및 인덱스를 저장하기 위한 변수

    //  링크드 리스트가 비어 있는지 확인
    if (head == NULL)
    {
        printf("\n링크드 리스트가 비어 있습니다!\n");
        return head;
    }

    nd *exc = head;
    nd *temp = head->next;

    printf("\n삭제할 노드? --> ");      //  삭제할 입력 노드
    scanf("%d", &indx);                  //  입력을 변수에 저장

    //  인덱스가 0인 경우
    if (indx<=0)
    {
        printf("\n잘못된 인덱스입니다! [해당 노드가 없습니다]\n");
        return head;
    }

    //  인덱스가 1인 경우
    else if (indx == 1)
    {
        head = f_del(head);     //  첫 번째 노드 삭제 함수
    }

    //  인덱스가 마지막 노드를 초과하는 경우
    else if (indx > node_count)
    {
        printf("\n잘못된 인덱스입니다! [노드가 없습니다]\n");
        return head;
    }

    //  인덱스가 범위를 벗어난 경우
    else if (temp == NULL || temp->next == NULL)
    {
        printf("\n잘못된 인덱스입니다! [범위 밖]\n");
        return head;
    }

    else
    {
        for (i=1; i<indx-1; i++)
        {
            //  지정한 인덱스로 이동
            temp = temp->next;
            exc = exc->next;
        }

        //  노드 주소 업데이트 및 노드 삭제
        exc->next = temp->next;
        free(temp);
    }

    return head;
}

nd* rev(nd *head)
{
    //  링크드 리스트가 비어 있는지 확인
    if (head == NULL)
    {
        printf("\n뒤집을 노드가 없습니다!\n");
        return head;
    }
    //  서로 다른 노드를 가리킬 포인터 설정
    nd *prev,*curr,*nxt;
    prev=NULL;              
    curr=nxt=head;

    while(nxt!=NULL)
    {
            //  리스트를 탐색
            nxt=nxt->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
    }

    //  헤드 할당
    head=prev;

    printf("\n링크드 리스트가 성공적으로 뒤집혔습니다.\n");
    return head;
}

void f_view(nd *head)
{
    //  링크드 리스트가 비어 있는지 확인
    if (head == NULL)
    {
        printf("\n링크드 리스트가 비어 있습니다!\n");
        return;
    }

    while (head != NULL)
    {
        //  링크드 리스트를 탐색하고 데이터 출력
        printf("\n데이터 --> %d", head->data);
        head = head->next;  //  다음 노드로 이동
    }

    printf("\n");
}

void c_view(nd *head, int node_count)
{
    int i, indx;        //  반복 및 인덱스를 저장하기 위한 변수
    nd *temp = head;    //  특정 노드로 이동하기 위한 포인터

    //  링크드 리스트가 비어 있는지 확인
    if (head == NULL)
    {
        printf("\n링크드 리스트가 비어 있습니다!\n");
        return;
    }

    printf("\n인덱스를 입력하여 노드 데이터를 출력 --> ");
    scanf("%d", &indx);

    if (indx<=0 || indx>node_count)
    {
        printf("\n잘못된 노드입니다 !\n");
        return;
    }

    for (i=1; i<indx; i++)
    {
        //  지정된 노드로 이동
        temp = temp->next;
    }

    //  지정된 노드에서 데이터 출력
    printf("\n데이터 --> %d\n", temp->data);
}

void nd_cn(int node_count)
{
    //  노드 수 출력
    printf("\n 노드 --> %d\n", node_count);
}