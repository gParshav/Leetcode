class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<vector<string>> q;

        q.push({beginWord});

        vector<vector<string>> ans;
        int level = 0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        while(!q.empty()){
            vector<string> temp = q.front();
            q.pop();

            if(temp.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
            }

            string word = temp.back();
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(temp);
                }

                else if(ans[0].size() == temp.size()){
                    ans.push_back(temp);
                }
            }

            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.count(word)>0){
                        cout<<word<<endl;
                        temp.push_back(word);

                        q.push(temp);
                        usedOnLevel.push_back(word);

                        temp.pop_back();
                    }
                }

                word[i] = original;
            }
        }


        return ans;

        
    }
};