///Tutorial:   http://apps.topcoder.com/forums/;jsessionid=5E28D21A692681019D97EA4EED3C7392?module=Thread&threadID=627379&start=0&mc=35#1039014

#define N 10000000

char str[N];
int H = 0, Bucket[N], nBucket[N], c;

struct Suffix{
	int idx;
	bool operator<(const Suffix& sfx) const
    {
		if(H == 0) return str[idx] < str[sfx.idx];
		else if(Bucket[idx] == Bucket[sfx.idx])
			return (Bucket[idx+H] < Bucket[sfx.idx+H]);
		else
			return (Bucket[idx] < Bucket[sfx.idx]);
	}
	bool operator==(const Suffix& sfx) const
	{
		return !(*this < sfx) && !(sfx < *this);
	}
} Pos[N];

int UpdateBuckets(int L)
{
	int start = 0, id = 0, c = 0;
	for(int i = 0; i < L; i++)
	{
        if(i != 0 && !(Pos[i] == Pos[i-1]))
		{
			start = i;
			id++;
		}
		if(i != start)
			c = 1;
		nBucket[Pos[i].idx] = id;
	}
	memcpy(Bucket, nBucket, 4 * L);
	return c;
}

void SuffixSort(int L)
{
	for(int i = 0; i < L; i++) Pos[i].idx = i;
	// H == 0, Sort based on first Character.
	sort(Pos, Pos + L);

	c = UpdateBuckets(L);
	for(H=1;c;H *= 2) {
        sort(Pos, Pos+L);
		c = UpdateBuckets(L);
	}
}

int main()
{
	cin >> str;
	int L = strlen(str) + 1;
	int cl = clock();
	SuffixSort(L);
	cerr << (clock() - cl) * 0.001 << endl;
	for(int i = 0; i < L; i++)
		cout << "'" << str + Pos[i].idx << "'" << endl;
	return 0;
}
