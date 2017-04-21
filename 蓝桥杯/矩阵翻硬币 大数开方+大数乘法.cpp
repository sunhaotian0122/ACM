#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

string stringMultiply(string str1,string str2) //字符串相乘
{
    int len1 = str1.length();
    int len2 = str2.length();
    int i,j,num[500]={0};  //num[]储存开方数，对于数据最大也只是10^1000，所以其开方数位数最多500位
    string ans = "";
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            num[len1-i-1 + len2-j-1] += (str1[i]-'0')*(str2[j]-'0');
            //因为字符串的最低位是数的最高位
            //len1和len2位数相乘其结果是len1+len2-1到len1+len2位数之间，而num[]从0开始，所以最高位是len1+len2-2或len1+len2-1
        }
    }
    for(i=0;i<len1+len2;i++)
    {
        //之前只是每位相加，现在实现进位
        num[i+1] += num[i]/10;
        num[i] %= 10;
    }
    for(i=len1+len2-1;i>=0;i--)
    {
        if(num[i]!=0) break; //找到最高位
    }
    for(j=i;j>=0;j--) ans += (num[j]+'0');
    return ans;
}

int stringCompare(string str1,string str2,int x) //大数比较，str1后加x个0后与str2比
{
    int len1 = str1.length();
    int len2 = str2.length();
    if(len1+x<len2) return 0;
    if(len1+x>len2) return 1;
    for(int i=0;i<len1;i++)
    {
        if(str1[i]>str2[i]) return 1;
        if(str1[i]<str2[i]) return 0;
    }
    return 0;
}

string stringSqrt(string str)  //大数开方
{
    int len = str.length();
    string ans="";
    string tmp="";
    if(len&1)
    {
        for(int i=0;i<len/2+1;i++)
        {
            for(int j=0;j<10;j++)
            {
                tmp = ans;
                tmp += (j+'0');
                if(stringCompare(stringMultiply(tmp,tmp),str,2*(len/2-i))) //tmp后少了len/2-i个零，平方后少了2*（len/2-i）个零
                {
                    ans += (j-1+'0');
                    break;
                }
                if(j==9)
                {
                    ans += '9';
                    break;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<len/2;i++)
        {
            for(int j=0;j<10;j++)
            {
                tmp = ans;
                tmp += (j+'0');
                if(stringCompare(stringMultiply(tmp,tmp),str,2*(len/2-i-1))) //tmp少了len/2-i-1个零，tmp平方后少了2*（len/2-i-1）个零
                {
                    ans += (j-1+'0');
                    break;
                }
                if(j==9)
                {
                    ans += '9';
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<stringMultiply(stringSqrt(str1),stringSqrt(str2))<<endl;
    return 0;
}
