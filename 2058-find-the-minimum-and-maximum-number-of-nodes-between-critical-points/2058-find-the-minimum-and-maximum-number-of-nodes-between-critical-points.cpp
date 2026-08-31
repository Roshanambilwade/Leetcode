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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int a1 = -1;
        int a2 = -1;
        vector<int>ans;

        ListNode*prev = head;
        ListNode*temp = head->next;
        int i = 2;
        while(temp->next != NULL){
            ListNode*next = temp->next;
             if((temp->val > prev->val && temp->val > next->val) || (temp->val < prev->val && temp->val < next->val)){
                ans.push_back(i);
             }
             i++;
             prev = temp;
             temp = temp->next;
        }
        if(ans.size() == 0 || ans.size() == 1){
            return {-1,-1};
        }
        int mind = INT_MAX;
        for(int i=1;i<ans.size();i++){
            mind = min(mind,(ans[i]-ans[i-1]));
        }
        int n = ans.size();
        int maxd = ans[n-1] - ans[0];

        return {mind,maxd};
        
    }
};