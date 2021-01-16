int solution2(int N){
	int digit;
	int ans = 0;
	int counter = 0;
	bool countFlag = false;
	while(N != 0){
		digit = N%2;
		N = (int) N/2;
		if (digit == 1)
		{
			ans = std::max(ans,counter);
			counter = 0;
			countFlag = true;
		}
		else if (countFlag == true){
			counter++;
		}
	}
	return ans;
}
