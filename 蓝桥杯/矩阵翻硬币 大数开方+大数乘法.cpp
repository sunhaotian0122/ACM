#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

string stringMultiply(string str1,string str2) //�ַ������
{
    int len1 = str1.length();
    int len2 = str2.length();
    int i,j,num[500]={0};  //num[]���濪�����������������Ҳֻ��10^1000�������俪����λ�����500λ
    string ans = "";
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            num[len1-i-1 + len2-j-1] += (str1[i]-'0')*(str2[j]-'0');
            //��Ϊ�ַ��������λ���������λ
            //len1��len2λ�����������len1+len2-1��len1+len2λ��֮�䣬��num[]��0��ʼ���������λ��len1+len2-2��len1+len2-1
        }
    }
    for(i=0;i<len1+len2;i++)
    {
        //֮ǰֻ��ÿλ��ӣ�����ʵ�ֽ�λ
        num[i+1] += num[i]/10;
        num[i] %= 10;
    }
    for(i=len1+len2-1;i>=0;i--)
    {
        if(num[i]!=0) break; //�ҵ����λ
    }
    for(j=i;j>=0;j--) ans += (num[j]+'0');
    return ans;
}

int stringCompare(string str1,string str2,int x) //�����Ƚϣ�str1���x��0����str2��
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

string stringSqrt(string str)  //��������
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
                if(stringCompare(stringMultiply(tmp,tmp),str,2*(len/2-i))) //tmp������len/2-i���㣬ƽ��������2*��len/2-i������
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
                if(stringCompare(stringMultiply(tmp,tmp),str,2*(len/2-i-1))) //tmp����len/2-i-1���㣬tmpƽ��������2*��len/2-i-1������
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
