vector<string> allPerm;
void permute(string s, int i=0) {
  if(i == s.length()-1) {
      allPerm.push_back(s);
      return;
  }
  for(int j=i; j<s.length(); j++) {
      swap(s[i], s[j]);
      permute(s, i+1);
      swap(s[i], s[j]);
  }
}

vector<string> find_permutation(string s)
{
  sort(allPerm.begin(), allPerm.end());
  permute(s, 0);
  return allPerm;
}
