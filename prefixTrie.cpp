/**
 * Class implementation of prefix trie
 *Link to full problem statement:
 */
class node {
public:
    node* child[26];
    bool isEnd;
};
class Trie {
public:
    node* root;
    Trie() {
        root  = new node();
    }

    void insert(string word) {
        node* curr = root;
        for (auto ch : word) {
            if (curr->child[ch - 'a'] == NULL) {
                curr->child[ch - 'a'] = new node();
            }
            curr = curr->child[ch - 'a'];
        }
        curr->isEnd = true;
    }

    // return true if word is in tree
    bool search(string word) {
        node* curr = root;
        for (auto ch : word) {
            if (curr->child[ch - 'a'] == NULL) {
                return false;
            }
            curr = curr->child[ch - 'a'];
        }
        if (curr->isEnd)
            return true;
        return false;
    }

    // return true if prefix is in tree
    bool startsWith(string prefix) {
        node* curr = root;
        for (auto ch : prefix) {
            if (curr->child[ch - 'a'] == NULL) {
                return false;
            }
            curr = curr->child[ch - 'a'];
        }
        return true;
    }
};
