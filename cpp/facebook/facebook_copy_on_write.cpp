设计 copy-on-write string class
   e.g. stringclass s("abc");
         stringclass s1 = s; // no copy
         s = "bcd"; // copy

mutex g_mutex;

class String {
	String() {
		data=make_shared<vector<char>>();
		len=0;
	}

	~String() {}

	String& operator=(String& s) {
		lock_guard<mutex> guard(g_mutex);
		if (data==NULL) {
			data=s.str();
			len=s.length();
		} else {
			data=make_shareptr<vector<char>>();
			len=s.length();
			data->resize(len);
			copy(s.str()->begin(), s.str()->end(), data->begin());
		}
	}

	String& operator=(const char *s) {
		lock_guard<mutex> guard(g_mutex);
		data=make_shareptr<vector<char>>();
		len=strlen(s);
		data->resize(len);
		for (int i=0; i<len; i++) data[i]=s[i];
	}

	shared_ptr<vector<char>> str() { return data; }
	int length() { return len; }

private:
	shared_ptr<vector<char>> data;
	int len;
};

