//root node should be a dummy node

class TrieNode {
public:
    map<char, TrieNode*> c;

    void insert(string& s){ insert(s, 0); }

    void insert(string& s, int i){
        if(i == s.size()) return;
        if(!c.count(s[i])) c[s[i]] = new TrieNode();
        c[s[i]]->insert(s, i+1);
    }

    ~TrieNode(){ for(auto& cu : c) delete cu.second; }
};