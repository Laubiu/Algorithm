#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> HAHA;
    HAHA.push(10);
    HAHA.push(25);
    HAHA.push(17);
    HAHA.push(48);
    HAHA.push(32);
    HAHA.push(56);
    HAHA.push(10);
    HAHA.push(27);
    
    // Print the initial queue
    std::cout << "初始优先级队列（最小堆）: ";
    std::priority_queue<int, std::vector<int>, std::greater<int>> temp = HAHA;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << "\n";
    std::cout << "最佳合并树的构造过程为：" << std::endl;
    // 生成最佳合并树
    while (HAHA.size() > 1) {
        // 选择最小的两个元素
        int first = HAHA.top();
        HAHA.pop();
        int second = HAHA.top();
        HAHA.pop();
        
        // 将它们组合并插入回队列中
        int combined = first + second;
        HAHA.push(combined);
        
        // 输出
        std::cout << "结合 " << first << " 和 " << second << " 组成 " << combined << "\n";
    }
    
    // The last element in the priority queue is the root of the optimal merge tree
    std::cout << "最优合并树的根: " << HAHA.top() << "\n";
    
    return 0;
}
