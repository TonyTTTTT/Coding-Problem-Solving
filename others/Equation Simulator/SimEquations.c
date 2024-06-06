#include<stdio.h>
#include<math.h>

int main()
{
    int P,Q,R,u,v,w,i,j,k,n;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&P,&Q,&R);
        for(u=1;u>0;u++)
        {
            for(v=1;v>0;v++)
            {
                for(w=1;w>0;w++)
                {
                    (u+2*v+3*w)==P;
                    (u*v*w)==Q;
                    (pow(u,3)+pow(v,2)+pow(v,1))==R;
					printf("in loop\n");
                }
            }
        }

        printf("Case %d:u=%d,v=%d,w=%d\n",i,(int)u,(int)v,(int)w);
        i=1;
    }

    return 0;
}
