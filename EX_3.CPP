#include <iostream>
#include <string>
using namespace std;

struct Word   /* ���ʶ��� */
{
	Word() : Str( "" ), Count( 0 )
	{
	}
	string	Str;
	int	Count;
};


void CalcCount( Word *words, string &content, int size )        /* ͳ�ƴ�Ƶ */
{
	int i;                                                  /* words���� content���� size���� */
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
	cout << "����һ��Ӣ��:";
	getline( cin, content );
	while ( cin.get( ch ) ) /* ������Сд��ĸ���ɴ�д��ĸ */
	{
		ch = cin.get(); /* �˲��ִ��ɣ��������������⣬��һ�����޷�ʵ�� */
		if ( 97 <= ch && ch <= 122 )
		{
			char (ch) = char(ch - 32);
			break;
		}
	}

	int wCount = 1;                 /* ���㵥������ */
	if ( content.length() < 4 )     /* ����С��4�ĵ���ɾ�� */
	{
		wCount--;
		content.erase( 0, offset + 1 );
		offset = content.find( ' ' );
		continue;
	}
	for ( unsigned int i = 0; i < content.length(); i++ )
	{
		if ( content[i] == ' ' || content[i] == '\t' || content[i] == '\n' || content[i] == '.' || content[i] == ',' )
			wCount++;                                                       /* �ָ�����Ϊ' '��'\t'��'\n'��','��'.'���� */
	}
	words = new Word[wCount];

	string::size_type offset = content.find( ' ' || '\t' || '\n' || '.' || ',' );   /* �����Էָ������� */
	while ( offset != string::npos )
	{
		string wStr = content.substr( 0, offset );
		content.erase( 0, offset + 1 );
		CalcCount( words, wStr, wCount );
		offset = content.find( ' ' || '\t' || '\n' || '.' || ',' );
	}
	CalcCount( words, content, wCount );

	for ( int j = 0; j < wCount; j++ ) /* ��������� */
	{
		cout << words[j].Str << ":" << words[j].Count << endl;
	}
	delete[] words;
	return(0);
}

