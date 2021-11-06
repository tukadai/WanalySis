#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

void check(vector<vector<int>> deck, vector<int> soul, int a)
{
    vector<int> score_list;
    rep(i, deck.size())
    {
        if (deck[i].size() < soul.size())
            deck[i].push_back(100);
        int d = 0;
        int s = 0;
        int count = 0;
        int score = 0;
        while (s < soul.size())
        {
            if (deck[i][d] <= count + soul[s] - 1)
            {
                count = deck[i][d] + 1;
                d++;
            }
            else
            {
                count += soul[s];
                score += soul[s];
                if (score >= a)
                    break;
            }
            s++;
        }
        score_list.push_back(score);
    }

    rep(i, score_list.size())
    {
        if (count(score_list.begin(), score_list.end(), i) == 0)
            continue;
        cout << i << "ダメージ: " << round((double)count(score_list.begin(), score_list.end(), i) / deck.size() * 100) << "%" << endl;
    }
    cout << "ダメージ期待値:" << endl;
    cout << round((double)accumulate(score_list.begin(), score_list.end(), 0) / deck.size() * 100) / 100 << endl;
}

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

int main(int argc, char *argv[])
{
    int a, b, c;
    cout << "キャラ1のソウル:" << endl;
    cin >> a;
    cout << "キャラ2のソウル:" << endl;
    cin >> b;
    cout << "キャラ3のソウル:" << endl;
    cin >> c;
    cout << "デッキ枚数" << endl;
    int sum;
    cin >> sum;
    int cx;
    cout << "残りCX: " << endl;
    cin >> cx;
    int d = 100;
    if (strcmp(argv[1], "dmg")==0)
    {
        cout << "与えたいダメージ" << endl;
        cin >> d;
    }

    vector<int> soul = {a, b, c};
    vector<vector<int>> deck;
    vector<int> chara = {0, 1, 2};
    vector<int> indexes(cx);
    recursive_comb(deck, indexes, sum - 1, cx);
    do
    {
        vector<int> souls = {soul[chara[0]], soul[chara[1]], soul[chara[2]]};
        cout << "---------------------------" << endl;
        if (argc == 1)
        {
            check(deck, souls, d);
            break;
        }
        else
        {
            cout << "アタック順:" << endl;
            cout << "キャラ" << chara[0] + 1 << " → キャラ" << chara[1] + 1 << " → キャラ" << chara[2] + 1 << endl;
            check(deck, souls, d);
        }
    } while (next_permutation(chara.begin(), chara.end()));
}
