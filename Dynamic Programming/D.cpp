#include <iostream>
#include <vector>


using namespace std;

bool is_possible[100001][101];


int main(){

	int tt_coins; cin>>tt_coins;
	int coin[tt_coins];

	for(auto &value:coin)cin>>value;

	is_possible[0][0]=true;

	vector<int> ans;

	for(int target=0; target <= 100000 ;++target){

		for(int ith=0; ith < tt_coins ; ++ith){

			is_possible[target][ith+1]=is_possible[target][ith];

			if(target >= coin[ith])
			is_possible[target][ith+1]=(is_possible[target][ith+1] || is_possible[target-coin[ith]][ith]);

		}

     if(is_possible[target][tt_coins] && target )ans.push_back(target);

	}

	cout<<ans.size()<<'\n';
	for(auto target:ans)cout<<target<<" ";

	return 0;
}
