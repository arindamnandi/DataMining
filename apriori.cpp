#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
string find_union(string s1,string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	int i = 0;
	int j = 0;
	int s[30] = {0};
	
	for (i = 0; i < l1; i++) {
		s[s1[i] - 'a']++;
	}
	
	for (i = 0; i < l2; i++) {
		s[s2[i] - 'a']++;
	}
	
	string str = "";
	
	for (i = 0; i < 30 ; i++) {
		char ch = i + 'a';
		if(s[i])
		str += ch;
	}
	
	return str;
}
int is_subsequence(string s1,string str)
{
	int l1 = s1.length();
	int l2 = str.length();
	int i = 0;
	int j = 0;
	
	while(i<l1 && j < l2)
	{
		if(s1[i] == str[j])
			i++;
		
		j++;
	}
	if(i == l1)
		return 1;
	else 
		return 0;
}
string item_name[30];
int main()
{
	FILE * fp,*fptr;
	fp = fopen("FILE2.txt","r");
	
	fptr = fopen("Output1.txt","w+");
	
	//fptr = fopen("program.txt", "w");
	
	char ch;
	string data[100];
	int i=0,j=0,k=0;
	string actual_string[30];
	int x = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == ',')
		{
			continue;
		}
		if(k==1)
		{
			
			string s = "";
			s += ch;
			while((ch = fgetc(fp)) != '\n')
			{
				cout<<ch;
				
				if(ch == ','){
					item_name[x] = s;
					x++;
					s = "";
				}
				else s += ch;
			}
			item_name[x] = s;
			k++;
		}
		else if(k<2)
		{
			if(ch == '\n')
			k++;
		}
		else
		{
			if(ch == '\n') {
				i++;
				j=0;
			}
			else { 
				if (ch != '0') {
					data[i] += 'a' + j;
				}
				
				j++;
				
			}
		}
	}
	int min_sup = 10;
	
//	for(i=0;i<24;i++)
//	cout<<data[i]<<endl;

	map<string,int> hd1;
	int s[30] = {0};

	for (i = 0; i < 24; i++) {
		int l = data[i].length();
		for (j = 0; j < l; j++)
			s[data[i][j] - 'a']++;
	}

	for(i=0;i<30;i++)
	{
		ch = i+'a';
		string s1 ="";
		s1 += ch;
		hd1[s1] = s[i];
	}

	map<string,int> :: iterator it;

	for(it = hd1.begin(); it != hd1.end(); it++)
	{
		string st = it->first;
		fprintf(fptr,"%s ", st.c_str());
		fprintf(fptr,"%d", it->second);
		char c = '\n';
		fprintf(fptr,"%c",c);
		//cout<<it->first<<" "<<it->second<<endl;
	}
		char c = '\n';
		fprintf(fptr,"%c",c);
		fprintf(fptr,"%c",c);
		vector<string> v;
	for(it = hd1.begin(); it != hd1.end(); it++)
	{
		if(it->second < min_sup)
		v.push_back(it->first);
	}
	for(i=0;i<(v.size());i++)
	{
		hd1.erase(v[i]);
	}
	for(it = hd1.begin(); it != hd1.end(); it++)
	{
		fprintf(fptr,"%s ", (it->first).c_str());
		fprintf(fptr,"%d", it->second);
		char c = '\n';
		fprintf(fptr,"%c",c);
		//cout<<it->first<<" "<<it->second<<endl;
	}
	
		char h = '\n';
		fprintf(fptr,"%c",h);
		fprintf(fptr,"%c",h);
	
	int p=1;
	while(1)
	{
		p++;
		map<string,int> hd2;
		map<string,int> :: iterator it1;
		map<string,int> :: iterator it2;
		for(it1 = hd1.begin(); it1 != hd1.end(); it1++)
		{
			for(it2 = it1; it2 != hd1.end(); it2++)
			{
				if(it1 == it2)
				continue;
				string s = find_union(it1->first,it2->first);
				if(s.length() == p)
				{
					hd2[s] = 0;
				}	
					
			}
		}
		for(it1 = hd2.begin(); it1 != hd2.end(); it1++)
		{
			for(i=0;i<100;i++)
			{
				(it1->second) += is_subsequence(it1->first,data[i]);
				
			} 
		}
		for(it1 = hd2.begin();it1!= hd2.end(); it1++)
		{
			fprintf(fptr,"%s ", (it1->first).c_str());
			fprintf(fptr,"%d", it1->second);
			char c = '\n';
			fprintf(fptr,"%c",c);
		//	cout<<it1->first<<" "<<it1->second<<endl;
		}
		char c = '\n';
		fprintf(fptr,"%c",c);
		fprintf(fptr,"%c",c);
		vector<string> v;
		for(it1 = hd2.begin(); it1 != hd2.end(); it1++)
		{
			if( (it1->second) < min_sup)
			{
				v.push_back(it1->first);
			}
		}
		
		for(i = 0; i < (v.size()); i++)
		{
			hd2.erase(v[i]);
		}
		
		for(it1 = hd2.begin();it1!= hd2.end(); it1++)
		{
			fprintf(fptr,"%s ",(it1->first).c_str());
			fprintf(fptr,"%d",it1->second);
			char c = '\n';
			fprintf(fptr,"%c",c);
		//	cout<<it1->first<<" "<<it1->second<<endl;
		}
		char h = '\n';
		fprintf(fptr,"%c",h);
		fprintf(fptr,"%c",h);
		if(hd2.begin() == hd2.end())
		break;
		hd1 = hd2;
		
	}
	cout<<"END";
}
