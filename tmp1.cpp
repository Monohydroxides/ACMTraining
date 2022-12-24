#include <bits/stdc++.h>
using namespace std;

int n;
string opt;

long long file_size, load_dir, load_child;
string file_path;

int file_idx;
struct file {
    int father_id;
    int type;       // 1: dir, 2: file
    long long load_dir, load_child;
    long long cur_load_dir, cur_load_child;
    map<string, int> child_file;
} file_sys[4000010];

void init () {
    file_idx = 1;
    file_sys[file_idx].father_id = -1;
    file_sys[file_idx].type = 1;
    file_sys[file_idx].load_dir = file_sys[file_idx].load_child = 0;
    file_sys[file_idx].cur_load_child = file_sys[file_idx].cur_load_dir = 0;
    file_sys[file_idx].child_file.clear();
}

vector<string> parser (string str) {
    vector<string> ret;
    int sz = str.size();
    int i = 1;
    while (i < sz) {
        int j = i;
        while (j < sz && str[j] != '/') {
            j++;
        }
        ret.push_back(str.substr(i, j - i));
        i = j + 1;
    }
    return ret;
}

pair<int, long long> check_file (vector<string> dir) {
    int cur_dir_id = 1;
    for (int argc = 0; argc < dir.size(); argc++) {
        string it = dir[argc];
        int nxt = file_sys[cur_dir_id].child_file[it];
        if (!nxt) {
            return {0, 0};
        }
        if (argc == dir.size() - 1) {
            if (file_sys[nxt].type == 2) {
                return {1, file_sys[nxt].cur_load_dir};
            }   
        } else {
            cur_dir_id = nxt;
        }
    }
    return {0, 0};
}

bool check_create_1 (vector<string> dir, long long file_size) {
    int cur_dir_id = 1;
    for (int argc = 0; argc < dir.size(); argc++) {
        string it = dir[argc];
        int nxt = file_sys[cur_dir_id].child_file[it];
        if (argc == dir.size() - 1) {
            if (nxt) {
                if (file_sys[nxt].type == 1) {
                    return 0;
                }
            }
            if ((file_sys[cur_dir_id].load_child && (file_sys[cur_dir_id].cur_load_child + file_size > file_sys[cur_dir_id].load_child))
            || (file_sys[cur_dir_id].load_dir && (file_sys[cur_dir_id].cur_load_dir + file_size > file_sys[cur_dir_id].load_dir))) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (!nxt) {
                if (file_sys[cur_dir_id].load_child 
                && (file_sys[cur_dir_id].cur_load_child + file_size > file_sys[cur_dir_id].load_child)) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                if (file_sys[nxt].type == 2) {
                    return 0;
                } else {
                    if (file_sys[cur_dir_id].load_child 
                    && (file_sys[cur_dir_id].cur_load_child + file_size > file_sys[cur_dir_id].load_child)) {
                        return 0;
                    } else {
                        cur_dir_id = nxt;
                    }
                }
            }
        }
    }
    return 1;
}

bool check_create_2 (vector<string> dir, long long file_size, long long original_file_size) {
    int cur_dir_id = 1;
    for (int argc = 0; argc < dir.size(); argc++) {
        string it = dir[argc];
        int nxt = file_sys[cur_dir_id].child_file[it];
        if (argc == dir.size() - 1) {
            if ((file_sys[cur_dir_id].load_child && (file_sys[cur_dir_id].load_child < file_sys[cur_dir_id].cur_load_child - original_file_size + file_size))
            || (file_sys[cur_dir_id].load_dir && (file_sys[cur_dir_id].load_dir < file_sys[cur_dir_id].cur_load_dir - original_file_size + file_size))) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if ((file_sys[cur_dir_id].load_child && (file_sys[cur_dir_id].load_child < file_sys[cur_dir_id].cur_load_child - original_file_size + file_size))) {
                return 0;
            }
            cur_dir_id = nxt;
        }
    }
    return 1;
}

int create_single_file_or_dir (int dir, string name, int type, long long file_size) {
    int nxt = ++file_idx;
    file_sys[nxt].father_id = dir;
    file_sys[nxt].type = type;
    file_sys[file_idx].load_dir = file_sys[file_idx].load_child = 0;
    file_sys[file_idx].cur_load_child = file_sys[file_idx].cur_load_dir = 0;
    file_sys[nxt].child_file.clear();

    file_sys[dir].child_file[name] = nxt;
    if (type == 1) {
        file_sys[dir].cur_load_child += file_size;
    } else if (type == 2) {
        file_sys[dir].cur_load_child += file_size;
        file_sys[dir].cur_load_dir += file_size;
    }
    return nxt;
}

void create_file (vector<string> dir, long long file_size, long long original_file_size) {
    int cur_dir_id = 1;
    for (int argc = 0; argc < dir.size(); argc++) {
        string it = dir[argc];
        int nxt = file_sys[cur_dir_id].child_file[it];
        if (nxt) {
            file_sys[cur_dir_id].cur_load_child -= original_file_size;
            file_sys[cur_dir_id].cur_load_child += file_size;
            if (argc == dir.size() - 1) {
                file_sys[cur_dir_id].cur_load_dir -= original_file_size;
                file_sys[cur_dir_id].cur_load_dir += file_size;
                file_sys[nxt].load_dir = file_sys[nxt].load_child = 0;
                file_sys[nxt].father_id = cur_dir_id;
                file_sys[nxt].cur_load_dir = file_sys[nxt].cur_load_child = file_size;
                file_sys[nxt].child_file.clear();
            }
            cur_dir_id = nxt;
        } else {
            int type = (argc == dir.size() - 1)? 2: 1;
            nxt = create_single_file_or_dir(cur_dir_id, it, type, file_size);
            if (argc == dir.size() - 1) {
                file_sys[nxt].cur_load_dir += file_size;
                file_sys[nxt].cur_load_child += file_size;
            }
            cur_dir_id = nxt;
        }
    }
}

pair<bool, long long> check_remove_1 (vector<string> dir) {
    int cur_dir_id = 1;
    for (int argc = 0; argc < dir.size(); argc++) {
        string it = dir[argc];
        int nxt = file_sys[cur_dir_id].child_file[it];
        if (!nxt) {
            return {0, 0};
        } else {
            cur_dir_id = nxt;
        }
    }
    return {1, file_sys[cur_dir_id].cur_load_child};
}

void remove_file (vector<string> dir, long long file_size) {
    int cur_dir_id = 1;

    if (!dir.size()) {
        file_sys[cur_dir_id].child_file.clear();
        file_sys[cur_dir_id].cur_load_child = file_sys[cur_dir_id].cur_load_dir = 0;
        return;
    }

    for (int argc = 0; argc < dir.size(); argc++) {
        string it = dir[argc];
        int nxt = file_sys[cur_dir_id].child_file[it];
        if (argc == dir.size() - 1) {
            file_sys[cur_dir_id].cur_load_child -= file_size;
            file_sys[cur_dir_id].cur_load_dir -= file_size;
            file_sys[cur_dir_id].child_file.erase(it);
        } else {
            file_sys[cur_dir_id].cur_load_child -= file_size;
            cur_dir_id = nxt;
        }
    }
}

bool check_qualify_1 (vector<string> dir, long long dir_load, long long child_load) {
    int cur_dir_id = 1;

    if (!dir.size()) {
        if ((child_load && file_sys[cur_dir_id].cur_load_child > child_load)
        || (dir_load && file_sys[cur_dir_id].cur_load_dir > dir_load)) {
            return false;
        }
        return true;
    }

    for (int argc = 0; argc < dir.size(); argc++) {
        string it = dir[argc];
        int nxt = file_sys[cur_dir_id].child_file[it];
        if (!nxt) {
            return false;
        } else {
            if (argc == dir.size() - 1) {
                if (file_sys[nxt].type == 2) {
                    return false;
                } 
                if ((dir_load && (dir_load < file_sys[nxt].cur_load_dir))
                || (child_load && (child_load < file_sys[nxt].cur_load_child))) {
                    return false;
                }
            } else {
                cur_dir_id = nxt;
            }
        }
    }
    return true;
}

void qualify_file (vector<string> dir, long long dir_load, long long child_load) {
    int cur_dir_id = 1;

    if (!dir.size()) {
        file_sys[cur_dir_id].load_child = child_load;
        file_sys[cur_dir_id].load_dir = dir_load;
        return;
    }

    for (int argc = 0; argc < dir.size(); argc++) {
        string it = dir[argc];
        int nxt = file_sys[cur_dir_id].child_file[it];
        if (argc == dir.size() - 1) {
            file_sys[nxt].load_child = child_load;
            file_sys[nxt].load_dir = dir_load;
        } else {
            cur_dir_id = nxt;
        }
    }
}

signed main () {
    init();
    cin >> n;
    while (n--) {
        cin >> opt >> file_path;
        vector<string> dir = parser(file_path);
        if (opt == "C") {
            cin >> file_size;
            pair<int, long long> detect1 = check_file(dir);

            if (detect1.first) {
                bool detect = check_create_2(dir, file_size, detect1.second);
                if (!detect) {
                    cout << "N\n";
                    continue;
                }
                create_file(dir, file_size, detect1.second);
                cout << "Y\n";
            } else {
                bool detect = check_create_1(dir, file_size);
                if (!detect) {
                    cout << "N\n";
                    continue;
                }
                create_file(dir, file_size, 0); 
                cout << "Y\n";
            }            
        } else if (opt == "R") {
            auto detect = check_remove_1(dir);
            if (!detect.first) {
                cout << "Y\n";
                continue;
            }
            remove_file(dir, detect.second);
            cout << "Y\n";
        } else if (opt == "Q") {
            cin >> load_dir >> load_child;
            if (!check_qualify_1(dir, load_dir, load_child)) {
                cout << "N\n";
                continue;
            }
            qualify_file(dir, load_dir, load_child);
            cout << "Y\n";
        }
    }
    return 0;
}
