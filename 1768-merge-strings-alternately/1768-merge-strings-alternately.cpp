class Solution{
public:
    string mergeAlternately(string word1, string word2){
        int i = 0;
        int n1 = (int)word1.size(), n2 = (int)word2.size();

        string ans;
        while (i < min(n1, n2)){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }

        while (i < n1)
            ans.push_back(word1[i++]);

        while (i < n2)
            ans.push_back(word2[i++]);

        return ans;
    }
};