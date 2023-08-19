#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,m;
    int a,b;

    cin >> n >> m;

    int ans = 0;
    set<int> numbers;
    vector<int> nums(n);
    vector<int> idx_numbers(n+1);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
        idx_numbers[nums[i]] = i;
        numbers.insert(nums[i]);
        if(numbers.find(nums[i]-1) == numbers.end()) {
            ans++;
        }
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        a--;b--;
        if(b<a) swap(a,b);
        
        int old_idx_prev_numA = idx_numbers[nums[a]-1];
        int old_idx_numA = idx_numbers[nums[a]];
        int old_idx_next_numA = idx_numbers[nums[a]+1];
        
        int old_idx_prev_numB = idx_numbers[nums[b]-1];
        int old_idx_numB = idx_numbers[nums[b]];
        int old_idx_next_numB = idx_numbers[nums[b]+1];

        int aux_num = nums[a];
        nums[a] = nums[b];
        nums[b] = aux_num;

        idx_numbers[nums[a]] = a;
        idx_numbers[nums[b]] = b;

        int new_idx_prev_numA = idx_numbers[nums[b]-1];
        int new_idx_numA = idx_numbers[nums[b]];
        int new_idx_next_numA = idx_numbers[nums[b]+1];
        
        int new_idx_prev_numB = idx_numbers[nums[a]-1];
        int new_idx_numB = idx_numbers[nums[a]];
        int new_idx_next_numB = idx_numbers[nums[a]+1];

        if(old_idx_next_numA > old_idx_numA && new_idx_next_numA < new_idx_numA) {
            ans++;
        }
        if(old_idx_prev_numA > old_idx_numA && new_idx_prev_numA < new_idx_numA) {
            ans--;
        }

        if(nums[b] - nums[a] != -1 && old_idx_prev_numB < old_idx_numB && new_idx_prev_numB > new_idx_numB) {
            ans++;
        }
        if(nums[b] - nums[a] != 1 && old_idx_next_numB < old_idx_numB && new_idx_next_numB > new_idx_numB) {
            ans--;
        }

        cout << ans << "\n";
    }

    return 0;
}