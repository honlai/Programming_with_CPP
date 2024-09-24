#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s1="",s2="";
    cin>>s1>>s2;
    vector<int> tmp_list(s1.length()+s2.length()-1,0);
    for(int i=s1.length()-1;i>=0;--i)
    {
        for(int j=s2.length()-1;j>=0;--j)
        {
            tmp_list[i+j]+=(int)(s1[i]-'0')*(int)(s2[j]-'0');
        }
    }
    int tmp=0;
    vector<int> ans;
    for(vector<int>::iterator iter_tmp_list=tmp_list.end()-1;iter_tmp_list!=tmp_list.begin();--iter_tmp_list)
    {
        tmp+=*iter_tmp_list;
        ans.push_back(tmp%10);
        tmp/=10;
    }
    ans.push_back(*tmp_list.begin()+tmp);
    for(int i=ans.size()-1;i>=0;--i)
    {
        cout<<ans[i]<<flush;
    }
    return 0;
}