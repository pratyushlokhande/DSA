/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        map<ListNode *, bool> m;

        while (head != NULL)
        {
            if (m.count(head))
            {
                return true;
            }

            m[head] = true;
            head = head->next;
        }

        return false;
    }
};