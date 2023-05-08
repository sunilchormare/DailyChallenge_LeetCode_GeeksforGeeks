class Solution {
public:
   char arr[3] = {'a', 'b', 'c'};
string result;

void solve(string curr, int n, int &k)
{
    if (curr.length() == n and k==1)
    {
        result = curr;
        k--;return;
    }

    if (curr.length() == n)
    {        
        k--; return;
    }

    for (int i = 0; i < 3; i++)
    {
        if ((curr.length() == 0) or (curr[curr.length() - 1] != arr[i]))
        {
            curr.push_back(arr[i]);
            solve(curr, n, k);
            curr.pop_back();
        }
    }
}

string getHappyString(int n, int k)
{
    string curr = "";
    solve(curr, n, k);
    return result;
}
};