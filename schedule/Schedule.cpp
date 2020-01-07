#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;

 

const int INF = 987654321; //엄청 큰 숫자

int length; //수열의 크기
int useNum;

//arr[]:양자화해야 할 수열, 정렬 상태

//partSum[]:arr[]의 부분합 저장, partSum[i]=A[0]+...A[i]의 합

//partSquareSum[]:arr[] 제곱의 부분합 저장, partSquareSum[i]는 arr[0]^2+...arr[i]^2의 합

int arr[100], partSum[100], partSquareSum[100], best_index_choice[100][100];

int cache[100][10];

//arr를 정렬하고 각 부분합 계산

void preCalculate(void)

{

    sort(arr, arr+length); //정렬

    partSum[0] = arr[0];

    partSquareSum[0] = arr[0] * arr[0];

 

    for (int i = 1; i < length; i++)

    {

        partSum[i] = partSum[i - 1] + arr[i];

        partSquareSum[i] = partSquareSum[i - 1] + arr[i] * arr[i];

    }

}

 

//arr[low]...arr[high] 구간을 하나의 숫자로 표현할 때 최소 오차 합 계산

int minDiffrence(int low, int high)

{

    //부분합을 이용해 arr[low]...arr[high]의 합 구함

    int sum = partSum[high] - (low == 0 ? 0 : partSum[low - 1]);

    int squareSum = partSquareSum[high] - (low == 0 ? 0 : partSquareSum[low - 1]);

    //평균을 반올림한 값으로 이 수들을 표현
    int mean = (int)(0.5 + (double)sum / (high - low + 1)); //반올림

    //sum(arr[i]-mean)^2를 전개한 결과를 부분합으로 표현

    //∑(arr[i]-mean)^2 = (high-low+1)*mean^2 - 2*(∑arr[i])*mean + ∑arr[i]^2

    int result = squareSum - (2 * mean*sum) + (mean*mean*(high - low + 1));

    return result;

}

 

int quantize(int from, int parts) //from번째 이후의 숫자들을 parts개의 묶음으로 묶는다

{

    //기저 사례:모든 숫자를 다 양자화했을 때

    if (from == length)

        return 0;

    //기저 사례:숫자는 아직 남았는데 더 묶을 수 없을 때 아주 큰 값 반환

    if (parts == 0)

        return INF;

    int &result = cache[from][parts];

    if (result != -1)

        return result;

    result = INF;
    int index_last_part_of_chunk = -1;

    //조각의 길이를 변화시켜 가며 최소치 찾음

    for (int partSize = 1; from + partSize <= length; partSize++) {
           
        int cand =  minDiffrence(from, from + partSize - 1) + quantize(from + partSize, parts - 1);
            
        if (cand < result) {
            result = cand;
            index_last_part_of_chunk = partSize + from;
        }
        
    }
    best_index_choice[from][parts] = index_last_part_of_chunk;
    return result;
    
}
void PrintLastElementEachChunk() {
    int i = 0 ;
    int chunk = useNum;
    cout << arr[i] << endl;
    while (i < length && chunk >= 0) {
        // cout << i << "th element" << endl;
        // cout << best_index_choice[i] << endl;
        cout << arr[best_index_choice[i][chunk]] << endl;
        i = best_index_choice[i][chunk];
        chunk--;
        
    }
    cout << endl;
}

 

int main(void)

{

    int test_case;

    cin >> test_case;

    if (test_case < 0 || test_case>50)

        exit(-1);

       

    for (int i = 0; i < test_case; i++)

    {

         //사용할 숫자 갯수

        cin >> length >> useNum;

        if (length < 1 || length>100 || useNum < 1 || useNum>10)

            exit(-1);

        for (int i = 0; i < length; i++)

            cin >> arr[i];

            preCalculate();

            memset(cache, -1, sizeof(cache));
            memset(best_index_choice, -1 , sizeof(best_index_choice));

            cout << quantize(0, useNum) << endl << endl;
               
            PrintLastElementEachChunk();
            

    }

    return 0;

}
