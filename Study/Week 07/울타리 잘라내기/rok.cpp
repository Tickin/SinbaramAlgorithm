#include <iostream>
#include <algorithm>

using namespace std;

int maxFence(int* fence, int start, int end);

int main() {
	int N; cin >> N;

	while (N--) {
		int len; cin >> len;
		int* fence = new int[len];

		for (int i = 0; i < len; i++)
			cin >> fence[i];

		int recycle = maxFence(fence, 0, len);

		cout << recycle << endl;
	}

	return 0;
}

int maxFence(int* fence, int start, int end) {

	if (end - start == 1)
		return fence[start];

	int center = start + ((end - start) / 2);
	int LMax = maxFence(fence, start, center);
	int RMax = maxFence(fence, center, end);
	
	int CMax = fence[center];
	int Left, Right, Height, Width;
	Left = Right = center;
	Height = fence[center];
	Width = 1;
	while (Right != end - 1 || Left != start) {
		if (Left == start) {
			Right++; Width++;
			if (Height > fence[Right])
				Height = fence[Right];
			if (CMax < Width*Height)
				CMax = Width*Height;
		}

		else if (Right == end - 1) {
			Left--; Width++;
			if (Height > fence[Left])
				Height = fence[Left];
			if (CMax < Width*Height)
				CMax = Width*Height;
		}

		else {
			if (fence[Left - 1] > fence[Right + 1]) {
				Left--; Width++;
				if (Height > fence[Left])
					Height = fence[Left];
				if (CMax < Width*Height)
					CMax = Width*Height;
			}
			else {
				Right++; Width++;
				if (Height > fence[Right])
					Height = fence[Right];
				if (CMax < Width*Height)
					CMax = Width*Height;
			}
		}
	}

	return max({ LMax, RMax, CMax });
}