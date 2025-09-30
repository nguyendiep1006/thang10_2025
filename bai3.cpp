// Bài: Tìm giá trị xuất hiện nhiều nhất; nếu hòa, chọn giá trị xuất hiện trước
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numElements;
	if(!(cin >> numElements)) return 0;

	// Ràng buộc: 0 <= A[i] <= 1e6, N <= 1000
	static int occurrenceCounts[1000001];
	int inputValues[1005];

	for(int index = 0; index < numElements; ++index){
		int value; cin >> value;
		inputValues[index] = value;
		// Mảng đánh dấu: đếm tần suất
		++occurrenceCounts[value];
	}

	// Duyệt từ trái sang phải để đảm bảo khi tần suất bằng nhau,
	// phần tử xuất hiện trước sẽ được giữ lại (chỉ cập nhật khi tần suất lớn hơn)
	int mostFrequentValue = inputValues[0];
	int mostFrequentCount = occurrenceCounts[inputValues[0]];
	for(int index = 1; index < numElements; ++index){
		int currentValue = inputValues[index];
		int currentCount = occurrenceCounts[currentValue];
		if(currentCount > mostFrequentCount){
			mostFrequentValue = currentValue;
			mostFrequentCount = currentCount;
		}
	}

	cout << mostFrequentValue << ' ' << mostFrequentCount << '\n';
	return 0;
}
