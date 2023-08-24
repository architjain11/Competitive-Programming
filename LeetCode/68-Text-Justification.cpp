class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans, line;
        int len=0, i=0;

        while(i<words.size()) {
            if(len+line.size()+words[i].size()>maxWidth) {
                int extra_space=maxWidth-len,
                    spaces=extra_space/max(1, (int)line.size()-1),
                    remainder=extra_space%max(1, (int)line.size()-1);

                for(int j=0; j<max(1, (int)line.size()-1); ++j) {
                    for(int k=0; k<spaces; ++k) line[j]+=" ";
                    if(remainder) {
                        line[j]+=" ";
                        remainder--;
                    }
                }

                string tmp=accumulate(line.begin(), line.end(), string());
                ans.push_back(tmp);
                line.clear(); len=0;
            }
            line.push_back(words[i]);
            len+=words[i].size();
            i++;
        }

        string lastLine;
        for(int i=0; i<line.size()-1; ++i) lastLine+=(line[i]+" ");
        lastLine+=line[line.size()-1];
        int trailSpace=maxWidth-lastLine.length();
        while(trailSpace--) lastLine+=" ";
        ans.push_back(lastLine);

        return ans;
    }
};