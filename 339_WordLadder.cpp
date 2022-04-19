#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        unordered_set<string> s;
        for (auto it : wordList)
            s.insert(it);

        if (s.find(targetWord) == s.end())
            return 0;

        int depth = 0;
        queue<string> q;
        q.push(startWord);

        while (!q.empty())
        {
            depth++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string str = q.front();
                q.pop();
                if (str == targetWord)
                    return depth + 1;

                for (int j = 0; j < str.size(); j++)
                {
                    char org = str[j];
                    for (char ch = 'a'; ch < 'z'; ch++)
                    {
                        if (org != ch)
                            str[j] = ch;
                        if (str == targetWord)
                            return depth + 1;
                        if (s.find(str) != s.end())
                        {
                            q.push(str);
                            s.erase(str);
                        }
                    }
                    str[j] = org;
                }
            }
        }
        return 0;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}