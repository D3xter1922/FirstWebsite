#include<stdio.h>
#include<math.h>
int situation(char grid[][3])
{
    int count_x=0,count_o=0,winx_count=0,wino_count=0;
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grid[i][j]=='X')
            {
                count_x++;
            }
            else if(grid[i][j]=='O')
            {
                count_o++;
            }

        }
    }
    for(int i=0;i<3;i++)//determines if there are any matches for x or o
    {
        if(grid[i][0]=='X'&&grid[i][1]=='X'&&grid[i][2]=='X')
        {
            winx_count++;
        }
        if(grid[0][i]=='X'&&grid[1][i]=='X'&&grid[2][i]=='X')
        {
            winx_count++;
        }
        if(grid[i][0]=='O'&&grid[i][1]=='O'&&grid[i][2]=='O')
        {
            wino_count++;
        }
        if(grid[0][i]=='O'&&grid[1][i]=='O'&&grid[2][i]=='O')
        {
            wino_count++;
        }
    }
    if(grid[0][0]=='X'&&grid[1][1]=='X'&&grid[2][2]=='X')
    {
        winx_count++;
    }
    if(grid[2][0]=='X'&&grid[1][1]=='X'&&grid[0][2]=='X')
    {
        winx_count++;
    }
    if(grid[0][0]=='O'&&grid[1][1]=='O'&&grid[2][2]=='O')
    {
        wino_count++;
    }
    if(grid[2][0]=='O'&&grid[1][1]=='O'&&grid[0][2]=='O')
    {
        wino_count++;
    }
    /*now we use these calculated parameters to label the situation
      1) game_drawn-->abs(count_x-count_o)<2 && (count_x+count_o)==9 && win_x==0 && win_o==0
         we_have_a_winner-->abs(count_x-count_o)<2 && ((win_x==0 && win_o==1)||(win_x==1 && win_o==0))

      2) abs(count_x-count_O)<2 && win_x==0 && win_o==0 && (count_x+count_o)<=8

      3) abs(count_x-count_o)>=2 || (win_x==1 && win_o==1)
    */
    if(abs(count_x-count_o)<2 && (count_x+count_o)==9 && winx_count==0 && wino_count==0)
    {
        return 1;
    }
    if(abs(count_x-count_o)<2 && ((winx_count==0 && wino_count>=1)||(winx_count>=1 && wino_count==0)))
    {
        return 1;
    }
    if(abs(count_x-count_o)<2 && winx_count==0 && wino_count==0 && (count_x+count_o)<=8)
    {
        return 2;
    }
    else return 3;

}
int main()
{
    int T;
    scanf("%d",&T);
    char grid[3][3],row_1[10],row_2[10],row_3[10];
    for(int i=0;i<T;i++)
    {
        scanf("%s",row_1);
        scanf("%s",row_2);
        scanf("%s",row_3);

        for(int i=0;i<3;i++)
        {
            grid[0][i]=row_1[i];
        }
        for(int i=0;i<3;i++)
        {
            grid[1][i]=row_2[i];
        }
        for(int i=0;i<3;i++)
        {
            grid[2][i]=row_3[i];
        }
        printf("%d\n",situation(grid));
        
    }

    return 0;
}