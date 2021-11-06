#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

void check(vector<vector<int>> deck, vector<int> soul)
{
    double sum = 0;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i].size() < soul.size())
            deck[i].push_back(100);
        // if (i != 2)
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
        sum += score;
        // cout << score << endl;
        // for (int j = 0; j < deck[i].size(); j++)
        // {
        //     cout << "d" << deck[i][j];
        // }
        // cout << endl;
    }

    cout << "ダメージ期待値:" << endl;
    cout << sum / deck.size() << endl;
}

// void make_deck(int sum, vector<vector<int>> &deck)
// {
//     for (int i = 0; i < sum - 2; i++)
//         for (int j = i + 1; j < sum - 1; j++)
//             for (int k = j + 1; k < sum; k++)
//             {
//                 vector<int> tmp;
//                 tmp.push_back(i);
//                 tmp.push_back(j);
//                 tmp.push_back(k);
//                 deck.push_back(tmp);
//             }
// }

void recursive_comb(vector<vector<int>> &deck, vector<int> &indexes, int s, int rest)
{
    if (rest == 0)
    {
        deck.push_back(indexes);
    }
    else
    {
        if (s < 0)
            return;
        recursive_comb(deck, indexes, s - 1, rest);
        indexes[rest - 1] = s;
        recursive_comb(deck, indexes, s - 1, rest - 1);
    }
}

int main()
{
    int a, b, c;
    // cin >> a >> b >> c;
    cout << "キャラ1のソウル:" << endl;
    cin >> a;
    cout << "キャラ2のソウル:" << endl;
    cin >> b;
    cout << "キャラ3のソウル:" << endl;
    cin >> c;
    vector<int> soul;
    soul.push_back(a);
    soul.push_back(b);
    soul.push_back(c);
    // int sum = a + b + c;
    cout << "デッキ枚数" << endl;
    int sum;
    cin >> sum;
    int cx;
    cout << "残りCX: " << endl;
    cin >> cx;
    vector<vector<int>> deck;
    vector<int> indexes(cx);
    vector<int> chara = {0, 1, 2};
    // cout << indexes.size() << endl;
    recursive_comb(deck, indexes, sum - 1, cx);
    do
    {
        vector<int> souls;
        souls.push_back(soul[chara[0]]);
        souls.push_back(soul[chara[1]]);
        souls.push_back(soul[chara[2]]);
        cout << "---------------------------" << endl;
        cout << "アタック順:" << endl;
        cout << "キャラ" << chara[0]+1 << " → キャラ" << chara[1]+1 << " → キャラ" << chara[2]+1 << endl;
        check(deck, souls);
    } while (next_permutation(chara.begin(), chara.end()));

    // rep(i, deck.size())
    // {
    //     rep(j, deck[i].size()) cout << deck[i][j];
    //     cout << endl;
    // }
    // cout<<deck.size()<<endl;
    // make_deck(sum, deck);
    // check(deck, soul);
    // cout << deck.size() << endl;
}
