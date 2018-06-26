/* 
	extended euclidean solves as+bt=gcd(a,b)
*/
ll extended_gcd(ll a, ll b) {
	ll s = 0, old_s = 1, t = 1, old_t = 0, r = b, old_r = a;
	while (r != 0) {
	ll q = old_r / r, z;
	z = old_r; old_r = r; r = z - q * r;
	z = old_s; old_s = s; s = z - q * s;
	z = old_t; old_t = t; t = z - q * t;
	}
	ll ans = b*old_t;	
	if (ans < 0) ans += M;
			return ans;
}

/* 
	generate combination of all factor decompositions
*/
void generate(ll a, ll b, int i) {
	if (i == factors.size()) {
		answer.push_back(extended_gcd(a, b));
	} else {
		generate(a * factors[i], b, i+1);
		generate(a, factors[i] * b, i+1);
	}
}