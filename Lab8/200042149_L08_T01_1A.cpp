#include<bits/stdc++.h>

using namespace std;

class Trie {
public:
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];
    Trie() {
        memset(trie,0,sizeof(trie));
        memset(endmark,0,sizeof(endmark));
        memset(pre,0,sizeof(pre));
    }
   
    void insert(string word) {
        int row = 1;
        for(int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if(trie[row][ch] == 0)
            {
                trie[row][ch] = ++id;
            }
            row = trie[row][ch];
            pre[row]++;
        }
        endmark[row] = 1;
       cout<<"Word added"<<endl;
    }
   
    bool search(string word) {
        int row = 1;
        for(int i = 0; i < word.size();i++)
        {
            bool check = false;
            if(word[i] == '.')
            {
                for(int j=0; j<26; j++)
                {
                    if(trie[row][j] != 0)
                    {
                        check = true;
                        row = trie[row][j];
                        break;
                    }
                }

                if(!check) return false;
            }
            else
            {
                int ch = word[i] - 'a';
                if(trie[row][ch] == 0) return false;
                row = trie[row][ch];
            }
        }
        return (endmark[row] == 1);
    }
   
    bool startsWith(string prefix) {
        int row = 1;
        for(int i = 0; i < prefix.size();i++)
        {
            int ch = prefix[i] - 'a';
            if(trie[row][ch] == 0) return false;
            row = trie[row][ch];

        }
        return (pre[row] >= 1);
    }
};

class WordDictionary
{
public:
    Trie* trie;
    WordDictionary()
    {
        trie = new Trie();
    }

    void AddWord(string word)
    {
        trie->insert(word);
    }

    bool Search(string word)
    {
        return trie->search(word);
    }
};

int main()
{
    cout<<"1.Add word"<<endl;
    cout<<"2.Search"<<endl;

    int in;
    WordDictionary wd;

    while(1)
    {
        cin>>in;
        if(in == 1)
        {
            string s;
            cin>>s;
            wd.AddWord(s);
        }
        if(in == 2)
        {
            string s;
            cin>>s;
            if(wd.Search(s)) cout<<"Word Found"<<endl;
            else cout<<"Word Not Found"<<endl;
        }
    }
    return 0;
}