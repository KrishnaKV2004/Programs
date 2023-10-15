//  単一リンクリストの実装

//  ヘッダーファイル -->

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  データ+アドレスを格納するノード構造 -->

typedef struct Node
{
    int data;               //  データを格納する整数変数
    struct Node * next;     //  次のノードのアドレスを格納するための自己参照ポインタ
} nd;

//  関数の宣言 -->

nd* f_ins(nd*);             //  最初の位置にノードを挿入するには
nd* l_ins(nd*);             //  ノードを最後の位置に挿入するには
nd* c_ins(nd*, int);        //  カスタム位置にノードを挿入するには

nd* f_del(nd*);             //  リンクされたリストの最初のノードを削除するには
nd* l_del(nd*);             //  リンクされたリストの最後のノードを削除するには
nd* c_del(nd*, int);        //  カスタム位置からノードを削除するには

nd * rev(nd *);             //  リンクされたリストを逆にするには

void f_view(nd*);           //  リンクされたリストの完全なデータを表示するには
void c_view(nd*, int);      //  リンクされたリストで特定のノード データを表示するには

void nd_cn(int);            //  リンクされたリストのノード数を表示するには

//  メイン機能 -->

int main()
{
    nd *head = NULL;         //  最初のノードのアドレスを格納するには
    int node_count = 0;      //  リンクされたリスト内のノードを数えるには
    char con, pos, choice;   //  選択肢を入力するには、続行し、操作する位置に移動します

    //  操作メニュー -->

    menu :

        system("cls");
        printf("\n# -------- リンクされたリスト -------- #\n");
        printf("\nオペレーション ---->\n");
        printf("\n[I] ノードを挿入するには");
        printf("\n[D] ノードを削除するには");
        printf("\n[V] データを表示するには");
        printf("\n[N] ノードを表示するには");
        printf("\n[R] リストを逆にするには");
        printf("\n\n操作を選択 ----> ");
        scanf(" %c", &choice);

        //  動作事例の確認 -->

        switch (choice)
        {
            //  挿入するには -->

            case 'I' :
            case 'i' :

                //  さらなる可能性を検証する -->
                system("cls");
                printf("\n挿入する場所を選択してください ---->\n");
                printf("\n[F] 最初の位置に挿入する");
                printf("\n[L] 最後の位置に挿入する");
                printf("\n[C] 任意の位置に挿入するには");
                printf("\n\n操作を選択 ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'F' :
                    case 'f' :

                        //  最初の位置にノードを挿入する関数
                        head = f_ins(head);
                        node_count ++;
                        break;

                    case 'L' :
                    case 'l' :

                        //  最後の位置にノードを挿入する関数
                        head = l_ins(head);
                        node_count ++;
                        break;

                    case 'C' :
                    case 'c' :

                        //  特定の位置にノードを挿入する機能
                        head = c_ins(head, node_count);
                        node_count ++;
                        break;

                    default:

                        //  無効な入力選択に対するメッセージ
                        printf("\n無効な操作 !\n");
                        sleep(2);
                        goto menu;
                        break;
                }
                break;

            case 'D' :
            case 'd' :

                //  さらなる可能性を検証する -->

                system("cls");
                printf("\n削除する場所を選択 ---->\n");
                printf("\n[F] 最初のノードを削除するには");
                printf("\n[L] 最後のノードを削除するには");
                printf("\n[C] カスタムノードを削除するには");
                printf("\n\n操作を選択 ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'F' :
                    case 'f' :

                        //  最初のノードを削除する関数
                        head = f_del(head);
                        node_count --;
                        break;

                    case 'L' :
                    case 'l' :

                        //  最後のノードを削除する関数
                        head = l_del(head);
                        node_count --;
                        break;

                    case 'C' :
                    case 'c' :

                        //  カスタムノードを削除する機能
                        head = c_del(head, node_count);
                        node_count --;
                        break;

                    default:

                        //  無効な入力選択に対するメッセージ
                        printf("\n無効な操作 !\n");
                        break;
                }
                break;

            case 'V' :
            case 'v' :

                //  さらに視聴できるかどうかを確認する -->

                system("cls");
                printf("\n表示する操作を選択 ---->\n");
                printf("\n[A] リンクされたリスト内のすべてのデータを表示するには");
                printf("\n[S] 特定のノードのデータを表示するには");
                printf("\n\n操作を選択 ----> ");
                scanf(" %c", &pos);

                switch (pos)
                {
                    case 'A' :
                    case 'a' :

                        //  機能 リンクされたリスト全体を表示する
                        f_view(head);
                        break;

                    case 'S' :
                    case 's' :

                        //  特定のノードのデータを表示する機能
                        c_view(head, node_count);
                        break;

                    default :

                        //  無効な入力選択に対するメッセージ
                        printf("\n無効な操作 !\n");
                        break;
                }
                break;

            case 'N' :
            case 'n' :

                //  ノード数を表示する機能
                nd_cn(node_count);
                break;

            case 'R' :
            case 'r' :

                //  リンクされたリストを反転する関数
                head = rev(head);
                break;

            default :

                //  無効な入力選択に対するメッセージ
                printf("\n無効な操作 !\n");
                break;
        }

        //  業務を継続するには -->

        printf("\n操作を続行しますか ? [Y/N] --> ");
        scanf(" %c", &con);

        if (con=='Y' || con=='y')
        {
            goto menu;  //  True の場合、メニューに移動
        }
        else
        {
            printf("\nありがとうございます。\n");
            sleep(3);
            exit(0);    //  それ以外の場合は終了します
        }

    return 0;
}

//  関数の定義 -->

nd* f_ins(nd *head)
{
    int val;                                    //  データ値を保存するには
    nd *new_node = (nd *)malloc(sizeof(nd));    //  新しいノードの割り当て

    //  メモリが割り当てられているかどうかを確認する
    if (new_node == NULL)
    {
        //  メモリが割り当てられていない場合
        printf("\nごめん ! メモリが割り当てられていません\n");
        return head;
    }

    //  保存する入力値
    printf("\nデータを入力 --> ");
    scanf("%d", &val);

    //  新しいノードに参加してヘッドを更新する
    new_node->data = val;
    new_node->next = head;
    head = new_node;

    return head;
}

nd* l_ins(nd *head)
{
    int val;                                    //  データ値を保存するには
    nd *temp = head;                            //  最後のノードに到達するための一時ポインタ
    nd *new_node = (nd *)malloc(sizeof(nd));    //  新しいノードの割り当て

    //  メモリが割り当てられているかどうかを確認する
    if (new_node == NULL)
    {
        //  メモリが割り当てられていない場合
        printf("\nごめん ! メモリが割り当てられていません\n");
        return head;
    }

    printf("\nデータを入力 --> ");
    scanf("%d", &val);

    //  ノードが存在しないことを確認する
    if (head == NULL)
    {
        //  ヘッド情報を使用して新しいノードを更新する
        new_node->data = val;
        new_node->next = head;
        head = new_node;

        return head;
    }
    //  ノードがすでに存在する場合
    else
    {
        //  最後のノードへのトラバース
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        //  一時情報を利用した新しいノードの更新
        new_node->data = val;
        temp->next = new_node;
        new_node->next = NULL;
    }

    return head;
}

nd* c_ins(nd *head, int node_count)
{
    int i,val,indx;                             //  反復するには、値とインデックスを保存します
    nd *exc = head;                             //  一時ノードとアドレスを交換するには
    nd *temp = head->next;                      //  特定のノードに移動するには
    nd *new_node = (nd *)malloc(sizeof(nd));    //  挿入する新しいノード

    //  ノードを挿入するための入力インデックス
    printf("\n ノードを挿入する場所を入力してください --> ");
    scanf("%d", &indx);

    //  -ve インデックス条件の確認
    if (indx<=0)
    {
        printf("\n無効なインデックスです! [範囲外]\n");
        return head;
    }

    //  最初のノードの状態を確認する
    if (indx == 1)
    {
            //  インデックス 1 にノードを挿入する関数
            head = f_ins(head);
    }

    //  インデックスが最後のノードであるかどうかを確認する
    if (indx == (node_count+1))
    {
        head = l_ins(head);
        return head;
    }

    //  インデックスがノードを超えているかどうかを確認する
    if (indx > node_count)
    {
        printf("\n無効なインデックスです! [範囲外]\n");
        return head;
    }

    //  間にノードを挿入する
    else
    {
        printf("\nデータを入力 --> ");
        scanf("%d", &val);

        for (i=1; i<indx-1; i++)
        {
            //  指定したノードへのトラバース
            temp = temp->next;
            exc = exc->next;
        }

        //  ノードのアドレスを更新中
        new_node->data = val;
        new_node->next = exc->next;
        exc->next = new_node;
    }

    return head;
}

nd* f_del(nd *head)
{
    //  リストが空かどうかを確認する
    if (head == NULL)
    {
        printf("\nリンクされたリストが空です !\n");
        return head;
    }

    nd *temp = head;        //  トラバースする一時ポインター

    //  次のノードでヘッドを更新し、一時を削除しています
    head = head->next;
    free(temp);

    return head;
}

nd* l_del(nd *head)
{
    //  リンクされたリストが空かどうかを確認する
    if (head == NULL)
    {
        printf("\nリンクされたリストが空です !\n");
        return head;
    }

    nd *temp = head;         //  トラバースする一時ポインター
    nd *exc = head->next;    //  Temp の次のノードを指すポインターの場合

    //  最後のノードまでの Fr のトラバース
    while (exc->next != NULL)
    {
        //  Temp と Fr を最後のノードに更新する
        temp = temp->next;
        exc = exc->next;
    }

    //  最後から 2 番目のノードに NULL を割り当て、最後のノードを削除する
    temp->next = NULL;
    free(exc);

    return head;
}

nd* c_del(nd *head, int node_count)
{
    int i, indx;    //  インデックスを反復して保存するには

    //  リンクされたリストが空かどうかを確認する
    if (head == NULL)
    {
        printf("\nリンクされたリストが空です !\n");
        return head;
    }

    nd *exc = head;
    nd *temp = head->next;

    printf("\n削除する ノード? --> ");      //  削除する入力ノード
    scanf("%d", &indx);                  //  入力を変数に保存

    //  インデックスがゼロの場合
    if (indx<=0)
    {
        printf("\n無効なインデックスです! [そのようなノードはありません]\n");
        return head;
    }

    //  インデックスが 1 の場合
    else if (indx == 1)
    {
        head = f_del(head);     //  最初のノードを削除する関数
    }

    //  インデックスが最後のノードを超える場合
    else if (indx > node_count)
    {
        printf("\n無効なインデックスです! [ノードが存在しません]\n");
        return head;
    }

    //  インデックスが範囲外の場合
    else if (temp == NULL || temp->next == NULL)
    {
        printf("\n無効なインデックスです! [範囲外]\n");
        return head;
    }

    else
    {
        for (i=1; i<indx-1; i++)
        {
            //  特定のインデックスへのトラバース
            temp = temp->next;
            exc = exc->next;
        }

        //  ノードアドレスの更新とノードの削除
        exc->next = temp->next;
        free(temp);
    }

    return head;
}

nd* rev(nd *head)
{
    //  リストが空かどうかを確認する
    if (head == NULL)
    {
        printf("\n逆にできる ノードはありません !\n");
        return head;
    }
    //  交換する異なるノードをポイントするには
    nd *prev,*curr,*nxt;
    prev=NULL;              
    curr=nxt=head;

    while(nxt!=NULL)
    {
            //  リストをたどる
            nxt=nxt->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
    }

    //  ヘッドの割り当て
    head=prev;

    printf("\nリンクされたリストが正常に反転されました。\n");
    return head;
}

void f_view(nd *head)
{
    //  リンクされたリストが空かどうかを確認する
    if (head == NULL)
    {
        printf("\nリンクされたリストが空です !\n");
        return;
    }

    while (head != NULL)
    {
        //  リンクされたリストの走査とデータの印刷
        printf("\nデータ --> %d", head->data);
        head = head->next;  //  次のノードへの移動
    }

    printf("\n");
}

void c_view(nd *head, int node_count)
{
    int i, indx;        //  インデックスを反復して保存するには
    nd *temp = head;    //  特定のノードに移動するには

    //  リンクされたリストが空かどうかを確認する
    if (head == NULL)
    {
        printf("\nリンクされたリストが空です !\n");
        return;
    }

    printf("\nインデックスを入力して ノード データを表示 --> ");
    scanf("%d", &indx);

    if (indx<=0 || indx>node_count)
    {
        printf("\n無効な ノードです !\n");
        return;
    }

    for (i=1; i<indx; i++)
    {
        //  指定したノードへのトラバース
        temp = temp->next;
    }

    //  指定したノードでのデータの印刷
    printf("\nデータ --> %d\n", temp->data);
}

void nd_cn(int node_count)
{
    //  ノード数の表示
    printf("\n ノード --> %d\n", node_count);
}