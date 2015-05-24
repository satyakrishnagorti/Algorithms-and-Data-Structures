#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> SA(100001);

vector<pair<int,string> > stuff;

bool cmp(pair<int,string> a,pair<int,string> b)
{
    return a.second<b.second;
}

void generate_suffix_array(string str)
{
    for(int i=0;i<str.size();i++)
    {
        string temp;
        temp  = str.substr(i);
        stuff.push_back(make_pair(i,temp));
    }
    sort(stuff.begin(),stuff.end(),cmp);

    for(int i=0;i<str.size();i++)
    {
        SA[i]=stuff[i].first;
    }
}

int main()
{
    string input;
    cin>>input;
    generate_suffix_array(input);
    for(int i=0;i<input.size();i++)
        cout<<SA[i]<<endl;
    return 0;
}
