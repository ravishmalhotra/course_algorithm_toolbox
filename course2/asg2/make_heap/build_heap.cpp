#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;




class HeapBuilder
{
private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const
    {
        cout << swaps_.size() << "\n";
        for (unsigned int i = 0; i < swaps_.size(); ++i)
        {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }

        /*for (unsigned int i = 0; i < data_.size(); ++i)
        cout<<data_[i] <<" ";

        cout<<"\n"; */
    }


    void ReadData()
    {
        int n;
        cin >> n;
        data_.resize(n);
        for(int i = 0; i < n; ++i)
            cin >> data_[i];
    }


    void sift_down(unsigned int index)
    {

        unsigned int swapping_index=index;
        int min_number=data_[index];

        if (2*index+1<=data_.size()-1) //Make sure left child exists
        {

            if (data_[2*index+1]<data_[index]) //If the value of left child is less than parent then update the swapping_index and min_number
            {
                swapping_index=2*index+1;
                min_number=data_[swapping_index];
            }


            if (2*index+2<=data_.size()-1 && data_[2*index+2]<min_number) //If right child exists and its value is less than the current min_number, then update the swapping index and min_number
            {
                swapping_index=2*index+2;
                min_number=data_[swapping_index];
            }

            if(swapping_index!=index)
            {
                swap(data_[index],data_[swapping_index]);
                swaps_.push_back(make_pair(swapping_index,index));
                sift_down(swapping_index); //Recursion to see if swapped index's children are in order

            }

        }

        else return;

    }

    void GenerateSwaps()
    {
        swaps_.clear();

        // Start from last index and sift up comparing parents.


        /*for (int i=data_.size()-1; i>0 ; i--)
        {

            int j=i;
            //int k=i;
            int counter =0;
            //Checking all parents. Start from last point and sift up
            while (j>0 && data_[j]<data_[(j-1)/2])
            {
                swap(data_[j],data_[(j-1)/2]);
                swaps_.push_back(make_pair((j-1)/2, j));
                j=(j-1)/2;
                counter++;
            }

        }*/

        //Start from the last parent index and sift down comparing children.
        //Since sift down has a recursive loop it checks given index to make sure
        //its children are in order. Therefore, starting from the last parent, it makes
        //sure its children are in order. Afterwards, moving to the parent above
        //will make sure its children are in order, so on and so forth.


        for (int i=(data_.size()-2)/2; i>=0 ; i--)
        sift_down(i);

    }
public:
    void Solve()
    {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
