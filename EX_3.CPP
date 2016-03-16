#include <iostream>
#include <string>
using namespace std;

struct Word   /* 单词对象 */
{
	Word() : Str( "" ), Count( 0 )
	{
	}
	string	Str;
	int	Count;
};


void CalcCount( Word *words, string &content, int size )        /* 统计词频 */
{
	int i;                                                  /* words单词 content内容 size个数 */
	for ( i = 0; i < size; i++ )
	{
		if ( words[i].Str == content )
		{
			words[i].Count++;
			return;
		}else if ( words[i].Str == "" )
			break;
	}
	words[i].Str	= content;
	words[i].Count	= 1;
}


int main()
{
	char	ch;
	Word	*words;
	string	content;
	cout << "输入一段英文:";
	getline( cin, content );
	while ( cin.get( ch ) ) /* 把所有小写字母换成大写字母 */
	{
		ch = cin.get(); /* 此部分存疑，可能是输入问题，这一部分无法实现 */
		if ( 97 <= ch && ch <= 122 )
		{
			char (ch) = char(ch - 32);
			break;
		}
	}

	int wCount = 1;                 /* 计算单词总数 */
	if ( content.length() < 4 )     /* 长度小于4的单词删除 */
	{
		wCount--;
		content.erase( 0, offset + 1 );
		offset = content.find( ' ' );
		continue;
	}
	for ( unsigned int i = 0; i < content.length(); i++ )
	{
		if ( content[i] == ' ' || content[i] == '\t' || content[i] == '\n' || content[i] == '.' || content[i] == ',' )
			wCount++;                                                       /* 分隔符分为' '，'\t'，'\n'，','，'.'五种 */
	}
	words = new Word[wCount];

	string::size_type offset = content.find( ' ' || '\t' || '\n' || '.' || ',' );   /* 单词以分隔符隔开 */
	while ( offset != string::npos )
	{
		string wStr = content.substr( 0, offset );
		content.erase( 0, offset + 1 );
		CalcCount( words, wStr, wCount );
		offset = content.find( ' ' || '\t' || '\n' || '.' || ',' );
	}
	CalcCount( words, content, wCount );

	for ( int j = 0; j < wCount; j++ ) /* 最后输出结果 */
	{
		cout << words[j].Str << ":" << words[j].Count << endl;
	}
	delete[] words;
	return(0);
}


