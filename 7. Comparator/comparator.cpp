/*
   greater<int>   in map,set,multimap,multiset in descending order
   greater<int>() sorting vector in descending order
   greater<int>   priority_queue in ascending order
*/

// user defined comparator for priority queue
/*
    #include <bits/stdc++.h>
    using namespace std;
    typedef pair<int,int> PII;

    class Compare
    {
    public:
        bool operator()(PII below, PII above)
        {
            if (below.first > above.first)
            {
                return true;
            }
            else if (below.first == above.first && below.second < above.second)
            {
                return true;
            }

            return false;
        }
    };

    int main()
    {
        priority_queue<PII, vector<PII>, Compare> ds;
        ds.push({100, 11});
        ds.push({100, 41});
        ds.push({100, 21});
        ds.push({300, 1});
        ds.push({300, 2});
        ds.push({1, 1});
        ds.push({1, 2});
        ds.push({1, 20});

        cout << "The priority queue is : \n";
        while (!ds.empty())
        {
            cout << ds.top().first << " " << ds.top().second
                << "\n";
            ds.pop(); // heapify happens
        }

        return 0;
    }
*/

// user defined comparator for vector
/*
    #include <bits/stdc++.h>
    using namespace std;

    bool cmp(int first, int second)
    {
        if (first > second)
            return true;
        return false;
    }

    int main()
    {
        vector<int> v={2,5,3,6,2,6,4,9};
        sort(v.begin(),v.end(),cmp);  user defined comparator function
        or sort(v.begin(),v.end(),greater<int>());  to sort in descending order

        for(int i:v){
            cout<<i<<" ";
        }
        return 0;
    }
*/
