void reverse(int arr[], unsigned int len)
{
	if (len > 0)
	{
		int front = 0;
		int back = (int)len - 1;
		int temp = 0;
		while (front < back)
		{
			temp = arr[front];
			arr[front] = arr[back];
			arr[back] = temp;
			front++;
			back--;
		}
	}
}