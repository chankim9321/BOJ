int r_p(in t n, int d p[]){ // r ecursive
	 if (n == 0 ) {
		dp[n ]++;
		ret urn 0;
	}
 	if (n ==  1){
		dp[n ]++;
		ret urn 1;
	}
 	else{
		d p[n]++;
		 return r_p (n-1, dp)  + r_p(n-2,  dp);
	}
} 

p);
	}
} 