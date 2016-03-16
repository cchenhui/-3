
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

#include <fstream>
using namespace std;

struct WORD
{
	string word;
	int num;
};

vector<WORD> a;  //创建vector对象，a[]

int&value(const string&s)
{
	for(int i=0;i<a.size();i++)
		if(s==a[i].word)
			return a[i].num;
		WORD p;
		p.word=s;
		p.num=0;
		a.push_back(p);  //在数组a最后添加数据
		return a[a.size()-1].num;
}

int main()
{
	string str;
    cout << "输入字符串：\n";
    char c;
    while(c=cin.get())
	{
        if(c>='a' && c<='z' || c>='A' && c<='Z' || c==' ' || c=='\n')  
            str+=c;   //去除符号
        if(c=='\n')
            break;
    }
//输出去掉非英文字符的字符串
	
	
	for(int j=0;str[j]!='\0';j++)
	{
		if(str[j]>='A'&&str[j]<='Z')
		{
			str[j]+= 32;  //大写字母Ascll码+32转换为小写
		}
	}
 //输出转换为小写的字符串

	string buf;
	ofstream fout("D:\123.txt");  //把转换好的字符串写入文件
	fout<<str;
	fout.close ();
	ifstream fin("D:\123.txt");  //读出写入的字符串并排序
	while(fin>>buf)
	value(buf)++;
	vector<WORD>::const_iterator p;  //迭代器访问元素
	for(p=a.begin();p!=a.end();++p)
		cout<<p->word<<":"<<p->num<<'\n';	
	return 0;
}
