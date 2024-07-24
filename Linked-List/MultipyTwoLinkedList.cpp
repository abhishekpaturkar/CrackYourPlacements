class solution
{
public:
    long long mod = 1000000007;
    long long convert(Node *head)
    {
        long long num = 0;
        Node *curr = head;

        while (curr)
        {
            num = (num * 10 + curr->data) % mod;
            curr = curr->next;
        }
        return num;
    }

    long long multiplyTwoLists(Node *l1, Node *l2)
    {
        long long num1 = convert(l1) % mod;
        long long num2 = convert(l2) % mod;

        return (num1 * num2) % mod;
    }
};