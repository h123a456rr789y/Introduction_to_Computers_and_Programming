#include<stdio.h>
#include<string.h>

int main()
{
    char str[6][100]= {""};
    char tmp[100];
    int n;

    printf("Choose function: 1.assign 2.clear 3.copy 4.cat(concatenate) 5.show 6.cmp(compare)\n");
    while(1)
    {
        while(scanf("%s",tmp))
        {

            if(!strcmp(tmp,"assign"))
            {
                scanf("%s",tmp);
                char *pch;
                if(pch=strstr(tmp,"str"))
                {
                    if(strlen(pch)==4 && (pch[3]-'0')<6)
                    {
                        if(strlen(str[pch[3]-'0'])==0)
                        {
                            scanf("%s",str[pch[3]-'0']);
                        }
                        else
                        {
                            printf("str%d has already been assign!\n",(pch[3]-'0'));
                        }
                    }
                    else
                    {
                        printf("invalid\n");
                    }
                }
                break;
            }
            else if(!strcmp(tmp,"clear"))
            {
                scanf("%s",tmp);
                char *pch;
                if(pch=strstr(tmp,"str"))
                {
                    if(strlen(pch)==4 && (pch[3]-'0')<6)
                    {
                        if(strlen(str[pch[3]-'0'])>0)
                        {
                            strcpy(str[pch[3]-'0'],"");
                        }
                        else
                        {
                            printf("Cannot clear an empty string!\n");
                        }
                    }
                    else
                    {
                        printf("invalid\n");
                    }


                }
                break;
            }
            else if(!strcmp(tmp,"copy"))
            {
                scanf("%s",tmp);
                char *pch;
                if(pch=strstr(tmp,"str"))
                {
                    if(strlen(pch)==4 && (pch[3]-'0')<6)
                    {
                        int p1=pch[3]-'0';
                        scanf("%s",tmp);
                        if(pch=strstr(tmp,"str"))
                        {
                            if(strlen(pch)==4 && (pch[3]-'0')<6)
                            {
                                int p2=pch[3]-'0';
                                if(strlen(str[p2])>0)
                                {
                                    strcpy(str[p1],str[p2]);
                                }
                                else
                                {
                                    printf("Cannot copy from an empty string!\n");
                                }
                            }
                            else
                            {
                                printf("invalid\n");
                            }
                        }
                        else
                        {
                            strcpy(str[p1],tmp);
                        }
                    }
                    else
                    {
                        printf("invalid\n");
                    }

                }
                break;
            }
            else if(!strcmp(tmp,"cat") || !strcmp(tmp,"concatenate"))
            {
                scanf("%s",tmp);
                char *pch;
                if(pch=strstr(tmp,"str"))
                {
                    if(strlen(pch)==4 && (pch[3]-'0')<6)
                    {
                        int p1=pch[3]-'0';
                        scanf("%s",tmp);
                        if(pch=strstr(tmp,"str"))
                        {
                            if(strlen(pch)==4 && (pch[3]-'0')<6)
                            {
                                int p2=pch[3]-'0';
                                if(strlen(str[p2])>0)
                                {
                                    strcat(str[p1],str[p2]);
                                }
                                else
                                {
                                    printf("Cannot concatenate from an empty string!\n");
                                }
                            }
                            else
                            {
                                printf("invalid\n");
                            }
                        }
                        else
                        {
                            strcat(str[p1],tmp);
                        }
                    }
                    else
                    {
                        printf("invalid\n");
                    }
                }
                break;
            }
            else if(!strcmp(tmp,"cmp") || !strcmp(tmp,"compare"))
            {
                scanf("%s",tmp);
                char *pch;
                if(pch=strstr(tmp,"str"))
                {
                    if(strlen(pch)==4 && (pch[3]-'0')<6)
                    {
                        int p1=pch[3]-'0';
                        scanf("%s",tmp);
                        if(pch=strstr(tmp,"str"))
                        {
                            if(strlen(pch)==4 && (pch[3]-'0')<6)
                            {
                                int p2=pch[3]-'0';
                                int ans=strcmp(str[p1],str[p2]);
                                if(ans==0)
                                {
                                    printf("the same\n");
                                }
                                else
                                {
                                    printf("not the same\n");
                                }
                            }
                            else
                            {
                                printf("invalid\n");
                            }
                        }
                        else
                        {
                            int ans=strcmp(str[p1],tmp);
                            if(ans==0)
                            {
                                printf("the same\n");
                            }
                            else
                            {
                                printf("not the same\n");
                            }
                        }
                    }
                    else
                    {
                        printf("invalid\n");
                    }
                }
                break;
            }

            else if(!strcmp(tmp,"show"))
            {
                int i,flag=0;
                for(i=0; i<6; i++)
                {
                    if(strlen(str[i])>0)
                    {
                        flag=1;
                        printf("str%d:%s\n",i,str[i]);
                    }
                }
                if(flag==0)
                {
                    printf("Nothing to show\n");
                }
                break;
            }
            else
            {

                break;
            }

        }
    }

    return 0;
}
