// #include <>
#include <iostream>
#include <vector>

using namespace std;

int score_element(int i)
{
    if (i <= 0)
        return 1;
    else
        return 0;
}

class Solution
{
  public:
    int bestRotation(vector<int> &A)
    {
        vector<int> sum_vec;
        for (int k = 0; k != A.size(); k++)
        {
            int sum = 0;
            for (vector<int>::size_type index = 0; index != A.size(); index++)
            {
                // element_score=sgn(A[index]-(len(A)-k+index)) if index<k else sgn(A[index]-(index-k))
                // element.append(element_score)

                int element_score;
                if (index < k)
                {
                    element_score = score_element(A[index] - (A.size() - (k - index)));
                }
                else
                {
                    element_score = score_element(A[index] - index + k);
                }
                sum += element_score;
            }
            sum_vec.push_back(sum);
        }
        int max = sum_vec[0];
        int index = 0;

        for (vector<int>::size_type i = 0; i != sum_vec.size(); i++)
        {
            if (sum_vec[i] > max){ index = i;
                                  max=sum_vec[i];
                                 }
               
        }
        return index;
    }
};