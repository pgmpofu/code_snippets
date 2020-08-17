int identical(int arr1[], int arr2[], unsigned int len)
{
  unsigned int index = 0;
		while (index  < len && len > 0)
		{
			if (arr1[index] != arr2[index])
			{
				return 0;
			}
      		
      		index++;
		}
	return 1;
}