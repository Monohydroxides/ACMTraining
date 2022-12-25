#include <bits/stdc++.h>
using namespace std;

int n;                              // 操作数
int file_id;                        // 动态分配文件
struct file {                       // 存放文件信息结构体
    int file_type;                  // 0：文件，1：目录
    int file_father;                // 父亲目录的 id
    map<string, int> file_child;    // 当 file_type = 1 时，存放所有子文件或目录的 id
    long long load_dir, load_child; // 题目中要求的两个配额
    long long cur_dir, cur_child;   // 目前使用到的两个配额，对于文件来讲他们相同
} file_sys[3000010];                // 题目的数据范围，其实开到 2e6 就够了

void init () {                      // 初始化
    file_sys[1].file_type = 1;
    file_sys[1].file_father = -1, file_sys[1].file_child.clear();
    file_sys[1].load_child = file_sys[1].load_dir = file_sys[1].cur_child = file_sys[1].cur_dir = 0;
    file_id = 1;
}

vector<string> parser (string path) {   // 对输入的字符串进行目录解析，在每个地址之前加上 /root
    vector<string> ans;
    path = "/root" + path;
    int i = 1;
    int sz = path.size();
    while (i < sz) {
        int j = i;
        while (j < sz && path[j] != '/') {
            j++;
        }
        ans.push_back(path.substr(i, j - i));
        i = j + 1;
    }
    return ans;
}

pair<int, long long> check_file (vector<string> path) {
    // 检查文件信息，在 Create 和 Remove 两个操作中用到
    // 返回的 pair 的 first 表示 check 状态，second 表示文件或目录信息
    int cur_id = 1;                                     // 当前进入的文件目录的 id，下同
    for (int argc = 0; argc < path.size(); argc++) {    // 遍历路径参数，下同
        string it = path[argc];                         
        int nxt = file_sys[cur_id].file_child[it];      // 下一个文件或目录的 id，若不存在则为 0，下同
        
        if (file_sys[cur_id].file_type == 0) {          
            return {2, file_sys[cur_id].cur_child};     // 返回 2 表示路径中存在非最后一层的文件作为目录，对于 Create 来说是非法的
        }

        if (!nxt) {                                     // 返回 0 表示当前文件或目录不存在
            return {0, 0};
        }

        if (argc == path.size() - 1) {                  // 遍历到最后一个参数了，下同
            if (file_sys[nxt].file_type == 1) {         // 如果最后一个路径仍然是目录，返回 -1，对 Create 来说是非法的
                return {-1, file_sys[nxt].cur_child};
            } else {                                    // 如果最后一个路径是文件，返回 1 和该文件的大小
                return {1, file_sys[nxt].cur_dir};
            }
        } else {
            cur_id = nxt;                               // 向下一层路径继续寻找
        }
    }
    return {0, 0};
}

int check_dir_create_delete (int id, long long file_sz, long long ori_file_sz, int type) {
    // 检查文件创建过程中，是否违反目录 id 的配额限制
    // file_sz 表示要创建的文件大小，ori_file_sz 表示替换的文件大小，若不存在替换则为 0
    // type 表示要创建的文件在目录 id 的后代中还是直接为目录 id 的孩子，若在后代中则为 0，否则为 1
    if (file_sys[id].load_child) {
        if (file_sys[id].cur_child - ori_file_sz + file_sz > file_sys[id].load_child) {
            return 0;
        }
    } 
    if (type) {
        if (file_sys[id].load_dir) {
            if (file_sys[id].cur_dir - ori_file_sz + file_sz > file_sys[id].load_dir) {
                return 0;
            }
        }
    }
    return 1;
}

pair<int, int> check_create (vector<string> path, long long file_sz, long long ori_file_sz) {
    // 检查文件创建过程中，整个路径上全部文件的违反配额情况
    int cur_id = 1;
    for (int argc = 0; argc < path.size(); argc++) {
        string it = path[argc];
        int nxt = file_sys[cur_id].file_child[it];
        if (!check_dir_create_delete(cur_id, file_sz, ori_file_sz, argc == path.size() - 1)) {
            return {-1, -1};
        }
        if (!nxt) {         // 若不存在后续的目录，那么后续的操作一定不会违反限制，直接返回 1
            return {1, 1};
        } else {
            cur_id = nxt;
        }
    }
    return {1, 1};
}

int create_single_file_or_dir (int type, int father_id, string name) {
    // 创建单个文件或目录，type 与 struct 中的 type 相同
    // father_id 表示父亲目录的 id
    // name 表示该文件和目录的名字，以便将其加入父亲目录的 map 中
    int nxt = ++file_id;
    file_sys[nxt].file_type = type, file_sys[nxt].file_father = father_id;
    file_sys[nxt].file_child.clear();
    file_sys[nxt].load_child = file_sys[nxt].load_dir = file_sys[nxt].cur_child = file_sys[nxt].cur_dir = 0;

    file_sys[father_id].file_child[name] = nxt;
    return nxt;
}

void create_file (vector<string> path, long long file_sz, long long ori_file_sz) {
    // 正式创建目录，path 为解析后的路径
    // file_sz 表示创建的文件大小，ori_file_sz 表示替换的文件大小，若不存在则为 0
    // 由于前面已经对各种非法情况进行了 check，该操作必然成功
    int cur_id = 1;
    for (int argc = 0; argc < path.size(); argc++) {
        string it = path[argc];
        int nxt = file_sys[cur_id].file_child[it];

        file_sys[cur_id].cur_child = file_sys[cur_id].cur_child - ori_file_sz + file_sz;
        if (argc == path.size() - 1) {
            file_sys[cur_id].cur_dir = file_sys[cur_id].cur_dir - ori_file_sz + file_sz;
            file_sys[nxt].cur_child = file_sys[nxt].cur_dir = file_sz;
        }

        if (!nxt) {
            nxt = create_single_file_or_dir(argc != path.size() - 1, cur_id, it);
            if (argc == path.size() - 1) {
                file_sys[nxt].cur_child += file_sz;
                file_sys[nxt].cur_dir += file_sz;
            }
        }
        cur_id = nxt;
    }
}

void remove_file_or_dir (vector<string> path, int remove_type, long long size) {
    // 删除文件或目录，remove_type 表示删除类型，若为 1 则是删除了文件，size 为删除的文件或目录大小
    int cur_id = 1;
    for (int argc = 0; argc < path.size(); argc++) {
        string it = path[argc];
        int nxt = file_sys[cur_id].file_child[it];

        file_sys[cur_id].cur_child -= size;
        if (argc == path.size() - 1) {
            if (remove_type == 1) {
                file_sys[cur_id].cur_dir -= size;
            }
            file_sys[cur_id].file_child.erase(it);
        } else {
            cur_id = nxt;
        }
    }
}

pair<int, int> check_qualify (vector<string> path, long long dir_load, long long child_load) {
    // 判断是否能约定配额
    // 若能，返回的 pair 中 first 为 1，second 为要约定配额的目录的 id
    // 若不能，返回的 pair 中 first 为 0，second 无意义
    int cur_id = 1;
    for (int argc = 0; argc < path.size(); argc++) {
        string it = path[argc];
        int nxt = file_sys[cur_id].file_child[it];
        if (!nxt) {
            return {0, 0};
        } else {
            if (argc == path.size() - 1) {
                if (file_sys[nxt].file_type == 0) {
                    return {0, 0};
                }
                if (dir_load) {
                    if (file_sys[nxt].cur_dir > dir_load) {
                        return {0, 0};
                    }
                }
                if (child_load) {
                    if (file_sys[nxt].cur_child > child_load) {
                        return {0, 0};
                    }
                }
                return {1, nxt};
            }
            cur_id = nxt;
        }
    }
    return {0, 0};
}

// 调试函数，可以忽略
// void print_state (int cur_id) {
//     std::cout << "File: " << cur_id << ":\n";
//     std::cout << "File Father: " << file_sys[cur_id].file_father << '\n';
//     std::cout << "File Children Size: " << file_sys[cur_id].file_child.size() << '\n';
//     for (auto [k, v]: file_sys[cur_id].file_child) {
//         std::cout << "Child Name: " << k << ", Child Id: " << v << '\n';
//     }
//     std::cout << "File load(Dir, Children): " << file_sys[cur_id].load_dir << " " << file_sys[cur_id].load_child << '\n';
//     std::cout << "File Cur Load(Dir, Children): " << file_sys[cur_id].cur_dir << " " << file_sys[cur_id].cur_child << '\n';
//     std::cout << '\n';
//     for (auto [k, v]: file_sys[cur_id].file_child) {
//         print_state(v);
//     }
// }

int main () {
    init();
    cin >> n;
    create_single_file_or_dir(1, 1, "root");                                            // 先创建根目录
    for (int Case = 1; Case <= n; Case++) {
        string opt, path;
        cin >> opt >> path;
        long long file_size, dir_load, child_load;
        vector<string> dir = parser(path);
        if (opt == "C") {
            cin >> file_size;
            pair<int, long long> detect1 = check_file(dir);                             // 对文件或目录的存在状态进行判断
            if (detect1.first == -1 || detect1.first == 2) {                            // 若路径非法，或已存在同名目录，则创建操作不成功
                std::cout << "N\n";
                continue;
            }
            pair<int, int> detect2 = check_create(dir, file_size, detect1.second);      // 对路径上的配额进行判断
            if (detect2.first == -1) {                                                  // 若配额不满足，则创建操作不成功
                std::cout << "N\n";
                continue;
            }
            create_file(dir, file_size, detect1.second);                                // 替换文件，若没有被替换的文件则 detect1.second 为 0
            std::cout << "Y\n";
        } else if (opt == "R") {
            pair<int, long long> detect1 = check_file(dir);                             // 对文件或目录的存在状态进行判断
            if (detect1.first == 0 || detect1.first == 2) {
                std::cout << "Y\n";                                                     // 该操作必然成功
                continue;
            }
            remove_file_or_dir(dir, detect1.first, detect1.second);                     // 真正合法的情况下，才需要删除文件和目录
            std::cout << "Y\n";
        } else if (opt == "Q") {
            cin >> dir_load >> child_load;
            pair<int, int> detect1 = check_qualify(dir, dir_load, child_load);          // 对文件的配额进行判断
            if (detect1.first == 0) {                                                   // 若进行配额后不满足，则操作不成功
                std::cout << "N\n";
                continue;
            }
            file_sys[detect1.second].load_dir = dir_load;                               // 进行配额
            file_sys[detect1.second].load_child = child_load;
            std::cout << "Y\n";
        }
        // print_state(1);
    }
    return 0;
}