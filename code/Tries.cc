#include "template.h"
typedef struct Trie{
  int words, prefixes;  //only proper prefixes(words not included)
  // bool isleaf; //for only checking words not counting prefix or words
  struct Trie * edges[26];
  Trie(){
    words = 0;  prefixes = 0;
    rep(i,26)
      edges[i] = NULL;
  }
} Trie;
Trie * root;
void addword(Trie * node, string a){
  rep(i,a.size()){
    if(node->edges[a[i] - 'a'] == NULL)
      node->edges[a[i] - 'a'] = new Trie();
    node = node->edges[a[i] - 'a'];
    node->prefixes++;
  }
  // node->isleaf = true;
  node->prefixes--;
  node->words++;
}

int count_words(Trie * node, string a){
  rep(i,a.size()){
    if(node->edges[a[i] - 'a'] == NULL)
      return 0;
    node = node->edges[a[i] - 'a'];
  }
  return node->words;
}

int count_prefixes(Trie * node, string a){
  rep(i,a.size()){
    if(node->edges[a[i] - 'a'] == NULL)
      return 0;
    node = node->edges[a[i] - 'a'];
  }
  return node->prefixes;
}

// bool find(Trie * node, string a){
//  rep(i,a.size()){
//    if(node->edges[a[i] - 'a'] == NULL)
//      return false;
//    node = node->edges[a[i] - 'a'];
//  }
//  return node->isleaf;
// }

int main(){
  root = new Trie();
  rep(i,26)
    if(root->edges[i] != NULL)
      cout<<(char)('a' + i);
  return 0;
}
