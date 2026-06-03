/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        std::unordered_map<int, ListNode*> seen;
        int index=0;
        while (head) {
            auto it = seen.find(head->val);
            if ( it == seen.end()) {
                seen[head->val]=head->next;
            } else {
                if (head->next==it->second)
                    return true;
            }
            index++;
            head=head->next;
        }
        return false;
    }
};
