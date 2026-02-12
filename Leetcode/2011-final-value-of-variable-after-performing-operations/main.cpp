#include <vector>
#include <iostream>

int finalValueAfterOperations(std::vector<std::string>& ops) {
    int x = 0;

    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == "--X" || ops[i] == "X--") {
            --x;
            continue;
        }
        else if (ops[i] == "++X" || ops[i] == "X++") {
            ++x;
            continue;
        }
    }

    return x;    
}
