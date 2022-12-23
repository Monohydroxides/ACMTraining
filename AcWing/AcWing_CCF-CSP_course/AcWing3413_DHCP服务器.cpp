
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int N, Tdef, Tmax, Tmin;
string Host;
int n;

string sendHost, receivHost, msgType;
int ti, ipAddr, expireTime;

struct ip {
    int state;  // 1：未分配；2：待分配，3：占用，4：过期
    string occupier;
    int expireTime;
} ipPool[10001];

void update_expire_time () {
    for (int i = 1; i <= N; i++) {
        if (ipPool[i].expireTime && ipPool[i].expireTime <= ti) {
            if (ipPool[i].state == 2) {
                ipPool[i].state = 1;
                ipPool[i].occupier = "";
                ipPool[i].expireTime = 0;
            } else {
                ipPool[i].state = 4;
                ipPool[i].expireTime = 0;
            }
        }
    }
}

int get_ip_by_occupy (string occupy) {
    for (int i = 1; i <= N; i++) {
        if (ipPool[i].occupier == occupy) {
            return i;
        }
    }
    return 0;
}

int get_ip_by_state (int state) {
    for (int i = 1; i <= N; i++) {
        if (ipPool[i].state == state) {
            return i;
        }
    }
    return 0;
}

int main () {
    cin >> N >> Tdef >> Tmax >> Tmin >> Host;
    cin >> n;

    for (int i = 1; i <= N; i++) {
        ipPool[i].state = 1;
    }

    while (n--) {
        cin >> ti >> sendHost >> receivHost>> msgType >> ipAddr >> expireTime;
        // cout << n << '\n';
        if (!(receivHost == Host || receivHost == "*")) {
            if (msgType != "REQ") {
                continue;
            }
        }
        if (msgType != "DIS" && msgType != "REQ") {
            continue;
        }
        if ((receivHost == Host && msgType == "DIS") || (receivHost == "*" && msgType != "DIS")) {
            continue;
        }

        update_expire_time();

        if (msgType == "DIS") {
            int ip = 0;

            ip = get_ip_by_occupy(sendHost);
            if (!ip) {
                ip = get_ip_by_state(1);
            }
            if (!ip) {
                ip = get_ip_by_state(4);
            }
            if (!ip) {
                continue;
            }

            ipPool[ip].state = 2;
            ipPool[ip].occupier = sendHost;
            if (expireTime == 0) {
                ipPool[ip].expireTime = ti + Tdef;
            } else {
                int t = expireTime - ti;
                t = max(t, Tmin), t = min(t, Tmax);
                ipPool[ip].expireTime = ti + t;
            }
            cout << Host << " " << sendHost << " OFR " << ip << " " << ipPool[ip].expireTime << '\n';
        } else if (msgType == "REQ") {
            if (receivHost != Host) {
                for (int i = 1; i <= N; i++) {
                    if (ipPool[i].occupier == sendHost && ipPool[i].state == 2) {
                        ipPool[i].state = 1;
                        ipPool[i].occupier = "";
                        ipPool[i].expireTime = 0;
                    }
                }
                continue;
            } else {
                if (!(ipAddr >= 1 && ipAddr <= N && ipPool[ipAddr].occupier == sendHost)) {
                    cout << Host << " " << sendHost << " NAK " << ipAddr << " " << 0 << '\n';
                } else {
                    ipPool[ipAddr].state = 3;
                    if (expireTime == 0) {
                        ipPool[ipAddr].expireTime = ti + Tdef;
                    } else {
                        int t = expireTime - ti;
                        t = max(t, Tmin), t = min(t, Tmax);
                        ipPool[ipAddr].expireTime = ti + t;
                    }
                    cout << Host << " " << sendHost << " ACK " << ipAddr << " " << ipPool[ipAddr].expireTime << '\n';
                }
            }
        }
    }
    return 0;
}
