#include <bits/stdc++.h>

using namespace std;


// Defining structure 
struct trie
{
    bool isword;
    trie *next[26];
    trie()
    {
        isword = false;
        for (int i = 0l; i < 26;i++)
            next[i] = NULL;
    }
};

void insert(string str,trie* rt)
{
    trie* root = rt;
    for (int i = 0; i < str.size();i++)
    {
        if(root->next[str[i]-'a']==NULL)
            root->next[str[i] - 'a'] = new trie();

        root = root->next[str[i] - 'a'];
    }
    root->isword = true;
}

bool search(string str, trie* rt)
{
    trie* root = rt;
    for (int i = 0; i < str.size();i++)
    {
        if(root->next[str[i]-'a'] == NULL)
            return false;
        else
            root = root->next[str[i] - 'a'];
    }
    return root->isword;
}

void del(string str,trie* rt)
{
    trie* root = rt;
    stack<trie *> st;
    for (int i = 0; i < str.size();i++)
    {
        if(root->next[str[i]-'a']==NULL)
            return;
        else
        {
            st.push(root);
        }
        root = root->next[str[i] - 'a'];
    }
    root->isword = false;
    for (int i = 0; i < 26;i++)
    {
        if(root->next[i]!=NULL)
        {
            root->isword = false;
            return;
        }
    }
    root = st.top();
    delete (root);
    st.pop();
    for (int i = 0; i < st.size();i++)
    {
        root = st.top();
        if(root->isword==false)
        {
            delete (st.top());
            st.pop();
        }
        else
            return;
    }
}

int main()
{
    trie *root = new trie();
    string str;
    int ch,c;
    do
    {
        cout << "\n1. Insert\n2. Search\n3. Delete\n";
        cin >> ch;
        cout << "Enter String: ";
        cin >> str;
        switch(ch)
        {
            case 1:
                insert(str, root);
                break;
            case 2: if(search(str,root))
                        cout << "Present\n";
                    else
                        cout << "Not Present\n";
                    break;
            case 3:
                del(str, root);
                cout << "String Deleted\n";
                break;
            default:
                cout << "Wrong Input- Exiting";
                break;
        }
        cout << "Enter 1 to continue and 0 to exit: ";
        cin >> c;
    } while (c == 1);
    return 0;
}