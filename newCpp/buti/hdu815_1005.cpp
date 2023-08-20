#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

std::vector<std::vector<int>> reshape(std::vector<int> &nums, int numRows, int numCols)
{
    int totalElements = numRows * numCols;
    if ((int)nums.size() != totalElements)
    {
        return {};
    }

    std::vector<std::vector<int>> reshaped(numRows, std::vector<int>(numCols));

    for (int i = 0; i < totalElements; ++i)
    {
        int newRow = i / numCols;
        int newCol = i % numCols;
        reshaped[newRow][newCol] = nums[i];
    }

    return reshaped;
}

void solve()
{
    std::string s;
    std::getline(std::cin, s);

    int numRows, numCols;
    std::cin >> numRows >> numCols;

    s = s.substr(1, s.size() - 2);
    std::stringstream ss(s);
    std::vector<int> input;
    int num;
    while (ss >> num)
    {
        input.push_back(num);
        if (ss.peek() == ',')
        {
            ss.ignore();
        }
    }

    std::vector<std::vector<int>> reshaped = reshape(input, numRows, numCols);

    std::cout << "[";
    for (int i = 0; i < numRows; ++i)
    {
        std::cout << "[";
        for (int j = 0; j < numCols; ++j)
        {
            std::cout << reshaped[i][j];
            if (j < numCols - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < numRows - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    std::cin.ignore();
}

int main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}