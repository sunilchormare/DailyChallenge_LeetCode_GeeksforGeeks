class Solution {
public:
    // string decodeMessage(string key, string message) {
    //    unordered_map<char,char> m;
    //     int ks=key.size(),ms=message.size(),c='a';
    //     for(int i=0;i<ks;++i)
    //     {
    //         if(key[i]==' ') m[' ']=' ';
    //         if(m[key[i]]>0) continue;
    //         m[key[i]]=c;
    //         c++;
    //     }
    //     string res="";
    //     for(int i=0;i<ms;++i)
    //     {
    //         //if(message[i]==' ') res+=' ';
    //         res+=m[message[i]];
    //     }
    //     return res;
    // }
    string decodeMessage(string key, string mess) {
    char m[128] = {}, cur = 'a';
    for (char k : key)
        if (isalpha(k) && m[k] == 0)
            m[k] = cur++;
    for (int i = 0; i < mess.size(); ++i)
        mess[i] = m[mess[i]] ?: mess[i];
    return mess;
}
};