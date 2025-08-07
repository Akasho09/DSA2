#include <iostream>
using namespace std;

void findcombos(int i, vector<int> &candidates, int target, vector<int> &arr, vector<vector<int>> &ans)
{
    if (i == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(arr);
        }
        return;
    }

    if (candidates[i] <= target)
    {
        arr.push_back(candidates[i]);
        findcombos(i, candidates, target - candidates[i], arr, ans);
        arr.pop_back();
    }
    findcombos(i + 1, candidates, target, arr, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> arr;
    vector<vector<int>> ans;
    findcombos(0, candidates, target, arr, ans);
    return ans;
}

void helper(vector<int> &candidates, int target, int sum, vector<int> v, vector<vector<int>> &ans, int i)
{
    if (sum == target)
    {
        ans.push_back(v);
        return;
    }
    if (sum > target)
    {
        return;
    }

    for (int j = i; j < candidates.size(); j++)
    {
        v.push_back(candidates[j]);
        helper(candidates, target, sum + candidates[j], v, ans, j);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> v;
    helper(candidates, target, 0, v, ans, 0);
    return ans;
}

int main()
{
}