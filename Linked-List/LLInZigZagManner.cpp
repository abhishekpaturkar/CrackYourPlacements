Node temp = head;
boolean flag = false;
while (temp.next != null)
{
    if (flag == false)
    {
        if (temp.data > temp.next.data)
        {
            int t = temp.data;
            temp.data = temp.next.data;
            temp.next.data = t;
        }
        flag = true;
    }
    else
    {
        if (temp.data < temp.next.data)
        {
            int t = temp.data;
            temp.data = temp.next.data;
            temp.next.data = t;
        }
        flag = false;
    }
    temp = temp.next;
}
return head;