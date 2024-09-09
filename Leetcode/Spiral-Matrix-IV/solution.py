# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def spiralMatrix(self, m, n, head):
        """
        :type m: int
        :type n: int
        :type head: Optional[ListNode]
        :rtype: List[List[int]]
        """
        ans = [[-1]*n for _ in range(m)]
        cur_x = 0
        cur_y = 0
        direct = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        direct_idx = 0

        while head:
            ans[cur_x][cur_y] = head.val

            if head.next is None:
                break

            next_x = cur_x + direct[direct_idx][0]
            next_y = cur_y + direct[direct_idx][1]

            if next_x<0 or next_x>=m or next_y<0 or next_y>=n or ans[next_x][next_y] != -1:
                direct_idx = (direct_idx + 1) % 4
            else:
                cur_x = next_x
                cur_y = next_y
                head = head.next

        return ans
    

if __name__ == '__main__':
    sol = Solution()

    m = 3
    n = 5
    l = [3,0,2,6,8,1,7,9,4,2,5,5,0]

    dummy = ListNode()
    cur = dummy

    for num in l:
        cur.next = ListNode(num)
        cur = cur.next

    sol.spiralMatrix(m, n, dummy.next)