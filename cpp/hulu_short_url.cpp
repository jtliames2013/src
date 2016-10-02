string idToShortUrl(long n) {
	string res;
	char letter[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	while (n>0) {
		int digit=n%62;
		res.push_back(letter[digit]);
		n/=62;
	}
	for (int i=res.size(); i<6; i++) {
		res.push_back('0');
	}
	reverse(res.begin(), res.end());

	return res;
}

long shortUrlToId(string s) {
	long res=0;
	for (int i=0; i<s.size(); i++) {
		if (s[i]>='a' && s[i]<='z') {
			res=res*62+s[i]-'a';
		} else if (s[i]>='A' && s[i]<='Z') {
			res=res*62+s[i]-'A'+26;
		} else if (s[i]>='0' && s[i]<='9') {
			res=res*62+s[i]-'0'+52;
		}
	}

	return res;
}

