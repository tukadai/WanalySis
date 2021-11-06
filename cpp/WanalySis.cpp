#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

void check(vector<vector<int>> deck, vector<int> soul)
{
    double sum = 0;
    // vector<int> chara{0, 1, 2};
    // do
    // {
    //     int score = 0;
    //     cout << chara[0] << "→" << chara[1] << "→" << chara[2] << "の時、期待値" << score << endl;
    // } while (next_permutation(chara.begin(), chara.end()));
    for (int i = 0; i < deck.size(); i++)
    {

        // if (i != 4)
        //     continue;
        // cout << i << endl;
        int d = 0;
        int s = 0;
        int count = 0;
        int score = 0;
        while (s < soul.size())
        {
            // cout << deck[i][d] << " ";
            // cout << count + soul[s] - 1 << endl;
            if (deck[i][d] <= count + soul[s] - 1)
            {
                count = deck[i][d] + 1;
                d++;
                // cout << d << endl;
            }
            else
            {
                count += soul[s];
                score += soul[s];
            }
            s++;
        }
        cout << score << endl;
        for (int j = 0; j < deck[i].size(); j++)
        {
            cout << deck[i][j];
        }
        cout << endl;
        sum += score;
        // cout<<soul.size()<<endl;
    }
    cout << sum / deck.size() << endl;
}

void make_deck(int sum, vector<vector<int>> &deck)
{
    for (int i = 0; i < sum - 2; i++)
    {
        for (int j = i + 1; j < sum - 1; j++)
        {
            for (int k = j + 1; k < sum; k++)
            {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(k);
                deck.push_back(tmp);
                // check(deck, soul);
                // cout << deck.size() << endl;
                // cout << i << j << k << endl;
            }
        }
    }
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
    vector<vector<int>> deck;
    make_deck(sum, deck);
    check(deck, soul);
    // cout << deck.size() << endl;
}
