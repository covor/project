#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int compare(char sum1,char sum2)//�����Ƚ�ׯ�Һ�������յ�����С 
{
 if(sum1>=sum2)
  return 1;
 else
  return 0;
 
}
int breakal(int sum)//�ж��Ƿ��� 
{
 if(sum>21)
  return 0;
 else
  return 1;
}
char change(int card)//�����ɵ������11,12,13����J,Q,K 
{
 char ch;
    switch(card)
 {
 case 1: ch='A';
  break;
 case 11:
  ch='J';
  case 12:
  ch='Q';
  case 13:
  	ch='K'; 
 } 
 return ch;
}
void game()//��Ϸ���ݲ��� 
{
 int i,k,n;
 char host_ch,player_ch,host_card[15],player_card[15];
 int host_sum=0,player_sum=0;
 srand(time(NULL));
 for(i=0;i<2;i++)//��ҳ�ǰ������ 
 {
  int (rand()%13+1);
  player_card[i]=int (rand()%13+1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  player_ch=change(player_card[i]);
  if(player_card[i]>1 && player_card[i]<=10)   //��ҵ���Ϊ2-10����� 
       printf("���鵽�ĵ�%d������%d\n",i+1,player_card[i]);
  else if(player_card[i]>10)//��ҵ��ƴ���10����� 
      {
       printf("��Ҫ���ĵ�%d������%c\n",i+1,player_ch);
       player_card[i]=10;
       }
  else
       printf("��Ҫ���ĵ�%d������A\n",i+1);
  if(player_ch=='A')//��ҵ���ΪA����� 
        player_card[i]=11;

  host_card[i]=int (rand()%13+1);//ׯ�ҳ�������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    if(host_card[i]>10)//ׯ�ҵ��ƴ���10����� 
       host_card[i]=10;
  else if(host_card[i]==1)//ׯ�ҵ���ΪA����� 
      host_card[i]=11;
    
     player_sum+=player_card[i];  //�ֱ��ׯ�Һ���ҵĵ������
  host_sum+=host_card[i];
 }
 printf("�����ڵ�����ֵΪ%d\n",player_sum);//�����ҵ�����ֵ
 
 
 for(i=2;i<5;i++)//���Ƶ��������Ϊ5�ţ��ٶ��ѵģ���֪��׼��׼�� 
 {
  if(host_sum<=17 && host_sum>0)//�����Զ��ж�ׯ���Ƿ�Ҫ�ƣ�С�ڵ���17�Ļ���Ҫ�� 
  {
   host_card[i]=int (rand()%13+1);
   host_ch=change(host_card[i]);
   if(host_ch=='A')  
     host_card[i]=11;
    else if(host_card[i]>10)
    host_card[i]=10;
   host_sum+=host_card[i];
  }
  printf("����Ҫ����Ҫ����\n");//ѯ���Ƿ����Ҫ�� 
  printf(" 1.Ҫ\n");
  printf(" 2.��Ҫ\n");
  scanf("%d",&k);
  if(k==1)
  {
   {
   player_card[i]=int (rand()%13+1);
   player_ch=change(player_card[i]);
   if(player_ch=='A')
     player_card[i]=11;
   
   else if(player_card[i]>10)
   player_card[i]=10;
    printf("��Ҫ���ĵ�%d������%d\n",i+1,player_card[i]);
   player_sum+=player_card[i];
   if(i==4)
   printf("�����е����Ѵﵽ���ޣ�\n");
   if(breakal(host_sum)==0)
   {
    if(breakal(player_sum)==0)
    {
     printf("ׯ�ұ����ˣ���Ҳ�����ˣ�ׯ�ҵ�����ֵ��%d,��������ֵ��%d\n",host_sum,player_sum);
     printf("\n�����ˡ�����\n");
     break;
    }
   }
   else
    if(breakal(player_sum)==0)
    {
     printf("�������ˣ�ׯ�ҵ�����ֵ��%d ��������ֵ��%d\n \n�����ˡ�����\n",host_sum,player_sum);
     break;
    }
  }
  if(breakal(host_sum)==0)
  {
   printf("ׯ�ұ����ˣ�ׯ�ҵ�����ֵ��%d����������ֵ��%d\n",host_sum,player_sum);
   printf("\n��ϲ������Ӯ�ˣ�\n");
   break;
  }
 }
  else
  {
  	if(breakal(host_sum)==0)//ׯ�ұ�����
	  { if(breakal(player_sum)==0) //���Ҳ������
	  {printf("ׯ�ұ����ˣ���Ҳ�����ˣ�ׯ�ҵĵ�����%d�����ĵ�����%d �������ˡ�����\n",host_sum,player_sum);
	  break; }
	   else if(breakal(player_sum)==1)//���û�б���
	  {printf("ׯ�ұ����ˣ�ׯ�ҵĵ�����%d�����ĵ�����%d����ϲ������Ӯ�ˣ�����\n",host_sum,player_sum) ;
	  break;} 
      }
      else if (breakal(host_sum)==1)//ׯ��û�б���
      {if(breakal(player_sum)==0)//��ұ�����
	  {printf("�������ˣ�ׯ�ҵĵ�����%d�����ĵ�����%d�������ˡ�����\n",host_sum,player_sum);
	  break; }
	  else if (breakal(player_sum)==1)//���û�б���
	  {if(compare(host_sum,player_sum)==1)
	  printf("ׯ�ҵĵ�����%d�����ĵ�����%d�������ˡ�����\n",host_sum,player_sum);
	  else
	  printf("ׯ�ҵĵ�����%d�����ĵ�����%d����ϲ������Ӯ�ˣ���\n");
	  break; 
	   } 
      }
}	   
}
}
int main()
{
kaishi:
 int n;
 printf("                 ��ӭ����21����Ϸ��\n");
 printf("        ************************************\n");
 printf("                   1.��ʼ��Ϸ\n");
 printf("                   2.�˳���Ϸ\n");
    printf("        ************************************\n");
 if(scanf("%d",&n)&&n==1)
  game();
 else if(n==2)
 {
  printf("      ******************************\n");
  printf("            ��Ϸ������ף����죡\n");
  printf("\n\n");
  printf("                   �ټ�!\n");
  printf("      ******************************\n");
  return 0;
 }
goto kaishi;
}
