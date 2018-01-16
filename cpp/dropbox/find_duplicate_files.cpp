经典题目find duplicate files, 但是跟leetcode上的比起来多了超级多follow up:

what if there are many video files, how do you optimize the solution in terms of performance
what is the slowest part of the entire algorithm
what's the characteristics of hash functions like md5, sha1, sha256
what is the possible problems of using dfs to obtaining all files of file system
what problem may exist if comparing only a small chunks of file

Find duplicate files
FollowUp: 如果这个函数非常慢，有哪些原因如何提高性能。Ans：根据metadata比如filesize先做group再找重

coding：Find Duplicate Files，先提出了基本的做法hash整个文件，然后小哥问如果文件太大了怎么办，那就先算每个文件的size，然后对size相同的文件分块hash。小哥先让我写了hash整个文件的代码，给了个函数接口可以算文件的hash值。然后小哥说给了一个Hasher类，里面有两个函数 void feed(byte[] arr)和 String getHash()，如何实现getHash这个函数。[/color]

#define REGULAR_FILE 1
#define DIRECTORY 2

struct Node {
	string pathname;
	unordered_map<string, Node*> children;
	int mode;
	long size;
	Node():mode(0), size(0) {}
};

class Solution {
	string getHash(string file) {
		unsigned char c[MD5_DIGEST_LENGTH];

		FILE *inFile = fopen(file.c_str(), "rb");
		MD5_CTX mdContext;
		int bytes;
		unsigned char data[1024];

		if (inFile == NULL) {
			return "";
		}

		MD5_Init (&mdContext);
		while ((bytes = fread (data, 1, 1024, inFile)) != 0)
			MD5_Update (&mdContext, data, bytes);
		MD5_Final (c,&mdContext);
		fclose(inFile);
		return string(reinterpret_cast<char*>(c));
	}

	void findDup(unordered_map<string, vector<string>>& mp, Node *node) {
		if (node==NULL) return;
		if (node->mode==REGULAR_FILE) {
			string hash=getHash(node->pathname);
			mp[hash].push_back(node->pathname);
			return;
		}

		for (auto iter:node->children) {
			findDup(mp, iter.second);
		}
	}

	vector<vector<string>> findDuplicateFiles(Node *root) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> mp;

		findDup(mp, root);

		for (auto iter:mp) {
			if (iter.second.size()>1) res.push_back(iter.second);
		}
		return res;
	}
};

int main() {
	return 0;
}

