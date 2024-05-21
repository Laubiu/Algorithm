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
    std::cout << "��ʼ���ȼ����У���С�ѣ�: ";
    std::priority_queue<int, std::vector<int>, std::greater<int>> temp = HAHA;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << "\n";
    std::cout << "��Ѻϲ����Ĺ������Ϊ��" << std::endl;
    // ������Ѻϲ���
    while (HAHA.size() > 1) {
        // ѡ����С������Ԫ��
        int first = HAHA.top();
        HAHA.pop();
        int second = HAHA.top();
        HAHA.pop();
        
        // ��������ϲ�����ض�����
        int combined = first + second;
        HAHA.push(combined);
        
        // ���
        std::cout << "��� " << first << " �� " << second << " ��� " << combined << "\n";
    }
    
    // The last element in the priority queue is the root of the optimal merge tree
    std::cout << "���źϲ����ĸ�: " << HAHA.top() << "\n";
    
    return 0;
}
