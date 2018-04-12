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
void find_substrings(string s,int i,string look_for) {
    if (s.find(look_for,i) == std::string::npos) {
        return;
    }else {
        cout<<i<<endl;
     find_substrings(s,s.find(look_for,i)+1,look_for);
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
        long ans = 0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                s[i]='1';
            else
                s[i]='0';
	//	cout << s.length() << endl;
		//cout << s << endl;
		
		bool start = false;
        int count = 0;
		vector<int> starts, ends;
        for(int i=0;i<s.length();i++){
            if(!start&&s[i]=='0'){
                start = true;
                count++;
				if (i == s.length() - 1) {
					if (count >= n) {
						if (s[i] == '1') {
							starts.push_back(i - count);
							ends.push_back(i - 1);
						}
						else {
							starts.push_back(i - count + 1);
							ends.push_back(i);
						}


						//           cout<<n<<" "<<(i-count)<<" "<<count<<endl;
					}
				}
            }else if(start) {
				if (s[i] == '0') {
					count++;
				}
				if(s[i]=='1'||i==s.length()-1) {
					if (count >= n) {
						if (s[i]=='1') {
							starts.push_back(i - count);
							ends.push_back(i - 1);
						}
						else {
							starts.push_back(i - count + 1);
							ends.push_back(i);
						}
					
						
						//           cout<<n<<" "<<(i-count)<<" "<<count<<endl;
					}
					start = false;
					count = 0;
				}
              
            }
        }
		if (starts.size() == 0) {
			cout << "Case #" << t << ": 0"  << endl;
		}
		else {
			int j = 0;
			for (int i = 0; i < s.length(); i++) {
				if (j >= starts.size()) {
					counts[i] = 0;
			//		cout << counts[i] << "," ;
				}
				else if (i <= starts[j]) {
					counts[i] = s.length() + 1    - (starts[j] + n);
			//		cout << counts[i] << ":";

				}
				else if (i > starts[j] && i <= ends[j]) {
				//	cout<< i <<" " << ends[j] - i << " number" << endl;
					if(ends[j]-i+1>=n){
						counts[i] = s.length() + 1  - (i + n);
			//			cout << counts[i] << ".";
					}
					else {
						i--;
						j++;
						continue;
					}
				}
				else {
					i--;
					j++;
					continue;
				}
			}
			//cout << endl;
			long ans = 0;
			for (int i = 0; i < s.length(); i++)
				ans += counts[i];
			/*
			for (int i = 0; i < s.length(); i++)
				cout << counts[i] << " ";
			cout << endl;
			*/
			
			cout << "Case #" << t << ": " << ans << endl;
		}
		
		//print(starts);
		//print(ends);
		
    }
    return 1;
}
