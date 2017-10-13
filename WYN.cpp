#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int compare(char sum1,char sum2)//用来比较庄家和玩家最终点数大小 
{
 if(sum1>=sum2)
  return 1;
 else
  return 0;
 
}
int breakal(int sum)//判定是否爆牌 
{
 if(sum>21)
  return 0;
 else
  return 1;
}
char change(int card)//将生成的随机数11,12,13换成J,Q,K 
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
void game()//游戏内容部分 
{
 int i,k,n;
 char host_ch,player_ch,host_card[15],player_card[15];
 int host_sum=0,player_sum=0;
 srand(time(NULL));
 for(i=0;i<2;i++)//玩家抽前两张牌 
 {
  int (rand()%13+1);
  player_card[i]=int (rand()%13+1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  player_ch=change(player_card[i]);
  if(player_card[i]>1 && player_card[i]<=10)   //玩家的牌为2-10的情况 
       printf("您抽到的第%d张牌是%d\n",i+1,player_card[i]);
  else if(player_card[i]>10)//玩家的牌大于10的情况 
      {
       printf("您要到的第%d张牌是%c\n",i+1,player_ch);
       player_card[i]=10;
       }
  else
       printf("您要到的第%d张牌是A\n",i+1);
  if(player_ch=='A')//玩家的牌为A的情况 
        player_card[i]=11;

  host_card[i]=int (rand()%13+1);//庄家抽两张牌                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    if(host_card[i]>10)//庄家的牌大于10的情况 
       host_card[i]=10;
  else if(host_card[i]==1)//庄家的牌为A的情况 
      host_card[i]=11;
    
     player_sum+=player_card[i];  //分别对庄家和玩家的点数求和
  host_sum+=host_card[i];
 }
 printf("您现在的总面值为%d\n",player_sum);//输出玩家的总面值
 
 
 for(i=2;i<5;i++)//抽牌的最大上限为5张（百度搜的，不知道准不准） 
 {
  if(host_sum<=17 && host_sum>0)//电脑自动判断庄家是否要牌，小于等于17的话就要牌 
  {
   host_card[i]=int (rand()%13+1);
   host_ch=change(host_card[i]);
   if(host_ch=='A')  
     host_card[i]=11;
    else if(host_card[i]>10)
    host_card[i]=10;
   host_sum+=host_card[i];
  }
  printf("您还要继续要牌吗？\n");//询问是否继续要牌 
  printf(" 1.要\n");
  printf(" 2.不要\n");
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
    printf("您要到的第%d张牌是%d\n",i+1,player_card[i]);
   player_sum+=player_card[i];
   if(i==4)
   printf("您手中的牌已达到上限！\n");
   if(breakal(host_sum)==0)
   {
    if(breakal(player_sum)==0)
    {
     printf("庄家爆牌了，您也爆牌了！庄家的牌面值是%d,您的牌面值是%d\n",host_sum,player_sum);
     printf("\n您输了。。。\n");
     break;
    }
   }
   else
    if(breakal(player_sum)==0)
    {
     printf("您爆牌了！庄家的牌面值是%d 您的牌面值是%d\n \n您输了。。。\n",host_sum,player_sum);
     break;
    }
  }
  if(breakal(host_sum)==0)
  {
   printf("庄家爆牌了！庄家的牌面值是%d，您的牌面值是%d\n",host_sum,player_sum);
   printf("\n恭喜您！您赢了！\n");
   break;
  }
 }
  else
  {
  	if(breakal(host_sum)==0)//庄家爆牌了
	  { if(breakal(player_sum)==0) //玩家也爆牌了
	  {printf("庄家爆牌了！您也爆牌了！庄家的点数是%d，您的点数是%d ，您输了。。。\n",host_sum,player_sum);
	  break; }
	   else if(breakal(player_sum)==1)//玩家没有爆牌
	  {printf("庄家爆牌了！庄家的点数是%d，您的点数是%d，恭喜您！您赢了！！！\n",host_sum,player_sum) ;
	  break;} 
      }
      else if (breakal(host_sum)==1)//庄家没有爆牌
      {if(breakal(player_sum)==0)//玩家爆牌了
	  {printf("您爆牌了！庄家的点数是%d，您的点数是%d，您输了。。。\n",host_sum,player_sum);
	  break; }
	  else if (breakal(player_sum)==1)//玩家没有爆牌
	  {if(compare(host_sum,player_sum)==1)
	  printf("庄家的点数是%d，您的点数是%d，您输了。。。\n",host_sum,player_sum);
	  else
	  printf("庄家的点数是%d，您的点数是%d，恭喜您！您赢了！！\n");
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
 printf("                 欢迎进入21点游戏！\n");
 printf("        ************************************\n");
 printf("                   1.开始游戏\n");
 printf("                   2.退出游戏\n");
    printf("        ************************************\n");
 if(scanf("%d",&n)&&n==1)
  game();
 else if(n==2)
 {
  printf("      ******************************\n");
  printf("            游戏结束！祝您愉快！\n");
  printf("\n\n");
  printf("                   再见!\n");
  printf("      ******************************\n");
  return 0;
 }
goto kaishi;
}
