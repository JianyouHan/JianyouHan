#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 编写一个函数来查找字符串数组中的最长公共前缀。
* 如果不存在公共前缀，返回空字符串 ""。
* 举例：
* 输入：strs = ["flower","flow","flight"]
* 输出："fl"
*
* 输入：strs = ["dog","racecar","car"]
*输出：""
*/
char * longestCommonPrefix(char ** strs, int strsSize){
    int i, j;
    if(strsSize == 0)
        return "";
    if(strs[0][0]<'a' ||strs[0][0]>'z')
    return "";
    char *common_prefix = (char *)malloc(200 * sizeof(char));
    if(NULL == common_prefix) return NULL;
    memset(common_prefix,0,sizeof(char)*200);

    //行列查找
    int min_line=strlen(strs[0]);
    //找出最短的一行字符数
    for(int k=0;k<strsSize;k++)
    {
        if(strlen(strs[k]) < min_line)
                min_line = strlen(strs[k]);
    }
    printf("\n min_line = %d\n",min_line);
    //循
    for(i=0; i< min_line; i++)  //按列遍历
    {
        common_prefix[i] = strs[0][i];
        for(j=0; j<strsSize; j++)//行
        {
            if(strs[j][i] != common_prefix[i])
            {
                common_prefix[i] = '\0';
                break;
            }
        }
    }
    return common_prefix;
}

int main()
{
    char *strs[3] = {"flower","flow","flight"};
    printf("the string array is:\n");
    for(int i=0; i<3;i++)
    {
        printf("%s\n",strs[i]);
    }
    char *common_prefix = (char *)malloc(200 * sizeof(char));
    common_prefix =  longestCommonPrefix(strs, 3);
    printf("the longest common prefix is:\n");
    if(common_prefix[0] == '\0')
    {
        printf("\"\"\n");
    }
    else
        printf("\"%s\"\n",common_prefix);
    return 0;
}
