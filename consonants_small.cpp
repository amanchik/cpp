#include <iostream>
#include <algorithm>
#include <map>
#include<vector>
using namespace std;
string con(int n) {
    string s="";
    for(int i=0;i<n;i++)
        s+='0';
    return s;
}
int find_substrings(string s,int i,string look_for) {
	if (i == s.length()) {
		return 0;
	}
    if (s.find(look_for,i) == std::string::npos) {
        return 0;
    }else {
		int first = s.find(look_for, i);
     return s.length()-first-1+find_substrings(s,i+1,look_for);
    }
}
template<typename Type>
void print(vector<Type> v) {
	for (int i = 0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        string s;
        cin>>s>>n;
		int counts[s.length()];
        for(int i=0;i<s.length();i++)
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                s[i]='1';
            else
                s[i]='0';
		string look_for = con(n);
		long ans = 0;
		for (int i = 0; i < s.length(); i++) {
			int row = 0;
			for (int j = 1; j <= s.length() - i; j++) {
				string str = s.substr(i, j);
				if (str.find(look_for) != std::string::npos) {
					row++;
				}

			}
			counts[i] = row;
			ans += row;
		}
		/*
		for (int i = 0; i < s.length(); i++)
			cout << counts[i] << " ";
		cout << endl;
		*/
		cout << "Case #" << t << ": "<<ans<< endl;

    }
    return 1;
}
