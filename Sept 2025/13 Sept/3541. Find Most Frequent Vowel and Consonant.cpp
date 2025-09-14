class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        int maxVowel=0,maxConsonant=0;
        for(int i=0;i<26;i++){
            if(i=='a'-'a' || i=='e'-'a' || i=='i'-'a' || i=='o'-'a' || i=='u'-'a')
                maxVowel=max(maxVowel,freq[i]);
            else
                maxConsonant=max(maxConsonant,freq[i]);
        }
        return maxVowel+maxConsonant;
    }
};
