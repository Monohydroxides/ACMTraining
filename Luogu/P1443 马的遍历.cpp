#include <stdio.h>
int book[410][410],matrix[410][410];
int move[8][2] = {{2,1},{2,-1},{1,-2},{1,2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
struct node
{
	int x;
	int y;
	int step;
}dlc[160010];
int main()
{
	int i,j,n,m,startx,starty,head,tail,nx,ny,k;
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	head = 1;
	tail = 1;
	dlc[head].x = startx;
	dlc[head].y = starty;
	dlc[head].step = 0;
	tail++;
	book[startx][starty] = 1;
	while(head < tail)
	{
		for(k = 0;k < 8;k++)
		{
			nx = dlc[head].x + move[k][0];
			ny = dlc[head].y + move[k][1];
			if(nx < 1 || ny < 1 || nx > n || ny > m)
			{
				continue;
			}
			if(book[nx][ny] == 0)
			{
				book[nx][ny] = 1;
				dlc[tail].x = nx;
				dlc[tail].y = ny;
				dlc[tail].step = dlc[head].step + 1;
				matrix[nx][ny] = dlc[tail].step;
				tail++;
			}
		}
		head++;
	}
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= m;j++)
		{
			if((i != startx || j != starty) && matrix[i][j] == 0)
			{
				printf("%-5d",-1);
			}
			else
			{
				printf("%-5d",matrix[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}