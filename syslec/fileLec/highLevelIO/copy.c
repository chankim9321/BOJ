int r_p(int n, int dp[]){ // recursive
	if (n == 0) {
		dp[n]++;
		return 0;
	}
	if (n == 1){
		dp[n]++;
		return 1;
	}
	else{
		dp[n]++;
		return r_p(n-1, dp) + r_p(n-2, dp);
	}
}

