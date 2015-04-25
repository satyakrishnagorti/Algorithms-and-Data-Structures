#include <bits/stdc++.h>

using namespace std;

#define ALPHA_SIZE 26
//const int ALPHA_SIZE=26;

struct trieNode{

  trieNode *childnode[ALPHA_SIZE];
  int prefix_count;
  bool isEnd;
};

trieNode * getNode()
{
  trieNode *node = new trieNode();
  //node->childnode = vector<trieNode*> (26,NULL);
  for(int i=0;i<ALPHA_SIZE;i++)
    node->childnode[i]=NULL;
  node->prefix_count = 0;
  node->isEnd = false;
  return node;
}

void insert(string word, trieNode *root)
{
  trieNode *current = root;
  current->prefix_count++;
  for(int i=0;i<word.size() ;++i)
  {
    int letter = word[i] - 'a';
    if(current->childnode[letter]==NULL){
      current->childnode[letter] = getNode();
    }

    current = current->childnode[letter];
    current->prefix_count++;
  }
  current->isEnd=true;
}

bool search(string word,trieNode *root)
{
    trieNode *current = root;
    for(int i=0;i<word.size();i++)
    {
        int letter = word[i]-'a';
        if(current==NULL)
            return false;
        else{
            current = current->childnode[letter];
        }
    }
    return current->isEnd;
}

/**
 * returns the prefix count of string passed
 * @param  prefix string
 * @param  root   trieNode
 * @return        int
 */
int word_prefix_count(string prefix,trieNode *root)
{
    trieNode *current = root;
    for(int i=0;i<prefix.size();i++)
    {
        int letter = prefix[i]-'a';
        if(current->childnode[letter]==NULL)
            return 0;
        else
            current = current->childnode[letter];
    }
    return current->prefix_count;
}


// testing
int main()
{
    trieNode * root = getNode();
    string first = "aaa", second = "abb", third = "abc", fourth = "baa", fifth = "aaab";
    insert(first,root);
    insert(second,root);
    insert(third,root);
    insert(fourth,root);
    insert(fifth,root);

    if(search(fourth,root))
        cout<<"FOUND\n";
    else cout<<"NO\n";

    cout<<"WORD PREFIX OF 'a':"<<word_prefix_count("a",root)<<endl;
    cout<<"WORD PREFIX OF 'b':"<<word_prefix_count("b",root)<<endl;
}
