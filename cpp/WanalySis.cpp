#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

void check(vector<int> deck, vector<int> soul)
{
    vector<int> chara{0, 1, 2};
    do
    {
        int score = 0;
        cout << chara[0] << "→" << chara[1] << "→" << chara[2] << "の時、期待値" << score << endl;
    } while (next_permutation(chara.begin(), chara.end()));
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> soul;
    soul.push_back(a);
    soul.push_back(b);
    soul.push_back(c);
    int sum = a + b + c;

    for (int i = 0; i < sum - 2; i++)
    {
        for (int j = i + 1; j < sum - 1; j++)
        {
            for (int k = j + 1; k < sum; k++)
            {
                vector<int> deck;
                deck.push_back(i);
                deck.push_back(j);
                deck.push_back(k);
                check(deck, soul);
                // cout << deck.size() << endl;
                // cout << i << j << k << endl;
            }
        }
    }
}
