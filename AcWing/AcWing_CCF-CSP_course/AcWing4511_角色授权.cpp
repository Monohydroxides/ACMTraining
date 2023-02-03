#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int n, m, q;
typedef struct data {
    unordered_map<string, bool> opts;
    unordered_map<string, bool> src_ty;
    unordered_map<string, bool> src_name;
} Data;

unordered_map<string, Data> chara;    
unordered_map<string, vector<string>> us;
unordered_map<string, vector<string>> usg;

string name, r, cha, usr, kl, op, srty, srnm, obj, nam, k;
int nv, no, nn, ns;
bool optag = 0, srtytag = 0, srnmtag = 0, tag = 0;

int main () {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int p = 1; p <= n; p++) {  
        cin >> name >> nv;
        for (int i = 1; i <= nv; i++) {
            cin >> r;
            chara[name].opts[r] = 1;
        }
        cin >> no;
        for (int i = 1; i <= no; i++) {
            cin >> r;
            chara[name].src_ty[r] = 1;
        }
        cin >> nn;
        if (nn == 0) {
            chara[name].src_name["*"] = 1;
        }
        for (int i = 1; i <= nn; i++) {
            cin >> r;
            chara[name].src_name[r] = 1;
        }
    }
    for (int p = 1; p <= m; p++) {
        cin >> cha >> ns; 
        for (int i = 1; i <= ns; i++) {
            cin >> obj >> nam;
            if (obj == "u") {
                us[nam].push_back(cha);
            } else {
                usg[nam].push_back(cha);
            }
        }
    }
    for (int p = 1; p <= q; p++) {
        cin >> usr;
        int ng;
        cin >> ng;
        vector<string> bel;
        for (int i = 1; i <= ng; i++) {
            cin >> kl;
            bel.push_back(kl);
        }
        cin >> op >> srty >> srnm;
        optag = 0, srtytag = 0, srnmtag = 0;
        tag = 0;
        if (us.count(usr)) {
            for (auto ch : us[usr]) {
                k = ch;
                if (!chara.count(k)) continue;
                optag = 0, srtytag = 0, srnmtag = 0;
                if (chara[k].opts.count("*") || chara[k].opts.count(op)) {
                    optag = 1;
                }
                if (chara[k].src_ty.count("*") || chara[k].src_ty.count(srty)) {
                    srtytag = 1;
                }
                if (chara[k].src_name.count("*") || chara[k].src_name.count(srnm)) {
                    srnmtag = 1;
                }
                if (optag && srtytag && srnmtag) {
                    tag = 1;
                    break;
                }
            }
        }
        if (tag) {
            cout << 1 << "\n";
            continue;
        }
        for (auto kl : bel) {
            if (usg.count(kl)) {
                for (auto ch : usg[kl]) {
                    k = ch;
                    if (!chara.count(k)) continue;
                    optag = 0, srtytag = 0, srnmtag = 0;
                    if (chara[k].opts.count("*") || chara[k].opts.count(op)) {
                        optag = 1;
                    }
                    if (chara[k].src_ty.count("*") || chara[k].src_ty.count(srty)) {
                        srtytag = 1;
                    }
                    if (chara[k].src_name.count("*") || chara[k].src_name.count(srnm)) {
                        srnmtag = 1;
                    }
                    if (optag && srtytag && srnmtag) {
                        tag = 1;
                        break;
                    }
                }
            }
        }
        if (tag) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
